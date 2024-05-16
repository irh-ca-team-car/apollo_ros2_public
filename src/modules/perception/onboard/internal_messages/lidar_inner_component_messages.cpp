#include "modules/perception/onboard/internal_messages/lidar_frame.h"
#include "modules/perception/onboard/internal_messages/lidar_inner_component_messages.h"

namespace apollo_msgs::msg
{
    using apollo::perception::onboard::LidarFrameMessage;
    nlohmann::json to_json(const LidarFrameMessage &msg)
    {
        nlohmann::json j;

        j["timestamp_"] = msg.timestamp_;
        j["lidar_timestamp_"] = msg.lidar_timestamp_;
        j["seq_num_"] = msg.seq_num_;
        j["type_name_"] = msg.type_name_;
        j["process_stage_"] = msg.process_stage_;
        j["error_code_"] = msg.error_code_;
        if (msg.lidar_frame_ != nullptr)
            j["lidar_frame_"] = to_json(*msg.lidar_frame_);
        else
            j["lidar_frame_"] = nullptr;
        return j;
    }
    LidarFrameMessage from_json_LidarFrameMessage(nlohmann::json obj)
    {
        LidarFrameMessage d;

        if (obj.contains("timestamp_"))
            d.timestamp_ = (obj["timestamp_"].is_string() ? atof(obj["timestamp_"].get<std::string>().c_str()) : obj["timestamp_"].get<double>());
        if (obj.contains("lidar_timestamp_"))
            d.lidar_timestamp_ = (obj["lidar_timestamp_"].is_string() ? (uint64_t)atoi(obj["lidar_timestamp_"].get<std::string>().c_str()) : obj["lidar_timestamp_"].get<uint64_t>());
        if (obj.contains("seq_num_"))
            d.seq_num_ = (obj["seq_num_"].is_string() ? (uint32_t)atoi(obj["seq_num_"].get<std::string>().c_str()) : obj["seq_num_"].get<uint32_t>());
        if (obj.contains("type_name_"))
            d.type_name_ = obj["type_name_"].get<std::string>();
        if (obj.contains("process_stage_"))
            d.process_stage_ = static_cast<apollo::perception::onboard::ProcessStage>(obj["process_stage_"].is_string() ? atoi(obj["process_stage_"].get<std::string>().c_str()) : obj["process_stage_"].get<int>());
        if (obj.contains("error_code_"))
            d.error_code_ = static_cast<apollo::common::ErrorCode>(obj["error_code_"].is_string() ? atoi(obj["error_code_"].get<std::string>().c_str()) : obj["error_code_"].get<int>());
        if (obj.contains("lidar_frame_"))
        {
            if (obj["lidar_frame_"].is_null())
                d.lidar_frame_ = nullptr;
            else
                d.lidar_frame_ = std::make_shared<LidarFrame>(from_json_LidarFrame(obj["lidar_frame_"]));
        }

        return d;
    }
    template <>
    LidarFrameMessage from_json<LidarFrameMessage>(nlohmann::json obj)
    {
        return from_json_LidarFrameMessage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, LidarFrameMessage &dt)
    {
        dt = from_json_LidarFrameMessage(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const LidarFrameMessage &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LidarFrameMessage &dt)
    {
        return os << to_json(dt).dump();
    }
}
