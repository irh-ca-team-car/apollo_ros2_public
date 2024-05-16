#include "component/pointcloud_adapter.h"

#include <exception>
#include <vector>

namespace apollo
{
  namespace drivers
  {
    namespace adapter
    {

      bool PointCloudAdapterComponent::Init()
      {
        auto input_topic = declare_parameter<std::string>("input_topic", "/apollo/sensor/camera/ros");
        auto output_topic = declare_parameter<std::string>("output_topic", "/apollo/sensor/camera/apollo");

        reader_ = this->CreateReader<sensor_msgs::msg::PointCloud2>(input_topic, std::bind(&PointCloudAdapterComponent::Proc, this, std::placeholders::_1));
        writer_ = this->CreateWriter<apollo::drivers::PointCloud>(output_topic);

        return true;
      }

      void PointCloudAdapterComponent::Proc(const std::shared_ptr<sensor_msgs::msg::PointCloud2> msg)
      {
        if(msg->header.stamp.sec < this->get_clock()->now().seconds() - 1800) return;
        apollo::drivers::PointCloud pc;
        pc.frameid = msg->header.frame_id;
        pc.apolloheader.frameid = msg->header.frame_id;
        pc.apolloheader.timestampsec = msg->header.stamp.sec;
        pc.height = msg->height;
        pc.isdense = msg->is_dense;
        pc.measurementtime = msg->header.stamp.nanosec;
        pc.width = msg->width;

        int x_offset = -1;
        int y_offset = -1;
        int z_offset = -1;
        int stamp_offset = -1;
        int intensity_offset = -1;
        for (const auto &field : msg->fields)
        {
          if (field.name == "x")
          {
            x_offset = field.offset;
          }
          else if (field.name == "y")
          {
            y_offset = field.offset;
          }
          else if (field.name == "z")
          {
            z_offset = field.offset;
          }
          else if (field.name == "ring")
          {
            stamp_offset = field.offset;
          }
          else if (field.name == "intensity")
          {
            intensity_offset = field.offset;
          }
        }
        if (x_offset == -1 || y_offset == -1 || z_offset == -1 || intensity_offset == -1)
        {
          std::cerr << "Field not contains x, y, z, timestamp, instensity"
                    << std::endl;
          return;
        }

        int total = msg->width * msg->height;
        // get data
        auto data = msg->data;

        for (int i = 0; i < total; ++i)
        {
          auto cyber_point = pc.point.emplace_back();
          int offset = i * msg->point_step;
          cyber_point.set__x(*reinterpret_cast<float *>(&data[offset + x_offset]));
          cyber_point.set__y(*reinterpret_cast<float *>(&data[offset + y_offset]));
          cyber_point.set__z(*reinterpret_cast<float *>(&data[offset + z_offset]));
          cyber_point.set__intensity(
              *reinterpret_cast<uint8_t *>(&data[offset + intensity_offset]));
          if (stamp_offset > -1)
            cyber_point.set__timestamp(static_cast<std::uint64_t>(
                *reinterpret_cast<double *>(&data[offset + stamp_offset]) * 1e9));
        }

        writer_->Write(pc);
      }
    } // namespace camera
  }   // namespace drivers
} // namespace apollo