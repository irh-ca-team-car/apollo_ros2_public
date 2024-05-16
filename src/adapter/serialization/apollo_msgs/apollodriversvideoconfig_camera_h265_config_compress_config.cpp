#include "adapter/serialization/apollo_msgs/apollodriversvideoconfig_camera_h265_config_compress_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvideoconfigCameraH265ConfigCompressConfig &msg) {
        nlohmann::json obj;
        obj["outputchannel"] = (msg.outputchannel);
        obj["imagepoolsize"] = (msg.imagepoolsize);
        return obj;
    }
    ApollodriversvideoconfigCameraH265ConfigCompressConfig from_json_ApollodriversvideoconfigCameraH265ConfigCompressConfig (nlohmann::json obj) {
        ApollodriversvideoconfigCameraH265ConfigCompressConfig msg;
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
    ApollodriversvideoconfigCameraH265ConfigCompressConfig from_json<ApollodriversvideoconfigCameraH265ConfigCompressConfig>(nlohmann::json obj){
        return from_json_ApollodriversvideoconfigCameraH265ConfigCompressConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvideoconfigCameraH265ConfigCompressConfig &dt)
    {
        dt=from_json_ApollodriversvideoconfigCameraH265ConfigCompressConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversvideoconfigCameraH265ConfigCompressConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvideoconfigCameraH265ConfigCompressConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
