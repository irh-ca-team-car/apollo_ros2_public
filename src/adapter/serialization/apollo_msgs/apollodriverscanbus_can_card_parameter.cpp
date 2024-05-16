#include "adapter/serialization/apollo_msgs/apollodriverscanbus_can_card_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscanbusCANCardParameter &msg) {
        nlohmann::json obj;
        obj["brand"] = (msg.brand);
        obj["type"] = (msg.type);
        obj["channelid"] = (msg.channelid);
        obj["interface"] = (msg.interface);
        obj["numports"] = (msg.numports);
        return obj;
    }
    ApollodriverscanbusCANCardParameter from_json_ApollodriverscanbusCANCardParameter (nlohmann::json obj) {
        ApollodriverscanbusCANCardParameter msg;
        if(obj.contains("brand"))
        {
            msg.brand = (obj["brand"].is_string()?atoi(obj["brand"].get<std::string>().c_str()):obj["brand"].get<int>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("channelid"))
        {
            msg.channelid = (obj["channelid"].is_string()?atoi(obj["channelid"].get<std::string>().c_str()):obj["channelid"].get<int>());
        }
        if(obj.contains("interface"))
        {
            msg.interface = (obj["interface"].is_string()?atoi(obj["interface"].get<std::string>().c_str()):obj["interface"].get<int>());
        }
        if(obj.contains("numports"))
        {
            msg.numports = (obj["numports"].is_string()?atoi(obj["numports"].get<std::string>().c_str()):obj["numports"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriverscanbusCANCardParameter from_json<ApollodriverscanbusCANCardParameter>(nlohmann::json obj){
        return from_json_ApollodriverscanbusCANCardParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscanbusCANCardParameter &dt)
    {
        dt=from_json_ApollodriverscanbusCANCardParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriverscanbusCANCardParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscanbusCANCardParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
