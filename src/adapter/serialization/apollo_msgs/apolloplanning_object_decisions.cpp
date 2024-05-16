#include "adapter/serialization/apollo_msgs/apolloplanning_object_decisions.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectDecisions &msg) {
        nlohmann::json obj;
        nlohmann::json arr_decision;
        for (auto it = msg.decision.begin(); it != msg.decision.end(); ++it) {
            arr_decision.push_back(to_json(*it));
        }
        obj["decision"] = arr_decision;
        return obj;
    }
    ApolloplanningObjectDecisions from_json_ApolloplanningObjectDecisions (nlohmann::json obj) {
        ApolloplanningObjectDecisions msg;
        if(obj.contains("decision"))
        {
            if(obj["decision"].is_array())
            {
                for (auto& element : obj["decision"])
                {
                    msg.decision.push_back(from_json_ApolloplanningObjectDecision(element));
                }
            }
            else
            {
                msg.decision.push_back(from_json_ApolloplanningObjectDecision(obj["decision"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningObjectDecisions from_json<ApolloplanningObjectDecisions>(nlohmann::json obj){
        return from_json_ApolloplanningObjectDecisions(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectDecisions &dt)
    {
        dt=from_json_ApolloplanningObjectDecisions(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectDecisions & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectDecisions & dt)
    {
        os << to_json(dt);
        return os;
    }
}
