// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCTPSType.h"
#include "Widgets/SCompoundWidget.h"

class SCheckBox;

/**
 * 
 */
class STARCRAFTTPS_API SSCTPSGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSCTPSGameOptionWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


private:

	//统一设置样式
	void StyleInitialized();

	//中文CheckBox事件
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);
	//英文文CheckBox事件
	void EnCheckBoxStateChanged(ECheckBoxState NewState);

private:
	//这个结构是SCTPSWidgetStyle里声明的，里面存储画刷、控件等元素
	const struct FSCTPSStyle *MenueStyle;
	//CheckBox的指针
	TSharedPtr<SCheckBox>EnCheckBox;
	TSharedPtr<SCheckBox>CnCheckBox;

};
