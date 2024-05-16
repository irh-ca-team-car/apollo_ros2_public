#include "adapter/serialization/apollo_msgs/apolloplanning_path_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathDeciderConfig &msg) {
        nlohmann::json obj;
        obj["staticobstaclebuffer"] = (msg.staticobstaclebuffer);
        return obj;
    }
    ApolloplanningPathDeciderConfig from_json_ApolloplanningPathDeciderConfig (nlohmann::json obj) {
        ApolloplanningPathDeciderConfig msg;
        if(obj.contains("staticobstaclebuffer"))
        {
            msg.staticobstaclebuffer = (obj["staticobstaclebuffer"].is_string()?atof(obj["staticobstaclebuffer"].get<std::string>().c_str()):obj["staticobstaclebuffer"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningPathDeciderConfig from_json<ApolloplanningPathDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPathDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningPathDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
