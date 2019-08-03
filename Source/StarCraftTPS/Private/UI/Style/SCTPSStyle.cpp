// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSStyle.h"
#include "SlateGameResources.h"

//单例模式变量不可以放在构造函数里，必须放在这里
TSharedPtr<FSlateStyleSet>SCTPSStyle::SCTPSStyleInstance = NULL;

void SCTPSStyle::Initiazle()
{
	if (!SCTPSStyleInstance.IsValid())
	{
		SCTPSStyleInstance = Create();
		//注册Style
		FSlateStyleRegistry::RegisterSlateStyle(*SCTPSStyleInstance);
	}
}

void SCTPSStyle::Shutdown()
{
	//注销Style
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
	TSharedRef<FSlateStyleSet>StyleRef = FSlateGameResources::New(SCTPSStyle::GetStyleSetName(), "/Game/UI/Style", "/Game/UI/Style");
	return StyleRef;
}
