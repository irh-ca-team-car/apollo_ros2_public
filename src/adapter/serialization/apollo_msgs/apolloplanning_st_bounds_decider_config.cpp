#include "adapter/serialization/apollo_msgs/apolloplanning_st_bounds_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSTBoundsDeciderConfig &msg) {
        nlohmann::json obj;
        obj["totaltime"] = (msg.totaltime);
        return obj;
    }
    ApolloplanningSTBoundsDeciderConfig from_json_ApolloplanningSTBoundsDeciderConfig (nlohmann::json obj) {
        ApolloplanningSTBoundsDeciderConfig msg;
        if(obj.contains("totaltime"))
        {
            msg.totaltime = (obj["totaltime"].is_string()?atof(obj["totaltime"].get<std::string>().c_str()):obj["totaltime"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningSTBoundsDeciderConfig from_json<ApolloplanningSTBoundsDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningSTBoundsDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSTBoundsDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningSTBoundsDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSTBoundsDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSTBoundsDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
