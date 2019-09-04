// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSHandle.h"

TSharedPtr<SCTPSHandle>SCTPSHandle::DataInstans = NULL;

void SCTPSHandle::Initialize()
{
	if (!DataInstans.IsValid())
	{
		DataInstans = Create();
	}
}

TSharedPtr<SCTPSHandle> SCTPSHandle::Get()
{
	Initialize();
	return DataInstans;
}

void SCTPSHandle::ChangeLanguage(ECultureTeam Culture)
{
	switch (Culture)
	{
	case ECultureTeam::EN:
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
		break;
	case ECultureTeam::ZN:
		FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
		break;
	}

	CurrentCultrue = Culture;
}

TSharedRef<SCTPSHandle> SCTPSHandle::Create()
{
	TSharedRef<SCTPSHandle>DataRef = MakeShareable(new SCTPSHandle());
	return DataRef;
}

SCTPSHandle::SCTPSHandle()
{
}



