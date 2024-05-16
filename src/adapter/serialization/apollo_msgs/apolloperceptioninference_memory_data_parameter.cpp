#include "adapter/serialization/apollo_msgs/apolloperceptioninference_memory_data_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceMemoryDataParameter &msg) {
        nlohmann::json obj;
        obj["batchsize"] = (msg.batchsize);
        obj["channels"] = (msg.channels);
        obj["height"] = (msg.height);
        obj["width"] = (msg.width);
        return obj;
    }
    ApolloperceptioninferenceMemoryDataParameter from_json_ApolloperceptioninferenceMemoryDataParameter (nlohmann::json obj) {
        ApolloperceptioninferenceMemoryDataParameter msg;
        if(obj.contains("batchsize"))
        {
            msg.batchsize = (obj["batchsize"].is_string()?atoi(obj["batchsize"].get<std::string>().c_str()):obj["batchsize"].get<uint32_t>());
        }
        if(obj.contains("channels"))
        {
            msg.channels = (obj["channels"].is_string()?atoi(obj["channels"].get<std::string>().c_str()):obj["channels"].get<uint32_t>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atoi(obj["height"].get<std::string>().c_str()):obj["height"].get<uint32_t>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceMemoryDataParameter from_json<ApolloperceptioninferenceMemoryDataParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceMemoryDataParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceMemoryDataParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceMemoryDataParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceMemoryDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceMemoryDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
