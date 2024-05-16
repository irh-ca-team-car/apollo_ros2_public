#include "adapter/serialization/apollo_msgs/apollocanbus_bms_report512.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusBmsReport512 &msg) {
        nlohmann::json obj;
        obj["batterycurrent"] = (msg.batterycurrent);
        obj["batteryvoltage"] = (msg.batteryvoltage);
        obj["batterysoc"] = (msg.batterysoc);
        return obj;
    }
    ApollocanbusBmsReport512 from_json_ApollocanbusBmsReport512 (nlohmann::json obj) {
        ApollocanbusBmsReport512 msg;
        if(obj.contains("batterycurrent"))
        {
            msg.batterycurrent = (obj["batterycurrent"].is_string()?atof(obj["batterycurrent"].get<std::string>().c_str()):obj["batterycurrent"].get<double>());
        }
        if(obj.contains("batteryvoltage"))
        {
            msg.batteryvoltage = (obj["batteryvoltage"].is_string()?atof(obj["batteryvoltage"].get<std::string>().c_str()):obj["batteryvoltage"].get<double>());
        }
        if(obj.contains("batterysoc"))
        {
            msg.batterysoc = (obj["batterysoc"].is_string()?atoi(obj["batterysoc"].get<std::string>().c_str()):obj["batterysoc"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusBmsReport512 from_json<ApollocanbusBmsReport512>(nlohmann::json obj){
        return from_json_ApollocanbusBmsReport512(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusBmsReport512 &dt)
    {
        dt=from_json_ApollocanbusBmsReport512(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusBmsReport512 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusBmsReport512 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
