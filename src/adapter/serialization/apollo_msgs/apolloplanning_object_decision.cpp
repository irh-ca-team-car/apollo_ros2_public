#include "adapter/serialization/apollo_msgs/apolloplanning_object_decision.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectDecision &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["perceptionid"] = (msg.perceptionid);
        nlohmann::json arr_objectdecision;
        for (auto it = msg.objectdecision.begin(); it != msg.objectdecision.end(); ++it) {
            arr_objectdecision.push_back(to_json(*it));
        }
        obj["objectdecision"] = arr_objectdecision;
        return obj;
    }
    ApolloplanningObjectDecision from_json_ApolloplanningObjectDecision (nlohmann::json obj) {
        ApolloplanningObjectDecision msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("perceptionid"))
        {
            msg.perceptionid = (obj["perceptionid"].is_string()?atoi(obj["perceptionid"].get<std::string>().c_str()):obj["perceptionid"].get<int>());
        }
        if(obj.contains("objectdecision"))
        {
            if(obj["objectdecision"].is_array())
            {
                for (auto& element : obj["objectdecision"])
                {
                    msg.objectdecision.push_back(from_json_ApolloplanningObjectDecisionType(element));
                }
            }
            else
            {
                msg.objectdecision.push_back(from_json_ApolloplanningObjectDecisionType(obj["objectdecision"]));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningObjectDecision from_json<ApolloplanningObjectDecision>(nlohmann::json obj){
        return from_json_ApolloplanningObjectDecision(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectDecision &dt)
    {
        dt=from_json_ApolloplanningObjectDecision(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectDecision & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectDecision & dt)
    {
        os << to_json(dt);
        return os;
    }
}
