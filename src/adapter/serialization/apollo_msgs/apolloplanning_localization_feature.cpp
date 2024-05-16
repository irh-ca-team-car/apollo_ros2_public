#include "adapter/serialization/apollo_msgs/apolloplanning_localization_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLocalizationFeature &msg) {
        nlohmann::json obj;
        obj["messagetimestampsec"] = (msg.messagetimestampsec);
        obj["position"] = to_json(msg.position);
        obj["heading"] = (msg.heading);
        obj["linearvelocity"] = to_json(msg.linearvelocity);
        obj["linearacceleration"] = to_json(msg.linearacceleration);
        obj["angularvelocity"] = to_json(msg.angularvelocity);
        return obj;
    }
    ApolloplanningLocalizationFeature from_json_ApolloplanningLocalizationFeature (nlohmann::json obj) {
        ApolloplanningLocalizationFeature msg;
        if(obj.contains("messagetimestampsec"))
        {
            msg.messagetimestampsec = (obj["messagetimestampsec"].is_string()?atof(obj["messagetimestampsec"].get<std::string>().c_str()):obj["messagetimestampsec"].get<double>());
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPointENU(obj["position"]);
        }
        if(obj.contains("heading"))
        {
            msg.heading = (obj["heading"].is_string()?atof(obj["heading"].get<std::string>().c_str()):obj["heading"].get<double>());
        }
        if(obj.contains("linearvelocity"))
        {
            msg.linearvelocity = from_json_ApollocommonPoint3D(obj["linearvelocity"]);
        }
        if(obj.contains("linearacceleration"))
        {
            msg.linearacceleration = from_json_ApollocommonPoint3D(obj["linearacceleration"]);
        }
        if(obj.contains("angularvelocity"))
        {
            msg.angularvelocity = from_json_ApollocommonPoint3D(obj["angularvelocity"]);
        }
        return msg;
    }
    template <>
    ApolloplanningLocalizationFeature from_json<ApolloplanningLocalizationFeature>(nlohmann::json obj){
        return from_json_ApolloplanningLocalizationFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLocalizationFeature &dt)
    {
        dt=from_json_ApolloplanningLocalizationFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLocalizationFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLocalizationFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
