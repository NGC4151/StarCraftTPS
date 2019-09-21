// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *Ä£°åµ¥Àý 
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


template<class T>
TSharedPtr<T>SCTPSSingleton<T>::TInstance = NULL;

template<class T>
void SCTPSSingleton<T>::Initialize()
{

	if (!TInstance.IsValid())
	{
		TInstance = Create();
	}
}

template<class T>
TSharedRef<T> SCTPSSingleton<T>::Create()
{
	TSharedRef<T>TRef = MakeShareable(new T());
	return TRef;
}

template<class T>
TSharedPtr<T> SCTPSSingleton<T>::Get()
{
	Initialize();
	return TInstance;
}

