// Fill out your copyright notice in the Description page of Project Settings.


#include "STutorialPluginEditorDetailsPanel.h"

#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "FTutorialPluginEditor.h"
#include "IDetailGroup.h"
#include "SlateOptMacros.h"
#include "TutorialCustomAsset.h"
#include "Widgets/SViewport.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void STutorialPluginEditorDetailsPanel::Construct(const FArguments& InArgs, TSharedPtr<FTutorialPluginEditor> TutorialPluginEditorRef)
{
	TutorialPluginEditorPtr = TutorialPluginEditorRef;

	SSingleObjectDetailsPanel::Construct(SSingleObjectDetailsPanel::FArguments(), true, true);

	PropertyView->SetObject(GetObjectToObserve());
}

UObject* STutorialPluginEditorDetailsPanel::GetObjectToObserve() const
{
	return TutorialPluginEditorPtr.Pin()->GetTutorialCustomAssetEdited();
}

TSharedRef<SWidget> STutorialPluginEditorDetailsPanel::PopulateSlot(TSharedRef<SWidget> PropertyEditorWidget)
{
	return SNew(SVerticalBox)
	+SVerticalBox::Slot()
	.FillHeight(1)
	[
		PropertyEditorWidget
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

TSharedRef<IDetailCustomization> FTutorialPluginEditorDetailsCustomization::MakeInstance()
{
	return MakeShareable(new FTutorialPluginEditorDetailsCustomization());
}

void FTutorialPluginEditorDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	DetailBuilderInstance = &DetailBuilder;
	
	TArray<TWeakObjectPtr<UObject>> ObjectsBeingCustomized;
	DetailBuilder.GetObjectsBeingCustomized(ObjectsBeingCustomized);
	TArray<UObject*> StrongObjects;
	CopyFromWeakArray(StrongObjects, ObjectsBeingCustomized);

	if (StrongObjects.IsEmpty())
	{
		UE_LOG(LogTemp, Log, TEXT("No object to modify"));
		return;
	}

	TutorialCustomAssetEdited = Cast<UTutorialCustomAsset>(StrongObjects[0]);

	DetailBuilder.HideCategory("Base");
	DetailBuilder.HideCategory("General Settings");
	DetailBuilder.HideCategory("Data");
	
	IDetailCategoryBuilder& BaseSettingsCat = DetailBuilder.EditCategory("BaseSettings", INVTEXT("Base Settings"));

	const TSharedPtr<IPropertyHandle> ShowParamProperty = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UTutorialCustomAsset, bShowParam));
	const TSharedPtr<IPropertyHandle> MyFloatParamProperty = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UTutorialCustomAsset, MyFloatParam));
	const TSharedPtr<IPropertyHandle> BaseOpacityProperty = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UTutorialCustomAsset, BaseOpacity));
	const TSharedPtr<IPropertyHandle> RotationModeProperty = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UTutorialCustomAsset, RotationMode));

	ShowParamProperty->SetOnPropertyValueChanged(FSimpleDelegate::CreateSP(this, &FTutorialPluginEditorDetailsCustomization::ForceRefresh));
	
	BaseSettingsCat.AddProperty(ShowParamProperty);
	BaseSettingsCat.AddProperty(MyFloatParamProperty);

	bool bShowBaseOpacityParam;
	ShowParamProperty->GetValue(bShowBaseOpacityParam);
	if (bShowBaseOpacityParam)
	{
		BaseSettingsCat.AddProperty(BaseOpacityProperty);
	}
		
	BaseSettingsCat.AddProperty(RotationModeProperty);

	BaseSettingsCat.AddCustomRow(INVTEXT("Debug"))
	.WholeRowContent()
	[
		SNew(SHorizontalBox)
		//Select Previous
		+SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(INVTEXT("<"))
			.OnClicked(FOnClicked::CreateSP(this, &FTutorialPluginEditorDetailsCustomization::OnPreviousButtonClicked))
		]
		//Select next
		+SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(INVTEXT(">"))
			.OnClicked(FOnClicked::CreateSP(this, &FTutorialPluginEditorDetailsCustomization::OnNextButtonClicked))
		]
		//Add New Control
		+SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(INVTEXT("Add"))
			.OnClicked(FOnClicked::CreateSP(this, &FTutorialPluginEditorDetailsCustomization::AddNewControl))
		]
		//Remove current control
		+SHorizontalBox::Slot()
		[
			SNew(SButton)
			.Text(INVTEXT("Remove"))
			.OnClicked(FOnClicked::CreateSP(this, &FTutorialPluginEditorDetailsCustomization::RemoveControl))
		]
	];

	const TSharedPtr<IPropertyHandle> MyDatasProperty = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UTutorialCustomAsset, MyTutorialDatas));

	const TSharedPtr<IPropertyHandleArray> DataArray = MyDatasProperty->AsArray();

	uint32 NumElement;
	DataArray->GetNumElements(NumElement);
	//uint32 SelectedIndex = 0;
	if (NumElement > 0 && (uint32)TutorialCustomAssetEdited->SelectedIndex < NumElement)
	{
		const TSharedPtr<IPropertyHandle> DataChild = DataArray->GetElement(TutorialCustomAssetEdited->SelectedIndex);

		IDetailCategoryBuilder& BaseCat = DetailBuilder.EditCategory("BaseArraySettings", INVTEXT("Base"));
		IDetailCategoryBuilder& PropertyCat = DetailBuilder.EditCategory("Properties", INVTEXT("Properties"));
		IDetailCategoryBuilder& InputCat = DetailBuilder.EditCategory("Input", INVTEXT("Input"));

		const TSharedPtr<IPropertyHandle> ControlNameProperty = DataChild->GetChildHandle("ControlName");
		const TSharedPtr<IPropertyHandle> IsJoystickProperty = DataChild->GetChildHandle("bIsJoystick");
		const TSharedPtr<IPropertyHandle> NormalBackgroundProperty = DataChild->GetChildHandle("NormalBackground");
		const TSharedPtr<IPropertyHandle> LandscapeCenterProperty = DataChild->GetChildHandle("LandscapeCenter");
		const TSharedPtr<IPropertyHandle> MainInputKeyProperty = DataChild->GetChildHandle("MainInputKey");
		const TSharedPtr<IPropertyHandle> VisualSizeProperty = DataChild->GetChildHandle("VisualSize");
		
		BaseCat.AddProperty(ControlNameProperty);
		BaseCat.AddProperty(IsJoystickProperty);

		PropertyCat.AddProperty(NormalBackgroundProperty);
		PropertyCat.AddProperty(LandscapeCenterProperty);
		PropertyCat.AddProperty(VisualSizeProperty);
		
		//InputCat.AddProperty(MainInputKeyProperty);

		IDetailGroup& Group = PropertyCat.AddGroup("Input", INVTEXT("Input"));
		Group.AddPropertyRow(MainInputKeyProperty.ToSharedRef());
	}	
}

void FTutorialPluginEditorDetailsCustomization::ForceRefresh()
{
	DetailBuilderInstance->ForceRefreshDetails();
}

FReply FTutorialPluginEditorDetailsCustomization::OnPreviousButtonClicked()
{
	UE_LOG(LogTemp, Log, TEXT("Previous Index"));
	int32 Max = TutorialCustomAssetEdited->MyTutorialDatas.Num()-1;
	TutorialCustomAssetEdited->SelectedIndex = FMath::Clamp(TutorialCustomAssetEdited->SelectedIndex - 1, 0, Max);
	ForceRefresh();
	return FReply::Handled();
}

FReply FTutorialPluginEditorDetailsCustomization::OnNextButtonClicked()
{
	UE_LOG(LogTemp, Log, TEXT("Next Index"));
	int32 Max = TutorialCustomAssetEdited->MyTutorialDatas.Num()-1;
	TutorialCustomAssetEdited->SelectedIndex = FMath::Clamp(TutorialCustomAssetEdited->SelectedIndex + 1, 0, Max);
	ForceRefresh();
	return FReply::Handled();
}

FReply FTutorialPluginEditorDetailsCustomization::AddNewControl()
{
	TutorialCustomAssetEdited->MyTutorialDatas.Add(FTutorialData());
	TutorialCustomAssetEdited->SelectedIndex = TutorialCustomAssetEdited->MyTutorialDatas.Num()-1;
	TutorialCustomAssetEdited->Modify();
	ForceRefresh();
	return FReply::Handled();
}

FReply FTutorialPluginEditorDetailsCustomization::RemoveControl()
{
	const uint32 RemoveAt = TutorialCustomAssetEdited->SelectedIndex;
	TutorialCustomAssetEdited->SelectedIndex = FMath::Clamp(TutorialCustomAssetEdited->MyTutorialDatas.Num()-2, 0, TutorialCustomAssetEdited->MyTutorialDatas.Num());
	TutorialCustomAssetEdited->MyTutorialDatas.RemoveAt(RemoveAt);
	TutorialCustomAssetEdited->Modify();
	ForceRefresh();
	return FReply::Handled();
}
