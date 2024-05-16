#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasinglestage_singlestage_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasinglestageSinglestageParam &msg) {
        nlohmann::json obj;
        obj["mindimensionval"] = (msg.mindimensionval);
        obj["checkdimension"] = (msg.checkdimension);
        return obj;
    }
    ApolloperceptioncamerasinglestageSinglestageParam from_json_ApolloperceptioncamerasinglestageSinglestageParam (nlohmann::json obj) {
        ApolloperceptioncamerasinglestageSinglestageParam msg;
        if(obj.contains("mindimensionval"))
        {
            msg.mindimensionval = (obj["mindimensionval"].is_string()?(float)atof(obj["mindimensionval"].get<std::string>().c_str()):obj["mindimensionval"].get<float>());
        }
        if(obj.contains("checkdimension"))
        {
            msg.checkdimension = (obj["checkdimension"].is_string()?(bool)atoi(obj["checkdimension"].get<std::string>().c_str()):obj["checkdimension"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncamerasinglestageSinglestageParam from_json<ApolloperceptioncamerasinglestageSinglestageParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncamerasinglestageSinglestageParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasinglestageSinglestageParam &dt)
    {
        dt=from_json_ApolloperceptioncamerasinglestageSinglestageParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasinglestageSinglestageParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasinglestageSinglestageParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
