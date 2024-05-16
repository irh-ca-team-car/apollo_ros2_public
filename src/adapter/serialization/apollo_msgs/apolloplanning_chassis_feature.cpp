#include "adapter/serialization/apollo_msgs/apolloplanning_chassis_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningChassisFeature &msg) {
        nlohmann::json obj;
        obj["messagetimestampsec"] = (msg.messagetimestampsec);
        obj["speedmps"] = (msg.speedmps);
        obj["throttlepercentage"] = (msg.throttlepercentage);
        obj["brakepercentage"] = (msg.brakepercentage);
        obj["steeringpercentage"] = (msg.steeringpercentage);
        obj["gearlocation"] = (msg.gearlocation);
        return obj;
    }
    ApolloplanningChassisFeature from_json_ApolloplanningChassisFeature (nlohmann::json obj) {
        ApolloplanningChassisFeature msg;
        if(obj.contains("messagetimestampsec"))
        {
            msg.messagetimestampsec = (obj["messagetimestampsec"].is_string()?atof(obj["messagetimestampsec"].get<std::string>().c_str()):obj["messagetimestampsec"].get<double>());
        }
        if(obj.contains("speedmps"))
        {
            msg.speedmps = (obj["speedmps"].is_string()?(float)atof(obj["speedmps"].get<std::string>().c_str()):obj["speedmps"].get<float>());
        }
        if(obj.contains("throttlepercentage"))
        {
            msg.throttlepercentage = (obj["throttlepercentage"].is_string()?(float)atof(obj["throttlepercentage"].get<std::string>().c_str()):obj["throttlepercentage"].get<float>());
        }
        if(obj.contains("brakepercentage"))
        {
            msg.brakepercentage = (obj["brakepercentage"].is_string()?(float)atof(obj["brakepercentage"].get<std::string>().c_str()):obj["brakepercentage"].get<float>());
        }
        if(obj.contains("steeringpercentage"))
        {
            msg.steeringpercentage = (obj["steeringpercentage"].is_string()?(float)atof(obj["steeringpercentage"].get<std::string>().c_str()):obj["steeringpercentage"].get<float>());
        }
        if(obj.contains("gearlocation"))
        {
            msg.gearlocation = (obj["gearlocation"].is_string()?atoi(obj["gearlocation"].get<std::string>().c_str()):obj["gearlocation"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningChassisFeature from_json<ApolloplanningChassisFeature>(nlohmann::json obj){
        return from_json_ApolloplanningChassisFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningChassisFeature &dt)
    {
        dt=from_json_ApolloplanningChassisFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningChassisFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningChassisFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
