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

void SCTPSJsonHandle::UpDateSaveData(FString Culture, float MusicVol, float SoundVol, TArray<FString>* SaveDataList)
{
	TSharedPtr<FJsonObject>JsonObj = MakeShareable(new FJsonObject);

	TArray<TSharedPtr<FJsonValue>>BaseDataArray;

	TSharedPtr<FJsonObject>CultureObject = MakeShareable(new FJsonObject);
	CultureObject->SetStringField("Culture", Culture);
	TSharedPtr<FJsonValueObject>CultureValue = MakeShareable(new FJsonValueObject(CultureObject));

	TSharedPtr<FJsonObject>MusicVolObject = MakeShareable(new FJsonObject);
	MusicVolObject->SetNumberField("MusicVol", MusicVol);
	TSharedPtr<FJsonValueObject>MusicVolValue = MakeShareable(new FJsonValueObject(MusicVolObject));

	TSharedPtr<FJsonObject>SoundVolObject = MakeShareable(new FJsonObject);
	SoundVolObject->SetNumberField("SoundVol", SoundVol);
	TSharedPtr<FJsonValueObject>SoundVolValue = MakeShareable(new FJsonValueObject(SoundVolObject));

	/**
	 * 将传入的SaveDataList里的存档数据遍历，将它转换为FJsonValueObject，然后存入SaveDataArray数组
	 */
	TArray<TSharedPtr<FJsonValue>>SaveDataArray;
	for (int i=0;i<SaveDataList->Num();++i)
	{
		TSharedPtr<FJsonObject>SaveItem = MakeShareable(new FJsonObject);
		SaveItem->SetStringField(FString::FromInt(i), (*SaveDataList)[i]);
		TSharedPtr<FJsonValueObject>SaveDataValue = MakeShareable(new FJsonValueObject(SaveItem));
		SaveDataArray.Add(SaveDataValue);
	}

	//将SaveDataArray存入"SaveData"数组域中
	TSharedPtr<FJsonObject>SaveDataObject = MakeShareable(new FJsonObject);
	SaveDataObject->SetArrayField("SaveData", SaveDataArray);
	TSharedPtr<FJsonValueObject>SaveDataValue = MakeShareable(new FJsonValueObject(SaveDataObject));

	BaseDataArray.Add(CultureValue);
	BaseDataArray.Add(MusicVolValue);
	BaseDataArray.Add(SoundVolValue);
	BaseDataArray.Add(SaveDataValue);

	JsonObj->SetArrayField("T", BaseDataArray);

	FString JsonStr;
	GetStringFromJsonData(JsonObj, JsonStr);

	SCTPSHelper::Debug(FString("Data:" + JsonStr), 20.f, FColor::Red);

	JsonStr.RemoveAt(0, 8);
	JsonStr.RemoveFromEnd(FString("}"));

	SCTPSHelper::Debug(FString("Data_Remove:" + JsonStr), 20.f, FColor::Red);

	SaveDataToJsonFile(JsonStr, RelativePath, SaveDataFileName);

}

bool SCTPSJsonHandle::GetStringFromJsonData(const TSharedPtr<FJsonObject>& JsonObject, FString& JsonStr)
{
	if (JsonObject.IsValid()&&JsonObject->Values.Num()>0)
	{
		TSharedRef<TJsonWriter<TCHAR>>JsonWriter = TJsonWriterFactory<TCHAR>::Create(&JsonStr);
		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);
		return true;
	}
	return false;
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

bool SCTPSJsonHandle::SaveDataToJsonFile(const FString& JsonStr, const FString& RelaPath, const FString& FileName)
{
	if (!JsonStr.IsEmpty())
	{
		if (!FileName.IsEmpty())
		{
			FString AbsoPath = FPaths::ProjectContentDir() + RelaPath + FileName;
			if (FFileHelper::SaveStringToFile(JsonStr,*AbsoPath))
			{
				return true;
			}
			else
			{
				SCTPSHelper::Debug(FString("Save data Failed!"), 5.f);
			}
		}
	}
	return false;
}

