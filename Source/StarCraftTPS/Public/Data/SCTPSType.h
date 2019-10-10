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
	ZN
};

//Menu按钮的类型
namespace EMenuItem {
	enum Type
	{
		None,
		StartGame,
		GameOption,
		NewGame,
		QuitGame,
		LoadRecord,
		StartGameGoBack,
		GameOptionGoback,
		NewGameGoBack,
		SelecteRecordGoBack,
		EnterGame,
		EnterRecord

	};
}

//Menu界面类型
namespace EMenuType
{
	enum Type
	{
		None,
		MainMenu,
	    StartGame,
		QuitGame,
		GameOption,
		NewGame,
		ChooseSaveData

	};


}

//动画状态枚举
namespace EMenuAnim
{
	enum Type
	{
		stop,
		open,
		close
	};
}

namespace EGameViewMode {
	enum Type {
		First,
		Third
	};
}