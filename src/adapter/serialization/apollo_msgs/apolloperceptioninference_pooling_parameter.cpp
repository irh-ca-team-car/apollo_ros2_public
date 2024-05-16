#include "adapter/serialization/apollo_msgs/apolloperceptioninference_pooling_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferencePoolingParameter &msg) {
        nlohmann::json obj;
        obj["pool"] = (msg.pool);
        obj["pad"] = (msg.pad);
        obj["padh"] = (msg.padh);
        obj["padw"] = (msg.padw);
        obj["kernelsize"] = (msg.kernelsize);
        obj["kernelh"] = (msg.kernelh);
        obj["kernelw"] = (msg.kernelw);
        obj["stride"] = (msg.stride);
        obj["strideh"] = (msg.strideh);
        obj["stridew"] = (msg.stridew);
        obj["engine"] = (msg.engine);
        obj["globalpooling"] = (msg.globalpooling);
        obj["roundmode"] = (msg.roundmode);
        return obj;
    }
    ApolloperceptioninferencePoolingParameter from_json_ApolloperceptioninferencePoolingParameter (nlohmann::json obj) {
        ApolloperceptioninferencePoolingParameter msg;
        if(obj.contains("pool"))
        {
            msg.pool = (obj["pool"].is_string()?atoi(obj["pool"].get<std::string>().c_str()):obj["pool"].get<int>());
        }
        if(obj.contains("pad"))
        {
            msg.pad = (obj["pad"].is_string()?atoi(obj["pad"].get<std::string>().c_str()):obj["pad"].get<uint32_t>());
        }
        if(obj.contains("padh"))
        {
            msg.padh = (obj["padh"].is_string()?atoi(obj["padh"].get<std::string>().c_str()):obj["padh"].get<uint32_t>());
        }
        if(obj.contains("padw"))
        {
            msg.padw = (obj["padw"].is_string()?atoi(obj["padw"].get<std::string>().c_str()):obj["padw"].get<uint32_t>());
        }
        if(obj.contains("kernelsize"))
        {
            msg.kernelsize = (obj["kernelsize"].is_string()?atoi(obj["kernelsize"].get<std::string>().c_str()):obj["kernelsize"].get<uint32_t>());
        }
        if(obj.contains("kernelh"))
        {
            msg.kernelh = (obj["kernelh"].is_string()?atoi(obj["kernelh"].get<std::string>().c_str()):obj["kernelh"].get<uint32_t>());
        }
        if(obj.contains("kernelw"))
        {
            msg.kernelw = (obj["kernelw"].is_string()?atoi(obj["kernelw"].get<std::string>().c_str()):obj["kernelw"].get<uint32_t>());
        }
        if(obj.contains("stride"))
        {
            msg.stride = (obj["stride"].is_string()?atoi(obj["stride"].get<std::string>().c_str()):obj["stride"].get<uint32_t>());
        }
        if(obj.contains("strideh"))
        {
            msg.strideh = (obj["strideh"].is_string()?atoi(obj["strideh"].get<std::string>().c_str()):obj["strideh"].get<uint32_t>());
        }
        if(obj.contains("stridew"))
        {
            msg.stridew = (obj["stridew"].is_string()?atoi(obj["stridew"].get<std::string>().c_str()):obj["stridew"].get<uint32_t>());
        }
        if(obj.contains("engine"))
        {
            msg.engine = (obj["engine"].is_string()?atoi(obj["engine"].get<std::string>().c_str()):obj["engine"].get<int>());
        }
        if(obj.contains("globalpooling"))
        {
            msg.globalpooling = (obj["globalpooling"].is_string()?(bool)atoi(obj["globalpooling"].get<std::string>().c_str()):obj["globalpooling"].get<bool>());
        }
        if(obj.contains("roundmode"))
        {
            msg.roundmode = (obj["roundmode"].is_string()?atoi(obj["roundmode"].get<std::string>().c_str()):obj["roundmode"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferencePoolingParameter from_json<ApolloperceptioninferencePoolingParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferencePoolingParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferencePoolingParameter &dt)
    {
        dt=from_json_ApolloperceptioninferencePoolingParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferencePoolingParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferencePoolingParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
