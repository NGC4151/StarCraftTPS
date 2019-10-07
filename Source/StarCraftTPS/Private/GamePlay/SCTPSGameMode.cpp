// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSGameMode.h"
#include "SCTPSHelper.h"
#include "SCTPSHandle.h"
#include "SCTPSGameInstance.h"
#include <Kismet/GameplayStatics.h>

#include "StarCraftTPS/Player/SCCharacter.h"
#include "StarCraftTPS/Player/SCPlayerController.h"
#include "StarCraftTPS/Player/SCPlayerState.h"
#include "SCTPSGameHUD.h"

ASCTPSGameMode::ASCTPSGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	HUDClass=ASCTPSGameHUD::StaticClass();
	PlayerControllerClass = ASCPlayerController::StaticClass();
	PlayerStateClass = ASCPlayerState::StaticClass();
	DefaultPawnClass = ASCCharacter::StaticClass();
}

void ASCTPSGameMode::Tick(float DeltaSeconds)
{

}

void ASCTPSGameMode::BeginPlay()
{

}
