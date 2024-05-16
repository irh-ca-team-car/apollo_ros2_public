#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_nm401.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuNm401 &msg) {
        nlohmann::json obj;
        obj["vcusleepcommand"] = (msg.vcusleepcommand);
        return obj;
    }
    ApollocanbusVcuNm401 from_json_ApollocanbusVcuNm401 (nlohmann::json obj) {
        ApollocanbusVcuNm401 msg;
        if(obj.contains("vcusleepcommand"))
        {
            msg.vcusleepcommand = (obj["vcusleepcommand"].is_string()?(bool)atoi(obj["vcusleepcommand"].get<std::string>().c_str()):obj["vcusleepcommand"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusVcuNm401 from_json<ApollocanbusVcuNm401>(nlohmann::json obj){
        return from_json_ApollocanbusVcuNm401(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuNm401 &dt)
    {
        dt=from_json_ApollocanbusVcuNm401(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuNm401 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuNm401 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
