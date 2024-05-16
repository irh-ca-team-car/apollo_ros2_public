#include "adapter/serialization/apollo_msgs/apollocanbus_component_rpt20.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusComponentRpt20 &msg) {
        nlohmann::json obj;
        obj["componenttype"] = (msg.componenttype);
        obj["componentfunc"] = (msg.componentfunc);
        obj["counter"] = (msg.counter);
        obj["complement"] = (msg.complement);
        obj["configfault"] = (msg.configfault);
        return obj;
    }
    ApollocanbusComponentRpt20 from_json_ApollocanbusComponentRpt20 (nlohmann::json obj) {
        ApollocanbusComponentRpt20 msg;
        if(obj.contains("componenttype"))
        {
            msg.componenttype = (obj["componenttype"].is_string()?atoi(obj["componenttype"].get<std::string>().c_str()):obj["componenttype"].get<int>());
        }
        if(obj.contains("componentfunc"))
        {
            msg.componentfunc = (obj["componentfunc"].is_string()?atoi(obj["componentfunc"].get<std::string>().c_str()):obj["componentfunc"].get<int>());
        }
        if(obj.contains("counter"))
        {
            msg.counter = (obj["counter"].is_string()?atoi(obj["counter"].get<std::string>().c_str()):obj["counter"].get<int>());
        }
        if(obj.contains("complement"))
        {
            msg.complement = (obj["complement"].is_string()?atoi(obj["complement"].get<std::string>().c_str()):obj["complement"].get<int>());
        }
        if(obj.contains("configfault"))
        {
            msg.configfault = (obj["configfault"].is_string()?(bool)atoi(obj["configfault"].get<std::string>().c_str()):obj["configfault"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusComponentRpt20 from_json<ApollocanbusComponentRpt20>(nlohmann::json obj){
        return from_json_ApollocanbusComponentRpt20(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusComponentRpt20 &dt)
    {
        dt=from_json_ApollocanbusComponentRpt20(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusComponentRpt20 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusComponentRpt20 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
