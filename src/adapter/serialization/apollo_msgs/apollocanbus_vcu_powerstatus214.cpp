#include "adapter/serialization/apollo_msgs/apollocanbus_vcu_powerstatus214.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusVcuPowerstatus214 &msg) {
        nlohmann::json obj;
        obj["vcupowermode"] = (msg.vcupowermode);
        obj["vcupowermodevalid"] = (msg.vcupowermodevalid);
        obj["replacebatterystateindication"] = (msg.replacebatterystateindication);
        obj["forbiddenaebsignal"] = (msg.forbiddenaebsignal);
        obj["bcuchargedischargecurrent"] = (msg.bcuchargedischargecurrent);
        obj["bcubattinternalvoltage"] = (msg.bcubattinternalvoltage);
        obj["vcudriverinfoalivecounter"] = (msg.vcudriverinfoalivecounter);
        obj["vcudriverinfochecksum"] = (msg.vcudriverinfochecksum);
        return obj;
    }
    ApollocanbusVcuPowerstatus214 from_json_ApollocanbusVcuPowerstatus214 (nlohmann::json obj) {
        ApollocanbusVcuPowerstatus214 msg;
        if(obj.contains("vcupowermode"))
        {
            msg.vcupowermode = (obj["vcupowermode"].is_string()?atoi(obj["vcupowermode"].get<std::string>().c_str()):obj["vcupowermode"].get<int>());
        }
        if(obj.contains("vcupowermodevalid"))
        {
            msg.vcupowermodevalid = (obj["vcupowermodevalid"].is_string()?atoi(obj["vcupowermodevalid"].get<std::string>().c_str()):obj["vcupowermodevalid"].get<int>());
        }
        if(obj.contains("replacebatterystateindication"))
        {
            msg.replacebatterystateindication = (obj["replacebatterystateindication"].is_string()?(bool)atoi(obj["replacebatterystateindication"].get<std::string>().c_str()):obj["replacebatterystateindication"].get<bool>());
        }
        if(obj.contains("forbiddenaebsignal"))
        {
            msg.forbiddenaebsignal = (obj["forbiddenaebsignal"].is_string()?(bool)atoi(obj["forbiddenaebsignal"].get<std::string>().c_str()):obj["forbiddenaebsignal"].get<bool>());
        }
        if(obj.contains("bcuchargedischargecurrent"))
        {
            msg.bcuchargedischargecurrent = (obj["bcuchargedischargecurrent"].is_string()?atof(obj["bcuchargedischargecurrent"].get<std::string>().c_str()):obj["bcuchargedischargecurrent"].get<double>());
        }
        if(obj.contains("bcubattinternalvoltage"))
        {
            msg.bcubattinternalvoltage = (obj["bcubattinternalvoltage"].is_string()?atof(obj["bcubattinternalvoltage"].get<std::string>().c_str()):obj["bcubattinternalvoltage"].get<double>());
        }
        if(obj.contains("vcudriverinfoalivecounter"))
        {
            msg.vcudriverinfoalivecounter = (obj["vcudriverinfoalivecounter"].is_string()?atoi(obj["vcudriverinfoalivecounter"].get<std::string>().c_str()):obj["vcudriverinfoalivecounter"].get<int>());
        }
        if(obj.contains("vcudriverinfochecksum"))
        {
            msg.vcudriverinfochecksum = (obj["vcudriverinfochecksum"].is_string()?atoi(obj["vcudriverinfochecksum"].get<std::string>().c_str()):obj["vcudriverinfochecksum"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusVcuPowerstatus214 from_json<ApollocanbusVcuPowerstatus214>(nlohmann::json obj){
        return from_json_ApollocanbusVcuPowerstatus214(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusVcuPowerstatus214 &dt)
    {
        dt=from_json_ApollocanbusVcuPowerstatus214(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusVcuPowerstatus214 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusVcuPowerstatus214 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
