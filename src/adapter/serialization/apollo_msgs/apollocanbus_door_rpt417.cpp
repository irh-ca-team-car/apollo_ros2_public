#include "adapter/serialization/apollo_msgs/apollocanbus_door_rpt417.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDoorRpt417 &msg) {
        nlohmann::json obj;
        obj["fueldooropenisvalid"] = (msg.fueldooropenisvalid);
        obj["trunkopenisvalid"] = (msg.trunkopenisvalid);
        obj["hoodopenisvalid"] = (msg.hoodopenisvalid);
        obj["rearpassdooropenisvalid"] = (msg.rearpassdooropenisvalid);
        obj["reardriverdooropenisvalid"] = (msg.reardriverdooropenisvalid);
        obj["passdooropenisvalid"] = (msg.passdooropenisvalid);
        obj["driverdooropenisvalid"] = (msg.driverdooropenisvalid);
        obj["fueldooropen"] = (msg.fueldooropen);
        obj["trunkopen"] = (msg.trunkopen);
        obj["hoodopen"] = (msg.hoodopen);
        obj["rearpassdooropen"] = (msg.rearpassdooropen);
        obj["reardriverdooropen"] = (msg.reardriverdooropen);
        obj["passdooropen"] = (msg.passdooropen);
        obj["driverdooropen"] = (msg.driverdooropen);
        return obj;
    }
    ApollocanbusDoorRpt417 from_json_ApollocanbusDoorRpt417 (nlohmann::json obj) {
        ApollocanbusDoorRpt417 msg;
        if(obj.contains("fueldooropenisvalid"))
        {
            msg.fueldooropenisvalid = (obj["fueldooropenisvalid"].is_string()?(bool)atoi(obj["fueldooropenisvalid"].get<std::string>().c_str()):obj["fueldooropenisvalid"].get<bool>());
        }
        if(obj.contains("trunkopenisvalid"))
        {
            msg.trunkopenisvalid = (obj["trunkopenisvalid"].is_string()?(bool)atoi(obj["trunkopenisvalid"].get<std::string>().c_str()):obj["trunkopenisvalid"].get<bool>());
        }
        if(obj.contains("hoodopenisvalid"))
        {
            msg.hoodopenisvalid = (obj["hoodopenisvalid"].is_string()?(bool)atoi(obj["hoodopenisvalid"].get<std::string>().c_str()):obj["hoodopenisvalid"].get<bool>());
        }
        if(obj.contains("rearpassdooropenisvalid"))
        {
            msg.rearpassdooropenisvalid = (obj["rearpassdooropenisvalid"].is_string()?(bool)atoi(obj["rearpassdooropenisvalid"].get<std::string>().c_str()):obj["rearpassdooropenisvalid"].get<bool>());
        }
        if(obj.contains("reardriverdooropenisvalid"))
        {
            msg.reardriverdooropenisvalid = (obj["reardriverdooropenisvalid"].is_string()?(bool)atoi(obj["reardriverdooropenisvalid"].get<std::string>().c_str()):obj["reardriverdooropenisvalid"].get<bool>());
        }
        if(obj.contains("passdooropenisvalid"))
        {
            msg.passdooropenisvalid = (obj["passdooropenisvalid"].is_string()?(bool)atoi(obj["passdooropenisvalid"].get<std::string>().c_str()):obj["passdooropenisvalid"].get<bool>());
        }
        if(obj.contains("driverdooropenisvalid"))
        {
            msg.driverdooropenisvalid = (obj["driverdooropenisvalid"].is_string()?(bool)atoi(obj["driverdooropenisvalid"].get<std::string>().c_str()):obj["driverdooropenisvalid"].get<bool>());
        }
        if(obj.contains("fueldooropen"))
        {
            msg.fueldooropen = (obj["fueldooropen"].is_string()?(bool)atoi(obj["fueldooropen"].get<std::string>().c_str()):obj["fueldooropen"].get<bool>());
        }
        if(obj.contains("trunkopen"))
        {
            msg.trunkopen = (obj["trunkopen"].is_string()?(bool)atoi(obj["trunkopen"].get<std::string>().c_str()):obj["trunkopen"].get<bool>());
        }
        if(obj.contains("hoodopen"))
        {
            msg.hoodopen = (obj["hoodopen"].is_string()?(bool)atoi(obj["hoodopen"].get<std::string>().c_str()):obj["hoodopen"].get<bool>());
        }
        if(obj.contains("rearpassdooropen"))
        {
            msg.rearpassdooropen = (obj["rearpassdooropen"].is_string()?(bool)atoi(obj["rearpassdooropen"].get<std::string>().c_str()):obj["rearpassdooropen"].get<bool>());
        }
        if(obj.contains("reardriverdooropen"))
        {
            msg.reardriverdooropen = (obj["reardriverdooropen"].is_string()?(bool)atoi(obj["reardriverdooropen"].get<std::string>().c_str()):obj["reardriverdooropen"].get<bool>());
        }
        if(obj.contains("passdooropen"))
        {
            msg.passdooropen = (obj["passdooropen"].is_string()?(bool)atoi(obj["passdooropen"].get<std::string>().c_str()):obj["passdooropen"].get<bool>());
        }
        if(obj.contains("driverdooropen"))
        {
            msg.driverdooropen = (obj["driverdooropen"].is_string()?(bool)atoi(obj["driverdooropen"].get<std::string>().c_str()):obj["driverdooropen"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusDoorRpt417 from_json<ApollocanbusDoorRpt417>(nlohmann::json obj){
        return from_json_ApollocanbusDoorRpt417(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDoorRpt417 &dt)
    {
        dt=from_json_ApollocanbusDoorRpt417(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDoorRpt417 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDoorRpt417 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
