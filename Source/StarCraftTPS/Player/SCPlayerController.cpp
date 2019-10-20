// Fill out your copyright notice in the Description page of Project Settings.

#include "SCPlayerController.h"
#include "SCTPSType.h"
#include "SCCharacter.h"

ASCPlayerController::ASCPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASCPlayerController::Tick(float DeltaSeconds)
{

}

void ASCPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!SCCharactor)
	{
		SCCharactor = Cast<ASCCharacter>(GetCharacter());
	}

	bShowMouseCursor = false;
	FInputModeGameOnly InputMode;
	InputMode.SetConsumeCaptureMouseDown(true);
	SetInputMode(InputMode);
}

void ASCPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//绑定视角切换的按键
	InputComponent->BindAction("ChangeView", IE_Pressed,this, &ASCPlayerController::ChangeView);

	//绑定鼠标左右键按下松开的事件
	InputComponent->BindAction("LeftEvent", IE_Pressed, this,&ASCPlayerController::LeftEventStart);
	InputComponent->BindAction("LeftEvent", IE_Released, this,&ASCPlayerController::LeftEventEnd);
	InputComponent->BindAction("RightEvent", IE_Released,this, &ASCPlayerController::RightEventStart);
	InputComponent->BindAction("RightEvent", IE_Released,this, &ASCPlayerController::RightEventEnd);

}

void ASCPlayerController::ChangeView()
{
	switch (SCCharactor->GameViewMode)
	{
	case EGameViewMode::First:
		SCCharactor->ChangeView(EGameViewMode::Third);
		break;
	case EGameViewMode::Third:
		SCCharactor->ChangeView(EGameViewMode::First);
		break;
	}
}

void ASCPlayerController::LeftEventStart()
{

}

void ASCPlayerController::LeftEventEnd()
{

}

void ASCPlayerController::RightEventStart()
{

}

void ASCPlayerController::RightEventEnd()
{

}

