// Fill out your copyright notice in the Description page of Project Settings.

#include "SCMenuController.h"

ASCMenuController::ASCMenuController()
{
	bShowMouseCursor = true;
}

void ASCMenuController::BeginPlay()
{
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	SetInputMode(InputMode);
}
