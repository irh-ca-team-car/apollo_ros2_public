#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream_serial.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigStreamSerial &msg) {
        nlohmann::json obj;
        obj["device"] = to_json(msg.device);
        obj["baudrate"] = (msg.baudrate);
        return obj;
    }
    ApollodriversgnssconfigStreamSerial from_json_ApollodriversgnssconfigStreamSerial (nlohmann::json obj) {
        ApollodriversgnssconfigStreamSerial msg;
        if(obj.contains("device"))
        {
            msg.device = from_json_Bytes(obj["device"]);
        }
        if(obj.contains("baudrate"))
        {
            msg.baudrate = (obj["baudrate"].is_string()?atoi(obj["baudrate"].get<std::string>().c_str()):obj["baudrate"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssconfigStreamSerial from_json<ApollodriversgnssconfigStreamSerial>(nlohmann::json obj){
        return from_json_ApollodriversgnssconfigStreamSerial(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigStreamSerial &dt)
    {
        dt=from_json_ApollodriversgnssconfigStreamSerial(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigStreamSerial & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigStreamSerial & dt)
    {
        os << to_json(dt);
        return os;
    }
}
