#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_spp_engine_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarSppEngineConfig &msg) {
        nlohmann::json obj;
        obj["heightgap"] = (msg.heightgap);
        return obj;
    }
    ApolloperceptionlidarSppEngineConfig from_json_ApolloperceptionlidarSppEngineConfig (nlohmann::json obj) {
        ApolloperceptionlidarSppEngineConfig msg;
        if(obj.contains("heightgap"))
        {
            msg.heightgap = (obj["heightgap"].is_string()?(float)atof(obj["heightgap"].get<std::string>().c_str()):obj["heightgap"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarSppEngineConfig from_json<ApolloperceptionlidarSppEngineConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarSppEngineConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarSppEngineConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarSppEngineConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarSppEngineConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarSppEngineConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
