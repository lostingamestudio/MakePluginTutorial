// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TutorialPluginEditor/Private/TutorialCustomAssetFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTutorialCustomAssetFactory() {}
// Cross Module References
	TUTORIALPLUGINEDITOR_API UClass* Z_Construct_UClass_UTutorialCustomAssetFactory_NoRegister();
	TUTORIALPLUGINEDITOR_API UClass* Z_Construct_UClass_UTutorialCustomAssetFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_TutorialPluginEditor();
// End Cross Module References
	void UTutorialCustomAssetFactory::StaticRegisterNativesUTutorialCustomAssetFactory()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTutorialCustomAssetFactory);
	UClass* Z_Construct_UClass_UTutorialCustomAssetFactory_NoRegister()
	{
		return UTutorialCustomAssetFactory::StaticClass();
	}
	struct Z_Construct_UClass_UTutorialCustomAssetFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTutorialCustomAssetFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_TutorialPluginEditor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTutorialCustomAssetFactory_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "TutorialCustomAssetFactory.h" },
		{ "ModuleRelativePath", "Private/TutorialCustomAssetFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTutorialCustomAssetFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTutorialCustomAssetFactory>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTutorialCustomAssetFactory_Statics::ClassParams = {
		&UTutorialCustomAssetFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UTutorialCustomAssetFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UTutorialCustomAssetFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTutorialCustomAssetFactory()
	{
		if (!Z_Registration_Info_UClass_UTutorialCustomAssetFactory.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTutorialCustomAssetFactory.OuterSingleton, Z_Construct_UClass_UTutorialCustomAssetFactory_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTutorialCustomAssetFactory.OuterSingleton;
	}
	template<> TUTORIALPLUGINEDITOR_API UClass* StaticClass<UTutorialCustomAssetFactory>()
	{
		return UTutorialCustomAssetFactory::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTutorialCustomAssetFactory);
	struct Z_CompiledInDeferFile_FID_MakePlugin_Plugins_TutorialPlugin_Source_TutorialPluginEditor_Private_TutorialCustomAssetFactory_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MakePlugin_Plugins_TutorialPlugin_Source_TutorialPluginEditor_Private_TutorialCustomAssetFactory_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTutorialCustomAssetFactory, UTutorialCustomAssetFactory::StaticClass, TEXT("UTutorialCustomAssetFactory"), &Z_Registration_Info_UClass_UTutorialCustomAssetFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTutorialCustomAssetFactory), 3100432472U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MakePlugin_Plugins_TutorialPlugin_Source_TutorialPluginEditor_Private_TutorialCustomAssetFactory_h_4210640083(TEXT("/Script/TutorialPluginEditor"),
		Z_CompiledInDeferFile_FID_MakePlugin_Plugins_TutorialPlugin_Source_TutorialPluginEditor_Private_TutorialCustomAssetFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MakePlugin_Plugins_TutorialPlugin_Source_TutorialPluginEditor_Private_TutorialCustomAssetFactory_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
