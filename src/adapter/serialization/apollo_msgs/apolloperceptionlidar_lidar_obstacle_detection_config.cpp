#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_lidar_obstacle_detection_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarLidarObstacleDetectionConfig &msg) {
        nlohmann::json obj;
        obj["detector"] = (msg.detector);
        obj["usemapmanager"] = (msg.usemapmanager);
        obj["useobjectfilterbank"] = (msg.useobjectfilterbank);
        return obj;
    }
    ApolloperceptionlidarLidarObstacleDetectionConfig from_json_ApolloperceptionlidarLidarObstacleDetectionConfig (nlohmann::json obj) {
        ApolloperceptionlidarLidarObstacleDetectionConfig msg;
        if(obj.contains("detector"))
        {
            msg.detector = (obj["detector"].is_string()?(obj["detector"].get<std::string>().c_str()):obj["detector"].get<std::string>());
        }
        if(obj.contains("usemapmanager"))
        {
            msg.usemapmanager = (obj["usemapmanager"].is_string()?(bool)atoi(obj["usemapmanager"].get<std::string>().c_str()):obj["usemapmanager"].get<bool>());
        }
        if(obj.contains("useobjectfilterbank"))
        {
            msg.useobjectfilterbank = (obj["useobjectfilterbank"].is_string()?(bool)atoi(obj["useobjectfilterbank"].get<std::string>().c_str()):obj["useobjectfilterbank"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarLidarObstacleDetectionConfig from_json<ApolloperceptionlidarLidarObstacleDetectionConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarLidarObstacleDetectionConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarLidarObstacleDetectionConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarLidarObstacleDetectionConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarLidarObstacleDetectionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarLidarObstacleDetectionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
