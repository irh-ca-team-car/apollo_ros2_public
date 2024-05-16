#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_stop_sign.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToStopSign &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["distance"] = (msg.distance);
        return obj;
    }
    ApollostorytellingCloseToStopSign from_json_ApollostorytellingCloseToStopSign (nlohmann::json obj) {
        ApollostorytellingCloseToStopSign msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("distance"))
        {
            msg.distance = (obj["distance"].is_string()?atof(obj["distance"].get<std::string>().c_str()):obj["distance"].get<double>());
        }
        return msg;
    }
    template <>
    ApollostorytellingCloseToStopSign from_json<ApollostorytellingCloseToStopSign>(nlohmann::json obj){
        return from_json_ApollostorytellingCloseToStopSign(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToStopSign &dt)
    {
        dt=from_json_ApollostorytellingCloseToStopSign(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToStopSign & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToStopSign & dt)
    {
        os << to_json(dt);
        return os;
    }
}
