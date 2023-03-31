// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyNotifyClass.generated.h"

UCLASS()
class OPENCVTEST_API AMyNotifyClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyNotifyClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void StartTheEnd(const EEndPlayReason::Type EndPlayReason);

private:
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SkeletalMesh;
};

