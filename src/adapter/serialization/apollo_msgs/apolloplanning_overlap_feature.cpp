#include "adapter/serialization/apollo_msgs/apolloplanning_overlap_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOverlapFeature &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["distance"] = (msg.distance);
        return obj;
    }
    ApolloplanningOverlapFeature from_json_ApolloplanningOverlapFeature (nlohmann::json obj) {
        ApolloplanningOverlapFeature msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("distance"))
        {
            msg.distance = (obj["distance"].is_string()?atof(obj["distance"].get<std::string>().c_str()):obj["distance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningOverlapFeature from_json<ApolloplanningOverlapFeature>(nlohmann::json obj){
        return from_json_ApolloplanningOverlapFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOverlapFeature &dt)
    {
        dt=from_json_ApolloplanningOverlapFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOverlapFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOverlapFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
