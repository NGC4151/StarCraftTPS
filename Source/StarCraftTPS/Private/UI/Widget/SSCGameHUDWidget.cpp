// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCGameHUDWidget.h"
#include "SlateOptMacros.h"
#include "SDPIScaler.h"
#include "SOverlay.h"
#include "SSCShortcutWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCGameHUDWidget::Construct(const FArguments& InArgs)
{
	UIScaler.Bind(this, &SSCGameHUDWidget::GetUIScaler);
	
	ChildSlot
	[
		SNew(SDPIScaler)
.DPIScale(UIScaler)
[
	SNew(SOverlay)
	+SOverlay::Slot()
.HAlign(HAlign_Center)
.VAlign(VAlign_Bottom)
[
	SAssignNew(ShortcutWidget, SSCShortcutWidget)
]
]
	];

}

float SSCGameHUDWidget::GetUIScaler()const
{
	return GetViewportSize().Y / 1080.f;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FVector2D SSCGameHUDWidget::GetViewportSize()const
{
	FVector2D Result(1920.f, 1080.f);
	if (GEngine&&GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(Result);
	}
	return Result;
}
