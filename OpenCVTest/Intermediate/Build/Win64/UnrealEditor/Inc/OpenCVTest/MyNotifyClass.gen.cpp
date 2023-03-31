// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OpenCVTest/Public/MyNotifyClass.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyNotifyClass() {}
// Cross Module References
	OPENCVTEST_API UClass* Z_Construct_UClass_AMyNotifyClass_NoRegister();
	OPENCVTEST_API UClass* Z_Construct_UClass_AMyNotifyClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_OpenCVTest();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EEndPlayReason();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AMyNotifyClass::execStartTheEnd)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_EndPlayReason);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartTheEnd(EEndPlayReason::Type(Z_Param_EndPlayReason));
		P_NATIVE_END;
	}
	void AMyNotifyClass::StaticRegisterNativesAMyNotifyClass()
	{
		UClass* Class = AMyNotifyClass::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "StartTheEnd", &AMyNotifyClass::execStartTheEnd },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics
	{
		struct MyNotifyClass_eventStartTheEnd_Parms
		{
			TEnumAsByte<EEndPlayReason::Type> EndPlayReason;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EndPlayReason_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_EndPlayReason;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::NewProp_EndPlayReason_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::NewProp_EndPlayReason = { "EndPlayReason", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyNotifyClass_eventStartTheEnd_Parms, EndPlayReason), Z_Construct_UEnum_Engine_EEndPlayReason, METADATA_PARAMS(Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::NewProp_EndPlayReason_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::NewProp_EndPlayReason_MetaData)) }; // 2713016423
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::NewProp_EndPlayReason,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyNotifyClass.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyNotifyClass, nullptr, "StartTheEnd", nullptr, nullptr, sizeof(Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::MyNotifyClass_eventStartTheEnd_Parms), Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyNotifyClass_StartTheEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyNotifyClass_StartTheEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyNotifyClass);
	UClass* Z_Construct_UClass_AMyNotifyClass_NoRegister()
	{
		return AMyNotifyClass::StaticClass();
	}
	struct Z_Construct_UClass_AMyNotifyClass_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SkeletalMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SkeletalMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyNotifyClass_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OpenCVTest,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyNotifyClass_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyNotifyClass_StartTheEnd, "StartTheEnd" }, // 2205475924
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyNotifyClass_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyNotifyClass.h" },
		{ "ModuleRelativePath", "Public/MyNotifyClass.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyNotifyClass_Statics::NewProp_SkeletalMesh_MetaData[] = {
		{ "Category", "MyNotifyClass" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyNotifyClass.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyNotifyClass_Statics::NewProp_SkeletalMesh = { "SkeletalMesh", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyNotifyClass, SkeletalMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyNotifyClass_Statics::NewProp_SkeletalMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyNotifyClass_Statics::NewProp_SkeletalMesh_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyNotifyClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyNotifyClass_Statics::NewProp_SkeletalMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyNotifyClass_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyNotifyClass>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyNotifyClass_Statics::ClassParams = {
		&AMyNotifyClass::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMyNotifyClass_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyNotifyClass_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyNotifyClass_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyNotifyClass_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyNotifyClass()
	{
		if (!Z_Registration_Info_UClass_AMyNotifyClass.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyNotifyClass.OuterSingleton, Z_Construct_UClass_AMyNotifyClass_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMyNotifyClass.OuterSingleton;
	}
	template<> OPENCVTEST_API UClass* StaticClass<AMyNotifyClass>()
	{
		return AMyNotifyClass::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyNotifyClass);
	struct Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_MyNotifyClass_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_MyNotifyClass_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMyNotifyClass, AMyNotifyClass::StaticClass, TEXT("AMyNotifyClass"), &Z_Registration_Info_UClass_AMyNotifyClass, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyNotifyClass), 3281916272U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_MyNotifyClass_h_4274814560(TEXT("/Script/OpenCVTest"),
		Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_MyNotifyClass_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_OpenCVTest_Source_OpenCVTest_Public_MyNotifyClass_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
