#include "adapter/serialization/apollo_msgs/apolloperceptioncameraomt_reference_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraomtReferenceParam &msg) {
        nlohmann::json obj;
        obj["margin"] = (msg.margin);
        obj["minallowheight"] = (msg.minallowheight);
        obj["areadecay"] = (msg.areadecay);
        obj["downsampling"] = (msg.downsampling);
        obj["heightdiffratio"] = (msg.heightdiffratio);
        return obj;
    }
    ApolloperceptioncameraomtReferenceParam from_json_ApolloperceptioncameraomtReferenceParam (nlohmann::json obj) {
        ApolloperceptioncameraomtReferenceParam msg;
        if(obj.contains("margin"))
        {
            msg.margin = (obj["margin"].is_string()?atoi(obj["margin"].get<std::string>().c_str()):obj["margin"].get<int>());
        }
        if(obj.contains("minallowheight"))
        {
            msg.minallowheight = (obj["minallowheight"].is_string()?atoi(obj["minallowheight"].get<std::string>().c_str()):obj["minallowheight"].get<int>());
        }
        if(obj.contains("areadecay"))
        {
            msg.areadecay = (obj["areadecay"].is_string()?(float)atof(obj["areadecay"].get<std::string>().c_str()):obj["areadecay"].get<float>());
        }
        if(obj.contains("downsampling"))
        {
            msg.downsampling = (obj["downsampling"].is_string()?atoi(obj["downsampling"].get<std::string>().c_str()):obj["downsampling"].get<int>());
        }
        if(obj.contains("heightdiffratio"))
        {
            msg.heightdiffratio = (obj["heightdiffratio"].is_string()?(float)atof(obj["heightdiffratio"].get<std::string>().c_str()):obj["heightdiffratio"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraomtReferenceParam from_json<ApolloperceptioncameraomtReferenceParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraomtReferenceParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraomtReferenceParam &dt)
    {
        dt=from_json_ApolloperceptioncameraomtReferenceParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraomtReferenceParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraomtReferenceParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
