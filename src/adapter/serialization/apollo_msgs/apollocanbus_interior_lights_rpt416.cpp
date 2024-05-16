#include "adapter/serialization/apollo_msgs/apollocanbus_interior_lights_rpt416.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusInteriorLightsRpt416 &msg) {
        nlohmann::json obj;
        obj["dimlevelisvalid"] = (msg.dimlevelisvalid);
        obj["moodlightsonisvalid"] = (msg.moodlightsonisvalid);
        obj["reardomelightsonisvalid"] = (msg.reardomelightsonisvalid);
        obj["frontdomelightsonisvalid"] = (msg.frontdomelightsonisvalid);
        obj["dimlevel"] = (msg.dimlevel);
        obj["moodlightson"] = (msg.moodlightson);
        obj["reardomelightson"] = (msg.reardomelightson);
        obj["frontdomelightson"] = (msg.frontdomelightson);
        return obj;
    }
    ApollocanbusInteriorLightsRpt416 from_json_ApollocanbusInteriorLightsRpt416 (nlohmann::json obj) {
        ApollocanbusInteriorLightsRpt416 msg;
        if(obj.contains("dimlevelisvalid"))
        {
            msg.dimlevelisvalid = (obj["dimlevelisvalid"].is_string()?(bool)atoi(obj["dimlevelisvalid"].get<std::string>().c_str()):obj["dimlevelisvalid"].get<bool>());
        }
        if(obj.contains("moodlightsonisvalid"))
        {
            msg.moodlightsonisvalid = (obj["moodlightsonisvalid"].is_string()?(bool)atoi(obj["moodlightsonisvalid"].get<std::string>().c_str()):obj["moodlightsonisvalid"].get<bool>());
        }
        if(obj.contains("reardomelightsonisvalid"))
        {
            msg.reardomelightsonisvalid = (obj["reardomelightsonisvalid"].is_string()?(bool)atoi(obj["reardomelightsonisvalid"].get<std::string>().c_str()):obj["reardomelightsonisvalid"].get<bool>());
        }
        if(obj.contains("frontdomelightsonisvalid"))
        {
            msg.frontdomelightsonisvalid = (obj["frontdomelightsonisvalid"].is_string()?(bool)atoi(obj["frontdomelightsonisvalid"].get<std::string>().c_str()):obj["frontdomelightsonisvalid"].get<bool>());
        }
        if(obj.contains("dimlevel"))
        {
            msg.dimlevel = (obj["dimlevel"].is_string()?atoi(obj["dimlevel"].get<std::string>().c_str()):obj["dimlevel"].get<int>());
        }
        if(obj.contains("moodlightson"))
        {
            msg.moodlightson = (obj["moodlightson"].is_string()?(bool)atoi(obj["moodlightson"].get<std::string>().c_str()):obj["moodlightson"].get<bool>());
        }
        if(obj.contains("reardomelightson"))
        {
            msg.reardomelightson = (obj["reardomelightson"].is_string()?(bool)atoi(obj["reardomelightson"].get<std::string>().c_str()):obj["reardomelightson"].get<bool>());
        }
        if(obj.contains("frontdomelightson"))
        {
            msg.frontdomelightson = (obj["frontdomelightson"].is_string()?(bool)atoi(obj["frontdomelightson"].get<std::string>().c_str()):obj["frontdomelightson"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusInteriorLightsRpt416 from_json<ApollocanbusInteriorLightsRpt416>(nlohmann::json obj){
        return from_json_ApollocanbusInteriorLightsRpt416(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusInteriorLightsRpt416 &dt)
    {
        dt=from_json_ApollocanbusInteriorLightsRpt416(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusInteriorLightsRpt416 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusInteriorLightsRpt416 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
