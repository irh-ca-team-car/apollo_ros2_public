#include "adapter/serialization/apollo_msgs/apolloplanning_main_cruise.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainCruise &msg) {
        nlohmann::json obj;
        obj["changelanetype"] = (msg.changelanetype);
        return obj;
    }
    ApolloplanningMainCruise from_json_ApolloplanningMainCruise (nlohmann::json obj) {
        ApolloplanningMainCruise msg;
        if(obj.contains("changelanetype"))
        {
            msg.changelanetype = (obj["changelanetype"].is_string()?atoi(obj["changelanetype"].get<std::string>().c_str()):obj["changelanetype"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloplanningMainCruise from_json<ApolloplanningMainCruise>(nlohmann::json obj){
        return from_json_ApolloplanningMainCruise(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainCruise &dt)
    {
        dt=from_json_ApolloplanningMainCruise(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainCruise & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainCruise & dt)
    {
        os << to_json(dt);
        return os;
    }
}
