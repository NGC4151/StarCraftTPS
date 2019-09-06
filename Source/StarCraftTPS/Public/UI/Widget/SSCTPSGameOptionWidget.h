// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCTPSType.h"
#include "Widgets/SCompoundWidget.h"

class SCheckBox;
class SSlider;

//修改语言的委托
DECLARE_DELEGATE_OneParam(FChangeCulture, const ECultureTeam)
//修改音量的委托
DECLARE_DELEGATE_TwoParams(FChangeVolume, const float, const float)

/**
 * 
 */
class STARCRAFTTPS_API SSCTPSGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSCTPSGameOptionWidget)
	{}
	SLATE_EVENT(FChangeCulture, ChangeCulture)
		SLATE_EVENT(FChangeVolume, ChangeVolume)
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
	//调整音量
	void ChangeMusicValue(float Value);
	void ChangeSoundValue(float Value);

private:
	//这个结构是SCTPSWidgetStyle里声明的，里面存储画刷、控件等元素
	const struct FSCTPSStyle *MenueStyle;
	//CheckBox的指针
	TSharedPtr<SCheckBox>EnCheckBox;
	TSharedPtr<SCheckBox>CnCheckBox;
	//两个滑条的指针
	TSharedPtr<SSlider>MusicSlider;
	TSharedPtr<SSlider>SoundSlider;
	//进度条百分比
	TSharedPtr<STextBlock>MusicTextBlock;
	TSharedPtr<STextBlock>SoundTextBlock;

	//委托变量
	FChangeCulture ChangeCulture;
	FChangeVolume ChangeVolume;


};
