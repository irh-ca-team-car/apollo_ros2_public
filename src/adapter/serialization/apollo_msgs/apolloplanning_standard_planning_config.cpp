#include "adapter/serialization/apollo_msgs/apolloplanning_standard_planning_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStandardPlanningConfig &msg) {
        nlohmann::json obj;
        nlohmann::json arr_plannertype;
        for (auto it = msg.plannertype.begin(); it != msg.plannertype.end(); ++it) {
            arr_plannertype.push_back((*it));
        }
        obj["plannertype"] = arr_plannertype;
        obj["plannerpublicroadconfig"] = (msg.plannerpublicroadconfig);
        return obj;
    }
    ApolloplanningStandardPlanningConfig from_json_ApolloplanningStandardPlanningConfig (nlohmann::json obj) {
        ApolloplanningStandardPlanningConfig msg;
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
        if(obj.contains("plannerpublicroadconfig"))
        {
            msg.plannerpublicroadconfig = (obj["plannerpublicroadconfig"].is_string()?atoi(obj["plannerpublicroadconfig"].get<std::string>().c_str()):obj["plannerpublicroadconfig"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningStandardPlanningConfig from_json<ApolloplanningStandardPlanningConfig>(nlohmann::json obj){
        return from_json_ApolloplanningStandardPlanningConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStandardPlanningConfig &dt)
    {
        dt=from_json_ApolloplanningStandardPlanningConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStandardPlanningConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStandardPlanningConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
