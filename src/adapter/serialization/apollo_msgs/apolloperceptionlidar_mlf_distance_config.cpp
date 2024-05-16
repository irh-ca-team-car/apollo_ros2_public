#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_mlf_distance_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfDistanceConfig &msg) {
        nlohmann::json obj;
        nlohmann::json arr_foregroundweights;
        for (auto it = msg.foregroundweights.begin(); it != msg.foregroundweights.end(); ++it) {
            arr_foregroundweights.push_back(to_json(*it));
        }
        obj["foregroundweights"] = arr_foregroundweights;
        nlohmann::json arr_backgroundweights;
        for (auto it = msg.backgroundweights.begin(); it != msg.backgroundweights.end(); ++it) {
            arr_backgroundweights.push_back(to_json(*it));
        }
        obj["backgroundweights"] = arr_backgroundweights;
        return obj;
    }
    ApolloperceptionlidarMlfDistanceConfig from_json_ApolloperceptionlidarMlfDistanceConfig (nlohmann::json obj) {
        ApolloperceptionlidarMlfDistanceConfig msg;
        if(obj.contains("foregroundweights"))
        {
            if(obj["foregroundweights"].is_array())
            {
                for (auto& element : obj["foregroundweights"])
                {
                    msg.foregroundweights.push_back(from_json_ApolloperceptionlidarMlfDistanceWeight(element));
                }
            }
            else
            {
                msg.foregroundweights.push_back(from_json_ApolloperceptionlidarMlfDistanceWeight(obj["foregroundweights"]));
            }
        }
        if(obj.contains("backgroundweights"))
        {
            if(obj["backgroundweights"].is_array())
            {
                for (auto& element : obj["backgroundweights"])
                {
                    msg.backgroundweights.push_back(from_json_ApolloperceptionlidarMlfDistanceWeight(element));
                }
            }
            else
            {
                msg.backgroundweights.push_back(from_json_ApolloperceptionlidarMlfDistanceWeight(obj["backgroundweights"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarMlfDistanceConfig from_json<ApolloperceptionlidarMlfDistanceConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarMlfDistanceConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfDistanceConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarMlfDistanceConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfDistanceConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfDistanceConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
