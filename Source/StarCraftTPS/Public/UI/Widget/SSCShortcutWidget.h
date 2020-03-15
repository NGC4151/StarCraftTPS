// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class STARCRAFTTPS_API SSCShortcutWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSCShortcutWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)override;

private:
	//��ʼ�����������ڵ�����
	void InitContainer();

private:
	const struct FSCGameStyle* GameStyle;

	//��Ʒ��Ϣ�ı����ָ��
	TSharedPtr<class STextBlock>ItemInfoTextBlock;

	//����ؼ�ָ��
	TSharedPtr<class SUniformGridPanel>UniformGridPanel;

	//�Ƿ��ʼ������
	bool IsInitContainer;
};