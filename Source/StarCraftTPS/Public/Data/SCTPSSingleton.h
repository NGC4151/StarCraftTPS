// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *ģ�嵥�� 
 */
template<class T> 
class STARCRAFTTPS_API SCTPSSingleton
{
public:
	static TSharedPtr<T>Get();

private:
	static TSharedRef<T>Create();

	static void Initialize();

private:
	static TSharedPtr<T>TInstance;
	
};

