#include "adapter/serialization/apollo_msgs/apollocanbus_dash_controls_right_cmd110.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDashControlsRightCmd110 &msg) {
        nlohmann::json obj;
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["enable"] = (msg.enable);
        obj["clearoverride"] = (msg.clearoverride);
        obj["clearfaults"] = (msg.clearfaults);
        obj["dashcontrolsbutton"] = (msg.dashcontrolsbutton);
        return obj;
    }
    ApollocanbusDashControlsRightCmd110 from_json_ApollocanbusDashControlsRightCmd110 (nlohmann::json obj) {
        ApollocanbusDashControlsRightCmd110 msg;
        if(obj.contains("ignoreoverrides"))
        {
            msg.ignoreoverrides = (obj["ignoreoverrides"].is_string()?(bool)atoi(obj["ignoreoverrides"].get<std::string>().c_str()):obj["ignoreoverrides"].get<bool>());
        }
        if(obj.contains("enable"))
        {
            msg.enable = (obj["enable"].is_string()?(bool)atoi(obj["enable"].get<std::string>().c_str()):obj["enable"].get<bool>());
        }
        if(obj.contains("clearoverride"))
        {
            msg.clearoverride = (obj["clearoverride"].is_string()?(bool)atoi(obj["clearoverride"].get<std::string>().c_str()):obj["clearoverride"].get<bool>());
        }
        if(obj.contains("clearfaults"))
        {
            msg.clearfaults = (obj["clearfaults"].is_string()?(bool)atoi(obj["clearfaults"].get<std::string>().c_str()):obj["clearfaults"].get<bool>());
        }
        if(obj.contains("dashcontrolsbutton"))
        {
            msg.dashcontrolsbutton = (obj["dashcontrolsbutton"].is_string()?atoi(obj["dashcontrolsbutton"].get<std::string>().c_str()):obj["dashcontrolsbutton"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusDashControlsRightCmd110 from_json<ApollocanbusDashControlsRightCmd110>(nlohmann::json obj){
        return from_json_ApollocanbusDashControlsRightCmd110(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDashControlsRightCmd110 &dt)
    {
        dt=from_json_ApollocanbusDashControlsRightCmd110(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDashControlsRightCmd110 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDashControlsRightCmd110 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
