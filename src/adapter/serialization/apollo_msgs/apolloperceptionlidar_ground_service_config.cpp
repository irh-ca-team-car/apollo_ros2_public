#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_ground_service_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarGroundServiceConfig &msg) {
        nlohmann::json obj;
        obj["roiradx"] = (msg.roiradx);
        obj["roirady"] = (msg.roirady);
        obj["gridsize"] = (msg.gridsize);
        return obj;
    }
    ApolloperceptionlidarGroundServiceConfig from_json_ApolloperceptionlidarGroundServiceConfig (nlohmann::json obj) {
        ApolloperceptionlidarGroundServiceConfig msg;
        if(obj.contains("roiradx"))
        {
            msg.roiradx = (obj["roiradx"].is_string()?atof(obj["roiradx"].get<std::string>().c_str()):obj["roiradx"].get<double>());
        }
        if(obj.contains("roirady"))
        {
            msg.roirady = (obj["roirady"].is_string()?atof(obj["roirady"].get<std::string>().c_str()):obj["roirady"].get<double>());
        }
        if(obj.contains("gridsize"))
        {
            msg.gridsize = (obj["gridsize"].is_string()?atoi(obj["gridsize"].get<std::string>().c_str()):obj["gridsize"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarGroundServiceConfig from_json<ApolloperceptionlidarGroundServiceConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarGroundServiceConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarGroundServiceConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarGroundServiceConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarGroundServiceConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarGroundServiceConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
