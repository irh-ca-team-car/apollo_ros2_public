#include "adapter/serialization/apollo_msgs/apollodrivers_esr_trackmotionpower540.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrTrackmotionpower540 &msg) {
        nlohmann::json obj;
        obj["cantxtrackrollingcount2"] = (msg.cantxtrackrollingcount2);
        obj["cantxtrackcanidgroup"] = (msg.cantxtrackcanidgroup);
        nlohmann::json arr_cantxtrackmotionpower;
        for (auto it = msg.cantxtrackmotionpower.begin(); it != msg.cantxtrackmotionpower.end(); ++it) {
            arr_cantxtrackmotionpower.push_back(to_json(*it));
        }
        obj["cantxtrackmotionpower"] = arr_cantxtrackmotionpower;
        return obj;
    }
    ApollodriversEsrTrackmotionpower540 from_json_ApollodriversEsrTrackmotionpower540 (nlohmann::json obj) {
        ApollodriversEsrTrackmotionpower540 msg;
        if(obj.contains("cantxtrackrollingcount2"))
        {
            msg.cantxtrackrollingcount2 = (obj["cantxtrackrollingcount2"].is_string()?(bool)atoi(obj["cantxtrackrollingcount2"].get<std::string>().c_str()):obj["cantxtrackrollingcount2"].get<bool>());
        }
        if(obj.contains("cantxtrackcanidgroup"))
        {
            msg.cantxtrackcanidgroup = (obj["cantxtrackcanidgroup"].is_string()?atoi(obj["cantxtrackcanidgroup"].get<std::string>().c_str()):obj["cantxtrackcanidgroup"].get<int>());
        }
        if(obj.contains("cantxtrackmotionpower"))
        {
            if(obj["cantxtrackmotionpower"].is_array())
            {
                for (auto& element : obj["cantxtrackmotionpower"])
                {
                    msg.cantxtrackmotionpower.push_back(from_json_ApollodriversMotionpower(element));
                }
            }
            else
            {
                msg.cantxtrackmotionpower.push_back(from_json_ApollodriversMotionpower(obj["cantxtrackmotionpower"]));
            }
        }
        return msg;
    }
    template <>
    ApollodriversEsrTrackmotionpower540 from_json<ApollodriversEsrTrackmotionpower540>(nlohmann::json obj){
        return from_json_ApollodriversEsrTrackmotionpower540(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrTrackmotionpower540 &dt)
    {
        dt=from_json_ApollodriversEsrTrackmotionpower540(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrTrackmotionpower540 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrTrackmotionpower540 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
