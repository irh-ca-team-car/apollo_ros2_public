#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_roadway.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLdwRoadway &msg) {
        nlohmann::json obj;
        obj["width0"] = (msg.width0);
        obj["width1"] = (msg.width1);
        obj["width2"] = (msg.width2);
        obj["istracking"] = (msg.istracking);
        obj["leftlane"] = to_json(msg.leftlane);
        obj["rightlane"] = to_json(msg.rightlane);
        obj["adjleftlane"] = to_json(msg.adjleftlane);
        obj["adjrightlane"] = to_json(msg.adjrightlane);
        return obj;
    }
    ApollodriversLdwRoadway from_json_ApollodriversLdwRoadway (nlohmann::json obj) {
        ApollodriversLdwRoadway msg;
        if(obj.contains("width0"))
        {
            msg.width0 = (obj["width0"].is_string()?atoi(obj["width0"].get<std::string>().c_str()):obj["width0"].get<int>());
        }
        if(obj.contains("width1"))
        {
            msg.width1 = (obj["width1"].is_string()?atoi(obj["width1"].get<std::string>().c_str()):obj["width1"].get<int>());
        }
        if(obj.contains("width2"))
        {
            msg.width2 = (obj["width2"].is_string()?atoi(obj["width2"].get<std::string>().c_str()):obj["width2"].get<int>());
        }
        if(obj.contains("istracking"))
        {
            msg.istracking = (obj["istracking"].is_string()?(bool)atoi(obj["istracking"].get<std::string>().c_str()):obj["istracking"].get<bool>());
        }
        if(obj.contains("leftlane"))
        {
            msg.leftlane = from_json_ApollodriversLdwLane(obj["leftlane"]);
        }
        if(obj.contains("rightlane"))
        {
            msg.rightlane = from_json_ApollodriversLdwLane(obj["rightlane"]);
        }
        if(obj.contains("adjleftlane"))
        {
            msg.adjleftlane = from_json_ApollodriversLdwLane(obj["adjleftlane"]);
        }
        if(obj.contains("adjrightlane"))
        {
            msg.adjrightlane = from_json_ApollodriversLdwLane(obj["adjrightlane"]);
        }
        return msg;
    }
    template <>
    ApollodriversLdwRoadway from_json<ApollodriversLdwRoadway>(nlohmann::json obj){
        return from_json_ApollodriversLdwRoadway(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLdwRoadway &dt)
    {
        dt=from_json_ApollodriversLdwRoadway(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversLdwRoadway & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLdwRoadway & dt)
    {
        os << to_json(dt);
        return os;
    }
}
