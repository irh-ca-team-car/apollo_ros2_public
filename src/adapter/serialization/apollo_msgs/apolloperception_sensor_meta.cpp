#include "adapter/serialization/apollo_msgs/apolloperception_sensor_meta.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionSensorMeta &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["type"] = (msg.type);
        obj["orientation"] = (msg.orientation);
        return obj;
    }
    ApolloperceptionSensorMeta from_json_ApolloperceptionSensorMeta (nlohmann::json obj) {
        ApolloperceptionSensorMeta msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("orientation"))
        {
            msg.orientation = (obj["orientation"].is_string()?atoi(obj["orientation"].get<std::string>().c_str()):obj["orientation"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptionSensorMeta from_json<ApolloperceptionSensorMeta>(nlohmann::json obj){
        return from_json_ApolloperceptionSensorMeta(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionSensorMeta &dt)
    {
        dt=from_json_ApolloperceptionSensorMeta(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionSensorMeta & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionSensorMeta & dt)
    {
        os << to_json(dt);
        return os;
    }
}
