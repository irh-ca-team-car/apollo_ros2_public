#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_target_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceYoloTargetParameter &msg) {
        nlohmann::json obj;
        obj["negroisratio"] = (msg.negroisratio);
        obj["ignthreshold"] = (msg.ignthreshold);
        obj["negthreshold"] = (msg.negthreshold);
        obj["minheight"] = (msg.minheight);
        obj["biasmatch"] = (msg.biasmatch);
        obj["rescore"] = (msg.rescore);
        obj["oricyc"] = (msg.oricyc);
        obj["objweight"] = (msg.objweight);
        obj["noobjweight"] = (msg.noobjweight);
        obj["numclasses"] = (msg.numclasses);
        nlohmann::json arr_dimensionstatistics;
        for (auto it = msg.dimensionstatistics.begin(); it != msg.dimensionstatistics.end(); ++it) {
            arr_dimensionstatistics.push_back(to_json(*it));
        }
        obj["dimensionstatistics"] = arr_dimensionstatistics;
        return obj;
    }
    ApolloperceptioninferenceYoloTargetParameter from_json_ApolloperceptioninferenceYoloTargetParameter (nlohmann::json obj) {
        ApolloperceptioninferenceYoloTargetParameter msg;
        if(obj.contains("negroisratio"))
        {
            msg.negroisratio = (obj["negroisratio"].is_string()?(float)atof(obj["negroisratio"].get<std::string>().c_str()):obj["negroisratio"].get<float>());
        }
        if(obj.contains("ignthreshold"))
        {
            msg.ignthreshold = (obj["ignthreshold"].is_string()?(float)atof(obj["ignthreshold"].get<std::string>().c_str()):obj["ignthreshold"].get<float>());
        }
        if(obj.contains("negthreshold"))
        {
            msg.negthreshold = (obj["negthreshold"].is_string()?(float)atof(obj["negthreshold"].get<std::string>().c_str()):obj["negthreshold"].get<float>());
        }
        if(obj.contains("minheight"))
        {
            msg.minheight = (obj["minheight"].is_string()?(float)atof(obj["minheight"].get<std::string>().c_str()):obj["minheight"].get<float>());
        }
        if(obj.contains("biasmatch"))
        {
            msg.biasmatch = (obj["biasmatch"].is_string()?(bool)atoi(obj["biasmatch"].get<std::string>().c_str()):obj["biasmatch"].get<bool>());
        }
        if(obj.contains("rescore"))
        {
            msg.rescore = (obj["rescore"].is_string()?(bool)atoi(obj["rescore"].get<std::string>().c_str()):obj["rescore"].get<bool>());
        }
        if(obj.contains("oricyc"))
        {
            msg.oricyc = (obj["oricyc"].is_string()?atoi(obj["oricyc"].get<std::string>().c_str()):obj["oricyc"].get<int>());
        }
        if(obj.contains("objweight"))
        {
            msg.objweight = (obj["objweight"].is_string()?(float)atof(obj["objweight"].get<std::string>().c_str()):obj["objweight"].get<float>());
        }
        if(obj.contains("noobjweight"))
        {
            msg.noobjweight = (obj["noobjweight"].is_string()?(float)atof(obj["noobjweight"].get<std::string>().c_str()):obj["noobjweight"].get<float>());
        }
        if(obj.contains("numclasses"))
        {
            msg.numclasses = (obj["numclasses"].is_string()?atoi(obj["numclasses"].get<std::string>().c_str()):obj["numclasses"].get<int>());
        }
        if(obj.contains("dimensionstatistics"))
        {
            if(obj["dimensionstatistics"].is_array())
            {
                for (auto& element : obj["dimensionstatistics"])
                {
                    msg.dimensionstatistics.push_back(from_json_ApolloperceptioninferenceDimensionStatistics(element));
                }
            }
            else
            {
                msg.dimensionstatistics.push_back(from_json_ApolloperceptioninferenceDimensionStatistics(obj["dimensionstatistics"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceYoloTargetParameter from_json<ApolloperceptioninferenceYoloTargetParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceYoloTargetParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceYoloTargetParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceYoloTargetParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceYoloTargetParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceYoloTargetParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
