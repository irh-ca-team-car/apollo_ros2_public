#include "adapter/serialization/apollo_msgs/apollodrivers_motionpower.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversMotionpower &msg) {
        nlohmann::json obj;
        obj["cantxtrackmoving"] = (msg.cantxtrackmoving);
        obj["cantxtrackmovingfast"] = (msg.cantxtrackmovingfast);
        obj["cantxtrackmovingslow"] = (msg.cantxtrackmovingslow);
        obj["cantxtrackpower"] = (msg.cantxtrackpower);
        return obj;
    }
    ApollodriversMotionpower from_json_ApollodriversMotionpower (nlohmann::json obj) {
        ApollodriversMotionpower msg;
        if(obj.contains("cantxtrackmoving"))
        {
            msg.cantxtrackmoving = (obj["cantxtrackmoving"].is_string()?(bool)atoi(obj["cantxtrackmoving"].get<std::string>().c_str()):obj["cantxtrackmoving"].get<bool>());
        }
        if(obj.contains("cantxtrackmovingfast"))
        {
            msg.cantxtrackmovingfast = (obj["cantxtrackmovingfast"].is_string()?(bool)atoi(obj["cantxtrackmovingfast"].get<std::string>().c_str()):obj["cantxtrackmovingfast"].get<bool>());
        }
        if(obj.contains("cantxtrackmovingslow"))
        {
            msg.cantxtrackmovingslow = (obj["cantxtrackmovingslow"].is_string()?(bool)atoi(obj["cantxtrackmovingslow"].get<std::string>().c_str()):obj["cantxtrackmovingslow"].get<bool>());
        }
        if(obj.contains("cantxtrackpower"))
        {
            msg.cantxtrackpower = (obj["cantxtrackpower"].is_string()?atoi(obj["cantxtrackpower"].get<std::string>().c_str()):obj["cantxtrackpower"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversMotionpower from_json<ApollodriversMotionpower>(nlohmann::json obj){
        return from_json_ApollodriversMotionpower(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversMotionpower &dt)
    {
        dt=from_json_ApollodriversMotionpower(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversMotionpower & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversMotionpower & dt)
    {
        os << to_json(dt);
        return os;
    }
}
