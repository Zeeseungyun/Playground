#include "ProjectPlayground/InGame/InGameModeBase.h"
#include "Engine/NetConnection.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

#include "ZeeNet/Public/Interface/Handler/Request/Dedicate.h"
#include "ZeeNet/Public/Interface/Handler/Request/UserCharacter.h"
#include "ProjectPlayground/InGame/InGamePlayerController.h"
#include "ProjectPlayground/InGame/InGameCharacter.h"
#include "ProjectPlayground/Network/ZeeNetworkClientSubsystem.h"
#include "ProjectPlayground/InGame/InGameMoveTown.h"

class FInGameRequestHandler_Dedicate 
	: public IZeeNetRequestHandler_Dedicate
{
public:
	TWeakObjectPtr<class AInGameModeBase> Owner;

	[[nodiscard]] EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetDedicateMove>& InPacket) final
	{
		if (!Owner.IsValid())
		{
			return EZeeNetRequestHandlerResponse::NoResponse;
		}

		const FZeeNetDedicateMove& Msg = InPacket.Message;

		AInGameModeBase::FPassport Passport;
		Passport.bIsMoveTown = true;
		Passport.UserIp = Msg.UserIp;
		Passport.Character = Msg.Character;
		Passport.MapName = Msg.ToServer.MapName;

		Owner->Passports.Add(FString::Printf(TEXT("%s%lld"), *Msg.UserIp, Msg.Character.User), Passport);

		//copy header.
		FZeeNetPacket<FZeeNetDedicateMove> ResPacket = InPacket;
		ResPacket.Message = {};
		ResPacket.Message.Character = Msg.Character;
		InResponser->Response(ResPacket);

		return EZeeNetRequestHandlerResponse::ResponseDirectly;
	}
};

class FInGameRequestHandler_UserCharacter
	: public IZeeNetRequestHandler_UserCharacter
{
public:
	TWeakObjectPtr<class AInGameModeBase> Owner;

	[[nodiscard]] EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetUserCharacterSelect>& InPacket) final 
	{
		if (!Owner.IsValid())
		{
			return EZeeNetRequestHandlerResponse::NoResponse;
		}

		const FZeeNetUserCharacterSelect& Msg = InPacket.Message;
		AInGameModeBase::FPassport Passport;
		Passport.bIsMoveTown = false;
		Passport.UserIp = Msg.UserIp;
		Passport.Character = Msg.Character;
		Passport.Pos = Msg.Position.Pos;
		Passport.Rot = Msg.Position.Rot;
		Passport.MapName = Msg.Position.MapName;

		Owner->Passports.Add(FString::Printf(TEXT("%s%lld"), *Msg.UserIp, Msg.Character.User), Passport);

		//copy header.
		FZeeNetPacket<FZeeNetUserCharacterSelect> ResPacket = InPacket;
		ResPacket.Message = {};
		ResPacket.Message.Character = Msg.Character;
		InResponser->Response(ResPacket);

		return EZeeNetRequestHandlerResponse::ResponseDirectly;
	}

};

AInGameModeBase::AInGameModeBase()
{
	// use our custom PlayerController class
	PlayerControllerClass = AInGamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/InGame/Blueprints/BP_InGameCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/InGame/Blueprints/BP_InGamePlayerController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void AInGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UZeeNetworkClientSubsystem* NetworkClientSubsystem = UZeeNetworkClientSubsystem::Get(this);
	if (NetworkClientSubsystem)
	{
		RequestHandler_Dedicate = MakeShared<FInGameRequestHandler_Dedicate>();
		RequestHandler_Dedicate->Owner = this;
		NetworkClientSubsystem->GetClient()->RegisterRequestHandler(RequestHandler_Dedicate);

		RequestHandler_UserCharacter = MakeShared<FInGameRequestHandler_UserCharacter>();
		RequestHandler_UserCharacter->Owner = this;
		NetworkClientSubsystem->GetClient()->RegisterRequestHandler(RequestHandler_UserCharacter);
	}

	for (TActorIterator<AInGameMoveTown> Iter(GetWorld()); Iter; ++Iter)
	{
		const FTransform Transform = Iter->GetMoveTownTransform();
		MoveTownDestPos = Transform.GetLocation();
		MoveTownDestRot = FRotator(Transform.GetRotation());
	}
}

void AInGameModeBase::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	UE_LOG(LogGameMode, Log, TEXT("ZeeLog, PreLogin Options[%s]."), *Options);
	if (!ErrorMessage.IsEmpty())
	{
		UE_LOG(LogGameMode, Log, TEXT("ZeeLog, PreLogin Failed[%s]."), *ErrorMessage);
		return;
	}
	
	const FString UserId = UGameplayStatics::ParseOption(Options, TEXT("Id"));
	const FString Key = FString::Printf(TEXT("%s%s"), *Address, *UserId);
	if (!Passports.Contains(Key))
	{
		ErrorMessage = FString::Printf(TEXT("InvalidKey[%s]"), *Key);
		UE_LOG(LogGameMode, Log, TEXT("ZeeLog, PreLogin Failed[%s]."), *ErrorMessage);
		return;
	}

	//Pass.
	UE_LOG(LogGameMode, Log, TEXT("ZeeLog, PreLogin Succeed."));
}

APlayerController* AInGameModeBase::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	if (!ErrorMessage.IsEmpty())
	{
		UE_LOG(LogGameMode, Log, TEXT("ZeeLog, Login Failed[%s]."), *ErrorMessage);
		return nullptr;
	}

	UNetConnection* NewPlayerConnection = Cast<UNetConnection>(NewPlayer);
	if (!::IsValid(NewPlayerConnection))
	{
		ErrorMessage = TEXT("if (!::IsValid(NewPlayerConnection))");
		UE_LOG(LogGameMode, Log, TEXT("ZeeLog, Login Failed[%s]."), *ErrorMessage);
		return nullptr;
	}

	const FString UserId = UGameplayStatics::ParseOption(Options, TEXT("Id"));
	const FString Key = FString::Printf(TEXT("%s%s"), *NewPlayerConnection->LowLevelGetRemoteAddress(), *UserId);
	const FPassport* const Found = Passports.Find(Key);

	if (!Found)
	{
		ErrorMessage = FString::Printf(TEXT("Invalid User Address[%s]"), *Key);
		UE_LOG(LogGameMode, Log, TEXT("ZeeLog, Login Failed[%s]."), *ErrorMessage);
		return nullptr;
	}


	AInGamePlayerController* PlayerController = Cast<AInGamePlayerController>(Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage));
	PlayerController->DataCharacter = Found->Character;
	PlayerController->DataPosition.UID = Found->Character.UID;
	PlayerController->DataPosition.MapName = Found->MapName;

	if (Found->bIsMoveTown)
	{
		PlayerController->DataPosition.Pos = MoveTownDestPos;
		PlayerController->DataPosition.Rot = MoveTownDestRot;
	}
	else
	{
		PlayerController->DataPosition.Pos = Found->Pos;
		PlayerController->DataPosition.Rot = Found->Rot;
	}
	
	Passports.Remove(Key);
	UE_LOG(LogGameMode, Log, TEXT("ZeeLog, Login Succeeded."));
	return PlayerController;
}

APawn* AInGameModeBase::SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot)
{
	AInGamePlayerController* PC = Cast<AInGamePlayerController>(NewPlayer);

	FTransform SpawnTransform;
	SpawnTransform.SetLocation(PC->DataPosition.Pos);
	SpawnTransform.SetRotation(PC->DataPosition.Rot);

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Instigator = GetInstigator();
	SpawnInfo.ObjectFlags |= RF_Transient;	// We never want to save default player pawns into a map
	UClass* PawnClass = GetDefaultPawnClassForController(NewPlayer);
	AInGameCharacter* ResultPawn = GetWorld()->SpawnActor<AInGameCharacter>(PawnClass, SpawnTransform, SpawnInfo);
	if (!ResultPawn)
	{
		UE_LOG(LogGameMode, Fatal, TEXT("SpawnDefaultPawnAtTransform: Couldn't spawn Pawn of type %s at %s"), *GetNameSafe(PawnClass), *SpawnTransform.ToHumanReadableString());
		return nullptr;
	}
	
	ResultPawn->CharacterName = PC->DataCharacter.Name;
	return ResultPawn;
}

void AInGameModeBase::Logout(AController* Exiting)
{
	AInGamePlayerController* PC = Cast<AInGamePlayerController>(Exiting);
	PC->OnLogout();
	Super::Logout(Exiting);
}
