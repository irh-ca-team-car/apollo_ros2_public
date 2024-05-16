#include "adapter/serialization/apollo_msgs/apollotask_manager_task_manager_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotaskManagerTaskManagerConfig &msg) {
        nlohmann::json obj;
        obj["topicconfig"] = to_json(msg.topicconfig);
        return obj;
    }
    ApollotaskManagerTaskManagerConfig from_json_ApollotaskManagerTaskManagerConfig (nlohmann::json obj) {
        ApollotaskManagerTaskManagerConfig msg;
        if(obj.contains("topicconfig"))
        {
            msg.topicconfig = from_json_ApollotaskManagerTopicConfig(obj["topicconfig"]);
        }
        return msg;
    }
    template <>
    ApollotaskManagerTaskManagerConfig from_json<ApollotaskManagerTaskManagerConfig>(nlohmann::json obj){
        return from_json_ApollotaskManagerTaskManagerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollotaskManagerTaskManagerConfig &dt)
    {
        dt=from_json_ApollotaskManagerTaskManagerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollotaskManagerTaskManagerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotaskManagerTaskManagerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
