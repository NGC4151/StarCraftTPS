// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCTPSMenuWidget.h"
#include "SlateOptMacros.h"
#include "SButton.h"
#include "Style/SCTPSStyle.h"
#include	"SBox.h"
#include "STextBlock.h"
#include "SBorder.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCTPSMenuWidget::Construct(const FArguments& InArgs)
{
	
	//»ñÈ¡±à¼­Æ÷µÄMenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");

	ChildSlot
		[
			SAssignNew(RootSizeBox,SBox)
			.HAlign(HAlign_Center)
		    .VAlign(VAlign_Center)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin(0.f, 50.f, 0.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenueStyle->MenueImage)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0.f, 25.f, 0.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenueStyle->RightIconImage)
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0.f, 25.f, 0.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenueStyle->LeftIconImage)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(SBox)
			.WidthOverride(288.f)
		.HeightOverride(68.f)
		[
			SNew(SBorder)
			.BorderImage(&MenueStyle->TitleBorderImage)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SAssignNew(TitleText, STextBlock)
			.Font(SCTPSStyle::Get().GetFontStyle("MenuItemFont"))
		    .Text(FText::FromString("StarCraft"))
		]
		]
		]

		]

		];
	RootSizeBox->SetWidthOverride(519.f);
	RootSizeBox->SetHeightOverride(800.f);

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
