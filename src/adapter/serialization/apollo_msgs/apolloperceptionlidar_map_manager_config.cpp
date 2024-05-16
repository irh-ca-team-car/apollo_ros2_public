#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_map_manager_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMapManagerConfig &msg) {
        nlohmann::json obj;
        obj["updatepose"] = (msg.updatepose);
        obj["roisearchdistance"] = (msg.roisearchdistance);
        obj["lanerange"] = (msg.lanerange);
        obj["maxdepth"] = (msg.maxdepth);
        return obj;
    }
    ApolloperceptionlidarMapManagerConfig from_json_ApolloperceptionlidarMapManagerConfig (nlohmann::json obj) {
        ApolloperceptionlidarMapManagerConfig msg;
        if(obj.contains("updatepose"))
        {
            msg.updatepose = (obj["updatepose"].is_string()?(bool)atoi(obj["updatepose"].get<std::string>().c_str()):obj["updatepose"].get<bool>());
        }
        if(obj.contains("roisearchdistance"))
        {
            msg.roisearchdistance = (obj["roisearchdistance"].is_string()?atof(obj["roisearchdistance"].get<std::string>().c_str()):obj["roisearchdistance"].get<double>());
        }
        if(obj.contains("lanerange"))
        {
            msg.lanerange = (obj["lanerange"].is_string()?atof(obj["lanerange"].get<std::string>().c_str()):obj["lanerange"].get<double>());
        }
        if(obj.contains("maxdepth"))
        {
            msg.maxdepth = (obj["maxdepth"].is_string()?atof(obj["maxdepth"].get<std::string>().c_str()):obj["maxdepth"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarMapManagerConfig from_json<ApolloperceptionlidarMapManagerConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarMapManagerConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMapManagerConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarMapManagerConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMapManagerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMapManagerConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
