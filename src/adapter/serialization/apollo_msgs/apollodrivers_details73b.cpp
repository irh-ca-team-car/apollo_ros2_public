#include "adapter/serialization/apollo_msgs/apollodrivers_details73b.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversDetails73b &msg) {
        nlohmann::json obj;
        obj["obstacleanglerate"] = (msg.obstacleanglerate);
        obj["obstaclescalechange"] = (msg.obstaclescalechange);
        obj["objectaccelx"] = (msg.objectaccelx);
        obj["reserved8"] = (msg.reserved8);
        obj["obstaclereplaced"] = (msg.obstaclereplaced);
        obj["reserved9"] = (msg.reserved9);
        obj["obstacleangle"] = (msg.obstacleangle);
        return obj;
    }
    ApollodriversDetails73b from_json_ApollodriversDetails73b (nlohmann::json obj) {
        ApollodriversDetails73b msg;
        if(obj.contains("obstacleanglerate"))
        {
            msg.obstacleanglerate = (obj["obstacleanglerate"].is_string()?atof(obj["obstacleanglerate"].get<std::string>().c_str()):obj["obstacleanglerate"].get<double>());
        }
        if(obj.contains("obstaclescalechange"))
        {
            msg.obstaclescalechange = (obj["obstaclescalechange"].is_string()?atof(obj["obstaclescalechange"].get<std::string>().c_str()):obj["obstaclescalechange"].get<double>());
        }
        if(obj.contains("objectaccelx"))
        {
            msg.objectaccelx = (obj["objectaccelx"].is_string()?atof(obj["objectaccelx"].get<std::string>().c_str()):obj["objectaccelx"].get<double>());
        }
        if(obj.contains("reserved8"))
        {
            msg.reserved8 = (obj["reserved8"].is_string()?atoi(obj["reserved8"].get<std::string>().c_str()):obj["reserved8"].get<int>());
        }
        if(obj.contains("obstaclereplaced"))
        {
            msg.obstaclereplaced = (obj["obstaclereplaced"].is_string()?(bool)atoi(obj["obstaclereplaced"].get<std::string>().c_str()):obj["obstaclereplaced"].get<bool>());
        }
        if(obj.contains("reserved9"))
        {
            msg.reserved9 = (obj["reserved9"].is_string()?atoi(obj["reserved9"].get<std::string>().c_str()):obj["reserved9"].get<int>());
        }
        if(obj.contains("obstacleangle"))
        {
            msg.obstacleangle = (obj["obstacleangle"].is_string()?atof(obj["obstacleangle"].get<std::string>().c_str()):obj["obstacleangle"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversDetails73b from_json<ApollodriversDetails73b>(nlohmann::json obj){
        return from_json_ApollodriversDetails73b(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversDetails73b &dt)
    {
        dt=from_json_ApollodriversDetails73b(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversDetails73b & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversDetails73b & dt)
    {
        os << to_json(dt);
        return os;
    }
}
