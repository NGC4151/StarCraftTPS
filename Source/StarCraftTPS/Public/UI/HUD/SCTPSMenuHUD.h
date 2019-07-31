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
		//声明一个MenuHUDWidget的共享指针，也可以用UPROPERTY（）宏声明普通指针的形式
		TSharedPtr<class SSCTPSMenuHUDWidget>MenuHUDWidget;
	
};
