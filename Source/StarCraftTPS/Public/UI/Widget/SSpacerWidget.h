// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SSpacer;

/**
 * 
 */
class STARCRAFTTPS_API SSpacerWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSpacerWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:

	FVector2D SetSpacerSize()const;
	TAttribute<FVector2D> InSpacerSize;

};
