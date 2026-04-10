// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "POEStudy/Public/GAS/POEGameplayAbility.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePOEGameplayAbility() {}

// Begin Cross Module References
GAMEPLAYABILITIES_API UClass* Z_Construct_UClass_UGameplayAbility();
POESTUDY_API UClass* Z_Construct_UClass_APOEStudyCharacter_NoRegister();
POESTUDY_API UClass* Z_Construct_UClass_APOEStudyPlayerController_NoRegister();
POESTUDY_API UClass* Z_Construct_UClass_UPOEGameplayAbility();
POESTUDY_API UClass* Z_Construct_UClass_UPOEGameplayAbility_NoRegister();
UPackage* Z_Construct_UPackage__Script_POEStudy();
// End Cross Module References

// Begin Class UPOEGameplayAbility Function GetPOECharacterFromActorInfo
struct Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics
{
	struct POEGameplayAbility_eventGetPOECharacterFromActorInfo_Parms
	{
		APOEStudyCharacter* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/GAS/POEGameplayAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(POEGameplayAbility_eventGetPOECharacterFromActorInfo_Parms, ReturnValue), Z_Construct_UClass_APOEStudyCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPOEGameplayAbility, nullptr, "GetPOECharacterFromActorInfo", nullptr, nullptr, Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::POEGameplayAbility_eventGetPOECharacterFromActorInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::POEGameplayAbility_eventGetPOECharacterFromActorInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPOEGameplayAbility::execGetPOECharacterFromActorInfo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(APOEStudyCharacter**)Z_Param__Result=P_THIS->GetPOECharacterFromActorInfo();
	P_NATIVE_END;
}
// End Class UPOEGameplayAbility Function GetPOECharacterFromActorInfo

// Begin Class UPOEGameplayAbility Function GetPOEPlayerControllerFromActorInfo
struct Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics
{
	struct POEGameplayAbility_eventGetPOEPlayerControllerFromActorInfo_Parms
	{
		APOEStudyPlayerController* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ability" },
		{ "ModuleRelativePath", "Public/GAS/POEGameplayAbility.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(POEGameplayAbility_eventGetPOEPlayerControllerFromActorInfo_Parms, ReturnValue), Z_Construct_UClass_APOEStudyPlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPOEGameplayAbility, nullptr, "GetPOEPlayerControllerFromActorInfo", nullptr, nullptr, Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::POEGameplayAbility_eventGetPOEPlayerControllerFromActorInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::POEGameplayAbility_eventGetPOEPlayerControllerFromActorInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UPOEGameplayAbility::execGetPOEPlayerControllerFromActorInfo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(APOEStudyPlayerController**)Z_Param__Result=P_THIS->GetPOEPlayerControllerFromActorInfo();
	P_NATIVE_END;
}
// End Class UPOEGameplayAbility Function GetPOEPlayerControllerFromActorInfo

// Begin Class UPOEGameplayAbility
void UPOEGameplayAbility::StaticRegisterNativesUPOEGameplayAbility()
{
	UClass* Class = UPOEGameplayAbility::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetPOECharacterFromActorInfo", &UPOEGameplayAbility::execGetPOECharacterFromActorInfo },
		{ "GetPOEPlayerControllerFromActorInfo", &UPOEGameplayAbility::execGetPOEPlayerControllerFromActorInfo },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPOEGameplayAbility);
UClass* Z_Construct_UClass_UPOEGameplayAbility_NoRegister()
{
	return UPOEGameplayAbility::StaticClass();
}
struct Z_Construct_UClass_UPOEGameplayAbility_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "GAS/POEGameplayAbility.h" },
		{ "ModuleRelativePath", "Public/GAS/POEGameplayAbility.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UPOEGameplayAbility_GetPOECharacterFromActorInfo, "GetPOECharacterFromActorInfo" }, // 1587726171
		{ &Z_Construct_UFunction_UPOEGameplayAbility_GetPOEPlayerControllerFromActorInfo, "GetPOEPlayerControllerFromActorInfo" }, // 4289608534
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPOEGameplayAbility>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UPOEGameplayAbility_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameplayAbility,
	(UObject* (*)())Z_Construct_UPackage__Script_POEStudy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPOEGameplayAbility_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPOEGameplayAbility_Statics::ClassParams = {
	&UPOEGameplayAbility::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPOEGameplayAbility_Statics::Class_MetaDataParams), Z_Construct_UClass_UPOEGameplayAbility_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPOEGameplayAbility()
{
	if (!Z_Registration_Info_UClass_UPOEGameplayAbility.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPOEGameplayAbility.OuterSingleton, Z_Construct_UClass_UPOEGameplayAbility_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPOEGameplayAbility.OuterSingleton;
}
template<> POESTUDY_API UClass* StaticClass<UPOEGameplayAbility>()
{
	return UPOEGameplayAbility::StaticClass();
}
UPOEGameplayAbility::UPOEGameplayAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPOEGameplayAbility);
UPOEGameplayAbility::~UPOEGameplayAbility() {}
// End Class UPOEGameplayAbility

// Begin Registration
struct Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPOEGameplayAbility, UPOEGameplayAbility::StaticClass, TEXT("UPOEGameplayAbility"), &Z_Registration_Info_UClass_UPOEGameplayAbility, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPOEGameplayAbility), 2614453334U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_4031319727(TEXT("/Script/POEStudy"),
	Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
