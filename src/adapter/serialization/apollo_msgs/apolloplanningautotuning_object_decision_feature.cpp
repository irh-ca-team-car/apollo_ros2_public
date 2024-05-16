#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_object_decision_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningObjectDecisionFeature &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["relatives"] = (msg.relatives);
        obj["relativel"] = (msg.relativel);
        obj["relativev"] = (msg.relativev);
        obj["speed"] = (msg.speed);
        return obj;
    }
    ApolloplanningautotuningObjectDecisionFeature from_json_ApolloplanningautotuningObjectDecisionFeature (nlohmann::json obj) {
        ApolloplanningautotuningObjectDecisionFeature msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("relatives"))
        {
            msg.relatives = (obj["relatives"].is_string()?atof(obj["relatives"].get<std::string>().c_str()):obj["relatives"].get<double>());
        }
        if(obj.contains("relativel"))
        {
            msg.relativel = (obj["relativel"].is_string()?atof(obj["relativel"].get<std::string>().c_str()):obj["relativel"].get<double>());
        }
        if(obj.contains("relativev"))
        {
            msg.relativev = (obj["relativev"].is_string()?atof(obj["relativev"].get<std::string>().c_str()):obj["relativev"].get<double>());
        }
        if(obj.contains("speed"))
        {
            msg.speed = (obj["speed"].is_string()?atof(obj["speed"].get<std::string>().c_str()):obj["speed"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningObjectDecisionFeature from_json<ApolloplanningautotuningObjectDecisionFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningObjectDecisionFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningObjectDecisionFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningObjectDecisionFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningObjectDecisionFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningObjectDecisionFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
