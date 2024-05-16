#include "component/odometry-adapter.h"

#include <exception>
#include <vector>
namespace apollo
{
  namespace drivers
  {
    namespace adapter
    {

      bool OdometryAdapterComponent::Init()
      {
        auto input_topic = declare_parameter<std::string>("input_topic", "/apollo/sensor/camera/apollo");
        auto output_topic = declare_parameter<std::string>("output_topic", "/apollo/sensor/camera/ros");
        world_frame = declare_parameter<std::string>("world_frame", "/world");

        reader_ = this->CreateReader<apollo_msgs::msg::ApollolocalizationLocalizationEstimate>(input_topic, std::bind(&OdometryAdapterComponent::Proc, this, std::placeholders::_1));
        writer_ = this->CreateWriter<nav_msgs::msg::Odometry>(output_topic);

        return true;
      }

      void OdometryAdapterComponent::Proc(const std::shared_ptr<apollo_msgs::msg::ApollolocalizationLocalizationEstimate> localization_apollo)
      {
        nav_msgs::msg::Odometry odom;

        odom.header.frame_id = world_frame;
        odom.header.stamp = get_clock()->now();

        //convert pose from apollo to pose in ROS
        //position
        odom.pose.pose.position.x = localization_apollo->pose.position.x;
        odom.pose.pose.position.y = localization_apollo->pose.position.y;
        odom.pose.pose.position.z = localization_apollo->pose.position.z;

        //orientation
        odom.pose.pose.orientation.x = localization_apollo->pose.orientation.qx;
        odom.pose.pose.orientation.y = localization_apollo->pose.orientation.qy;
        odom.pose.pose.orientation.z = localization_apollo->pose.orientation.qz;
        odom.pose.pose.orientation.w = localization_apollo->pose.orientation.qw;

        //converting twists
        //linear
        odom.twist.twist.linear.x = localization_apollo->pose.linearvelocity.x;
        odom.twist.twist.linear.y = localization_apollo->pose.linearvelocity.y;
        odom.twist.twist.linear.z = localization_apollo->pose.linearvelocity.z;
        //angular
        odom.twist.twist.angular.x = localization_apollo->pose.angularvelocity.x;
        odom.twist.twist.angular.y = localization_apollo->pose.angularvelocity.y;
        odom.twist.twist.angular.z = localization_apollo->pose.angularvelocity.z;

        writer_->Write(odom);
      }
    } // namespace camera
  }   // namespace drivers
} // namespace apollo