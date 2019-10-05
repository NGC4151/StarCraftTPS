// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SCTPSGameMode.generated.h"

/**
 * 
 */
UCLASS()
class STARCRAFTTPS_API ASCTPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASCTPSGameMode();

	virtual void Tick(float DeltaSeconds)override;

protected:
	virtual void BeginPlay()override;
	
};
