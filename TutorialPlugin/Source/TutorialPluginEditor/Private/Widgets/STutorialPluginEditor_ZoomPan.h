// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class TUTORIALPLUGINEDITOR_API STutorialPluginEditor_ZoomPan : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STutorialPluginEditor_ZoomPan)
		{
		}
	SLATE_DEFAULT_SLOT(FArguments, Content)

	SLATE_ATTRIBUTE(FVector2D, Offset)
	SLATE_ATTRIBUTE(float, Zoom)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual void OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const override;

private:
	TAttribute<FVector2D> Offset;
	TAttribute<float> Zoom;
};
