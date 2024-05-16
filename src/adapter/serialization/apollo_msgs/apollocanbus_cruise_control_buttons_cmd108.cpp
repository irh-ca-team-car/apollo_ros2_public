#include "adapter/serialization/apollo_msgs/apollocanbus_cruise_control_buttons_cmd108.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusCruiseControlButtonsCmd108 &msg) {
        nlohmann::json obj;
        obj["cruisecontrolbutton"] = (msg.cruisecontrolbutton);
        obj["ignoreoverrides"] = (msg.ignoreoverrides);
        obj["clearoverride"] = (msg.clearoverride);
        obj["enable"] = (msg.enable);
        obj["clearfaults"] = (msg.clearfaults);
        return obj;
    }
    ApollocanbusCruiseControlButtonsCmd108 from_json_ApollocanbusCruiseControlButtonsCmd108 (nlohmann::json obj) {
        ApollocanbusCruiseControlButtonsCmd108 msg;
        if(obj.contains("cruisecontrolbutton"))
        {
            msg.cruisecontrolbutton = (obj["cruisecontrolbutton"].is_string()?atoi(obj["cruisecontrolbutton"].get<std::string>().c_str()):obj["cruisecontrolbutton"].get<int>());
        }
        if(obj.contains("ignoreoverrides"))
        {
            msg.ignoreoverrides = (obj["ignoreoverrides"].is_string()?(bool)atoi(obj["ignoreoverrides"].get<std::string>().c_str()):obj["ignoreoverrides"].get<bool>());
        }
        if(obj.contains("clearoverride"))
        {
            msg.clearoverride = (obj["clearoverride"].is_string()?(bool)atoi(obj["clearoverride"].get<std::string>().c_str()):obj["clearoverride"].get<bool>());
        }
        if(obj.contains("enable"))
        {
            msg.enable = (obj["enable"].is_string()?(bool)atoi(obj["enable"].get<std::string>().c_str()):obj["enable"].get<bool>());
        }
        if(obj.contains("clearfaults"))
        {
            msg.clearfaults = (obj["clearfaults"].is_string()?(bool)atoi(obj["clearfaults"].get<std::string>().c_str()):obj["clearfaults"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusCruiseControlButtonsCmd108 from_json<ApollocanbusCruiseControlButtonsCmd108>(nlohmann::json obj){
        return from_json_ApollocanbusCruiseControlButtonsCmd108(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusCruiseControlButtonsCmd108 &dt)
    {
        dt=from_json_ApollocanbusCruiseControlButtonsCmd108(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusCruiseControlButtonsCmd108 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusCruiseControlButtonsCmd108 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
