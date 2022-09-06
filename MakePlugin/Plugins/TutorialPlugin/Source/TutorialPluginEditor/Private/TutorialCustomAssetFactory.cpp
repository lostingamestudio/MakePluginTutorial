#include "TutorialCustomAssetFactory.h"

#include "TutorialCustomAsset.h"

UTutorialCustomAssetFactory::UTutorialCustomAssetFactory()
{
	bCreateNew = true;
	bEditAfterNew = false;
	SupportedClass = UTutorialCustomAsset::StaticClass();
}

UObject* UTutorialCustomAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UTutorialCustomAsset>(InParent, InClass, InName);
}
