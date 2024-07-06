#include "LobbyGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "ProjectPlayground/Lobby/LobbyPlayerController.h"
#include "ProjectPlayground/Lobby/LobbyCharacter.h"

ALobbyGameMode::ALobbyGameMode()
{
	PlayerControllerClass = ALobbyPlayerController::StaticClass();
	DefaultPawnClass = ALobbyCharacter::StaticClass();
	PrimaryActorTick.bCanEverTick = false;
}
