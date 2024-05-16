#include "adapter/serialization/apollo_msgs/apolloplanning_path_decider_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathDeciderStatus &msg) {
        nlohmann::json obj;
        obj["frontstaticobstaclecyclecounter"] = (msg.frontstaticobstaclecyclecounter);
        obj["abletouseselflanecounter"] = (msg.abletouseselflanecounter);
        obj["isinpathlaneborrowscenario"] = (msg.isinpathlaneborrowscenario);
        obj["frontstaticobstacleid"] = (msg.frontstaticobstacleid);
        nlohmann::json arr_decidedsidepassdirection;
        for (auto it = msg.decidedsidepassdirection.begin(); it != msg.decidedsidepassdirection.end(); ++it) {
            arr_decidedsidepassdirection.push_back((*it));
        }
        obj["decidedsidepassdirection"] = arr_decidedsidepassdirection;
        return obj;
    }
    ApolloplanningPathDeciderStatus from_json_ApolloplanningPathDeciderStatus (nlohmann::json obj) {
        ApolloplanningPathDeciderStatus msg;
        if(obj.contains("frontstaticobstaclecyclecounter"))
        {
            msg.frontstaticobstaclecyclecounter = (obj["frontstaticobstaclecyclecounter"].is_string()?atoi(obj["frontstaticobstaclecyclecounter"].get<std::string>().c_str()):obj["frontstaticobstaclecyclecounter"].get<int>());
        }
        if(obj.contains("abletouseselflanecounter"))
        {
            msg.abletouseselflanecounter = (obj["abletouseselflanecounter"].is_string()?atoi(obj["abletouseselflanecounter"].get<std::string>().c_str()):obj["abletouseselflanecounter"].get<int>());
        }
        if(obj.contains("isinpathlaneborrowscenario"))
        {
            msg.isinpathlaneborrowscenario = (obj["isinpathlaneborrowscenario"].is_string()?(bool)atoi(obj["isinpathlaneborrowscenario"].get<std::string>().c_str()):obj["isinpathlaneborrowscenario"].get<bool>());
        }
        if(obj.contains("frontstaticobstacleid"))
        {
            msg.frontstaticobstacleid = (obj["frontstaticobstacleid"].is_string()?(obj["frontstaticobstacleid"].get<std::string>().c_str()):obj["frontstaticobstacleid"].get<std::string>());
        }
        if(obj.contains("decidedsidepassdirection"))
        {
            if(obj["decidedsidepassdirection"].is_array())
            {
                for (auto& element : obj["decidedsidepassdirection"])
                {
                    msg.decidedsidepassdirection.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.decidedsidepassdirection.push_back((obj["decidedsidepassdirection"].is_string()?atoi(obj["decidedsidepassdirection"].get<std::string>().c_str()):obj["decidedsidepassdirection"].get<int>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningPathDeciderStatus from_json<ApolloplanningPathDeciderStatus>(nlohmann::json obj){
        return from_json_ApolloplanningPathDeciderStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathDeciderStatus &dt)
    {
        dt=from_json_ApolloplanningPathDeciderStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathDeciderStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathDeciderStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
