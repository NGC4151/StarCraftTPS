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

	UpdateMontage();
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

void USCPlayerAnim::UpdateMontage()
{

	if (!Charactor)return;
	if (!Montage_IsPlaying(TPSReload))
	{
		Montage_Play(TPSReload);
	}
}

