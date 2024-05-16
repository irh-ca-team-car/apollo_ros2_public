#include "adapter/serialization/apollo_msgs/apollodata_environment_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataEnvironmentInfo &msg) {
        nlohmann::json obj;
        obj["mapname"] = (msg.mapname);
        obj["temperature"] = (msg.temperature);
        return obj;
    }
    ApollodataEnvironmentInfo from_json_ApollodataEnvironmentInfo (nlohmann::json obj) {
        ApollodataEnvironmentInfo msg;
        if(obj.contains("mapname"))
        {
            msg.mapname = (obj["mapname"].is_string()?(obj["mapname"].get<std::string>().c_str()):obj["mapname"].get<std::string>());
        }
        if(obj.contains("temperature"))
        {
            msg.temperature = (obj["temperature"].is_string()?(float)atof(obj["temperature"].get<std::string>().c_str()):obj["temperature"].get<float>());
        }
        return msg;
    }
    template <>
    ApollodataEnvironmentInfo from_json<ApollodataEnvironmentInfo>(nlohmann::json obj){
        return from_json_ApollodataEnvironmentInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataEnvironmentInfo &dt)
    {
        dt=from_json_ApollodataEnvironmentInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataEnvironmentInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataEnvironmentInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
