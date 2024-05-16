#include "adapter/serialization/apollo_msgs/apolloimage_decompress_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloimageDecompressConfig &msg) {
        nlohmann::json obj;
        obj["channelname"] = (msg.channelname);
        return obj;
    }
    ApolloimageDecompressConfig from_json_ApolloimageDecompressConfig (nlohmann::json obj) {
        ApolloimageDecompressConfig msg;
        if(obj.contains("channelname"))
        {
            msg.channelname = (obj["channelname"].is_string()?(obj["channelname"].get<std::string>().c_str()):obj["channelname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloimageDecompressConfig from_json<ApolloimageDecompressConfig>(nlohmann::json obj){
        return from_json_ApolloimageDecompressConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloimageDecompressConfig &dt)
    {
        dt=from_json_ApolloimageDecompressConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloimageDecompressConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloimageDecompressConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
