#include "adapter/serialization/apollo_msgs/apollothird_party_perception_third_party_perception_device.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollothirdPartyPerceptionThirdPartyPerceptionDevice &msg) {
        nlohmann::json obj;
        obj["devicetype"] = (msg.devicetype);
        return obj;
    }
    ApollothirdPartyPerceptionThirdPartyPerceptionDevice from_json_ApollothirdPartyPerceptionThirdPartyPerceptionDevice (nlohmann::json obj) {
        ApollothirdPartyPerceptionThirdPartyPerceptionDevice msg;
        if(obj.contains("devicetype"))
        {
            msg.devicetype = (obj["devicetype"].is_string()?atoi(obj["devicetype"].get<std::string>().c_str()):obj["devicetype"].get<int>());
        }
        return msg;
    }
    template <>
    ApollothirdPartyPerceptionThirdPartyPerceptionDevice from_json<ApollothirdPartyPerceptionThirdPartyPerceptionDevice>(nlohmann::json obj){
        return from_json_ApollothirdPartyPerceptionThirdPartyPerceptionDevice(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollothirdPartyPerceptionThirdPartyPerceptionDevice &dt)
    {
        dt=from_json_ApollothirdPartyPerceptionThirdPartyPerceptionDevice(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollothirdPartyPerceptionThirdPartyPerceptionDevice & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollothirdPartyPerceptionThirdPartyPerceptionDevice & dt)
    {
        os << to_json(dt);
        return os;
    }
}
