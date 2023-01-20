
#ifndef _H_
#define _H_

#include <opencv2/opencv.hpp>


class noiseFilter {
private:
    static const int maxHistory = 10;
    cv::Point2f lastPoint;
    float pointMaxTolerance;
    cv::Point2f history[maxHistory];
    int historyHead, historySize;
public:
    noiseFilter(float maxTolerance);
    cv::Point2f& getResult();
    cv::Point2f& updatePoint(cv::Point2f newPoint);
    float pointDistance(cv::Point2f& point1, cv::Point2f& point2);
};
#endif
