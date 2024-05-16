#include "adapter/serialization/apollo_msgs/apollodriversconti_radar_radar_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriverscontiRadarRadarConf &msg) {
        nlohmann::json obj;
        obj["maxdistancevalid"] = (msg.maxdistancevalid);
        obj["sensoridvalid"] = (msg.sensoridvalid);
        obj["radarpowervalid"] = (msg.radarpowervalid);
        obj["outputtypevalid"] = (msg.outputtypevalid);
        obj["sendqualityvalid"] = (msg.sendqualityvalid);
        obj["sendextinfovalid"] = (msg.sendextinfovalid);
        obj["sortindexvalid"] = (msg.sortindexvalid);
        obj["storeinnvmvalid"] = (msg.storeinnvmvalid);
        obj["ctrlrelayvalid"] = (msg.ctrlrelayvalid);
        obj["rcsthresholdvalid"] = (msg.rcsthresholdvalid);
        obj["maxdistance"] = (msg.maxdistance);
        obj["sensorid"] = (msg.sensorid);
        obj["outputtype"] = (msg.outputtype);
        obj["radarpower"] = (msg.radarpower);
        obj["ctrlrelay"] = (msg.ctrlrelay);
        obj["sendextinfo"] = (msg.sendextinfo);
        obj["sendquality"] = (msg.sendquality);
        obj["sortindex"] = (msg.sortindex);
        obj["storeinnvm"] = (msg.storeinnvm);
        obj["rcsthreshold"] = (msg.rcsthreshold);
        obj["inputsendinterval"] = (msg.inputsendinterval);
        return obj;
    }
    ApollodriverscontiRadarRadarConf from_json_ApollodriverscontiRadarRadarConf (nlohmann::json obj) {
        ApollodriverscontiRadarRadarConf msg;
        if(obj.contains("maxdistancevalid"))
        {
            msg.maxdistancevalid = (obj["maxdistancevalid"].is_string()?(bool)atoi(obj["maxdistancevalid"].get<std::string>().c_str()):obj["maxdistancevalid"].get<bool>());
        }
        if(obj.contains("sensoridvalid"))
        {
            msg.sensoridvalid = (obj["sensoridvalid"].is_string()?(bool)atoi(obj["sensoridvalid"].get<std::string>().c_str()):obj["sensoridvalid"].get<bool>());
        }
        if(obj.contains("radarpowervalid"))
        {
            msg.radarpowervalid = (obj["radarpowervalid"].is_string()?(bool)atoi(obj["radarpowervalid"].get<std::string>().c_str()):obj["radarpowervalid"].get<bool>());
        }
        if(obj.contains("outputtypevalid"))
        {
            msg.outputtypevalid = (obj["outputtypevalid"].is_string()?(bool)atoi(obj["outputtypevalid"].get<std::string>().c_str()):obj["outputtypevalid"].get<bool>());
        }
        if(obj.contains("sendqualityvalid"))
        {
            msg.sendqualityvalid = (obj["sendqualityvalid"].is_string()?(bool)atoi(obj["sendqualityvalid"].get<std::string>().c_str()):obj["sendqualityvalid"].get<bool>());
        }
        if(obj.contains("sendextinfovalid"))
        {
            msg.sendextinfovalid = (obj["sendextinfovalid"].is_string()?(bool)atoi(obj["sendextinfovalid"].get<std::string>().c_str()):obj["sendextinfovalid"].get<bool>());
        }
        if(obj.contains("sortindexvalid"))
        {
            msg.sortindexvalid = (obj["sortindexvalid"].is_string()?(bool)atoi(obj["sortindexvalid"].get<std::string>().c_str()):obj["sortindexvalid"].get<bool>());
        }
        if(obj.contains("storeinnvmvalid"))
        {
            msg.storeinnvmvalid = (obj["storeinnvmvalid"].is_string()?(bool)atoi(obj["storeinnvmvalid"].get<std::string>().c_str()):obj["storeinnvmvalid"].get<bool>());
        }
        if(obj.contains("ctrlrelayvalid"))
        {
            msg.ctrlrelayvalid = (obj["ctrlrelayvalid"].is_string()?(bool)atoi(obj["ctrlrelayvalid"].get<std::string>().c_str()):obj["ctrlrelayvalid"].get<bool>());
        }
        if(obj.contains("rcsthresholdvalid"))
        {
            msg.rcsthresholdvalid = (obj["rcsthresholdvalid"].is_string()?(bool)atoi(obj["rcsthresholdvalid"].get<std::string>().c_str()):obj["rcsthresholdvalid"].get<bool>());
        }
        if(obj.contains("maxdistance"))
        {
            msg.maxdistance = (obj["maxdistance"].is_string()?atoi(obj["maxdistance"].get<std::string>().c_str()):obj["maxdistance"].get<uint32_t>());
        }
        if(obj.contains("sensorid"))
        {
            msg.sensorid = (obj["sensorid"].is_string()?atoi(obj["sensorid"].get<std::string>().c_str()):obj["sensorid"].get<uint32_t>());
        }
        if(obj.contains("outputtype"))
        {
            msg.outputtype = (obj["outputtype"].is_string()?atoi(obj["outputtype"].get<std::string>().c_str()):obj["outputtype"].get<int>());
        }
        if(obj.contains("radarpower"))
        {
            msg.radarpower = (obj["radarpower"].is_string()?atoi(obj["radarpower"].get<std::string>().c_str()):obj["radarpower"].get<uint32_t>());
        }
        if(obj.contains("ctrlrelay"))
        {
            msg.ctrlrelay = (obj["ctrlrelay"].is_string()?atoi(obj["ctrlrelay"].get<std::string>().c_str()):obj["ctrlrelay"].get<uint32_t>());
        }
        if(obj.contains("sendextinfo"))
        {
            msg.sendextinfo = (obj["sendextinfo"].is_string()?(bool)atoi(obj["sendextinfo"].get<std::string>().c_str()):obj["sendextinfo"].get<bool>());
        }
        if(obj.contains("sendquality"))
        {
            msg.sendquality = (obj["sendquality"].is_string()?(bool)atoi(obj["sendquality"].get<std::string>().c_str()):obj["sendquality"].get<bool>());
        }
        if(obj.contains("sortindex"))
        {
            msg.sortindex = (obj["sortindex"].is_string()?atoi(obj["sortindex"].get<std::string>().c_str()):obj["sortindex"].get<uint32_t>());
        }
        if(obj.contains("storeinnvm"))
        {
            msg.storeinnvm = (obj["storeinnvm"].is_string()?atoi(obj["storeinnvm"].get<std::string>().c_str()):obj["storeinnvm"].get<uint32_t>());
        }
        if(obj.contains("rcsthreshold"))
        {
            msg.rcsthreshold = (obj["rcsthreshold"].is_string()?atoi(obj["rcsthreshold"].get<std::string>().c_str()):obj["rcsthreshold"].get<int>());
        }
        if(obj.contains("inputsendinterval"))
        {
            msg.inputsendinterval = (obj["inputsendinterval"].is_string()?atol(obj["inputsendinterval"].get<std::string>().c_str()):obj["inputsendinterval"].get<uint64_t>());
        }
        return msg;
    }
    template <>
    ApollodriverscontiRadarRadarConf from_json<ApollodriverscontiRadarRadarConf>(nlohmann::json obj){
        return from_json_ApollodriverscontiRadarRadarConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriverscontiRadarRadarConf &dt)
    {
        dt=from_json_ApollodriverscontiRadarRadarConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriverscontiRadarRadarConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriverscontiRadarRadarConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
