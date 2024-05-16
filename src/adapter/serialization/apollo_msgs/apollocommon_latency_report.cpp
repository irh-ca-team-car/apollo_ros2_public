#include "adapter/serialization/apollo_msgs/apollocommon_latency_report.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyReport &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["e2eslatency"] = to_json(msg.e2eslatency);
        obj["moduleslatency"] = to_json(msg.moduleslatency);
        return obj;
    }
    ApollocommonLatencyReport from_json_ApollocommonLatencyReport (nlohmann::json obj) {
        ApollocommonLatencyReport msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("e2eslatency"))
        {
            msg.e2eslatency = from_json_ApollocommonLatencyTrack(obj["e2eslatency"]);
        }
        if(obj.contains("moduleslatency"))
        {
            msg.moduleslatency = from_json_ApollocommonLatencyTrack(obj["moduleslatency"]);
        }
        return msg;
    }
    template <>
    ApollocommonLatencyReport from_json<ApollocommonLatencyReport>(nlohmann::json obj){
        return from_json_ApollocommonLatencyReport(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyReport &dt)
    {
        dt=from_json_ApollocommonLatencyReport(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyReport & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyReport & dt)
    {
        os << to_json(dt);
        return os;
    }
}
