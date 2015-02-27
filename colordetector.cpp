#include "ColorDetector.h"

ColorDetector* ColorDetector::singleton = 0;

ColorDetector::ColorDetector():minDist(100)
{
    target[0] = target[1] = target[2] = 0;
}

ColorDetector* ColorDetector::getInstance()
{
    if(singleton == 0)
    {
        singleton = new ColorDetector;
    }
    return singleton;
}

void ColorDetector::destory()
{
    if(singleton!=0)
    {
        delete singleton;
    }
    singleton = 0;
}

void ColorDetector::setColorDistanceThreshold(int distance)
{
    if(distance < 0)
    {
        distance = 0;
    }
    minDist = distance;
}

int ColorDetector::getColorDistanceThreshold() const
{
    return minDist;
}

void ColorDetector::setTargetColor(unsigned char red,
                unsigned char green, unsigned char blue)
{   // 颜色通道转换
    target[2] = red;
    target[1] = green;
    target[0] = blue;
}

void ColorDetector::setTargetColor(cv::Vec3b color)
{
    target = color;
}

cv::Vec3b ColorDetector::getTargetColor() const
{
    return target;
}

int ColorDetector::getDistance(const cv::Vec3b& color) const
{
    return abs(color[0]-target[0])+abs(color[1]-target[1])+abs(color[2]-target[2]);
}

void ColorDetector::process()
{
    result.create(image.rows, image.cols, CV_8U);
    cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
    cv::Mat_<uchar>::iterator itout = result.begin<uchar>();
        for(; it!=itend; ++it, ++itout)
        {
            if(getDistance(*it) < minDist)
            {
                *itout = 255;
            }else
            {
                *itout = 0;
            }
        }
}

cv::Mat ColorDetector::getResult() const
{
    return result;
}

bool ColorDetector::setInputImage(std::string filename)
{
    image = cv::imread(filename);
        if(!image.data)
        {
            return false;
        }
        return true;
}

cv::Mat ColorDetector::getInputImage() const
{
    return image;
}
