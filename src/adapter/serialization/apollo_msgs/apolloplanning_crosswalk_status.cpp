#include "adapter/serialization/apollo_msgs/apolloplanning_crosswalk_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningCrosswalkStatus &msg) {
        nlohmann::json obj;
        obj["crosswalkid"] = (msg.crosswalkid);
        nlohmann::json arr_stoptime;
        for (auto it = msg.stoptime.begin(); it != msg.stoptime.end(); ++it) {
            arr_stoptime.push_back(to_json(*it));
        }
        obj["stoptime"] = arr_stoptime;
        nlohmann::json arr_finishedcrosswalk;
        for (auto it = msg.finishedcrosswalk.begin(); it != msg.finishedcrosswalk.end(); ++it) {
            arr_finishedcrosswalk.push_back((*it));
        }
        obj["finishedcrosswalk"] = arr_finishedcrosswalk;
        return obj;
    }
    ApolloplanningCrosswalkStatus from_json_ApolloplanningCrosswalkStatus (nlohmann::json obj) {
        ApolloplanningCrosswalkStatus msg;
        if(obj.contains("crosswalkid"))
        {
            msg.crosswalkid = (obj["crosswalkid"].is_string()?(obj["crosswalkid"].get<std::string>().c_str()):obj["crosswalkid"].get<std::string>());
        }
        if(obj.contains("stoptime"))
        {
            if(obj["stoptime"].is_array())
            {
                for (auto& element : obj["stoptime"])
                {
                    msg.stoptime.push_back(from_json_ApolloplanningStopTime(element));
                }
            }
            else
            {
                msg.stoptime.push_back(from_json_ApolloplanningStopTime(obj["stoptime"]));
            }
        }
        if(obj.contains("finishedcrosswalk"))
        {
            if(obj["finishedcrosswalk"].is_array())
            {
                for (auto& element : obj["finishedcrosswalk"])
                {
                    msg.finishedcrosswalk.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.finishedcrosswalk.push_back((obj["finishedcrosswalk"].is_string()?(obj["finishedcrosswalk"].get<std::string>().c_str()):obj["finishedcrosswalk"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningCrosswalkStatus from_json<ApolloplanningCrosswalkStatus>(nlohmann::json obj){
        return from_json_ApolloplanningCrosswalkStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningCrosswalkStatus &dt)
    {
        dt=from_json_ApolloplanningCrosswalkStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningCrosswalkStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningCrosswalkStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
