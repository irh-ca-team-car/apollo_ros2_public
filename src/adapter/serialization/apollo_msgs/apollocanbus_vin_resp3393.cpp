#include "adapter/serialization/apollo_msgs/apollocanbus_vin_resp3393.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVinResp3393 &msg) {
        nlohmann::json obj;
        obj["vin16"] = (msg.vin16);
        return obj;
    }
    ApollocanbusVinResp3393 from_json_ApollocanbusVinResp3393 (nlohmann::json obj) {
        ApollocanbusVinResp3393 msg;
        if(obj.contains("vin16"))
        {
            msg.vin16 = (obj["vin16"].is_string()?atoi(obj["vin16"].get<std::string>().c_str()):obj["vin16"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVinResp3393 from_json<ApollocanbusVinResp3393>(nlohmann::json obj){
        return from_json_ApollocanbusVinResp3393(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVinResp3393 &dt)
    {
        dt=from_json_ApollocanbusVinResp3393(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVinResp3393 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVinResp3393 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
