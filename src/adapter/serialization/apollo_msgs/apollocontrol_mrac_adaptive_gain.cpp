#include "adapter/serialization/apollo_msgs/apollocontrol_mrac_adaptive_gain.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolMracAdaptiveGain &msg) {
        nlohmann::json obj;
        nlohmann::json arr_stateadaptivegain;
        for (auto it = msg.stateadaptivegain.begin(); it != msg.stateadaptivegain.end(); ++it) {
            arr_stateadaptivegain.push_back((*it));
        }
        obj["stateadaptivegain"] = arr_stateadaptivegain;
        nlohmann::json arr_inputadaptivegain;
        for (auto it = msg.inputadaptivegain.begin(); it != msg.inputadaptivegain.end(); ++it) {
            arr_inputadaptivegain.push_back((*it));
        }
        obj["inputadaptivegain"] = arr_inputadaptivegain;
        nlohmann::json arr_nonlinearadaptivegain;
        for (auto it = msg.nonlinearadaptivegain.begin(); it != msg.nonlinearadaptivegain.end(); ++it) {
            arr_nonlinearadaptivegain.push_back((*it));
        }
        obj["nonlinearadaptivegain"] = arr_nonlinearadaptivegain;
        return obj;
    }
    ApollocontrolMracAdaptiveGain from_json_ApollocontrolMracAdaptiveGain (nlohmann::json obj) {
        ApollocontrolMracAdaptiveGain msg;
        if(obj.contains("stateadaptivegain"))
        {
            if(obj["stateadaptivegain"].is_array())
            {
                for (auto& element : obj["stateadaptivegain"])
                {
                    msg.stateadaptivegain.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.stateadaptivegain.push_back((obj["stateadaptivegain"].is_string()?atof(obj["stateadaptivegain"].get<std::string>().c_str()):obj["stateadaptivegain"].get<double>()));
            }
        }
        if(obj.contains("inputadaptivegain"))
        {
            if(obj["inputadaptivegain"].is_array())
            {
                for (auto& element : obj["inputadaptivegain"])
                {
                    msg.inputadaptivegain.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.inputadaptivegain.push_back((obj["inputadaptivegain"].is_string()?atof(obj["inputadaptivegain"].get<std::string>().c_str()):obj["inputadaptivegain"].get<double>()));
            }
        }
        if(obj.contains("nonlinearadaptivegain"))
        {
            if(obj["nonlinearadaptivegain"].is_array())
            {
                for (auto& element : obj["nonlinearadaptivegain"])
                {
                    msg.nonlinearadaptivegain.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.nonlinearadaptivegain.push_back((obj["nonlinearadaptivegain"].is_string()?atof(obj["nonlinearadaptivegain"].get<std::string>().c_str()):obj["nonlinearadaptivegain"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApollocontrolMracAdaptiveGain from_json<ApollocontrolMracAdaptiveGain>(nlohmann::json obj){
        return from_json_ApollocontrolMracAdaptiveGain(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolMracAdaptiveGain &dt)
    {
        dt=from_json_ApollocontrolMracAdaptiveGain(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolMracAdaptiveGain & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolMracAdaptiveGain & dt)
    {
        os << to_json(dt);
        return os;
    }
}
