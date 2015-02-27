#ifndef COLORDETECTOR_H_
#define COLORDETECTOR_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>

class ColorDetector
{
private:
        int minDist;
        cv::Vec3b target;
        cv::Mat result;
        cv::Mat image;
        ColorDetector();
        // 提供静态的接口来获得ColorDetector对象
        static ColorDetector *singleton;

public:
    cv::Mat getInputImage() const; // 载入图像
    cv::Mat getResult() const; // 返回图像处理结果
    void process(); // 将阈值范围内的像素点置为255，其余为0
    int getDistance(const cv::Vec3b&) const;
    bool setInputImage(std::string); // 判断是否已输入图像
    static ColorDetector * getInstance(); // 使用单例模式创建类的实例
    static void destory(); // 一个对象的析构函数
    // 设置颜色阈值
    void setColorDistanceThreshold(int);
    int getColorDistanceThreshold() const;
    // 设置颜色
    void setTargetColor(unsigned char, unsigned char, unsigned char); // 颜色通道转换
    void setTargetColor(cv::Vec3b);
    cv::Vec3b getTargetColor() const;
};


#endif /* COLORDETECTOR_H_ */
