#include "adapter/serialization/apollo_msgs/apolloperceptioninference_noise_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNoiseParameter &msg) {
        nlohmann::json obj;
        obj["prob"] = (msg.prob);
        obj["histeq"] = (msg.histeq);
        obj["inverse"] = (msg.inverse);
        obj["decolorize"] = (msg.decolorize);
        obj["gaussblur"] = (msg.gaussblur);
        obj["jpeg"] = (msg.jpeg);
        obj["posterize"] = (msg.posterize);
        obj["erode"] = (msg.erode);
        obj["saltpepper"] = (msg.saltpepper);
        obj["saltpepperparam"] = to_json(msg.saltpepperparam);
        obj["clahe"] = (msg.clahe);
        obj["converttohsv"] = (msg.converttohsv);
        obj["converttolab"] = (msg.converttolab);
        return obj;
    }
    ApolloperceptioninferenceNoiseParameter from_json_ApolloperceptioninferenceNoiseParameter (nlohmann::json obj) {
        ApolloperceptioninferenceNoiseParameter msg;
        if(obj.contains("prob"))
        {
            msg.prob = (obj["prob"].is_string()?(float)atof(obj["prob"].get<std::string>().c_str()):obj["prob"].get<float>());
        }
        if(obj.contains("histeq"))
        {
            msg.histeq = (obj["histeq"].is_string()?(bool)atoi(obj["histeq"].get<std::string>().c_str()):obj["histeq"].get<bool>());
        }
        if(obj.contains("inverse"))
        {
            msg.inverse = (obj["inverse"].is_string()?(bool)atoi(obj["inverse"].get<std::string>().c_str()):obj["inverse"].get<bool>());
        }
        if(obj.contains("decolorize"))
        {
            msg.decolorize = (obj["decolorize"].is_string()?(bool)atoi(obj["decolorize"].get<std::string>().c_str()):obj["decolorize"].get<bool>());
        }
        if(obj.contains("gaussblur"))
        {
            msg.gaussblur = (obj["gaussblur"].is_string()?(bool)atoi(obj["gaussblur"].get<std::string>().c_str()):obj["gaussblur"].get<bool>());
        }
        if(obj.contains("jpeg"))
        {
            msg.jpeg = (obj["jpeg"].is_string()?(float)atof(obj["jpeg"].get<std::string>().c_str()):obj["jpeg"].get<float>());
        }
        if(obj.contains("posterize"))
        {
            msg.posterize = (obj["posterize"].is_string()?(bool)atoi(obj["posterize"].get<std::string>().c_str()):obj["posterize"].get<bool>());
        }
        if(obj.contains("erode"))
        {
            msg.erode = (obj["erode"].is_string()?(bool)atoi(obj["erode"].get<std::string>().c_str()):obj["erode"].get<bool>());
        }
        if(obj.contains("saltpepper"))
        {
            msg.saltpepper = (obj["saltpepper"].is_string()?(bool)atoi(obj["saltpepper"].get<std::string>().c_str()):obj["saltpepper"].get<bool>());
        }
        if(obj.contains("saltpepperparam"))
        {
            msg.saltpepperparam = from_json_ApolloperceptioninferenceSaltPepperParameter(obj["saltpepperparam"]);
        }
        if(obj.contains("clahe"))
        {
            msg.clahe = (obj["clahe"].is_string()?(bool)atoi(obj["clahe"].get<std::string>().c_str()):obj["clahe"].get<bool>());
        }
        if(obj.contains("converttohsv"))
        {
            msg.converttohsv = (obj["converttohsv"].is_string()?(bool)atoi(obj["converttohsv"].get<std::string>().c_str()):obj["converttohsv"].get<bool>());
        }
        if(obj.contains("converttolab"))
        {
            msg.converttolab = (obj["converttolab"].is_string()?(bool)atoi(obj["converttolab"].get<std::string>().c_str()):obj["converttolab"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceNoiseParameter from_json<ApolloperceptioninferenceNoiseParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceNoiseParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNoiseParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceNoiseParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNoiseParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNoiseParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
