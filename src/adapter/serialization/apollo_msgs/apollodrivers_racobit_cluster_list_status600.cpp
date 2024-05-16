#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_cluster_list_status600.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRacobitClusterListStatus600 &msg) {
        nlohmann::json obj;
        obj["near"] = (msg.near);
        obj["far"] = (msg.far);
        obj["meascounter"] = (msg.meascounter);
        obj["interfaceversion"] = (msg.interfaceversion);
        return obj;
    }
    ApollodriversRacobitClusterListStatus600 from_json_ApollodriversRacobitClusterListStatus600 (nlohmann::json obj) {
        ApollodriversRacobitClusterListStatus600 msg;
        if(obj.contains("near"))
        {
            msg.near = (obj["near"].is_string()?atoi(obj["near"].get<std::string>().c_str()):obj["near"].get<int>());
        }
        if(obj.contains("far"))
        {
            msg.far = (obj["far"].is_string()?atoi(obj["far"].get<std::string>().c_str()):obj["far"].get<int>());
        }
        if(obj.contains("meascounter"))
        {
            msg.meascounter = (obj["meascounter"].is_string()?atoi(obj["meascounter"].get<std::string>().c_str()):obj["meascounter"].get<int>());
        }
        if(obj.contains("interfaceversion"))
        {
            msg.interfaceversion = (obj["interfaceversion"].is_string()?atoi(obj["interfaceversion"].get<std::string>().c_str()):obj["interfaceversion"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversRacobitClusterListStatus600 from_json<ApollodriversRacobitClusterListStatus600>(nlohmann::json obj){
        return from_json_ApollodriversRacobitClusterListStatus600(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRacobitClusterListStatus600 &dt)
    {
        dt=from_json_ApollodriversRacobitClusterListStatus600(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversRacobitClusterListStatus600 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRacobitClusterListStatus600 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
