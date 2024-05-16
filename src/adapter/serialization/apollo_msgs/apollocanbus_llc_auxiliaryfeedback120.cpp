#include "adapter/serialization/apollo_msgs/apollocanbus_llc_auxiliaryfeedback120.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcAuxiliaryfeedback120 &msg) {
        nlohmann::json obj;
        obj["llcfbkinverter"] = (msg.llcfbkinverter);
        obj["llcfbkpduch8"] = (msg.llcfbkpduch8);
        obj["llcfbkpduch7"] = (msg.llcfbkpduch7);
        obj["llcfbkpduch6"] = (msg.llcfbkpduch6);
        obj["llcfbkpduch5"] = (msg.llcfbkpduch5);
        obj["llcfbkpduch4"] = (msg.llcfbkpduch4);
        obj["llcfbkpduch3"] = (msg.llcfbkpduch3);
        obj["llcfbkpduch2"] = (msg.llcfbkpduch2);
        obj["llcfbkpduch1"] = (msg.llcfbkpduch1);
        obj["llcfbkhazardlights"] = (msg.llcfbkhazardlights);
        obj["llcfbkledgreenon"] = (msg.llcfbkledgreenon);
        obj["llcfbkhorn"] = (msg.llcfbkhorn);
        obj["llcfbkbuzzeron"] = (msg.llcfbkbuzzeron);
        obj["llcfbkturnsignal"] = (msg.llcfbkturnsignal);
        obj["llcfbklowbeam"] = (msg.llcfbklowbeam);
        obj["llcfbkhighbeam"] = (msg.llcfbkhighbeam);
        obj["llcfbkledredon"] = (msg.llcfbkledredon);
        obj["llcfbkautonomybuttonpressed"] = (msg.llcfbkautonomybuttonpressed);
        return obj;
    }
    ApollocanbusLlcAuxiliaryfeedback120 from_json_ApollocanbusLlcAuxiliaryfeedback120 (nlohmann::json obj) {
        ApollocanbusLlcAuxiliaryfeedback120 msg;
        if(obj.contains("llcfbkinverter"))
        {
            msg.llcfbkinverter = (obj["llcfbkinverter"].is_string()?(bool)atoi(obj["llcfbkinverter"].get<std::string>().c_str()):obj["llcfbkinverter"].get<bool>());
        }
        if(obj.contains("llcfbkpduch8"))
        {
            msg.llcfbkpduch8 = (obj["llcfbkpduch8"].is_string()?(bool)atoi(obj["llcfbkpduch8"].get<std::string>().c_str()):obj["llcfbkpduch8"].get<bool>());
        }
        if(obj.contains("llcfbkpduch7"))
        {
            msg.llcfbkpduch7 = (obj["llcfbkpduch7"].is_string()?(bool)atoi(obj["llcfbkpduch7"].get<std::string>().c_str()):obj["llcfbkpduch7"].get<bool>());
        }
        if(obj.contains("llcfbkpduch6"))
        {
            msg.llcfbkpduch6 = (obj["llcfbkpduch6"].is_string()?(bool)atoi(obj["llcfbkpduch6"].get<std::string>().c_str()):obj["llcfbkpduch6"].get<bool>());
        }
        if(obj.contains("llcfbkpduch5"))
        {
            msg.llcfbkpduch5 = (obj["llcfbkpduch5"].is_string()?(bool)atoi(obj["llcfbkpduch5"].get<std::string>().c_str()):obj["llcfbkpduch5"].get<bool>());
        }
        if(obj.contains("llcfbkpduch4"))
        {
            msg.llcfbkpduch4 = (obj["llcfbkpduch4"].is_string()?(bool)atoi(obj["llcfbkpduch4"].get<std::string>().c_str()):obj["llcfbkpduch4"].get<bool>());
        }
        if(obj.contains("llcfbkpduch3"))
        {
            msg.llcfbkpduch3 = (obj["llcfbkpduch3"].is_string()?(bool)atoi(obj["llcfbkpduch3"].get<std::string>().c_str()):obj["llcfbkpduch3"].get<bool>());
        }
        if(obj.contains("llcfbkpduch2"))
        {
            msg.llcfbkpduch2 = (obj["llcfbkpduch2"].is_string()?(bool)atoi(obj["llcfbkpduch2"].get<std::string>().c_str()):obj["llcfbkpduch2"].get<bool>());
        }
        if(obj.contains("llcfbkpduch1"))
        {
            msg.llcfbkpduch1 = (obj["llcfbkpduch1"].is_string()?(bool)atoi(obj["llcfbkpduch1"].get<std::string>().c_str()):obj["llcfbkpduch1"].get<bool>());
        }
        if(obj.contains("llcfbkhazardlights"))
        {
            msg.llcfbkhazardlights = (obj["llcfbkhazardlights"].is_string()?(bool)atoi(obj["llcfbkhazardlights"].get<std::string>().c_str()):obj["llcfbkhazardlights"].get<bool>());
        }
        if(obj.contains("llcfbkledgreenon"))
        {
            msg.llcfbkledgreenon = (obj["llcfbkledgreenon"].is_string()?(bool)atoi(obj["llcfbkledgreenon"].get<std::string>().c_str()):obj["llcfbkledgreenon"].get<bool>());
        }
        if(obj.contains("llcfbkhorn"))
        {
            msg.llcfbkhorn = (obj["llcfbkhorn"].is_string()?(bool)atoi(obj["llcfbkhorn"].get<std::string>().c_str()):obj["llcfbkhorn"].get<bool>());
        }
        if(obj.contains("llcfbkbuzzeron"))
        {
            msg.llcfbkbuzzeron = (obj["llcfbkbuzzeron"].is_string()?(bool)atoi(obj["llcfbkbuzzeron"].get<std::string>().c_str()):obj["llcfbkbuzzeron"].get<bool>());
        }
        if(obj.contains("llcfbkturnsignal"))
        {
            msg.llcfbkturnsignal = (obj["llcfbkturnsignal"].is_string()?atoi(obj["llcfbkturnsignal"].get<std::string>().c_str()):obj["llcfbkturnsignal"].get<int>());
        }
        if(obj.contains("llcfbklowbeam"))
        {
            msg.llcfbklowbeam = (obj["llcfbklowbeam"].is_string()?(bool)atoi(obj["llcfbklowbeam"].get<std::string>().c_str()):obj["llcfbklowbeam"].get<bool>());
        }
        if(obj.contains("llcfbkhighbeam"))
        {
            msg.llcfbkhighbeam = (obj["llcfbkhighbeam"].is_string()?(bool)atoi(obj["llcfbkhighbeam"].get<std::string>().c_str()):obj["llcfbkhighbeam"].get<bool>());
        }
        if(obj.contains("llcfbkledredon"))
        {
            msg.llcfbkledredon = (obj["llcfbkledredon"].is_string()?(bool)atoi(obj["llcfbkledredon"].get<std::string>().c_str()):obj["llcfbkledredon"].get<bool>());
        }
        if(obj.contains("llcfbkautonomybuttonpressed"))
        {
            msg.llcfbkautonomybuttonpressed = (obj["llcfbkautonomybuttonpressed"].is_string()?(bool)atoi(obj["llcfbkautonomybuttonpressed"].get<std::string>().c_str()):obj["llcfbkautonomybuttonpressed"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusLlcAuxiliaryfeedback120 from_json<ApollocanbusLlcAuxiliaryfeedback120>(nlohmann::json obj){
        return from_json_ApollocanbusLlcAuxiliaryfeedback120(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcAuxiliaryfeedback120 &dt)
    {
        dt=from_json_ApollocanbusLlcAuxiliaryfeedback120(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcAuxiliaryfeedback120 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcAuxiliaryfeedback120 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
