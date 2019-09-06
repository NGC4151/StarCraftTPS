// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Data/SCTPSType.h"

//����һ������
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


	//��д�������갴����صļ����¼�
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)override;

	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)override;

	virtual void OnMouseLeave(const FPointerEvent& MouseEvent)override;

private:

	//��ȡ��ɫ
	FSlateColor GetTintColor()const;

private:
	//����ṹ��SCTPSWidgetStyle�������ģ�����洢��ˢ���ؼ���Ԫ��
	const struct FSCTPSStyle *MenueStyle;

	FItemClicked OnClicked;

	EMenuItem::Type ItemType;

	bool IsMouseButtonDown;

};