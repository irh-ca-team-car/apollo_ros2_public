#include "adapter/serialization/apollo_msgs/apolloperceptioninference_crop_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceCropParameter &msg) {
        nlohmann::json obj;
        obj["axis"] = (msg.axis);
        nlohmann::json arr_offset;
        for (auto it = msg.offset.begin(); it != msg.offset.end(); ++it) {
            arr_offset.push_back((*it));
        }
        obj["offset"] = arr_offset;
        return obj;
    }
    ApolloperceptioninferenceCropParameter from_json_ApolloperceptioninferenceCropParameter (nlohmann::json obj) {
        ApolloperceptioninferenceCropParameter msg;
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("offset"))
        {
            if(obj["offset"].is_array())
            {
                for (auto& element : obj["offset"])
                {
                    msg.offset.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.offset.push_back((obj["offset"].is_string()?atoi(obj["offset"].get<std::string>().c_str()):obj["offset"].get<uint32_t>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceCropParameter from_json<ApolloperceptioninferenceCropParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceCropParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceCropParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceCropParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceCropParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceCropParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
