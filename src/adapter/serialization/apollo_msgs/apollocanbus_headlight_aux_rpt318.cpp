#include "adapter/serialization/apollo_msgs/apollocanbus_headlight_aux_rpt318.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusHeadlightAuxRpt318 &msg) {
        nlohmann::json obj;
        obj["headlightsmodeisvalid"] = (msg.headlightsmodeisvalid);
        obj["headlightsmode"] = (msg.headlightsmode);
        obj["foglightsonisvalid"] = (msg.foglightsonisvalid);
        obj["foglightson"] = (msg.foglightson);
        obj["headlightsonbrightisvalid"] = (msg.headlightsonbrightisvalid);
        obj["headlightsonbright"] = (msg.headlightsonbright);
        obj["headlightsonisvalid"] = (msg.headlightsonisvalid);
        obj["headlightson"] = (msg.headlightson);
        return obj;
    }
    ApollocanbusHeadlightAuxRpt318 from_json_ApollocanbusHeadlightAuxRpt318 (nlohmann::json obj) {
        ApollocanbusHeadlightAuxRpt318 msg;
        if(obj.contains("headlightsmodeisvalid"))
        {
            msg.headlightsmodeisvalid = (obj["headlightsmodeisvalid"].is_string()?(bool)atoi(obj["headlightsmodeisvalid"].get<std::string>().c_str()):obj["headlightsmodeisvalid"].get<bool>());
        }
        if(obj.contains("headlightsmode"))
        {
            msg.headlightsmode = (obj["headlightsmode"].is_string()?atoi(obj["headlightsmode"].get<std::string>().c_str()):obj["headlightsmode"].get<int>());
        }
        if(obj.contains("foglightsonisvalid"))
        {
            msg.foglightsonisvalid = (obj["foglightsonisvalid"].is_string()?(bool)atoi(obj["foglightsonisvalid"].get<std::string>().c_str()):obj["foglightsonisvalid"].get<bool>());
        }
        if(obj.contains("foglightson"))
        {
            msg.foglightson = (obj["foglightson"].is_string()?(bool)atoi(obj["foglightson"].get<std::string>().c_str()):obj["foglightson"].get<bool>());
        }
        if(obj.contains("headlightsonbrightisvalid"))
        {
            msg.headlightsonbrightisvalid = (obj["headlightsonbrightisvalid"].is_string()?(bool)atoi(obj["headlightsonbrightisvalid"].get<std::string>().c_str()):obj["headlightsonbrightisvalid"].get<bool>());
        }
        if(obj.contains("headlightsonbright"))
        {
            msg.headlightsonbright = (obj["headlightsonbright"].is_string()?(bool)atoi(obj["headlightsonbright"].get<std::string>().c_str()):obj["headlightsonbright"].get<bool>());
        }
        if(obj.contains("headlightsonisvalid"))
        {
            msg.headlightsonisvalid = (obj["headlightsonisvalid"].is_string()?(bool)atoi(obj["headlightsonisvalid"].get<std::string>().c_str()):obj["headlightsonisvalid"].get<bool>());
        }
        if(obj.contains("headlightson"))
        {
            msg.headlightson = (obj["headlightson"].is_string()?(bool)atoi(obj["headlightson"].get<std::string>().c_str()):obj["headlightson"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusHeadlightAuxRpt318 from_json<ApollocanbusHeadlightAuxRpt318>(nlohmann::json obj){
        return from_json_ApollocanbusHeadlightAuxRpt318(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusHeadlightAuxRpt318 &dt)
    {
        dt=from_json_ApollocanbusHeadlightAuxRpt318(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusHeadlightAuxRpt318 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusHeadlightAuxRpt318 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
