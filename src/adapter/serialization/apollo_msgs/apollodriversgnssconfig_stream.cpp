#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStream &msg) {
        nlohmann::json obj;
        obj["format"] = (msg.format);
        obj["type"] = to_json(msg.type);
        obj["pushlocation"] = (msg.pushlocation);
        return obj;
    }
    ApollodriversgnssconfigStream from_json_ApollodriversgnssconfigStream (nlohmann::json obj) {
        ApollodriversgnssconfigStream msg;
        if(obj.contains("format"))
        {
            msg.format = (obj["format"].is_string()?atoi(obj["format"].get<std::string>().c_str()):obj["format"].get<int>());
        }
        if(obj.contains("type"))
        {
            msg.type = from_json_ApollodriversgnssconfigStreamtype(obj["type"]);
        }
        if(obj.contains("pushlocation"))
        {
            msg.pushlocation = (obj["pushlocation"].is_string()?(bool)atoi(obj["pushlocation"].get<std::string>().c_str()):obj["pushlocation"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssconfigStream from_json<ApollodriversgnssconfigStream>(nlohmann::json obj){
        return from_json_ApollodriversgnssconfigStream(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStream &dt)
    {
        dt=from_json_ApollodriversgnssconfigStream(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStream & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStream & dt)
    {
        os << to_json(dt);
        return os;
    }
}
