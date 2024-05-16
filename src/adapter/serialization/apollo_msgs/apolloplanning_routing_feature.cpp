#include "adapter/serialization/apollo_msgs/apolloplanning_routing_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningRoutingFeature &msg) {
        nlohmann::json obj;
        obj["routingresponse"] = to_json(msg.routingresponse);
        nlohmann::json arr_localroutinglaneid;
        for (auto it = msg.localroutinglaneid.begin(); it != msg.localroutinglaneid.end(); ++it) {
            arr_localroutinglaneid.push_back((*it));
        }
        obj["localroutinglaneid"] = arr_localroutinglaneid;
        obj["localrouting"] = to_json(msg.localrouting);
        return obj;
    }
    ApolloplanningRoutingFeature from_json_ApolloplanningRoutingFeature (nlohmann::json obj) {
        ApolloplanningRoutingFeature msg;
        if(obj.contains("routingresponse"))
        {
            msg.routingresponse = from_json_ApolloplanningRoutingResponseFeature(obj["routingresponse"]);
        }
        if(obj.contains("localroutinglaneid"))
        {
            if(obj["localroutinglaneid"].is_array())
            {
                for (auto& element : obj["localroutinglaneid"])
                {
                    msg.localroutinglaneid.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.localroutinglaneid.push_back((obj["localroutinglaneid"].is_string()?(obj["localroutinglaneid"].get<std::string>().c_str()):obj["localroutinglaneid"].get<std::string>()));
            }
        }
        if(obj.contains("localrouting"))
        {
            msg.localrouting = from_json_ApolloplanningRoutingResponseFeature(obj["localrouting"]);
        }
        return msg;
    }
    template <>
    ApolloplanningRoutingFeature from_json<ApolloplanningRoutingFeature>(nlohmann::json obj){
        return from_json_ApolloplanningRoutingFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningRoutingFeature &dt)
    {
        dt=from_json_ApolloplanningRoutingFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningRoutingFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningRoutingFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
