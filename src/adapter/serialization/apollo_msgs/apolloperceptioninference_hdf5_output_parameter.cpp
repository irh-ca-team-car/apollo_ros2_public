#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hdf5_output_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceHDF5OutputParameter &msg) {
        nlohmann::json obj;
        obj["filename"] = (msg.filename);
        return obj;
    }
    ApolloperceptioninferenceHDF5OutputParameter from_json_ApolloperceptioninferenceHDF5OutputParameter (nlohmann::json obj) {
        ApolloperceptioninferenceHDF5OutputParameter msg;
        if(obj.contains("filename"))
        {
            msg.filename = (obj["filename"].is_string()?(obj["filename"].get<std::string>().c_str()):obj["filename"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceHDF5OutputParameter from_json<ApolloperceptioninferenceHDF5OutputParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceHDF5OutputParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceHDF5OutputParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceHDF5OutputParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceHDF5OutputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceHDF5OutputParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
