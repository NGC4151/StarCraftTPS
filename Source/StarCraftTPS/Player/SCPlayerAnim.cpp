// Fill out your copyright notice in the Description page of Project Settings.

#include "SCPlayerAnim.h"
#include "SCCharacter.h"
#include "SCTPSHelper.h"
#include <Animation/AnimMontage.h>

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

	//更新上半身的旋转
	float SpineDir = Charactor->GetActorRotation().Yaw - 90.f;
	if (SpineDir < -180.f)SpineDir += 180;
	if (SpineDir > 180.f)SpineDir -= 180;
	SpineRotator = FRotator(0.f, SpineDir, 90.f);
}

//根据Charactor->UpperType播放蒙太奇
void USCPlayerAnim::UpdateMontage()
{
	//如果charactor为空侧跳出
	if (!Charactor)return;

	//如果当前的动画没有播放玩则不更新动画
	if (!Montage_GetIsStopped(CurrentMontage))return;

	//如果角色视角和动画的视角不一致，则不更新动画，这个用来防止某个人称的动画播放时另一个人称的动画也同时播放
	if (Charactor->GameViewMode != GameViewMode)return;
	
	switch (Charactor->UpperType)
	{
	case EUpperBody::None:
		//当动画播放完后，将currentmontage设为空
		if (CurrentMontage != nullptr)
		{
			Montage_Stop(0);
			CurrentMontage = nullptr;
			CanChangeView(true);
		}
		break;
	case EUpperBody::Fire:
		if (!Montage_IsPlaying(Fire)) {
			Montage_Play(Fire);
			CurrentMontage = Fire;
			CanChangeView(false);
		}
		break;
	case EUpperBody::Reload:
		if (!Montage_IsPlaying(Reload)) {
			Montage_Play(Reload);
			CurrentMontage = Reload;
			CanChangeView(false);
		}
		break;
	case EUpperBody::Aim:
		if (!Montage_IsPlaying(Aim)) {
			Montage_Play(Aim);
			CurrentMontage = Aim;
			CanChangeView(false);
		}
		break;
	case EUpperBody::Pick:
		if (!Montage_IsPlaying(Pick)) {
			Montage_Play(Pick);
			CurrentMontage = Pick;
			CanChangeView(false);
		}
		break;
	case EUpperBody::Hit:
		if (!Montage_IsPlaying(Hit)) {
			Montage_Play(Hit);
			CurrentMontage = Hit;
			CanChangeView(false);
		}
		break;
	}
}

void USCPlayerAnim::CanChangeView(bool IsCanChange)
{
	if (!Charactor)return;

	Charactor->bCanChangeView = IsCanChange;
}

