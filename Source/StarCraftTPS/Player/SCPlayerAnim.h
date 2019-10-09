// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SCPlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class STARCRAFTTPS_API USCPlayerAnim : public UAnimInstance
{
	GENERATED_BODY()

public:
	USCPlayerAnim();
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayAnim")
		FRotator SpineRotator;
protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds)override;
protected:
	void GetCharactorPointer();

	virtual void UpdateParater();

protected:
	class ASCCharacter* Charactor;
};
