#include "adapter/serialization/apollo_msgs/apollodrivers_ultrasonic.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversUltrasonic &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_ranges;
        for (auto it = msg.ranges.begin(); it != msg.ranges.end(); ++it) {
            arr_ranges.push_back((*it));
        }
        obj["ranges"] = arr_ranges;
        return obj;
    }
    ApollodriversUltrasonic from_json_ApollodriversUltrasonic (nlohmann::json obj) {
        ApollodriversUltrasonic msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("ranges"))
        {
            if(obj["ranges"].is_array())
            {
                for (auto& element : obj["ranges"])
                {
                    msg.ranges.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.ranges.push_back((obj["ranges"].is_string()?(float)atof(obj["ranges"].get<std::string>().c_str()):obj["ranges"].get<float>()));
            }
        }
        return msg;
    }
    template <>
    ApollodriversUltrasonic from_json<ApollodriversUltrasonic>(nlohmann::json obj){
        return from_json_ApollodriversUltrasonic(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversUltrasonic &dt)
    {
        dt=from_json_ApollodriversUltrasonic(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversUltrasonic & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversUltrasonic & dt)
    {
        os << to_json(dt);
        return os;
    }
}
