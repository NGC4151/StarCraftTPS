// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class STARCRAFTTPS_API SSCGameHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSCGameHUDWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	float GetUIScaler()const;

public:
	//快捷栏指针
	TSharedPtr<class SSCShortcutWidget>ShortcutWidget;

private:

	FVector2D GetViewportSize()const;

private:
	//DPI缩放的值
	TAttribute<float>UIScaler;
};
