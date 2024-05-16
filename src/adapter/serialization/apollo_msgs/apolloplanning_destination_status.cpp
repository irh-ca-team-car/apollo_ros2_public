#include "adapter/serialization/apollo_msgs/apolloplanning_destination_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDestinationStatus &msg) {
        nlohmann::json obj;
        obj["haspasseddestination"] = (msg.haspasseddestination);
        return obj;
    }
    ApolloplanningDestinationStatus from_json_ApolloplanningDestinationStatus (nlohmann::json obj) {
        ApolloplanningDestinationStatus msg;
        if(obj.contains("haspasseddestination"))
        {
            msg.haspasseddestination = (obj["haspasseddestination"].is_string()?(bool)atoi(obj["haspasseddestination"].get<std::string>().c_str()):obj["haspasseddestination"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningDestinationStatus from_json<ApolloplanningDestinationStatus>(nlohmann::json obj){
        return from_json_ApolloplanningDestinationStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDestinationStatus &dt)
    {
        dt=from_json_ApolloplanningDestinationStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDestinationStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDestinationStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
