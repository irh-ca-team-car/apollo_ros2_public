#include "adapter/serialization/apollo_msgs/apolloperceptioninference_b_box_reg_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBBoxRegParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_bboxmean;
        for (auto it = msg.bboxmean.begin(); it != msg.bboxmean.end(); ++it) {
            arr_bboxmean.push_back((*it));
        }
        obj["bboxmean"] = arr_bboxmean;
        nlohmann::json arr_bboxstd;
        for (auto it = msg.bboxstd.begin(); it != msg.bboxstd.end(); ++it) {
            arr_bboxstd.push_back((*it));
        }
        obj["bboxstd"] = arr_bboxstd;
        return obj;
    }
    ApolloperceptioninferenceBBoxRegParameter from_json_ApolloperceptioninferenceBBoxRegParameter (nlohmann::json obj) {
        ApolloperceptioninferenceBBoxRegParameter msg;
        if(obj.contains("bboxmean"))
        {
            if(obj["bboxmean"].is_array())
            {
                for (auto& element : obj["bboxmean"])
                {
                    msg.bboxmean.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.bboxmean.push_back((obj["bboxmean"].is_string()?(float)atof(obj["bboxmean"].get<std::string>().c_str()):obj["bboxmean"].get<float>()));
            }
        }
        if(obj.contains("bboxstd"))
        {
            if(obj["bboxstd"].is_array())
            {
                for (auto& element : obj["bboxstd"])
                {
                    msg.bboxstd.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.bboxstd.push_back((obj["bboxstd"].is_string()?(float)atof(obj["bboxstd"].get<std::string>().c_str()):obj["bboxstd"].get<float>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceBBoxRegParameter from_json<ApolloperceptioninferenceBBoxRegParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceBBoxRegParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBBoxRegParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceBBoxRegParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBBoxRegParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBBoxRegParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
