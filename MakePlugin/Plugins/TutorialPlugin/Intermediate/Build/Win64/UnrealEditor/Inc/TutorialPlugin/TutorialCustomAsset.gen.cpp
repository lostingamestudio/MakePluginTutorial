// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TutorialPlugin/Public/TutorialCustomAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTutorialCustomAsset() {}
// Cross Module References
	TUTORIALPLUGIN_API UClass* Z_Construct_UClass_UTutorialCustomAsset_NoRegister();
	TUTORIALPLUGIN_API UClass* Z_Construct_UClass_UTutorialCustomAsset();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_TutorialPlugin();
// End Cross Module References
	void UTutorialCustomAsset::StaticRegisterNativesUTutorialCustomAsset()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTutorialCustomAsset);
	UClass* Z_Construct_UClass_UTutorialCustomAsset_NoRegister()
	{
		return UTutorialCustomAsset::StaticClass();
	}
	struct Z_Construct_UClass_UTutorialCustomAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTutorialCustomAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_TutorialPlugin,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTutorialCustomAsset_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "TutorialCustomAsset.h" },
		{ "ModuleRelativePath", "Public/TutorialCustomAsset.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTutorialCustomAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTutorialCustomAsset>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTutorialCustomAsset_Statics::ClassParams = {
		&UTutorialCustomAsset::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UTutorialCustomAsset_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UTutorialCustomAsset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTutorialCustomAsset()
	{
		if (!Z_Registration_Info_UClass_UTutorialCustomAsset.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTutorialCustomAsset.OuterSingleton, Z_Construct_UClass_UTutorialCustomAsset_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTutorialCustomAsset.OuterSingleton;
	}
	template<> TUTORIALPLUGIN_API UClass* StaticClass<UTutorialCustomAsset>()
	{
		return UTutorialCustomAsset::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTutorialCustomAsset);
	struct Z_CompiledInDeferFile_FID_MakePlugin_Plugins_TutorialPlugin_Source_TutorialPlugin_Public_TutorialCustomAsset_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MakePlugin_Plugins_TutorialPlugin_Source_TutorialPlugin_Public_TutorialCustomAsset_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTutorialCustomAsset, UTutorialCustomAsset::StaticClass, TEXT("UTutorialCustomAsset"), &Z_Registration_Info_UClass_UTutorialCustomAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTutorialCustomAsset), 1119745173U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MakePlugin_Plugins_TutorialPlugin_Source_TutorialPlugin_Public_TutorialCustomAsset_h_770510764(TEXT("/Script/TutorialPlugin"),
		Z_CompiledInDeferFile_FID_MakePlugin_Plugins_TutorialPlugin_Source_TutorialPlugin_Public_TutorialCustomAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MakePlugin_Plugins_TutorialPlugin_Source_TutorialPlugin_Public_TutorialCustomAsset_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
