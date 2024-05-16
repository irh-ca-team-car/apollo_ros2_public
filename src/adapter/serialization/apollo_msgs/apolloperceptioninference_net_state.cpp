#include "adapter/serialization/apollo_msgs/apolloperceptioninference_net_state.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNetState &msg) {
        nlohmann::json obj;
        obj["phase"] = (msg.phase);
        obj["level"] = (msg.level);
        nlohmann::json arr_stage;
        for (auto it = msg.stage.begin(); it != msg.stage.end(); ++it) {
            arr_stage.push_back((*it));
        }
        obj["stage"] = arr_stage;
        return obj;
    }
    ApolloperceptioninferenceNetState from_json_ApolloperceptioninferenceNetState (nlohmann::json obj) {
        ApolloperceptioninferenceNetState msg;
        if(obj.contains("phase"))
        {
            msg.phase = (obj["phase"].is_string()?atoi(obj["phase"].get<std::string>().c_str()):obj["phase"].get<int>());
        }
        if(obj.contains("level"))
        {
            msg.level = (obj["level"].is_string()?atoi(obj["level"].get<std::string>().c_str()):obj["level"].get<int>());
        }
        if(obj.contains("stage"))
        {
            if(obj["stage"].is_array())
            {
                for (auto& element : obj["stage"])
                {
                    msg.stage.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.stage.push_back((obj["stage"].is_string()?(obj["stage"].get<std::string>().c_str()):obj["stage"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceNetState from_json<ApolloperceptioninferenceNetState>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceNetState(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNetState &dt)
    {
        dt=from_json_ApolloperceptioninferenceNetState(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNetState & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNetState & dt)
    {
        os << to_json(dt);
        return os;
    }
}
