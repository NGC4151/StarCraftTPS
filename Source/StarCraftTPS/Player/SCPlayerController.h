// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SCTPSType.h"
#include "SCPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STARCRAFTTPS_API ASCPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:

	ASCPlayerController();

	virtual void Tick(float DeltaSeconds)override;

	virtual void SetupInputComponent()override;

public:

	//获取玩家角色
	class ASCCharacter* SCCharactor;

protected:

	virtual void BeginPlay()override;

private:

	//切换视角
	void ChangeView();

	//鼠标按键事件
	void LeftEventStart();
	void LeftEventEnd();
	void RightEventStart();
	void RightEventEnd();

private:
	//左键预动作
	EUpperBody::Type LeftUpperType;
	//右键预动作
	EUpperBody::Type RightUpperType;
};
