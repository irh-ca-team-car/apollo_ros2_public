#include "adapter/serialization/apollo_msgs/apolloplanning_planner_navi_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlannerNaviConfig &msg) {
        nlohmann::json obj;
        nlohmann::json arr_task;
        for (auto it = msg.task.begin(); it != msg.task.end(); ++it) {
            arr_task.push_back((*it));
        }
        obj["task"] = arr_task;
        obj["navipathdeciderconfig"] = to_json(msg.navipathdeciderconfig);
        obj["navispeeddeciderconfig"] = to_json(msg.navispeeddeciderconfig);
        obj["naviobstacledeciderconfig"] = to_json(msg.naviobstacledeciderconfig);
        return obj;
    }
    ApolloplanningPlannerNaviConfig from_json_ApolloplanningPlannerNaviConfig (nlohmann::json obj) {
        ApolloplanningPlannerNaviConfig msg;
        if(obj.contains("task"))
        {
            if(obj["task"].is_array())
            {
                for (auto& element : obj["task"])
                {
                    msg.task.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.task.push_back((obj["task"].is_string()?atoi(obj["task"].get<std::string>().c_str()):obj["task"].get<int>()));
            }
        }
        if(obj.contains("navipathdeciderconfig"))
        {
            msg.navipathdeciderconfig = from_json_ApolloplanningNaviPathDeciderConfig(obj["navipathdeciderconfig"]);
        }
        if(obj.contains("navispeeddeciderconfig"))
        {
            msg.navispeeddeciderconfig = from_json_ApolloplanningNaviSpeedDeciderConfig(obj["navispeeddeciderconfig"]);
        }
        if(obj.contains("naviobstacledeciderconfig"))
        {
            msg.naviobstacledeciderconfig = from_json_ApolloplanningNaviObstacleDeciderConfig(obj["naviobstacledeciderconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningPlannerNaviConfig from_json<ApolloplanningPlannerNaviConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPlannerNaviConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlannerNaviConfig &dt)
    {
        dt=from_json_ApolloplanningPlannerNaviConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlannerNaviConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlannerNaviConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
