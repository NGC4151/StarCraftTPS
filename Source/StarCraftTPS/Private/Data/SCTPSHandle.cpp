// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSHandle.h"
#include "Internationalization.h"
#include "SCTPSSingleton.h"
#include "SCTPSJsonHandle.h"
#include "SCTPSHelper.h"

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
	}
	if (SoundVol>0)
	{
		SoundValue = SoundVol;
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


