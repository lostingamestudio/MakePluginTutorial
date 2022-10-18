// Fill out your copyright notice in the Description page of Project Settings.


#include "SVirtualControlEditor.h"
#include "STutorialPluginEditor_Viewport.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SVirtualControlEditor::Construct(const FArguments& InArgs, TSharedPtr<STutorialPluginEditor_Viewport> Viewport)
{
	CurrentPosition = InArgs._Position;
	CurrentBackground = InArgs._Background;
	CurrentName = InArgs._ControlName;
	CurrentSize = InArgs._Size;
	ViewportPtr = Viewport;
}

FReply SVirtualControlEditor::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	ViewportPtr->SelectVirtualControl(CurrentName);
	return FReply::Handled();
}

int32 SVirtualControlEditor::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	FSlateDrawElement::MakeBox
	(
		OutDrawElements,
		LayerId,
		AllottedGeometry.ToPaintGeometry(),
		&CurrentBackground
	);

	return LayerId;
}

FVector2D SVirtualControlEditor::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	return CurrentSize;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
