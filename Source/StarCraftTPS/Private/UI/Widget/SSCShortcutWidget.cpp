// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCShortcutWidget.h"
#include "SlateOptMacros.h"
#include "Style/SCTPSStyle.h"
#include "SCGameWidgetStyle.h"
#include "SBox.h"
#include "STextBlock.h"
#include "SUniformGridPanel.h"
#include "SBorder.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCShortcutWidget::Construct(const FArguments& InArgs)
{
	GameStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCGameStyle>("BP_SCGameStyle");
	
	ChildSlot
		[
			SNew(SBox)
			.WidthOverride(900.f)
		.HeightOverride(160.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SAssignNew(ItemInfoTextBlock, STextBlock)
			.Font(GameStyle->Font_Outline_40)
		.ColorAndOpacity(GameStyle->FontColor_White)
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin(0.f, 60.f, 0.f, 0.f))
		[
			SAssignNew(UniformGridPanel, SUniformGridPanel)
		]
		]
		];

	IsInitContainer = false;
}

void SSCShortcutWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	if (!IsInitContainer)
	{
		InitContainer();
		IsInitContainer = true;
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSCShortcutWidget::InitContainer()
{
	for (int i = 0; i < 9; ++i)
	{
		//´´½¨ÈÝÆ÷
		TSharedPtr<class SBorder>Containerborder;
		TSharedPtr<class SBorder>ImageBorder;
		TSharedPtr<class STextBlock>NumTextBlock;

		SAssignNew(Containerborder, SBorder)
			.Padding(FMargin(10.f))
			//´ýÉ¾³ý
.BorderImage(&GameStyle->NormalContainerBrush)
			[
				SAssignNew(ImageBorder, SBorder)
				.HAlign(HAlign_Right)
			.VAlign(VAlign_Bottom)
			.Padding(FMargin(0.f, 0.f, 5.f, 0.f))
			.BorderImage(&GameStyle->EmptyBrush)
			[
				SAssignNew(NumTextBlock, STextBlock)
				.Font(GameStyle->Font_Outline_20)
			.ColorAndOpacity(GameStyle->FontColor_Black)
			//´ýÉ¾³ý
.Text(FText::FromString("99"))
			]
			];

		UniformGridPanel->AddSlot(i, 0)
			[
				Containerborder->AsShared()
			];
	}
}
