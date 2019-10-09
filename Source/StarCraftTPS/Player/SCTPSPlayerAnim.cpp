// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSPlayerAnim.h"
#include "SCCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SCTPSHelper.h"

USCTPSPlayerAnim::USCTPSPlayerAnim()
{
	bIsInAir = false;
	Direction = 0.f;
}

void USCTPSPlayerAnim::UpdateParater()
{
	Super::UpdateParater();
	if (!Charactor)return;
	bIsInAir = Charactor->GetCharacterMovement()->IsFalling();
	float PreDir = Charactor->GetVelocity().ToOrientationRotator().Yaw - Charactor->GetActorRotation().Yaw;
	SCTPSHelper::Debug(FString("Charactor->GetVelocity=") + FString::SanitizeFloat(Charactor->GetVelocity().ToOrientationRotator().Yaw), 0.f);
	SCTPSHelper::Debug(FString("GetActorRotation=") + FString::SanitizeFloat(Charactor->GetActorRotation().Yaw), 0.f);
	SCTPSHelper::Debug(FString("PreDir=") + FString::SanitizeFloat(PreDir),0.f);
	if (PreDir > 180.f)PreDir -= 360.f;
	if (PreDir < -180)PreDir += 360.f;
	Direction = PreDir;
	SCTPSHelper::Debug(FString("Direction=") + FString::SanitizeFloat(Direction), 0.f);


}

