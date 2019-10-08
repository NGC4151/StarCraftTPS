// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SCTPSWidgetStyle.h"

class STextComboBox;

/**
 * 
 */
class STARCRAFTTPS_API SChooseSaveDataWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SChooseSaveDataWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//���´浵��
	void UpdataSaveDataName();

private:

	//����ṹ��SCTPSWidgetStyle�������ģ�����洢��ˢ���ؼ���Ԫ��
	const struct FSCTPSStyle *MenueStyle;

	//�����˵�
	TSharedPtr<STextComboBox>SaveDataComboBox;
	
	//�����˵����ַ�ָ������
	TArray<TSharedPtr<FString>>OptionsSource;

};