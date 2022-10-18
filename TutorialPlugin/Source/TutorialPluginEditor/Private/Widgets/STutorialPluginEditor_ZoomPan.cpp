// Fill out your copyright notice in the Description page of Project Settings.


#include "STutorialPluginEditor_ZoomPan.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void STutorialPluginEditor_ZoomPan::Construct(const FArguments& InArgs)
{
	Offset = InArgs._Offset;
	Zoom = InArgs._Zoom;
	
	ChildSlot
	[
		InArgs._Content.Widget
	];
}

void STutorialPluginEditor_ZoomPan::OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const
{
	if (ArrangedChildren.Accepts(ChildSlot.GetWidget()->GetVisibility()))
	{
		const AlignmentArrangeResult XResult = AlignChild<Orient_Horizontal>(AllottedGeometry.GetLocalSize().X, ChildSlot, ChildSlot.GetPadding(), 1);
		const AlignmentArrangeResult YResult = AlignChild<Orient_Vertical>(AllottedGeometry.GetLocalSize().Y, ChildSlot, ChildSlot.GetPadding(), 1);

		const FVector2D ChildOffset = FVector2D(XResult.Offset, YResult.Offset) - Offset.Get();
		
		FGeometry ChildGeometry = AllottedGeometry.MakeChild(ChildSlot.GetWidget()->GetDesiredSize(), FSlateLayoutTransform(Zoom.Get(), ChildOffset));
		
		ArrangedChildren.AddWidget(ChildSlot.GetWidget()->GetVisibility(), FArrangedWidget(ChildSlot.GetWidget(), ChildGeometry));
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
