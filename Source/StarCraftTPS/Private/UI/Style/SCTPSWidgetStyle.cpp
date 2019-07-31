// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSWidgetStyle.h"

FSCTPSStyle::FSCTPSStyle()
{
}

FSCTPSStyle::~FSCTPSStyle()
{
}

const FName FSCTPSStyle::TypeName(TEXT("FSCTPSStyle"));

const FSCTPSStyle& FSCTPSStyle::GetDefault()
{
	static FSCTPSStyle Default;
	return Default;
}

void FSCTPSStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

