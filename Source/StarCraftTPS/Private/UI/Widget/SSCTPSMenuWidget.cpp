// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCTPSMenuWidget.h"
#include "SNewGameWidget.h"
#include "SChooseSaveDataWidget.h"
#include "SSCTPSGameOptionWidget.h"
#include "SSCTPSMenuItemWidget.h"
#include "SlateOptMacros.h"
#include "Style/SCTPSStyle.h"
#include "SCTPSWidgetStyle.h"
#include "SCTPSHelper.h"
#include "SCTPSHandle.h"
#include "SButton.h"
#include "SBox.h"
#include "STextBlock.h"
#include "SBorder.h"
#include "SBoxPanel.h"
#include "SSpacerWidget.h"


struct MenuGroup 
{
	//菜单标题
	FText MenuName;
	//菜单高度
	float MenuHeight;
	//下属组件
	TArray<TSharedPtr<SCompoundWidget>>ChildWidget;
	//构造函数
	MenuGroup(const FText Name, const float Height, TArray<TSharedPtr<SCompoundWidget>>* Children)
	{
		MenuName = Name;
		MenuHeight = Height;
		for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It(*Children);It;++It)
		{
			ChildWidget.Add(*It);
		}
	}
};




BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCTPSMenuWidget::Construct(const FArguments& InArgs)
{
	
	//获取编辑器的MenuStyle
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

	InitializedMenuList();

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

void SSCTPSMenuWidget::InitializedMenuList()
{
	//实例化主界面
	TArray<TSharedPtr<SCompoundWidget>>MainMenuList;
	MainMenuList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "StartGame", "StartGame")).ItemType(EMenuItem::StartGame).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));
	MainMenuList.Add(SNew(SSpacerWidget));
	MainMenuList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "GameOption", "GameOption")).ItemType(EMenuItem::GameOption).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));
	MainMenuList.Add(SNew(SSpacerWidget));
	MainMenuList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "QuitGame", "QuitGame")).ItemType(EMenuItem::QuitGame).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::MainMenu, MakeShareable(new MenuGroup(NSLOCTEXT("SCTPSMenu", "Menu", "Menu"), 510.f, &MainMenuList)));


	//开始游戏界面实例化
	TArray<TSharedPtr<SCompoundWidget>>StartGameList;
	StartGameList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "NewGame", "NewGame")).ItemType(EMenuItem::StartGame).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));
	StartGameList.Add(SNew(SSpacerWidget));
	StartGameList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "LoadRecord", "LoadRecord")).ItemType(EMenuItem::GameOption).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));
	StartGameList.Add(SNew(SSpacerWidget));
	StartGameList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "GoBack", "GoBack")).ItemType(EMenuItem::QuitGame).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::StartGame, MakeShareable(new MenuGroup(NSLOCTEXT("SCTPSMenu", "StartGame", "StartGame"), 510.f, &StartGameList)));


	//游戏设置界面实例化
	TArray<TSharedPtr<SCompoundWidget>>GameOptionList;
	SAssignNew(GameOptionWidget, SSCTPSGameOptionWidget)
		.ChangeCulture(this, &SSCTPSMenuWidget::ChangeCulture)  //绑定函数到委托
		.ChangeVolume(this, &SSCTPSMenuWidget::ChangeVolume);   //绑定函数到委托

	GameOptionList.Add(GameOptionWidget);
	GameOptionList.Add(SNew(SSpacerWidget));
	GameOptionList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "GoBack", "GoBack")).ItemType(EMenuItem::GameOptionGoback).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::GameOption, MakeShareable(new MenuGroup(NSLOCTEXT("SCTPSMenu", "GameOption", "GameOption"), 610.f, &GameOptionList)));


	//开始新游戏界面
	TArray<TSharedPtr<SCompoundWidget>>NewGameList;
	SAssignNew(NewGameWidget, SNewGameWidget);
	NewGameList.Add(NewGameWidget);
	NewGameList.Add(SNew(SSpacerWidget));
	NewGameList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "EnterGame", "EnterGame")).ItemType(EMenuItem::EnterGame).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));
	NewGameList.Add(SNew(SSpacerWidget));
	NewGameList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "GoBack", "GoBack")).ItemType(EMenuItem::NewGameGoBack).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::NewGame, MakeShareable(new MenuGroup(NSLOCTEXT("SCTPSMenu", "NewGame", "NewGame"), 510.f, &NewGameList)));

	//选择存档界面
	TArray<TSharedPtr<SCompoundWidget>>ChooseSaveDataList;
	SAssignNew(ChooseSaveDataWidget, SChooseSaveDataWidget);
	NewGameList.Add(ChooseSaveDataWidget);
	NewGameList.Add(SNew(SSpacerWidget));
	NewGameList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "EnterRecord", "EnterRecord")).ItemType(EMenuItem::EnterRecord).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));
	NewGameList.Add(SNew(SSpacerWidget));
	NewGameList.Add(SNew(SSCTPSMenuItemWidget).ItemText(NSLOCTEXT("SCTPSMenu", "GoBack", "GoBack")).ItemType(EMenuItem::SelecteRecordGoBack).OnClicked(this, &SSCTPSMenuWidget::MenuItemOnClicked));

	MenuMap.Add(EMenuType::ChooseSaveData, MakeShareable(new MenuGroup(NSLOCTEXT("SCTPSMenu", "LoadRecord", "LoadRecord"), 510.f, &ChooseSaveDataList)));


	//默认选择的控件
	ChooseWidget(EMenuType::MainMenu);



}

void SSCTPSMenuWidget::ChooseWidget(EMenuType::Type WidgetType)
{
	//移除组件
	ContentBox->ClearChildren();
	//如果MenuType是None
	if (WidgetType == EMenuType::None)return;
	//循环添加组件
	for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It((*MenuMap.Find(WidgetType))->ChildWidget);It;++It)
	{
		ContentBox->AddSlot().AutoHeight()[(*It)->AsShared()];
	}
	//更改标题
	TitleText->SetText((*MenuMap.Find(WidgetType))->MenuName);
	//修改Size
	ChangeWidgetSize(600.f, (*MenuMap.Find(WidgetType))->MenuHeight);


}

//如果不修改高度，NewHeight传入-1
void SSCTPSMenuWidget::ChangeWidgetSize(float NewWidth, float NewHeight)
{
	RootSizeBox->SetWidthOverride(NewWidth);
	if (NewHeight < 0)return;
	RootSizeBox->SetHeightOverride(NewHeight);
	
}
