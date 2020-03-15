// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSGameHUD.h"
#include "SSCGameHUDWidget.h"
#include "Engine/Engine.h"
#include "SlateBasics.h"

ASCTPSGameHUD::ASCTPSGameHUD()
{
	if (GEngine&&GEngine->GameViewport)
	{
		//创建HUD，并添加到视口 
		SAssignNew(GameHUDWidget, SSCGameHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(GameHUDWidget.ToSharedRef()));
	}

}
