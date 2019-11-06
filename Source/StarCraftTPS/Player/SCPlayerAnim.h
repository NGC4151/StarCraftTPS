// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SCTPSType.h"
#include "SCPlayerAnim.generated.h"

class UAnimMontage;

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

	//重写更新参数函数
	virtual void UpdateParater();

	//重写更新蒙太奇函数
	virtual void UpdateMontage();

	//更改是否可以切换视角
	void CanChangeView(bool IsCanChange);

protected:
	//角色指针
	class ASCCharacter* Charactor;

	//蒙太奇指针
	UAnimMontage* Reload;
	UAnimMontage* Fire;
	UAnimMontage* Aim;
	UAnimMontage* Pick;
	UAnimMontage* Hit;
	

	//保存当前播放的蒙太奇
	UAnimMontage* CurrentMontage;

	//保存当前的视角模式
	EGameViewMode::Type GameViewMode;
};
