#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_scene_manager_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarSceneManagerConfig &msg) {
        nlohmann::json obj;
        nlohmann::json arr_servicename;
        for (auto it = msg.servicename.begin(); it != msg.servicename.end(); ++it) {
            arr_servicename.push_back((*it));
        }
        obj["servicename"] = arr_servicename;
        return obj;
    }
    ApolloperceptionlidarSceneManagerConfig from_json_ApolloperceptionlidarSceneManagerConfig (nlohmann::json obj) {
        ApolloperceptionlidarSceneManagerConfig msg;
        if(obj.contains("servicename"))
        {
            if(obj["servicename"].is_array())
            {
                for (auto& element : obj["servicename"])
                {
                    msg.servicename.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.servicename.push_back((obj["servicename"].is_string()?(obj["servicename"].get<std::string>().c_str()):obj["servicename"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarSceneManagerConfig from_json<ApolloperceptionlidarSceneManagerConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarSceneManagerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarSceneManagerConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarSceneManagerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarSceneManagerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarSceneManagerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
