#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status65e5.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus65e5 &msg) {
        nlohmann::json obj;
        obj["cantxswversiondsp3rdbyte"] = (msg.cantxswversiondsp3rdbyte);
        obj["cantxverticalalignupdated"] = (msg.cantxverticalalignupdated);
        obj["cantxverticalmisalignment"] = (msg.cantxverticalmisalignment);
        obj["cantxservalignupdatesdone"] = (msg.cantxservalignupdatesdone);
        obj["cantxfoundtarget"] = (msg.cantxfoundtarget);
        obj["cantxfactorymisalignment"] = (msg.cantxfactorymisalignment);
        obj["cantxfactoryalignstatus2"] = (msg.cantxfactoryalignstatus2);
        obj["cantxfactoryalignstatus1"] = (msg.cantxfactoryalignstatus1);
        obj["cantxrecommendunconverge"] = (msg.cantxrecommendunconverge);
        obj["cantxwavediffa2d"] = (msg.cantxwavediffa2d);
        obj["cantxsystempowermode"] = (msg.cantxsystempowermode);
        obj["cantxsupplyn5va2d"] = (msg.cantxsupplyn5va2d);
        obj["cantxsupply1p8va2d"] = (msg.cantxsupply1p8va2d);
        return obj;
    }
    ApollodriversEsrStatus65e5 from_json_ApollodriversEsrStatus65e5 (nlohmann::json obj) {
        ApollodriversEsrStatus65e5 msg;
        if(obj.contains("cantxswversiondsp3rdbyte"))
        {
            msg.cantxswversiondsp3rdbyte = (obj["cantxswversiondsp3rdbyte"].is_string()?atoi(obj["cantxswversiondsp3rdbyte"].get<std::string>().c_str()):obj["cantxswversiondsp3rdbyte"].get<int>());
        }
        if(obj.contains("cantxverticalalignupdated"))
        {
            msg.cantxverticalalignupdated = (obj["cantxverticalalignupdated"].is_string()?atoi(obj["cantxverticalalignupdated"].get<std::string>().c_str()):obj["cantxverticalalignupdated"].get<int>());
        }
        if(obj.contains("cantxverticalmisalignment"))
        {
            msg.cantxverticalmisalignment = (obj["cantxverticalmisalignment"].is_string()?atof(obj["cantxverticalmisalignment"].get<std::string>().c_str()):obj["cantxverticalmisalignment"].get<double>());
        }
        if(obj.contains("cantxservalignupdatesdone"))
        {
            msg.cantxservalignupdatesdone = (obj["cantxservalignupdatesdone"].is_string()?atoi(obj["cantxservalignupdatesdone"].get<std::string>().c_str()):obj["cantxservalignupdatesdone"].get<int>());
        }
        if(obj.contains("cantxfoundtarget"))
        {
            msg.cantxfoundtarget = (obj["cantxfoundtarget"].is_string()?atoi(obj["cantxfoundtarget"].get<std::string>().c_str()):obj["cantxfoundtarget"].get<int>());
        }
        if(obj.contains("cantxfactorymisalignment"))
        {
            msg.cantxfactorymisalignment = (obj["cantxfactorymisalignment"].is_string()?atof(obj["cantxfactorymisalignment"].get<std::string>().c_str()):obj["cantxfactorymisalignment"].get<double>());
        }
        if(obj.contains("cantxfactoryalignstatus2"))
        {
            msg.cantxfactoryalignstatus2 = (obj["cantxfactoryalignstatus2"].is_string()?atoi(obj["cantxfactoryalignstatus2"].get<std::string>().c_str()):obj["cantxfactoryalignstatus2"].get<int>());
        }
        if(obj.contains("cantxfactoryalignstatus1"))
        {
            msg.cantxfactoryalignstatus1 = (obj["cantxfactoryalignstatus1"].is_string()?atoi(obj["cantxfactoryalignstatus1"].get<std::string>().c_str()):obj["cantxfactoryalignstatus1"].get<int>());
        }
        if(obj.contains("cantxrecommendunconverge"))
        {
            msg.cantxrecommendunconverge = (obj["cantxrecommendunconverge"].is_string()?atoi(obj["cantxrecommendunconverge"].get<std::string>().c_str()):obj["cantxrecommendunconverge"].get<int>());
        }
        if(obj.contains("cantxwavediffa2d"))
        {
            msg.cantxwavediffa2d = (obj["cantxwavediffa2d"].is_string()?atoi(obj["cantxwavediffa2d"].get<std::string>().c_str()):obj["cantxwavediffa2d"].get<int>());
        }
        if(obj.contains("cantxsystempowermode"))
        {
            msg.cantxsystempowermode = (obj["cantxsystempowermode"].is_string()?atoi(obj["cantxsystempowermode"].get<std::string>().c_str()):obj["cantxsystempowermode"].get<int>());
        }
        if(obj.contains("cantxsupplyn5va2d"))
        {
            msg.cantxsupplyn5va2d = (obj["cantxsupplyn5va2d"].is_string()?atoi(obj["cantxsupplyn5va2d"].get<std::string>().c_str()):obj["cantxsupplyn5va2d"].get<int>());
        }
        if(obj.contains("cantxsupply1p8va2d"))
        {
            msg.cantxsupply1p8va2d = (obj["cantxsupply1p8va2d"].is_string()?atoi(obj["cantxsupply1p8va2d"].get<std::string>().c_str()):obj["cantxsupply1p8va2d"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrStatus65e5 from_json<ApollodriversEsrStatus65e5>(nlohmann::json obj){
        return from_json_ApollodriversEsrStatus65e5(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus65e5 &dt)
    {
        dt=from_json_ApollodriversEsrStatus65e5(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus65e5 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus65e5 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
