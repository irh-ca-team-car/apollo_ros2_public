#include "adapter/serialization/apollo_msgs/apollostorytelling_close_to_junction.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingCloseToJunction &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["type"] = (msg.type);
        obj["distance"] = (msg.distance);
        return obj;
    }
    ApollostorytellingCloseToJunction from_json_ApollostorytellingCloseToJunction (nlohmann::json obj) {
        ApollostorytellingCloseToJunction msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("distance"))
        {
            msg.distance = (obj["distance"].is_string()?atof(obj["distance"].get<std::string>().c_str()):obj["distance"].get<double>());
        }
        return msg;
    }
    template <>
    ApollostorytellingCloseToJunction from_json<ApollostorytellingCloseToJunction>(nlohmann::json obj){
        return from_json_ApollostorytellingCloseToJunction(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingCloseToJunction &dt)
    {
        dt=from_json_ApollostorytellingCloseToJunction(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingCloseToJunction & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingCloseToJunction & dt)
    {
        os << to_json(dt);
        return os;
    }
}
