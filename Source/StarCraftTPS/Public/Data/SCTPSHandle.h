// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCTPSType.h"


class USoundCue;

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

	//存档数据
	TArray<FString>SaveDataList;

	//输入的存档名
	FString SaveName;


private:
	//创建单例，方法和数据分开存放
	static TSharedRef<SCTPSHandle>Create();

	//根据enum类型获取字符串
	template<typename TEnum>
	FString GetEnumValueAsString(const FString& Name, TEnum Value);

	//根据字符串获取enum的值
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString& Name, FString Value);

	//初始化存档数据
	void InitializeSaveData();
	//初始化声音数据
	void InitiMenuAudio();

private:

	static TSharedPtr<SCTPSHandle>DataInstans;
	//用Tmap保存菜单音效资源的指针
	TMap<FString, TArray<USoundCue*>>MenuAudioRes;
	//这个结构是SCTPSWidgetStyle里声明的，里面存储画刷、控件等元素
	const struct FSCTPSStyle *MenueStyle;
};


