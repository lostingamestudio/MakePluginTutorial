// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Widgets/SCompoundWidget.h"

class SCanvas;
class UTutorialCustomAsset;

/**
 * 
 */
class TUTORIALPLUGINEDITOR_API STutorialPluginEditor_Viewport : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STutorialPluginEditor_Viewport)
		{
		}

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs, UTutorialCustomAsset* TutorialCustomAsset);

	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

	void SelectVirtualControl(FName ControlName);

	void GenerateVirtualControl();

	void AddNewVirtualControl();
	
private:
	TSharedPtr<SCanvas> DesignerSurface;

	FVector2D GetDesignerSurfacePosition() const;
	float GetDesignerSurfaceScale() const;

	FVector2D Panning;
	float Scale;

	UTutorialCustomAsset* TutorialCustomAssetEdited;
};
