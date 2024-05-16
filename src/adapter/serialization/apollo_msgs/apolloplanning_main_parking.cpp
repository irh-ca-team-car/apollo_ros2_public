#include "adapter/serialization/apollo_msgs/apolloplanning_main_parking.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainParking &msg) {
        nlohmann::json obj;
        obj["status"] = (msg.status);
        return obj;
    }
    ApolloplanningMainParking from_json_ApolloplanningMainParking (nlohmann::json obj) {
        ApolloplanningMainParking msg;
        if(obj.contains("status"))
        {
            msg.status = (obj["status"].is_string()?atoi(obj["status"].get<std::string>().c_str()):obj["status"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningMainParking from_json<ApolloplanningMainParking>(nlohmann::json obj){
        return from_json_ApolloplanningMainParking(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainParking &dt)
    {
        dt=from_json_ApolloplanningMainParking(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainParking & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainParking & dt)
    {
        os << to_json(dt);
        return os;
    }
}
