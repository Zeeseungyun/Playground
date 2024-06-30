#include "ProjectPlayground/InGame/InGameModeBase.h"
#include "Engine/NetConnection.h"
#include "Kismet/GameplayStatics.h"

#include "ZeeNet/Public/Interface/Handler/Request/Dedicate.h"
#include "ProjectPlayground/InGame/InGamePlayerController.h"
#include "ProjectPlayground/InGame/InGameCharacter.h"
#include "ProjectPlayground/Network/ZeeNetworkClientSubsystem.h"

class FInGameRequestHandler : public IZeeNetRequestHandler_Dedicate
{
public:
	TWeakObjectPtr<class AInGameModeBase> Owner;

	[[nodiscard]] EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetDedicateLogin>& InPacket) override
	{
		return EZeeNetRequestHandlerResponse::NoResponse;
	}

	[[nodiscard]] EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const FZeeNetPacket<FZeeNetDedicateMove>& InPacket)  override
	{
		if (!Owner.IsValid())
		{
			return EZeeNetRequestHandlerResponse::NoResponse;
		}

		const FZeeNetDedicateMove& Msg = InPacket.Message;
		Owner->DedicateMoveToUIDs.Add(FString::Printf(TEXT("%s%lld"), *Msg.UserIp, Msg.Character.User), Msg);

		//copy header.
		FZeeNetPacket<FZeeNetDedicateMove> ResPacket = InPacket;
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
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
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
		RequestHandler = MakeShared<FInGameRequestHandler>();
		RequestHandler->Owner = this;
		NetworkClientSubsystem->GetClient()->RegisterRequestHandler(RequestHandler);
	}
}

void AInGameModeBase::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	UE_LOG(LogTemp, Log, TEXT("ZeeLog, PreLogin Options[%s]."), *Options);
	if (!ErrorMessage.IsEmpty())
	{
		UE_LOG(LogTemp, Log, TEXT("ZeeLog, PreLogin Failed[%s]."), *ErrorMessage);
		return;
	}

	const FString UserId = UGameplayStatics::ParseOption(Options, TEXT("Id"));
	if (!DedicateMoveToUIDs.Contains(FString::Printf(TEXT("%s%s"), *Address, *UserId)))
	{
		ErrorMessage = FString::Printf(TEXT("InvalidAddress[%s%s]"), *Address, *UserId);
		UE_LOG(LogTemp, Log, TEXT("ZeeLog, PreLogin Failed[%s]."), *ErrorMessage);
		return;
	}

	//Pass.
	UE_LOG(LogTemp, Log, TEXT("ZeeLog, PreLogin Succeed."));
}

APlayerController* AInGameModeBase::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	if (!ErrorMessage.IsEmpty())
	{
		UE_LOG(LogTemp, Log, TEXT("ZeeLog, Login Failed[%s]."), *ErrorMessage);
		return nullptr;
	}

	UNetConnection* NewPlayerConnection = Cast<UNetConnection>(NewPlayer);
	if (!::IsValid(NewPlayerConnection))
	{
		ErrorMessage = TEXT("if (!::IsValid(NewPlayerConnection))");
		UE_LOG(LogTemp, Log, TEXT("ZeeLog, Login Failed[%s]."), *ErrorMessage);
		return nullptr;
	}

	const FString UserId = UGameplayStatics::ParseOption(Options, TEXT("Id"));
	const FString Key = FString::Printf(TEXT("%s%s"), *NewPlayerConnection->LowLevelGetRemoteAddress(), *UserId);
	const FZeeNetDedicateMove* const Found = DedicateMoveToUIDs.Find(Key);
	if (!Found)
	{
		ErrorMessage = FString::Printf(TEXT("Invalid User Address[%s]"), *Key);
		UE_LOG(LogTemp, Log, TEXT("ZeeLog, Login Failed[%s]."), *ErrorMessage);
		return nullptr;
	}

	AInGamePlayerController* PlayerController = Cast<AInGamePlayerController>(Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage));
	PlayerController->DataCharacter = Found->Character;
	PlayerController->DataPosition = Found->Position;
	
	UE_LOG(LogTemp, Log, TEXT("ZeeLog, Login Succeeded."));
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
		UE_LOG(LogGameMode, Warning, TEXT("SpawnDefaultPawnAtTransform: Couldn't spawn Pawn of type %s at %s"), *GetNameSafe(PawnClass), *SpawnTransform.ToHumanReadableString());
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
