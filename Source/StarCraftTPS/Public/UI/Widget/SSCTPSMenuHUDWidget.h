// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SOverlay;
class SSCTPSMenuWidget;

/**
 * 
 */
class STARCRAFTTPS_API SSCTPSMenuHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSCTPSMenuHUDWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	float GetUIScaler()const;

	FVector2D GetViewportSize()const;

	FReply OnClick();

private:

	//这个结构是SCTPSWidgetStyle里声明的，里面存储画刷、控件等元素
	const struct FSCTPSStyle *MenueStyle;
	//DPI缩放系数
	TAttribute<float>UIScaler;
	//获取Image的Slot
	SOverlay::FOverlaySlot* ImageSlot;

	TSharedPtr<SSCTPSMenuWidget>MenueWidget;

};
