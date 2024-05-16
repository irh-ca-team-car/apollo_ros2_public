#include "adapter/serialization/apollo_msgs/apolloperceptioninference_prior_box_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePriorBoxParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_minsize;
        for (auto it = msg.minsize.begin(); it != msg.minsize.end(); ++it) {
            arr_minsize.push_back((*it));
        }
        obj["minsize"] = arr_minsize;
        nlohmann::json arr_maxsize;
        for (auto it = msg.maxsize.begin(); it != msg.maxsize.end(); ++it) {
            arr_maxsize.push_back((*it));
        }
        obj["maxsize"] = arr_maxsize;
        nlohmann::json arr_aspectratio;
        for (auto it = msg.aspectratio.begin(); it != msg.aspectratio.end(); ++it) {
            arr_aspectratio.push_back((*it));
        }
        obj["aspectratio"] = arr_aspectratio;
        obj["flip"] = (msg.flip);
        obj["clip"] = (msg.clip);
        nlohmann::json arr_variance;
        for (auto it = msg.variance.begin(); it != msg.variance.end(); ++it) {
            arr_variance.push_back((*it));
        }
        obj["variance"] = arr_variance;
        obj["imgsize"] = (msg.imgsize);
        obj["imgh"] = (msg.imgh);
        obj["imgw"] = (msg.imgw);
        obj["step"] = (msg.step);
        obj["steph"] = (msg.steph);
        obj["stepw"] = (msg.stepw);
        obj["offset"] = (msg.offset);
        return obj;
    }
    ApolloperceptioninferencePriorBoxParameter from_json_ApolloperceptioninferencePriorBoxParameter (nlohmann::json obj) {
        ApolloperceptioninferencePriorBoxParameter msg;
        if(obj.contains("minsize"))
        {
            if(obj["minsize"].is_array())
            {
                for (auto& element : obj["minsize"])
                {
                    msg.minsize.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.minsize.push_back((obj["minsize"].is_string()?(float)atof(obj["minsize"].get<std::string>().c_str()):obj["minsize"].get<float>()));
            }
        }
        if(obj.contains("maxsize"))
        {
            if(obj["maxsize"].is_array())
            {
                for (auto& element : obj["maxsize"])
                {
                    msg.maxsize.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.maxsize.push_back((obj["maxsize"].is_string()?(float)atof(obj["maxsize"].get<std::string>().c_str()):obj["maxsize"].get<float>()));
            }
        }
        if(obj.contains("aspectratio"))
        {
            if(obj["aspectratio"].is_array())
            {
                for (auto& element : obj["aspectratio"])
                {
                    msg.aspectratio.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.aspectratio.push_back((obj["aspectratio"].is_string()?(float)atof(obj["aspectratio"].get<std::string>().c_str()):obj["aspectratio"].get<float>()));
            }
        }
        if(obj.contains("flip"))
        {
            msg.flip = (obj["flip"].is_string()?(bool)atoi(obj["flip"].get<std::string>().c_str()):obj["flip"].get<bool>());
        }
        if(obj.contains("clip"))
        {
            msg.clip = (obj["clip"].is_string()?(bool)atoi(obj["clip"].get<std::string>().c_str()):obj["clip"].get<bool>());
        }
        if(obj.contains("variance"))
        {
            if(obj["variance"].is_array())
            {
                for (auto& element : obj["variance"])
                {
                    msg.variance.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.variance.push_back((obj["variance"].is_string()?(float)atof(obj["variance"].get<std::string>().c_str()):obj["variance"].get<float>()));
            }
        }
        if(obj.contains("imgsize"))
        {
            msg.imgsize = (obj["imgsize"].is_string()?atoi(obj["imgsize"].get<std::string>().c_str()):obj["imgsize"].get<uint32_t>());
        }
        if(obj.contains("imgh"))
        {
            msg.imgh = (obj["imgh"].is_string()?atoi(obj["imgh"].get<std::string>().c_str()):obj["imgh"].get<uint32_t>());
        }
        if(obj.contains("imgw"))
        {
            msg.imgw = (obj["imgw"].is_string()?atoi(obj["imgw"].get<std::string>().c_str()):obj["imgw"].get<uint32_t>());
        }
        if(obj.contains("step"))
        {
            msg.step = (obj["step"].is_string()?(float)atof(obj["step"].get<std::string>().c_str()):obj["step"].get<float>());
        }
        if(obj.contains("steph"))
        {
            msg.steph = (obj["steph"].is_string()?(float)atof(obj["steph"].get<std::string>().c_str()):obj["steph"].get<float>());
        }
        if(obj.contains("stepw"))
        {
            msg.stepw = (obj["stepw"].is_string()?(float)atof(obj["stepw"].get<std::string>().c_str()):obj["stepw"].get<float>());
        }
        if(obj.contains("offset"))
        {
            msg.offset = (obj["offset"].is_string()?(float)atof(obj["offset"].get<std::string>().c_str()):obj["offset"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferencePriorBoxParameter from_json<ApolloperceptioninferencePriorBoxParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferencePriorBoxParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePriorBoxParameter &dt)
    {
        dt=from_json_ApolloperceptioninferencePriorBoxParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePriorBoxParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePriorBoxParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
