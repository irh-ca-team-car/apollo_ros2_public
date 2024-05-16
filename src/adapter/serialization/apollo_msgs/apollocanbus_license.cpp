#include "adapter/serialization/apollo_msgs/apollocanbus_license.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLicense &msg) {
        nlohmann::json obj;
        obj["vin"] = (msg.vin);
        return obj;
    }
    ApollocanbusLicense from_json_ApollocanbusLicense (nlohmann::json obj) {
        ApollocanbusLicense msg;
        if(obj.contains("vin"))
        {
            msg.vin = (obj["vin"].is_string()?(obj["vin"].get<std::string>().c_str()):obj["vin"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollocanbusLicense from_json<ApollocanbusLicense>(nlohmann::json obj){
        return from_json_ApollocanbusLicense(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLicense &dt)
    {
        dt=from_json_ApollocanbusLicense(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLicense & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLicense & dt)
    {
        os << to_json(dt);
        return os;
    }
}
