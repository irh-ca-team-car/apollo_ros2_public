#include "adapter/serialization/apollo_msgs/apolloperception_model_config_proto.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionModelConfigProto &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["version"] = (msg.version);
        nlohmann::json arr_integerparams;
        for (auto it = msg.integerparams.begin(); it != msg.integerparams.end(); ++it) {
            arr_integerparams.push_back(to_json(*it));
        }
        obj["integerparams"] = arr_integerparams;
        nlohmann::json arr_stringparams;
        for (auto it = msg.stringparams.begin(); it != msg.stringparams.end(); ++it) {
            arr_stringparams.push_back(to_json(*it));
        }
        obj["stringparams"] = arr_stringparams;
        nlohmann::json arr_doubleparams;
        for (auto it = msg.doubleparams.begin(); it != msg.doubleparams.end(); ++it) {
            arr_doubleparams.push_back(to_json(*it));
        }
        obj["doubleparams"] = arr_doubleparams;
        nlohmann::json arr_floatparams;
        for (auto it = msg.floatparams.begin(); it != msg.floatparams.end(); ++it) {
            arr_floatparams.push_back(to_json(*it));
        }
        obj["floatparams"] = arr_floatparams;
        nlohmann::json arr_boolparams;
        for (auto it = msg.boolparams.begin(); it != msg.boolparams.end(); ++it) {
            arr_boolparams.push_back(to_json(*it));
        }
        obj["boolparams"] = arr_boolparams;
        nlohmann::json arr_arrayintegerparams;
        for (auto it = msg.arrayintegerparams.begin(); it != msg.arrayintegerparams.end(); ++it) {
            arr_arrayintegerparams.push_back(to_json(*it));
        }
        obj["arrayintegerparams"] = arr_arrayintegerparams;
        nlohmann::json arr_arraystringparams;
        for (auto it = msg.arraystringparams.begin(); it != msg.arraystringparams.end(); ++it) {
            arr_arraystringparams.push_back(to_json(*it));
        }
        obj["arraystringparams"] = arr_arraystringparams;
        nlohmann::json arr_arraydoubleparams;
        for (auto it = msg.arraydoubleparams.begin(); it != msg.arraydoubleparams.end(); ++it) {
            arr_arraydoubleparams.push_back(to_json(*it));
        }
        obj["arraydoubleparams"] = arr_arraydoubleparams;
        nlohmann::json arr_arrayfloatparams;
        for (auto it = msg.arrayfloatparams.begin(); it != msg.arrayfloatparams.end(); ++it) {
            arr_arrayfloatparams.push_back(to_json(*it));
        }
        obj["arrayfloatparams"] = arr_arrayfloatparams;
        nlohmann::json arr_arrayboolparams;
        for (auto it = msg.arrayboolparams.begin(); it != msg.arrayboolparams.end(); ++it) {
            arr_arrayboolparams.push_back(to_json(*it));
        }
        obj["arrayboolparams"] = arr_arrayboolparams;
        return obj;
    }
    ApolloperceptionModelConfigProto from_json_ApolloperceptionModelConfigProto (nlohmann::json obj) {
        ApolloperceptionModelConfigProto msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("version"))
        {
            msg.version = (obj["version"].is_string()?(obj["version"].get<std::string>().c_str()):obj["version"].get<std::string>());
        }
        if(obj.contains("integerparams"))
        {
            if(obj["integerparams"].is_array())
            {
                for (auto& element : obj["integerparams"])
                {
                    msg.integerparams.push_back(from_json_ApolloperceptionKeyValueInt(element));
                }
            }
            else
            {
                msg.integerparams.push_back(from_json_ApolloperceptionKeyValueInt(obj["integerparams"]));
            }
        }
        if(obj.contains("stringparams"))
        {
            if(obj["stringparams"].is_array())
            {
                for (auto& element : obj["stringparams"])
                {
                    msg.stringparams.push_back(from_json_ApolloperceptionKeyValueString(element));
                }
            }
            else
            {
                msg.stringparams.push_back(from_json_ApolloperceptionKeyValueString(obj["stringparams"]));
            }
        }
        if(obj.contains("doubleparams"))
        {
            if(obj["doubleparams"].is_array())
            {
                for (auto& element : obj["doubleparams"])
                {
                    msg.doubleparams.push_back(from_json_ApolloperceptionKeyValueDouble(element));
                }
            }
            else
            {
                msg.doubleparams.push_back(from_json_ApolloperceptionKeyValueDouble(obj["doubleparams"]));
            }
        }
        if(obj.contains("floatparams"))
        {
            if(obj["floatparams"].is_array())
            {
                for (auto& element : obj["floatparams"])
                {
                    msg.floatparams.push_back(from_json_ApolloperceptionKeyValueFloat(element));
                }
            }
            else
            {
                msg.floatparams.push_back(from_json_ApolloperceptionKeyValueFloat(obj["floatparams"]));
            }
        }
        if(obj.contains("boolparams"))
        {
            if(obj["boolparams"].is_array())
            {
                for (auto& element : obj["boolparams"])
                {
                    msg.boolparams.push_back(from_json_ApolloperceptionKeyValueBool(element));
                }
            }
            else
            {
                msg.boolparams.push_back(from_json_ApolloperceptionKeyValueBool(obj["boolparams"]));
            }
        }
        if(obj.contains("arrayintegerparams"))
        {
            if(obj["arrayintegerparams"].is_array())
            {
                for (auto& element : obj["arrayintegerparams"])
                {
                    msg.arrayintegerparams.push_back(from_json_ApolloperceptionKeyValueArrayInt(element));
                }
            }
            else
            {
                msg.arrayintegerparams.push_back(from_json_ApolloperceptionKeyValueArrayInt(obj["arrayintegerparams"]));
            }
        }
        if(obj.contains("arraystringparams"))
        {
            if(obj["arraystringparams"].is_array())
            {
                for (auto& element : obj["arraystringparams"])
                {
                    msg.arraystringparams.push_back(from_json_ApolloperceptionKeyValueArrayString(element));
                }
            }
            else
            {
                msg.arraystringparams.push_back(from_json_ApolloperceptionKeyValueArrayString(obj["arraystringparams"]));
            }
        }
        if(obj.contains("arraydoubleparams"))
        {
            if(obj["arraydoubleparams"].is_array())
            {
                for (auto& element : obj["arraydoubleparams"])
                {
                    msg.arraydoubleparams.push_back(from_json_ApolloperceptionKeyValueArrayDouble(element));
                }
            }
            else
            {
                msg.arraydoubleparams.push_back(from_json_ApolloperceptionKeyValueArrayDouble(obj["arraydoubleparams"]));
            }
        }
        if(obj.contains("arrayfloatparams"))
        {
            if(obj["arrayfloatparams"].is_array())
            {
                for (auto& element : obj["arrayfloatparams"])
                {
                    msg.arrayfloatparams.push_back(from_json_ApolloperceptionKeyValueArrayFloat(element));
                }
            }
            else
            {
                msg.arrayfloatparams.push_back(from_json_ApolloperceptionKeyValueArrayFloat(obj["arrayfloatparams"]));
            }
        }
        if(obj.contains("arrayboolparams"))
        {
            if(obj["arrayboolparams"].is_array())
            {
                for (auto& element : obj["arrayboolparams"])
                {
                    msg.arrayboolparams.push_back(from_json_ApolloperceptionKeyValueArrayBool(element));
                }
            }
            else
            {
                msg.arrayboolparams.push_back(from_json_ApolloperceptionKeyValueArrayBool(obj["arrayboolparams"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionModelConfigProto from_json<ApolloperceptionModelConfigProto>(nlohmann::json obj){
        return from_json_ApolloperceptionModelConfigProto(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionModelConfigProto &dt)
    {
        dt=from_json_ApolloperceptionModelConfigProto(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionModelConfigProto & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionModelConfigProto & dt)
    {
        os << to_json(dt);
        return os;
    }
}
