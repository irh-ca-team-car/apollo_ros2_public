#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_crosswalk.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToCrosswalk &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["distance"] = (msg.distance);
        return obj;
    }
    ApollostorytellingCloseToCrosswalk from_json_ApollostorytellingCloseToCrosswalk (nlohmann::json obj) {
        ApollostorytellingCloseToCrosswalk msg;
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
    ApollostorytellingCloseToCrosswalk from_json<ApollostorytellingCloseToCrosswalk>(nlohmann::json obj){
        return from_json_ApollostorytellingCloseToCrosswalk(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToCrosswalk &dt)
    {
        dt=from_json_ApollostorytellingCloseToCrosswalk(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToCrosswalk & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToCrosswalk & dt)
    {
        os << to_json(dt);
        return os;
    }
}
