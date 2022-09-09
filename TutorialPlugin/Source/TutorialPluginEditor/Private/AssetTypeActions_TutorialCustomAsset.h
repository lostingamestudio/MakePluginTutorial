#pragma once
#include "AssetTypeActions_Base.h"
#include "TutorialCustomAsset.h"

class FAssetTypeActions_TutorialCustomAsset : public FAssetTypeActions_Base
{
public:
	FAssetTypeActions_TutorialCustomAsset(EAssetTypeCategories::Type InAssetCategory)
		: AssetTypeCategory(InAssetCategory)
	{
		
	}
	
	virtual FText GetName() const override { return INVTEXT("Tutorial Custom Asset"); }
	virtual UClass* GetSupportedClass() const override { return UTutorialCustomAsset::StaticClass(); }
	virtual FColor GetTypeColor() const override { return FColor::Orange; }

	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;

	virtual uint32 GetCategories() override { return AssetTypeCategory; }

private:
	EAssetTypeCategories::Type AssetTypeCategory;
};
