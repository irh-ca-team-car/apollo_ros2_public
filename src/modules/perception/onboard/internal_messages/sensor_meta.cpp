#include "modules/perception/onboard/internal_messages/sensor_meta.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::SensorInfo;
    nlohmann::json to_json(const SensorInfo &msg)
    {
        nlohmann::json j;

        j["name"] = msg.name;
        j["type"] = msg.type;
        j["orientation"] = msg.orientation;
        j["frame_id"] = msg.frame_id;

        return j;
    }
    SensorInfo from_json_SensorInfo(nlohmann::json obj)
    {
        SensorInfo d;
        
        if (obj.contains("name"))
            d.name = obj["name"].get<std::string>();
        if (obj.contains("type"))
            d.type = static_cast<apollo::perception::base::SensorType>(obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        if (obj.contains("orientation"))
            d.orientation = static_cast<apollo::perception::base::SensorOrientation>(obj["orientation"].is_string()?atoi(obj["orientation"].get<std::string>().c_str()):obj["orientation"].get<int>());
        if (obj.contains("frame_id"))
            d.frame_id = obj["frame_id"].get<std::string>();
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, SensorInfo &dt)
    {
        dt = from_json_SensorInfo(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const SensorInfo &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const SensorInfo &dt)
    {
        return os << to_json(dt).dump();
    }
}
