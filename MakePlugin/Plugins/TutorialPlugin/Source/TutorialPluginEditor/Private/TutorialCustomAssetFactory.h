#pragma once

#include "Factories/Factory.h"
#include "TutorialCustomAssetFactory.generated.h"

UCLASS()
class UTutorialCustomAssetFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	UTutorialCustomAssetFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	
};
