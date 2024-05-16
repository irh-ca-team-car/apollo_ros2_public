#include "adapter/serialization/apollo_msgs/apolloplanning_speed_decider_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningSpeedDeciderStatus &msg) {
        nlohmann::json obj;
        nlohmann::json arr_pedestrianstoptime;
        for (auto it = msg.pedestrianstoptime.begin(); it != msg.pedestrianstoptime.end(); ++it) {
            arr_pedestrianstoptime.push_back(to_json(*it));
        }
        obj["pedestrianstoptime"] = arr_pedestrianstoptime;
        return obj;
    }
    ApolloplanningSpeedDeciderStatus from_json_ApolloplanningSpeedDeciderStatus (nlohmann::json obj) {
        ApolloplanningSpeedDeciderStatus msg;
        if(obj.contains("pedestrianstoptime"))
        {
            if(obj["pedestrianstoptime"].is_array())
            {
                for (auto& element : obj["pedestrianstoptime"])
                {
                    msg.pedestrianstoptime.push_back(from_json_ApolloplanningStopTime(element));
                }
            }
            else
            {
                msg.pedestrianstoptime.push_back(from_json_ApolloplanningStopTime(obj["pedestrianstoptime"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningSpeedDeciderStatus from_json<ApolloplanningSpeedDeciderStatus>(nlohmann::json obj){
        return from_json_ApolloplanningSpeedDeciderStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningSpeedDeciderStatus &dt)
    {
        dt=from_json_ApolloplanningSpeedDeciderStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningSpeedDeciderStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningSpeedDeciderStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
