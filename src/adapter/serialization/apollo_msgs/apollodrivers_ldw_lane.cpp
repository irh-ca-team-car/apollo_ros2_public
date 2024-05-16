#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_lane.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLdwLane &msg) {
        nlohmann::json obj;
        obj["width"] = (msg.width);
        obj["quality"] = (msg.quality);
        obj["style"] = (msg.style);
        obj["leftboundary"] = to_json(msg.leftboundary);
        obj["rightboundary"] = to_json(msg.rightboundary);
        return obj;
    }
    ApollodriversLdwLane from_json_ApollodriversLdwLane (nlohmann::json obj) {
        ApollodriversLdwLane msg;
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<int>());
        }
        if(obj.contains("quality"))
        {
            msg.quality = (obj["quality"].is_string()?atoi(obj["quality"].get<std::string>().c_str()):obj["quality"].get<int>());
        }
        if(obj.contains("style"))
        {
            msg.style = (obj["style"].is_string()?atoi(obj["style"].get<std::string>().c_str()):obj["style"].get<int>());
        }
        if(obj.contains("leftboundary"))
        {
            msg.leftboundary = from_json_ApollodriversLdwLaneBoundary(obj["leftboundary"]);
        }
        if(obj.contains("rightboundary"))
        {
            msg.rightboundary = from_json_ApollodriversLdwLaneBoundary(obj["rightboundary"]);
        }
        return msg;
    }
    template <>
    ApollodriversLdwLane from_json<ApollodriversLdwLane>(nlohmann::json obj){
        return from_json_ApollodriversLdwLane(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLdwLane &dt)
    {
        dt=from_json_ApollodriversLdwLane(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversLdwLane & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLdwLane & dt)
    {
        os << to_json(dt);
        return os;
    }
}
