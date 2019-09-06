// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
//���������л���ö��
UENUM()
enum class ECultureTeam : uint8 {
	EN=0,
	ZN=1
};

//Menu��ť������
namespace EMenuItem {
	enum Type
	{
		None,
		StartGame,
		GameOption,
		NewGame,
		LoadRecord,
		StartGameGoBack,
		GameOptionGoback,
		NewGameGoBack,
		SelecteRecordGoBack,
		EnterGame,
		EnterRecord

	};
}