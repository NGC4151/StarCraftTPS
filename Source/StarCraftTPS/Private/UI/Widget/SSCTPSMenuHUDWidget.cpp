// Fill out your copyright notice in the Description page of Project Settings.

#include "SSCTPSMenuHUDWidget.h"
#include "SButton.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSCTPSMenuHUDWidget::Construct(const FArguments& InArgs)
{
	
	ChildSlot
	[
		SNew(SButton)
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
