#include "adapter/serialization/apollo_msgs/apolloplanning_internal_speed_plan.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalSpeedPlan &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_speedpoint;
        for (auto it = msg.speedpoint.begin(); it != msg.speedpoint.end(); ++it) {
            arr_speedpoint.push_back(to_json(*it));
        }
        obj["speedpoint"] = arr_speedpoint;
        return obj;
    }
    ApolloplanningInternalSpeedPlan from_json_ApolloplanningInternalSpeedPlan (nlohmann::json obj) {
        ApolloplanningInternalSpeedPlan msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("speedpoint"))
        {
            if(obj["speedpoint"].is_array())
            {
                for (auto& element : obj["speedpoint"])
                {
                    msg.speedpoint.push_back(from_json_ApollocommonSpeedPoint(element));
                }
            }
            else
            {
                msg.speedpoint.push_back(from_json_ApollocommonSpeedPoint(obj["speedpoint"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalSpeedPlan from_json<ApolloplanningInternalSpeedPlan>(nlohmann::json obj){
        return from_json_ApolloplanningInternalSpeedPlan(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalSpeedPlan &dt)
    {
        dt=from_json_ApolloplanningInternalSpeedPlan(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalSpeedPlan & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalSpeedPlan & dt)
    {
        os << to_json(dt);
        return os;
    }
}
