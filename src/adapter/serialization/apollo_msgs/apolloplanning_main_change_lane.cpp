#include "adapter/serialization/apollo_msgs/apolloplanning_main_change_lane.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainChangeLane &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        nlohmann::json arr_defaultlane;
        for (auto it = msg.defaultlane.begin(); it != msg.defaultlane.end(); ++it) {
            arr_defaultlane.push_back(to_json(*it));
        }
        obj["defaultlane"] = arr_defaultlane;
        obj["defaultlanestop"] = to_json(msg.defaultlanestop);
        obj["targetlanestop"] = to_json(msg.targetlanestop);
        return obj;
    }
    ApolloplanningMainChangeLane from_json_ApolloplanningMainChangeLane (nlohmann::json obj) {
        ApolloplanningMainChangeLane msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("defaultlane"))
        {
            if(obj["defaultlane"].is_array())
            {
                for (auto& element : obj["defaultlane"])
                {
                    msg.defaultlane.push_back(from_json_ApolloplanningTargetLane(element));
                }
            }
            else
            {
                msg.defaultlane.push_back(from_json_ApolloplanningTargetLane(obj["defaultlane"]));
            }
        }
        if(obj.contains("defaultlanestop"))
        {
            msg.defaultlanestop = from_json_ApolloplanningMainStop(obj["defaultlanestop"]);
        }
        if(obj.contains("targetlanestop"))
        {
            msg.targetlanestop = from_json_ApolloplanningMainStop(obj["targetlanestop"]);
        }
        return msg;
    }
    template <>
    ApolloplanningMainChangeLane from_json<ApolloplanningMainChangeLane>(nlohmann::json obj){
        return from_json_ApolloplanningMainChangeLane(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainChangeLane &dt)
    {
        dt=from_json_ApolloplanningMainChangeLane(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainChangeLane & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainChangeLane & dt)
    {
        os << to_json(dt);
        return os;
    }
}
