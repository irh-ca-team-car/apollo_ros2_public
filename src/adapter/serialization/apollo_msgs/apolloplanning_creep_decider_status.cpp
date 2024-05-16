#include "adapter/serialization/apollo_msgs/apolloplanning_creep_decider_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCreepDeciderStatus &msg) {
        nlohmann::json obj;
        obj["creepclearcounter"] = (msg.creepclearcounter);
        return obj;
    }
    ApolloplanningCreepDeciderStatus from_json_ApolloplanningCreepDeciderStatus (nlohmann::json obj) {
        ApolloplanningCreepDeciderStatus msg;
        if(obj.contains("creepclearcounter"))
        {
            msg.creepclearcounter = (obj["creepclearcounter"].is_string()?atoi(obj["creepclearcounter"].get<std::string>().c_str()):obj["creepclearcounter"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloplanningCreepDeciderStatus from_json<ApolloplanningCreepDeciderStatus>(nlohmann::json obj){
        return from_json_ApolloplanningCreepDeciderStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCreepDeciderStatus &dt)
    {
        dt=from_json_ApolloplanningCreepDeciderStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCreepDeciderStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCreepDeciderStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
