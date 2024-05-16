#include "adapter/serialization/apollo_msgs/apolloplanning_main_stop.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainStop &msg) {
        nlohmann::json obj;
        obj["reasoncode"] = (msg.reasoncode);
        obj["reason"] = (msg.reason);
        obj["stoppoint"] = to_json(msg.stoppoint);
        obj["stopheading"] = (msg.stopheading);
        obj["changelanetype"] = (msg.changelanetype);
        return obj;
    }
    ApolloplanningMainStop from_json_ApolloplanningMainStop (nlohmann::json obj) {
        ApolloplanningMainStop msg;
        if(obj.contains("reasoncode"))
        {
            msg.reasoncode = (obj["reasoncode"].is_string()?atoi(obj["reasoncode"].get<std::string>().c_str()):obj["reasoncode"].get<int>());
        }
        if(obj.contains("reason"))
        {
            msg.reason = (obj["reason"].is_string()?(obj["reason"].get<std::string>().c_str()):obj["reason"].get<std::string>());
        }
        if(obj.contains("stoppoint"))
        {
            msg.stoppoint = from_json_ApollocommonPointENU(obj["stoppoint"]);
        }
        if(obj.contains("stopheading"))
        {
            msg.stopheading = (obj["stopheading"].is_string()?atof(obj["stopheading"].get<std::string>().c_str()):obj["stopheading"].get<double>());
        }
        if(obj.contains("changelanetype"))
        {
            msg.changelanetype = (obj["changelanetype"].is_string()?atoi(obj["changelanetype"].get<std::string>().c_str()):obj["changelanetype"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningMainStop from_json<ApolloplanningMainStop>(nlohmann::json obj){
        return from_json_ApolloplanningMainStop(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainStop &dt)
    {
        dt=from_json_ApolloplanningMainStop(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainStop & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainStop & dt)
    {
        os << to_json(dt);
        return os;
    }
}
