#include "adapter/serialization/apollo_msgs/apolloperceptioninference_video_data_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceVideoDataParameter &msg) {
        nlohmann::json obj;
        obj["videotype"] = (msg.videotype);
        obj["deviceid"] = (msg.deviceid);
        obj["videofile"] = (msg.videofile);
        obj["skipframes"] = (msg.skipframes);
        return obj;
    }
    ApolloperceptioninferenceVideoDataParameter from_json_ApolloperceptioninferenceVideoDataParameter (nlohmann::json obj) {
        ApolloperceptioninferenceVideoDataParameter msg;
        if(obj.contains("videotype"))
        {
            msg.videotype = (obj["videotype"].is_string()?atoi(obj["videotype"].get<std::string>().c_str()):obj["videotype"].get<int>());
        }
        if(obj.contains("deviceid"))
        {
            msg.deviceid = (obj["deviceid"].is_string()?atoi(obj["deviceid"].get<std::string>().c_str()):obj["deviceid"].get<int>());
        }
        if(obj.contains("videofile"))
        {
            msg.videofile = (obj["videofile"].is_string()?(obj["videofile"].get<std::string>().c_str()):obj["videofile"].get<std::string>());
        }
        if(obj.contains("skipframes"))
        {
            msg.skipframes = (obj["skipframes"].is_string()?atoi(obj["skipframes"].get<std::string>().c_str()):obj["skipframes"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceVideoDataParameter from_json<ApolloperceptioninferenceVideoDataParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceVideoDataParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceVideoDataParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceVideoDataParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceVideoDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceVideoDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
