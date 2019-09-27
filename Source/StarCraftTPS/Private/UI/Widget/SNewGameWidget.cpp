// Fill out your copyright notice in the Description page of Project Settings.

#include "SNewGameWidget.h"
#include "SlateOptMacros.h"
#include "Style/SCTPSStyle.h"
#include "SCTPSWidgetStyle.h"
#include "SBox.h"
#include "STextBlock.h"
#include "SOverlay.h"
#include "SEditableTextBox.h"
#include "SImage.h"
#include "SCTPSHandle.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SNewGameWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器的MenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");



	ChildSlot
		[
			SNew(SBox)
			.WidthOverride(500.f)
		    .HeightOverride(100.f)
		[
			SNew(SOverlay)
	//背景图片
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(&MenueStyle->MenuItemImage)
		]

	//新游戏文本框
	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(FMargin(20.f, 0.f, 0.f, 0.f))
		[
			SNew(STextBlock)
			.Font(MenueStyle->Font_40)
		    .Text(NSLOCTEXT("SCTPSMenu", "NewGame", "NewGame"))
		]
	//输入存档名的可编辑文本框
	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0.f, 0.f, 20.f, 0.f))
		[
			//用一个BOX包含可编辑文本框，控制大小
			SNew(SBox)
			.WidthOverride(300.f)
		    .HeightOverride(60.f)
		[
			SAssignNew(EditTextBox, SEditableTextBox)
			.HintText(NSLOCTEXT("SCTPSMenu", "RenameRecord", "Input Record Name!"))
		    .Font(MenueStyle->Font_30)
		]

		]

		]

		];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

bool SNewGameWidget::CanEnterGame()
{
	//获取输入的存档名
	FText InputText = EditTextBox->GetText();
	//判断是否为空字符
	if (InputText.ToString().IsEmpty()) return false;
	//查询存档是否重名
	for (TArray<FString>::TIterator It(SCTPSHandle::Get()->SaveDataList);It;++It)
	{
		if ((*It).Equals(InputText.ToString()))
		{
			EditTextBox->SetText(FText::FromString(""));
			EditTextBox->SetHintText(NSLOCTEXT("SCTPSMenu","RenameDown", "Record Name Had Repeated!"));
			return false;
		}
	}

	//保存新的存档名
	SCTPSHandle::Get()->SaveName = InputText.ToString();
	return true;

	
}
