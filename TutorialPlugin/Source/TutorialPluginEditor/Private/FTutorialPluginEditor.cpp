#include "FTutorialPluginEditor.h"

#include "TutorialCustomAsset.h"
#include "Tabs/STutorialPluginEditorDetailsPanel.h"
#include "Viewport//STutorialPluginEditor_Viewport.h"

struct FTutorialPluginEditorTabs
{
	static const FName ControlPreviewId;
	static const FName ControlCreatorId;
	static const FName ViewportId;
	static const FName DetailsId;
};

const FName FTutorialPluginEditorTabs::ControlPreviewId("ControlPreview");
const FName FTutorialPluginEditorTabs::ControlCreatorId("ControlCreator");
const FName FTutorialPluginEditorTabs::ViewportId("Viewport");
const FName FTutorialPluginEditorTabs::DetailsId("Details");

FText FTutorialPluginEditor::GetBaseToolkitName() const
{
	return NSLOCTEXT("TutorialPluginEditor", "AppLabel", "Tutorial Custom Asset Editor");
}

FName FTutorialPluginEditor::GetToolkitFName() const
{
	return FName("TutorialCustomAssetEditor");
}

FString FTutorialPluginEditor::GetWorldCentricTabPrefix() const
{
	return NSLOCTEXT("TutorialPluginEditor", "WorldCentricTabPrefix", "TutorialCustomAsset ").ToString();
}

FLinearColor FTutorialPluginEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::Blue;
}

void FTutorialPluginEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(INVTEXT("Tutorial Plugin Editor"));
	TSharedRef<FWorkspaceItem> WorkspaceMenuCategoryRef = WorkspaceMenuCategory.ToSharedRef();
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(FTutorialPluginEditorTabs::ControlPreviewId, FOnSpawnTab::CreateSP(this, &FTutorialPluginEditor::SpawnTabControlPreview))
	.SetGroup(WorkspaceMenuCategoryRef);

	InTabManager->RegisterTabSpawner(FTutorialPluginEditorTabs::ControlCreatorId, FOnSpawnTab::CreateSP(this, &FTutorialPluginEditor::SpawnTabControlCreator))
	.SetGroup(WorkspaceMenuCategoryRef);

	InTabManager->RegisterTabSpawner(FTutorialPluginEditorTabs::ViewportId, FOnSpawnTab::CreateSP(this, &FTutorialPluginEditor::SpawnTabViewport))
	.SetGroup(WorkspaceMenuCategoryRef)
	.SetDisplayName(INVTEXT("2D Viewport"));

	InTabManager->RegisterTabSpawner(FTutorialPluginEditorTabs::DetailsId, FOnSpawnTab::CreateSP(this, &FTutorialPluginEditor::SpawnTabDetails))
	.SetGroup(WorkspaceMenuCategoryRef)
	.SetIcon(FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Details"));
}

void FTutorialPluginEditor::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	InTabManager->UnregisterTabSpawner(FTutorialPluginEditorTabs::ControlPreviewId);
	InTabManager->UnregisterTabSpawner(FTutorialPluginEditorTabs::ControlCreatorId);
	InTabManager->UnregisterTabSpawner(FTutorialPluginEditorTabs::ViewportId);
	InTabManager->UnregisterTabSpawner(FTutorialPluginEditorTabs::DetailsId);
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
}

TSharedRef<SDockTab> FTutorialPluginEditor::SpawnTabControlPreview(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab);
}

TSharedRef<SDockTab> FTutorialPluginEditor::SpawnTabControlCreator(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab);
}

TSharedRef<SDockTab> FTutorialPluginEditor::SpawnTabViewport(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab)
	[
		SAssignNew(ViewportInstance, STutorialPluginEditor_Viewport, TutorialCustomAssetEdited)
	];
}

TSharedRef<SDockTab> FTutorialPluginEditor::SpawnTabDetails(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab)
	[
		SAssignNew(DetailsPanelInstance, STutorialPluginEditorDetailsPanel, SharedThis(this))
	];
}

void FTutorialPluginEditor::InitTutorialCustomAssetEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UTutorialCustomAsset* InTutorialCustomAsset)
{
	TutorialCustomAssetEdited = InTutorialCustomAsset;
	
	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("StandaloneDefault_WIP_V1")->AddArea
	(
		FTabManager::NewPrimaryArea()
		->SetOrientation(Orient_Horizontal)
		->Split
		(
			FTabManager::NewSplitter()
			->SetOrientation(Orient_Vertical)
			->SetSizeCoefficient(0.25f)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.3f)
				->SetHideTabWell(true)
				->AddTab(FTutorialPluginEditorTabs::ControlPreviewId, ETabState::OpenedTab)
			)
			->Split
			(
			FTabManager::NewStack()
				->SetHideTabWell(false)
				->AddTab(FTutorialPluginEditorTabs::ControlCreatorId, ETabState::OpenedTab)
			)
		)
		->Split
		(
		FTabManager::NewStack()
			->SetHideTabWell(true)
			->AddTab(FTutorialPluginEditorTabs::ViewportId, ETabState::OpenedTab)
		)
		->Split
		(
		FTabManager::NewStack()
			->SetSizeCoefficient(0.3f)
			->SetHideTabWell(true)
			->AddTab(FTutorialPluginEditorTabs::DetailsId, ETabState::OpenedTab)
		)
	);
	
	InitAssetEditor(Mode, InitToolkitHost, FName("TutorialPluginEditorAppIdentifier"), StandaloneDefaultLayout, true, true, InTutorialCustomAsset);
}

UTutorialCustomAsset* FTutorialPluginEditor::GetTutorialCustomAssetEdited()
{
	return TutorialCustomAssetEdited;
}
