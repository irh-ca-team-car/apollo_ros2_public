#include "adapter/serialization/apollo_msgs/apolloperceptionlidar_mlf_engine_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionlidarMlfEngineConfig &msg) {
        nlohmann::json obj;
        nlohmann::json arr_mainsensor;
        for (auto it = msg.mainsensor.begin(); it != msg.mainsensor.end(); ++it) {
            arr_mainsensor.push_back((*it));
        }
        obj["mainsensor"] = arr_mainsensor;
        obj["usehistogramformatch"] = (msg.usehistogramformatch);
        obj["histogrambinsize"] = (msg.histogrambinsize);
        obj["outputpredictobjects"] = (msg.outputpredictobjects);
        obj["reservedinvisibletime"] = (msg.reservedinvisibletime);
        obj["useframetimestamp"] = (msg.useframetimestamp);
        return obj;
    }
    ApolloperceptionlidarMlfEngineConfig from_json_ApolloperceptionlidarMlfEngineConfig (nlohmann::json obj) {
        ApolloperceptionlidarMlfEngineConfig msg;
        if(obj.contains("mainsensor"))
        {
            if(obj["mainsensor"].is_array())
            {
                for (auto& element : obj["mainsensor"])
                {
                    msg.mainsensor.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.mainsensor.push_back((obj["mainsensor"].is_string()?(obj["mainsensor"].get<std::string>().c_str()):obj["mainsensor"].get<std::string>()));
            }
        }
        if(obj.contains("usehistogramformatch"))
        {
            msg.usehistogramformatch = (obj["usehistogramformatch"].is_string()?(bool)atoi(obj["usehistogramformatch"].get<std::string>().c_str()):obj["usehistogramformatch"].get<bool>());
        }
        if(obj.contains("histogrambinsize"))
        {
            msg.histogrambinsize = (obj["histogrambinsize"].is_string()?atoi(obj["histogrambinsize"].get<std::string>().c_str()):obj["histogrambinsize"].get<uint32_t>());
        }
        if(obj.contains("outputpredictobjects"))
        {
            msg.outputpredictobjects = (obj["outputpredictobjects"].is_string()?(bool)atoi(obj["outputpredictobjects"].get<std::string>().c_str()):obj["outputpredictobjects"].get<bool>());
        }
        if(obj.contains("reservedinvisibletime"))
        {
            msg.reservedinvisibletime = (obj["reservedinvisibletime"].is_string()?atof(obj["reservedinvisibletime"].get<std::string>().c_str()):obj["reservedinvisibletime"].get<double>());
        }
        if(obj.contains("useframetimestamp"))
        {
            msg.useframetimestamp = (obj["useframetimestamp"].is_string()?(bool)atoi(obj["useframetimestamp"].get<std::string>().c_str()):obj["useframetimestamp"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloperceptionlidarMlfEngineConfig from_json<ApolloperceptionlidarMlfEngineConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionlidarMlfEngineConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionlidarMlfEngineConfig &dt)
    {
        dt=from_json_ApolloperceptionlidarMlfEngineConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionlidarMlfEngineConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionlidarMlfEngineConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
