// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCTPSMenuItemWidget.h"
#include "SlateOptMacros.h"
#include "SCTPSStyle.h"
#include "SCTPSWidgetStyle.h"
#include "SBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCTPSMenuItemWidget::Construct(const FArguments& InArgs)
{
	//»ñÈ¡±à¼­Æ÷µÄMenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");

	OnClicked = InArgs._OnClicked;
	ItemType = InArgs._ItemType.Get();
	
	ChildSlot
	[
		SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(100.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
.Padding(FMargin(10.f,0.f,10.f,0.f))
		[
			SNew(SImage)
			.Image(&MenueStyle->MenuItemImage)
.ColorAndOpacity(this,&SSCTPSMenuItemWidget::GetTintColor)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(InArgs._ItemText)
		    .Font(MenueStyle->Font_60)
		]
		]

	];

	IsMouseButtonDown = false;
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SSCTPSMenuItemWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	IsMouseButtonDown = true;
	return FReply::Handled();
}

FReply SSCTPSMenuItemWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (IsMouseButtonDown)
	{
		IsMouseButtonDown = false;
		OnClicked.ExecuteIfBound(ItemType);
	}
	return FReply::Handled();
}

void SSCTPSMenuItemWidget::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	IsMouseButtonDown = false;
}

FSlateColor SSCTPSMenuItemWidget::GetTintColor() const
{
	if (IsMouseButtonDown) return FLinearColor(0.1f, 0.1f, 1.0f, 0.5f);
	return FLinearColor(1.f, 1.f, 1.f, 1.f);
}

