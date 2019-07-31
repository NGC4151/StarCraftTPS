// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSMenuHUD.h"
#include "SSCTPSMenuHUDWidget.h"
#include "SlateBasics.h"

ASCTPSMenuHUD::ASCTPSMenuHUD()
{
	if (GEngine&&GEngine->GameViewport)
	{
		//创建一个MenuHUDWidget实例，并添加到视口
		SAssignNew(MenuHUDWidget, SSCTPSMenuHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(MenuHUDWidget.ToSharedRef());
	}
}
