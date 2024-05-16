#include "adapter/serialization/apollo_msgs/apolloplanning_stop_point.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStopPoint &msg) {
        nlohmann::json obj;
        obj["s"] = (msg.s);
        obj["type"] = (msg.type);
        return obj;
    }
    ApolloplanningStopPoint from_json_ApolloplanningStopPoint (nlohmann::json obj) {
        ApolloplanningStopPoint msg;
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atof(obj["s"].get<std::string>().c_str()):obj["s"].get<double>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningStopPoint from_json<ApolloplanningStopPoint>(nlohmann::json obj){
        return from_json_ApolloplanningStopPoint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStopPoint &dt)
    {
        dt=from_json_ApolloplanningStopPoint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStopPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStopPoint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
