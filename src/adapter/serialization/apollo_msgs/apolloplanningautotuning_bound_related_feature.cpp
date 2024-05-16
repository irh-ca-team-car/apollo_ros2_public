#include "adapter/serialization/apollo_msgs/apolloplanningautotuning_bound_related_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningautotuningBoundRelatedFeature &msg) {
        nlohmann::json obj;
        obj["bounddistance"] = (msg.bounddistance);
        obj["crossablelevel"] = (msg.crossablelevel);
        return obj;
    }
    ApolloplanningautotuningBoundRelatedFeature from_json_ApolloplanningautotuningBoundRelatedFeature (nlohmann::json obj) {
        ApolloplanningautotuningBoundRelatedFeature msg;
        if(obj.contains("bounddistance"))
        {
            msg.bounddistance = (obj["bounddistance"].is_string()?atof(obj["bounddistance"].get<std::string>().c_str()):obj["bounddistance"].get<double>());
        }
        if(obj.contains("crossablelevel"))
        {
            msg.crossablelevel = (obj["crossablelevel"].is_string()?atoi(obj["crossablelevel"].get<std::string>().c_str()):obj["crossablelevel"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningautotuningBoundRelatedFeature from_json<ApolloplanningautotuningBoundRelatedFeature>(nlohmann::json obj){
        return from_json_ApolloplanningautotuningBoundRelatedFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningautotuningBoundRelatedFeature &dt)
    {
        dt=from_json_ApolloplanningautotuningBoundRelatedFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningautotuningBoundRelatedFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningautotuningBoundRelatedFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
