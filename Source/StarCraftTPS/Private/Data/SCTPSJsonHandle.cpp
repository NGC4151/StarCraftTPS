// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSJsonHandle.h"

SCTPSJsonHandle::SCTPSJsonHandle()
{
	SaveDataFileName = FString("SaveData.json");
	RelativePath = FString("Res/ConfigData");
}

void SCTPSJsonHandle::ReadSaveData(FString& Culture, float& MusicVol, float&SoundVol, TArray<FString>& SaveDataList)
{
	//读取json文件，存在JsonValue字符串里
	FString JsonValue;
	LoadStringFromFile(SaveDataFileName, RelativePath, JsonValue);

	TArray<TSharedPtr<FJsonValue>>JsonParsed;
	TSharedRef<TJsonReader<TCHAR>>JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);

	if (FJsonSerializer::Deserialize(JsonReader,JsonParsed))
	{
		//获取数据
		Culture = JsonParsed[0]->AsObject()->GetStringField(FString("Culture"));
		MusicVol = JsonParsed[1]->AsObject()->GetNumberField(FString("MusicVol"));
		SoundVol = JsonParsed[2]->AsObject()->GetNumberField(FString("SoundVol"));

		//获取存档数据
		TArray<TSharedPtr<FJsonValue>>SaveDataArray = JsonParsed[3]->AsObject()->GetArrayField(FString("SaveData"));
		for (int i=0;i<SaveDataArray.Num();++i)
		{
			FString SaveDataName = SaveDataArray[i]->AsObject()->GetStringField(FString::FromInt(i));
			SaveDataList.Add(SaveDataName);
		}
	}
	else
	{
		SCTPSHelper::Debug(FString("Deserialize Failed!!"), 5.f, FColor::Red);
	}
}

bool SCTPSJsonHandle::LoadStringFromFile(const FString& FileName, const FString& RelativePath, FString& ResultString)
{
	if (!FileName.IsEmpty())
	{
		//获取绝对路径
		FString AbsoPath = FPaths::GameContentDir() + RelativePath + FileName;
		if (FPaths::FileExists(AbsoPath))
		{
			if (FFileHelper::LoadANSITextFileToStrings(ResultString,*AbsoPath))
			{
				return true;
			}
			else
			{
				//加载失败
				SCTPSHelper::Debug(FString("Load Error!!"), 3.0f, FColor::Red);
			}
		}
		else
		{
			SCTPSHelper::Debug(FString("File No Exist!"), 3.0f, FColor::Red);
		}
	}
}

