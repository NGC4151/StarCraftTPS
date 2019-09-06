// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCTPSMenuWidget.h"
#include "SlateOptMacros.h"
#include "SButton.h"
#include "Style/SCTPSStyle.h"
#include "SBox.h"
#include "STextBlock.h"
#include "SBorder.h"
#include "SSCTPSMenuItemWidget.h"
#include "SBoxPanel.h"
#include "SSCTPSGameOptionWidget.h"
#include "SCTPSHelper.h"
#include "SCTPSHandle.h"

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
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(SBox)
			.WidthOverride(400.f)
		    .HeightOverride(100.f)
		[
			SNew(SBorder)
			.BorderImage(&MenueStyle->TitleBorderImage)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SAssignNew(TitleText, STextBlock)
			.Font(SCTPSStyle::Get().GetFontStyle("MenuItemFont"))
		    .Text(NSLOCTEXT("SCTPSMenu","Menu","Menu"))
		]
		]
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		.Padding(FMargin(0.f, 130.f, 0.f, 0.f))
		[
			SAssignNew(ContentBox, SVerticalBox)
		]
		]

		];


	RootSizeBox->SetWidthOverride(519.f);
	RootSizeBox->SetHeightOverride(800.f);

	//
	ContentBox->AddSlot()
		[
			SNew(SSCTPSGameOptionWidget)
.ChangeCulture(this,&SSCTPSMenuWidget::ChangeCulture)
.ChangeVolume(this,&SSCTPSMenuWidget::ChangeVolume)
			
		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSCTPSMenuWidget::MenuItemOnClicked(EMenuItem::Type ItemType)
{
	SCTPSHelper::Debug(FString("Button had press down!"), 3.0f, FColor::Blue);
	
}

void SSCTPSMenuWidget::ChangeCulture(ECultureTeam Cultrue)
{
	SCTPSHandle::Get()->ChangeLanguage(Cultrue);
}

void SSCTPSMenuWidget::ChangeVolume(const float MusicVol, const float SoundVol)
{
	SCTPSHandle::Get()->ChangeVolume(MusicVol, SoundVol);
}
