#include "adapter/serialization/apollo_msgs/apollothird_party_perception_radar_obstacles.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollothirdPartyPerceptionRadarObstacles &msg) {
        nlohmann::json obj;
        nlohmann::json arr_radarobstacle;
        for (auto it = msg.radarobstacle.begin(); it != msg.radarobstacle.end(); ++it) {
            arr_radarobstacle.push_back(to_json(*it));
        }
        obj["radarobstacle"] = arr_radarobstacle;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["errorcode"] = (msg.errorcode);
        return obj;
    }
    ApollothirdPartyPerceptionRadarObstacles from_json_ApollothirdPartyPerceptionRadarObstacles (nlohmann::json obj) {
        ApollothirdPartyPerceptionRadarObstacles msg;
        if(obj.contains("radarobstacle"))
        {
            if(obj["radarobstacle"].is_array())
            {
                for (auto& element : obj["radarobstacle"])
                {
                    msg.radarobstacle.push_back(from_json_ApollothirdPartyPerceptionRadarObstaclesradarObstacle(element));
                }
            }
            else
            {
                msg.radarobstacle.push_back(from_json_ApollothirdPartyPerceptionRadarObstaclesradarObstacle(obj["radarobstacle"]));
            }
        }
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("errorcode"))
        {
            msg.errorcode = (obj["errorcode"].is_string()?atoi(obj["errorcode"].get<std::string>().c_str()):obj["errorcode"].get<int>());
        }
        return msg;
    }
    template <>
    ApollothirdPartyPerceptionRadarObstacles from_json<ApollothirdPartyPerceptionRadarObstacles>(nlohmann::json obj){
        return from_json_ApollothirdPartyPerceptionRadarObstacles(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollothirdPartyPerceptionRadarObstacles &dt)
    {
        dt=from_json_ApollothirdPartyPerceptionRadarObstacles(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollothirdPartyPerceptionRadarObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollothirdPartyPerceptionRadarObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
}
