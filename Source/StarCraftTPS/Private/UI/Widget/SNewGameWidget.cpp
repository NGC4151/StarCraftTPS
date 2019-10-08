// Fill out your copyright notice in the Description page of Project Settings.

#include "SNewGameWidget.h"
#include "SlateOptMacros.h"
#include "Style/SCTPSStyle.h"
#include "SCTPSWidgetStyle.h"
#include "SBox.h"
#include "STextBlock.h"
#include "SOverlay.h"
#include "SEditableTextBox.h"
#include "SImage.h"
#include "SCTPSHandle.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SNewGameWidget::Construct(const FArguments& InArgs)
{
	//��ȡ�༭����MenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");



	ChildSlot
		[
			SNew(SBox)
			.WidthOverride(500.f)
		    .HeightOverride(100.f)
		[
			SNew(SOverlay)
	//����ͼƬ
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(&MenueStyle->MenuItemImage)
		]

	//����Ϸ�ı���
	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(FMargin(20.f, 0.f, 0.f, 0.f))
		[
			SNew(STextBlock)
			.Font(MenueStyle->Font_40)
		    .Text(NSLOCTEXT("SCTPSMenu", "NewGame", "NewGame"))
		]
	//����浵���Ŀɱ༭�ı���
	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0.f, 0.f, 20.f, 0.f))
		[
			//��һ��BOX�����ɱ༭�ı��򣬿��ƴ�С
			SNew(SBox)
			.WidthOverride(300.f)
		    .HeightOverride(60.f)
		[
			SAssignNew(EditTextBox, SEditableTextBox)
			.HintText(NSLOCTEXT("SCTPSMenu", "RenameRecord", "Input Record Name!"))
		    .Font(MenueStyle->Font_30)
		]

		]

		]

		];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

bool SNewGameWidget::CanEnterGame()
{
	//��ȡ����Ĵ浵��
	FText InputText = EditTextBox->GetText();
	//�ж��Ƿ�Ϊ���ַ�
	if (InputText.ToString().IsEmpty()) return false;
	//��ѯ�浵�Ƿ�����
	for (TArray<FString>::TIterator It(SCTPSHandle::Get()->SaveDataList);It;++It)
	{
		if ((*It).Equals(InputText.ToString()))
		{
			EditTextBox->SetText(FText::FromString(""));
			EditTextBox->SetHintText(NSLOCTEXT("SCTPSMenu","RenameDown", "Record Name Had Repeated!"));
			return false;
		}
	}

	//�����µĴ浵��
	SCTPSHandle::Get()->SaveName = InputText.ToString();
	return true;

	
}