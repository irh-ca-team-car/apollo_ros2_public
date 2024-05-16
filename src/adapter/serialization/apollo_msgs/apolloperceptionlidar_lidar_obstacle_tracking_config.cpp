#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_lidar_obstacle_tracking_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarLidarObstacleTrackingConfig &msg) {
        nlohmann::json obj;
        obj["multitargettracker"] = (msg.multitargettracker);
        obj["frameclassifier"] = (msg.frameclassifier);
        obj["fusionclassifier"] = (msg.fusionclassifier);
        return obj;
    }
    ApolloperceptionlidarLidarObstacleTrackingConfig from_json_ApolloperceptionlidarLidarObstacleTrackingConfig (nlohmann::json obj) {
        ApolloperceptionlidarLidarObstacleTrackingConfig msg;
        if(obj.contains("multitargettracker"))
        {
            msg.multitargettracker = (obj["multitargettracker"].is_string()?(obj["multitargettracker"].get<std::string>().c_str()):obj["multitargettracker"].get<std::string>());
        }
        if(obj.contains("frameclassifier"))
        {
            msg.frameclassifier = (obj["frameclassifier"].is_string()?(obj["frameclassifier"].get<std::string>().c_str()):obj["frameclassifier"].get<std::string>());
        }
        if(obj.contains("fusionclassifier"))
        {
            msg.fusionclassifier = (obj["fusionclassifier"].is_string()?(obj["fusionclassifier"].get<std::string>().c_str()):obj["fusionclassifier"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarLidarObstacleTrackingConfig from_json<ApolloperceptionlidarLidarObstacleTrackingConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarLidarObstacleTrackingConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarLidarObstacleTrackingConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarLidarObstacleTrackingConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarLidarObstacleTrackingConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarLidarObstacleTrackingConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
