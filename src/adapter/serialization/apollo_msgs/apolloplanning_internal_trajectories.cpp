#include "adapter/serialization/apollo_msgs/apolloplanning_internal_trajectories.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalTrajectories &msg) {
        nlohmann::json obj;
        nlohmann::json arr_trajectory;
        for (auto it = msg.trajectory.begin(); it != msg.trajectory.end(); ++it) {
            arr_trajectory.push_back(to_json(*it));
        }
        obj["trajectory"] = arr_trajectory;
        return obj;
    }
    ApolloplanningInternalTrajectories from_json_ApolloplanningInternalTrajectories (nlohmann::json obj) {
        ApolloplanningInternalTrajectories msg;
        if(obj.contains("trajectory"))
        {
            if(obj["trajectory"].is_array())
            {
                for (auto& element : obj["trajectory"])
                {
                    msg.trajectory.push_back(from_json_ApollocommonTrajectory(element));
                }
            }
            else
            {
                msg.trajectory.push_back(from_json_ApollocommonTrajectory(obj["trajectory"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalTrajectories from_json<ApolloplanningInternalTrajectories>(nlohmann::json obj){
        return from_json_ApolloplanningInternalTrajectories(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalTrajectories &dt)
    {
        dt=from_json_ApolloplanningInternalTrajectories(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalTrajectories & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalTrajectories & dt)
    {
        os << to_json(dt);
        return os;
    }
}
