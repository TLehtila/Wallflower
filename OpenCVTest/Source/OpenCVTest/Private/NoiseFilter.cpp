// Fill out your copyright notice in the Description page of Project Settings.


#include "NoiseFilter.h"

#include "PreOpenCVHeaders.h"
#include "OpenCVHelper.h"
#include <ThirdParty/OpenCV/include/opencv2/imgproc.hpp>
#include <ThirdParty/OpenCV/include/opencv2/imgcodecs.hpp>
#include <ThirdParty/OpenCV/include/opencv2/videoio.hpp>
#include <ThirdParty/OpenCV/include/opencv2/video.hpp>
#include <ThirdParty/OpenCV/include/opencv2/highgui/highgui.hpp>
#include <ThirdParty/OpenCV/include/opencv2/core.hpp>
#include "PostOpenCVHeaders.h"

// adapted from https://stackoverflow.com/a/50047253
NoiseFilter::NoiseFilter(float maxTolerance )
{
    historyHead = historySize = 0;
    pointMaxTolerance = maxTolerance * maxTolerance;
    lastPoint = cv::Point2f(0.0f, 0.0f);
}

NoiseFilter::~NoiseFilter()
{
}

cv::Point2f& NoiseFilter::getResult() {
    float sumx = 0;
    float sumy = 0;
    for (int i = 0; i < historySize; i++) {
        sumx += history[i].x;
        sumy += history[i].y;
    }

    lastPoint.x = sumx / historySize;
    lastPoint.y = sumy / historySize;

    return lastPoint;
}

cv::Point2f& NoiseFilter::updatePoint(cv::Point2f newPoint) {
    float distance = pointDistance(lastPoint, newPoint);
    //if (distance > pointMaxTolerance) {
    //    historyHead = historySize = 0;
    //}
    history[historyHead] = newPoint;
    historyHead = (historyHead + 1) % maxHistory;
    if (historySize < maxHistory) {
        historySize++;
    }
    cv::Point2f point = getResult();
    return getResult();
}

float NoiseFilter::pointDistance(cv::Point2f& point1, cv::Point2f& point2) {
    float distancex = point1.x - point2.x;
    float distancey = point1.y - point2.y;
    return (distancex * distancex + distancey * distancey);
}
