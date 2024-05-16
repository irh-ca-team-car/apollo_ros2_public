#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_signal.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToSignal &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["distance"] = (msg.distance);
        return obj;
    }
    ApollostorytellingCloseToSignal from_json_ApollostorytellingCloseToSignal (nlohmann::json obj) {
        ApollostorytellingCloseToSignal msg;
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
    ApollostorytellingCloseToSignal from_json<ApollostorytellingCloseToSignal>(nlohmann::json obj){
        return from_json_ApollostorytellingCloseToSignal(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToSignal &dt)
    {
        dt=from_json_ApollostorytellingCloseToSignal(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToSignal & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToSignal & dt)
    {
        os << to_json(dt);
        return os;
    }
}
