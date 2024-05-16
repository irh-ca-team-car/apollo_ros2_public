#include "adapter/serialization/apollo_msgs/apolloperception_model_config_file_list_proto.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionModelConfigFileListProto &msg) {
        nlohmann::json obj;
        nlohmann::json arr_modelconfigpath;
        for (auto it = msg.modelconfigpath.begin(); it != msg.modelconfigpath.end(); ++it) {
            arr_modelconfigpath.push_back((*it));
        }
        obj["modelconfigpath"] = arr_modelconfigpath;
        return obj;
    }
    ApolloperceptionModelConfigFileListProto from_json_ApolloperceptionModelConfigFileListProto (nlohmann::json obj) {
        ApolloperceptionModelConfigFileListProto msg;
        if(obj.contains("modelconfigpath"))
        {
            if(obj["modelconfigpath"].is_array())
            {
                for (auto& element : obj["modelconfigpath"])
                {
                    msg.modelconfigpath.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.modelconfigpath.push_back((obj["modelconfigpath"].is_string()?(obj["modelconfigpath"].get<std::string>().c_str()):obj["modelconfigpath"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionModelConfigFileListProto from_json<ApolloperceptionModelConfigFileListProto>(nlohmann::json obj){
        return from_json_ApolloperceptionModelConfigFileListProto(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionModelConfigFileListProto &dt)
    {
        dt=from_json_ApolloperceptionModelConfigFileListProto(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionModelConfigFileListProto & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionModelConfigFileListProto & dt)
    {
        os << to_json(dt);
        return os;
    }
}
