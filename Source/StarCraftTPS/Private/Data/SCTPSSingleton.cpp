// Fill out your copyright notice in the Description page of Project Settings.

#include "SCTPSSingleton.h"

template<class T>
TSharedPtr<T>SCTPSSingleton<T>::TInstance = NULL;

template<class T>
void SCTPSSingleton<T>::Initialize()
{
	TSharedRef<T>TRef = MakeShareable(new T());
	return TRef;
}

template<class T>
TSharedRef<boost::T> SCTPSSingleton<T>::Create()
{
	if (!TInstance.IsValid())
	{
		TInstance = Create();
	}
}

template<class T>
TSharedPtr<boost::T> SCTPSSingleton<T>::Get()
{
	Initialize();
	return TInstance;
}

