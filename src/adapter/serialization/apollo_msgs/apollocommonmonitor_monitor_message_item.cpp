#include "adapter/serialization/apollo_msgs/apollocommonmonitor_monitor_message_item.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonmonitorMonitorMessageItem &msg) {
        nlohmann::json obj;
        obj["source"] = (msg.source);
        obj["msg"] = (msg.msg);
        obj["loglevel"] = (msg.loglevel);
        return obj;
    }
    ApollocommonmonitorMonitorMessageItem from_json_ApollocommonmonitorMonitorMessageItem (nlohmann::json obj) {
        ApollocommonmonitorMonitorMessageItem msg;
        if(obj.contains("source"))
        {
            msg.source = (obj["source"].is_string()?atoi(obj["source"].get<std::string>().c_str()):obj["source"].get<int>());
        }
        if(obj.contains("msg"))
        {
            msg.msg = (obj["msg"].is_string()?(obj["msg"].get<std::string>().c_str()):obj["msg"].get<std::string>());
        }
        if(obj.contains("loglevel"))
        {
            msg.loglevel = (obj["loglevel"].is_string()?atoi(obj["loglevel"].get<std::string>().c_str()):obj["loglevel"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocommonmonitorMonitorMessageItem from_json<ApollocommonmonitorMonitorMessageItem>(nlohmann::json obj){
        return from_json_ApollocommonmonitorMonitorMessageItem(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonmonitorMonitorMessageItem &dt)
    {
        dt=from_json_ApollocommonmonitorMonitorMessageItem(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonmonitorMonitorMessageItem & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonmonitorMonitorMessageItem & dt)
    {
        os << to_json(dt);
        return os;
    }
}
