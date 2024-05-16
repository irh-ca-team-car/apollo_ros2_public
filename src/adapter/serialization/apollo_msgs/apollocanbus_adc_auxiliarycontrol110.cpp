#include "adapter/serialization/apollo_msgs/apollocanbus_adc_auxiliarycontrol110.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusAdcAuxiliarycontrol110 &msg) {
        nlohmann::json obj;
        obj["adcauxcontrolcounter"] = (msg.adcauxcontrolcounter);
        obj["adcauxcontrolchecksum"] = (msg.adcauxcontrolchecksum);
        obj["adccmdinvertercontrolenable"] = (msg.adccmdinvertercontrolenable);
        obj["adccmdinverter"] = (msg.adccmdinverter);
        obj["adccmdwiper"] = (msg.adccmdwiper);
        obj["adccmdpducontrolenable"] = (msg.adccmdpducontrolenable);
        obj["adccmdpduch8"] = (msg.adccmdpduch8);
        obj["adccmdpduch7"] = (msg.adccmdpduch7);
        obj["adccmdpduch6"] = (msg.adccmdpduch6);
        obj["adccmdpduch5"] = (msg.adccmdpduch5);
        obj["adccmdpduch4"] = (msg.adccmdpduch4);
        obj["adccmdpduch3"] = (msg.adccmdpduch3);
        obj["adccmdpduch2"] = (msg.adccmdpduch2);
        obj["adccmdpduch1"] = (msg.adccmdpduch1);
        obj["adccmdhazardlights"] = (msg.adccmdhazardlights);
        obj["adccmdhighbeam"] = (msg.adccmdhighbeam);
        obj["adccmdlowbeam"] = (msg.adccmdlowbeam);
        obj["adccmdhorn"] = (msg.adccmdhorn);
        obj["adccmdturnsignal"] = (msg.adccmdturnsignal);
        return obj;
    }
    ApollocanbusAdcAuxiliarycontrol110 from_json_ApollocanbusAdcAuxiliarycontrol110 (nlohmann::json obj) {
        ApollocanbusAdcAuxiliarycontrol110 msg;
        if(obj.contains("adcauxcontrolcounter"))
        {
            msg.adcauxcontrolcounter = (obj["adcauxcontrolcounter"].is_string()?atoi(obj["adcauxcontrolcounter"].get<std::string>().c_str()):obj["adcauxcontrolcounter"].get<int>());
        }
        if(obj.contains("adcauxcontrolchecksum"))
        {
            msg.adcauxcontrolchecksum = (obj["adcauxcontrolchecksum"].is_string()?atoi(obj["adcauxcontrolchecksum"].get<std::string>().c_str()):obj["adcauxcontrolchecksum"].get<int>());
        }
        if(obj.contains("adccmdinvertercontrolenable"))
        {
            msg.adccmdinvertercontrolenable = (obj["adccmdinvertercontrolenable"].is_string()?(bool)atoi(obj["adccmdinvertercontrolenable"].get<std::string>().c_str()):obj["adccmdinvertercontrolenable"].get<bool>());
        }
        if(obj.contains("adccmdinverter"))
        {
            msg.adccmdinverter = (obj["adccmdinverter"].is_string()?(bool)atoi(obj["adccmdinverter"].get<std::string>().c_str()):obj["adccmdinverter"].get<bool>());
        }
        if(obj.contains("adccmdwiper"))
        {
            msg.adccmdwiper = (obj["adccmdwiper"].is_string()?atoi(obj["adccmdwiper"].get<std::string>().c_str()):obj["adccmdwiper"].get<int>());
        }
        if(obj.contains("adccmdpducontrolenable"))
        {
            msg.adccmdpducontrolenable = (obj["adccmdpducontrolenable"].is_string()?(bool)atoi(obj["adccmdpducontrolenable"].get<std::string>().c_str()):obj["adccmdpducontrolenable"].get<bool>());
        }
        if(obj.contains("adccmdpduch8"))
        {
            msg.adccmdpduch8 = (obj["adccmdpduch8"].is_string()?(bool)atoi(obj["adccmdpduch8"].get<std::string>().c_str()):obj["adccmdpduch8"].get<bool>());
        }
        if(obj.contains("adccmdpduch7"))
        {
            msg.adccmdpduch7 = (obj["adccmdpduch7"].is_string()?(bool)atoi(obj["adccmdpduch7"].get<std::string>().c_str()):obj["adccmdpduch7"].get<bool>());
        }
        if(obj.contains("adccmdpduch6"))
        {
            msg.adccmdpduch6 = (obj["adccmdpduch6"].is_string()?(bool)atoi(obj["adccmdpduch6"].get<std::string>().c_str()):obj["adccmdpduch6"].get<bool>());
        }
        if(obj.contains("adccmdpduch5"))
        {
            msg.adccmdpduch5 = (obj["adccmdpduch5"].is_string()?(bool)atoi(obj["adccmdpduch5"].get<std::string>().c_str()):obj["adccmdpduch5"].get<bool>());
        }
        if(obj.contains("adccmdpduch4"))
        {
            msg.adccmdpduch4 = (obj["adccmdpduch4"].is_string()?(bool)atoi(obj["adccmdpduch4"].get<std::string>().c_str()):obj["adccmdpduch4"].get<bool>());
        }
        if(obj.contains("adccmdpduch3"))
        {
            msg.adccmdpduch3 = (obj["adccmdpduch3"].is_string()?(bool)atoi(obj["adccmdpduch3"].get<std::string>().c_str()):obj["adccmdpduch3"].get<bool>());
        }
        if(obj.contains("adccmdpduch2"))
        {
            msg.adccmdpduch2 = (obj["adccmdpduch2"].is_string()?(bool)atoi(obj["adccmdpduch2"].get<std::string>().c_str()):obj["adccmdpduch2"].get<bool>());
        }
        if(obj.contains("adccmdpduch1"))
        {
            msg.adccmdpduch1 = (obj["adccmdpduch1"].is_string()?(bool)atoi(obj["adccmdpduch1"].get<std::string>().c_str()):obj["adccmdpduch1"].get<bool>());
        }
        if(obj.contains("adccmdhazardlights"))
        {
            msg.adccmdhazardlights = (obj["adccmdhazardlights"].is_string()?(bool)atoi(obj["adccmdhazardlights"].get<std::string>().c_str()):obj["adccmdhazardlights"].get<bool>());
        }
        if(obj.contains("adccmdhighbeam"))
        {
            msg.adccmdhighbeam = (obj["adccmdhighbeam"].is_string()?(bool)atoi(obj["adccmdhighbeam"].get<std::string>().c_str()):obj["adccmdhighbeam"].get<bool>());
        }
        if(obj.contains("adccmdlowbeam"))
        {
            msg.adccmdlowbeam = (obj["adccmdlowbeam"].is_string()?(bool)atoi(obj["adccmdlowbeam"].get<std::string>().c_str()):obj["adccmdlowbeam"].get<bool>());
        }
        if(obj.contains("adccmdhorn"))
        {
            msg.adccmdhorn = (obj["adccmdhorn"].is_string()?(bool)atoi(obj["adccmdhorn"].get<std::string>().c_str()):obj["adccmdhorn"].get<bool>());
        }
        if(obj.contains("adccmdturnsignal"))
        {
            msg.adccmdturnsignal = (obj["adccmdturnsignal"].is_string()?atoi(obj["adccmdturnsignal"].get<std::string>().c_str()):obj["adccmdturnsignal"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusAdcAuxiliarycontrol110 from_json<ApollocanbusAdcAuxiliarycontrol110>(nlohmann::json obj){
        return from_json_ApollocanbusAdcAuxiliarycontrol110(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusAdcAuxiliarycontrol110 &dt)
    {
        dt=from_json_ApollocanbusAdcAuxiliarycontrol110(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusAdcAuxiliarycontrol110 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusAdcAuxiliarycontrol110 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
