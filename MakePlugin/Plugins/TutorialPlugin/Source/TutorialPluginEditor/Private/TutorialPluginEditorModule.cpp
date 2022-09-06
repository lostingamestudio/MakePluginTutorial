#include "TutorialPluginEditorModule.h"

#include "AssetToolsModule.h"
#include "AssetTypeActions_TutorialCustomAsset.h"
#include "IAssetTools.h"

void FTutorialPluginEditorModule::StartupModule()
{
	IModuleInterface::StartupModule();
	GLog->Log("Startup Tutorial Plugin");

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	AssetTypeCategory = AssetTools.RegisterAdvancedAssetCategory("TutorialPlugin", INVTEXT("Tutorial Plugin"));
	
	TSharedRef<IAssetTypeActions> Actions = MakeShared<FAssetTypeActions_TutorialCustomAsset>(AssetTypeCategory);
	AssetTools.RegisterAssetTypeActions(Actions);
}

void FTutorialPluginEditorModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
	GLog->Log("Shutdown Tutorial Plugin");
}

IMPLEMENT_MODULE(FTutorialPluginEditorModule, TutorialPluginEditor);