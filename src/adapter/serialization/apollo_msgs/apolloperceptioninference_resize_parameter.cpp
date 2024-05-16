#include "adapter/serialization/apollo_msgs/apolloperceptioninference_resize_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceResizeParameter &msg) {
        nlohmann::json obj;
        obj["prob"] = (msg.prob);
        obj["resizemode"] = (msg.resizemode);
        obj["height"] = (msg.height);
        obj["width"] = (msg.width);
        obj["heightscale"] = (msg.heightscale);
        obj["widthscale"] = (msg.widthscale);
        obj["padmode"] = (msg.padmode);
        nlohmann::json arr_padvalue;
        for (auto it = msg.padvalue.begin(); it != msg.padvalue.end(); ++it) {
            arr_padvalue.push_back((*it));
        }
        obj["padvalue"] = arr_padvalue;
        nlohmann::json arr_interpmode;
        for (auto it = msg.interpmode.begin(); it != msg.interpmode.end(); ++it) {
            arr_interpmode.push_back((*it));
        }
        obj["interpmode"] = arr_interpmode;
        return obj;
    }
    ApolloperceptioninferenceResizeParameter from_json_ApolloperceptioninferenceResizeParameter (nlohmann::json obj) {
        ApolloperceptioninferenceResizeParameter msg;
        if(obj.contains("prob"))
        {
            msg.prob = (obj["prob"].is_string()?(float)atof(obj["prob"].get<std::string>().c_str()):obj["prob"].get<float>());
        }
        if(obj.contains("resizemode"))
        {
            msg.resizemode = (obj["resizemode"].is_string()?atoi(obj["resizemode"].get<std::string>().c_str()):obj["resizemode"].get<int>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atoi(obj["height"].get<std::string>().c_str()):obj["height"].get<uint32_t>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<uint32_t>());
        }
        if(obj.contains("heightscale"))
        {
            msg.heightscale = (obj["heightscale"].is_string()?atoi(obj["heightscale"].get<std::string>().c_str()):obj["heightscale"].get<uint32_t>());
        }
        if(obj.contains("widthscale"))
        {
            msg.widthscale = (obj["widthscale"].is_string()?atoi(obj["widthscale"].get<std::string>().c_str()):obj["widthscale"].get<uint32_t>());
        }
        if(obj.contains("padmode"))
        {
            msg.padmode = (obj["padmode"].is_string()?atoi(obj["padmode"].get<std::string>().c_str()):obj["padmode"].get<int>());
        }
        if(obj.contains("padvalue"))
        {
            if(obj["padvalue"].is_array())
            {
                for (auto& element : obj["padvalue"])
                {
                    msg.padvalue.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.padvalue.push_back((obj["padvalue"].is_string()?(float)atof(obj["padvalue"].get<std::string>().c_str()):obj["padvalue"].get<float>()));
            }
        }
        if(obj.contains("interpmode"))
        {
            if(obj["interpmode"].is_array())
            {
                for (auto& element : obj["interpmode"])
                {
                    msg.interpmode.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.interpmode.push_back((obj["interpmode"].is_string()?atoi(obj["interpmode"].get<std::string>().c_str()):obj["interpmode"].get<int>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceResizeParameter from_json<ApolloperceptioninferenceResizeParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceResizeParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceResizeParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceResizeParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceResizeParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceResizeParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
