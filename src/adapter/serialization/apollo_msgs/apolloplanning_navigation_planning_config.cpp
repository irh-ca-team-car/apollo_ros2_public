#include "adapter/serialization/apollo_msgs/apolloplanning_navigation_planning_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningNavigationPlanningConfig &msg) {
        nlohmann::json obj;
        nlohmann::json arr_plannertype;
        for (auto it = msg.plannertype.begin(); it != msg.plannertype.end(); ++it) {
            arr_plannertype.push_back((*it));
        }
        obj["plannertype"] = arr_plannertype;
        obj["plannernaviconfig"] = to_json(msg.plannernaviconfig);
        return obj;
    }
    ApolloplanningNavigationPlanningConfig from_json_ApolloplanningNavigationPlanningConfig (nlohmann::json obj) {
        ApolloplanningNavigationPlanningConfig msg;
        if(obj.contains("plannertype"))
        {
            if(obj["plannertype"].is_array())
            {
                for (auto& element : obj["plannertype"])
                {
                    msg.plannertype.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.plannertype.push_back((obj["plannertype"].is_string()?atoi(obj["plannertype"].get<std::string>().c_str()):obj["plannertype"].get<int>()));
            }
        }
        if(obj.contains("plannernaviconfig"))
        {
            msg.plannernaviconfig = from_json_ApolloplanningPlannerNaviConfig(obj["plannernaviconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningNavigationPlanningConfig from_json<ApolloplanningNavigationPlanningConfig>(nlohmann::json obj){
        return from_json_ApolloplanningNavigationPlanningConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningNavigationPlanningConfig &dt)
    {
        dt=from_json_ApolloplanningNavigationPlanningConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningNavigationPlanningConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningNavigationPlanningConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
