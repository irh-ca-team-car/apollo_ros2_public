#include "adapter/serialization/apollo_msgs/apolloperceptioncameralane_dark_scnn_lane_postprocessor_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam &msg) {
        nlohmann::json obj;
        obj["lanemapwidth"] = (msg.lanemapwidth);
        obj["lanemapheight"] = (msg.lanemapheight);
        obj["roiheight"] = (msg.roiheight);
        obj["roistart"] = (msg.roistart);
        obj["roiwidth"] = (msg.roiwidth);
        return obj;
    }
    ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam from_json_ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam (nlohmann::json obj) {
        ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam msg;
        if(obj.contains("lanemapwidth"))
        {
            msg.lanemapwidth = (obj["lanemapwidth"].is_string()?atoi(obj["lanemapwidth"].get<std::string>().c_str()):obj["lanemapwidth"].get<uint32_t>());
        }
        if(obj.contains("lanemapheight"))
        {
            msg.lanemapheight = (obj["lanemapheight"].is_string()?atoi(obj["lanemapheight"].get<std::string>().c_str()):obj["lanemapheight"].get<uint32_t>());
        }
        if(obj.contains("roiheight"))
        {
            msg.roiheight = (obj["roiheight"].is_string()?atoi(obj["roiheight"].get<std::string>().c_str()):obj["roiheight"].get<uint32_t>());
        }
        if(obj.contains("roistart"))
        {
            msg.roistart = (obj["roistart"].is_string()?atoi(obj["roistart"].get<std::string>().c_str()):obj["roistart"].get<uint32_t>());
        }
        if(obj.contains("roiwidth"))
        {
            msg.roiwidth = (obj["roiwidth"].is_string()?atoi(obj["roiwidth"].get<std::string>().c_str()):obj["roiwidth"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam from_json<ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam &dt)
    {
        dt=from_json_ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameralaneDarkSCNNLanePostprocessorParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
