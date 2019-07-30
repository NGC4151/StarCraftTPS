// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSMenuHUDGameMode.h"
#include "SCMenuController.h"
#include "SCTPSMenuHUD.h"


ASCTPSMenuHUDGameMode::ASCTPSMenuHUDGameMode()
{
	PlayerControllerClass = ASCMenuController::StaticClass();
	HUDClass = ASCTPSMenuHUD::StaticClass();
}
