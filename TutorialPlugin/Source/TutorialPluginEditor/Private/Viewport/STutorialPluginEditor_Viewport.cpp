// Fill out your copyright notice in the Description page of Project Settings.


#include "STutorialPluginEditor_Viewport.h"
#include "TutorialCustomAsset.h"
#include "SlateOptMacros.h"
#include "SVirtualControlEditor.h"
#include "Widgets/SCanvas.h"
#include "Widgets/STutorialPluginEditor_ZoomPan.h"
#include "Widgets/Layout/SConstraintCanvas.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void STutorialPluginEditor_Viewport::Construct(const FArguments& InArgs, UTutorialCustomAsset* TutorialCustomAsset)
{
	TutorialCustomAssetEdited = TutorialCustomAsset;
	
	Panning = FVector2D::Zero();
	Scale = 1.0f;
	
	ChildSlot
	[
		SNew(SOverlay)
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(STutorialPluginEditor_ZoomPan)
			.Offset(this, &STutorialPluginEditor_Viewport::GetDesignerSurfacePosition)
			.Zoom(this, &STutorialPluginEditor_Viewport::GetDesignerSurfaceScale)
			[
				SNew(SBox)
				.WidthOverride(1280)
				.HeightOverride(720)
				[
					SAssignNew(DesignerSurface, SCanvas)
				]
			]
			
		]
	];

	GenerateVirtualControl();
}

FReply STutorialPluginEditor_Viewport::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.IsMouseButtonDown(EKeys::RightMouseButton))
	{
		Panning -= MouseEvent.GetCursorDelta();
		return FReply::Handled();
	}
	
	return FReply::Unhandled();
}

FReply STutorialPluginEditor_Viewport::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	Scale = FMath::Clamp(Scale += MouseEvent.GetWheelDelta() * 0.1f, 0.1f, 2.0f);
	return FReply::Handled();
}

int32 STutorialPluginEditor_Viewport::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	const FGeometry DesignerSurfaceGeometry = DesignerSurface->GetTickSpaceGeometry();
	const FSlateRect DesignerSurfaceRect = FSlateRect(FVector2D::ZeroVector, FVector2D(1280.0f, 720.0f));
	
	TArray<FVector2D> Points;
	Points.Add(DesignerSurfaceRect.GetTopLeft());
	Points.Add(DesignerSurfaceRect.GetTopRight());
	Points.Add(DesignerSurfaceRect.GetBottomRight());
	Points.Add(DesignerSurfaceRect.GetBottomLeft());
	Points.Add(DesignerSurfaceRect.GetTopLeft());
	FSlateDrawElement::MakeLines(OutDrawElements,LayerId,DesignerSurfaceGeometry.ToPaintGeometry(), Points, ESlateDrawEffect::None, FLinearColor::White, false);
	
	return SCompoundWidget::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
}

void STutorialPluginEditor_Viewport::SelectVirtualControl(FName ControlName)
{
	
}

void STutorialPluginEditor_Viewport::GenerateVirtualControl()
{
	for (FTutorialData& Data : TutorialCustomAssetEdited->MyTutorialDatas)
	{
		TSharedRef<SVirtualControlEditor> Control = SNew(SVirtualControlEditor, SharedThis(this))
		.Position(Data.LandscapeCenter)
		.Background(Data.NormalBackground)
		.Size(Data.VisualSize)
		.ControlName(Data.ControlName);
		
		DesignerSurface->AddSlot()
		.Position(FVector2D(1280.0f * Data.LandscapeCenter.X, 720.0f * Data.LandscapeCenter.Y))
		.Size(Data.VisualSize)
		[
			Control
		];
	}
}

FVector2D STutorialPluginEditor_Viewport::GetDesignerSurfacePosition() const
{
	return Panning;
}

float STutorialPluginEditor_Viewport::GetDesignerSurfaceScale() const
{
	return Scale;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
