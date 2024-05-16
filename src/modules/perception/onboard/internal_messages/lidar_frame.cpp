#include "modules/perception/onboard/internal_messages/point.h"
#include "modules/perception/onboard/internal_messages/point_cloud.h"
#include "modules/perception/onboard/internal_messages/sensor_meta.h"
#include "modules/perception/onboard/internal_messages/hdmap_struct.h"
#include "modules/perception/onboard/internal_messages/object.h"
#include "modules/perception/onboard/internal_messages/lidar_frame.h"
#include "modules/perception/base/base64.h"
namespace apollo_msgs::msg
{
    using apollo::perception::lidar::LidarFrame;

    nlohmann::json to_json_cloud(const LidarFrame &msg)
    {
        nlohmann::json j;
        nlohmann::json Arr;
        unsigned char *ptr;

        ptr = (unsigned char *)&msg.cloud->points_timestamp_[0];
        j["points_timestamp_"] = base64_encode(ptr, sizeof(double) * msg.cloud->points_timestamp_.size());

        ptr = (unsigned char *)&msg.cloud->points_height_[0];
        j["points_height_"] = base64_encode(ptr, sizeof(float) * msg.cloud->points_height_.size());

        ptr = (unsigned char *)&msg.cloud->points_beam_id_[0];
        j["points_beam_id_"] = base64_encode(ptr, sizeof(int32_t) * msg.cloud->points_beam_id_.size());

        ptr = (unsigned char *)&msg.cloud->points_label_[0];
        j["points_label_"] = base64_encode(ptr, sizeof(uint8_t) * msg.cloud->points_label_.size());

        ptr = (unsigned char *)&msg.cloud->points_[0];
        j["points_"] = base64_encode(ptr, sizeof(PointF) * msg.cloud->points_.size());

        nlohmann::json arr_sensor_to_world_pose_;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                arr_sensor_to_world_pose_.push_back(msg.cloud->sensor_to_world_pose_(i, j));
            }
        }
        j["sensor_to_world_pose_"] = arr_sensor_to_world_pose_;

        j["timestamp"] = msg.cloud->timestamp_;
        j["width_"] = (int)msg.cloud->width_;
        j["height_"] = (int)msg.cloud->height_;

        return j;
    }

    nlohmann::json to_json_world_cloud(const LidarFrame &msg)
    {
        nlohmann::json j;
        unsigned char *ptr;
        ptr = (unsigned char *)&msg.world_cloud->points_timestamp_[0];
        j["points_timestamp_"] = base64_encode(ptr, sizeof(double) * msg.world_cloud->points_timestamp_.size());

        ptr = (unsigned char *)&msg.world_cloud->points_height_[0];
        j["points_height_"] = base64_encode(ptr, sizeof(float) * msg.world_cloud->points_height_.size());

        ptr = (unsigned char *)&msg.world_cloud->points_beam_id_[0];
        j["points_beam_id_"] = base64_encode(ptr, sizeof(int32_t) * msg.world_cloud->points_beam_id_.size());

        ptr = (unsigned char *)&msg.world_cloud->points_label_[0];
        j["points_label_"] = base64_encode(ptr, sizeof(uint8_t) * msg.world_cloud->points_label_.size());

        ptr = (unsigned char *)&msg.world_cloud->points_[0];
        j["points_"] = base64_encode(ptr, sizeof(PointD) * msg.world_cloud->points_.size());

        nlohmann::json arr_sensor_to_world_pose_;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                arr_sensor_to_world_pose_.push_back(msg.world_cloud->sensor_to_world_pose_(i, j));
            }
        }
        j["sensor_to_world_pose_"] = arr_sensor_to_world_pose_;

        j["timestamp"] = msg.world_cloud->timestamp_;
        j["width_"] = (int)msg.world_cloud->width_;
        j["height_"] = (int)msg.world_cloud->height_;

        return j;
    }

    nlohmann::json to_json(const LidarFrame &msg)
    {
        nlohmann::json j;
        if (msg.cloud != nullptr)
            j["cloud"] = to_json_cloud(msg);
        else
            j["cloud"] = nullptr;
        if (msg.world_cloud != nullptr)
            j["world_cloud"] = to_json_world_cloud(msg);
        else
            j["world_cloud"] = nullptr;
        j["timestamp"] = msg.timestamp;
        nlohmann::json arr_lidar2world_pose;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                arr_lidar2world_pose.push_back(msg.lidar2world_pose(i, j));
            }
        }
        j["lidar2world_pose"] = arr_lidar2world_pose;
        nlohmann::json arr_novatel2world_pose;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                arr_novatel2world_pose.push_back(msg.novatel2world_pose(i, j));
            }
        }
        j["novatel2world_pose"] = arr_novatel2world_pose;
        if (msg.hdmap_struct != nullptr)
            j["hdmap_struct"] = to_json(*msg.hdmap_struct);
        else
            j["hdmap_struct"] = nullptr;
        nlohmann::json arr_segmented_objects;
        for (auto it = msg.segmented_objects.begin(); it != msg.segmented_objects.end(); ++it)
        {
            if (*it != nullptr)
                arr_segmented_objects.push_back(to_json(**it));
            else
                arr_segmented_objects.push_back(nullptr);
        }
        j["segmented_objects"] = arr_segmented_objects;
        nlohmann::json arr_tracked_objects;
        for (auto it = msg.tracked_objects.begin(); it != msg.tracked_objects.end(); ++it)
        {
            if (*it != nullptr)
                arr_tracked_objects.push_back(to_json(**it));
            else
                arr_tracked_objects.push_back(nullptr);
        }
        j["tracked_objects"] = arr_tracked_objects;
        j["roi_indices"] = to_json(msg.roi_indices);
        j["non_ground_indices"] = to_json(msg.non_ground_indices);
        j["secondary_indices"] = to_json(msg.secondary_indices);
        j["sensor_info"] = to_json(msg.sensor_info);
        j["reserve"] = msg.reserve;
        return j;
    }
    template <typename PointT>
    void from_json_point_cloud(std::shared_ptr<apollo::perception::base::AttributePointCloud<PointT>> d, nlohmann::json obj)
    {

        /* ptr = (unsigned char *)&msg.cloud->points_timestamp_[0];
        j["points_timestamp_"] = base64_encode(ptr, sizeof(double) * msg.cloud->points_timestamp_.size());

        ptr = (unsigned char *)&msg.cloud->points_height_[0];
        j["points_height_"] = base64_encode(ptr, sizeof(float) * msg.cloud->points_height_.size());

        ptr = (unsigned char *)&msg.cloud->points_beam_id_[0];
        j["points_beam_id_"] = base64_encode(ptr, sizeof(int32_t) * msg.cloud->points_beam_id_.size());

        ptr = (unsigned char *)&msg.cloud->points_label_[0];
        j["points_label_"] = base64_encode(ptr, sizeof(uint8_t) * msg.cloud->points_label_.size());

        ptr = (unsigned char *)&msg.cloud->points_[0];
        j["points_"] = base64_encode(ptr, sizeof(PointF) * msg.cloud->points_.size());*/

        if (obj.contains("points_timestamp_"))
        {
            std::vector<unsigned char> v = base64_decode(obj["points_timestamp_"].get<std::string>());
            d->points_timestamp_ = std::vector<double>((double *)&v[0], (double *)(&v[0] + v.size()));
        }

        if (obj.contains("points_height_"))
        {
            std::vector<unsigned char> v = base64_decode(obj["points_height_"].get<std::string>());
            d->points_height_ = std::vector<float>((float *)&v[0], (float *)(&v[0] + v.size()));
        }

        if (obj.contains("points_beam_id_"))
        {
            std::vector<unsigned char> v = base64_decode(obj["points_beam_id_"].get<std::string>());
            d->points_beam_id_ = std::vector<int32_t>((int32_t *)&v[0], (int32_t *)(&v[0] + v.size()));
        }
        if (obj.contains("points_label_"))
        {
            d->points_label_ = base64_decode(obj["points_label_"].get<std::string>());
        }
        if (obj.contains("points_"))
        {
            std::vector<unsigned char> v = base64_decode(obj["points_"].get<std::string>());
            d->points_ = std::vector<PointT>((PointT *)&v[0], (PointT *)(&v[0] + v.size()));
        }
        if (obj.contains("width_"))
            d->width_ = (obj["width_"].is_string() ? (size_t)atoi(obj["width_"].get<std::string>().c_str()) : obj["width_"].get<size_t>());
        if (obj.contains("height_"))
            d->height_ = (obj["height_"].is_string() ? (size_t)atoi(obj["height_"].get<std::string>().c_str()) : obj["height_"].get<size_t>());
        if (obj.contains("timestamp_"))
            d->timestamp_ = (obj["timestamp_"].is_string() ? atof(obj["timestamp_"].get<std::string>().c_str()) : obj["timestamp_"].get<double>());
        if (obj.contains("sensor_to_world_pose_"))
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    d->sensor_to_world_pose_(i, j) = (obj["sensor_to_world_pose_"][i * 4 + j].is_string() ? atof(obj["sensor_to_world_pose_"][i * 4 + j].get<std::string>().c_str()) : obj["sensor_to_world_pose_"][i * 4 + j].get<double>());
                }
            }
    }
    LidarFrame from_json_LidarFrame(nlohmann::json obj)
    {
        LidarFrame d;

        if (d.cloud == nullptr)
        {
            d.cloud = apollo::perception::base::PointFCloudPool::Instance().Get();
        }
        if (d.world_cloud == nullptr)
        {
            d.world_cloud = apollo::perception::base::PointDCloudPool::Instance().Get();
        }

        if (obj.contains("cloud"))
        {
            // frame->cloud = base::PointFCloudPool::Instance().Get();
            if (obj["cloud"].is_null())
                d.cloud = nullptr;
            else
                from_json_point_cloud<PointF>(d.cloud, obj["cloud"]);
        }
        if (obj.contains("world_cloud"))
        {
            // frame->world_cloud = base::PointDCloudPool::Instance().Get();

            if (obj["world_cloud"].is_null())
                d.world_cloud = nullptr;
            else
                from_json_point_cloud<PointD>(d.world_cloud, obj["world_cloud"]);
        }
        if (obj.contains("timestamp"))
            d.timestamp = (obj["timestamp"].is_string() ? atof(obj["timestamp"].get<std::string>().c_str()) : obj["timestamp"].get<double>());
        if (obj.contains("lidar2world_pose"))
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    d.lidar2world_pose(i, j) = (obj["lidar2world_pose"][i * 4 + j].is_string() ? atof(obj["lidar2world_pose"][i * 4 + j].get<std::string>().c_str()) : obj["lidar2world_pose"][i * 4 + j].get<double>());
                }
            }
        if (obj.contains("novatel2world_pose"))
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    d.novatel2world_pose(i, j) = (obj["novatel2world_pose"][i * 4 + j].is_string() ? atof(obj["novatel2world_pose"][i * 4 + j].get<std::string>().c_str()) : obj["novatel2world_pose"][i * 4 + j].get<double>());
                }
            }
        if (obj.contains("hdmap_struct"))
        {
            if (obj["hdmap_struct"].is_null())
                d.hdmap_struct = nullptr;
            else
                d.hdmap_struct = std::make_shared<HdmapStruct>(from_json_HdmapStruct(obj["hdmap_struct"]));
        }
        if (obj.contains("segmented_objects"))
            for (auto element : obj["segmented_objects"])
            {
                if (element.is_null())
                    d.segmented_objects.push_back(nullptr);
                else
                {
                    std::shared_ptr<Object> inter;
                    *inter = from_json_Object(element);
                    d.segmented_objects.push_back(inter);
                }
            }
        if (obj.contains("tracked_objects"))
            for (auto element : obj["tracked_objects"])
            {
                if (element.is_null())
                    d.tracked_objects.push_back(nullptr);
                else
                {
                    std::shared_ptr<Object> inter;
                    *inter = from_json_Object(element);
                    d.tracked_objects.push_back(inter);
                }
            }
        if (obj.contains("roi_indices"))
            d.roi_indices = from_json_PointIndices(obj["roi_indices"]);
        if (obj.contains("non_ground_indices"))
            d.non_ground_indices = from_json_PointIndices(obj["non_ground_indices"]);
        if (obj.contains("secondary_indices"))
            d.secondary_indices = from_json_PointIndices(obj["secondary_indices"]);
        if (obj.contains("sensor_info"))
            d.sensor_info = from_json_SensorInfo(obj["sensor_info"]);
        if (obj.contains("reserve"))
            d.reserve = obj["reserve"].get<std::string>();

        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, LidarFrame &dt)
    {
        dt = from_json_LidarFrame(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const LidarFrame &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LidarFrame &dt)
    {
        return os << to_json(dt).dump();
    }
}
