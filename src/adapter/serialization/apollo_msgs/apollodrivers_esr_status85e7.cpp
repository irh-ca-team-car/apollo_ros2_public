#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status85e7.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus85e7 &msg) {
        nlohmann::json obj;
        obj["cantxhistoryfault7"] = (msg.cantxhistoryfault7);
        obj["cantxhistoryfault6"] = (msg.cantxhistoryfault6);
        obj["cantxhistoryfault5"] = (msg.cantxhistoryfault5);
        obj["cantxhistoryfault4"] = (msg.cantxhistoryfault4);
        obj["cantxhistoryfault3"] = (msg.cantxhistoryfault3);
        obj["cantxhistoryfault2"] = (msg.cantxhistoryfault2);
        obj["cantxhistoryfault1"] = (msg.cantxhistoryfault1);
        obj["cantxhistoryfault0"] = (msg.cantxhistoryfault0);
        return obj;
    }
    ApollodriversEsrStatus85e7 from_json_ApollodriversEsrStatus85e7 (nlohmann::json obj) {
        ApollodriversEsrStatus85e7 msg;
        if(obj.contains("cantxhistoryfault7"))
        {
            msg.cantxhistoryfault7 = (obj["cantxhistoryfault7"].is_string()?atoi(obj["cantxhistoryfault7"].get<std::string>().c_str()):obj["cantxhistoryfault7"].get<int>());
        }
        if(obj.contains("cantxhistoryfault6"))
        {
            msg.cantxhistoryfault6 = (obj["cantxhistoryfault6"].is_string()?atoi(obj["cantxhistoryfault6"].get<std::string>().c_str()):obj["cantxhistoryfault6"].get<int>());
        }
        if(obj.contains("cantxhistoryfault5"))
        {
            msg.cantxhistoryfault5 = (obj["cantxhistoryfault5"].is_string()?atoi(obj["cantxhistoryfault5"].get<std::string>().c_str()):obj["cantxhistoryfault5"].get<int>());
        }
        if(obj.contains("cantxhistoryfault4"))
        {
            msg.cantxhistoryfault4 = (obj["cantxhistoryfault4"].is_string()?atoi(obj["cantxhistoryfault4"].get<std::string>().c_str()):obj["cantxhistoryfault4"].get<int>());
        }
        if(obj.contains("cantxhistoryfault3"))
        {
            msg.cantxhistoryfault3 = (obj["cantxhistoryfault3"].is_string()?atoi(obj["cantxhistoryfault3"].get<std::string>().c_str()):obj["cantxhistoryfault3"].get<int>());
        }
        if(obj.contains("cantxhistoryfault2"))
        {
            msg.cantxhistoryfault2 = (obj["cantxhistoryfault2"].is_string()?atoi(obj["cantxhistoryfault2"].get<std::string>().c_str()):obj["cantxhistoryfault2"].get<int>());
        }
        if(obj.contains("cantxhistoryfault1"))
        {
            msg.cantxhistoryfault1 = (obj["cantxhistoryfault1"].is_string()?atoi(obj["cantxhistoryfault1"].get<std::string>().c_str()):obj["cantxhistoryfault1"].get<int>());
        }
        if(obj.contains("cantxhistoryfault0"))
        {
            msg.cantxhistoryfault0 = (obj["cantxhistoryfault0"].is_string()?atoi(obj["cantxhistoryfault0"].get<std::string>().c_str()):obj["cantxhistoryfault0"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrStatus85e7 from_json<ApollodriversEsrStatus85e7>(nlohmann::json obj){
        return from_json_ApollodriversEsrStatus85e7(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus85e7 &dt)
    {
        dt=from_json_ApollodriversEsrStatus85e7(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus85e7 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus85e7 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
