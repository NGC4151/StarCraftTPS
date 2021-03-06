// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SCTPSGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class STARCRAFTTPS_API ASCTPSGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	ASCTPSGameHUD();

private:
	//创建一个SSCGameHUDWidget的共享指针
	TSharedPtr<class SSCGameHUDWidget>GameHUDWidget;
};
