// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Style/SCTPSWidgetStyle.h"

/**
 * 
 */
class STARCRAFTTPS_API SSCTPSMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSCTPSMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	//这个结构是SCTPSWidgetStyle里声明的，里面存储画刷、控件等元素
	const struct FSCTPSStyle *MenueStyle;
};
