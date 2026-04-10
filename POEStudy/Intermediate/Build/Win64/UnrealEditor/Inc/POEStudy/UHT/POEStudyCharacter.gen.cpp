// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "POEStudy/POEStudyCharacter.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePOEStudyCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
POESTUDY_API UClass* Z_Construct_UClass_APOEStudyCharacter();
POESTUDY_API UClass* Z_Construct_UClass_APOEStudyCharacter_NoRegister();
POESTUDY_API UClass* Z_Construct_UClass_UPOEAbilitySystemComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_POEStudy();
// End Cross Module References

// Begin Class APOEStudyCharacter Function OnCharacterLanded
struct POEStudyCharacter_eventOnCharacterLanded_Parms
{
	FHitResult Hit;
};
static const FName NAME_APOEStudyCharacter_OnCharacterLanded = FName(TEXT("OnCharacterLanded"));
void APOEStudyCharacter::OnCharacterLanded(FHitResult const& Hit)
{
	POEStudyCharacter_eventOnCharacterLanded_Parms Parms;
	Parms.Hit=Hit;
	UFunction* Func = FindFunctionChecked(NAME_APOEStudyCharacter_OnCharacterLanded);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "POEStudyCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(POEStudyCharacter_eventOnCharacterLanded_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics::NewProp_Hit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APOEStudyCharacter, nullptr, "OnCharacterLanded", nullptr, nullptr, Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics::PropPointers), sizeof(POEStudyCharacter_eventOnCharacterLanded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics::Function_MetaDataParams), Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics::Function_MetaDataParams) };
static_assert(sizeof(POEStudyCharacter_eventOnCharacterLanded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded_Statics::FuncParams);
	}
	return ReturnFunction;
}
// End Class APOEStudyCharacter Function OnCharacterLanded

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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbilitySystemComp_MetaData[] = {
		{ "Category", "POE Study" },
		{ "EditInline", "true" },
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
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AbilitySystemComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TopDownCameraComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APOEStudyCharacter_OnCharacterLanded, "OnCharacterLanded" }, // 3377488841
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APOEStudyCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APOEStudyCharacter_Statics::NewProp_AbilitySystemComp = { "AbilitySystemComp", nullptr, (EPropertyFlags)0x01140000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APOEStudyCharacter, AbilitySystemComp), Z_Construct_UClass_UPOEAbilitySystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbilitySystemComp_MetaData), NewProp_AbilitySystemComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APOEStudyCharacter_Statics::NewProp_TopDownCameraComponent = { "TopDownCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APOEStudyCharacter, TopDownCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TopDownCameraComponent_MetaData), NewProp_TopDownCameraComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APOEStudyCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APOEStudyCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APOEStudyCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APOEStudyCharacter_Statics::NewProp_AbilitySystemComp,
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
	FuncInfo,
	Z_Construct_UClass_APOEStudyCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
		{ Z_Construct_UClass_APOEStudyCharacter, APOEStudyCharacter::StaticClass, TEXT("APOEStudyCharacter"), &Z_Registration_Info_UClass_APOEStudyCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APOEStudyCharacter), 3388239143U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyCharacter_h_834906914(TEXT("/Script/POEStudy"),
	Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_POEStudyCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
