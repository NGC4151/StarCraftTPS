// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include "SlateBrush.h"

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

	UPROPERTY(EditAnywhere, Category = HUD)
		FSlateBrush MenueHUDBackgroundBrush;
	UPROPERTY(EditAnywhere, Category = HUD)
		FSlateBrush MenueImage;
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
