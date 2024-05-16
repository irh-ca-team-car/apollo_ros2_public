#include "adapter/serialization/apollo_msgs/apolloperception_multi_model_config_proto.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionMultiModelConfigProto &msg) {
        nlohmann::json obj;
        nlohmann::json arr_modelconfigs;
        for (auto it = msg.modelconfigs.begin(); it != msg.modelconfigs.end(); ++it) {
            arr_modelconfigs.push_back(to_json(*it));
        }
        obj["modelconfigs"] = arr_modelconfigs;
        return obj;
    }
    ApolloperceptionMultiModelConfigProto from_json_ApolloperceptionMultiModelConfigProto (nlohmann::json obj) {
        ApolloperceptionMultiModelConfigProto msg;
        if(obj.contains("modelconfigs"))
        {
            if(obj["modelconfigs"].is_array())
            {
                for (auto& element : obj["modelconfigs"])
                {
                    msg.modelconfigs.push_back(from_json_ApolloperceptionModelConfigProto(element));
                }
            }
            else
            {
                msg.modelconfigs.push_back(from_json_ApolloperceptionModelConfigProto(obj["modelconfigs"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptionMultiModelConfigProto from_json<ApolloperceptionMultiModelConfigProto>(nlohmann::json obj){
        return from_json_ApolloperceptionMultiModelConfigProto(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionMultiModelConfigProto &dt)
    {
        dt=from_json_ApolloperceptionMultiModelConfigProto(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionMultiModelConfigProto & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionMultiModelConfigProto & dt)
    {
        os << to_json(dt);
        return os;
    }
}
