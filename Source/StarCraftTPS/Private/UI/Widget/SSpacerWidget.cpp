// Fill out your copyright notice in the Description page of Project Settings.

#include "SSpacerWidget.h"
#include "SlateOptMacros.h"
#include "SOverlay.h"
#include "SSPacer.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSpacerWidget::Construct(const FArguments& InArgs)
{
	InSpacerSize.Bind(this, &SSpacerWidget::SetSpacerSize);

	ChildSlot
	[
		SNew(SOverlay)
		+SOverlay::Slot()
.HAlign(HAlign_Fill)
.VAlign(VAlign_Fill)
[
	SNew(SSpacer)
.Size(InSpacerSize)

]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FVector2D SSpacerWidget::SetSpacerSize() const
{
	return FVector2D(0.f, 20.f);
}
