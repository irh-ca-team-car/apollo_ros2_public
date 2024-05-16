#include "adapter/serialization/apollo_msgs/apollocanbus_vin_resp2392.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVinResp2392 &msg) {
        nlohmann::json obj;
        obj["vin15"] = (msg.vin15);
        obj["vin14"] = (msg.vin14);
        obj["vin13"] = (msg.vin13);
        obj["vin12"] = (msg.vin12);
        obj["vin11"] = (msg.vin11);
        obj["vin10"] = (msg.vin10);
        obj["vin09"] = (msg.vin09);
        obj["vin08"] = (msg.vin08);
        return obj;
    }
    ApollocanbusVinResp2392 from_json_ApollocanbusVinResp2392 (nlohmann::json obj) {
        ApollocanbusVinResp2392 msg;
        if(obj.contains("vin15"))
        {
            msg.vin15 = (obj["vin15"].is_string()?atoi(obj["vin15"].get<std::string>().c_str()):obj["vin15"].get<int>());
        }
        if(obj.contains("vin14"))
        {
            msg.vin14 = (obj["vin14"].is_string()?atoi(obj["vin14"].get<std::string>().c_str()):obj["vin14"].get<int>());
        }
        if(obj.contains("vin13"))
        {
            msg.vin13 = (obj["vin13"].is_string()?atoi(obj["vin13"].get<std::string>().c_str()):obj["vin13"].get<int>());
        }
        if(obj.contains("vin12"))
        {
            msg.vin12 = (obj["vin12"].is_string()?atoi(obj["vin12"].get<std::string>().c_str()):obj["vin12"].get<int>());
        }
        if(obj.contains("vin11"))
        {
            msg.vin11 = (obj["vin11"].is_string()?atoi(obj["vin11"].get<std::string>().c_str()):obj["vin11"].get<int>());
        }
        if(obj.contains("vin10"))
        {
            msg.vin10 = (obj["vin10"].is_string()?atoi(obj["vin10"].get<std::string>().c_str()):obj["vin10"].get<int>());
        }
        if(obj.contains("vin09"))
        {
            msg.vin09 = (obj["vin09"].is_string()?atoi(obj["vin09"].get<std::string>().c_str()):obj["vin09"].get<int>());
        }
        if(obj.contains("vin08"))
        {
            msg.vin08 = (obj["vin08"].is_string()?atoi(obj["vin08"].get<std::string>().c_str()):obj["vin08"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVinResp2392 from_json<ApollocanbusVinResp2392>(nlohmann::json obj){
        return from_json_ApollocanbusVinResp2392(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVinResp2392 &dt)
    {
        dt=from_json_ApollocanbusVinResp2392(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVinResp2392 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVinResp2392 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
