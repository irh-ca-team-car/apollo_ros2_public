#include "adapter/serialization/apollo_msgs/apollocommon_latency_track.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyTrack &msg) {
        nlohmann::json obj;
        nlohmann::json arr_latencytrack;
        for (auto it = msg.latencytrack.begin(); it != msg.latencytrack.end(); ++it) {
            arr_latencytrack.push_back((*it));
        }
        obj["latencytrack"] = arr_latencytrack;
        return obj;
    }
    ApollocommonLatencyTrack from_json_ApollocommonLatencyTrack (nlohmann::json obj) {
        ApollocommonLatencyTrack msg;
        if(obj.contains("latencytrack"))
        {
            if(obj["latencytrack"].is_array())
            {
                for (auto& element : obj["latencytrack"])
                {
                    msg.latencytrack.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.latencytrack.push_back((obj["latencytrack"].is_string()?atoi(obj["latencytrack"].get<std::string>().c_str()):obj["latencytrack"].get<int>()));
            }
        }
        return msg;
    }
    template <>
    ApollocommonLatencyTrack from_json<ApollocommonLatencyTrack>(nlohmann::json obj){
        return from_json_ApollocommonLatencyTrack(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyTrack &dt)
    {
        dt=from_json_ApollocommonLatencyTrack(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyTrack & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyTrack & dt)
    {
        os << to_json(dt);
        return os;
    }
}
