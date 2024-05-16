#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_kalman_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraomtKalmanParam &msg) {
        nlohmann::json obj;
        obj["initvariance"] = (msg.initvariance);
        obj["processvariance"] = (msg.processvariance);
        obj["measurevariance"] = (msg.measurevariance);
        return obj;
    }
    ApolloperceptioncameraomtKalmanParam from_json_ApolloperceptioncameraomtKalmanParam (nlohmann::json obj) {
        ApolloperceptioncameraomtKalmanParam msg;
        if(obj.contains("initvariance"))
        {
            msg.initvariance = (obj["initvariance"].is_string()?(float)atof(obj["initvariance"].get<std::string>().c_str()):obj["initvariance"].get<float>());
        }
        if(obj.contains("processvariance"))
        {
            msg.processvariance = (obj["processvariance"].is_string()?(float)atof(obj["processvariance"].get<std::string>().c_str()):obj["processvariance"].get<float>());
        }
        if(obj.contains("measurevariance"))
        {
            msg.measurevariance = (obj["measurevariance"].is_string()?(float)atof(obj["measurevariance"].get<std::string>().c_str()):obj["measurevariance"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraomtKalmanParam from_json<ApolloperceptioncameraomtKalmanParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraomtKalmanParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraomtKalmanParam &dt)
    {
        dt=from_json_ApolloperceptioncameraomtKalmanParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraomtKalmanParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraomtKalmanParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
