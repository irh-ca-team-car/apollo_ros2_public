#include "adapter/serialization/apollo_msgs/modulesteleopmodem_modem_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ModulesteleopmodemModemInfo &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["provider"] = (msg.provider);
        obj["ip"] = (msg.ip);
        obj["ipcount"] = (msg.ipcount);
        obj["gateway"] = (msg.gateway);
        obj["port"] = (msg.port);
        obj["dev"] = (msg.dev);
        obj["tx"] = (msg.tx);
        obj["rx"] = (msg.rx);
        obj["ping"] = (msg.ping);
        obj["smoni"] = (msg.smoni);
        obj["technology"] = (msg.technology);
        obj["connection"] = (msg.connection);
        obj["signal"] = (msg.signal);
        obj["quality"] = (msg.quality);
        obj["bandwidthul"] = (msg.bandwidthul);
        obj["bandwidthdl"] = (msg.bandwidthdl);
        obj["caaggregation"] = (msg.caaggregation);
        obj["rank"] = (msg.rank);
        return obj;
    }
    ModulesteleopmodemModemInfo from_json_ModulesteleopmodemModemInfo (nlohmann::json obj) {
        ModulesteleopmodemModemInfo msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("provider"))
        {
            msg.provider = (obj["provider"].is_string()?(obj["provider"].get<std::string>().c_str()):obj["provider"].get<std::string>());
        }
        if(obj.contains("ip"))
        {
            msg.ip = (obj["ip"].is_string()?(obj["ip"].get<std::string>().c_str()):obj["ip"].get<std::string>());
        }
        if(obj.contains("ipcount"))
        {
            msg.ipcount = (obj["ipcount"].is_string()?atoi(obj["ipcount"].get<std::string>().c_str()):obj["ipcount"].get<int>());
        }
        if(obj.contains("gateway"))
        {
            msg.gateway = (obj["gateway"].is_string()?(obj["gateway"].get<std::string>().c_str()):obj["gateway"].get<std::string>());
        }
        if(obj.contains("port"))
        {
            msg.port = (obj["port"].is_string()?(obj["port"].get<std::string>().c_str()):obj["port"].get<std::string>());
        }
        if(obj.contains("dev"))
        {
            msg.dev = (obj["dev"].is_string()?(obj["dev"].get<std::string>().c_str()):obj["dev"].get<std::string>());
        }
        if(obj.contains("tx"))
        {
            msg.tx = (obj["tx"].is_string()?atol(obj["tx"].get<std::string>().c_str()):obj["tx"].get<uint64_t>());
        }
        if(obj.contains("rx"))
        {
            msg.rx = (obj["rx"].is_string()?atol(obj["rx"].get<std::string>().c_str()):obj["rx"].get<uint64_t>());
        }
        if(obj.contains("ping"))
        {
            msg.ping = (obj["ping"].is_string()?(obj["ping"].get<std::string>().c_str()):obj["ping"].get<std::string>());
        }
        if(obj.contains("smoni"))
        {
            msg.smoni = (obj["smoni"].is_string()?(obj["smoni"].get<std::string>().c_str()):obj["smoni"].get<std::string>());
        }
        if(obj.contains("technology"))
        {
            msg.technology = (obj["technology"].is_string()?(obj["technology"].get<std::string>().c_str()):obj["technology"].get<std::string>());
        }
        if(obj.contains("connection"))
        {
            msg.connection = (obj["connection"].is_string()?(obj["connection"].get<std::string>().c_str()):obj["connection"].get<std::string>());
        }
        if(obj.contains("signal"))
        {
            msg.signal = (obj["signal"].is_string()?atoi(obj["signal"].get<std::string>().c_str()):obj["signal"].get<int>());
        }
        if(obj.contains("quality"))
        {
            msg.quality = (obj["quality"].is_string()?atoi(obj["quality"].get<std::string>().c_str()):obj["quality"].get<int>());
        }
        if(obj.contains("bandwidthul"))
        {
            msg.bandwidthul = (obj["bandwidthul"].is_string()?atoi(obj["bandwidthul"].get<std::string>().c_str()):obj["bandwidthul"].get<int>());
        }
        if(obj.contains("bandwidthdl"))
        {
            msg.bandwidthdl = (obj["bandwidthdl"].is_string()?atoi(obj["bandwidthdl"].get<std::string>().c_str()):obj["bandwidthdl"].get<int>());
        }
        if(obj.contains("caaggregation"))
        {
            msg.caaggregation = (obj["caaggregation"].is_string()?(bool)atoi(obj["caaggregation"].get<std::string>().c_str()):obj["caaggregation"].get<bool>());
        }
        if(obj.contains("rank"))
        {
            msg.rank = (obj["rank"].is_string()?atoi(obj["rank"].get<std::string>().c_str()):obj["rank"].get<int>());
        }
        return msg;
    }
    template <>
    ModulesteleopmodemModemInfo from_json<ModulesteleopmodemModemInfo>(nlohmann::json obj){
        return from_json_ModulesteleopmodemModemInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ModulesteleopmodemModemInfo &dt)
    {
        dt=from_json_ModulesteleopmodemModemInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ModulesteleopmodemModemInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ModulesteleopmodemModemInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
