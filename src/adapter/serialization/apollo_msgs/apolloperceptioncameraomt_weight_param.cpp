#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_weight_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraomtWeightParam &msg) {
        nlohmann::json obj;
        obj["appearance"] = (msg.appearance);
        obj["motion"] = (msg.motion);
        obj["shape"] = (msg.shape);
        obj["tracklet"] = (msg.tracklet);
        obj["overlap"] = (msg.overlap);
        return obj;
    }
    ApolloperceptioncameraomtWeightParam from_json_ApolloperceptioncameraomtWeightParam (nlohmann::json obj) {
        ApolloperceptioncameraomtWeightParam msg;
        if(obj.contains("appearance"))
        {
            msg.appearance = (obj["appearance"].is_string()?(float)atof(obj["appearance"].get<std::string>().c_str()):obj["appearance"].get<float>());
        }
        if(obj.contains("motion"))
        {
            msg.motion = (obj["motion"].is_string()?(float)atof(obj["motion"].get<std::string>().c_str()):obj["motion"].get<float>());
        }
        if(obj.contains("shape"))
        {
            msg.shape = (obj["shape"].is_string()?(float)atof(obj["shape"].get<std::string>().c_str()):obj["shape"].get<float>());
        }
        if(obj.contains("tracklet"))
        {
            msg.tracklet = (obj["tracklet"].is_string()?(float)atof(obj["tracklet"].get<std::string>().c_str()):obj["tracklet"].get<float>());
        }
        if(obj.contains("overlap"))
        {
            msg.overlap = (obj["overlap"].is_string()?(float)atof(obj["overlap"].get<std::string>().c_str()):obj["overlap"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraomtWeightParam from_json<ApolloperceptioncameraomtWeightParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraomtWeightParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraomtWeightParam &dt)
    {
        dt=from_json_ApolloperceptioncameraomtWeightParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraomtWeightParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraomtWeightParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
