#include "adapter/serialization/apollo_msgs/apolloperceptioncamera_object_template.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameraObjectTemplate &msg) {
        nlohmann::json obj;
        obj["speedlimit"] = (msg.speedlimit);
        nlohmann::json arr_dim;
        for (auto it = msg.dim.begin(); it != msg.dim.end(); ++it) {
            arr_dim.push_back(to_json(*it));
        }
        obj["dim"] = arr_dim;
        return obj;
    }
    ApolloperceptioncameraObjectTemplate from_json_ApolloperceptioncameraObjectTemplate (nlohmann::json obj) {
        ApolloperceptioncameraObjectTemplate msg;
        if(obj.contains("speedlimit"))
        {
            msg.speedlimit = (obj["speedlimit"].is_string()?(float)atof(obj["speedlimit"].get<std::string>().c_str()):obj["speedlimit"].get<float>());
        }
        if(obj.contains("dim"))
        {
            if(obj["dim"].is_array())
            {
                for (auto& element : obj["dim"])
                {
                    msg.dim.push_back(from_json_ApolloperceptioncameraDim(element));
                }
            }
            else
            {
                msg.dim.push_back(from_json_ApolloperceptioncameraDim(obj["dim"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioncameraObjectTemplate from_json<ApolloperceptioncameraObjectTemplate>(nlohmann::json obj){
        return from_json_ApolloperceptioncameraObjectTemplate(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameraObjectTemplate &dt)
    {
        dt=from_json_ApolloperceptioncameraObjectTemplate(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameraObjectTemplate & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameraObjectTemplate & dt)
    {
        os << to_json(dt);
        return os;
    }
}
