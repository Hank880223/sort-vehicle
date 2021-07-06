#pragma once
#ifndef YOLOV3NET_H_
#define YOLOV3NET_H_
#include <string>
#include "net.h"
#include "opencv2/opencv.hpp"

struct Object
{
    cv::Rect_<float> rect;
    int label;
    float prob;
};

class Yolov3 {
public:

	Yolov3(const std::string &model_path);
	~Yolov3();
	void start(const cv::Mat& img, int target_width_size, int target_height_size, std::vector<Object> &objects);
	void start(const cv::Mat& img, int target_width_size, int target_height_size, float prob, std::vector<cv::Rect> &objects);
	cv::Mat draw_objects(const cv::Mat& img, const std::vector<Object>& objects);
	
private:
	void Yolov3Net(ncnn::Mat& img_);
	ncnn::Net yolov3;
	ncnn::Mat ncnn_img;
	ncnn::Mat out;
	
};

#endif // !MOBILEFACENET_H_
