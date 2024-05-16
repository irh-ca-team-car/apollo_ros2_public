#include "adapter/serialization/apollo_msgs/apollodriverscameraconfig_config_compress_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscameraconfigConfigCompressConfig &msg) {
        nlohmann::json obj;
        obj["outputchannel"] = (msg.outputchannel);
        obj["imagepoolsize"] = (msg.imagepoolsize);
        return obj;
    }
    ApollodriverscameraconfigConfigCompressConfig from_json_ApollodriverscameraconfigConfigCompressConfig (nlohmann::json obj) {
        ApollodriverscameraconfigConfigCompressConfig msg;
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
    ApollodriverscameraconfigConfigCompressConfig from_json<ApollodriverscameraconfigConfigCompressConfig>(nlohmann::json obj){
        return from_json_ApollodriverscameraconfigConfigCompressConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscameraconfigConfigCompressConfig &dt)
    {
        dt=from_json_ApollodriverscameraconfigConfigCompressConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriverscameraconfigConfigCompressConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscameraconfigConfigCompressConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
