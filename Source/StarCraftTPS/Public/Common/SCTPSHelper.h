// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Engine/GameEngine.h" //在原生C++类里需要包含这两个头文件才能用Gengine里的函数
#include <SlateApplication.h>
#include <SlateSound.h>
#include "TimerManager.h"

namespace SCTPSHelper {
	FORCEINLINE void Debug(FString Message, float DisplayTime=3.0f,FColor MessageColor=FColor::Blue) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, DisplayTime, MessageColor, Message);
		}
	}

	template<class UserClass>
	FORCEINLINE FTimerHandle PlaySoundAndCall(UWorld* world, const FSlateSound sound, UserClass* InUserObject, typename FTimerDelegate::TRawMethodDelegate<UserClass>::FMethodPtr InMethod)
	{
		FSlateApplication::Get().PlaySound(sound);
		FTimerHandle Result;
		const float SoundTime = FMath::Max(FSlateApplication::Get().GetSoundDuration(sound), 0.1f);
		FTimerDelegate Callback;
		Callback.BindRaw(InUserObject, InMethod);
		world->GetTimerManager().SetTimer(Result, Callback, SoundTime, false);
		return Result;
	}
}

