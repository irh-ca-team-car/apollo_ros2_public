#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_clear_area.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToClearArea &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["distance"] = (msg.distance);
        return obj;
    }
    ApollostorytellingCloseToClearArea from_json_ApollostorytellingCloseToClearArea (nlohmann::json obj) {
        ApollostorytellingCloseToClearArea msg;
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
    ApollostorytellingCloseToClearArea from_json<ApollostorytellingCloseToClearArea>(nlohmann::json obj){
        return from_json_ApollostorytellingCloseToClearArea(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToClearArea &dt)
    {
        dt=from_json_ApollostorytellingCloseToClearArea(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToClearArea & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToClearArea & dt)
    {
        os << to_json(dt);
        return os;
    }
}
