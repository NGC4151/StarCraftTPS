// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SCTPSType.h"


class SBox;
class STextBlock;
class SVerticalBox;
class SSCTPSGameOptionWidget;
class SNewGameWidget;
class SChooseSaveDataWidget;
struct MenuGroup;



/**
 * 
 */
class STARCRAFTTPS_API SSCTPSMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSCTPSMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)override;

private:
	//绑定到各个MenuItem的方法
	void MenuItemOnClicked(EMenuItem::Type ItemType);
	//修改语言
	void ChangeCulture(ECultureTeam Cultrue);
	//修改音量
	void ChangeVolume(const float MusicVol, const float SoundVol);
	//初始化所有控件
	void InitializedMenuList();
	//选择Widget
	void ChooseWidget(EMenuType::Type WidgetType);
	//修改控件宽和高
	void ChangeWidgetSize(float Newwidth, float NewHeight);
	//初始化动画
	void InitializedAnimation();
	//通知某个控件播放动画
	void PlayAnimation(EMenuType::Type MenuType);


private:
	//保存根节点的
	TSharedPtr<SBox>RootSizeBox;
	//保存标题
	TSharedPtr<STextBlock>TitleText;
	//这个结构是SCTPSWidgetStyle里声明的，里面存储画刷、控件等元素
	const struct FSCTPSStyle *MenueStyle;
	//垂直面板的指针
	TSharedPtr<SVerticalBox>ContentBox;
	//保存菜单组
	TMap<EMenuType::Type, TSharedPtr<MenuGroup>>MenuMap;
	//新游戏控件的指针
	TSharedPtr<SNewGameWidget>NewGameWidget;
	//游戏设置控件的指针
	TSharedPtr<SSCTPSGameOptionWidget>GameOptionWidget;
	//选择存档控件指针
	TSharedPtr<SChooseSaveDataWidget>ChooseSaveDataWidget;


	//曲线动画播放器
	FCurveSequence MenuAnimation;
	//曲线控制器
	FCurveHandle CurveHandle;
	//保存当前高度
	float CurrentHeight;
	//控件是否显示
	bool IsWidgetShow;
	//按键是否锁住
	bool ControlLocked;
	//保存当前的动画状态
	EMenuAnim::Type AnimState;
	//保存当前的菜单
	EMenuType::Type CurrentMenu;



	
};
