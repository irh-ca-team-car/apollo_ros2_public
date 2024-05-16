#include "adapter/serialization/apollo_msgs/apolloplanning_task_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTaskConfig &msg) {
        nlohmann::json obj;
        obj["tasktype"] = (msg.tasktype);
        obj["taskconfig"] = to_json(msg.taskconfig);
        return obj;
    }
    ApolloplanningTaskConfig from_json_ApolloplanningTaskConfig (nlohmann::json obj) {
        ApolloplanningTaskConfig msg;
        if(obj.contains("tasktype"))
        {
            msg.tasktype = (obj["tasktype"].is_string()?atoi(obj["tasktype"].get<std::string>().c_str()):obj["tasktype"].get<int>());
        }
        if(obj.contains("taskconfig"))
        {
            msg.taskconfig = from_json_ApolloplanningTaskConfigtaskConfig(obj["taskconfig"]);
        }
        return msg;
    }
    template <>
    ApolloplanningTaskConfig from_json<ApolloplanningTaskConfig>(nlohmann::json obj){
        return from_json_ApolloplanningTaskConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTaskConfig &dt)
    {
        dt=from_json_ApolloplanningTaskConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTaskConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTaskConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
