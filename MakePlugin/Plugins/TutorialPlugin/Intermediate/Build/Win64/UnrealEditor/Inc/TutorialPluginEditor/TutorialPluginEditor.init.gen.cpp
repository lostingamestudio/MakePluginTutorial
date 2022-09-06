// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTutorialPluginEditor_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_TutorialPluginEditor;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_TutorialPluginEditor()
	{
		if (!Z_Registration_Info_UPackage__Script_TutorialPluginEditor.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/TutorialPluginEditor",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000040,
				0x5D975684,
				0x1D72398D,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_TutorialPluginEditor.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_TutorialPluginEditor.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_TutorialPluginEditor(Z_Construct_UPackage__Script_TutorialPluginEditor, TEXT("/Script/TutorialPluginEditor"), Z_Registration_Info_UPackage__Script_TutorialPluginEditor, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x5D975684, 0x1D72398D));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
