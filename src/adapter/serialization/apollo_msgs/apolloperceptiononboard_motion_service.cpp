#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_motion_service.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardMotionService &msg) {
        nlohmann::json obj;
        obj["cameranames"] = (msg.cameranames);
        obj["inputcamerachannelnames"] = (msg.inputcamerachannelnames);
        obj["inputlocalizationchannelname"] = (msg.inputlocalizationchannelname);
        obj["outputtopicchannelname"] = (msg.outputtopicchannelname);
        return obj;
    }
    ApolloperceptiononboardMotionService from_json_ApolloperceptiononboardMotionService (nlohmann::json obj) {
        ApolloperceptiononboardMotionService msg;
        if(obj.contains("cameranames"))
        {
            msg.cameranames = (obj["cameranames"].is_string()?(obj["cameranames"].get<std::string>().c_str()):obj["cameranames"].get<std::string>());
        }
        if(obj.contains("inputcamerachannelnames"))
        {
            msg.inputcamerachannelnames = (obj["inputcamerachannelnames"].is_string()?(obj["inputcamerachannelnames"].get<std::string>().c_str()):obj["inputcamerachannelnames"].get<std::string>());
        }
        if(obj.contains("inputlocalizationchannelname"))
        {
            msg.inputlocalizationchannelname = (obj["inputlocalizationchannelname"].is_string()?(obj["inputlocalizationchannelname"].get<std::string>().c_str()):obj["inputlocalizationchannelname"].get<std::string>());
        }
        if(obj.contains("outputtopicchannelname"))
        {
            msg.outputtopicchannelname = (obj["outputtopicchannelname"].is_string()?(obj["outputtopicchannelname"].get<std::string>().c_str()):obj["outputtopicchannelname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptiononboardMotionService from_json<ApolloperceptiononboardMotionService>(nlohmann::json obj){
        return from_json_ApolloperceptiononboardMotionService(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardMotionService &dt)
    {
        dt=from_json_ApolloperceptiononboardMotionService(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardMotionService & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardMotionService & dt)
    {
        os << to_json(dt);
        return os;
    }
}
