// Fill out your copyright notice in the Description page of Project Settings.

#include "SCMenuController.h"

ASCMenuController::ASCMenuController()
{
	bShowMouseCursor = true;
}

void ASCMenuController::BeginPlay()
{
	FInputModeUIOnly InputMode;
	//设置鼠标的视口锁定行为
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
}
