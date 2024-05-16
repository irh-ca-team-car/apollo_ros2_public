#include "adapter/serialization/apollo_msgs/apollocanbus_scu1301.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusScu1301 &msg) {
        nlohmann::json obj;
        obj["vin16"] = (msg.vin16);
        obj["scustopbutst"] = (msg.scustopbutst);
        obj["scudrvmode"] = (msg.scudrvmode);
        obj["scufaultst"] = (msg.scufaultst);
        return obj;
    }
    ApollocanbusScu1301 from_json_ApollocanbusScu1301 (nlohmann::json obj) {
        ApollocanbusScu1301 msg;
        if(obj.contains("vin16"))
        {
            msg.vin16 = (obj["vin16"].is_string()?atoi(obj["vin16"].get<std::string>().c_str()):obj["vin16"].get<int>());
        }
        if(obj.contains("scustopbutst"))
        {
            msg.scustopbutst = (obj["scustopbutst"].is_string()?atoi(obj["scustopbutst"].get<std::string>().c_str()):obj["scustopbutst"].get<int>());
        }
        if(obj.contains("scudrvmode"))
        {
            msg.scudrvmode = (obj["scudrvmode"].is_string()?atoi(obj["scudrvmode"].get<std::string>().c_str()):obj["scudrvmode"].get<int>());
        }
        if(obj.contains("scufaultst"))
        {
            msg.scufaultst = (obj["scufaultst"].is_string()?atoi(obj["scufaultst"].get<std::string>().c_str()):obj["scufaultst"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusScu1301 from_json<ApollocanbusScu1301>(nlohmann::json obj){
        return from_json_ApollocanbusScu1301(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusScu1301 &dt)
    {
        dt=from_json_ApollocanbusScu1301(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusScu1301 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusScu1301 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
