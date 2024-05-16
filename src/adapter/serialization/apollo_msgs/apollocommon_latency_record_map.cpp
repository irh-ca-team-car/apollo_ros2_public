#include "adapter/serialization/apollo_msgs/apollocommon_latency_record_map.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonLatencyRecordMap &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["modulename"] = (msg.modulename);
        nlohmann::json arr_latencyrecords;
        for (auto it = msg.latencyrecords.begin(); it != msg.latencyrecords.end(); ++it) {
            arr_latencyrecords.push_back(to_json(*it));
        }
        obj["latencyrecords"] = arr_latencyrecords;
        return obj;
    }
    ApollocommonLatencyRecordMap from_json_ApollocommonLatencyRecordMap (nlohmann::json obj) {
        ApollocommonLatencyRecordMap msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("modulename"))
        {
            msg.modulename = (obj["modulename"].is_string()?(obj["modulename"].get<std::string>().c_str()):obj["modulename"].get<std::string>());
        }
        if(obj.contains("latencyrecords"))
        {
            if(obj["latencyrecords"].is_array())
            {
                for (auto& element : obj["latencyrecords"])
                {
                    msg.latencyrecords.push_back(from_json_ApollocommonLatencyRecord(element));
                }
            }
            else
            {
                msg.latencyrecords.push_back(from_json_ApollocommonLatencyRecord(obj["latencyrecords"]));
            }
        }
        return msg;
    }
    template <>
    ApollocommonLatencyRecordMap from_json<ApollocommonLatencyRecordMap>(nlohmann::json obj){
        return from_json_ApollocommonLatencyRecordMap(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonLatencyRecordMap &dt)
    {
        dt=from_json_ApollocommonLatencyRecordMap(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonLatencyRecordMap & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonLatencyRecordMap & dt)
    {
        os << to_json(dt);
        return os;
    }
}
