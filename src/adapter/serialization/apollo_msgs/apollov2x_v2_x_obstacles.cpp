#include "adapter/serialization/apollo_msgs/apollov2x_v2_x_obstacles.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xV2XObstacles &msg) {
        nlohmann::json obj;
        nlohmann::json arr_v2xobstacle;
        for (auto it = msg.v2xobstacle.begin(); it != msg.v2xobstacle.end(); ++it) {
            arr_v2xobstacle.push_back(to_json(*it));
        }
        obj["v2xobstacle"] = arr_v2xobstacle;
        obj["areamap"] = to_json(msg.areamap);
        obj["trafficflow"] = (msg.trafficflow);
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["errorcode"] = (msg.errorcode);
        return obj;
    }
    Apollov2xV2XObstacles from_json_Apollov2xV2XObstacles (nlohmann::json obj) {
        Apollov2xV2XObstacles msg;
        if(obj.contains("v2xobstacle"))
        {
            if(obj["v2xobstacle"].is_array())
            {
                for (auto& element : obj["v2xobstacle"])
                {
                    msg.v2xobstacle.push_back(from_json_Apollov2xV2XObstacle(element));
                }
            }
            else
            {
                msg.v2xobstacle.push_back(from_json_Apollov2xV2XObstacle(obj["v2xobstacle"]));
            }
        }
        if(obj.contains("areamap"))
        {
            msg.areamap = from_json_Apollov2xMiniAreaMap(obj["areamap"]);
        }
        if(obj.contains("trafficflow"))
        {
            msg.trafficflow = (obj["trafficflow"].is_string()?atof(obj["trafficflow"].get<std::string>().c_str()):obj["trafficflow"].get<double>());
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
    Apollov2xV2XObstacles from_json<Apollov2xV2XObstacles>(nlohmann::json obj){
        return from_json_Apollov2xV2XObstacles(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xV2XObstacles &dt)
    {
        dt=from_json_Apollov2xV2XObstacles(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xV2XObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xV2XObstacles & dt)
    {
        os << to_json(dt);
        return os;
    }
}
