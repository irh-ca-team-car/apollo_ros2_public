#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_streamtype.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStreamtype &msg) {
        nlohmann::json obj;
        obj["serial"] = (msg.serial);
        obj["tcp"] = (msg.tcp);
        obj["udp"] = (msg.udp);
        obj["ntrip"] = (msg.ntrip);
        return obj;
    }
    ApollodriversgnssconfigStreamtype from_json_ApollodriversgnssconfigStreamtype (nlohmann::json obj) {
        ApollodriversgnssconfigStreamtype msg;
        if(obj.contains("serial"))
        {
            msg.serial = (obj["serial"].is_string()?atoi(obj["serial"].get<std::string>().c_str()):obj["serial"].get<int>());
        }
        if(obj.contains("tcp"))
        {
            msg.tcp = (obj["tcp"].is_string()?atoi(obj["tcp"].get<std::string>().c_str()):obj["tcp"].get<int>());
        }
        if(obj.contains("udp"))
        {
            msg.udp = (obj["udp"].is_string()?atoi(obj["udp"].get<std::string>().c_str()):obj["udp"].get<int>());
        }
        if(obj.contains("ntrip"))
        {
            msg.ntrip = (obj["ntrip"].is_string()?atoi(obj["ntrip"].get<std::string>().c_str()):obj["ntrip"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssconfigStreamtype from_json<ApollodriversgnssconfigStreamtype>(nlohmann::json obj){
        return from_json_ApollodriversgnssconfigStreamtype(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStreamtype &dt)
    {
        dt=from_json_ApollodriversgnssconfigStreamtype(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStreamtype & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStreamtype & dt)
    {
        os << to_json(dt);
        return os;
    }
}
