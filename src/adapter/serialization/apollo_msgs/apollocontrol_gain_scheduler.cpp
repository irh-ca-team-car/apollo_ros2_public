#include "adapter/serialization/apollo_msgs/apollocontrol_gain_scheduler.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolGainScheduler &msg) {
        nlohmann::json obj;
        nlohmann::json arr_scheduler;
        for (auto it = msg.scheduler.begin(); it != msg.scheduler.end(); ++it) {
            arr_scheduler.push_back(to_json(*it));
        }
        obj["scheduler"] = arr_scheduler;
        return obj;
    }
    ApollocontrolGainScheduler from_json_ApollocontrolGainScheduler (nlohmann::json obj) {
        ApollocontrolGainScheduler msg;
        if(obj.contains("scheduler"))
        {
            if(obj["scheduler"].is_array())
            {
                for (auto& element : obj["scheduler"])
                {
                    msg.scheduler.push_back(from_json_ApollocontrolGainSchedulerInfo(element));
                }
            }
            else
            {
                msg.scheduler.push_back(from_json_ApollocontrolGainSchedulerInfo(obj["scheduler"]));
            }
        }
        return msg;
    }
    template <>
    ApollocontrolGainScheduler from_json<ApollocontrolGainScheduler>(nlohmann::json obj){
        return from_json_ApollocontrolGainScheduler(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolGainScheduler &dt)
    {
        dt=from_json_ApollocontrolGainScheduler(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolGainScheduler & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolGainScheduler & dt)
    {
        os << to_json(dt);
        return os;
    }
}
