#include "adapter/serialization/apollo_msgs/apollodrivers_esr_status44e3.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversEsrStatus44e3 &msg) {
        nlohmann::json obj;
        obj["cantxtrucktargetdet"] = (msg.cantxtrucktargetdet);
        obj["cantxlronlygratinglobedet"] = (msg.cantxlronlygratinglobedet);
        obj["cantxsidelobeblockage"] = (msg.cantxsidelobeblockage);
        obj["cantxpartialblockage"] = (msg.cantxpartialblockage);
        obj["cantxpathidaccstat"] = (msg.cantxpathidaccstat);
        obj["cantxmrlrmode"] = (msg.cantxmrlrmode);
        obj["cantxautoalignangle"] = (msg.cantxautoalignangle);
        obj["cantxrollingcount3"] = (msg.cantxrollingcount3);
        obj["cantxpathidfcwstat"] = (msg.cantxpathidfcwstat);
        obj["cantxpathidfcwmove"] = (msg.cantxpathidfcwmove);
        obj["cantxpathidcmbbstat"] = (msg.cantxpathidcmbbstat);
        obj["cantxpathidcmbbmove"] = (msg.cantxpathidcmbbmove);
        obj["cantxpathidacc"] = (msg.cantxpathidacc);
        return obj;
    }
    ApollodriversEsrStatus44e3 from_json_ApollodriversEsrStatus44e3 (nlohmann::json obj) {
        ApollodriversEsrStatus44e3 msg;
        if(obj.contains("cantxtrucktargetdet"))
        {
            msg.cantxtrucktargetdet = (obj["cantxtrucktargetdet"].is_string()?atoi(obj["cantxtrucktargetdet"].get<std::string>().c_str()):obj["cantxtrucktargetdet"].get<int>());
        }
        if(obj.contains("cantxlronlygratinglobedet"))
        {
            msg.cantxlronlygratinglobedet = (obj["cantxlronlygratinglobedet"].is_string()?atoi(obj["cantxlronlygratinglobedet"].get<std::string>().c_str()):obj["cantxlronlygratinglobedet"].get<int>());
        }
        if(obj.contains("cantxsidelobeblockage"))
        {
            msg.cantxsidelobeblockage = (obj["cantxsidelobeblockage"].is_string()?atoi(obj["cantxsidelobeblockage"].get<std::string>().c_str()):obj["cantxsidelobeblockage"].get<int>());
        }
        if(obj.contains("cantxpartialblockage"))
        {
            msg.cantxpartialblockage = (obj["cantxpartialblockage"].is_string()?atoi(obj["cantxpartialblockage"].get<std::string>().c_str()):obj["cantxpartialblockage"].get<int>());
        }
        if(obj.contains("cantxpathidaccstat"))
        {
            msg.cantxpathidaccstat = (obj["cantxpathidaccstat"].is_string()?atoi(obj["cantxpathidaccstat"].get<std::string>().c_str()):obj["cantxpathidaccstat"].get<int>());
        }
        if(obj.contains("cantxmrlrmode"))
        {
            msg.cantxmrlrmode = (obj["cantxmrlrmode"].is_string()?atoi(obj["cantxmrlrmode"].get<std::string>().c_str()):obj["cantxmrlrmode"].get<int>());
        }
        if(obj.contains("cantxautoalignangle"))
        {
            msg.cantxautoalignangle = (obj["cantxautoalignangle"].is_string()?atof(obj["cantxautoalignangle"].get<std::string>().c_str()):obj["cantxautoalignangle"].get<double>());
        }
        if(obj.contains("cantxrollingcount3"))
        {
            msg.cantxrollingcount3 = (obj["cantxrollingcount3"].is_string()?atoi(obj["cantxrollingcount3"].get<std::string>().c_str()):obj["cantxrollingcount3"].get<int>());
        }
        if(obj.contains("cantxpathidfcwstat"))
        {
            msg.cantxpathidfcwstat = (obj["cantxpathidfcwstat"].is_string()?atoi(obj["cantxpathidfcwstat"].get<std::string>().c_str()):obj["cantxpathidfcwstat"].get<int>());
        }
        if(obj.contains("cantxpathidfcwmove"))
        {
            msg.cantxpathidfcwmove = (obj["cantxpathidfcwmove"].is_string()?atoi(obj["cantxpathidfcwmove"].get<std::string>().c_str()):obj["cantxpathidfcwmove"].get<int>());
        }
        if(obj.contains("cantxpathidcmbbstat"))
        {
            msg.cantxpathidcmbbstat = (obj["cantxpathidcmbbstat"].is_string()?atoi(obj["cantxpathidcmbbstat"].get<std::string>().c_str()):obj["cantxpathidcmbbstat"].get<int>());
        }
        if(obj.contains("cantxpathidcmbbmove"))
        {
            msg.cantxpathidcmbbmove = (obj["cantxpathidcmbbmove"].is_string()?atoi(obj["cantxpathidcmbbmove"].get<std::string>().c_str()):obj["cantxpathidcmbbmove"].get<int>());
        }
        if(obj.contains("cantxpathidacc"))
        {
            msg.cantxpathidacc = (obj["cantxpathidacc"].is_string()?atoi(obj["cantxpathidacc"].get<std::string>().c_str()):obj["cantxpathidacc"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversEsrStatus44e3 from_json<ApollodriversEsrStatus44e3>(nlohmann::json obj){
        return from_json_ApollodriversEsrStatus44e3(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversEsrStatus44e3 &dt)
    {
        dt=from_json_ApollodriversEsrStatus44e3(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversEsrStatus44e3 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversEsrStatus44e3 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
