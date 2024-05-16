#include "adapter/serialization/apollo_msgs/apollocanbus_park_report504.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusParkReport504 &msg) {
        nlohmann::json obj;
        obj["parkingactual"] = (msg.parkingactual);
        obj["parkflt"] = (msg.parkflt);
        return obj;
    }
    ApollocanbusParkReport504 from_json_ApollocanbusParkReport504 (nlohmann::json obj) {
        ApollocanbusParkReport504 msg;
        if(obj.contains("parkingactual"))
        {
            msg.parkingactual = (obj["parkingactual"].is_string()?atoi(obj["parkingactual"].get<std::string>().c_str()):obj["parkingactual"].get<int>());
        }
        if(obj.contains("parkflt"))
        {
            msg.parkflt = (obj["parkflt"].is_string()?atoi(obj["parkflt"].get<std::string>().c_str()):obj["parkflt"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusParkReport504 from_json<ApollocanbusParkReport504>(nlohmann::json obj){
        return from_json_ApollocanbusParkReport504(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusParkReport504 &dt)
    {
        dt=from_json_ApollocanbusParkReport504(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusParkReport504 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusParkReport504 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
