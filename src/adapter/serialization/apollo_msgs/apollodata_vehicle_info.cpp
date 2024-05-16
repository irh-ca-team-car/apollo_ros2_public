#include "adapter/serialization/apollo_msgs/apollodata_vehicle_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodataVehicleInfo &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["brand"] = (msg.brand);
        obj["model"] = (msg.model);
        obj["license"] = to_json(msg.license);
        obj["canbusconf"] = to_json(msg.canbusconf);
        obj["vehicleconfig"] = to_json(msg.vehicleconfig);
        obj["controlconfig"] = to_json(msg.controlconfig);
        return obj;
    }
    ApollodataVehicleInfo from_json_ApollodataVehicleInfo (nlohmann::json obj) {
        ApollodataVehicleInfo msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("brand"))
        {
            msg.brand = (obj["brand"].is_string()?atoi(obj["brand"].get<std::string>().c_str()):obj["brand"].get<int>());
        }
        if(obj.contains("model"))
        {
            msg.model = (obj["model"].is_string()?atoi(obj["model"].get<std::string>().c_str()):obj["model"].get<int>());
        }
        if(obj.contains("license"))
        {
            msg.license = from_json_ApollocanbusLicense(obj["license"]);
        }
        if(obj.contains("canbusconf"))
        {
            msg.canbusconf = from_json_ApollocanbusCanbusConf(obj["canbusconf"]);
        }
        if(obj.contains("vehicleconfig"))
        {
            msg.vehicleconfig = from_json_ApollocommonVehicleConfig(obj["vehicleconfig"]);
        }
        if(obj.contains("controlconfig"))
        {
            msg.controlconfig = from_json_ApollocontrolControlConf(obj["controlconfig"]);
        }
        return msg;
    }
    template <>
    ApollodataVehicleInfo from_json<ApollodataVehicleInfo>(nlohmann::json obj){
        return from_json_ApollodataVehicleInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodataVehicleInfo &dt)
    {
        dt=from_json_ApollodataVehicleInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodataVehicleInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodataVehicleInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
