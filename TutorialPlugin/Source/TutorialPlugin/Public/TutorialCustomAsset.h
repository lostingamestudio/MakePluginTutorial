// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TutorialCustomAsset.generated.h"

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
	
};
