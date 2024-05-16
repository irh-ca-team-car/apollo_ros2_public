#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_object_list_status60_a.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRacobitObjectListStatus60A &msg) {
        nlohmann::json obj;
        obj["nofobjects"] = (msg.nofobjects);
        obj["meascounter"] = (msg.meascounter);
        obj["interfaceversion"] = (msg.interfaceversion);
        return obj;
    }
    ApollodriversRacobitObjectListStatus60A from_json_ApollodriversRacobitObjectListStatus60A (nlohmann::json obj) {
        ApollodriversRacobitObjectListStatus60A msg;
        if(obj.contains("nofobjects"))
        {
            msg.nofobjects = (obj["nofobjects"].is_string()?atoi(obj["nofobjects"].get<std::string>().c_str()):obj["nofobjects"].get<int>());
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
    ApollodriversRacobitObjectListStatus60A from_json<ApollodriversRacobitObjectListStatus60A>(nlohmann::json obj){
        return from_json_ApollodriversRacobitObjectListStatus60A(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRacobitObjectListStatus60A &dt)
    {
        dt=from_json_ApollodriversRacobitObjectListStatus60A(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversRacobitObjectListStatus60A & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRacobitObjectListStatus60A & dt)
    {
        os << to_json(dt);
        return os;
    }
}
