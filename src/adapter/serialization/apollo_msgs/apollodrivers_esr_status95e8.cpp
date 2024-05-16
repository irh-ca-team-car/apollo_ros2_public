#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status95e8.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus95e8 &msg) {
        nlohmann::json obj;
        obj["cantxpathidacc3"] = (msg.cantxpathidacc3);
        obj["cantxpathidacc2"] = (msg.cantxpathidacc2);
        obj["cantxfilteredxohpacccipv"] = (msg.cantxfilteredxohpacccipv);
        obj["cantxwaterspraytargetid"] = (msg.cantxwaterspraytargetid);
        obj["cantxserialnum3rdbyte"] = (msg.cantxserialnum3rdbyte);
        obj["cantxsideslipangle"] = (msg.cantxsideslipangle);
        obj["cantxavgpwrcwblkg"] = (msg.cantxavgpwrcwblkg);
        return obj;
    }
    ApollodriversEsrStatus95e8 from_json_ApollodriversEsrStatus95e8 (nlohmann::json obj) {
        ApollodriversEsrStatus95e8 msg;
        if(obj.contains("cantxpathidacc3"))
        {
            msg.cantxpathidacc3 = (obj["cantxpathidacc3"].is_string()?atoi(obj["cantxpathidacc3"].get<std::string>().c_str()):obj["cantxpathidacc3"].get<int>());
        }
        if(obj.contains("cantxpathidacc2"))
        {
            msg.cantxpathidacc2 = (obj["cantxpathidacc2"].is_string()?atoi(obj["cantxpathidacc2"].get<std::string>().c_str()):obj["cantxpathidacc2"].get<int>());
        }
        if(obj.contains("cantxfilteredxohpacccipv"))
        {
            msg.cantxfilteredxohpacccipv = (obj["cantxfilteredxohpacccipv"].is_string()?atof(obj["cantxfilteredxohpacccipv"].get<std::string>().c_str()):obj["cantxfilteredxohpacccipv"].get<double>());
        }
        if(obj.contains("cantxwaterspraytargetid"))
        {
            msg.cantxwaterspraytargetid = (obj["cantxwaterspraytargetid"].is_string()?atoi(obj["cantxwaterspraytargetid"].get<std::string>().c_str()):obj["cantxwaterspraytargetid"].get<int>());
        }
        if(obj.contains("cantxserialnum3rdbyte"))
        {
            msg.cantxserialnum3rdbyte = (obj["cantxserialnum3rdbyte"].is_string()?atoi(obj["cantxserialnum3rdbyte"].get<std::string>().c_str()):obj["cantxserialnum3rdbyte"].get<int>());
        }
        if(obj.contains("cantxsideslipangle"))
        {
            msg.cantxsideslipangle = (obj["cantxsideslipangle"].is_string()?atof(obj["cantxsideslipangle"].get<std::string>().c_str()):obj["cantxsideslipangle"].get<double>());
        }
        if(obj.contains("cantxavgpwrcwblkg"))
        {
            msg.cantxavgpwrcwblkg = (obj["cantxavgpwrcwblkg"].is_string()?atoi(obj["cantxavgpwrcwblkg"].get<std::string>().c_str()):obj["cantxavgpwrcwblkg"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrStatus95e8 from_json<ApollodriversEsrStatus95e8>(nlohmann::json obj){
        return from_json_ApollodriversEsrStatus95e8(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus95e8 &dt)
    {
        dt=from_json_ApollodriversEsrStatus95e8(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus95e8 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus95e8 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
