#include "adapter/serialization/apollo_msgs/apollocanbus_vin_resp1391.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVinResp1391 &msg) {
        nlohmann::json obj;
        obj["vin07"] = (msg.vin07);
        obj["vin06"] = (msg.vin06);
        obj["vin05"] = (msg.vin05);
        obj["vin04"] = (msg.vin04);
        obj["vin03"] = (msg.vin03);
        obj["vin02"] = (msg.vin02);
        obj["vin00"] = (msg.vin00);
        obj["vin01"] = (msg.vin01);
        return obj;
    }
    ApollocanbusVinResp1391 from_json_ApollocanbusVinResp1391 (nlohmann::json obj) {
        ApollocanbusVinResp1391 msg;
        if(obj.contains("vin07"))
        {
            msg.vin07 = (obj["vin07"].is_string()?atoi(obj["vin07"].get<std::string>().c_str()):obj["vin07"].get<int>());
        }
        if(obj.contains("vin06"))
        {
            msg.vin06 = (obj["vin06"].is_string()?atoi(obj["vin06"].get<std::string>().c_str()):obj["vin06"].get<int>());
        }
        if(obj.contains("vin05"))
        {
            msg.vin05 = (obj["vin05"].is_string()?atoi(obj["vin05"].get<std::string>().c_str()):obj["vin05"].get<int>());
        }
        if(obj.contains("vin04"))
        {
            msg.vin04 = (obj["vin04"].is_string()?atoi(obj["vin04"].get<std::string>().c_str()):obj["vin04"].get<int>());
        }
        if(obj.contains("vin03"))
        {
            msg.vin03 = (obj["vin03"].is_string()?atoi(obj["vin03"].get<std::string>().c_str()):obj["vin03"].get<int>());
        }
        if(obj.contains("vin02"))
        {
            msg.vin02 = (obj["vin02"].is_string()?atoi(obj["vin02"].get<std::string>().c_str()):obj["vin02"].get<int>());
        }
        if(obj.contains("vin00"))
        {
            msg.vin00 = (obj["vin00"].is_string()?atoi(obj["vin00"].get<std::string>().c_str()):obj["vin00"].get<int>());
        }
        if(obj.contains("vin01"))
        {
            msg.vin01 = (obj["vin01"].is_string()?atoi(obj["vin01"].get<std::string>().c_str()):obj["vin01"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVinResp1391 from_json<ApollocanbusVinResp1391>(nlohmann::json obj){
        return from_json_ApollocanbusVinResp1391(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVinResp1391 &dt)
    {
        dt=from_json_ApollocanbusVinResp1391(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVinResp1391 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVinResp1391 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
