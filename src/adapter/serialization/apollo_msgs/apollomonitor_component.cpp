#include "adapter/serialization/apollo_msgs/apollomonitor_component.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorComponent &msg) {
        nlohmann::json obj;
        obj["summary"] = to_json(msg.summary);
        obj["processstatus"] = to_json(msg.processstatus);
        obj["channelstatus"] = to_json(msg.channelstatus);
        obj["resourcestatus"] = to_json(msg.resourcestatus);
        obj["otherstatus"] = to_json(msg.otherstatus);
        obj["modulestatus"] = to_json(msg.modulestatus);
        return obj;
    }
    ApollomonitorComponent from_json_ApollomonitorComponent (nlohmann::json obj) {
        ApollomonitorComponent msg;
        if(obj.contains("summary"))
        {
            msg.summary = from_json_ApollomonitorComponentStatus(obj["summary"]);
        }
        if(obj.contains("processstatus"))
        {
            msg.processstatus = from_json_ApollomonitorComponentStatus(obj["processstatus"]);
        }
        if(obj.contains("channelstatus"))
        {
            msg.channelstatus = from_json_ApollomonitorComponentStatus(obj["channelstatus"]);
        }
        if(obj.contains("resourcestatus"))
        {
            msg.resourcestatus = from_json_ApollomonitorComponentStatus(obj["resourcestatus"]);
        }
        if(obj.contains("otherstatus"))
        {
            msg.otherstatus = from_json_ApollomonitorComponentStatus(obj["otherstatus"]);
        }
        if(obj.contains("modulestatus"))
        {
            msg.modulestatus = from_json_ApollomonitorComponentStatus(obj["modulestatus"]);
        }
        return msg;
    }
    template <>
    ApollomonitorComponent from_json<ApollomonitorComponent>(nlohmann::json obj){
        return from_json_ApollomonitorComponent(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorComponent &dt)
    {
        dt=from_json_ApollomonitorComponent(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollomonitorComponent & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorComponent & dt)
    {
        os << to_json(dt);
        return os;
    }
}
