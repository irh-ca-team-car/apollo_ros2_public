#include "adapter/serialization/apollo_msgs/apolloplanning_main_decision.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainDecision &msg) {
        nlohmann::json obj;
        obj["task"] = to_json(msg.task);
        nlohmann::json arr_targetlane;
        for (auto it = msg.targetlane.begin(); it != msg.targetlane.end(); ++it) {
            arr_targetlane.push_back(to_json(*it));
        }
        obj["targetlane"] = arr_targetlane;
        return obj;
    }
    ApolloplanningMainDecision from_json_ApolloplanningMainDecision (nlohmann::json obj) {
        ApolloplanningMainDecision msg;
        if(obj.contains("task"))
        {
            msg.task = from_json_ApolloplanningMainDecisiontask(obj["task"]);
        }
        if(obj.contains("targetlane"))
        {
            if(obj["targetlane"].is_array())
            {
                for (auto& element : obj["targetlane"])
                {
                    msg.targetlane.push_back(from_json_ApolloplanningTargetLane(element));
                }
            }
            else
            {
                msg.targetlane.push_back(from_json_ApolloplanningTargetLane(obj["targetlane"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningMainDecision from_json<ApolloplanningMainDecision>(nlohmann::json obj){
        return from_json_ApolloplanningMainDecision(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainDecision &dt)
    {
        dt=from_json_ApolloplanningMainDecision(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainDecision & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainDecision & dt)
    {
        os << to_json(dt);
        return os;
    }
}
