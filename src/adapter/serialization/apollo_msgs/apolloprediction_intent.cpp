#include "adapter/serialization/apollo_msgs/apolloprediction_intent.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionIntent &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        return obj;
    }
    ApollopredictionIntent from_json_ApollopredictionIntent (nlohmann::json obj) {
        ApollopredictionIntent msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        return msg;
    }
    template <>
    ApollopredictionIntent from_json<ApollopredictionIntent>(nlohmann::json obj){
        return from_json_ApollopredictionIntent(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionIntent &dt)
    {
        dt=from_json_ApollopredictionIntent(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionIntent & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionIntent & dt)
    {
        os << to_json(dt);
        return os;
    }
}
