#include "adapter/serialization/apollo_msgs/apolloprediction_scenario.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionScenario &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        obj["junctionid"] = (msg.junctionid);
        return obj;
    }
    ApollopredictionScenario from_json_ApollopredictionScenario (nlohmann::json obj) {
        ApollopredictionScenario msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("junctionid"))
        {
            msg.junctionid = (obj["junctionid"].is_string()?(obj["junctionid"].get<std::string>().c_str()):obj["junctionid"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollopredictionScenario from_json<ApollopredictionScenario>(nlohmann::json obj){
        return from_json_ApollopredictionScenario(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionScenario &dt)
    {
        dt=from_json_ApollopredictionScenario(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionScenario & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionScenario & dt)
    {
        os << to_json(dt);
        return os;
    }
}
