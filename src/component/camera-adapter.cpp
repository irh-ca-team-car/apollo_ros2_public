#include "component/camera-adapter.h"
#include "cv_bridge/cv_bridge.h"
#include "image_transport/image_transport.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <exception>
#include <vector>

namespace apollo
{
  namespace drivers
  {
    namespace camera
    {

      bool CameraAdapterComponent::Init()
      {
        auto input_topic = declare_parameter<std::string>("input_topic", "/apollo/sensor/camera/ros");
        auto output_topic = declare_parameter<std::string>("output_topic", "/apollo/sensor/camera/apollo");
        width = declare_parameter<int>("width", 1920);
        height = declare_parameter<int>("height", 1080);
        rclcpp::Node::SharedPtr node = std::shared_ptr<rclcpp::Node>(node_);
        static image_transport::ImageTransport it(node);
        static image_transport::Subscriber readerit_=it.subscribe(input_topic, 1, [this](const sensor_msgs::msg::Image::ConstSharedPtr & msg){
          Proc(msg);
        });
        //reader_ = this->CreateReader<sensor_msgs::msg::Image>(input_topic, std::bind(&CameraAdapterComponent::Proc, this, std::placeholders::_1));
        writer_ = this->CreateWriter<apollo::drivers::Image>(output_topic);

        return true;
      }

      void CameraAdapterComponent::Proc(const sensor_msgs::msg::Image::ConstSharedPtr & msg)
      {
        if(msg->header.stamp.sec < this->get_clock()->now().seconds() - 1800) 
        {
          AWARN << "Receiving old data";
          return;
        }
        else
        {
          //AINFO << "Received image to process";
        }
        sensor_msgs::msg::Image::SharedPtr smsg_;
        try
        {
          auto cv_img = cv_bridge::toCvShare(msg, "bgr8")->image;
          cv::Mat img_dst;
          cv::resize(cv_img, img_dst, cv::Size(width, height), 0, 0, cv::INTER_AREA);
          smsg_ = cv_bridge::CvImage(msg->header, "bgr8", img_dst).toImageMsg();
        }
        catch (cv_bridge::Exception &e)
        {
          AERROR << "Could not convert from '"<< msg->encoding.c_str()<<"' to 'bgr8'.";
          return;
        }
        if (smsg_ != nullptr)
        {
          sensor_msgs::msg::Image smsg = *smsg_;

          apollo::drivers::Image img_apollo;
          img_apollo.data.data = smsg.data;
          img_apollo.encoding = "bgr8";
          img_apollo.apolloheader.frameid = smsg.header.frame_id;
          img_apollo.apolloheader.timestampsec = smsg.header.stamp.sec;
          img_apollo.height = smsg.height;
          img_apollo.width = smsg.width;
          img_apollo.step = smsg.step;
          img_apollo.frameid = smsg.header.frame_id;
          //AERROR << "Publishing";

          writer_->Write(img_apollo);
        }
      }
    } // namespace camera
  }   // namespace drivers
} // namespace apollo