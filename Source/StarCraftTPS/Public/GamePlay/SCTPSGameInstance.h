// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SCTPSGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class STARCRAFTTPS_API USCTPSGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	//virtual void Init()override; ���ڳ�ʼ��GameInstance���ݵģ�

	UPROPERTY(VisibleAnywhere, Category = "SCTPS")
		FName GameName;
	
};