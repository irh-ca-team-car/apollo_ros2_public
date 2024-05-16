#include "adapter/serialization/apollo_msgs/apolloperceptioncameralocation_refiner_location_refiner_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameralocationRefinerLocationRefinerParam &msg) {
        nlohmann::json obj;
        obj["mindisttocamera"] = (msg.mindisttocamera);
        obj["roih2bottomscale"] = (msg.roih2bottomscale);
        return obj;
    }
    ApolloperceptioncameralocationRefinerLocationRefinerParam from_json_ApolloperceptioncameralocationRefinerLocationRefinerParam (nlohmann::json obj) {
        ApolloperceptioncameralocationRefinerLocationRefinerParam msg;
        if(obj.contains("mindisttocamera"))
        {
            msg.mindisttocamera = (obj["mindisttocamera"].is_string()?(float)atof(obj["mindisttocamera"].get<std::string>().c_str()):obj["mindisttocamera"].get<float>());
        }
        if(obj.contains("roih2bottomscale"))
        {
            msg.roih2bottomscale = (obj["roih2bottomscale"].is_string()?(float)atof(obj["roih2bottomscale"].get<std::string>().c_str()):obj["roih2bottomscale"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameralocationRefinerLocationRefinerParam from_json<ApolloperceptioncameralocationRefinerLocationRefinerParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameralocationRefinerLocationRefinerParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameralocationRefinerLocationRefinerParam &dt)
    {
        dt=from_json_ApolloperceptioncameralocationRefinerLocationRefinerParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameralocationRefinerLocationRefinerParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameralocationRefinerLocationRefinerParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
