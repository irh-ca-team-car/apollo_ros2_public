#include "adapter/serialization/apollo_msgs/apollodrivers_acm_inst_resp7e4.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversAcmInstResp7e4 &msg) {
        nlohmann::json obj;
        obj["data7"] = (msg.data7);
        obj["data6"] = (msg.data6);
        obj["data5"] = (msg.data5);
        obj["data4"] = (msg.data4);
        obj["data3"] = (msg.data3);
        obj["rtncmdcounter"] = (msg.rtncmdcounter);
        obj["commandreturncode"] = (msg.commandreturncode);
        obj["pid"] = (msg.pid);
        return obj;
    }
    ApollodriversAcmInstResp7e4 from_json_ApollodriversAcmInstResp7e4 (nlohmann::json obj) {
        ApollodriversAcmInstResp7e4 msg;
        if(obj.contains("data7"))
        {
            msg.data7 = (obj["data7"].is_string()?atoi(obj["data7"].get<std::string>().c_str()):obj["data7"].get<int>());
        }
        if(obj.contains("data6"))
        {
            msg.data6 = (obj["data6"].is_string()?atoi(obj["data6"].get<std::string>().c_str()):obj["data6"].get<int>());
        }
        if(obj.contains("data5"))
        {
            msg.data5 = (obj["data5"].is_string()?atoi(obj["data5"].get<std::string>().c_str()):obj["data5"].get<int>());
        }
        if(obj.contains("data4"))
        {
            msg.data4 = (obj["data4"].is_string()?atoi(obj["data4"].get<std::string>().c_str()):obj["data4"].get<int>());
        }
        if(obj.contains("data3"))
        {
            msg.data3 = (obj["data3"].is_string()?atoi(obj["data3"].get<std::string>().c_str()):obj["data3"].get<int>());
        }
        if(obj.contains("rtncmdcounter"))
        {
            msg.rtncmdcounter = (obj["rtncmdcounter"].is_string()?atoi(obj["rtncmdcounter"].get<std::string>().c_str()):obj["rtncmdcounter"].get<int>());
        }
        if(obj.contains("commandreturncode"))
        {
            msg.commandreturncode = (obj["commandreturncode"].is_string()?atoi(obj["commandreturncode"].get<std::string>().c_str()):obj["commandreturncode"].get<int>());
        }
        if(obj.contains("pid"))
        {
            msg.pid = (obj["pid"].is_string()?atoi(obj["pid"].get<std::string>().c_str()):obj["pid"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversAcmInstResp7e4 from_json<ApollodriversAcmInstResp7e4>(nlohmann::json obj){
        return from_json_ApollodriversAcmInstResp7e4(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversAcmInstResp7e4 &dt)
    {
        dt=from_json_ApollodriversAcmInstResp7e4(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversAcmInstResp7e4 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversAcmInstResp7e4 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
