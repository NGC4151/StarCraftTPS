// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Engine/GameEngine.h" //��ԭ��C++������Ҫ����������ͷ�ļ�������Gengine��ĺ���

namespace SCTPSHelper {
	FORCEINLINE void Debug(FString Message, float DisplayTime=3.0f,FColor MessageColor=FColor::Blue) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, DisplayTime, MessageColor, Message);
		}
	}
}
