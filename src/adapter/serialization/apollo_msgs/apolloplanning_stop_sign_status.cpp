#include "adapter/serialization/apollo_msgs/apolloplanning_stop_sign_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningStopSignStatus &msg) {
        nlohmann::json obj;
        obj["currentstopsignoverlapid"] = (msg.currentstopsignoverlapid);
        obj["donestopsignoverlapid"] = (msg.donestopsignoverlapid);
        nlohmann::json arr_waitforobstacleid;
        for (auto it = msg.waitforobstacleid.begin(); it != msg.waitforobstacleid.end(); ++it) {
            arr_waitforobstacleid.push_back((*it));
        }
        obj["waitforobstacleid"] = arr_waitforobstacleid;
        return obj;
    }
    ApolloplanningStopSignStatus from_json_ApolloplanningStopSignStatus (nlohmann::json obj) {
        ApolloplanningStopSignStatus msg;
        if(obj.contains("currentstopsignoverlapid"))
        {
            msg.currentstopsignoverlapid = (obj["currentstopsignoverlapid"].is_string()?(obj["currentstopsignoverlapid"].get<std::string>().c_str()):obj["currentstopsignoverlapid"].get<std::string>());
        }
        if(obj.contains("donestopsignoverlapid"))
        {
            msg.donestopsignoverlapid = (obj["donestopsignoverlapid"].is_string()?(obj["donestopsignoverlapid"].get<std::string>().c_str()):obj["donestopsignoverlapid"].get<std::string>());
        }
        if(obj.contains("waitforobstacleid"))
        {
            if(obj["waitforobstacleid"].is_array())
            {
                for (auto& element : obj["waitforobstacleid"])
                {
                    msg.waitforobstacleid.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.waitforobstacleid.push_back((obj["waitforobstacleid"].is_string()?(obj["waitforobstacleid"].get<std::string>().c_str()):obj["waitforobstacleid"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningStopSignStatus from_json<ApolloplanningStopSignStatus>(nlohmann::json obj){
        return from_json_ApolloplanningStopSignStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningStopSignStatus &dt)
    {
        dt=from_json_ApolloplanningStopSignStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningStopSignStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningStopSignStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
