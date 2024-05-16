#include "adapter/serialization/apollo_msgs/apollodriversrobosense_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversrobosenseConfig &msg) {
        nlohmann::json obj;
        obj["model"] = (msg.model);
        obj["frameid"] = (msg.frameid);
        obj["ip"] = (msg.ip);
        obj["msopport"] = (msg.msopport);
        obj["difopport"] = (msg.difopport);
        obj["echomode6"] = (msg.echomode6);
        obj["startangle"] = (msg.startangle);
        obj["endangle"] = (msg.endangle);
        obj["mindistance"] = (msg.mindistance);
        obj["maxdistance"] = (msg.maxdistance);
        obj["cutangle"] = (msg.cutangle);
        obj["pointcloudchannel"] = (msg.pointcloudchannel);
        obj["scanchannel"] = (msg.scanchannel);
        obj["calibrationfile15"] = (msg.calibrationfile15);
        obj["uselidarclock"] = (msg.uselidarclock);
        return obj;
    }
    ApollodriversrobosenseConfig from_json_ApollodriversrobosenseConfig (nlohmann::json obj) {
        ApollodriversrobosenseConfig msg;
        if(obj.contains("model"))
        {
            msg.model = (obj["model"].is_string()?(obj["model"].get<std::string>().c_str()):obj["model"].get<std::string>());
        }
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("ip"))
        {
            msg.ip = (obj["ip"].is_string()?(obj["ip"].get<std::string>().c_str()):obj["ip"].get<std::string>());
        }
        if(obj.contains("msopport"))
        {
            msg.msopport = (obj["msopport"].is_string()?atoi(obj["msopport"].get<std::string>().c_str()):obj["msopport"].get<uint32_t>());
        }
        if(obj.contains("difopport"))
        {
            msg.difopport = (obj["difopport"].is_string()?atoi(obj["difopport"].get<std::string>().c_str()):obj["difopport"].get<uint32_t>());
        }
        if(obj.contains("echomode6"))
        {
            msg.echomode6 = (obj["echomode6"].is_string()?atoi(obj["echomode6"].get<std::string>().c_str()):obj["echomode6"].get<uint32_t>());
        }
        if(obj.contains("startangle"))
        {
            msg.startangle = (obj["startangle"].is_string()?atoi(obj["startangle"].get<std::string>().c_str()):obj["startangle"].get<uint32_t>());
        }
        if(obj.contains("endangle"))
        {
            msg.endangle = (obj["endangle"].is_string()?atoi(obj["endangle"].get<std::string>().c_str()):obj["endangle"].get<uint32_t>());
        }
        if(obj.contains("mindistance"))
        {
            msg.mindistance = (obj["mindistance"].is_string()?atoi(obj["mindistance"].get<std::string>().c_str()):obj["mindistance"].get<uint32_t>());
        }
        if(obj.contains("maxdistance"))
        {
            msg.maxdistance = (obj["maxdistance"].is_string()?atoi(obj["maxdistance"].get<std::string>().c_str()):obj["maxdistance"].get<uint32_t>());
        }
        if(obj.contains("cutangle"))
        {
            msg.cutangle = (obj["cutangle"].is_string()?atoi(obj["cutangle"].get<std::string>().c_str()):obj["cutangle"].get<uint32_t>());
        }
        if(obj.contains("pointcloudchannel"))
        {
            msg.pointcloudchannel = (obj["pointcloudchannel"].is_string()?(obj["pointcloudchannel"].get<std::string>().c_str()):obj["pointcloudchannel"].get<std::string>());
        }
        if(obj.contains("scanchannel"))
        {
            msg.scanchannel = (obj["scanchannel"].is_string()?(obj["scanchannel"].get<std::string>().c_str()):obj["scanchannel"].get<std::string>());
        }
        if(obj.contains("calibrationfile15"))
        {
            msg.calibrationfile15 = (obj["calibrationfile15"].is_string()?(obj["calibrationfile15"].get<std::string>().c_str()):obj["calibrationfile15"].get<std::string>());
        }
        if(obj.contains("uselidarclock"))
        {
            msg.uselidarclock = (obj["uselidarclock"].is_string()?(bool)atoi(obj["uselidarclock"].get<std::string>().c_str()):obj["uselidarclock"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollodriversrobosenseConfig from_json<ApollodriversrobosenseConfig>(nlohmann::json obj){
        return from_json_ApollodriversrobosenseConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversrobosenseConfig &dt)
    {
        dt=from_json_ApollodriversrobosenseConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversrobosenseConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversrobosenseConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
