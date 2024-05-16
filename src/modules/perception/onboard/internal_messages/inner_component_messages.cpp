#include "modules/perception/onboard/internal_messages/frame.h"
#include "modules/perception/onboard/internal_messages/hdmap_struct.h"
#include "modules/perception/onboard/internal_messages/inner_component_messages.h"
#include "modules/perception/base/object_pool_types.h"
namespace apollo_msgs::msg
{
    using apollo::perception::onboard::SensorFrameMessage;
    nlohmann::json to_json(const SensorFrameMessage &msg)
    {
        nlohmann::json j;

        j["error_code_"] = msg.error_code_;
        j["sensor_id_"] = msg.sensor_id_;
        j["timestamp_"] = msg.timestamp_;
        j["lidar_timestamp_"] = msg.lidar_timestamp_;
        j["seq_num_"] = msg.seq_num_;
        j["type_name_"] = msg.type_name_;
        if (msg.hdmap_ != nullptr)
            j["hdmap_"] = to_json(*msg.hdmap_);
        else
            j["hdmap_"] = nullptr;
        if (msg.frame_ != nullptr)
            j["frame_"] = to_json(*msg.frame_);
        else
            j["frame_"] = nullptr;
        j["process_stage_"] = msg.process_stage_;

        return j;
    }
    SensorFrameMessage from_json_SensorFrameMessage(nlohmann::json obj)
    {
        SensorFrameMessage d;

        if (obj.contains("error_code_"))
            d.error_code_ = static_cast<apollo::common::ErrorCode>(obj["error_code_"].is_string() ? atoi(obj["error_code_"].get<std::string>().c_str()) : obj["error_code_"].get<int>());
        if (obj.contains("sensor_id_"))
            d.sensor_id_ = obj["sensor_id_"].get<std::string>();
        if (obj.contains("timestamp_"))
            d.timestamp_ = (obj["timestamp_"].is_string() ? atof(obj["timestamp_"].get<std::string>().c_str()) : obj["timestamp_"].get<double>());
        if (obj.contains("lidar_timestamp_"))
            d.lidar_timestamp_ = (obj["lidar_timestamp_"].is_string() ? (uint64_t)atoi(obj["lidar_timestamp_"].get<std::string>().c_str()) : obj["lidar_timestamp_"].get<uint64_t>());
        if (obj.contains("seq_num_"))
            d.seq_num_ = (obj["seq_num_"].is_string() ? (uint32_t)atoi(obj["seq_num_"].get<std::string>().c_str()) : obj["seq_num_"].get<uint32_t>());
        if (obj.contains("type_name_"))
            d.type_name_ = obj["type_name_"].get<std::string>();
        if (obj.contains("hdmap_"))
        {
            if (obj["hdmap_"].is_null())
                d.hdmap_ = nullptr;
            else
            {
                AFATAL << "Not supported yet";
                //HDMapUtil::BaseMapPtr();
                //*d.hdmap_ = from_json_HdmapStruct(obj["hdmap_"]);
            }
        }
        if (obj.contains("frame_"))
        {
            if (obj["frame_"].is_null())
                d.frame_ = nullptr;
            else
            {
                d.frame_=apollo::perception::base::FramePool::Instance().Get();
                *d.frame_ = from_json_Frame(obj["frame_"]);
            }
        }
        if (obj.contains("process_stage_"))
            d.process_stage_ = static_cast<apollo::perception::onboard::ProcessStage>(obj["process_stage_"].is_string() ? atoi(obj["process_stage_"].get<std::string>().c_str()) : obj["process_stage_"].get<int>());

        return d;
    }
    template <>
    SensorFrameMessage from_json<SensorFrameMessage>(nlohmann::json obj)
    {
        return from_json_SensorFrameMessage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, SensorFrameMessage &dt)
    {
        dt = from_json_SensorFrameMessage(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const SensorFrameMessage &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const SensorFrameMessage &dt)
    {
        return os << to_json(dt).dump();
    }
}
