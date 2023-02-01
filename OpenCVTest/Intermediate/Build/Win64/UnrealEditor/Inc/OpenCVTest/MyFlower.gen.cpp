// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OpenCVTest/Public/MyFlower.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyFlower() {}
// Cross Module References
	OPENCVTEST_API UClass* Z_Construct_UClass_AMyFlower_NoRegister();
	OPENCVTEST_API UClass* Z_Construct_UClass_AMyFlower();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_OpenCVTest();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AMyFlower::execSpawnActor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SpawnActor();
		P_NATIVE_END;
	}
	void AMyFlower::StaticRegisterNativesAMyFlower()
	{
		UClass* Class = AMyFlower::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SpawnActor", &AMyFlower::execSpawnActor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyFlower_SpawnActor_Statics
	{
		struct MyFlower_eventSpawnActor_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MyFlower_eventSpawnActor_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MyFlower_eventSpawnActor_Parms), &Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyFlower.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyFlower, nullptr, "SpawnActor", nullptr, nullptr, sizeof(Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::MyFlower_eventSpawnActor_Parms), Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyFlower_SpawnActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyFlower_SpawnActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyFlower);
	UClass* Z_Construct_UClass_AMyFlower_NoRegister()
	{
		return AMyFlower::StaticClass();
	}
	struct Z_Construct_UClass_AMyFlower_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyFlower_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OpenCVTest,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyFlower_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyFlower_SpawnActor, "SpawnActor" }, // 1997295529
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyFlower_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyFlower.h" },
		{ "ModuleRelativePath", "Public/MyFlower.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyFlower_Statics::NewProp_StaticMesh_MetaData[] = {
		{ "Category", "MyFlower" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyFlower.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyFlower_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyFlower, StaticMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyFlower_Statics::NewProp_StaticMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyFlower_Statics::NewProp_StaticMesh_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyFlower_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyFlower_Statics::NewProp_StaticMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyFlower_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyFlower>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyFlower_Statics::ClassParams = {
		&AMyFlower::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMyFlower_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyFlower_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyFlower_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyFlower_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyFlower()
	{
		if (!Z_Registration_Info_UClass_AMyFlower.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyFlower.OuterSingleton, Z_Construct_UClass_AMyFlower_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyFlower.OuterSingleton;
	}
	template<> OPENCVTEST_API UClass* StaticClass<AMyFlower>()
	{
		return AMyFlower::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyFlower);
	struct Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_MyFlower_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_MyFlower_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyFlower, AMyFlower::StaticClass, TEXT("AMyFlower"), &Z_Registration_Info_UClass_AMyFlower, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyFlower), 1413146956U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_MyFlower_h_862276913(TEXT("/Script/OpenCVTest"),
		Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_MyFlower_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_MyFlower_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
