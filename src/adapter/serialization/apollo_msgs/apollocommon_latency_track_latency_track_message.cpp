#include "adapter/serialization/apollo_msgs/apollocommon_latency_track_latency_track_message.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyTrackLatencyTrackMessage &msg) {
        nlohmann::json obj;
        obj["latencyname"] = (msg.latencyname);
        obj["latencystat"] = to_json(msg.latencystat);
        return obj;
    }
    ApollocommonLatencyTrackLatencyTrackMessage from_json_ApollocommonLatencyTrackLatencyTrackMessage (nlohmann::json obj) {
        ApollocommonLatencyTrackLatencyTrackMessage msg;
        if(obj.contains("latencyname"))
        {
            msg.latencyname = (obj["latencyname"].is_string()?(obj["latencyname"].get<std::string>().c_str()):obj["latencyname"].get<std::string>());
        }
        if(obj.contains("latencystat"))
        {
            msg.latencystat = from_json_ApollocommonLatencyStat(obj["latencystat"]);
        }
        return msg;
    }
    template <>
    ApollocommonLatencyTrackLatencyTrackMessage from_json<ApollocommonLatencyTrackLatencyTrackMessage>(nlohmann::json obj){
        return from_json_ApollocommonLatencyTrackLatencyTrackMessage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyTrackLatencyTrackMessage &dt)
    {
        dt=from_json_ApollocommonLatencyTrackLatencyTrackMessage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyTrackLatencyTrackMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyTrackLatencyTrackMessage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
