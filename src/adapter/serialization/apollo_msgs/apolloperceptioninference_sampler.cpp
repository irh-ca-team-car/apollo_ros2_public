#include "adapter/serialization/apollo_msgs/apolloperceptioninference_sampler.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSampler &msg) {
        nlohmann::json obj;
        obj["minscale"] = (msg.minscale);
        obj["maxscale"] = (msg.maxscale);
        obj["minaspectratio"] = (msg.minaspectratio);
        obj["maxaspectratio"] = (msg.maxaspectratio);
        return obj;
    }
    ApolloperceptioninferenceSampler from_json_ApolloperceptioninferenceSampler (nlohmann::json obj) {
        ApolloperceptioninferenceSampler msg;
        if(obj.contains("minscale"))
        {
            msg.minscale = (obj["minscale"].is_string()?(float)atof(obj["minscale"].get<std::string>().c_str()):obj["minscale"].get<float>());
        }
        if(obj.contains("maxscale"))
        {
            msg.maxscale = (obj["maxscale"].is_string()?(float)atof(obj["maxscale"].get<std::string>().c_str()):obj["maxscale"].get<float>());
        }
        if(obj.contains("minaspectratio"))
        {
            msg.minaspectratio = (obj["minaspectratio"].is_string()?(float)atof(obj["minaspectratio"].get<std::string>().c_str()):obj["minaspectratio"].get<float>());
        }
        if(obj.contains("maxaspectratio"))
        {
            msg.maxaspectratio = (obj["maxaspectratio"].is_string()?(float)atof(obj["maxaspectratio"].get<std::string>().c_str()):obj["maxaspectratio"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceSampler from_json<ApolloperceptioninferenceSampler>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceSampler(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSampler &dt)
    {
        dt=from_json_ApolloperceptioninferenceSampler(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSampler & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSampler & dt)
    {
        os << to_json(dt);
        return os;
    }
}
