// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCTPSMenuWidget.h"
#include "SlateOptMacros.h"
#include "SButton.h"
#include "Style/SCTPSStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCTPSMenuWidget::Construct(const FArguments& InArgs)
{
	
	//»ñÈ¡±à¼­Æ÷µÄMenuStyle
	MenueStyle = &SCTPSStyle::Get().GetWidgetStyle<FSCTPSStyle>("BP_SCTPSMenuStyle");

	ChildSlot
		[
			SNew(SButton)
			.HAlign(HAlign_Center)
		    .VAlign(VAlign_Center)
		
		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
