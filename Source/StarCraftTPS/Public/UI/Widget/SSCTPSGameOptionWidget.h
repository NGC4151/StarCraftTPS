// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCTPSType.h"
#include "Widgets/SCompoundWidget.h"

class SCheckBox;
class SSlider;

//�޸����Ե�ί��
DECLARE_DELEGATE_OneParam(FChangeCulture, const ECultureTeam)
//�޸�������ί��
DECLARE_DELEGATE_TwoParams(FChangeVolume, const float, const float)

/**
 * 
 */
class STARCRAFTTPS_API SSCTPSGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSCTPSGameOptionWidget)
	{}
	SLATE_EVENT(FChangeCulture, ChangeCulture)
		SLATE_EVENT(FChangeVolume, ChangeVolume)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


private:

	//ͳһ������ʽ
	void StyleInitialized();

	//����CheckBox�¼�
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);
	//Ӣ����CheckBox�¼�
	void EnCheckBoxStateChanged(ECheckBoxState NewState);
	//��������
	void ChangeMusicValue(float Value);
	void ChangeSoundValue(float Value);

private:
	//����ṹ��SCTPSWidgetStyle�������ģ�����洢��ˢ���ؼ���Ԫ��
	const struct FSCTPSStyle *MenueStyle;
	//CheckBox��ָ��
	TSharedPtr<SCheckBox>EnCheckBox;
	TSharedPtr<SCheckBox>CnCheckBox;
	//����������ָ��
	TSharedPtr<SSlider>MusicSlider;
	TSharedPtr<SSlider>SoundSlider;
	//�������ٷֱ�
	TSharedPtr<STextBlock>MusicTextBlock;
	TSharedPtr<STextBlock>SoundTextBlock;

	//ί�б���
	FChangeCulture ChangeCulture;
	FChangeVolume ChangeVolume;


};