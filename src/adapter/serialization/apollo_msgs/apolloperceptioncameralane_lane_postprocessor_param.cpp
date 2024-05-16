#include "adapter/serialization/apollo_msgs/apolloperceptioncameralane_lane_postprocessor_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncameralaneLanePostprocessorParam &msg) {
        nlohmann::json obj;
        obj["omitbottomlinenum"] = (msg.omitbottomlinenum);
        obj["lanelinemapscorethresh"] = (msg.lanelinemapscorethresh);
        obj["lanelinepointscorethresh"] = (msg.lanelinepointscorethresh);
        obj["lanelinepointminnumthresh"] = (msg.lanelinepointminnumthresh);
        obj["ccvalidpixelsratio"] = (msg.ccvalidpixelsratio);
        obj["lanelinerejectdistthresh"] = (msg.lanelinerejectdistthresh);
        return obj;
    }
    ApolloperceptioncameralaneLanePostprocessorParam from_json_ApolloperceptioncameralaneLanePostprocessorParam (nlohmann::json obj) {
        ApolloperceptioncameralaneLanePostprocessorParam msg;
        if(obj.contains("omitbottomlinenum"))
        {
            msg.omitbottomlinenum = (obj["omitbottomlinenum"].is_string()?atoi(obj["omitbottomlinenum"].get<std::string>().c_str()):obj["omitbottomlinenum"].get<int>());
        }
        if(obj.contains("lanelinemapscorethresh"))
        {
            msg.lanelinemapscorethresh = (obj["lanelinemapscorethresh"].is_string()?(float)atof(obj["lanelinemapscorethresh"].get<std::string>().c_str()):obj["lanelinemapscorethresh"].get<float>());
        }
        if(obj.contains("lanelinepointscorethresh"))
        {
            msg.lanelinepointscorethresh = (obj["lanelinepointscorethresh"].is_string()?(float)atof(obj["lanelinepointscorethresh"].get<std::string>().c_str()):obj["lanelinepointscorethresh"].get<float>());
        }
        if(obj.contains("lanelinepointminnumthresh"))
        {
            msg.lanelinepointminnumthresh = (obj["lanelinepointminnumthresh"].is_string()?atoi(obj["lanelinepointminnumthresh"].get<std::string>().c_str()):obj["lanelinepointminnumthresh"].get<int>());
        }
        if(obj.contains("ccvalidpixelsratio"))
        {
            msg.ccvalidpixelsratio = (obj["ccvalidpixelsratio"].is_string()?(float)atof(obj["ccvalidpixelsratio"].get<std::string>().c_str()):obj["ccvalidpixelsratio"].get<float>());
        }
        if(obj.contains("lanelinerejectdistthresh"))
        {
            msg.lanelinerejectdistthresh = (obj["lanelinerejectdistthresh"].is_string()?(float)atof(obj["lanelinerejectdistthresh"].get<std::string>().c_str()):obj["lanelinerejectdistthresh"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncameralaneLanePostprocessorParam from_json<ApolloperceptioncameralaneLanePostprocessorParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncameralaneLanePostprocessorParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncameralaneLanePostprocessorParam &dt)
    {
        dt=from_json_ApolloperceptioncameralaneLanePostprocessorParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncameralaneLanePostprocessorParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncameralaneLanePostprocessorParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
