#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status75e6.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus75e6 &msg) {
        nlohmann::json obj;
        obj["cantxactivefault7"] = (msg.cantxactivefault7);
        obj["cantxactivefault6"] = (msg.cantxactivefault6);
        obj["cantxactivefault5"] = (msg.cantxactivefault5);
        obj["cantxactivefault4"] = (msg.cantxactivefault4);
        obj["cantxactivefault3"] = (msg.cantxactivefault3);
        obj["cantxactivefault2"] = (msg.cantxactivefault2);
        obj["cantxactivefault0"] = (msg.cantxactivefault0);
        obj["cantxactivefault1"] = (msg.cantxactivefault1);
        return obj;
    }
    ApollodriversEsrStatus75e6 from_json_ApollodriversEsrStatus75e6 (nlohmann::json obj) {
        ApollodriversEsrStatus75e6 msg;
        if(obj.contains("cantxactivefault7"))
        {
            msg.cantxactivefault7 = (obj["cantxactivefault7"].is_string()?atoi(obj["cantxactivefault7"].get<std::string>().c_str()):obj["cantxactivefault7"].get<int>());
        }
        if(obj.contains("cantxactivefault6"))
        {
            msg.cantxactivefault6 = (obj["cantxactivefault6"].is_string()?atoi(obj["cantxactivefault6"].get<std::string>().c_str()):obj["cantxactivefault6"].get<int>());
        }
        if(obj.contains("cantxactivefault5"))
        {
            msg.cantxactivefault5 = (obj["cantxactivefault5"].is_string()?atoi(obj["cantxactivefault5"].get<std::string>().c_str()):obj["cantxactivefault5"].get<int>());
        }
        if(obj.contains("cantxactivefault4"))
        {
            msg.cantxactivefault4 = (obj["cantxactivefault4"].is_string()?atoi(obj["cantxactivefault4"].get<std::string>().c_str()):obj["cantxactivefault4"].get<int>());
        }
        if(obj.contains("cantxactivefault3"))
        {
            msg.cantxactivefault3 = (obj["cantxactivefault3"].is_string()?atoi(obj["cantxactivefault3"].get<std::string>().c_str()):obj["cantxactivefault3"].get<int>());
        }
        if(obj.contains("cantxactivefault2"))
        {
            msg.cantxactivefault2 = (obj["cantxactivefault2"].is_string()?atoi(obj["cantxactivefault2"].get<std::string>().c_str()):obj["cantxactivefault2"].get<int>());
        }
        if(obj.contains("cantxactivefault0"))
        {
            msg.cantxactivefault0 = (obj["cantxactivefault0"].is_string()?atoi(obj["cantxactivefault0"].get<std::string>().c_str()):obj["cantxactivefault0"].get<int>());
        }
        if(obj.contains("cantxactivefault1"))
        {
            msg.cantxactivefault1 = (obj["cantxactivefault1"].is_string()?atoi(obj["cantxactivefault1"].get<std::string>().c_str()):obj["cantxactivefault1"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrStatus75e6 from_json<ApollodriversEsrStatus75e6>(nlohmann::json obj){
        return from_json_ApollodriversEsrStatus75e6(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus75e6 &dt)
    {
        dt=from_json_ApollodriversEsrStatus75e6(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus75e6 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus75e6 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
