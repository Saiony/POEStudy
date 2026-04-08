// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "POEStudy/POEStudyCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePOEStudyCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
POESTUDY_API UClass* Z_Construct_UClass_APOEStudyCharacter();
POESTUDY_API UClass* Z_Construct_UClass_APOEStudyCharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_POEStudy();
// End Cross Module References

// Begin Class APOEStudyCharacter
void APOEStudyCharacter::StaticRegisterNativesAPOEStudyCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APOEStudyCharacter);
UClass* Z_Construct_UClass_APOEStudyCharacter_NoRegister()
{
	return APOEStudyCharacter::StaticClass();
}
struct Z_Construct_UClass_APOEStudyCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "POEStudyCharacter.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "POEStudyCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TopDownCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Top down camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "POEStudyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Top down camera" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera above the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "POEStudyCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera above the character" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TopDownCameraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APOEStudyCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APOEStudyCharacter_Statics::NewProp_TopDownCameraComponent = { "TopDownCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APOEStudyCharacter, TopDownCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TopDownCameraComponent_MetaData), NewProp_TopDownCameraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APOEStudyCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APOEStudyCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APOEStudyCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APOEStudyCharacter_Statics::NewProp_TopDownCameraComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APOEStudyCharacter_Statics::NewProp_CameraBoom,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APOEStudyCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APOEStudyCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_POEStudy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APOEStudyCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APOEStudyCharacter_Statics::ClassParams = {
	&APOEStudyCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_APOEStudyCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_APOEStudyCharacter_Statics::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APOEStudyCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_APOEStudyCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APOEStudyCharacter()
{
	if (!Z_Registration_Info_UClass_APOEStudyCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APOEStudyCharacter.OuterSingleton, Z_Construct_UClass_APOEStudyCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APOEStudyCharacter.OuterSingleton;
}
template<> POESTUDY_API UClass* StaticClass<APOEStudyCharacter>()
{
	return APOEStudyCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APOEStudyCharacter);
APOEStudyCharacter::~APOEStudyCharacter() {}
// End Class APOEStudyCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APOEStudyCharacter, APOEStudyCharacter::StaticClass, TEXT("APOEStudyCharacter"), &Z_Registration_Info_UClass_APOEStudyCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APOEStudyCharacter), 3609184500U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyCharacter_h_2117827806(TEXT("/Script/POEStudy"),
	Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
