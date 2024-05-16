#include "adapter/serialization/apollo_msgs/apollotask_manager_task.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotaskManagerTask &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["taskname"] = (msg.taskname);
        obj["tasktype"] = (msg.tasktype);
        obj["cycleroutingtask"] = to_json(msg.cycleroutingtask);
        return obj;
    }
    ApollotaskManagerTask from_json_ApollotaskManagerTask (nlohmann::json obj) {
        ApollotaskManagerTask msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("taskname"))
        {
            msg.taskname = (obj["taskname"].is_string()?(obj["taskname"].get<std::string>().c_str()):obj["taskname"].get<std::string>());
        }
        if(obj.contains("tasktype"))
        {
            msg.tasktype = (obj["tasktype"].is_string()?atoi(obj["tasktype"].get<std::string>().c_str()):obj["tasktype"].get<int>());
        }
        if(obj.contains("cycleroutingtask"))
        {
            msg.cycleroutingtask = from_json_ApollotaskManagerCycleRoutingTask(obj["cycleroutingtask"]);
        }
        return msg;
    }
    template <>
    ApollotaskManagerTask from_json<ApollotaskManagerTask>(nlohmann::json obj){
        return from_json_ApollotaskManagerTask(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollotaskManagerTask &dt)
    {
        dt=from_json_ApollotaskManagerTask(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollotaskManagerTask & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotaskManagerTask & dt)
    {
        os << to_json(dt);
        return os;
    }
}
