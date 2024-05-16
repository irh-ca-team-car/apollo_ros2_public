#include "adapter/serialization/apollo_msgs/apolloperceptioninference_slice_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceSliceParameter &msg) {
        nlohmann::json obj;
        obj["axis"] = (msg.axis);
        nlohmann::json arr_slicepoint;
        for (auto it = msg.slicepoint.begin(); it != msg.slicepoint.end(); ++it) {
            arr_slicepoint.push_back((*it));
        }
        obj["slicepoint"] = arr_slicepoint;
        obj["slicedim"] = (msg.slicedim);
        return obj;
    }
    ApolloperceptioninferenceSliceParameter from_json_ApolloperceptioninferenceSliceParameter (nlohmann::json obj) {
        ApolloperceptioninferenceSliceParameter msg;
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("slicepoint"))
        {
            if(obj["slicepoint"].is_array())
            {
                for (auto& element : obj["slicepoint"])
                {
                    msg.slicepoint.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<uint32_t>()));
                }
            }
            else
            {
                msg.slicepoint.push_back((obj["slicepoint"].is_string()?atoi(obj["slicepoint"].get<std::string>().c_str()):obj["slicepoint"].get<uint32_t>()));
            }
        }
        if(obj.contains("slicedim"))
        {
            msg.slicedim = (obj["slicedim"].is_string()?atoi(obj["slicedim"].get<std::string>().c_str()):obj["slicedim"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceSliceParameter from_json<ApolloperceptioninferenceSliceParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceSliceParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceSliceParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceSliceParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceSliceParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceSliceParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
