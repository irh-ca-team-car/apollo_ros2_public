#include "adapter/serialization/apollo_msgs/apolloperceptiononboard_fusion_component_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptiononboardFusionComponentConfig &msg) {
        nlohmann::json obj;
        obj["fusionmethod"] = (msg.fusionmethod);
        nlohmann::json arr_fusionmainsensors;
        for (auto it = msg.fusionmainsensors.begin(); it != msg.fusionmainsensors.end(); ++it) {
            arr_fusionmainsensors.push_back((*it));
        }
        obj["fusionmainsensors"] = arr_fusionmainsensors;
        obj["objectinroicheck"] = (msg.objectinroicheck);
        obj["radiusforroiobjectcheck"] = (msg.radiusforroiobjectcheck);
        obj["outputobstacleschannelname"] = (msg.outputobstacleschannelname);
        obj["outputvizfusedcontentchannelname"] = (msg.outputvizfusedcontentchannelname);
        return obj;
    }
    ApolloperceptiononboardFusionComponentConfig from_json_ApolloperceptiononboardFusionComponentConfig (nlohmann::json obj) {
        ApolloperceptiononboardFusionComponentConfig msg;
        if(obj.contains("fusionmethod"))
        {
            msg.fusionmethod = (obj["fusionmethod"].is_string()?(obj["fusionmethod"].get<std::string>().c_str()):obj["fusionmethod"].get<std::string>());
        }
        if(obj.contains("fusionmainsensors"))
        {
            if(obj["fusionmainsensors"].is_array())
            {
                for (auto& element : obj["fusionmainsensors"])
                {
                    msg.fusionmainsensors.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.fusionmainsensors.push_back((obj["fusionmainsensors"].is_string()?(obj["fusionmainsensors"].get<std::string>().c_str()):obj["fusionmainsensors"].get<std::string>()));
            }
        }
        if(obj.contains("objectinroicheck"))
        {
            msg.objectinroicheck = (obj["objectinroicheck"].is_string()?(bool)atoi(obj["objectinroicheck"].get<std::string>().c_str()):obj["objectinroicheck"].get<bool>());
        }
        if(obj.contains("radiusforroiobjectcheck"))
        {
            msg.radiusforroiobjectcheck = (obj["radiusforroiobjectcheck"].is_string()?atof(obj["radiusforroiobjectcheck"].get<std::string>().c_str()):obj["radiusforroiobjectcheck"].get<double>());
        }
        if(obj.contains("outputobstacleschannelname"))
        {
            msg.outputobstacleschannelname = (obj["outputobstacleschannelname"].is_string()?(obj["outputobstacleschannelname"].get<std::string>().c_str()):obj["outputobstacleschannelname"].get<std::string>());
        }
        if(obj.contains("outputvizfusedcontentchannelname"))
        {
            msg.outputvizfusedcontentchannelname = (obj["outputvizfusedcontentchannelname"].is_string()?(obj["outputvizfusedcontentchannelname"].get<std::string>().c_str()):obj["outputvizfusedcontentchannelname"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptiononboardFusionComponentConfig from_json<ApolloperceptiononboardFusionComponentConfig>(nlohmann::json obj){
        return from_json_ApolloperceptiononboardFusionComponentConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptiononboardFusionComponentConfig &dt)
    {
        dt=from_json_ApolloperceptiononboardFusionComponentConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptiononboardFusionComponentConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptiononboardFusionComponentConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
