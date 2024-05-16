#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status24e1.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus24e1 &msg) {
        nlohmann::json obj;
        obj["cantxyawratebias"] = (msg.cantxyawratebias);
        obj["cantxvehspdcompfactor"] = (msg.cantxvehspdcompfactor);
        obj["cantxswversiondsp"] = (msg.cantxswversiondsp);
        obj["cantxtemperature"] = (msg.cantxtemperature);
        obj["cantxrawdatamode"] = (msg.cantxrawdatamode);
        obj["cantxrangeperferror"] = (msg.cantxrangeperferror);
        obj["cantxoverheaterror"] = (msg.cantxoverheaterror);
        obj["cantxmaximumtracksack"] = (msg.cantxmaximumtracksack);
        obj["cantxinternalerror"] = (msg.cantxinternalerror);
        obj["cantxgroupingmode"] = (msg.cantxgroupingmode);
        obj["cantxxcvroperational"] = (msg.cantxxcvroperational);
        obj["cantxsteeringangleack"] = (msg.cantxsteeringangleack);
        obj["cantxrollingcount2"] = (msg.cantxrollingcount2);
        return obj;
    }
    ApollodriversEsrStatus24e1 from_json_ApollodriversEsrStatus24e1 (nlohmann::json obj) {
        ApollodriversEsrStatus24e1 msg;
        if(obj.contains("cantxyawratebias"))
        {
            msg.cantxyawratebias = (obj["cantxyawratebias"].is_string()?atof(obj["cantxyawratebias"].get<std::string>().c_str()):obj["cantxyawratebias"].get<double>());
        }
        if(obj.contains("cantxvehspdcompfactor"))
        {
            msg.cantxvehspdcompfactor = (obj["cantxvehspdcompfactor"].is_string()?atof(obj["cantxvehspdcompfactor"].get<std::string>().c_str()):obj["cantxvehspdcompfactor"].get<double>());
        }
        if(obj.contains("cantxswversiondsp"))
        {
            msg.cantxswversiondsp = (obj["cantxswversiondsp"].is_string()?atoi(obj["cantxswversiondsp"].get<std::string>().c_str()):obj["cantxswversiondsp"].get<int>());
        }
        if(obj.contains("cantxtemperature"))
        {
            msg.cantxtemperature = (obj["cantxtemperature"].is_string()?atoi(obj["cantxtemperature"].get<std::string>().c_str()):obj["cantxtemperature"].get<int>());
        }
        if(obj.contains("cantxrawdatamode"))
        {
            msg.cantxrawdatamode = (obj["cantxrawdatamode"].is_string()?atoi(obj["cantxrawdatamode"].get<std::string>().c_str()):obj["cantxrawdatamode"].get<int>());
        }
        if(obj.contains("cantxrangeperferror"))
        {
            msg.cantxrangeperferror = (obj["cantxrangeperferror"].is_string()?atoi(obj["cantxrangeperferror"].get<std::string>().c_str()):obj["cantxrangeperferror"].get<int>());
        }
        if(obj.contains("cantxoverheaterror"))
        {
            msg.cantxoverheaterror = (obj["cantxoverheaterror"].is_string()?atoi(obj["cantxoverheaterror"].get<std::string>().c_str()):obj["cantxoverheaterror"].get<int>());
        }
        if(obj.contains("cantxmaximumtracksack"))
        {
            msg.cantxmaximumtracksack = (obj["cantxmaximumtracksack"].is_string()?atoi(obj["cantxmaximumtracksack"].get<std::string>().c_str()):obj["cantxmaximumtracksack"].get<int>());
        }
        if(obj.contains("cantxinternalerror"))
        {
            msg.cantxinternalerror = (obj["cantxinternalerror"].is_string()?atoi(obj["cantxinternalerror"].get<std::string>().c_str()):obj["cantxinternalerror"].get<int>());
        }
        if(obj.contains("cantxgroupingmode"))
        {
            msg.cantxgroupingmode = (obj["cantxgroupingmode"].is_string()?atoi(obj["cantxgroupingmode"].get<std::string>().c_str()):obj["cantxgroupingmode"].get<int>());
        }
        if(obj.contains("cantxxcvroperational"))
        {
            msg.cantxxcvroperational = (obj["cantxxcvroperational"].is_string()?atoi(obj["cantxxcvroperational"].get<std::string>().c_str()):obj["cantxxcvroperational"].get<int>());
        }
        if(obj.contains("cantxsteeringangleack"))
        {
            msg.cantxsteeringangleack = (obj["cantxsteeringangleack"].is_string()?atoi(obj["cantxsteeringangleack"].get<std::string>().c_str()):obj["cantxsteeringangleack"].get<int>());
        }
        if(obj.contains("cantxrollingcount2"))
        {
            msg.cantxrollingcount2 = (obj["cantxrollingcount2"].is_string()?atoi(obj["cantxrollingcount2"].get<std::string>().c_str()):obj["cantxrollingcount2"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrStatus24e1 from_json<ApollodriversEsrStatus24e1>(nlohmann::json obj){
        return from_json_ApollodriversEsrStatus24e1(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus24e1 &dt)
    {
        dt=from_json_ApollodriversEsrStatus24e1(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus24e1 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus24e1 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
