#include "adapter/serialization/apollo_msgs/apollocanbus_fail241.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusFail241 &msg) {
        nlohmann::json obj;
        obj["engfail"] = (msg.engfail);
        obj["espfail"] = (msg.espfail);
        obj["epbfail"] = (msg.epbfail);
        obj["shiftfail"] = (msg.shiftfail);
        obj["epsfail"] = (msg.epsfail);
        return obj;
    }
    ApollocanbusFail241 from_json_ApollocanbusFail241 (nlohmann::json obj) {
        ApollocanbusFail241 msg;
        if(obj.contains("engfail"))
        {
            msg.engfail = (obj["engfail"].is_string()?atoi(obj["engfail"].get<std::string>().c_str()):obj["engfail"].get<int>());
        }
        if(obj.contains("espfail"))
        {
            msg.espfail = (obj["espfail"].is_string()?atoi(obj["espfail"].get<std::string>().c_str()):obj["espfail"].get<int>());
        }
        if(obj.contains("epbfail"))
        {
            msg.epbfail = (obj["epbfail"].is_string()?atoi(obj["epbfail"].get<std::string>().c_str()):obj["epbfail"].get<int>());
        }
        if(obj.contains("shiftfail"))
        {
            msg.shiftfail = (obj["shiftfail"].is_string()?atoi(obj["shiftfail"].get<std::string>().c_str()):obj["shiftfail"].get<int>());
        }
        if(obj.contains("epsfail"))
        {
            msg.epsfail = (obj["epsfail"].is_string()?atoi(obj["epsfail"].get<std::string>().c_str()):obj["epsfail"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusFail241 from_json<ApollocanbusFail241>(nlohmann::json obj){
        return from_json_ApollocanbusFail241(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusFail241 &dt)
    {
        dt=from_json_ApollocanbusFail241(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusFail241 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusFail241 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
