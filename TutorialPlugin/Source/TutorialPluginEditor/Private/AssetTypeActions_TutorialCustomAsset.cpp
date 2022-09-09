#include "AssetTypeActions_TutorialCustomAsset.h"

#include "TutorialPluginEditorModule.h"


void FAssetTypeActions_TutorialCustomAsset::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (UObject* Obj : InObjects)
	{
		UTutorialCustomAsset* TutorialCustomAsset = Cast<UTutorialCustomAsset>(Obj);
		if (TutorialCustomAsset != nullptr)
		{
			FTutorialPluginEditorModule* EditorModule = &FModuleManager::LoadModuleChecked<FTutorialPluginEditorModule>("TutorialPluginEditor");
			EditorModule->CreateTutorialCustomAssetEditor(Mode, EditWithinLevelEditor, TutorialCustomAsset);
		}
	}
}
