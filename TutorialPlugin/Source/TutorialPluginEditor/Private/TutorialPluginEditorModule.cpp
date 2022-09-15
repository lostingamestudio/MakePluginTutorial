#include "TutorialPluginEditorModule.h"

#include "AssetToolsModule.h"
#include "AssetTypeActions_TutorialCustomAsset.h"
#include "FTutorialPluginEditor.h"
#include "IAssetTools.h"
#include "Tabs/STutorialPluginEditorDetailsPanel.h"

void FTutorialPluginEditorModule::StartupModule()
{
	IModuleInterface::StartupModule();

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	AssetTypeCategory = AssetTools.RegisterAdvancedAssetCategory("TutorialPlugin", INVTEXT("Tutorial Plugin"));
	
	TSharedRef<IAssetTypeActions> Actions = MakeShared<FAssetTypeActions_TutorialCustomAsset>(AssetTypeCategory);
	AssetTools.RegisterAssetTypeActions(Actions);
	CreatedAssetTypeActions = Actions;

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyEditorModule.RegisterCustomClassLayout("TutorialCustomAsset", FOnGetDetailCustomizationInstance::CreateStatic(&FTutorialPluginEditorDetailsCustomization::MakeInstance));
	PropertyEditorModule.NotifyCustomizationModuleChanged();
}

void FTutorialPluginEditorModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();

	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		AssetTools.UnregisterAssetTypeActions(CreatedAssetTypeActions.ToSharedRef());
	}

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyEditorModule.UnregisterCustomClassLayout("TutorialCustomAsset");
	PropertyEditorModule.NotifyCustomizationModuleChanged();
}

void FTutorialPluginEditorModule::CreateTutorialCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UTutorialCustomAsset* InTutorialCustomAsset)
{
	TSharedRef<FTutorialPluginEditor> TutorialPluginEditor(new FTutorialPluginEditor());
	TutorialPluginEditorPtr = TutorialPluginEditor;
	TutorialPluginEditor->InitTutorialCustomAssetEditor(Mode, InitToolkitHost, InTutorialCustomAsset);
}

IMPLEMENT_MODULE(FTutorialPluginEditorModule, TutorialPluginEditor);
