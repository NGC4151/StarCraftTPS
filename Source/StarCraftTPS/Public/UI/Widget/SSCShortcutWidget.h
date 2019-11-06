// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class STARCRAFTTPS_API SSCShortcutWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSCShortcutWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)override;

private:
	//初始化所有网格内的容器
	void InitContainer();

private:
	const struct FSCGameStyle* GameStyle;

	//物品信息文本块的指针
	TSharedPtr<class STextBlock>ItemInfoTextBlock;

	//网格控件指针
	TSharedPtr<class SUniformGridPanel>UniformGridPanel;

	//是否初始化容器
	bool IsInitContainer;
};
