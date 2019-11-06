// Fill out your copyright notice in the Description page of Project Settings.

#include "SCGameWidgetStyle.h"

FSCGameStyle::FSCGameStyle()
{
}

FSCGameStyle::~FSCGameStyle()
{
}

const FName FSCGameStyle::TypeName(TEXT("FSCGameStyle"));

const FSCGameStyle& FSCGameStyle::GetDefault()
{
	static FSCGameStyle Default;
	return Default;
}

void FSCGameStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

