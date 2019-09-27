// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"


class SEditableTextBox;

/**
 * 
 */
class STARCRAFTTPS_API SNewGameWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SNewGameWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//确认是否能进入游戏
	bool CanEnterGame();

private:

	//这个结构是SCTPSWidgetStyle里声明的，里面存储画刷、控件等元素
	const struct FSCTPSStyle *MenueStyle;

	//输入框指针
	TSharedPtr<SEditableTextBox>EditTextBox;
};
