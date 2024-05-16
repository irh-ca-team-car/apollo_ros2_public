#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hdf5_data_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceHDF5DataParameter &msg) {
        nlohmann::json obj;
        obj["source"] = (msg.source);
        obj["batchsize"] = (msg.batchsize);
        obj["shuffle"] = (msg.shuffle);
        return obj;
    }
    ApolloperceptioninferenceHDF5DataParameter from_json_ApolloperceptioninferenceHDF5DataParameter (nlohmann::json obj) {
        ApolloperceptioninferenceHDF5DataParameter msg;
        if(obj.contains("source"))
        {
            msg.source = (obj["source"].is_string()?(obj["source"].get<std::string>().c_str()):obj["source"].get<std::string>());
        }
        if(obj.contains("batchsize"))
        {
            msg.batchsize = (obj["batchsize"].is_string()?atoi(obj["batchsize"].get<std::string>().c_str()):obj["batchsize"].get<uint32_t>());
        }
        if(obj.contains("shuffle"))
        {
            msg.shuffle = (obj["shuffle"].is_string()?(bool)atoi(obj["shuffle"].get<std::string>().c_str()):obj["shuffle"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceHDF5DataParameter from_json<ApolloperceptioninferenceHDF5DataParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceHDF5DataParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceHDF5DataParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceHDF5DataParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceHDF5DataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceHDF5DataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
