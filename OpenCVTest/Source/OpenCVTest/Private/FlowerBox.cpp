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

//https://forums.unrealengine.com/t/using-unreal-engine-5-0-3-or-5-1-0-built-in-opencv-plugin/744951
#include "PreOpenCVHeaders.h"
#include "OpenCVHelper.h"
#include <ThirdParty/OpenCV/include/opencv2/imgproc.hpp>
#include <ThirdParty/OpenCV/include/opencv2/highgui/highgui.hpp>
#include <ThirdParty/OpenCV/include/opencv2/core.hpp>
#include "PostOpenCVHeaders.h"

#include "Kismet/GameplayStatics.h"

#include "NoiseFilter.h"


// Sets default values
AFlowerBox::AFlowerBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 
	bAllowTickBeforeBeginPlay = true;

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
		ScheduleVideoProcess();
	}

	capOne.open(0);
	capTwo.open(1);

	if (!capOne.isOpened() || !capTwo.isOpened()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Failed to open videocapture"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Videocaptures open"));
	}

	noiseFilterOne = new NoiseFilter(10.5f);
	noiseFilterTwo = new NoiseFilter(10.5f);
	noiseFilterFinal = new NoiseFilter(10.5f);

	pBackSubOne = cv::createBackgroundSubtractorMOG2();
	pBackSubTwo = cv::createBackgroundSubtractorMOG2();

	capOne >> frameOne;
	capTwo >> frameTwo;
	correctedPointsTogether.x = 0.0f;
	correctedPointsTogether.y = 0.0f;

	cameraX = 640.0f;
	cameraY = 360.0f;
	displayX = 140.0f;
	displayY = 85.0f;
	additionalX = -70.0f;
	additionalY = 70.0f;


	//int capOneWidth = frameOne.size[1];
	//int capOneHeight = frameOne.size[0];
	//int capTwoWidth = frameTwo.size[1];
	//int capTwoHeight = frameTwo.size[0];

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("capOne: x = %f, y = %f"), capOneWidth, capOneHeight));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("capTwo: x = %f, y = %f"), capTwoWidth, capTwoHeight));


}

void AFlowerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!playing) {
		playing = true;
	}

	auto i = std::begin(flowers);
	int spot = 0;

	while (i != std::end(flowers)) {

		if (flowers[spot]!= nullptr) {
			FVector flowerLocation = flowers[spot]->GetActorLocation();
			//FRotator flowerRotation = flowers[spot]->GetActorRotation();

			flowerLocation.Z += 1;
			//flowerRotation += {10, 0, 0};
			//if (flowerRotation.Roll > 360) {
			//	flowerRotation = { 0, -90, 0 };
			//}
		
			flowers[spot]->SetActorLocation(flowerLocation);
			//flowers[spot]->SetActorRotation(flowerRotation);

			if (flowerLocation.Z > displayX + 10) {
				flowers[spot]->Destroy();
				flowers.erase(i);
			}
			else {
				i++;
				spot++;
			}
		}
	}

}

void AFlowerBox::EndPlay(const EEndPlayReason::Type EndPlayReason) {
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

bool AFlowerBox::SpawnActor() {
	bool Success = false;
	AActor* SpawnedActor;
	if (true) {
		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());

		FVector SpawnLocation;
		FRotator SpawnRotation = { 0, -90, 0 };
		SpawnLocation.X += 75;
		SpawnLocation.Y += displayPointY;
		SpawnLocation.Z += displayPointX;

		SpawnedActor = GetWorld()->SpawnActor<AActor>(FlowerToBeSpawned, SpawnLocation, SpawnRotation);

		if (SpawnedActor != nullptr) {
			Success = true;
			flowers.push_back(SpawnedActor);
		}

		if (Success) {

			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Spawned"));
		}
	}

	return Success;
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

void AFlowerBox::ScheduleVideoProcess() {
	float DeltaToNextProcess = 0.1;

	GetWorld()->GetTimerManager().SetTimer(VideoTimerHandle, this, &AFlowerBox::processVideo, DeltaToNextProcess, false);
}

void AFlowerBox::processVideo() {
	if(playing) {
		capOne >> frameOne;
		capTwo >> frameTwo;


		//GaussianBlur(frameOne, frameBlurOne, Size(9, 9), 5, 0);
		//GaussianBlur(frameTwo, frameBlurTwo, Size(9, 9), 5, 0);


		pBackSubOne->apply(frameOne, fgMaskOne, -1.0);
		pBackSubTwo->apply(frameTwo, fgMaskTwo, -1.0);

		//cv::Canny(fgMaskOne, cannyOne, 50, 150);
		//cv::Canny(fgMaskTwo, cannyTwo, 50, 150);


		touchPointOne = getContours(fgMaskOne);
		touchPointTwo = getContours(fgMaskTwo);
		correctedPointOne = noiseFilterOne->updatePoint(touchPointOne);
		correctedPointTwo = noiseFilterTwo->updatePoint(touchPointTwo);

		pointsTogether.x = correctedPointTwo.x;
		pointsTogether.y = correctedPointOne.y;

		correctedPointsTogether = noiseFilterFinal->updatePoint(pointsTogether);

		//https://stackoverflow.com/questions/929103/convert-a-number-range-to-another-range-maintaining-ratio

		displayPointX = displayX - ((correctedPointsTogether.x * displayX) / cameraX) + additionalX;
		displayPointY = (correctedPointsTogether.y * displayY) / cameraY + additionalY;

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("spawn coordinates: x = %f, y = %f"), displayPointX, displayPointY));
		ScheduleVideoProcess();
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

