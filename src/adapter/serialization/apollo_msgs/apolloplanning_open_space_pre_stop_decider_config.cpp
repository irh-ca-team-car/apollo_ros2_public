#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_pre_stop_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpacePreStopDeciderConfig &msg) {
        nlohmann::json obj;
        obj["stoptype"] = (msg.stoptype);
        obj["rightawaystopdistance"] = (msg.rightawaystopdistance);
        obj["stopdistancetotarget"] = (msg.stopdistancetotarget);
        return obj;
    }
    ApolloplanningOpenSpacePreStopDeciderConfig from_json_ApolloplanningOpenSpacePreStopDeciderConfig (nlohmann::json obj) {
        ApolloplanningOpenSpacePreStopDeciderConfig msg;
        if(obj.contains("stoptype"))
        {
            msg.stoptype = (obj["stoptype"].is_string()?atoi(obj["stoptype"].get<std::string>().c_str()):obj["stoptype"].get<int>());
        }
        if(obj.contains("rightawaystopdistance"))
        {
            msg.rightawaystopdistance = (obj["rightawaystopdistance"].is_string()?atof(obj["rightawaystopdistance"].get<std::string>().c_str()):obj["rightawaystopdistance"].get<double>());
        }
        if(obj.contains("stopdistancetotarget"))
        {
            msg.stopdistancetotarget = (obj["stopdistancetotarget"].is_string()?atof(obj["stopdistancetotarget"].get<std::string>().c_str()):obj["stopdistancetotarget"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningOpenSpacePreStopDeciderConfig from_json<ApolloplanningOpenSpacePreStopDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningOpenSpacePreStopDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpacePreStopDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningOpenSpacePreStopDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpacePreStopDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpacePreStopDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
