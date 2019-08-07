// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCTPSMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include "SButton.h"
#include "SOverlay.h"
#include "SImage.h"
#include "SCTPSStyle.h"
#include "SCTPSWidgetStyle.h"
#include "SDPIScaler.h"
#include "SSCTPSMenuWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCTPSMenuHUDWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器的MenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");

	//将UIScaler绑定到GetUIScaler函数，UIScaler通过这个函数不断更新
	UIScaler.Bind(this, &SSCTPSMenuHUDWidget::GetUIScaler);

	ChildSlot
		[
			SNew(SDPIScaler)
			.DPIScale(UIScaler)
		    [
				SNew(SOverlay)
					+ SOverlay::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					[
						SNew(SImage)
						.Image(&MenueStyle->MenueHUDBackgroundBrush)
					]
				+ SOverlay::Slot()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
                    .Expose(ImageSlot)
					[
						SAssignNew(MenueWidget,SSCTPSMenuWidget)
					]
				+ SOverlay::Slot()
					.HAlign(HAlign_Left)
					.VAlign(VAlign_Top)
					[
						SNew(SButton)
						.OnClicked(this, &SSCTPSMenuHUDWidget::OnClick)
					]
			]

		];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

float SSCTPSMenuHUDWidget::GetUIScaler() const
{
	return GetViewportSize().Y / 1080.f;
}

FVector2D SSCTPSMenuHUDWidget::GetViewportSize() const
{
	FVector2D Result(1920, 1080);
	if (GEngine&&GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(Result);
	}

	return Result;
}

FReply SSCTPSMenuHUDWidget::OnClick()
{
	ImageSlot->HAlign(HAlign_Right).VAlign(VAlign_Bottom);
	return FReply::Handled();
}
