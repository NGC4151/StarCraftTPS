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
	//����Json�浵
	void ReadSaveData(FString& Culture, float& MusicVol, float&SoundVol, TArray<FString>& SaveDataList);
private:
	//��ȡJson�ļ����ַ���
	bool LoadStringFromFile(const FString& FileName, const FString& RelativePath, FString& ResultString);
private:
	//�浵��
	FString SaveDataFileName;
	//���·��
	FString  RelativePath;

};