#include "adapter/serialization/apollo_msgs/apollodata_static_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataStaticInfo &msg) {
        nlohmann::json obj;
        obj["vehicle"] = to_json(msg.vehicle);
        obj["environment"] = to_json(msg.environment);
        obj["hardware"] = to_json(msg.hardware);
        obj["software"] = to_json(msg.software);
        obj["user"] = to_json(msg.user);
        return obj;
    }
    ApollodataStaticInfo from_json_ApollodataStaticInfo (nlohmann::json obj) {
        ApollodataStaticInfo msg;
        if(obj.contains("vehicle"))
        {
            msg.vehicle = from_json_ApollodataVehicleInfo(obj["vehicle"]);
        }
        if(obj.contains("environment"))
        {
            msg.environment = from_json_ApollodataEnvironmentInfo(obj["environment"]);
        }
        if(obj.contains("hardware"))
        {
            msg.hardware = from_json_ApollodataHardwareInfo(obj["hardware"]);
        }
        if(obj.contains("software"))
        {
            msg.software = from_json_ApollodataSoftwareInfo(obj["software"]);
        }
        if(obj.contains("user"))
        {
            msg.user = from_json_ApollodataUserInfo(obj["user"]);
        }
        return msg;
    }
    template <>
    ApollodataStaticInfo from_json<ApollodataStaticInfo>(nlohmann::json obj){
        return from_json_ApollodataStaticInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataStaticInfo &dt)
    {
        dt=from_json_ApollodataStaticInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataStaticInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataStaticInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
