#include "adapter/serialization/apollo_msgs/apolloperceptionfusion_probabilistic_fusion_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionfusionProbabilisticFusionConfig &msg) {
        nlohmann::json obj;
        obj["uselidar"] = (msg.uselidar);
        obj["useradar"] = (msg.useradar);
        obj["usecamera"] = (msg.usecamera);
        obj["trackermethod"] = (msg.trackermethod);
        obj["dataassociationmethod"] = (msg.dataassociationmethod);
        obj["gatekeepermethod"] = (msg.gatekeepermethod);
        nlohmann::json arr_prohibitionsensors;
        for (auto it = msg.prohibitionsensors.begin(); it != msg.prohibitionsensors.end(); ++it) {
            arr_prohibitionsensors.push_back((*it));
        }
        obj["prohibitionsensors"] = arr_prohibitionsensors;
        obj["maxlidarinvisibleperiod"] = (msg.maxlidarinvisibleperiod);
        obj["maxradarinvisibleperiod"] = (msg.maxradarinvisibleperiod);
        obj["maxcamerainvisibleperiod"] = (msg.maxcamerainvisibleperiod);
        obj["maxcachedframenum"] = (msg.maxcachedframenum);
        return obj;
    }
    ApolloperceptionfusionProbabilisticFusionConfig from_json_ApolloperceptionfusionProbabilisticFusionConfig (nlohmann::json obj) {
        ApolloperceptionfusionProbabilisticFusionConfig msg;
        if(obj.contains("uselidar"))
        {
            msg.uselidar = (obj["uselidar"].is_string()?(bool)atoi(obj["uselidar"].get<std::string>().c_str()):obj["uselidar"].get<bool>());
        }
        if(obj.contains("useradar"))
        {
            msg.useradar = (obj["useradar"].is_string()?(bool)atoi(obj["useradar"].get<std::string>().c_str()):obj["useradar"].get<bool>());
        }
        if(obj.contains("usecamera"))
        {
            msg.usecamera = (obj["usecamera"].is_string()?(bool)atoi(obj["usecamera"].get<std::string>().c_str()):obj["usecamera"].get<bool>());
        }
        if(obj.contains("trackermethod"))
        {
            msg.trackermethod = (obj["trackermethod"].is_string()?(obj["trackermethod"].get<std::string>().c_str()):obj["trackermethod"].get<std::string>());
        }
        if(obj.contains("dataassociationmethod"))
        {
            msg.dataassociationmethod = (obj["dataassociationmethod"].is_string()?(obj["dataassociationmethod"].get<std::string>().c_str()):obj["dataassociationmethod"].get<std::string>());
        }
        if(obj.contains("gatekeepermethod"))
        {
            msg.gatekeepermethod = (obj["gatekeepermethod"].is_string()?(obj["gatekeepermethod"].get<std::string>().c_str()):obj["gatekeepermethod"].get<std::string>());
        }
        if(obj.contains("prohibitionsensors"))
        {
            if(obj["prohibitionsensors"].is_array())
            {
                for (auto& element : obj["prohibitionsensors"])
                {
                    msg.prohibitionsensors.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.prohibitionsensors.push_back((obj["prohibitionsensors"].is_string()?(obj["prohibitionsensors"].get<std::string>().c_str()):obj["prohibitionsensors"].get<std::string>()));
            }
        }
        if(obj.contains("maxlidarinvisibleperiod"))
        {
            msg.maxlidarinvisibleperiod = (obj["maxlidarinvisibleperiod"].is_string()?atof(obj["maxlidarinvisibleperiod"].get<std::string>().c_str()):obj["maxlidarinvisibleperiod"].get<double>());
        }
        if(obj.contains("maxradarinvisibleperiod"))
        {
            msg.maxradarinvisibleperiod = (obj["maxradarinvisibleperiod"].is_string()?atof(obj["maxradarinvisibleperiod"].get<std::string>().c_str()):obj["maxradarinvisibleperiod"].get<double>());
        }
        if(obj.contains("maxcamerainvisibleperiod"))
        {
            msg.maxcamerainvisibleperiod = (obj["maxcamerainvisibleperiod"].is_string()?atof(obj["maxcamerainvisibleperiod"].get<std::string>().c_str()):obj["maxcamerainvisibleperiod"].get<double>());
        }
        if(obj.contains("maxcachedframenum"))
        {
            msg.maxcachedframenum = (obj["maxcachedframenum"].is_string()?atol(obj["maxcachedframenum"].get<std::string>().c_str()):obj["maxcachedframenum"].get<long>());
        }
        return msg;
    }
    template <>
    ApolloperceptionfusionProbabilisticFusionConfig from_json<ApolloperceptionfusionProbabilisticFusionConfig>(nlohmann::json obj){
        return from_json_ApolloperceptionfusionProbabilisticFusionConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionfusionProbabilisticFusionConfig &dt)
    {
        dt=from_json_ApolloperceptionfusionProbabilisticFusionConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionfusionProbabilisticFusionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionfusionProbabilisticFusionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
