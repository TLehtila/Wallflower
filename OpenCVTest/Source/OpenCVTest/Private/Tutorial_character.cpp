// Fill out your copyright notice in the Description page of Project Settings.


#include "Tutorial_character.h"

// Sets default values
ATutorial_character::ATutorial_character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATutorial_character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATutorial_character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATutorial_character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATutorial_character::SpawnFlower() 
{
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(flowerToSpawn, GetActorTransform(), spawnParams);
}