#include "adapter/serialization/apollo_msgs/apolloplanning_latency_stats.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningLatencyStats &msg) {
        nlohmann::json obj;
        obj["totaltimems"] = (msg.totaltimems);
        nlohmann::json arr_taskstats;
        for (auto it = msg.taskstats.begin(); it != msg.taskstats.end(); ++it) {
            arr_taskstats.push_back(to_json(*it));
        }
        obj["taskstats"] = arr_taskstats;
        obj["initframetimems"] = (msg.initframetimems);
        return obj;
    }
    ApolloplanningLatencyStats from_json_ApolloplanningLatencyStats (nlohmann::json obj) {
        ApolloplanningLatencyStats msg;
        if(obj.contains("totaltimems"))
        {
            msg.totaltimems = (obj["totaltimems"].is_string()?atof(obj["totaltimems"].get<std::string>().c_str()):obj["totaltimems"].get<double>());
        }
        if(obj.contains("taskstats"))
        {
            if(obj["taskstats"].is_array())
            {
                for (auto& element : obj["taskstats"])
                {
                    msg.taskstats.push_back(from_json_ApolloplanningTaskStats(element));
                }
            }
            else
            {
                msg.taskstats.push_back(from_json_ApolloplanningTaskStats(obj["taskstats"]));
            }
        }
        if(obj.contains("initframetimems"))
        {
            msg.initframetimems = (obj["initframetimems"].is_string()?atof(obj["initframetimems"].get<std::string>().c_str()):obj["initframetimems"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningLatencyStats from_json<ApolloplanningLatencyStats>(nlohmann::json obj){
        return from_json_ApolloplanningLatencyStats(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningLatencyStats &dt)
    {
        dt=from_json_ApolloplanningLatencyStats(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningLatencyStats & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningLatencyStats & dt)
    {
        os << to_json(dt);
        return os;
    }
}
