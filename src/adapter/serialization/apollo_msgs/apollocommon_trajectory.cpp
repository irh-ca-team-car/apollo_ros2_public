#include "adapter/serialization/apollo_msgs/apollocommon_trajectory.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonTrajectory &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_trajectorypoint;
        for (auto it = msg.trajectorypoint.begin(); it != msg.trajectorypoint.end(); ++it) {
            arr_trajectorypoint.push_back(to_json(*it));
        }
        obj["trajectorypoint"] = arr_trajectorypoint;
        return obj;
    }
    ApollocommonTrajectory from_json_ApollocommonTrajectory (nlohmann::json obj) {
        ApollocommonTrajectory msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("trajectorypoint"))
        {
            if(obj["trajectorypoint"].is_array())
            {
                for (auto& element : obj["trajectorypoint"])
                {
                    msg.trajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(element));
                }
            }
            else
            {
                msg.trajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(obj["trajectorypoint"]));
            }
        }
        return msg;
    }
    template <>
    ApollocommonTrajectory from_json<ApollocommonTrajectory>(nlohmann::json obj){
        return from_json_ApollocommonTrajectory(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonTrajectory &dt)
    {
        dt=from_json_ApollocommonTrajectory(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonTrajectory & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonTrajectory & dt)
    {
        os << to_json(dt);
        return os;
    }
}
