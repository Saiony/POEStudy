// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GAS/POEGameplayAbility.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APOEStudyCharacter;
class APOEStudyPlayerController;
#ifdef POESTUDY_POEGameplayAbility_generated_h
#error "POEGameplayAbility.generated.h already included, missing '#pragma once' in POEGameplayAbility.h"
#endif
#define POESTUDY_POEGameplayAbility_generated_h

#define FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetPOEPlayerControllerFromActorInfo); \
	DECLARE_FUNCTION(execGetPOECharacterFromActorInfo);


#define FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPOEGameplayAbility(); \
	friend struct Z_Construct_UClass_UPOEGameplayAbility_Statics; \
public: \
	DECLARE_CLASS(UPOEGameplayAbility, UGameplayAbility, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/POEStudy"), NO_API) \
	DECLARE_SERIALIZER(UPOEGameplayAbility)


#define FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPOEGameplayAbility(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UPOEGameplayAbility(UPOEGameplayAbility&&); \
	UPOEGameplayAbility(const UPOEGameplayAbility&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPOEGameplayAbility); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPOEGameplayAbility); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPOEGameplayAbility) \
	NO_API virtual ~UPOEGameplayAbility();


#define FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_15_PROLOG
#define FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_18_INCLASS_NO_PURE_DECLS \
	FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> POESTUDY_API UClass* StaticClass<class UPOEGameplayAbility>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_caue_gamedev_POEStudy_POEStudy_Source_POEStudy_Public_GAS_POEGameplayAbility_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
