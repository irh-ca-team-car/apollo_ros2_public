#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_yield_sign.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToYieldSign &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["distance"] = (msg.distance);
        return obj;
    }
    ApollostorytellingCloseToYieldSign from_json_ApollostorytellingCloseToYieldSign (nlohmann::json obj) {
        ApollostorytellingCloseToYieldSign msg;
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
    ApollostorytellingCloseToYieldSign from_json<ApollostorytellingCloseToYieldSign>(nlohmann::json obj){
        return from_json_ApollostorytellingCloseToYieldSign(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToYieldSign &dt)
    {
        dt=from_json_ApollostorytellingCloseToYieldSign(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToYieldSign & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToYieldSign & dt)
    {
        os << to_json(dt);
        return os;
    }
}
