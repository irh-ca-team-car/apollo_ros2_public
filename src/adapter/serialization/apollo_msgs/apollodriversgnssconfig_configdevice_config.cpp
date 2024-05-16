#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_configdevice_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssconfigConfigdeviceConfig &msg) {
        nlohmann::json obj;
        obj["novatelconfig"] = to_json(msg.novatelconfig);
        obj["ubloxconfig"] = (msg.ubloxconfig);
        return obj;
    }
    ApollodriversgnssconfigConfigdeviceConfig from_json_ApollodriversgnssconfigConfigdeviceConfig (nlohmann::json obj) {
        ApollodriversgnssconfigConfigdeviceConfig msg;
        if(obj.contains("novatelconfig"))
        {
            msg.novatelconfig = from_json_ApollodriversgnssconfigNovatelConfig(obj["novatelconfig"]);
        }
        if(obj.contains("ubloxconfig"))
        {
            msg.ubloxconfig = (obj["ubloxconfig"].is_string()?atoi(obj["ubloxconfig"].get<std::string>().c_str()):obj["ubloxconfig"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversgnssconfigConfigdeviceConfig from_json<ApollodriversgnssconfigConfigdeviceConfig>(nlohmann::json obj){
        return from_json_ApollodriversgnssconfigConfigdeviceConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssconfigConfigdeviceConfig &dt)
    {
        dt=from_json_ApollodriversgnssconfigConfigdeviceConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssconfigConfigdeviceConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssconfigConfigdeviceConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
