// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"

/**
 * 一个纯C++类，用于Style的注册和注销
 */
class STARCRAFTTPS_API SCTPSStyle
{
public:
	/*初始化，创建一个Style实例并将其注册到编辑器*/
	static void Initiazle();

	/*注销Style实例并将其Reset*/
	static void Shutdown();

	/*设置Style的名字，然后通过这个名字在Game目录中找到这个名字的文件*/
	static FName GetStyleSetName();

	/*获取Style实例*/
	static const ISlateStyle& Get();

private:
	/*创建一个Style实例，返回实例的引用*/
	static TSharedRef<class FSlateStyleSet>Create();

	static TSharedPtr<FSlateStyleSet>SCTPSStyleInstance;

};
