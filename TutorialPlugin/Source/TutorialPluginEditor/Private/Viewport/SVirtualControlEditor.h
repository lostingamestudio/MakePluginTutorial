// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Widgets/SLeafWidget.h"

class STutorialPluginEditor_Viewport;

/**
 * 
 */
class TUTORIALPLUGINEDITOR_API SVirtualControlEditor : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SVirtualControlEditor)
		{
		}

	SLATE_ARGUMENT(FVector2D, Position)
	SLATE_ARGUMENT(FSlateBrush, Background)
	SLATE_ARGUMENT(FVector2D, Size)
	SLATE_ARGUMENT(FName, ControlName)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs, TSharedPtr<STutorialPluginEditor_Viewport> Viewport);
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;

private:
	FVector2D CurrentPosition;
	FVector2D CurrentSize;
	FSlateBrush CurrentBackground;
	FName CurrentName;

	TSharedPtr<STutorialPluginEditor_Viewport> ViewportPtr;
};
