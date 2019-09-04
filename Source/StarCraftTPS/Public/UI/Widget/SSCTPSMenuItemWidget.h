// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Data/SCTPSType.h"

//声明一个代理
DECLARE_DELEGATE_OneParam(FItemClicked,const EMenuItem::Type)

/**
 * 
 */
class STARCRAFTTPS_API SSCTPSMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSCTPSMenuItemWidget)
	{}


	SLATE_ATTRIBUTE(FText, ItemText)
	SLATE_EVENT(FItemClicked, OnClicked)
	SLATE_ATTRIBUTE(EMenuItem::Type, ItemType)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	//重写组件的鼠标按键相关的几个事件
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)override;

	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)override;

	virtual void OnMouseLeave(const FPointerEvent& MouseEvent)override;

private:

	//获取颜色
	FSlateColor GetTintColor()const;

private:
	//这个结构是SCTPSWidgetStyle里声明的，里面存储画刷、控件等元素
	const struct FSCTPSStyle *MenueStyle;

	FItemClicked OnClicked;

	EMenuItem::Type ItemType;

	bool IsMouseButtonDown;

};
