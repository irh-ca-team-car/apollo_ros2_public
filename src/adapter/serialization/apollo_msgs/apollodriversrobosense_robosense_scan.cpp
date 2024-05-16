#include "adapter/serialization/apollo_msgs/apollodriversrobosense_robosense_scan.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversrobosenseRobosenseScan &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["model"] = (msg.model);
        nlohmann::json arr_firingpkts;
        for (auto it = msg.firingpkts.begin(); it != msg.firingpkts.end(); ++it) {
            arr_firingpkts.push_back(to_json(*it));
        }
        obj["firingpkts"] = arr_firingpkts;
        obj["basetime"] = (msg.basetime);
        return obj;
    }
    ApollodriversrobosenseRobosenseScan from_json_ApollodriversrobosenseRobosenseScan (nlohmann::json obj) {
        ApollodriversrobosenseRobosenseScan msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("model"))
        {
            msg.model = (obj["model"].is_string()?(obj["model"].get<std::string>().c_str()):obj["model"].get<std::string>());
        }
        if(obj.contains("firingpkts"))
        {
            if(obj["firingpkts"].is_array())
            {
                for (auto& element : obj["firingpkts"])
                {
                    msg.firingpkts.push_back(from_json_ApollodriversrobosenseRobosenseScanPacket(element));
                }
            }
            else
            {
                msg.firingpkts.push_back(from_json_ApollodriversrobosenseRobosenseScanPacket(obj["firingpkts"]));
            }
        }
        if(obj.contains("basetime"))
        {
            msg.basetime = (obj["basetime"].is_string()?atol(obj["basetime"].get<std::string>().c_str()):obj["basetime"].get<uint64_t>());
        }
        return msg;
    }
    template <>
    ApollodriversrobosenseRobosenseScan from_json<ApollodriversrobosenseRobosenseScan>(nlohmann::json obj){
        return from_json_ApollodriversrobosenseRobosenseScan(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversrobosenseRobosenseScan &dt)
    {
        dt=from_json_ApollodriversrobosenseRobosenseScan(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversrobosenseRobosenseScan & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversrobosenseRobosenseScan & dt)
    {
        os << to_json(dt);
        return os;
    }
}
