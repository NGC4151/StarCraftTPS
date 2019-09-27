// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SCTPSType.h"


class SBox;
class STextBlock;
class SVerticalBox;



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

private:
	//绑定到各个MenuItem的方法
	void MenuItemOnClicked(EMenuItem::Type ItemType);
	//修改语言
	void ChangeCulture(ECultureTeam Cultrue);
	//修改音量
	void ChangeVolume(const float MusicVol, const float SoundVol);


private:
	//保存根节点的
	TSharedPtr<SBox>RootSizeBox;
	//保存标题
	TSharedPtr<STextBlock>TitleText;
	//这个结构是SCTPSWidgetStyle里声明的，里面存储画刷、控件等元素
	const struct FSCTPSStyle *MenueStyle;
	//垂直面板的指针
	TSharedPtr<SVerticalBox>ContentBox;

	
};
