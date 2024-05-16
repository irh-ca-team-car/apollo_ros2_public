#include "component/adc-trajectory-adapter.h"

#include <exception>
#include <vector>
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
namespace apollo
{
  namespace drivers
  {
    namespace adapter
    {

      bool ADCTrajectoryAdapterComponent::Init()
      {
        auto input_topic = declare_parameter<std::string>("input_topic", "/apollo/sensor/camera/apollo");
        auto output_topic = declare_parameter<std::string>("output_topic", "/apollo/sensor/camera/ros");
        world_frame = declare_parameter<std::string>("world_frame", "/world");

        reader_ = this->CreateReader<apollo_msgs::msg::ApolloplanningADCTrajectory>(input_topic, std::bind(&ADCTrajectoryAdapterComponent::Proc, this, std::placeholders::_1));
        writer_ = this->CreateWriter<nav_msgs::msg::Path>(output_topic);

        return true;
      }

      void ADCTrajectoryAdapterComponent::Proc(const std::shared_ptr<apollo_msgs::msg::ApolloplanningADCTrajectory> trajectory_apollo)
      {
        nav_msgs::msg::Path path_cmd;

        for (const auto &trajectory_point : trajectory_apollo->trajectorypoint)
        {
          geometry_msgs::msg::PoseStamped pose;
          pose.header.frame_id = world_frame;
          pose.pose.position.x = trajectory_point.pathpoint.x;
          pose.pose.position.y = trajectory_point.pathpoint.y;
          pose.pose.position.z = trajectory_point.pathpoint.z;
  
          tf2::Quaternion q_tf;
          q_tf.setRPY(0.0, 0.0, trajectory_point.pathpoint.theta);
          pose.pose.orientation = tf2::toMsg(q_tf);

          path_cmd.poses.push_back(pose);
        }

        path_cmd.header.frame_id = world_frame;
        path_cmd.header.stamp = node_->get_clock()->now();

        writer_->Write(path_cmd);
      }
    } // namespace camera
  }   // namespace drivers
} // namespace apollo