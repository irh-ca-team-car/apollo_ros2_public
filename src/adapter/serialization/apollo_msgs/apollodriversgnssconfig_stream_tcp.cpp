#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream_tcp.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStreamTcp &msg) {
        nlohmann::json obj;
        obj["address"] = to_json(msg.address);
        obj["port"] = (msg.port);
        return obj;
    }
    ApollodriversgnssconfigStreamTcp from_json_ApollodriversgnssconfigStreamTcp (nlohmann::json obj) {
        ApollodriversgnssconfigStreamTcp msg;
        if(obj.contains("address"))
        {
            msg.address = from_json_Bytes(obj["address"]);
        }
        if(obj.contains("port"))
        {
            msg.port = (obj["port"].is_string()?atoi(obj["port"].get<std::string>().c_str()):obj["port"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssconfigStreamTcp from_json<ApollodriversgnssconfigStreamTcp>(nlohmann::json obj){
        return from_json_ApollodriversgnssconfigStreamTcp(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStreamTcp &dt)
    {
        dt=from_json_ApollodriversgnssconfigStreamTcp(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStreamTcp & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStreamTcp & dt)
    {
        os << to_json(dt);
        return os;
    }
}
