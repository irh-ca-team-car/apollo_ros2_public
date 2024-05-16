#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dfmbpsroi_align_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceDFMBPSROIAlignParameter &msg) {
        nlohmann::json obj;
        obj["heatmapa"] = (msg.heatmapa);
        obj["outputdim"] = (msg.outputdim);
        obj["groupheight"] = (msg.groupheight);
        obj["groupwidth"] = (msg.groupwidth);
        obj["pooledheight"] = (msg.pooledheight);
        obj["pooledwidth"] = (msg.pooledwidth);
        obj["padratio"] = (msg.padratio);
        obj["sampleperpart"] = (msg.sampleperpart);
        obj["transstd"] = (msg.transstd);
        obj["partheight"] = (msg.partheight);
        obj["partwidth"] = (msg.partwidth);
        obj["heatmapb"] = (msg.heatmapb);
        return obj;
    }
    ApolloperceptioninferenceDFMBPSROIAlignParameter from_json_ApolloperceptioninferenceDFMBPSROIAlignParameter (nlohmann::json obj) {
        ApolloperceptioninferenceDFMBPSROIAlignParameter msg;
        if(obj.contains("heatmapa"))
        {
            msg.heatmapa = (obj["heatmapa"].is_string()?(float)atof(obj["heatmapa"].get<std::string>().c_str()):obj["heatmapa"].get<float>());
        }
        if(obj.contains("outputdim"))
        {
            msg.outputdim = (obj["outputdim"].is_string()?atoi(obj["outputdim"].get<std::string>().c_str()):obj["outputdim"].get<int>());
        }
        if(obj.contains("groupheight"))
        {
            msg.groupheight = (obj["groupheight"].is_string()?atoi(obj["groupheight"].get<std::string>().c_str()):obj["groupheight"].get<int>());
        }
        if(obj.contains("groupwidth"))
        {
            msg.groupwidth = (obj["groupwidth"].is_string()?atoi(obj["groupwidth"].get<std::string>().c_str()):obj["groupwidth"].get<int>());
        }
        if(obj.contains("pooledheight"))
        {
            msg.pooledheight = (obj["pooledheight"].is_string()?atoi(obj["pooledheight"].get<std::string>().c_str()):obj["pooledheight"].get<int>());
        }
        if(obj.contains("pooledwidth"))
        {
            msg.pooledwidth = (obj["pooledwidth"].is_string()?atoi(obj["pooledwidth"].get<std::string>().c_str()):obj["pooledwidth"].get<int>());
        }
        if(obj.contains("padratio"))
        {
            msg.padratio = (obj["padratio"].is_string()?(float)atof(obj["padratio"].get<std::string>().c_str()):obj["padratio"].get<float>());
        }
        if(obj.contains("sampleperpart"))
        {
            msg.sampleperpart = (obj["sampleperpart"].is_string()?atoi(obj["sampleperpart"].get<std::string>().c_str()):obj["sampleperpart"].get<int>());
        }
        if(obj.contains("transstd"))
        {
            msg.transstd = (obj["transstd"].is_string()?(float)atof(obj["transstd"].get<std::string>().c_str()):obj["transstd"].get<float>());
        }
        if(obj.contains("partheight"))
        {
            msg.partheight = (obj["partheight"].is_string()?atoi(obj["partheight"].get<std::string>().c_str()):obj["partheight"].get<int>());
        }
        if(obj.contains("partwidth"))
        {
            msg.partwidth = (obj["partwidth"].is_string()?atoi(obj["partwidth"].get<std::string>().c_str()):obj["partwidth"].get<int>());
        }
        if(obj.contains("heatmapb"))
        {
            msg.heatmapb = (obj["heatmapb"].is_string()?(float)atof(obj["heatmapb"].get<std::string>().c_str()):obj["heatmapb"].get<float>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceDFMBPSROIAlignParameter from_json<ApolloperceptioninferenceDFMBPSROIAlignParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceDFMBPSROIAlignParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceDFMBPSROIAlignParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceDFMBPSROIAlignParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceDFMBPSROIAlignParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceDFMBPSROIAlignParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
