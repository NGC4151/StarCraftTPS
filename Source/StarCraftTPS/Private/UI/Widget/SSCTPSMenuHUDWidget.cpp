// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCTPSMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include "SButton.h"
#include "SOverlay.h"
#include "SImage.h"
#include "SCTPSStyle.h"
#include "SCTPSWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCTPSMenuHUDWidget::Construct(const FArguments& InArgs)
{
	//»ñÈ¡±à¼­Æ÷µÄMenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");

	ChildSlot
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
		[
			SNew(SImage)
			.Image(&MenueStyle->MenueImage)
		]

		];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
