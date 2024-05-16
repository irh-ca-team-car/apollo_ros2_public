#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_mlf_tracker_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfTrackerConfig &msg) {
        nlohmann::json obj;
        nlohmann::json arr_filtername;
        for (auto it = msg.filtername.begin(); it != msg.filtername.end(); ++it) {
            arr_filtername.push_back((*it));
        }
        obj["filtername"] = arr_filtername;
        return obj;
    }
    ApolloperceptionlidarMlfTrackerConfig from_json_ApolloperceptionlidarMlfTrackerConfig (nlohmann::json obj) {
        ApolloperceptionlidarMlfTrackerConfig msg;
        if(obj.contains("filtername"))
        {
            if(obj["filtername"].is_array())
            {
                for (auto& element : obj["filtername"])
                {
                    msg.filtername.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.filtername.push_back((obj["filtername"].is_string()?(obj["filtername"].get<std::string>().c_str()):obj["filtername"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarMlfTrackerConfig from_json<ApolloperceptionlidarMlfTrackerConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarMlfTrackerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfTrackerConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarMlfTrackerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfTrackerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfTrackerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
