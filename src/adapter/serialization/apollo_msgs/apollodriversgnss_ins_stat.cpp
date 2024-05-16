#include "adapter/serialization/apollo_msgs/apollodriversgnss_ins_stat.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssInsStat &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["insstatus"] = (msg.insstatus);
        obj["postype"] = (msg.postype);
        return obj;
    }
    ApollodriversgnssInsStat from_json_ApollodriversgnssInsStat (nlohmann::json obj) {
        ApollodriversgnssInsStat msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("insstatus"))
        {
            msg.insstatus = (obj["insstatus"].is_string()?atoi(obj["insstatus"].get<std::string>().c_str()):obj["insstatus"].get<uint32_t>());
        }
        if(obj.contains("postype"))
        {
            msg.postype = (obj["postype"].is_string()?atoi(obj["postype"].get<std::string>().c_str()):obj["postype"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssInsStat from_json<ApollodriversgnssInsStat>(nlohmann::json obj){
        return from_json_ApollodriversgnssInsStat(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssInsStat &dt)
    {
        dt=from_json_ApollodriversgnssInsStat(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssInsStat & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssInsStat & dt)
    {
        os << to_json(dt);
        return os;
    }
}
