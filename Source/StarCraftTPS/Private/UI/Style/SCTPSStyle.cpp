// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSStyle.h"
#include "SlateGameResources.h"

TSharedPtr<FSlateStyleSet>SCTPSStyle::SCTPSStyleInstance = NULL;

void SCTPSStyle::Initiazle()
{
	if (!SCTPSStyleInstance.IsValid())
	{
		SCTPSStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*SCTPSStyleInstance);
	}
}

void SCTPSStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*SCTPSStyleInstance);
	ensure(SCTPSStyleInstance.IsUnique());
	SCTPSStyleInstance.Reset();
}

FName SCTPSStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("SCTPSStyle"));
	return StyleSetName;
}

const ISlateStyle& SCTPSStyle::Get()
{
	return *SCTPSStyleInstance;
}

TSharedRef<class FSlateStyleSet> SCTPSStyle::Create()
{
	TSharedRef<FSlateStyleSet>StyleRef = FSlateGameResources::New(SCTPSStyle::GetStyleSetName, "/Game/UI/Style", "/Game/UI/Style");
	return StyleRef;
}
