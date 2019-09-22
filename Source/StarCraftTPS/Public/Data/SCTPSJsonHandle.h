// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Json.h"

/**
 *
 */
class STARCRAFTTPS_API SCTPSJsonHandle
{
public:

	SCTPSJsonHandle();

	//解析Json存档
	void ReadSaveData(FString& Culture, float& MusicVol, float&SoundVol, TArray<FString>& SaveDataList);

	//更新存档
	void UpDateSaveData(FString Culture, float MusicVol, float SoundVol, TArray<FString>* SaveDataList);

private:

	//从jsonobj获取数据存入字符串
	bool GetStringFromJsonData(const TSharedPtr<FJsonObject>& JsonObject, FString& JsonStr);

	//读取Json文件到字符串
	bool LoadStringFromFile(const FString& FileName, const FString& RelativePath, FString& ResultString);

	//写入字符串到json文件
	bool SaveDataToJsonFile(const FString& JsonStr, const FString& RelaPath, const FString& FileName);

private:

	//存档名
	FString SaveDataFileName;
	//相对路径
	FString  RelativePath;

};
