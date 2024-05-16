#include "adapter/serialization/apollo_msgs/apolloplanning_bare_intersection_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningBareIntersectionStatus &msg) {
        nlohmann::json obj;
        obj["currentpncjunctionoverlapid"] = (msg.currentpncjunctionoverlapid);
        obj["donepncjunctionoverlapid"] = (msg.donepncjunctionoverlapid);
        obj["clearcounter"] = (msg.clearcounter);
        return obj;
    }
    ApolloplanningBareIntersectionStatus from_json_ApolloplanningBareIntersectionStatus (nlohmann::json obj) {
        ApolloplanningBareIntersectionStatus msg;
        if(obj.contains("currentpncjunctionoverlapid"))
        {
            msg.currentpncjunctionoverlapid = (obj["currentpncjunctionoverlapid"].is_string()?(obj["currentpncjunctionoverlapid"].get<std::string>().c_str()):obj["currentpncjunctionoverlapid"].get<std::string>());
        }
        if(obj.contains("donepncjunctionoverlapid"))
        {
            msg.donepncjunctionoverlapid = (obj["donepncjunctionoverlapid"].is_string()?(obj["donepncjunctionoverlapid"].get<std::string>().c_str()):obj["donepncjunctionoverlapid"].get<std::string>());
        }
        if(obj.contains("clearcounter"))
        {
            msg.clearcounter = (obj["clearcounter"].is_string()?atoi(obj["clearcounter"].get<std::string>().c_str()):obj["clearcounter"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloplanningBareIntersectionStatus from_json<ApolloplanningBareIntersectionStatus>(nlohmann::json obj){
        return from_json_ApolloplanningBareIntersectionStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningBareIntersectionStatus &dt)
    {
        dt=from_json_ApolloplanningBareIntersectionStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningBareIntersectionStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningBareIntersectionStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
