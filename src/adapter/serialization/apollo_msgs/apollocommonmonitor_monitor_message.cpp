#include "adapter/serialization/apollo_msgs/apollocommonmonitor_monitor_message.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonmonitorMonitorMessage &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_item;
        for (auto it = msg.item.begin(); it != msg.item.end(); ++it) {
            arr_item.push_back(to_json(*it));
        }
        obj["item"] = arr_item;
        return obj;
    }
    ApollocommonmonitorMonitorMessage from_json_ApollocommonmonitorMonitorMessage (nlohmann::json obj) {
        ApollocommonmonitorMonitorMessage msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("item"))
        {
            if(obj["item"].is_array())
            {
                for (auto& element : obj["item"])
                {
                    msg.item.push_back(from_json_ApollocommonmonitorMonitorMessageItem(element));
                }
            }
            else
            {
                msg.item.push_back(from_json_ApollocommonmonitorMonitorMessageItem(obj["item"]));
            }
        }
        return msg;
    }
    template <>
    ApollocommonmonitorMonitorMessage from_json<ApollocommonmonitorMonitorMessage>(nlohmann::json obj){
        return from_json_ApollocommonmonitorMonitorMessage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonmonitorMonitorMessage &dt)
    {
        dt=from_json_ApollocommonmonitorMonitorMessage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonmonitorMonitorMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonmonitorMonitorMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
