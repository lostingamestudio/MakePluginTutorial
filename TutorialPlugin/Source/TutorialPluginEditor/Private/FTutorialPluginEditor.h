#pragma once

class UTutorialCustomAsset;
class STutorialPluginEditorDetailsPanel;
class STutorialPluginEditor_Viewport;

class FTutorialPluginEditor : public FAssetEditorToolkit
{
public:
	virtual FText GetBaseToolkitName() const override;
	virtual FName GetToolkitFName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;

	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	
	void InitTutorialCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UTutorialCustomAsset* InTutorialCustomAsset);

	UTutorialCustomAsset* GetTutorialCustomAssetEdited();

private:
	TSharedRef<SDockTab> SpawnTabControlPreview(const FSpawnTabArgs& SpawnTabArgs);
	TSharedRef<SDockTab> SpawnTabControlCreator(const FSpawnTabArgs& SpawnTabArgs);
	TSharedRef<SDockTab> SpawnTabViewport(const FSpawnTabArgs& SpawnTabArgs);
	TSharedRef<SDockTab> SpawnTabDetails(const FSpawnTabArgs& SpawnTabArgs);

	UTutorialCustomAsset* TutorialCustomAssetEdited;

	TSharedPtr<STutorialPluginEditorDetailsPanel> DetailsPanelInstance;
	TSharedPtr<STutorialPluginEditor_Viewport> ViewportInstance;
};
