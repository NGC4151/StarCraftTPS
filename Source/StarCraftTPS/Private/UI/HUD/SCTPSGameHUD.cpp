// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSGameHUD.h"
#include "SSCGameHUDWidget.h"

ASCTPSGameHUD::ASCTPSGameHUD()
{
	if (GEngine&&GEngine->GameViewport)
	{
		SAssignNew(GameHUDWidget, SSCGameHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(GameHUDWidget.ToSharedRef());
	}

}
