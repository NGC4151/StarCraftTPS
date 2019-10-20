// Fill out your copyright notice in the Description page of Project Settings.

#include "SCFPSPlayerAnim.h"
#include <ConstructorHelpers.h>
#include <Animation/AnimMontage.h>

USCFPSPlayerAnim::USCFPSPlayerAnim()
{
	//从编辑器资源目录寻找文件
	static ConstructorHelpers::FObjectFinder<UAnimMontage>FPPReload(TEXT("AnimMontage'/Game/Animations/FPP_Animations/HeroFPP_RifleReload_Montage.HeroFPP_RifleReload_Montage'"));
	Reload = FPPReload.Object;
}
