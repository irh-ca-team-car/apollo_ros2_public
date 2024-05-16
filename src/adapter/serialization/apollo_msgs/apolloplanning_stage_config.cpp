#include "adapter/serialization/apollo_msgs/apolloplanning_stage_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStageConfig &msg) {
        nlohmann::json obj;
        obj["stagetype"] = (msg.stagetype);
        obj["enabled"] = (msg.enabled);
        nlohmann::json arr_tasktype;
        for (auto it = msg.tasktype.begin(); it != msg.tasktype.end(); ++it) {
            arr_tasktype.push_back((*it));
        }
        obj["tasktype"] = arr_tasktype;
        nlohmann::json arr_taskconfig;
        for (auto it = msg.taskconfig.begin(); it != msg.taskconfig.end(); ++it) {
            arr_taskconfig.push_back(to_json(*it));
        }
        obj["taskconfig"] = arr_taskconfig;
        return obj;
    }
    ApolloplanningStageConfig from_json_ApolloplanningStageConfig (nlohmann::json obj) {
        ApolloplanningStageConfig msg;
        if(obj.contains("stagetype"))
        {
            msg.stagetype = (obj["stagetype"].is_string()?atoi(obj["stagetype"].get<std::string>().c_str()):obj["stagetype"].get<int>());
        }
        if(obj.contains("enabled"))
        {
            msg.enabled = (obj["enabled"].is_string()?(bool)atoi(obj["enabled"].get<std::string>().c_str()):obj["enabled"].get<bool>());
        }
        if(obj.contains("tasktype"))
        {
            if(obj["tasktype"].is_array())
            {
                for (auto& element : obj["tasktype"])
                {
                    msg.tasktype.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.tasktype.push_back((obj["tasktype"].is_string()?atoi(obj["tasktype"].get<std::string>().c_str()):obj["tasktype"].get<int>()));
            }
        }
        if(obj.contains("taskconfig"))
        {
            if(obj["taskconfig"].is_array())
            {
                for (auto& element : obj["taskconfig"])
                {
                    msg.taskconfig.push_back(from_json_ApolloplanningTaskConfig(element));
                }
            }
            else
            {
                msg.taskconfig.push_back(from_json_ApolloplanningTaskConfig(obj["taskconfig"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningStageConfig from_json<ApolloplanningStageConfig>(nlohmann::json obj){
        return from_json_ApolloplanningStageConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStageConfig &dt)
    {
        dt=from_json_ApolloplanningStageConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStageConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStageConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
