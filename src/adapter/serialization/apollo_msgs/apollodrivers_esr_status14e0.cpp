#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status14e0.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus14e0 &msg) {
        nlohmann::json obj;
        obj["cantxdsptimestamp"] = (msg.cantxdsptimestamp);
        obj["cantxcommerror"] = (msg.cantxcommerror);
        obj["cantxyawratecalc"] = (msg.cantxyawratecalc);
        obj["cantxvehiclespeedcalc"] = (msg.cantxvehiclespeedcalc);
        obj["cantxscanindex"] = (msg.cantxscanindex);
        obj["cantxrollingcount1"] = (msg.cantxrollingcount1);
        obj["cantxradiuscurvaturecalc"] = (msg.cantxradiuscurvaturecalc);
        return obj;
    }
    ApollodriversEsrStatus14e0 from_json_ApollodriversEsrStatus14e0 (nlohmann::json obj) {
        ApollodriversEsrStatus14e0 msg;
        if(obj.contains("cantxdsptimestamp"))
        {
            msg.cantxdsptimestamp = (obj["cantxdsptimestamp"].is_string()?atof(obj["cantxdsptimestamp"].get<std::string>().c_str()):obj["cantxdsptimestamp"].get<double>());
        }
        if(obj.contains("cantxcommerror"))
        {
            msg.cantxcommerror = (obj["cantxcommerror"].is_string()?(bool)atoi(obj["cantxcommerror"].get<std::string>().c_str()):obj["cantxcommerror"].get<bool>());
        }
        if(obj.contains("cantxyawratecalc"))
        {
            msg.cantxyawratecalc = (obj["cantxyawratecalc"].is_string()?atof(obj["cantxyawratecalc"].get<std::string>().c_str()):obj["cantxyawratecalc"].get<double>());
        }
        if(obj.contains("cantxvehiclespeedcalc"))
        {
            msg.cantxvehiclespeedcalc = (obj["cantxvehiclespeedcalc"].is_string()?atof(obj["cantxvehiclespeedcalc"].get<std::string>().c_str()):obj["cantxvehiclespeedcalc"].get<double>());
        }
        if(obj.contains("cantxscanindex"))
        {
            msg.cantxscanindex = (obj["cantxscanindex"].is_string()?atoi(obj["cantxscanindex"].get<std::string>().c_str()):obj["cantxscanindex"].get<int>());
        }
        if(obj.contains("cantxrollingcount1"))
        {
            msg.cantxrollingcount1 = (obj["cantxrollingcount1"].is_string()?atoi(obj["cantxrollingcount1"].get<std::string>().c_str()):obj["cantxrollingcount1"].get<int>());
        }
        if(obj.contains("cantxradiuscurvaturecalc"))
        {
            msg.cantxradiuscurvaturecalc = (obj["cantxradiuscurvaturecalc"].is_string()?atoi(obj["cantxradiuscurvaturecalc"].get<std::string>().c_str()):obj["cantxradiuscurvaturecalc"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrStatus14e0 from_json<ApollodriversEsrStatus14e0>(nlohmann::json obj){
        return from_json_ApollodriversEsrStatus14e0(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus14e0 &dt)
    {
        dt=from_json_ApollodriversEsrStatus14e0(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus14e0 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus14e0 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
