#include "adapter/serialization/apollo_msgs/apollotask_manager_cycle_routing_task.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollotaskManagerCycleRoutingTask &msg) {
        nlohmann::json obj;
        obj["cyclenum"] = (msg.cyclenum);
        obj["routingrequest"] = to_json(msg.routingrequest);
        return obj;
    }
    ApollotaskManagerCycleRoutingTask from_json_ApollotaskManagerCycleRoutingTask (nlohmann::json obj) {
        ApollotaskManagerCycleRoutingTask msg;
        if(obj.contains("cyclenum"))
        {
            msg.cyclenum = (obj["cyclenum"].is_string()?atoi(obj["cyclenum"].get<std::string>().c_str()):obj["cyclenum"].get<int>());
        }
        if(obj.contains("routingrequest"))
        {
            msg.routingrequest = from_json_ApolloroutingRoutingRequest(obj["routingrequest"]);
        }
        return msg;
    }
    template <>
    ApollotaskManagerCycleRoutingTask from_json<ApollotaskManagerCycleRoutingTask>(nlohmann::json obj){
        return from_json_ApollotaskManagerCycleRoutingTask(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollotaskManagerCycleRoutingTask &dt)
    {
        dt=from_json_ApollotaskManagerCycleRoutingTask(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollotaskManagerCycleRoutingTask & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollotaskManagerCycleRoutingTask & dt)
    {
        os << to_json(dt);
        return os;
    }
}
