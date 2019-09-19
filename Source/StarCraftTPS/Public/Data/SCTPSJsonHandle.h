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
private:
	//读取Json文件到字符串
	bool LoadStringFromFile(const FString& FileName, const FString& RelativePath, FString& ResultString);
private:
	//存档名
	FString SaveDataFileName;
	//相对路径
	FString  RelativePath;

};
