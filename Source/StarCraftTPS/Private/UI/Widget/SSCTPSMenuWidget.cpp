// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCTPSMenuWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCTPSMenuWidget::Construct(const FArguments& InArgs)
{
	
	//��ȡ�༭����MenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");

	ChildSlot
	[
		
	];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
