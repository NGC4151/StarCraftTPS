// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSMenuHUDGameMode.h"
#include "SCMenuController.h"
#include "SCTPSMenuHUD.h"
#include "SCTPSGameInstance.h"
#include <Kismet/GameplayStatics.h>


ASCTPSMenuHUDGameMode::ASCTPSMenuHUDGameMode()
{
	PlayerControllerClass = ASCMenuController::StaticClass();
	HUDClass = ASCTPSMenuHUD::StaticClass();
}

void ASCTPSMenuHUDGameMode::BeginPlay()
{
	Cast<USCTPSGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()))->GameName = FName("SCTPSGameIns");
}
