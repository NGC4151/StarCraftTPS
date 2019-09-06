// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCTPSType.h"

/**
 * 
 */
class STARCRAFTTPS_API SCTPSHandle
{
public:
	SCTPSHandle();
	
	static void Initialize();

	static TSharedPtr<SCTPSHandle>Get();

	void ChangeLanguage(ECultureTeam Culture);

	void ChangeVolume(float MusicVol,float SoundVol);


public:
	ECultureTeam CurrentCultrue;

	float MusicValue;
	float SoundValue;

private:
	//创建单例，方法和数据分开存放
	static TSharedRef<SCTPSHandle>Create();

private:
	static TSharedPtr<SCTPSHandle>DataInstans;
};
