// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"
#include "SSingleObjectDetailsPanel.h"

class UTutorialCustomAsset;
class FTutorialPluginEditor;

/**
 * 
 */
class TUTORIALPLUGINEDITOR_API STutorialPluginEditorDetailsPanel : public SSingleObjectDetailsPanel
{
public:
	SLATE_BEGIN_ARGS(STutorialPluginEditorDetailsPanel)
		{
		}

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs, TSharedPtr<FTutorialPluginEditor> TutorialPluginEditorRef);

	virtual UObject* GetObjectToObserve() const override;
	virtual TSharedRef<SWidget> PopulateSlot(TSharedRef<SWidget> PropertyEditorWidget) override;

private:
	TWeakPtr<FTutorialPluginEditor> TutorialPluginEditorPtr;
};

class FTutorialPluginEditorDetailsCustomization : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();
	
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	IDetailLayoutBuilder* DetailBuilderInstance;
	UTutorialCustomAsset* TutorialCustomAssetEdited;

	void ForceRefresh();
	
	FReply OnPreviousButtonClicked();
	FReply OnNextButtonClicked();

	FReply AddNewControl();
	FReply RemoveControl();
};
