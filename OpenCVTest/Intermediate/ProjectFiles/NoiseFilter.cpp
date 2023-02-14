#include "NoiseFilter.h"


#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>


//https://stackoverflow.com/a/50047253
static const int maxHistory = 10;
cv::Point2f lastPoint;
float pointMaxTolerance;
cv::Point2f history[maxHistory];
int historyHead, historySize;


NoiseFilter::noiseFilter(float maxTolerance) {
    historyHead = historySize = 0;
    pointMaxTolerance = maxTolerance * maxTolerance;
    lastPoint = cv::Point2f(0.0f, 0.0f);
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
    float distance = noiseFilter::pointDistance(lastPoint, newPoint);
    if (distance > pointMaxTolerance) {
        historyHead = historySize = 0;
    }
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
