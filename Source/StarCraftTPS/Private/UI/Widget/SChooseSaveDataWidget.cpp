// Fill out your copyright notice in the Description page of Project Settings.

#include "SChooseSaveDataWidget.h"
#include "SlateOptMacros.h"
#include "Style/SCTPSStyle.h"
#include "SCTPSWidgetStyle.h"
#include "SBox.h"
#include "STextBlock.h"
#include "SOverlay.h"
#include "STextComboBox.h"
#include "SImage.h"
#include "SCTPSHandle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SChooseSaveDataWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器的MenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");

	//初始化下拉菜单数据
	for (TArray<FString>::TIterator It(SCTPSHandle::Get()->SaveDataList); It; ++It)
	{
		OptionsSource.Add(MakeShareable(new FString(*It)));
	}

	
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
			SAssignNew(SaveDataComboBox,STextComboBox)
.Font(MenueStyle->Font_30)
.OptionsSource(&OptionsSource)
		]

		]

		]
	];
	//设置下拉框的默认项
	SaveDataComboBox->SetSelectedItem(OptionsSource[0]);

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SChooseSaveDataWidget::UpdataSaveDataName()
{
	SCTPSHandle::Get()->SaveName = *SaveDataComboBox->GetSelectedItem().Get();
}
