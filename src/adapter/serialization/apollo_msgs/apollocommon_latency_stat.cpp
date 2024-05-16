#include "adapter/serialization/apollo_msgs/apollocommon_latency_stat.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyStat &msg) {
        nlohmann::json obj;
        obj["minduration"] = (msg.minduration);
        obj["maxduration"] = (msg.maxduration);
        obj["averduration"] = (msg.averduration);
        obj["samplesize"] = (msg.samplesize);
        return obj;
    }
    ApollocommonLatencyStat from_json_ApollocommonLatencyStat (nlohmann::json obj) {
        ApollocommonLatencyStat msg;
        if(obj.contains("minduration"))
        {
            msg.minduration = (obj["minduration"].is_string()?atol(obj["minduration"].get<std::string>().c_str()):obj["minduration"].get<uint64_t>());
        }
        if(obj.contains("maxduration"))
        {
            msg.maxduration = (obj["maxduration"].is_string()?atol(obj["maxduration"].get<std::string>().c_str()):obj["maxduration"].get<uint64_t>());
        }
        if(obj.contains("averduration"))
        {
            msg.averduration = (obj["averduration"].is_string()?atol(obj["averduration"].get<std::string>().c_str()):obj["averduration"].get<uint64_t>());
        }
        if(obj.contains("samplesize"))
        {
            msg.samplesize = (obj["samplesize"].is_string()?atoi(obj["samplesize"].get<std::string>().c_str()):obj["samplesize"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollocommonLatencyStat from_json<ApollocommonLatencyStat>(nlohmann::json obj){
        return from_json_ApollocommonLatencyStat(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyStat &dt)
    {
        dt=from_json_ApollocommonLatencyStat(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyStat & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyStat & dt)
    {
        os << to_json(dt);
        return os;
    }
}
