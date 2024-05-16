#include "adapter/serialization/apollo_msgs/apolloplanning_shift_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningShiftConfig &msg) {
        nlohmann::json obj;
        obj["maxspeed"] = (msg.maxspeed);
        obj["maxmovedestlaneshifty"] = (msg.maxmovedestlaneshifty);
        return obj;
    }
    ApolloplanningShiftConfig from_json_ApolloplanningShiftConfig (nlohmann::json obj) {
        ApolloplanningShiftConfig msg;
        if(obj.contains("maxspeed"))
        {
            msg.maxspeed = (obj["maxspeed"].is_string()?atof(obj["maxspeed"].get<std::string>().c_str()):obj["maxspeed"].get<double>());
        }
        if(obj.contains("maxmovedestlaneshifty"))
        {
            msg.maxmovedestlaneshifty = (obj["maxmovedestlaneshifty"].is_string()?atof(obj["maxmovedestlaneshifty"].get<std::string>().c_str()):obj["maxmovedestlaneshifty"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningShiftConfig from_json<ApolloplanningShiftConfig>(nlohmann::json obj){
        return from_json_ApolloplanningShiftConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningShiftConfig &dt)
    {
        dt=from_json_ApolloplanningShiftConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningShiftConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningShiftConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
