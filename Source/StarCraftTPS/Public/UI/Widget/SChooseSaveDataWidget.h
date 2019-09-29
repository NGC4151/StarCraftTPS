// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SCTPSWidgetStyle.h"

class STextComboBox;

/**
 * 
 */
class STARCRAFTTPS_API SChooseSaveDataWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SChooseSaveDataWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//更新存档名
	void UpdataSaveDataName();

private:

	//这个结构是SCTPSWidgetStyle里声明的，里面存储画刷、控件等元素
	const struct FSCTPSStyle *MenueStyle;

	//下拉菜单
	TSharedPtr<STextComboBox>SaveDataComboBox;
	
	//下拉菜单的字符指针数组
	TArray<TSharedPtr<FString>>OptionsSource;

};
