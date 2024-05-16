#include "adapter/serialization/apollo_msgs/apolloplanning_decision_result.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningDecisionResult &msg) {
        nlohmann::json obj;
        obj["maindecision"] = to_json(msg.maindecision);
        obj["objectdecision"] = to_json(msg.objectdecision);
        obj["vehiclesignal"] = to_json(msg.vehiclesignal);
        return obj;
    }
    ApolloplanningDecisionResult from_json_ApolloplanningDecisionResult (nlohmann::json obj) {
        ApolloplanningDecisionResult msg;
        if(obj.contains("maindecision"))
        {
            msg.maindecision = from_json_ApolloplanningMainDecision(obj["maindecision"]);
        }
        if(obj.contains("objectdecision"))
        {
            msg.objectdecision = from_json_ApolloplanningObjectDecisions(obj["objectdecision"]);
        }
        if(obj.contains("vehiclesignal"))
        {
            msg.vehiclesignal = from_json_ApollocommonVehicleSignal(obj["vehiclesignal"]);
        }
        return msg;
    }
    template <>
    ApolloplanningDecisionResult from_json<ApolloplanningDecisionResult>(nlohmann::json obj){
        return from_json_ApolloplanningDecisionResult(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningDecisionResult &dt)
    {
        dt=from_json_ApolloplanningDecisionResult(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningDecisionResult & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningDecisionResult & dt)
    {
        os << to_json(dt);
        return os;
    }
}
