// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSMenuHUD.h"
#include "SSCTPSMenuHUDWidget.h"
#include "SlateBasics.h"

ASCTPSMenuHUD::ASCTPSMenuHUD()
{
	if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(MenuHUDWidget, SSCTPSMenuHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(MenuHUDWidget.ToSharedRef());
	}
}
