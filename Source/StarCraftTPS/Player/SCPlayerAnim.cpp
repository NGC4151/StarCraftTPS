// Fill out your copyright notice in the Description page of Project Settings.

#include "SCPlayerAnim.h"
#include "SCCharacter.h"
#include "SCTPSHelper.h"

USCPlayerAnim::USCPlayerAnim()
{
	Speed = 0.f;
	SpineRotator = FRotator(0.f, 0.f, 0.f);
}

void USCPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	GetCharactorPointer();

	UpdateParater();
}

void USCPlayerAnim::GetCharactorPointer()
{
	if (!Charactor) Charactor = Cast<ASCCharacter>(TryGetPawnOwner());
}

void USCPlayerAnim::UpdateParater()
{
	if (!Charactor)return;
	Speed = Charactor->GetVelocity().Size();
}


