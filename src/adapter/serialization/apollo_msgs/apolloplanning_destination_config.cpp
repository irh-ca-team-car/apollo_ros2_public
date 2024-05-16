#include "adapter/serialization/apollo_msgs/apolloplanning_destination_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDestinationConfig &msg) {
        nlohmann::json obj;
        obj["stopdistance"] = (msg.stopdistance);
        return obj;
    }
    ApolloplanningDestinationConfig from_json_ApolloplanningDestinationConfig (nlohmann::json obj) {
        ApolloplanningDestinationConfig msg;
        if(obj.contains("stopdistance"))
        {
            msg.stopdistance = (obj["stopdistance"].is_string()?atof(obj["stopdistance"].get<std::string>().c_str()):obj["stopdistance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningDestinationConfig from_json<ApolloplanningDestinationConfig>(nlohmann::json obj){
        return from_json_ApolloplanningDestinationConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDestinationConfig &dt)
    {
        dt=from_json_ApolloplanningDestinationConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDestinationConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDestinationConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
