#include "adapter/serialization/apollo_msgs/apolloperceptioninference_transformation_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceTransformationParameter &msg) {
        nlohmann::json obj;
        obj["scale"] = (msg.scale);
        obj["mirror"] = (msg.mirror);
        obj["cropsize"] = (msg.cropsize);
        obj["croph"] = (msg.croph);
        obj["cropw"] = (msg.cropw);
        obj["meanfile"] = (msg.meanfile);
        nlohmann::json arr_meanvalue;
        for (auto it = msg.meanvalue.begin(); it != msg.meanvalue.end(); ++it) {
            arr_meanvalue.push_back((*it));
        }
        obj["meanvalue"] = arr_meanvalue;
        obj["forcecolor"] = (msg.forcecolor);
        obj["forcegray"] = (msg.forcegray);
        obj["resizeparam"] = to_json(msg.resizeparam);
        obj["noiseparam"] = to_json(msg.noiseparam);
        obj["distortparam"] = to_json(msg.distortparam);
        obj["expandparam"] = to_json(msg.expandparam);
        obj["jitter"] = (msg.jitter);
        obj["emitconstraint"] = to_json(msg.emitconstraint);
        return obj;
    }
    ApolloperceptioninferenceTransformationParameter from_json_ApolloperceptioninferenceTransformationParameter (nlohmann::json obj) {
        ApolloperceptioninferenceTransformationParameter msg;
        if(obj.contains("scale"))
        {
            msg.scale = (obj["scale"].is_string()?(float)atof(obj["scale"].get<std::string>().c_str()):obj["scale"].get<float>());
        }
        if(obj.contains("mirror"))
        {
            msg.mirror = (obj["mirror"].is_string()?(bool)atoi(obj["mirror"].get<std::string>().c_str()):obj["mirror"].get<bool>());
        }
        if(obj.contains("cropsize"))
        {
            msg.cropsize = (obj["cropsize"].is_string()?atoi(obj["cropsize"].get<std::string>().c_str()):obj["cropsize"].get<uint32_t>());
        }
        if(obj.contains("croph"))
        {
            msg.croph = (obj["croph"].is_string()?atoi(obj["croph"].get<std::string>().c_str()):obj["croph"].get<uint32_t>());
        }
        if(obj.contains("cropw"))
        {
            msg.cropw = (obj["cropw"].is_string()?atoi(obj["cropw"].get<std::string>().c_str()):obj["cropw"].get<uint32_t>());
        }
        if(obj.contains("meanfile"))
        {
            msg.meanfile = (obj["meanfile"].is_string()?(obj["meanfile"].get<std::string>().c_str()):obj["meanfile"].get<std::string>());
        }
        if(obj.contains("meanvalue"))
        {
            if(obj["meanvalue"].is_array())
            {
                for (auto& element : obj["meanvalue"])
                {
                    msg.meanvalue.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.meanvalue.push_back((obj["meanvalue"].is_string()?(float)atof(obj["meanvalue"].get<std::string>().c_str()):obj["meanvalue"].get<float>()));
            }
        }
        if(obj.contains("forcecolor"))
        {
            msg.forcecolor = (obj["forcecolor"].is_string()?(bool)atoi(obj["forcecolor"].get<std::string>().c_str()):obj["forcecolor"].get<bool>());
        }
        if(obj.contains("forcegray"))
        {
            msg.forcegray = (obj["forcegray"].is_string()?(bool)atoi(obj["forcegray"].get<std::string>().c_str()):obj["forcegray"].get<bool>());
        }
        if(obj.contains("resizeparam"))
        {
            msg.resizeparam = from_json_ApolloperceptioninferenceResizeParameter(obj["resizeparam"]);
        }
        if(obj.contains("noiseparam"))
        {
            msg.noiseparam = from_json_ApolloperceptioninferenceNoiseParameter(obj["noiseparam"]);
        }
        if(obj.contains("distortparam"))
        {
            msg.distortparam = from_json_ApolloperceptioninferenceDistortionParameter(obj["distortparam"]);
        }
        if(obj.contains("expandparam"))
        {
            msg.expandparam = from_json_ApolloperceptioninferenceExpansionParameter(obj["expandparam"]);
        }
        if(obj.contains("jitter"))
        {
            msg.jitter = (obj["jitter"].is_string()?(float)atof(obj["jitter"].get<std::string>().c_str()):obj["jitter"].get<float>());
        }
        if(obj.contains("emitconstraint"))
        {
            msg.emitconstraint = from_json_ApolloperceptioninferenceEmitConstraint(obj["emitconstraint"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceTransformationParameter from_json<ApolloperceptioninferenceTransformationParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceTransformationParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceTransformationParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceTransformationParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceTransformationParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceTransformationParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
