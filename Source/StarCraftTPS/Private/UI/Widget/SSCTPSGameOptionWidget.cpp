// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCTPSGameOptionWidget.h"
#include "SlateOptMacros.h"
#include "SCTPSStyle.h"
#include "SCTPSWidgetStyle.h"
#include "SBox.h"
#include "SImage.h"
#include "SBorder.h"
#include "SOverlay.h"
#include "STextBlock.h"
#include "SBoxPanel.h"
#include "SCheckBox.h"
#include "SCTPSHandle.h"
#include "SSlider.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCTPSGameOptionWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器的MenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");

	//获取委托
	ChangeCulture = InArgs._ChangeCulture;
	ChangeVolume = InArgs._ChangeVolume;

	ChildSlot
		[
			SNew(SBox)
		.WidthOverride(500.f)
		.HeightOverride(300.f)
		[
			SNew(SOverlay)
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
		.Image(&MenueStyle->SettingsBackgroundImage)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin(50.f))
		[
			SNew(SVerticalBox)
//第一行
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SHorizontalBox)

	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		.FillWidth(1.f)
		[
			SAssignNew(CnCheckBox, SCheckBox)
			.OnCheckStateChanged(this, &SSCTPSGameOptionWidget::ZhCheckBoxStateChanged)
		[
			SNew(STextBlock)
		.Font(MenueStyle->Font_30)
		.ColorAndOpacity(MenueStyle->FontColor_W)
		.Text(NSLOCTEXT("SCTPSMenu", "Chinese", "Chinese"))
		]
		]

	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		.FillWidth(1.f)
		[
			SAssignNew(EnCheckBox, SCheckBox)
			.OnCheckStateChanged(this, &SSCTPSGameOptionWidget::EnCheckBoxStateChanged)
		[
			SNew(STextBlock)
		.Font(MenueStyle->Font_30)
		.ColorAndOpacity(MenueStyle->FontColor_W)
		.Text(NSLOCTEXT("SCTPSMenu", "English", "English"))
		]
		]
		]
	//第二行
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(MenueStyle->Font_30)
		.ColorAndOpacity(MenueStyle->FontColor_W)
		.Text(NSLOCTEXT("SCTPSMenu", "Music", "Music"))
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SBox)
			.WidthOverride(240.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		.Padding(FMargin(30.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenueStyle->SliderImage)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		[
			SAssignNew(MusicSlider, SSlider)
			.Style(&MenueStyle->MySliderStyle)
		.OnValueChanged(this, &SSCTPSGameOptionWidget::ChangeMusicValue)
		]


		]
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		[
			SAssignNew(MusicTextBlock, STextBlock)
			.Font(MenueStyle->Font_40)
		.ColorAndOpacity(MenueStyle->FontColor_W)

		]
		]
//第三行
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(MenueStyle->Font_30)
		.ColorAndOpacity(MenueStyle->FontColor_W)
		.Text(NSLOCTEXT("SCTPSMenu", "Sound", "Sound"))
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SBox)
			.WidthOverride(240.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		.Padding(FMargin(30.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenueStyle->SliderImage)
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		[
			SAssignNew(SoundSlider, SSlider)
			.Style(&MenueStyle->MySliderStyle)
		.OnValueChanged(this, &SSCTPSGameOptionWidget::ChangeSoundValue)
		]


		]
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		[
			SAssignNew(SoundTextBlock, STextBlock)
			.Font(MenueStyle->Font_40)
		.ColorAndOpacity(MenueStyle->FontColor_W)

		]
		]

		]

		]
		];
	
	StyleInitialized();
}

void SSCTPSGameOptionWidget::StyleInitialized()
{
	//设置CnCheckBox的样式
	CnCheckBox->SetUncheckedImage(&MenueStyle->CheckBoxNoSelectedImage);
	CnCheckBox->SetUncheckedHoveredImage(&MenueStyle->CheckBoxNoSelectedImage);
	CnCheckBox->SetCheckedPressedImage(&MenueStyle->CheckBoxSelectedImage);
	CnCheckBox->SetCheckedImage(&MenueStyle->CheckBoxSelectedImage);
	CnCheckBox->SetCheckedHoveredImage(&MenueStyle->CheckBoxSelectedImage);
	CnCheckBox->SetCheckedPressedImage(&MenueStyle->CheckBoxSelectedImage);

	//设置EnCheckBox的样式
	EnCheckBox->SetUncheckedImage(&MenueStyle->CheckBoxNoSelectedImage);
	EnCheckBox->SetUncheckedHoveredImage(&MenueStyle->CheckBoxNoSelectedImage);
	EnCheckBox->SetCheckedPressedImage(&MenueStyle->CheckBoxSelectedImage);
	EnCheckBox->SetCheckedImage(&MenueStyle->CheckBoxSelectedImage);
	EnCheckBox->SetCheckedHoveredImage(&MenueStyle->CheckBoxSelectedImage);
	EnCheckBox->SetCheckedPressedImage(&MenueStyle->CheckBoxSelectedImage);

	switch (SCTPSHandle::Get()->CurrentCultrue)
	{
	case ECultureTeam::EN:
		EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
		CnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		break;
	case ECultureTeam::ZN:
		EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		CnCheckBox->SetIsChecked(ECheckBoxState::Checked);
		break;

	}

	SoundTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(SCTPSHandle::Get()->SoundValue * 100)) 
		+ FString("%")));
	MusicTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(SCTPSHandle::Get()->MusicValue * 100))
		+ FString("%")));

	MusicSlider->SetValue(SCTPSHandle::Get()->MusicValue);
	SoundSlider->SetValue(SCTPSHandle::Get()->SoundValue);

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSCTPSGameOptionWidget::ZhCheckBoxStateChanged(ECheckBoxState NewState)
{
	//当CheckBox被点击时设置CheckBox的状态
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	CnCheckBox->SetIsChecked(ECheckBoxState::Checked);
	//改变语言
	//SCTPSHandle::Get()->ChangeLanguage(ECultureTeam::ZN);
	ChangeCulture.ExecuteIfBound(ECultureTeam::ZN);
}

void SSCTPSGameOptionWidget::EnCheckBoxStateChanged(ECheckBoxState NewState)
{
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
	CnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);

	//改变语言
	//SCTPSHandle::Get()->ChangeLanguage(ECultureTeam::EN);
	ChangeCulture.ExecuteIfBound(ECultureTeam::EN);
}

void SSCTPSGameOptionWidget::ChangeMusicValue(float Value)
{
	MusicTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));
	//SCTPSHandle::ChangeVolume(Value, -1);
	ChangeVolume.ExecuteIfBound(Value, -1);
}

void SSCTPSGameOptionWidget::ChangeSoundValue(float Value)
{
	SoundTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));
	//SCTPSHandle::ChangeVolume(-1, -Value);
	ChangeVolume.ExecuteIfBound(-1, Value);
}
