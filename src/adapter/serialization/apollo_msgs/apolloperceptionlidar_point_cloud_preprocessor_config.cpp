#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_point_cloud_preprocessor_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarPointCloudPreprocessorConfig &msg) {
        nlohmann::json obj;
        obj["filternaninfpoints"] = (msg.filternaninfpoints);
        obj["filternearbyboxpoints"] = (msg.filternearbyboxpoints);
        obj["boxforwardx"] = (msg.boxforwardx);
        obj["boxbackwardx"] = (msg.boxbackwardx);
        obj["boxforwardy"] = (msg.boxforwardy);
        obj["boxbackwardy"] = (msg.boxbackwardy);
        obj["filterhighzpoints"] = (msg.filterhighzpoints);
        obj["zthreshold"] = (msg.zthreshold);
        return obj;
    }
    ApolloperceptionlidarPointCloudPreprocessorConfig from_json_ApolloperceptionlidarPointCloudPreprocessorConfig (nlohmann::json obj) {
        ApolloperceptionlidarPointCloudPreprocessorConfig msg;
        if(obj.contains("filternaninfpoints"))
        {
            msg.filternaninfpoints = (obj["filternaninfpoints"].is_string()?(bool)atoi(obj["filternaninfpoints"].get<std::string>().c_str()):obj["filternaninfpoints"].get<bool>());
        }
        if(obj.contains("filternearbyboxpoints"))
        {
            msg.filternearbyboxpoints = (obj["filternearbyboxpoints"].is_string()?(bool)atoi(obj["filternearbyboxpoints"].get<std::string>().c_str()):obj["filternearbyboxpoints"].get<bool>());
        }
        if(obj.contains("boxforwardx"))
        {
            msg.boxforwardx = (obj["boxforwardx"].is_string()?(float)atof(obj["boxforwardx"].get<std::string>().c_str()):obj["boxforwardx"].get<float>());
        }
        if(obj.contains("boxbackwardx"))
        {
            msg.boxbackwardx = (obj["boxbackwardx"].is_string()?(float)atof(obj["boxbackwardx"].get<std::string>().c_str()):obj["boxbackwardx"].get<float>());
        }
        if(obj.contains("boxforwardy"))
        {
            msg.boxforwardy = (obj["boxforwardy"].is_string()?(float)atof(obj["boxforwardy"].get<std::string>().c_str()):obj["boxforwardy"].get<float>());
        }
        if(obj.contains("boxbackwardy"))
        {
            msg.boxbackwardy = (obj["boxbackwardy"].is_string()?(float)atof(obj["boxbackwardy"].get<std::string>().c_str()):obj["boxbackwardy"].get<float>());
        }
        if(obj.contains("filterhighzpoints"))
        {
            msg.filterhighzpoints = (obj["filterhighzpoints"].is_string()?(bool)atoi(obj["filterhighzpoints"].get<std::string>().c_str()):obj["filterhighzpoints"].get<bool>());
        }
        if(obj.contains("zthreshold"))
        {
            msg.zthreshold = (obj["zthreshold"].is_string()?(float)atof(obj["zthreshold"].get<std::string>().c_str()):obj["zthreshold"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarPointCloudPreprocessorConfig from_json<ApolloperceptionlidarPointCloudPreprocessorConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarPointCloudPreprocessorConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarPointCloudPreprocessorConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarPointCloudPreprocessorConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarPointCloudPreprocessorConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarPointCloudPreprocessorConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
