#include "yolov3.h"



Yolov3::Yolov3(const std::string &model_path) {
    std::string param_files = model_path + "yolov3-tiny_obj_opt.param";
    std::string bin_files = model_path + "yolov3-tiny_obj_opt.bin";
    yolov3.load_param(param_files.c_str());
    yolov3.load_model(bin_files.c_str());
}

Yolov3::~Yolov3() {
    yolov3.clear();
}

void Yolov3::Yolov3Net(ncnn::Mat& img_) {
    ncnn::Extractor ex = yolov3.create_extractor();
    ex.set_num_threads(4);
    ex.set_light_mode(true);
    ex.input("data", img_);
    ex.extract("output", out);
}

void Yolov3::start(const cv::Mat& img, int target_width_size, int target_height_size, std::vector<Object> &objects) {
	int img_w = img.cols;
    int img_h = img.rows;
    ncnn::Mat ncnn_img = ncnn::Mat::from_pixels_resize(img.data,  ncnn::Mat::PIXEL_BGR2RGB, img.cols, img.rows, target_width_size, target_height_size);

    const float mean_vals[3] = {0, 0, 0};
    const float norm_vals[3] = {1 / 255.0, 1 / 255.0, 1 / 255.0};
    ncnn_img.substract_mean_normalize(0, norm_vals);
    Yolov3Net(ncnn_img);
	objects.clear();
	for (int i=0; i<out.h; i++)
	{
		const float* values = out.row(i);

		Object object;
		object.label = values[0];
		object.prob = values[1];
		object.rect.x = values[2] * img_w;
		object.rect.y = values[3] * img_h;
		object.rect.width = values[4] * img_w - object.rect.x;
		object.rect.height = values[5] * img_h - object.rect.y;
		objects.push_back(object);
	}

}

void Yolov3::start(const cv::Mat& img, int target_width_size, int target_height_size, float prob, std::vector<cv::Rect> &objects) {
	int img_w = img.cols;
    int img_h = img.rows;
    ncnn::Mat ncnn_img = ncnn::Mat::from_pixels_resize(img.data,  ncnn::Mat::PIXEL_BGR2RGB, img.cols, img.rows, target_width_size, target_height_size);

    const float mean_vals[3] = {0, 0, 0};
    const float norm_vals[3] = {1 / 255.0, 1 / 255.0, 1 / 255.0};
    ncnn_img.substract_mean_normalize(0, norm_vals);
    Yolov3Net(ncnn_img);
	objects.clear();
	for (int i=0; i<out.h; i++)
	{
		const float* values = out.row(i);
		cv::Rect object;
		if(values[1] > 0.8)
		{
			object.x = values[2] * img_w;
			object.y = values[3] * img_h;
			object.width = values[4] * img_w;
			object.height = values[5] * img_h;
			objects.push_back(object);
		}	
	}

}


cv::Mat Yolov3::draw_objects(const cv::Mat& img, const std::vector<Object>& objects)
{
    
    //cv::Mat image = img.clone();

    for (size_t i = 0; i < objects.size(); i++)
    {
        const Object& obj = objects[i];

		if(obj.prob > 0.9)
        	cv::rectangle(img, obj.rect, cv::Scalar(255, 0, 0));
    }

	return img;
}

