#include "adapter/serialization/apollo_msgs/apolloperceptioninference_gen_anchor_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceGenAnchorParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_anchorwidth;
        for (auto it = msg.anchorwidth.begin(); it != msg.anchorwidth.end(); ++it) {
            arr_anchorwidth.push_back((*it));
        }
        obj["anchorwidth"] = arr_anchorwidth;
        nlohmann::json arr_anchorheight;
        for (auto it = msg.anchorheight.begin(); it != msg.anchorheight.end(); ++it) {
            arr_anchorheight.push_back((*it));
        }
        obj["anchorheight"] = arr_anchorheight;
        return obj;
    }
    ApolloperceptioninferenceGenAnchorParameter from_json_ApolloperceptioninferenceGenAnchorParameter (nlohmann::json obj) {
        ApolloperceptioninferenceGenAnchorParameter msg;
        if(obj.contains("anchorwidth"))
        {
            if(obj["anchorwidth"].is_array())
            {
                for (auto& element : obj["anchorwidth"])
                {
                    msg.anchorwidth.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.anchorwidth.push_back((obj["anchorwidth"].is_string()?(float)atof(obj["anchorwidth"].get<std::string>().c_str()):obj["anchorwidth"].get<float>()));
            }
        }
        if(obj.contains("anchorheight"))
        {
            if(obj["anchorheight"].is_array())
            {
                for (auto& element : obj["anchorheight"])
                {
                    msg.anchorheight.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.anchorheight.push_back((obj["anchorheight"].is_string()?(float)atof(obj["anchorheight"].get<std::string>().c_str()):obj["anchorheight"].get<float>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceGenAnchorParameter from_json<ApolloperceptioninferenceGenAnchorParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceGenAnchorParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceGenAnchorParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceGenAnchorParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceGenAnchorParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceGenAnchorParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
