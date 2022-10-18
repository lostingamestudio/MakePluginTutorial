// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TutorialCustomAsset.generated.h"

USTRUCT(BlueprintType)
struct FTutorialData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Control")
	FName ControlName;

	/** If true, this control is an virtual joystick */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Control")
	bool bIsJoystick;
	
	/** Image for button or background for stick when unpressed */
	UPROPERTY(Category="Control", EditAnywhere, BlueprintReadWrite)
	FSlateBrush NormalBackground;
	
	/** The center point of the control in landscape mode. It's relative to screen size (0-1) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Control")
	FVector2D LandscapeCenter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Control")
	FVector2D VisualSize;

	/** The main input to send from this control (for sticks, this is the horizontal axis) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Control")
	FKey MainInputKey;

	/** Default constructor */
	FTutorialData() :
	bIsJoystick(false),
	LandscapeCenter(0.5f,0.5f),
	VisualSize(80.0f)
	{
		ControlName = FName(TEXT("NewControl"));
	}
};

UENUM()
enum class ERotationMode
{
	/** Device rotation detection is disabled */
	None UMETA(DisplayName="Disabled"),

	/** Device rotation detection is enabled and you provide data for landscape and portrait orientation */
	Manual,

	/** Device rotation detection is enabled and you provide data for landscape. Portrait orientation will be calculated automatically but may provide an inaccurate result */
	Automatic
};

/**
 * 
 */
UCLASS(BlueprintType)
class TUTORIALPLUGIN_API UTutorialCustomAsset : public UObject
{
	GENERATED_BODY()

public:

	UTutorialCustomAsset();
	
	UPROPERTY(Category="Base", EditAnywhere, BlueprintReadWrite)
	bool bShowParam;

	UPROPERTY(Category="Base", EditAnywhere, BlueprintReadWrite)
	float MyFloatParam;

	UPROPERTY(Category="General Settings", EditAnywhere, BlueprintReadWrite)
	float BaseOpacity;

	UPROPERTY(Category="General Settings|Rotation", EditAnywhere, BlueprintReadWrite)
	ERotationMode RotationMode;

	UPROPERTY(Category="Data", EditAnywhere, BlueprintReadWrite)
	TArray<FTutorialData> MyTutorialDatas;

	int32 SelectedIndex;
};
