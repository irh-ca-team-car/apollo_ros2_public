#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_novatel_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigNovatelConfig &msg) {
        nlohmann::json obj;
        obj["imuorientation"] = (msg.imuorientation);
        return obj;
    }
    ApollodriversgnssconfigNovatelConfig from_json_ApollodriversgnssconfigNovatelConfig (nlohmann::json obj) {
        ApollodriversgnssconfigNovatelConfig msg;
        if(obj.contains("imuorientation"))
        {
            msg.imuorientation = (obj["imuorientation"].is_string()?atoi(obj["imuorientation"].get<std::string>().c_str()):obj["imuorientation"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssconfigNovatelConfig from_json<ApollodriversgnssconfigNovatelConfig>(nlohmann::json obj){
        return from_json_ApollodriversgnssconfigNovatelConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigNovatelConfig &dt)
    {
        dt=from_json_ApollodriversgnssconfigNovatelConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigNovatelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigNovatelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
