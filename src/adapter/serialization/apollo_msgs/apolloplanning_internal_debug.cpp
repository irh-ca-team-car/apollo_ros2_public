#include "adapter/serialization/apollo_msgs/apolloplanning_internal_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalDebug &msg) {
        nlohmann::json obj;
        obj["planningdata"] = to_json(msg.planningdata);
        return obj;
    }
    ApolloplanningInternalDebug from_json_ApolloplanningInternalDebug (nlohmann::json obj) {
        ApolloplanningInternalDebug msg;
        if(obj.contains("planningdata"))
        {
            msg.planningdata = from_json_ApolloplanningInternalPlanningData(obj["planningdata"]);
        }
        return msg;
    }
    template <>
    ApolloplanningInternalDebug from_json<ApolloplanningInternalDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalDebug &dt)
    {
        dt=from_json_ApolloplanningInternalDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
