#include "adapter/serialization/apollo_msgs/apolloperceptioninference_net_state_rule.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNetStateRule &msg) {
        nlohmann::json obj;
        obj["phase"] = (msg.phase);
        obj["minlevel"] = (msg.minlevel);
        obj["maxlevel"] = (msg.maxlevel);
        nlohmann::json arr_stage;
        for (auto it = msg.stage.begin(); it != msg.stage.end(); ++it) {
            arr_stage.push_back((*it));
        }
        obj["stage"] = arr_stage;
        nlohmann::json arr_notstage;
        for (auto it = msg.notstage.begin(); it != msg.notstage.end(); ++it) {
            arr_notstage.push_back((*it));
        }
        obj["notstage"] = arr_notstage;
        return obj;
    }
    ApolloperceptioninferenceNetStateRule from_json_ApolloperceptioninferenceNetStateRule (nlohmann::json obj) {
        ApolloperceptioninferenceNetStateRule msg;
        if(obj.contains("phase"))
        {
            msg.phase = (obj["phase"].is_string()?atoi(obj["phase"].get<std::string>().c_str()):obj["phase"].get<int>());
        }
        if(obj.contains("minlevel"))
        {
            msg.minlevel = (obj["minlevel"].is_string()?atoi(obj["minlevel"].get<std::string>().c_str()):obj["minlevel"].get<int>());
        }
        if(obj.contains("maxlevel"))
        {
            msg.maxlevel = (obj["maxlevel"].is_string()?atoi(obj["maxlevel"].get<std::string>().c_str()):obj["maxlevel"].get<int>());
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
        if(obj.contains("notstage"))
        {
            if(obj["notstage"].is_array())
            {
                for (auto& element : obj["notstage"])
                {
                    msg.notstage.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.notstage.push_back((obj["notstage"].is_string()?(obj["notstage"].get<std::string>().c_str()):obj["notstage"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceNetStateRule from_json<ApolloperceptioninferenceNetStateRule>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceNetStateRule(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNetStateRule &dt)
    {
        dt=from_json_ApolloperceptioninferenceNetStateRule(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNetStateRule & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNetStateRule & dt)
    {
        os << to_json(dt);
        return os;
    }
}
