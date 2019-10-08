// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"


class SEditableTextBox;

/**
 * 
 */
class STARCRAFTTPS_API SNewGameWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SNewGameWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//ȷ���Ƿ��ܽ�����Ϸ
	bool CanEnterGame();

private:

	//����ṹ��SCTPSWidgetStyle�������ģ�����洢��ˢ���ؼ���Ԫ��
	const struct FSCTPSStyle *MenueStyle;

	//�����ָ��
	TSharedPtr<SEditableTextBox>EditTextBox;
};