#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_rule_configconfig.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficRuleConfigconfig &msg) {
        nlohmann::json obj;
        obj["backsidevehicle"] = to_json(msg.backsidevehicle);
        obj["crosswalk"] = to_json(msg.crosswalk);
        obj["destination"] = to_json(msg.destination);
        obj["keepclear"] = to_json(msg.keepclear);
        obj["referencelineend"] = to_json(msg.referencelineend);
        obj["rerouting"] = to_json(msg.rerouting);
        obj["stopsign"] = to_json(msg.stopsign);
        obj["trafficlight"] = to_json(msg.trafficlight);
        obj["yieldsign"] = to_json(msg.yieldsign);
        return obj;
    }
    ApolloplanningTrafficRuleConfigconfig from_json_ApolloplanningTrafficRuleConfigconfig (nlohmann::json obj) {
        ApolloplanningTrafficRuleConfigconfig msg;
        if(obj.contains("backsidevehicle"))
        {
            msg.backsidevehicle = from_json_ApolloplanningBacksideVehicleConfig(obj["backsidevehicle"]);
        }
        if(obj.contains("crosswalk"))
        {
            msg.crosswalk = from_json_ApolloplanningCrosswalkConfig(obj["crosswalk"]);
        }
        if(obj.contains("destination"))
        {
            msg.destination = from_json_ApolloplanningDestinationConfig(obj["destination"]);
        }
        if(obj.contains("keepclear"))
        {
            msg.keepclear = from_json_ApolloplanningKeepClearConfig(obj["keepclear"]);
        }
        if(obj.contains("referencelineend"))
        {
            msg.referencelineend = from_json_ApolloplanningReferenceLineEndConfig(obj["referencelineend"]);
        }
        if(obj.contains("rerouting"))
        {
            msg.rerouting = from_json_ApolloplanningReroutingConfig(obj["rerouting"]);
        }
        if(obj.contains("stopsign"))
        {
            msg.stopsign = from_json_ApolloplanningStopSignConfig(obj["stopsign"]);
        }
        if(obj.contains("trafficlight"))
        {
            msg.trafficlight = from_json_ApolloplanningTrafficLightConfig(obj["trafficlight"]);
        }
        if(obj.contains("yieldsign"))
        {
            msg.yieldsign = from_json_ApolloplanningYieldSignConfig(obj["yieldsign"]);
        }
        return msg;
    }
    template <>
    ApolloplanningTrafficRuleConfigconfig from_json<ApolloplanningTrafficRuleConfigconfig>(nlohmann::json obj){
        return from_json_ApolloplanningTrafficRuleConfigconfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficRuleConfigconfig &dt)
    {
        dt=from_json_ApolloplanningTrafficRuleConfigconfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficRuleConfigconfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficRuleConfigconfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
