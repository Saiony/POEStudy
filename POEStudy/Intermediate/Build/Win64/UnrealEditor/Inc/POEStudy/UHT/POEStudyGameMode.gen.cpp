// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "POEStudy/POEStudyGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePOEStudyGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
POESTUDY_API UClass* Z_Construct_UClass_APOEStudyGameMode();
POESTUDY_API UClass* Z_Construct_UClass_APOEStudyGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_POEStudy();
// End Cross Module References

// Begin Class APOEStudyGameMode
void APOEStudyGameMode::StaticRegisterNativesAPOEStudyGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APOEStudyGameMode);
UClass* Z_Construct_UClass_APOEStudyGameMode_NoRegister()
{
	return APOEStudyGameMode::StaticClass();
}
struct Z_Construct_UClass_APOEStudyGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "POEStudyGameMode.h" },
		{ "ModuleRelativePath", "POEStudyGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APOEStudyGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_APOEStudyGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_POEStudy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APOEStudyGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APOEStudyGameMode_Statics::ClassParams = {
	&APOEStudyGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APOEStudyGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_APOEStudyGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APOEStudyGameMode()
{
	if (!Z_Registration_Info_UClass_APOEStudyGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APOEStudyGameMode.OuterSingleton, Z_Construct_UClass_APOEStudyGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APOEStudyGameMode.OuterSingleton;
}
template<> POESTUDY_API UClass* StaticClass<APOEStudyGameMode>()
{
	return APOEStudyGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APOEStudyGameMode);
APOEStudyGameMode::~APOEStudyGameMode() {}
// End Class APOEStudyGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APOEStudyGameMode, APOEStudyGameMode::StaticClass, TEXT("APOEStudyGameMode"), &Z_Registration_Info_UClass_APOEStudyGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APOEStudyGameMode), 3724767493U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyGameMode_h_2178327838(TEXT("/Script/POEStudy"),
	Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
