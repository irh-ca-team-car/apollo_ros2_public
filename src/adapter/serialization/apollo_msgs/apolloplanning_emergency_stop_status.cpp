#include "adapter/serialization/apollo_msgs/apolloplanning_emergency_stop_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningEmergencyStopStatus &msg) {
        nlohmann::json obj;
        obj["stopfencepoint"] = to_json(msg.stopfencepoint);
        return obj;
    }
    ApolloplanningEmergencyStopStatus from_json_ApolloplanningEmergencyStopStatus (nlohmann::json obj) {
        ApolloplanningEmergencyStopStatus msg;
        if(obj.contains("stopfencepoint"))
        {
            msg.stopfencepoint = from_json_ApollocommonPointENU(obj["stopfencepoint"]);
        }
        return msg;
    }
    template <>
    ApolloplanningEmergencyStopStatus from_json<ApolloplanningEmergencyStopStatus>(nlohmann::json obj){
        return from_json_ApolloplanningEmergencyStopStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningEmergencyStopStatus &dt)
    {
        dt=from_json_ApolloplanningEmergencyStopStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningEmergencyStopStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningEmergencyStopStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
