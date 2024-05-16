#include "modules/perception/onboard/internal_messages/vehicle_struct.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::CarLight;
    nlohmann::json to_json(const CarLight &msg)
    {
        nlohmann::json j;

        j["brake_visible"] = msg.brake_visible;
        j["brake_switch_on"] = msg.brake_switch_on;
        j["left_turn_visible"] = msg.left_turn_visible;
        j["left_turn_switch_on"] = msg.left_turn_switch_on;
        j["right_turn_visible"] = msg.right_turn_visible;
        j["right_turn_switch_on"] = msg.right_turn_switch_on;

        return j;
    }
    CarLight from_json_CarLight(nlohmann::json obj)
    {
        CarLight d;
        
        if (obj.contains("brake_visible"))
            d.brake_visible = (obj["brake_visible"].is_string()?atof(obj["brake_visible"].get<std::string>().c_str()):obj["brake_visible"].get<float>());
        if (obj.contains("brake_switch_on"))
            d.brake_switch_on = (obj["brake_switch_on"].is_string()?atof(obj["brake_switch_on"].get<std::string>().c_str()):obj["brake_switch_on"].get<float>());
        if (obj.contains("left_turn_visible"))
            d.left_turn_visible = (obj["left_turn_visible"].is_string()?atof(obj["left_turn_visible"].get<std::string>().c_str()):obj["left_turn_visible"].get<float>());
        if (obj.contains("left_turn_switch_on"))
            d.left_turn_switch_on = (obj["left_turn_switch_on"].is_string()?atof(obj["left_turn_switch_on"].get<std::string>().c_str()):obj["left_turn_switch_on"].get<float>());
        if (obj.contains("right_turn_visible"))
            d.right_turn_visible = (obj["right_turn_visible"].is_string()?atof(obj["right_turn_visible"].get<std::string>().c_str()):obj["right_turn_visible"].get<float>());
        if (obj.contains("right_turn_switch_on"))
            d.right_turn_switch_on = (obj["right_turn_switch_on"].is_string()?atof(obj["right_turn_switch_on"].get<std::string>().c_str()):obj["right_turn_switch_on"].get<float>());
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, CarLight &dt)
    {
        dt = from_json_CarLight(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const CarLight &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const CarLight &dt)
    {
        return os << to_json(dt).dump();
    }
}
