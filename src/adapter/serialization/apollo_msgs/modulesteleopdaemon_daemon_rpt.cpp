#include "adapter/serialization/apollo_msgs/modulesteleopdaemon_daemon_rpt.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ModulesteleopdaemonDaemonRpt &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_services;
        for (auto it = msg.services.begin(); it != msg.services.end(); ++it) {
            arr_services.push_back((*it));
        }
        obj["services"] = arr_services;
        return obj;
    }
    ModulesteleopdaemonDaemonRpt from_json_ModulesteleopdaemonDaemonRpt (nlohmann::json obj) {
        ModulesteleopdaemonDaemonRpt msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("services"))
        {
            if(obj["services"].is_array())
            {
                for (auto& element : obj["services"])
                {
                    msg.services.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.services.push_back((obj["services"].is_string()?(obj["services"].get<std::string>().c_str()):obj["services"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ModulesteleopdaemonDaemonRpt from_json<ModulesteleopdaemonDaemonRpt>(nlohmann::json obj){
        return from_json_ModulesteleopdaemonDaemonRpt(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ModulesteleopdaemonDaemonRpt &dt)
    {
        dt=from_json_ModulesteleopdaemonDaemonRpt(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ModulesteleopdaemonDaemonRpt & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ModulesteleopdaemonDaemonRpt & dt)
    {
        os << to_json(dt);
        return os;
    }
}
