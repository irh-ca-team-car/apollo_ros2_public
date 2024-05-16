#include "adapter/serialization/apollo_msgs/apolloplanning_stats_group.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStatsGroup &msg) {
        nlohmann::json obj;
        obj["max"] = (msg.max);
        obj["min"] = (msg.min);
        obj["sum"] = (msg.sum);
        obj["avg"] = (msg.avg);
        obj["num"] = (msg.num);
        return obj;
    }
    ApolloplanningStatsGroup from_json_ApolloplanningStatsGroup (nlohmann::json obj) {
        ApolloplanningStatsGroup msg;
        if(obj.contains("max"))
        {
            msg.max = (obj["max"].is_string()?atof(obj["max"].get<std::string>().c_str()):obj["max"].get<double>());
        }
        if(obj.contains("min"))
        {
            msg.min = (obj["min"].is_string()?atof(obj["min"].get<std::string>().c_str()):obj["min"].get<double>());
        }
        if(obj.contains("sum"))
        {
            msg.sum = (obj["sum"].is_string()?atof(obj["sum"].get<std::string>().c_str()):obj["sum"].get<double>());
        }
        if(obj.contains("avg"))
        {
            msg.avg = (obj["avg"].is_string()?atof(obj["avg"].get<std::string>().c_str()):obj["avg"].get<double>());
        }
        if(obj.contains("num"))
        {
            msg.num = (obj["num"].is_string()?atoi(obj["num"].get<std::string>().c_str()):obj["num"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningStatsGroup from_json<ApolloplanningStatsGroup>(nlohmann::json obj){
        return from_json_ApolloplanningStatsGroup(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStatsGroup &dt)
    {
        dt=from_json_ApolloplanningStatsGroup(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStatsGroup & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStatsGroup & dt)
    {
        os << to_json(dt);
        return os;
    }
}
