#include "adapter/serialization/apollo_msgs/apollodata_hardware_infoconfigs.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataHardwareInfoconfigs &msg) {
        nlohmann::json obj;
        obj["key"] = (msg.key);
        obj["data"] = (msg.data);
        return obj;
    }
    ApollodataHardwareInfoconfigs from_json_ApollodataHardwareInfoconfigs (nlohmann::json obj) {
        ApollodataHardwareInfoconfigs msg;
        if(obj.contains("key"))
        {
            msg.key = (obj["key"].is_string()?(obj["key"].get<std::string>().c_str()):obj["key"].get<std::string>());
        }
        if(obj.contains("data"))
        {
            msg.data = (obj["data"].is_string()?(obj["data"].get<std::string>().c_str()):obj["data"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollodataHardwareInfoconfigs from_json<ApollodataHardwareInfoconfigs>(nlohmann::json obj){
        return from_json_ApollodataHardwareInfoconfigs(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataHardwareInfoconfigs &dt)
    {
        dt=from_json_ApollodataHardwareInfoconfigs(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataHardwareInfoconfigs & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataHardwareInfoconfigs & dt)
    {
        os << to_json(dt);
        return os;
    }
}
