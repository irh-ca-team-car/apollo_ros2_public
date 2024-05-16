#include "adapter/serialization/apollo_msgs/apollocanbus_rear_lights_rpt418.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusRearLightsRpt418 &msg) {
        nlohmann::json obj;
        obj["reverselightsonisvalid"] = (msg.reverselightsonisvalid);
        obj["brakelightsonisvalid"] = (msg.brakelightsonisvalid);
        obj["reverselightson"] = (msg.reverselightson);
        obj["brakelightson"] = (msg.brakelightson);
        return obj;
    }
    ApollocanbusRearLightsRpt418 from_json_ApollocanbusRearLightsRpt418 (nlohmann::json obj) {
        ApollocanbusRearLightsRpt418 msg;
        if(obj.contains("reverselightsonisvalid"))
        {
            msg.reverselightsonisvalid = (obj["reverselightsonisvalid"].is_string()?(bool)atoi(obj["reverselightsonisvalid"].get<std::string>().c_str()):obj["reverselightsonisvalid"].get<bool>());
        }
        if(obj.contains("brakelightsonisvalid"))
        {
            msg.brakelightsonisvalid = (obj["brakelightsonisvalid"].is_string()?(bool)atoi(obj["brakelightsonisvalid"].get<std::string>().c_str()):obj["brakelightsonisvalid"].get<bool>());
        }
        if(obj.contains("reverselightson"))
        {
            msg.reverselightson = (obj["reverselightson"].is_string()?(bool)atoi(obj["reverselightson"].get<std::string>().c_str()):obj["reverselightson"].get<bool>());
        }
        if(obj.contains("brakelightson"))
        {
            msg.brakelightson = (obj["brakelightson"].is_string()?(bool)atoi(obj["brakelightson"].get<std::string>().c_str()):obj["brakelightson"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusRearLightsRpt418 from_json<ApollocanbusRearLightsRpt418>(nlohmann::json obj){
        return from_json_ApollocanbusRearLightsRpt418(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusRearLightsRpt418 &dt)
    {
        dt=from_json_ApollocanbusRearLightsRpt418(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusRearLightsRpt418 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusRearLightsRpt418 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
