#include "adapter/serialization/apollo_msgs/apolloprediction_stop_sign.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionStopSign &msg) {
        nlohmann::json obj;
        obj["stopsignid"] = (msg.stopsignid);
        obj["laneid"] = (msg.laneid);
        obj["lanes"] = (msg.lanes);
        obj["lanesequences"] = (msg.lanesequences);
        return obj;
    }
    ApollopredictionStopSign from_json_ApollopredictionStopSign (nlohmann::json obj) {
        ApollopredictionStopSign msg;
        if(obj.contains("stopsignid"))
        {
            msg.stopsignid = (obj["stopsignid"].is_string()?(obj["stopsignid"].get<std::string>().c_str()):obj["stopsignid"].get<std::string>());
        }
        if(obj.contains("laneid"))
        {
            msg.laneid = (obj["laneid"].is_string()?(obj["laneid"].get<std::string>().c_str()):obj["laneid"].get<std::string>());
        }
        if(obj.contains("lanes"))
        {
            msg.lanes = (obj["lanes"].is_string()?atof(obj["lanes"].get<std::string>().c_str()):obj["lanes"].get<double>());
        }
        if(obj.contains("lanesequences"))
        {
            msg.lanesequences = (obj["lanesequences"].is_string()?atof(obj["lanesequences"].get<std::string>().c_str()):obj["lanesequences"].get<double>());
        }
        return msg;
    }
    template <>
    ApollopredictionStopSign from_json<ApollopredictionStopSign>(nlohmann::json obj){
        return from_json_ApollopredictionStopSign(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionStopSign &dt)
    {
        dt=from_json_ApollopredictionStopSign(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionStopSign & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionStopSign & dt)
    {
        os << to_json(dt);
        return os;
    }
}
