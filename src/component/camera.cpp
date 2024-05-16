#include "component/camera.h"

#include <exception>
#include <vector>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "cv_bridge/cv_bridge.h"

namespace apollo
{
  namespace drivers
  {
    namespace camera
    {

      bool CameraComponent::Init()
      {
        camera_topic = declare_parameter<std::string>("channel_name", "/apollo/sensor/camera/");
        device = declare_parameter<int>("device", 0);
        config_width = declare_parameter<int>("width", 0);
        config_height = declare_parameter<int>("height", 0);
        config_frame_rate = declare_parameter<double>("frame_rate", 30);
        config_pixel_format = declare_parameter<std::string>("pixel_format", "yuyv");
        //string pixel_format [default = "yuyv"];
        //optional uint32 width = 5;
        //optional uint32 height = 6;
        //optional uint32 frame_rate = 7;
        //optional string channel_name = 23;

        RCLCPP_INFO(get_logger(), "BEGIN CONFIG:Camera %d", device);
        RCLCPP_INFO(get_logger(), "\tWidth %d", config_width);
        RCLCPP_INFO(get_logger(), "\tHeight %d", config_height);
        RCLCPP_INFO(get_logger(), "\tTopic %s", camera_topic.c_str());
        RCLCPP_INFO(get_logger(), "END CONFIG  :Camera %d", device);
        writer_ = this->CreateWriter<sensor_msgs::msg::Image>(camera_topic);

        async_result_ = std::async(&CameraComponent::run, this);
        return true;
      }

      void CameraComponent::run()
      {
        running_.exchange(true);

        cv::VideoCapture camera(device);
        if (config_width != 0)
          camera.set(cv::CAP_PROP_FRAME_WIDTH, config_width);
        if (config_height != 0)
          camera.set(cv::CAP_PROP_FRAME_HEIGHT, config_height);

        if (!camera.isOpened())
        {
          AERROR << "ERROR: Could not open camera";
        }
        while (!cyber::IsShutdown())
        {
          cv::Mat frame;
          camera >> frame;

          cv_bridge::CvImage img;
          img.image = frame;
          img.encoding = "bgr8";
          auto msg = img.toImageMsg();

          writer_->Write(msg);

          cv::waitKey(1);
        }
      }

      CameraComponent::~CameraComponent()
      {
        if (running_.load())
        {
          running_.exchange(false);
          async_result_.wait();
        }
      }

    } // namespace camera
  }   // namespace drivers
} // namespace apollo