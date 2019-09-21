// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSJsonHandle.h"
#include "SCTPSHelper.h"

SCTPSJsonHandle::SCTPSJsonHandle()
{
	SaveDataFileName = FString("SaveData.json");
	RelativePath = FString("Res/DataConfig/");
}

void SCTPSJsonHandle::ReadSaveData(FString& Culture, float& MusicVol, float&SoundVol, TArray<FString>& SaveDataList)
{
	//读取json文件，存在JsonValue字符串里
	FString JsonValue;
	LoadStringFromFile(SaveDataFileName, RelativePath, JsonValue);

	TArray<TSharedPtr<FJsonValue>>JsonParsed;
	TSharedRef<TJsonReader<TCHAR>>JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);

	//将读取到的字符串存入JsonReader，它一个TJsonReader类型的数组引用JsonReader，然后将解析的结果保存至JsonParsed
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
		FString AbsoPath = FPaths::ProjectContentDir()+ RelativePath + FileName;
		SCTPSHelper::Debug(AbsoPath, 5.0f, FColor::Red);
		if (FPaths::FileExists(AbsoPath))
		{
			if (FFileHelper::LoadFileToString(ResultString,*AbsoPath))
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
	return false;
}

