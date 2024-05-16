#include "adapter/serialization/apollo_msgs/apolloplanning_stop_time.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStopTime &msg) {
        nlohmann::json obj;
        obj["obstacleid"] = (msg.obstacleid);
        obj["stoptimestampsec"] = (msg.stoptimestampsec);
        return obj;
    }
    ApolloplanningStopTime from_json_ApolloplanningStopTime (nlohmann::json obj) {
        ApolloplanningStopTime msg;
        if(obj.contains("obstacleid"))
        {
            msg.obstacleid = (obj["obstacleid"].is_string()?(obj["obstacleid"].get<std::string>().c_str()):obj["obstacleid"].get<std::string>());
        }
        if(obj.contains("stoptimestampsec"))
        {
            msg.stoptimestampsec = (obj["stoptimestampsec"].is_string()?atof(obj["stoptimestampsec"].get<std::string>().c_str()):obj["stoptimestampsec"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningStopTime from_json<ApolloplanningStopTime>(nlohmann::json obj){
        return from_json_ApolloplanningStopTime(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStopTime &dt)
    {
        dt=from_json_ApolloplanningStopTime(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStopTime & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStopTime & dt)
    {
        os << to_json(dt);
        return os;
    }
}
