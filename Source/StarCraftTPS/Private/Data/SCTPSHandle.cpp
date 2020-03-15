// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSHandle.h"
#include "Internationalization.h"
#include "SCTPSSingleton.h"
#include "SCTPSJsonHandle.h"
#include "SCTPSHelper.h"
#include "Style/SCTPSStyle.h"
#include "SCTPSWidgetStyle.h"
#include <Sound/SoundCue.h>

TSharedPtr<SCTPSHandle>SCTPSHandle::DataInstans = NULL;

void SCTPSHandle::Initialize()
{
	if (!DataInstans.IsValid())
	{
		DataInstans = Create();
	}
}

TSharedPtr<SCTPSHandle> SCTPSHandle::Get()
{
	Initialize();
	return DataInstans;
}

void SCTPSHandle::ChangeLanguage(ECultureTeam Culture)
{
	switch (Culture)
	{
	case ECultureTeam::EN:
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
		break;
	case ECultureTeam::ZN:
		FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
		break;
	}

	CurrentCultrue = Culture;

	//更新存档数据
	SCTPSSingleton<SCTPSJsonHandle>::Get()->UpDateSaveData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCultrue), MusicValue, SoundValue, &SaveDataList);
}

void SCTPSHandle::ChangeVolume(float MusicVol, float SoundVol)
{
	if (MusicVol>0)
	{
		MusicValue = MusicVol;
		//循环设置背景音量
		for (TArray<USoundCue*>::TIterator It(MenuAudioRes.Find(FString("Music"))->CreateIterator()); It; ++It)
		{
			//设置音量
			(*It)->VolumeMultiplier = MusicValue;
		}

	}
	if (SoundVol>0)
	{
		SoundValue = SoundVol;

		for (TArray<USoundCue*>::TIterator It(MenuAudioRes.Find(FString("Sound"))->CreateIterator()); It; ++It)
		{
			(*It)->VolumeMultiplier = SoundValue;
		}
	}
	//更新存档数据
	SCTPSSingleton<SCTPSJsonHandle>::Get()->UpDateSaveData(GetEnumValueAsString<ECultureTeam>(FString("ECultureTeam"), CurrentCultrue), MusicValue, SoundValue, &SaveDataList);
}


TSharedRef<SCTPSHandle> SCTPSHandle::Create()
{
	TSharedRef<SCTPSHandle>DataRef = MakeShareable(new SCTPSHandle());
	return DataRef;
}

SCTPSHandle::SCTPSHandle()
{
	//初始化存档数据
	InitializeSaveData();
	//初始化音乐
	InitiMenuAudio();
}

template<typename TEnum>
FString SCTPSHandle::GetEnumValueAsString(const FString& Name, TEnum Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		return FString("InValid!");
	}
	return EnumPtr->GetNameStringByIndex((int32)Value);
}

template<typename TEnum>
TEnum SCTPSHandle::GetEnumValueFromString(const FString& Name, FString Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr)
	{
		SCTPSHelper::Debug(FString("EnumPtr is none"), 5.f, FColor::Yellow);
		return TEnum(0);
	}
	return (TEnum)EnumPtr->GetIndexByName(FName(*FString(Value)));
}

void SCTPSHandle::InitializeSaveData()

{
	SaveName = FString("");

	//获取语言
	FString  Culture;

	//读取存档数据
	SCTPSSingleton<SCTPSJsonHandle>::Get()->ReadSaveData(Culture, MusicValue, SoundValue, SaveDataList);

	//初始化语言音乐声音
	//ChangeLanguage(ECultureTeam::ZN);
	ChangeLanguage(GetEnumValueFromString<ECultureTeam>(FString("ECultureTeam"), Culture));

	//输出存档信息到日志
	SCTPSHelper::Debug(Culture + FString("--") + FString::SanitizeFloat(MusicValue) + FString("--") + FString::SanitizeFloat(SoundValue),5.f,FColor::Yellow);

	//循环读取存档数据（使用迭代器）
	for (TArray<FString>::TIterator It(SaveDataList);It;++It)
	{
		SCTPSHelper::Debug(*It, 5.f, FColor::Yellow);
	}


}

void SCTPSHandle::InitiMenuAudio()
{
	//获取编辑器的MenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");

	//添加SoundCue资源到USound类型数组
	TArray<USoundCue*>MusicList;
	MusicList.Add(Cast<USoundCue>(MenueStyle->BackgroundMusic.GetResourceObject()));

	TArray<USoundCue*>SoundList;
	SoundList.Add(Cast<USoundCue>(MenueStyle->MenuChangeSound.GetResourceObject()));
	SoundList.Add(Cast<USoundCue>(MenueStyle->ButtonPressedSound.GetResourceObject()));

	//添加资源到Tmap
	MenuAudioRes.Add(FString("Music"), MusicList);
	MenuAudioRes.Add(FString("Sound"), SoundList);

	//重置下声音
	ChangeVolume(MusicValue, SoundValue);
	

}

void SCTPSHandle::InitializeGameData()
{
	InitObjectAttr();
}

void SCTPSHandle::InitObjectAttr()
{
	SCTPSSingleton<SCTPSJsonHandle>::Get()->ObjectAttrJsonReader(ObjectAttributeMap);
}


