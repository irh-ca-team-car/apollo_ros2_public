#include "adapter/serialization/apollo_msgs/apolloplanning_task_stats.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTaskStats &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["timems"] = (msg.timems);
        return obj;
    }
    ApolloplanningTaskStats from_json_ApolloplanningTaskStats (nlohmann::json obj) {
        ApolloplanningTaskStats msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("timems"))
        {
            msg.timems = (obj["timems"].is_string()?atof(obj["timems"].get<std::string>().c_str()):obj["timems"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningTaskStats from_json<ApolloplanningTaskStats>(nlohmann::json obj){
        return from_json_ApolloplanningTaskStats(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTaskStats &dt)
    {
        dt=from_json_ApolloplanningTaskStats(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTaskStats & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTaskStats & dt)
    {
        os << to_json(dt);
        return os;
    }
}
