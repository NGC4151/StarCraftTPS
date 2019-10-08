// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/SCPlayerAnim.h"
#include "SCTPSPlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class STARCRAFTTPS_API USCTPSPlayerAnim : public USCPlayerAnim
{
	GENERATED_BODY()
public:
	USCTPSPlayerAnim();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
		bool bIsInAir;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
		float Direction;

	
};
