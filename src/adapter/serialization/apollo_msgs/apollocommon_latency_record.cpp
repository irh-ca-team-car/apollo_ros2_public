#include "adapter/serialization/apollo_msgs/apollocommon_latency_record.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyRecord &msg) {
        nlohmann::json obj;
        obj["begintime"] = (msg.begintime);
        obj["endtime"] = (msg.endtime);
        obj["messageid"] = (msg.messageid);
        return obj;
    }
    ApollocommonLatencyRecord from_json_ApollocommonLatencyRecord (nlohmann::json obj) {
        ApollocommonLatencyRecord msg;
        if(obj.contains("begintime"))
        {
            msg.begintime = (obj["begintime"].is_string()?atol(obj["begintime"].get<std::string>().c_str()):obj["begintime"].get<uint64_t>());
        }
        if(obj.contains("endtime"))
        {
            msg.endtime = (obj["endtime"].is_string()?atol(obj["endtime"].get<std::string>().c_str()):obj["endtime"].get<uint64_t>());
        }
        if(obj.contains("messageid"))
        {
            msg.messageid = (obj["messageid"].is_string()?atol(obj["messageid"].get<std::string>().c_str()):obj["messageid"].get<uint64_t>());
        }
        return msg;
    }
    template <>
    ApollocommonLatencyRecord from_json<ApollocommonLatencyRecord>(nlohmann::json obj){
        return from_json_ApollocommonLatencyRecord(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyRecord &dt)
    {
        dt=from_json_ApollocommonLatencyRecord(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyRecord & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyRecord & dt)
    {
        os << to_json(dt);
        return os;
    }
}
