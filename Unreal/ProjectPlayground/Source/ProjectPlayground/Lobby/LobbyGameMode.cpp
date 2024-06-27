// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "ProjectPlayground/Lobby/LobbyPlayerController.h"
#include "ProjectPlayground/Lobby/LobbyCharacter.h"

ALobbyGameMode::ALobbyGameMode()
{
	PlayerControllerClass = ALobbyPlayerController::StaticClass();
	DefaultPawnClass = ALobbyCharacter::StaticClass();
}