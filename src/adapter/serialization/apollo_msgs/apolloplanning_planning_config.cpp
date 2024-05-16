#include "adapter/serialization/apollo_msgs/apolloplanning_planning_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningConfig &msg) {
        nlohmann::json obj;
        obj["topicconfig"] = to_json(msg.topicconfig);
        obj["learningmode"] = (msg.learningmode);
        obj["planningconfig"] = to_json(msg.planningconfig);
        nlohmann::json arr_defaulttaskconfig;
        for (auto it = msg.defaulttaskconfig.begin(); it != msg.defaulttaskconfig.end(); ++it) {
            arr_defaulttaskconfig.push_back(to_json(*it));
        }
        obj["defaulttaskconfig"] = arr_defaulttaskconfig;
        return obj;
    }
    ApolloplanningPlanningConfig from_json_ApolloplanningPlanningConfig (nlohmann::json obj) {
        ApolloplanningPlanningConfig msg;
        if(obj.contains("topicconfig"))
        {
            msg.topicconfig = from_json_ApolloplanningTopicConfig(obj["topicconfig"]);
        }
        if(obj.contains("learningmode"))
        {
            msg.learningmode = (obj["learningmode"].is_string()?atoi(obj["learningmode"].get<std::string>().c_str()):obj["learningmode"].get<int>());
        }
        if(obj.contains("planningconfig"))
        {
            msg.planningconfig = from_json_ApolloplanningPlanningConfigplanningConfig(obj["planningconfig"]);
        }
        if(obj.contains("defaulttaskconfig"))
        {
            if(obj["defaulttaskconfig"].is_array())
            {
                for (auto& element : obj["defaulttaskconfig"])
                {
                    msg.defaulttaskconfig.push_back(from_json_ApolloplanningTaskConfig(element));
                }
            }
            else
            {
                msg.defaulttaskconfig.push_back(from_json_ApolloplanningTaskConfig(obj["defaulttaskconfig"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningPlanningConfig from_json<ApolloplanningPlanningConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPlanningConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningConfig &dt)
    {
        dt=from_json_ApolloplanningPlanningConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
