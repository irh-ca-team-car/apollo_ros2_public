#include "adapter/serialization/apollo_msgs/apolloperceptioninference_distortion_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDistortionParameter &msg) {
        nlohmann::json obj;
        obj["brightnessprob"] = (msg.brightnessprob);
        obj["brightnessdelta"] = (msg.brightnessdelta);
        obj["contrastprob"] = (msg.contrastprob);
        obj["contrastlower"] = (msg.contrastlower);
        obj["contrastupper"] = (msg.contrastupper);
        obj["hueprob"] = (msg.hueprob);
        obj["huedelta"] = (msg.huedelta);
        obj["saturationprob"] = (msg.saturationprob);
        obj["saturationlower"] = (msg.saturationlower);
        obj["saturationupper"] = (msg.saturationupper);
        obj["randomorderprob"] = (msg.randomorderprob);
        return obj;
    }
    ApolloperceptioninferenceDistortionParameter from_json_ApolloperceptioninferenceDistortionParameter (nlohmann::json obj) {
        ApolloperceptioninferenceDistortionParameter msg;
        if(obj.contains("brightnessprob"))
        {
            msg.brightnessprob = (obj["brightnessprob"].is_string()?(float)atof(obj["brightnessprob"].get<std::string>().c_str()):obj["brightnessprob"].get<float>());
        }
        if(obj.contains("brightnessdelta"))
        {
            msg.brightnessdelta = (obj["brightnessdelta"].is_string()?(float)atof(obj["brightnessdelta"].get<std::string>().c_str()):obj["brightnessdelta"].get<float>());
        }
        if(obj.contains("contrastprob"))
        {
            msg.contrastprob = (obj["contrastprob"].is_string()?(float)atof(obj["contrastprob"].get<std::string>().c_str()):obj["contrastprob"].get<float>());
        }
        if(obj.contains("contrastlower"))
        {
            msg.contrastlower = (obj["contrastlower"].is_string()?(float)atof(obj["contrastlower"].get<std::string>().c_str()):obj["contrastlower"].get<float>());
        }
        if(obj.contains("contrastupper"))
        {
            msg.contrastupper = (obj["contrastupper"].is_string()?(float)atof(obj["contrastupper"].get<std::string>().c_str()):obj["contrastupper"].get<float>());
        }
        if(obj.contains("hueprob"))
        {
            msg.hueprob = (obj["hueprob"].is_string()?(float)atof(obj["hueprob"].get<std::string>().c_str()):obj["hueprob"].get<float>());
        }
        if(obj.contains("huedelta"))
        {
            msg.huedelta = (obj["huedelta"].is_string()?(float)atof(obj["huedelta"].get<std::string>().c_str()):obj["huedelta"].get<float>());
        }
        if(obj.contains("saturationprob"))
        {
            msg.saturationprob = (obj["saturationprob"].is_string()?(float)atof(obj["saturationprob"].get<std::string>().c_str()):obj["saturationprob"].get<float>());
        }
        if(obj.contains("saturationlower"))
        {
            msg.saturationlower = (obj["saturationlower"].is_string()?(float)atof(obj["saturationlower"].get<std::string>().c_str()):obj["saturationlower"].get<float>());
        }
        if(obj.contains("saturationupper"))
        {
            msg.saturationupper = (obj["saturationupper"].is_string()?(float)atof(obj["saturationupper"].get<std::string>().c_str()):obj["saturationupper"].get<float>());
        }
        if(obj.contains("randomorderprob"))
        {
            msg.randomorderprob = (obj["randomorderprob"].is_string()?(float)atof(obj["randomorderprob"].get<std::string>().c_str()):obj["randomorderprob"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDistortionParameter from_json<ApolloperceptioninferenceDistortionParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDistortionParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDistortionParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceDistortionParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDistortionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDistortionParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
