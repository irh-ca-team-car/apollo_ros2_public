#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream_udp.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStreamUdp &msg) {
        nlohmann::json obj;
        obj["address"] = to_json(msg.address);
        obj["port"] = (msg.port);
        return obj;
    }
    ApollodriversgnssconfigStreamUdp from_json_ApollodriversgnssconfigStreamUdp (nlohmann::json obj) {
        ApollodriversgnssconfigStreamUdp msg;
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
    ApollodriversgnssconfigStreamUdp from_json<ApollodriversgnssconfigStreamUdp>(nlohmann::json obj){
        return from_json_ApollodriversgnssconfigStreamUdp(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStreamUdp &dt)
    {
        dt=from_json_ApollodriversgnssconfigStreamUdp(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStreamUdp & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStreamUdp & dt)
    {
        os << to_json(dt);
        return os;
    }
}
