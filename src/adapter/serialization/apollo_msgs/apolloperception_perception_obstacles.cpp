#include "adapter/serialization/apollo_msgs/apolloperception_perception_obstacles.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionPerceptionObstacles &msg) {
        nlohmann::json obj;
        nlohmann::json arr_perceptionobstacle;
        for (auto it = msg.perceptionobstacle.begin(); it != msg.perceptionobstacle.end(); ++it) {
            arr_perceptionobstacle.push_back(to_json(*it));
        }
        obj["perceptionobstacle"] = arr_perceptionobstacle;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["errorcode"] = (msg.errorcode);
        obj["lanemarker"] = to_json(msg.lanemarker);
        obj["cipvinfo"] = to_json(msg.cipvinfo);
        return obj;
    }
    ApolloperceptionPerceptionObstacles from_json_ApolloperceptionPerceptionObstacles (nlohmann::json obj) {
        ApolloperceptionPerceptionObstacles msg;
        if(obj.contains("perceptionobstacle"))
        {
            if(obj["perceptionobstacle"].is_array())
            {
                for (auto& element : obj["perceptionobstacle"])
                {
                    msg.perceptionobstacle.push_back(from_json_ApolloperceptionPerceptionObstacle(element));
                }
            }
            else
            {
                msg.perceptionobstacle.push_back(from_json_ApolloperceptionPerceptionObstacle(obj["perceptionobstacle"]));
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
        if(obj.contains("lanemarker"))
        {
            msg.lanemarker = from_json_ApolloperceptionLaneMarkers(obj["lanemarker"]);
        }
        if(obj.contains("cipvinfo"))
        {
            msg.cipvinfo = from_json_ApolloperceptionCIPVInfo(obj["cipvinfo"]);
        }
        return msg;
    }
    template <>
    ApolloperceptionPerceptionObstacles from_json<ApolloperceptionPerceptionObstacles>(nlohmann::json obj){
        return from_json_ApolloperceptionPerceptionObstacles(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionPerceptionObstacles &dt)
    {
        dt=from_json_ApolloperceptionPerceptionObstacles(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionPerceptionObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionPerceptionObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
}
