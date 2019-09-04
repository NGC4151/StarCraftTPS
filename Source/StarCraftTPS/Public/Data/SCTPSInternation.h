// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class STARCRAFTTPS_API SCTPSInternation
{
public:
	static void Register(FText Value) {
		return;
	}
};

#define LOCTEXT_NAMESPACE "SCTPSMenu"

SCTPSInternation::Register(LOCTEXT("Menu","Menu"))
SCTPSInternation::Register(LOCTEXT("StartGame", "StartGame"))
SCTPSInternation::Register(LOCTEXT("GameOption", "GameOption"))
SCTPSInternation::Register(LOCTEXT("QuitGame", "QuitGame"))

SCTPSInternation::Register(LOCTEXT("NewGame", "NewGame"))
SCTPSInternation::Register(LOCTEXT("LoadRecord", "LoadRecord"))

SCTPSInternation::Register(LOCTEXT("SelectRecord", "SelectRecord"))

SCTPSInternation::Register(LOCTEXT("RecordName", "RecordName"))
SCTPSInternation::Register(LOCTEXT("EnterGame", "EnterGame"))
SCTPSInternation::Register(LOCTEXT("EnterRecord", "EnterRecord"))
SCTPSInternation::Register(LOCTEXT("RenameRecord", "Input Record Name!"))
SCTPSInternation::Register(LOCTEXT("RenameDown", "Record Name Had Repeated!"))

SCTPSInternation::Register(LOCTEXT("Chinese", "Chinese"))
SCTPSInternation::Register(LOCTEXT("English", "English"))
SCTPSInternation::Register(LOCTEXT("Music", "Music"))
SCTPSInternation::Register(LOCTEXT("Sound", "Sound"))
SCTPSInternation::Register(LOCTEXT("GoBack", "GoBack"))


#undef LOCTEXT_NAMESPACE