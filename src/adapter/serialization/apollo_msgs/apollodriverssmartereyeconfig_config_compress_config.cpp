#include "adapter/serialization/apollo_msgs/apollodriverssmartereyeconfig_config_compress_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverssmartereyeconfigConfigCompressConfig &msg) {
        nlohmann::json obj;
        obj["outputchannel"] = (msg.outputchannel);
        obj["imagepoolsize"] = (msg.imagepoolsize);
        return obj;
    }
    ApollodriverssmartereyeconfigConfigCompressConfig from_json_ApollodriverssmartereyeconfigConfigCompressConfig (nlohmann::json obj) {
        ApollodriverssmartereyeconfigConfigCompressConfig msg;
        if(obj.contains("outputchannel"))
        {
            msg.outputchannel = (obj["outputchannel"].is_string()?(obj["outputchannel"].get<std::string>().c_str()):obj["outputchannel"].get<std::string>());
        }
        if(obj.contains("imagepoolsize"))
        {
            msg.imagepoolsize = (obj["imagepoolsize"].is_string()?atoi(obj["imagepoolsize"].get<std::string>().c_str()):obj["imagepoolsize"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriverssmartereyeconfigConfigCompressConfig from_json<ApollodriverssmartereyeconfigConfigCompressConfig>(nlohmann::json obj){
        return from_json_ApollodriverssmartereyeconfigConfigCompressConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverssmartereyeconfigConfigCompressConfig &dt)
    {
        dt=from_json_ApollodriverssmartereyeconfigConfigCompressConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriverssmartereyeconfigConfigCompressConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverssmartereyeconfigConfigCompressConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
