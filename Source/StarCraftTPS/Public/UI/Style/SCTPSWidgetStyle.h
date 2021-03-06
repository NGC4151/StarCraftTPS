// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include "SlateBrush.h"
#include "SlateFontInfo.h"
#include <SlateSound.h>

#include "SCTPSWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct STARCRAFTTPS_API FSCTPSStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FSCTPSStyle();
	virtual ~FSCTPSStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FSCTPSStyle& GetDefault();

	/**
	 * 菜单的各个UI的图片
	 */
	UPROPERTY(EditAnywhere, Category = HUD)
		FSlateBrush MenueHUDBackgroundBrush;
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush MenueImage;
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush MenuItemImage;
	UPROPERTY(EditAnywhere, Category = Menu)
		FSlateBrush TitleBorderImage;
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush SettingsBackgroundImage;
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush CheckBoxSelectedImage;
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush CheckBoxNoSelectedImage;
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSlateBrush SliderImage;
	UPROPERTY(EditAnywhere, Category = GameOption)
		FSliderStyle MySliderStyle;

	//音效及背景音乐资源
	UPROPERTY(EditAnywhere, Category = Sound)
		FSlateSound ButtonPressedSound;
	UPROPERTY(EditAnywhere, Category = Sound)
		FSlateSound MenuChangeSound;
	UPROPERTY(EditAnywhere, Category = Sound)
		FSlateSound BackgroundMusic;

	//字体大小
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_60;
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_40;
	UPROPERTY(EditAnywhere, Category = Common)
		FSlateFontInfo Font_30;
	UPROPERTY(EditAnywhere, Category = Common)
		FLinearColor FontColor_B;
	UPROPERTY(EditAnywhere, Category = Common)
		FLinearColor FontColor_W;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class USCTPSWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FSCTPSStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
