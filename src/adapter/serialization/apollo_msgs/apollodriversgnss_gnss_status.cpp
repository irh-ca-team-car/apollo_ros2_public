#include "adapter/serialization/apollo_msgs/apollodriversgnss_gnss_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssGnssStatus &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["solutioncompleted"] = (msg.solutioncompleted);
        obj["solutionstatus"] = (msg.solutionstatus);
        obj["positiontype"] = (msg.positiontype);
        obj["numsats"] = (msg.numsats);
        return obj;
    }
    ApollodriversgnssGnssStatus from_json_ApollodriversgnssGnssStatus (nlohmann::json obj) {
        ApollodriversgnssGnssStatus msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("solutioncompleted"))
        {
            msg.solutioncompleted = (obj["solutioncompleted"].is_string()?(bool)atoi(obj["solutioncompleted"].get<std::string>().c_str()):obj["solutioncompleted"].get<bool>());
        }
        if(obj.contains("solutionstatus"))
        {
            msg.solutionstatus = (obj["solutionstatus"].is_string()?atoi(obj["solutionstatus"].get<std::string>().c_str()):obj["solutionstatus"].get<uint32_t>());
        }
        if(obj.contains("positiontype"))
        {
            msg.positiontype = (obj["positiontype"].is_string()?atoi(obj["positiontype"].get<std::string>().c_str()):obj["positiontype"].get<uint32_t>());
        }
        if(obj.contains("numsats"))
        {
            msg.numsats = (obj["numsats"].is_string()?atoi(obj["numsats"].get<std::string>().c_str()):obj["numsats"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssGnssStatus from_json<ApollodriversgnssGnssStatus>(nlohmann::json obj){
        return from_json_ApollodriversgnssGnssStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssGnssStatus &dt)
    {
        dt=from_json_ApollodriversgnssGnssStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssGnssStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssGnssStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
