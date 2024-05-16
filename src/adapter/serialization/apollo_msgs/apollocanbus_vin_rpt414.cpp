#include "adapter/serialization/apollo_msgs/apollocanbus_vin_rpt414.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVinRpt414 &msg) {
        nlohmann::json obj;
        obj["vehserial"] = (msg.vehserial);
        obj["vehmycode"] = (msg.vehmycode);
        obj["vehmfgcode"] = (msg.vehmfgcode);
        return obj;
    }
    ApollocanbusVinRpt414 from_json_ApollocanbusVinRpt414 (nlohmann::json obj) {
        ApollocanbusVinRpt414 msg;
        if(obj.contains("vehserial"))
        {
            msg.vehserial = (obj["vehserial"].is_string()?atoi(obj["vehserial"].get<std::string>().c_str()):obj["vehserial"].get<int>());
        }
        if(obj.contains("vehmycode"))
        {
            msg.vehmycode = (obj["vehmycode"].is_string()?atoi(obj["vehmycode"].get<std::string>().c_str()):obj["vehmycode"].get<int>());
        }
        if(obj.contains("vehmfgcode"))
        {
            msg.vehmfgcode = (obj["vehmfgcode"].is_string()?atoi(obj["vehmfgcode"].get<std::string>().c_str()):obj["vehmfgcode"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVinRpt414 from_json<ApollocanbusVinRpt414>(nlohmann::json obj){
        return from_json_ApollocanbusVinRpt414(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVinRpt414 &dt)
    {
        dt=from_json_ApollocanbusVinRpt414(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVinRpt414 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVinRpt414 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
