#include "adapter/serialization/apollo_msgs/apollocanbus_scu_eps311.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScuEps311 &msg) {
        nlohmann::json obj;
        obj["epsintidx"] = (msg.epsintidx);
        obj["epssteeranglespd"] = (msg.epssteeranglespd);
        obj["epssteerangle"] = (msg.epssteerangle);
        obj["epsfaultst"] = (msg.epsfaultst);
        obj["epsdrvmode"] = (msg.epsdrvmode);
        return obj;
    }
    ApollocanbusScuEps311 from_json_ApollocanbusScuEps311 (nlohmann::json obj) {
        ApollocanbusScuEps311 msg;
        if(obj.contains("epsintidx"))
        {
            msg.epsintidx = (obj["epsintidx"].is_string()?atoi(obj["epsintidx"].get<std::string>().c_str()):obj["epsintidx"].get<int>());
        }
        if(obj.contains("epssteeranglespd"))
        {
            msg.epssteeranglespd = (obj["epssteeranglespd"].is_string()?atof(obj["epssteeranglespd"].get<std::string>().c_str()):obj["epssteeranglespd"].get<double>());
        }
        if(obj.contains("epssteerangle"))
        {
            msg.epssteerangle = (obj["epssteerangle"].is_string()?atof(obj["epssteerangle"].get<std::string>().c_str()):obj["epssteerangle"].get<double>());
        }
        if(obj.contains("epsfaultst"))
        {
            msg.epsfaultst = (obj["epsfaultst"].is_string()?atoi(obj["epsfaultst"].get<std::string>().c_str()):obj["epsfaultst"].get<int>());
        }
        if(obj.contains("epsdrvmode"))
        {
            msg.epsdrvmode = (obj["epsdrvmode"].is_string()?atoi(obj["epsdrvmode"].get<std::string>().c_str()):obj["epsdrvmode"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusScuEps311 from_json<ApollocanbusScuEps311>(nlohmann::json obj){
        return from_json_ApollocanbusScuEps311(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScuEps311 &dt)
    {
        dt=from_json_ApollocanbusScuEps311(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScuEps311 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScuEps311 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
