// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SCMenuController.generated.h"

/**
 * 
 */
UCLASS()
class STARCRAFTTPS_API ASCMenuController : public APlayerController
{
	GENERATED_BODY()
public:
		ASCMenuController();
protected:
	virtual void BeginPlay()override;
	
};
