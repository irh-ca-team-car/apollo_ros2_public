#include "adapter/serialization/apollo_msgs/apolloplanning_path_reuse_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathReuseDeciderConfig &msg) {
        nlohmann::json obj;
        obj["reusepath"] = (msg.reusepath);
        return obj;
    }
    ApolloplanningPathReuseDeciderConfig from_json_ApolloplanningPathReuseDeciderConfig (nlohmann::json obj) {
        ApolloplanningPathReuseDeciderConfig msg;
        if(obj.contains("reusepath"))
        {
            msg.reusepath = (obj["reusepath"].is_string()?(bool)atoi(obj["reusepath"].get<std::string>().c_str()):obj["reusepath"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningPathReuseDeciderConfig from_json<ApolloplanningPathReuseDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPathReuseDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathReuseDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningPathReuseDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathReuseDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathReuseDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
