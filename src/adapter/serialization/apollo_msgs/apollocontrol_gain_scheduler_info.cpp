#include "adapter/serialization/apollo_msgs/apollocontrol_gain_scheduler_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolGainSchedulerInfo &msg) {
        nlohmann::json obj;
        obj["speed"] = (msg.speed);
        obj["ratio"] = (msg.ratio);
        return obj;
    }
    ApollocontrolGainSchedulerInfo from_json_ApollocontrolGainSchedulerInfo (nlohmann::json obj) {
        ApollocontrolGainSchedulerInfo msg;
        if(obj.contains("speed"))
        {
            msg.speed = (obj["speed"].is_string()?atof(obj["speed"].get<std::string>().c_str()):obj["speed"].get<double>());
        }
        if(obj.contains("ratio"))
        {
            msg.ratio = (obj["ratio"].is_string()?atof(obj["ratio"].get<std::string>().c_str()):obj["ratio"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocontrolGainSchedulerInfo from_json<ApollocontrolGainSchedulerInfo>(nlohmann::json obj){
        return from_json_ApollocontrolGainSchedulerInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolGainSchedulerInfo &dt)
    {
        dt=from_json_ApollocontrolGainSchedulerInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolGainSchedulerInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolGainSchedulerInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
