#include "adapter/serialization/apollo_msgs/modulesteleopdaemon_daemon_cmd.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ModulesteleopdaemonDaemonCmd &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["service"] = (msg.service);
        obj["cmd"] = (msg.cmd);
        return obj;
    }
    ModulesteleopdaemonDaemonCmd from_json_ModulesteleopdaemonDaemonCmd (nlohmann::json obj) {
        ModulesteleopdaemonDaemonCmd msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("service"))
        {
            msg.service = (obj["service"].is_string()?(obj["service"].get<std::string>().c_str()):obj["service"].get<std::string>());
        }
        if(obj.contains("cmd"))
        {
            msg.cmd = (obj["cmd"].is_string()?(obj["cmd"].get<std::string>().c_str()):obj["cmd"].get<std::string>());
        }
        return msg;
    }
    template <>
    ModulesteleopdaemonDaemonCmd from_json<ModulesteleopdaemonDaemonCmd>(nlohmann::json obj){
        return from_json_ModulesteleopdaemonDaemonCmd(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ModulesteleopdaemonDaemonCmd &dt)
    {
        dt=from_json_ModulesteleopdaemonDaemonCmd(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ModulesteleopdaemonDaemonCmd & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ModulesteleopdaemonDaemonCmd & dt)
    {
        os << to_json(dt);
        return os;
    }
}
