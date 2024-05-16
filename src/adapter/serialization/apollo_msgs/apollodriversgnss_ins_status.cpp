#include "adapter/serialization/apollo_msgs/apollodriversgnss_ins_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssInsStatus &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["type"] = (msg.type);
        return obj;
    }
    ApollodriversgnssInsStatus from_json_ApollodriversgnssInsStatus (nlohmann::json obj) {
        ApollodriversgnssInsStatus msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssInsStatus from_json<ApollodriversgnssInsStatus>(nlohmann::json obj){
        return from_json_ApollodriversgnssInsStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssInsStatus &dt)
    {
        dt=from_json_ApollodriversgnssInsStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssInsStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssInsStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
