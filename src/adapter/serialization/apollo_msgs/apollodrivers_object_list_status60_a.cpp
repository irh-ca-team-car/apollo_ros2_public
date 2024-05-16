#include "adapter/serialization/apollo_msgs/apollodrivers_object_list_status60_a.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversObjectListStatus60A &msg) {
        nlohmann::json obj;
        obj["nofobjects"] = (msg.nofobjects);
        obj["meascounter"] = (msg.meascounter);
        obj["interfaceversion"] = (msg.interfaceversion);
        return obj;
    }
    ApollodriversObjectListStatus60A from_json_ApollodriversObjectListStatus60A (nlohmann::json obj) {
        ApollodriversObjectListStatus60A msg;
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
    ApollodriversObjectListStatus60A from_json<ApollodriversObjectListStatus60A>(nlohmann::json obj){
        return from_json_ApollodriversObjectListStatus60A(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversObjectListStatus60A &dt)
    {
        dt=from_json_ApollodriversObjectListStatus60A(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversObjectListStatus60A & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversObjectListStatus60A & dt)
    {
        os << to_json(dt);
        return os;
    }
}
