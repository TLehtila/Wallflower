// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowerBox.h"
//#include <opencv2/core.hpp>
//
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/videoio.hpp>
//#include <opencv2/video.hpp>

#include <fstream>
#include <iostream>
#include <array>
#include <string>
#include <filesystem>

#include "PreOpenCVHeaders.h"
#include "OpenCVHelper.h"
#include <ThirdParty/OpenCV/include/opencv2/imgproc.hpp>
#include <ThirdParty/OpenCV/include/opencv2/highgui/highgui.hpp>
#include <ThirdParty/OpenCV/include/opencv2/core.hpp>
#include "PostOpenCVHeaders.h"

#include "NoiseFilter.h"


// Sets default values
AFlowerBox::AFlowerBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 

	//PrimaryActorTick.bStartWithTickEnabled = true;
	//PrimaryActorTick.bAllowTickOnDedicatedServer = true;
	bAllowTickBeforeBeginPlay = true;

	//PrimaryActorTick.RegisterTickFunction(GetLevel());

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;
}

//https://www.youtube.com/watch?v=pNpHU2exYI8

// Called when the game starts or when spawned
void AFlowerBox::BeginPlay()
{
	Super::BeginPlay();

	if (ShouldSpawn) {
		ScheduleActorSpawn();
	}

	capOne.open(0);

	if (!capOne.isOpened()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Failed to open videocapture"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Videocapture open??"));
	}

	noiseFilterOne = new NoiseFilter(10.5f);
	noiseFilterTwo = new NoiseFilter(10.5f);
	noiseFilterFinal = new NoiseFilter(10.5f);


	//capOne >> frameOne;
	//capTwo >> frameTwo;

	//int capOneWidth = frameOne.size[1];
	//int capOneHeight = frameOne.size[0];
	//int capTwoWidth = frameTwo.size[1];
	//int capTwoHeight = frameTwo.size[0];



}

void AFlowerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	capOne.read(frameOne);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Tick tock"));
	//cv::imshow("camera", frameOne);




	capOne >> frameOne;
	capTwo >> frameTwo;


	//GaussianBlur(frameOne, frameBlurOne, Size(9, 9), 5, 0);
	//GaussianBlur(frameTwo, frameBlurTwo, Size(9, 9), 5, 0);


	//pBackSubOne->cv::apply(frameOne, fgMaskOne, -1.0);
	//pBackSubTwo->cv::apply(frameTwo, fgMaskTwo, -1.0);

	//cv::Canny(fgMaskOne, cannyOne, 50, 150);
	//cv::Canny(fgMaskTwo, cannyTwo, 50, 150);


	//touchPointOne = getContours(fgMaskOne);
	//touchPointTwo = getContours(fgMaskTwo);
	//correctedPointOne = noiseFilterOne->updatePoint(touchPointOne);
	//correctedPointTwo = noiseFilterTwo->updatePoint(touchPointTwo);


	//pointsTogether.x = correctedPointTwo.x;
	//pointsTogether.y = correctedPointOne.y;

	//correctedPointsTogether = noiseFilterFinal->updatePoint(pointsTogether);

	

}

void AFlowerBox::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

bool AFlowerBox::SpawnActor() {
	bool SpawnedActor = false;
	if (true) {
		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());

		FVector SpawnLocation = BoxBounds.Origin;
		FRotator SpawnRotation = { 0, -90, 0 };
		SpawnLocation.X += -BoxBounds.BoxExtent.X + 2 * BoxBounds.BoxExtent.X * FMath::FRand();
		SpawnLocation.Y += -BoxBounds.BoxExtent.Y + 2 * BoxBounds.BoxExtent.Y * FMath::FRand();
		SpawnLocation.Z += -BoxBounds.BoxExtent.Z + 2 * BoxBounds.BoxExtent.Z * FMath::FRand();

		SpawnedActor = GetWorld()->SpawnActor<AActor>(FlowerToBeSpawned, SpawnLocation, SpawnRotation) != nullptr;

		if (SpawnedActor) {

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Spawned"));
		}
	}

	return SpawnedActor;
}

void AFlowerBox::ScheduleActorSpawn() {
	float DeltaToNextSpawn = SpawnTime + (-RandomTime + 2 * RandomTime * FMath::FRand());

	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AFlowerBox::SpawnActorScheduled, DeltaToNextSpawn, false);
}


void AFlowerBox::SpawnActorScheduled() {
	if (SpawnActor()) {
		if (ShouldSpawn) {
			ScheduleActorSpawn();
		}
	}
	else {

	}
}



cv::Point2f AFlowerBox::getContours(cv::Mat img) {
	cv::Point2f coordinates;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	//drawContours(imgResult, contours, -1, Scalar(150, 50, 0), 5);

	//Point corner;
	std::vector<std::vector<cv::Point>> contourPoly(contours.size());
	std::vector<cv::Rect> boundRectangle(contours.size());

	for (int i = 0; i < contours.size(); i++) {
		int area = cv::contourArea(contours[i]);
		if (area > 1000) {
			float perimeter = cv::arcLength(contours[i], true);
			cv::approxPolyDP(contours[i], contourPoly[i], 0.02 * perimeter, true);
			//drawContours(imgResult, contourPoly, i, Scalar(150, 50, 0), 5);

			boundRectangle[i] = cv::boundingRect(contourPoly[i]);
			//rectangle(imgResult, boundRectangle[i].tl(), boundRectangle[i].br(), cv::Scalar(255, 255, 255), 5);
			coordinates = boundRectangle[i].br();

		}
	}
	return coordinates;
}

