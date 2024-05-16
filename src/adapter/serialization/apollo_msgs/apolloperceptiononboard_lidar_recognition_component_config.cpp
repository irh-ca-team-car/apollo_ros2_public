#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_lidar_recognition_component_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardLidarRecognitionComponentConfig &msg) {
        nlohmann::json obj;
        obj["mainsensorname"] = (msg.mainsensorname);
        obj["outputchannelname"] = (msg.outputchannelname);
        return obj;
    }
    ApolloperceptiononboardLidarRecognitionComponentConfig from_json_ApolloperceptiononboardLidarRecognitionComponentConfig (nlohmann::json obj) {
        ApolloperceptiononboardLidarRecognitionComponentConfig msg;
        if(obj.contains("mainsensorname"))
        {
            msg.mainsensorname = (obj["mainsensorname"].is_string()?(obj["mainsensorname"].get<std::string>().c_str()):obj["mainsensorname"].get<std::string>());
        }
        if(obj.contains("outputchannelname"))
        {
            msg.outputchannelname = (obj["outputchannelname"].is_string()?(obj["outputchannelname"].get<std::string>().c_str()):obj["outputchannelname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptiononboardLidarRecognitionComponentConfig from_json<ApolloperceptiononboardLidarRecognitionComponentConfig>(nlohmann::json obj){
        return from_json_ApolloperceptiononboardLidarRecognitionComponentConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardLidarRecognitionComponentConfig &dt)
    {
        dt=from_json_ApolloperceptiononboardLidarRecognitionComponentConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardLidarRecognitionComponentConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardLidarRecognitionComponentConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
