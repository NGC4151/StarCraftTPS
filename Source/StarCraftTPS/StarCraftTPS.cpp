// Fill out your copyright notice in the Description page of Project Settings.

#include "StarCraftTPS.h"
#include "Modules/ModuleManager.h"
#include "SCTPSStyle.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FSCTPSModule, StarCraftTPS, "StarCraftTPS" );



void FSCTPSModule::StartupModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(SCTPSStyle::GetStyleSetName());
	SCTPSStyle::Initiazle();
}

void FSCTPSModule::ShutdownModule()
{
	SCTPSStyle::Shutdown();
}
