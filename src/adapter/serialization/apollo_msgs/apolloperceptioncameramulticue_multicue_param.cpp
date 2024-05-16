#include "adapter/serialization/apollo_msgs/apolloperceptioncameramulticue_multicue_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameramulticueMulticueParam &msg) {
        nlohmann::json obj;
        obj["mindimensionval"] = (msg.mindimensionval);
        obj["checkdimension"] = (msg.checkdimension);
        return obj;
    }
    ApolloperceptioncameramulticueMulticueParam from_json_ApolloperceptioncameramulticueMulticueParam (nlohmann::json obj) {
        ApolloperceptioncameramulticueMulticueParam msg;
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
    ApolloperceptioncameramulticueMulticueParam from_json<ApolloperceptioncameramulticueMulticueParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameramulticueMulticueParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameramulticueMulticueParam &dt)
    {
        dt=from_json_ApolloperceptioncameramulticueMulticueParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameramulticueMulticueParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameramulticueMulticueParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
