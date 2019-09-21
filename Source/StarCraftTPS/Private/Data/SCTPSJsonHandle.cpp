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
	//��ȡjson�ļ�������JsonValue�ַ�����
	FString JsonValue;
	LoadStringFromFile(SaveDataFileName, RelativePath, JsonValue);

	TArray<TSharedPtr<FJsonValue>>JsonParsed;
	TSharedRef<TJsonReader<TCHAR>>JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);

	//����ȡ�����ַ�������JsonReader����һ��TJsonReader���͵���������JsonReader��Ȼ�󽫽����Ľ��������JsonParsed
	if (FJsonSerializer::Deserialize(JsonReader,JsonParsed))
	{
		//��ȡ����
		Culture = JsonParsed[0]->AsObject()->GetStringField(FString("Culture"));
		MusicVol = JsonParsed[1]->AsObject()->GetNumberField(FString("MusicVol"));
		SoundVol = JsonParsed[2]->AsObject()->GetNumberField(FString("SoundVol"));

		//��ȡ�浵����
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
		//��ȡ����·��
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
				//����ʧ��
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
