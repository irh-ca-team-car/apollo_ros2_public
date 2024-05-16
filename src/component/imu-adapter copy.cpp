#include "component/imu-adapter.h"

#include <exception>
#include <vector>
#include <cmath>

namespace apollo
{
  namespace drivers
  {
    namespace adapter
    {

      bool IMUAdapterComponent::Init()
      {
        auto input_topic = declare_parameter<std::string>("input_topic", "/apollo/sensor/camera/ros");
        auto output_topic = declare_parameter<std::string>("output_topic", "/apollo/sensor/gnss/imu");
        auto output_topic_c = declare_parameter<std::string>("output_topic_corrected", "/apollo/sensor/gnss/corrected_imu");

        reader_ = this->CreateReader<sensor_msgs::msg::Imu>(input_topic, std::bind(&IMUAdapterComponent::Proc, this, std::placeholders::_1));
        writer_ = this->CreateWriter<apollo::drivers::gnss::Imu>(output_topic);
        writer_c_ = this->CreateWriter<apollo::localization::CorrectedImu>(output_topic_c);

        return true;
      }

      void IMUAdapterComponent::Proc(const std::shared_ptr<sensor_msgs::msg::Imu> imu_msg)
      {
        apollo::drivers::gnss::Imu imu_apollo;

        imu_apollo.apolloheader.frameid = imu_msg->header.frame_id;
        imu_apollo.apolloheader.timestampsec = imu_msg->header.stamp.sec;

        imu_apollo.linearacceleration.set__x(imu_msg->linear_acceleration.x);
        imu_apollo.linearacceleration.set__y(imu_msg->linear_acceleration.y);
        imu_apollo.linearacceleration.set__z(imu_msg->linear_acceleration.z);

        imu_apollo.angularvelocity.set__x(imu_msg->angular_velocity.x);
        imu_apollo.angularvelocity.set__y(imu_msg->angular_velocity.y);
        imu_apollo.angularvelocity.set__z(imu_msg->angular_velocity.z);

        writer_->Write(imu_apollo);

        apollo::localization::CorrectedImu imu_apollo2;
        imu_apollo2.apolloheader.frameid = imu_msg->header.frame_id;
        imu_apollo2.apolloheader.timestampsec = imu_msg->header.stamp.sec;

        imu_apollo2.imu.angularvelocity.x = imu_msg->angular_velocity.x;
        imu_apollo2.imu.angularvelocity.y = imu_msg->angular_velocity.y;
        imu_apollo2.imu.angularvelocity.z = imu_msg->angular_velocity.z;

        imu_apollo2.imu.orientation.qw = imu_msg->orientation.w;
        imu_apollo2.imu.orientation.qz = imu_msg->orientation.x;
        imu_apollo2.imu.orientation.qy = imu_msg->orientation.y;
        imu_apollo2.imu.orientation.qz = imu_msg->orientation.z;

        imu_apollo2.imu.linearacceleration.x = imu_msg->linear_acceleration.x;
        imu_apollo2.imu.linearacceleration.y = imu_msg->linear_acceleration.y;
        imu_apollo2.imu.linearacceleration.z = imu_msg->linear_acceleration.z;

        double w, x, y, z, roll, pitch, yaw;
        x =  imu_msg->orientation.x;
        y =  imu_msg->orientation.y;
        z =  imu_msg->orientation.z;
        w =  imu_msg->orientation.w;

        // roll (x-axis rotation)
        double sinr_cosp = 2 * (w * x + y * z);
        double cosr_cosp = 1 - 2 * (x * x + y * y);
        roll = std::atan2(sinr_cosp, cosr_cosp);

        // pitch (y-axis rotation)
        double sinp = 2 * (w * y - z * x);
        if (std::abs(sinp) >= 1)
        pitch = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
        else
        pitch = std::asin(sinp);

        // yaw (z-axis rotation)
        double siny_cosp = 2 * (w * z + x * y);
        double cosy_cosp = 1 - 2 * (y * y + z * z);
        yaw = std::atan2(siny_cosp, cosy_cosp);

        imu_apollo2.imu.eulerangles.x = roll;
        imu_apollo2.imu.eulerangles.y = pitch;
        imu_apollo2.imu.eulerangles.z = yaw;

        writer_c_->Write(imu_apollo2);
      }
    } // namespace camera
  }   // namespace drivers
} // namespace apollo