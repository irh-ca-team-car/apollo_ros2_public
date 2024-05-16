#include "adapter/serialization/apollo_msgs/apolloperceptioninference_multi_box_loss_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceMultiBoxLossParameter &msg) {
        nlohmann::json obj;
        obj["loclosstype"] = (msg.loclosstype);
        obj["conflosstype"] = (msg.conflosstype);
        obj["locweight"] = (msg.locweight);
        obj["numclasses"] = (msg.numclasses);
        obj["sharelocation"] = (msg.sharelocation);
        obj["matchtype"] = (msg.matchtype);
        obj["overlapthreshold"] = (msg.overlapthreshold);
        obj["usepriorformatching"] = (msg.usepriorformatching);
        obj["backgroundlabelid"] = (msg.backgroundlabelid);
        obj["usedifficultgt"] = (msg.usedifficultgt);
        obj["donegmining"] = (msg.donegmining);
        obj["negposratio"] = (msg.negposratio);
        obj["negoverlap"] = (msg.negoverlap);
        obj["codetype"] = (msg.codetype);
        obj["encodevarianceintarget"] = (msg.encodevarianceintarget);
        obj["mapobjecttoagnostic"] = (msg.mapobjecttoagnostic);
        obj["ignorecrossboundarybbox"] = (msg.ignorecrossboundarybbox);
        obj["bpinside"] = (msg.bpinside);
        obj["miningtype"] = (msg.miningtype);
        obj["nmsparam"] = to_json(msg.nmsparam);
        obj["samplesize"] = (msg.samplesize);
        obj["usepriorfornms"] = (msg.usepriorfornms);
        return obj;
    }
    ApolloperceptioninferenceMultiBoxLossParameter from_json_ApolloperceptioninferenceMultiBoxLossParameter (nlohmann::json obj) {
        ApolloperceptioninferenceMultiBoxLossParameter msg;
        if(obj.contains("loclosstype"))
        {
            msg.loclosstype = (obj["loclosstype"].is_string()?atoi(obj["loclosstype"].get<std::string>().c_str()):obj["loclosstype"].get<int>());
        }
        if(obj.contains("conflosstype"))
        {
            msg.conflosstype = (obj["conflosstype"].is_string()?atoi(obj["conflosstype"].get<std::string>().c_str()):obj["conflosstype"].get<int>());
        }
        if(obj.contains("locweight"))
        {
            msg.locweight = (obj["locweight"].is_string()?(float)atof(obj["locweight"].get<std::string>().c_str()):obj["locweight"].get<float>());
        }
        if(obj.contains("numclasses"))
        {
            msg.numclasses = (obj["numclasses"].is_string()?atoi(obj["numclasses"].get<std::string>().c_str()):obj["numclasses"].get<uint32_t>());
        }
        if(obj.contains("sharelocation"))
        {
            msg.sharelocation = (obj["sharelocation"].is_string()?(bool)atoi(obj["sharelocation"].get<std::string>().c_str()):obj["sharelocation"].get<bool>());
        }
        if(obj.contains("matchtype"))
        {
            msg.matchtype = (obj["matchtype"].is_string()?atoi(obj["matchtype"].get<std::string>().c_str()):obj["matchtype"].get<int>());
        }
        if(obj.contains("overlapthreshold"))
        {
            msg.overlapthreshold = (obj["overlapthreshold"].is_string()?(float)atof(obj["overlapthreshold"].get<std::string>().c_str()):obj["overlapthreshold"].get<float>());
        }
        if(obj.contains("usepriorformatching"))
        {
            msg.usepriorformatching = (obj["usepriorformatching"].is_string()?(bool)atoi(obj["usepriorformatching"].get<std::string>().c_str()):obj["usepriorformatching"].get<bool>());
        }
        if(obj.contains("backgroundlabelid"))
        {
            msg.backgroundlabelid = (obj["backgroundlabelid"].is_string()?atoi(obj["backgroundlabelid"].get<std::string>().c_str()):obj["backgroundlabelid"].get<uint32_t>());
        }
        if(obj.contains("usedifficultgt"))
        {
            msg.usedifficultgt = (obj["usedifficultgt"].is_string()?(bool)atoi(obj["usedifficultgt"].get<std::string>().c_str()):obj["usedifficultgt"].get<bool>());
        }
        if(obj.contains("donegmining"))
        {
            msg.donegmining = (obj["donegmining"].is_string()?(bool)atoi(obj["donegmining"].get<std::string>().c_str()):obj["donegmining"].get<bool>());
        }
        if(obj.contains("negposratio"))
        {
            msg.negposratio = (obj["negposratio"].is_string()?(float)atof(obj["negposratio"].get<std::string>().c_str()):obj["negposratio"].get<float>());
        }
        if(obj.contains("negoverlap"))
        {
            msg.negoverlap = (obj["negoverlap"].is_string()?(float)atof(obj["negoverlap"].get<std::string>().c_str()):obj["negoverlap"].get<float>());
        }
        if(obj.contains("codetype"))
        {
            msg.codetype = (obj["codetype"].is_string()?atoi(obj["codetype"].get<std::string>().c_str()):obj["codetype"].get<int>());
        }
        if(obj.contains("encodevarianceintarget"))
        {
            msg.encodevarianceintarget = (obj["encodevarianceintarget"].is_string()?(bool)atoi(obj["encodevarianceintarget"].get<std::string>().c_str()):obj["encodevarianceintarget"].get<bool>());
        }
        if(obj.contains("mapobjecttoagnostic"))
        {
            msg.mapobjecttoagnostic = (obj["mapobjecttoagnostic"].is_string()?(bool)atoi(obj["mapobjecttoagnostic"].get<std::string>().c_str()):obj["mapobjecttoagnostic"].get<bool>());
        }
        if(obj.contains("ignorecrossboundarybbox"))
        {
            msg.ignorecrossboundarybbox = (obj["ignorecrossboundarybbox"].is_string()?(bool)atoi(obj["ignorecrossboundarybbox"].get<std::string>().c_str()):obj["ignorecrossboundarybbox"].get<bool>());
        }
        if(obj.contains("bpinside"))
        {
            msg.bpinside = (obj["bpinside"].is_string()?(bool)atoi(obj["bpinside"].get<std::string>().c_str()):obj["bpinside"].get<bool>());
        }
        if(obj.contains("miningtype"))
        {
            msg.miningtype = (obj["miningtype"].is_string()?atoi(obj["miningtype"].get<std::string>().c_str()):obj["miningtype"].get<int>());
        }
        if(obj.contains("nmsparam"))
        {
            msg.nmsparam = from_json_ApolloperceptioninferenceNonMaximumSuppressionParameter(obj["nmsparam"]);
        }
        if(obj.contains("samplesize"))
        {
            msg.samplesize = (obj["samplesize"].is_string()?atoi(obj["samplesize"].get<std::string>().c_str()):obj["samplesize"].get<int>());
        }
        if(obj.contains("usepriorfornms"))
        {
            msg.usepriorfornms = (obj["usepriorfornms"].is_string()?(bool)atoi(obj["usepriorfornms"].get<std::string>().c_str()):obj["usepriorfornms"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceMultiBoxLossParameter from_json<ApolloperceptioninferenceMultiBoxLossParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceMultiBoxLossParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceMultiBoxLossParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceMultiBoxLossParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceMultiBoxLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceMultiBoxLossParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
