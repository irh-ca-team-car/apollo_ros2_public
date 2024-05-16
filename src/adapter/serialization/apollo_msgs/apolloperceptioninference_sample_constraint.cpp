#include "adapter/serialization/apollo_msgs/apolloperceptioninference_sample_constraint.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSampleConstraint &msg) {
        nlohmann::json obj;
        obj["minjaccardoverlap"] = (msg.minjaccardoverlap);
        obj["maxjaccardoverlap"] = (msg.maxjaccardoverlap);
        obj["minsamplecoverage"] = (msg.minsamplecoverage);
        obj["maxsamplecoverage"] = (msg.maxsamplecoverage);
        obj["minobjectcoverage"] = (msg.minobjectcoverage);
        obj["maxobjectcoverage"] = (msg.maxobjectcoverage);
        nlohmann::json arr_balancetype;
        for (auto it = msg.balancetype.begin(); it != msg.balancetype.end(); ++it) {
            arr_balancetype.push_back((*it));
        }
        obj["balancetype"] = arr_balancetype;
        return obj;
    }
    ApolloperceptioninferenceSampleConstraint from_json_ApolloperceptioninferenceSampleConstraint (nlohmann::json obj) {
        ApolloperceptioninferenceSampleConstraint msg;
        if(obj.contains("minjaccardoverlap"))
        {
            msg.minjaccardoverlap = (obj["minjaccardoverlap"].is_string()?(float)atof(obj["minjaccardoverlap"].get<std::string>().c_str()):obj["minjaccardoverlap"].get<float>());
        }
        if(obj.contains("maxjaccardoverlap"))
        {
            msg.maxjaccardoverlap = (obj["maxjaccardoverlap"].is_string()?(float)atof(obj["maxjaccardoverlap"].get<std::string>().c_str()):obj["maxjaccardoverlap"].get<float>());
        }
        if(obj.contains("minsamplecoverage"))
        {
            msg.minsamplecoverage = (obj["minsamplecoverage"].is_string()?(float)atof(obj["minsamplecoverage"].get<std::string>().c_str()):obj["minsamplecoverage"].get<float>());
        }
        if(obj.contains("maxsamplecoverage"))
        {
            msg.maxsamplecoverage = (obj["maxsamplecoverage"].is_string()?(float)atof(obj["maxsamplecoverage"].get<std::string>().c_str()):obj["maxsamplecoverage"].get<float>());
        }
        if(obj.contains("minobjectcoverage"))
        {
            msg.minobjectcoverage = (obj["minobjectcoverage"].is_string()?(float)atof(obj["minobjectcoverage"].get<std::string>().c_str()):obj["minobjectcoverage"].get<float>());
        }
        if(obj.contains("maxobjectcoverage"))
        {
            msg.maxobjectcoverage = (obj["maxobjectcoverage"].is_string()?(float)atof(obj["maxobjectcoverage"].get<std::string>().c_str()):obj["maxobjectcoverage"].get<float>());
        }
        if(obj.contains("balancetype"))
        {
            if(obj["balancetype"].is_array())
            {
                for (auto& element : obj["balancetype"])
                {
                    msg.balancetype.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.balancetype.push_back((obj["balancetype"].is_string()?atoi(obj["balancetype"].get<std::string>().c_str()):obj["balancetype"].get<int>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceSampleConstraint from_json<ApolloperceptioninferenceSampleConstraint>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceSampleConstraint(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSampleConstraint &dt)
    {
        dt=from_json_ApolloperceptioninferenceSampleConstraint(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSampleConstraint & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSampleConstraint & dt)
    {
        os << to_json(dt);
        return os;
    }
}
