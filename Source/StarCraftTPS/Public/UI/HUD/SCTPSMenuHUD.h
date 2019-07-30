// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SCTPSMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class STARCRAFTTPS_API ASCTPSMenuHUD : public AHUD
{
	GENERATED_BODY()
public:
		ASCTPSMenuHUD();

		TSharedPtr<class SSCTPSMenuHUDWidget>MenuHUDWidget;
	
};
