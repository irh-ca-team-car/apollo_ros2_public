#include "adapter/serialization/apollo_msgs/apolloplanning_traffic_light_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrafficLightStatus &msg) {
        nlohmann::json obj;
        nlohmann::json arr_currenttrafficlightoverlapid;
        for (auto it = msg.currenttrafficlightoverlapid.begin(); it != msg.currenttrafficlightoverlapid.end(); ++it) {
            arr_currenttrafficlightoverlapid.push_back((*it));
        }
        obj["currenttrafficlightoverlapid"] = arr_currenttrafficlightoverlapid;
        nlohmann::json arr_donetrafficlightoverlapid;
        for (auto it = msg.donetrafficlightoverlapid.begin(); it != msg.donetrafficlightoverlapid.end(); ++it) {
            arr_donetrafficlightoverlapid.push_back((*it));
        }
        obj["donetrafficlightoverlapid"] = arr_donetrafficlightoverlapid;
        return obj;
    }
    ApolloplanningTrafficLightStatus from_json_ApolloplanningTrafficLightStatus (nlohmann::json obj) {
        ApolloplanningTrafficLightStatus msg;
        if(obj.contains("currenttrafficlightoverlapid"))
        {
            if(obj["currenttrafficlightoverlapid"].is_array())
            {
                for (auto& element : obj["currenttrafficlightoverlapid"])
                {
                    msg.currenttrafficlightoverlapid.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.currenttrafficlightoverlapid.push_back((obj["currenttrafficlightoverlapid"].is_string()?(obj["currenttrafficlightoverlapid"].get<std::string>().c_str()):obj["currenttrafficlightoverlapid"].get<std::string>()));
            }
        }
        if(obj.contains("donetrafficlightoverlapid"))
        {
            if(obj["donetrafficlightoverlapid"].is_array())
            {
                for (auto& element : obj["donetrafficlightoverlapid"])
                {
                    msg.donetrafficlightoverlapid.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.donetrafficlightoverlapid.push_back((obj["donetrafficlightoverlapid"].is_string()?(obj["donetrafficlightoverlapid"].get<std::string>().c_str()):obj["donetrafficlightoverlapid"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningTrafficLightStatus from_json<ApolloplanningTrafficLightStatus>(nlohmann::json obj){
        return from_json_ApolloplanningTrafficLightStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrafficLightStatus &dt)
    {
        dt=from_json_ApolloplanningTrafficLightStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrafficLightStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrafficLightStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
