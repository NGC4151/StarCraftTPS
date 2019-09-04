// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
//用于语言切换的枚举
UENUM()
enum class ECultureTeam : uint8 {
	EN=0,
	ZN=1
};

//Menu按钮的类型
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