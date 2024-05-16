#include "adapter/serialization/apollo_msgs/apollocanbus_fbs3237.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusFbs3237 &msg) {
        nlohmann::json obj;
        obj["engspd"] = (msg.engspd);
        obj["accpedalpos"] = (msg.accpedalpos);
        obj["epbswtichposition"] = (msg.epbswtichposition);
        obj["currentgear"] = (msg.currentgear);
        obj["epsstreeingmode"] = (msg.epsstreeingmode);
        obj["epsdrvinputtrqvalue"] = (msg.epsdrvinputtrqvalue);
        obj["epsconsumedcurrvalue"] = (msg.epsconsumedcurrvalue);
        obj["epscurrmod"] = (msg.epscurrmod);
        return obj;
    }
    ApollocanbusFbs3237 from_json_ApollocanbusFbs3237 (nlohmann::json obj) {
        ApollocanbusFbs3237 msg;
        if(obj.contains("engspd"))
        {
            msg.engspd = (obj["engspd"].is_string()?atof(obj["engspd"].get<std::string>().c_str()):obj["engspd"].get<double>());
        }
        if(obj.contains("accpedalpos"))
        {
            msg.accpedalpos = (obj["accpedalpos"].is_string()?atof(obj["accpedalpos"].get<std::string>().c_str()):obj["accpedalpos"].get<double>());
        }
        if(obj.contains("epbswtichposition"))
        {
            msg.epbswtichposition = (obj["epbswtichposition"].is_string()?atoi(obj["epbswtichposition"].get<std::string>().c_str()):obj["epbswtichposition"].get<int>());
        }
        if(obj.contains("currentgear"))
        {
            msg.currentgear = (obj["currentgear"].is_string()?atoi(obj["currentgear"].get<std::string>().c_str()):obj["currentgear"].get<int>());
        }
        if(obj.contains("epsstreeingmode"))
        {
            msg.epsstreeingmode = (obj["epsstreeingmode"].is_string()?atoi(obj["epsstreeingmode"].get<std::string>().c_str()):obj["epsstreeingmode"].get<int>());
        }
        if(obj.contains("epsdrvinputtrqvalue"))
        {
            msg.epsdrvinputtrqvalue = (obj["epsdrvinputtrqvalue"].is_string()?atof(obj["epsdrvinputtrqvalue"].get<std::string>().c_str()):obj["epsdrvinputtrqvalue"].get<double>());
        }
        if(obj.contains("epsconsumedcurrvalue"))
        {
            msg.epsconsumedcurrvalue = (obj["epsconsumedcurrvalue"].is_string()?atof(obj["epsconsumedcurrvalue"].get<std::string>().c_str()):obj["epsconsumedcurrvalue"].get<double>());
        }
        if(obj.contains("epscurrmod"))
        {
            msg.epscurrmod = (obj["epscurrmod"].is_string()?atoi(obj["epscurrmod"].get<std::string>().c_str()):obj["epscurrmod"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusFbs3237 from_json<ApollocanbusFbs3237>(nlohmann::json obj){
        return from_json_ApollocanbusFbs3237(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusFbs3237 &dt)
    {
        dt=from_json_ApollocanbusFbs3237(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusFbs3237 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusFbs3237 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
