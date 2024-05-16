#include "adapter/serialization/apollo_msgs/apollorelative_map_relative_map_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapRelativeMapConfig &msg) {
        nlohmann::json obj;
        obj["mapparam"] = to_json(msg.mapparam);
        obj["navigationlane"] = to_json(msg.navigationlane);
        return obj;
    }
    ApollorelativeMapRelativeMapConfig from_json_ApollorelativeMapRelativeMapConfig (nlohmann::json obj) {
        ApollorelativeMapRelativeMapConfig msg;
        if(obj.contains("mapparam"))
        {
            msg.mapparam = from_json_ApollorelativeMapMapGenerationParam(obj["mapparam"]);
        }
        if(obj.contains("navigationlane"))
        {
            msg.navigationlane = from_json_ApollorelativeMapNavigationLaneConfig(obj["navigationlane"]);
        }
        return msg;
    }
    template <>
    ApollorelativeMapRelativeMapConfig from_json<ApollorelativeMapRelativeMapConfig>(nlohmann::json obj){
        return from_json_ApollorelativeMapRelativeMapConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapRelativeMapConfig &dt)
    {
        dt=from_json_ApollorelativeMapRelativeMapConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapRelativeMapConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapRelativeMapConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
