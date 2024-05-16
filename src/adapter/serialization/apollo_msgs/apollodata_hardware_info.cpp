#include "adapter/serialization/apollo_msgs/apollodata_hardware_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataHardwareInfo &msg) {
        nlohmann::json obj;
        nlohmann::json arr_configs;
        for (auto it = msg.configs.begin(); it != msg.configs.end(); ++it) {
            arr_configs.push_back(to_json(*it));
        }
        obj["configs"] = arr_configs;
        return obj;
    }
    ApollodataHardwareInfo from_json_ApollodataHardwareInfo (nlohmann::json obj) {
        ApollodataHardwareInfo msg;
        if(obj.contains("configs"))
        {
            if(obj["configs"].is_array())
            {
                for (auto& element : obj["configs"])
                {
                    msg.configs.push_back(from_json_ApollodataHardwareInfoconfigs(element));
                }
            }
            else
            {
                msg.configs.push_back(from_json_ApollodataHardwareInfoconfigs(obj["configs"]));
            }
        }
        return msg;
    }
    template <>
    ApollodataHardwareInfo from_json<ApollodataHardwareInfo>(nlohmann::json obj){
        return from_json_ApollodataHardwareInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataHardwareInfo &dt)
    {
        dt=from_json_ApollodataHardwareInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataHardwareInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataHardwareInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
