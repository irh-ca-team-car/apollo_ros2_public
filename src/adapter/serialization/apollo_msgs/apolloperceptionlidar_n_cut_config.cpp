#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_n_cut_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarNCutConfig &msg) {
        nlohmann::json obj;
        obj["paramfile"] = (msg.paramfile);
        return obj;
    }
    ApolloperceptionlidarNCutConfig from_json_ApolloperceptionlidarNCutConfig (nlohmann::json obj) {
        ApolloperceptionlidarNCutConfig msg;
        if(obj.contains("paramfile"))
        {
            msg.paramfile = (obj["paramfile"].is_string()?(obj["paramfile"].get<std::string>().c_str()):obj["paramfile"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarNCutConfig from_json<ApolloperceptionlidarNCutConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarNCutConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarNCutConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarNCutConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarNCutConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarNCutConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
