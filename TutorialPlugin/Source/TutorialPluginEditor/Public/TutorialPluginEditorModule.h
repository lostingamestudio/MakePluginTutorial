#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "AssetTypeCategories.h"


class UTutorialCustomAsset;
class IAssetTypeActions;
class FTutorialPluginEditor;

class FTutorialPluginEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void CreateTutorialCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UTutorialCustomAsset* InTutorialCustomAsset);

private:
	EAssetTypeCategories::Type AssetTypeCategory;

	TSharedPtr<IAssetTypeActions> CreatedAssetTypeActions;

	TWeakPtr<FTutorialPluginEditor> TutorialPluginEditorPtr;
};
