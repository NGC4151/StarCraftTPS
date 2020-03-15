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

//视角模式枚举
namespace EGameViewMode {
	enum Type {
		First,
		Third
	};
}

//上半身动画状态
namespace EUpperBody
{
	enum Type
	{
		None,
		Fire,
		Reload,
		Aim,
		Pick,
		Hit
	};
}

//物品类型
namespace EObjectType
{
	enum Type
	{
		Normal = 0,
		Food,
		Tool,
		Weapon
	};
}


//物品属性的结构体
struct ObjectAttribute 
{
	FText ZH;
	FText EN;
	EObjectType::Type ObjectType;
	int PlantAttack;
	int MetalAttack;
	int AnimalAttack;
	int AttackRange;

	FString TexPath;

	ObjectAttribute(const FText ENName, const FText ZHName, const EObjectType::Type OT, const int PA, const int MA, const int AA, const int AR, const FString TP)
	{
		ZH = ZHName;
		EN = ENName;
		ObjectType = OT;
		PlantAttack = PA;
		MetalAttack = MA;
		AnimalAttack = AA;
		AttackRange = AR;
		TexPath = TP;
	}
};