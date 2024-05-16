#include "adapter/serialization/apollo_msgs/apolloplanning_change_lane_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningChangeLaneStatus &msg) {
        nlohmann::json obj;
        obj["status"] = (msg.status);
        obj["pathid"] = (msg.pathid);
        obj["timestamp"] = (msg.timestamp);
        obj["existlanechangestartposition"] = (msg.existlanechangestartposition);
        obj["lanechangestartposition"] = to_json(msg.lanechangestartposition);
        obj["lastsucceedtimestamp"] = (msg.lastsucceedtimestamp);
        obj["iscurrentoptsucceed"] = (msg.iscurrentoptsucceed);
        obj["iscleartochangelane"] = (msg.iscleartochangelane);
        return obj;
    }
    ApolloplanningChangeLaneStatus from_json_ApolloplanningChangeLaneStatus (nlohmann::json obj) {
        ApolloplanningChangeLaneStatus msg;
        if(obj.contains("status"))
        {
            msg.status = (obj["status"].is_string()?atoi(obj["status"].get<std::string>().c_str()):obj["status"].get<int>());
        }
        if(obj.contains("pathid"))
        {
            msg.pathid = (obj["pathid"].is_string()?(obj["pathid"].get<std::string>().c_str()):obj["pathid"].get<std::string>());
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("existlanechangestartposition"))
        {
            msg.existlanechangestartposition = (obj["existlanechangestartposition"].is_string()?(bool)atoi(obj["existlanechangestartposition"].get<std::string>().c_str()):obj["existlanechangestartposition"].get<bool>());
        }
        if(obj.contains("lanechangestartposition"))
        {
            msg.lanechangestartposition = from_json_ApollocommonPoint3D(obj["lanechangestartposition"]);
        }
        if(obj.contains("lastsucceedtimestamp"))
        {
            msg.lastsucceedtimestamp = (obj["lastsucceedtimestamp"].is_string()?atof(obj["lastsucceedtimestamp"].get<std::string>().c_str()):obj["lastsucceedtimestamp"].get<double>());
        }
        if(obj.contains("iscurrentoptsucceed"))
        {
            msg.iscurrentoptsucceed = (obj["iscurrentoptsucceed"].is_string()?(bool)atoi(obj["iscurrentoptsucceed"].get<std::string>().c_str()):obj["iscurrentoptsucceed"].get<bool>());
        }
        if(obj.contains("iscleartochangelane"))
        {
            msg.iscleartochangelane = (obj["iscleartochangelane"].is_string()?(bool)atoi(obj["iscleartochangelane"].get<std::string>().c_str()):obj["iscleartochangelane"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningChangeLaneStatus from_json<ApolloplanningChangeLaneStatus>(nlohmann::json obj){
        return from_json_ApolloplanningChangeLaneStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningChangeLaneStatus &dt)
    {
        dt=from_json_ApolloplanningChangeLaneStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningChangeLaneStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningChangeLaneStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
