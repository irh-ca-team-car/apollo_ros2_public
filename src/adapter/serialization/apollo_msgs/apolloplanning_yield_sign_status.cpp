#include "adapter/serialization/apollo_msgs/apolloplanning_yield_sign_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningYieldSignStatus &msg) {
        nlohmann::json obj;
        nlohmann::json arr_currentyieldsignoverlapid;
        for (auto it = msg.currentyieldsignoverlapid.begin(); it != msg.currentyieldsignoverlapid.end(); ++it) {
            arr_currentyieldsignoverlapid.push_back((*it));
        }
        obj["currentyieldsignoverlapid"] = arr_currentyieldsignoverlapid;
        nlohmann::json arr_doneyieldsignoverlapid;
        for (auto it = msg.doneyieldsignoverlapid.begin(); it != msg.doneyieldsignoverlapid.end(); ++it) {
            arr_doneyieldsignoverlapid.push_back((*it));
        }
        obj["doneyieldsignoverlapid"] = arr_doneyieldsignoverlapid;
        nlohmann::json arr_waitforobstacleid;
        for (auto it = msg.waitforobstacleid.begin(); it != msg.waitforobstacleid.end(); ++it) {
            arr_waitforobstacleid.push_back((*it));
        }
        obj["waitforobstacleid"] = arr_waitforobstacleid;
        return obj;
    }
    ApolloplanningYieldSignStatus from_json_ApolloplanningYieldSignStatus (nlohmann::json obj) {
        ApolloplanningYieldSignStatus msg;
        if(obj.contains("currentyieldsignoverlapid"))
        {
            if(obj["currentyieldsignoverlapid"].is_array())
            {
                for (auto& element : obj["currentyieldsignoverlapid"])
                {
                    msg.currentyieldsignoverlapid.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.currentyieldsignoverlapid.push_back((obj["currentyieldsignoverlapid"].is_string()?(obj["currentyieldsignoverlapid"].get<std::string>().c_str()):obj["currentyieldsignoverlapid"].get<std::string>()));
            }
        }
        if(obj.contains("doneyieldsignoverlapid"))
        {
            if(obj["doneyieldsignoverlapid"].is_array())
            {
                for (auto& element : obj["doneyieldsignoverlapid"])
                {
                    msg.doneyieldsignoverlapid.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.doneyieldsignoverlapid.push_back((obj["doneyieldsignoverlapid"].is_string()?(obj["doneyieldsignoverlapid"].get<std::string>().c_str()):obj["doneyieldsignoverlapid"].get<std::string>()));
            }
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
    ApolloplanningYieldSignStatus from_json<ApolloplanningYieldSignStatus>(nlohmann::json obj){
        return from_json_ApolloplanningYieldSignStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningYieldSignStatus &dt)
    {
        dt=from_json_ApolloplanningYieldSignStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningYieldSignStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningYieldSignStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
