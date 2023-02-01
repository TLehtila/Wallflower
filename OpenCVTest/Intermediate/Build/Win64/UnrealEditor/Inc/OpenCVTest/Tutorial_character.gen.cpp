// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OpenCVTest/Public/Tutorial_character.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTutorial_character() {}
// Cross Module References
	OPENCVTEST_API UClass* Z_Construct_UClass_ATutorial_character_NoRegister();
	OPENCVTEST_API UClass* Z_Construct_UClass_ATutorial_character();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_OpenCVTest();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ATutorial_character::execSpawnFlower)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnFlower();
		P_NATIVE_END;
	}
	void ATutorial_character::StaticRegisterNativesATutorial_character()
	{
		UClass* Class = ATutorial_character::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SpawnFlower", &ATutorial_character::execSpawnFlower },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATutorial_character_SpawnFlower_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATutorial_character_SpawnFlower_Statics::Function_MetaDataParams[] = {
		{ "Category", "Abilities" },
		{ "ModuleRelativePath", "Public/Tutorial_character.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATutorial_character_SpawnFlower_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATutorial_character, nullptr, "SpawnFlower", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATutorial_character_SpawnFlower_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ATutorial_character_SpawnFlower_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATutorial_character_SpawnFlower()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATutorial_character_SpawnFlower_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATutorial_character);
	UClass* Z_Construct_UClass_ATutorial_character_NoRegister()
	{
		return ATutorial_character::StaticClass();
	}
	struct Z_Construct_UClass_ATutorial_character_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_flowerToSpawn_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_flowerToSpawn;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATutorial_character_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_OpenCVTest,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATutorial_character_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATutorial_character_SpawnFlower, "SpawnFlower" }, // 4055832049
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATutorial_character_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Tutorial_character.h" },
		{ "ModuleRelativePath", "Public/Tutorial_character.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATutorial_character_Statics::NewProp_flowerToSpawn_MetaData[] = {
		{ "Category", "Tutorial_character" },
		{ "ModuleRelativePath", "Public/Tutorial_character.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATutorial_character_Statics::NewProp_flowerToSpawn = { "flowerToSpawn", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATutorial_character, flowerToSpawn), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ATutorial_character_Statics::NewProp_flowerToSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ATutorial_character_Statics::NewProp_flowerToSpawn_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATutorial_character_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATutorial_character_Statics::NewProp_flowerToSpawn,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATutorial_character_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATutorial_character>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATutorial_character_Statics::ClassParams = {
		&ATutorial_character::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATutorial_character_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATutorial_character_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ATutorial_character_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATutorial_character_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATutorial_character()
	{
		if (!Z_Registration_Info_UClass_ATutorial_character.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATutorial_character.OuterSingleton, Z_Construct_UClass_ATutorial_character_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATutorial_character.OuterSingleton;
	}
	template<> OPENCVTEST_API UClass* StaticClass<ATutorial_character>()
	{
		return ATutorial_character::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATutorial_character);
	struct Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_Tutorial_character_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_Tutorial_character_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATutorial_character, ATutorial_character::StaticClass, TEXT("ATutorial_character"), &Z_Registration_Info_UClass_ATutorial_character, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATutorial_character), 738306214U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_Tutorial_character_h_2574439618(TEXT("/Script/OpenCVTest"),
		Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_Tutorial_character_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_Tutorial_character_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
