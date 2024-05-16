#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream_ntrip.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStreamNtrip &msg) {
        nlohmann::json obj;
        obj["address"] = to_json(msg.address);
        obj["port"] = (msg.port);
        obj["mountpoint"] = to_json(msg.mountpoint);
        obj["user"] = to_json(msg.user);
        obj["password"] = to_json(msg.password);
        obj["timeouts"] = (msg.timeouts);
        return obj;
    }
    ApollodriversgnssconfigStreamNtrip from_json_ApollodriversgnssconfigStreamNtrip (nlohmann::json obj) {
        ApollodriversgnssconfigStreamNtrip msg;
        if(obj.contains("address"))
        {
            msg.address = from_json_Bytes(obj["address"]);
        }
        if(obj.contains("port"))
        {
            msg.port = (obj["port"].is_string()?atoi(obj["port"].get<std::string>().c_str()):obj["port"].get<int>());
        }
        if(obj.contains("mountpoint"))
        {
            msg.mountpoint = from_json_Bytes(obj["mountpoint"]);
        }
        if(obj.contains("user"))
        {
            msg.user = from_json_Bytes(obj["user"]);
        }
        if(obj.contains("password"))
        {
            msg.password = from_json_Bytes(obj["password"]);
        }
        if(obj.contains("timeouts"))
        {
            msg.timeouts = (obj["timeouts"].is_string()?atoi(obj["timeouts"].get<std::string>().c_str()):obj["timeouts"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssconfigStreamNtrip from_json<ApollodriversgnssconfigStreamNtrip>(nlohmann::json obj){
        return from_json_ApollodriversgnssconfigStreamNtrip(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStreamNtrip &dt)
    {
        dt=from_json_ApollodriversgnssconfigStreamNtrip(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStreamNtrip & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStreamNtrip & dt)
    {
        os << to_json(dt);
        return os;
    }
}
