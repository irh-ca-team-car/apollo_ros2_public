#include "adapter/serialization/apollo_msgs/apollocanbus_esp.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEsp &msg) {
        nlohmann::json obj;
        obj["isespaccerror"] = (msg.isespaccerror);
        obj["isespon"] = (msg.isespon);
        obj["isespactive"] = (msg.isespactive);
        obj["isabserror"] = (msg.isabserror);
        obj["isabsactive"] = (msg.isabsactive);
        obj["istcsvdcfail"] = (msg.istcsvdcfail);
        obj["isabsenabled"] = (msg.isabsenabled);
        obj["isstabactive"] = (msg.isstabactive);
        obj["isstabenabled"] = (msg.isstabenabled);
        obj["istracactive"] = (msg.istracactive);
        obj["istracenabled"] = (msg.istracenabled);
        return obj;
    }
    ApollocanbusEsp from_json_ApollocanbusEsp (nlohmann::json obj) {
        ApollocanbusEsp msg;
        if(obj.contains("isespaccerror"))
        {
            msg.isespaccerror = (obj["isespaccerror"].is_string()?(bool)atoi(obj["isespaccerror"].get<std::string>().c_str()):obj["isespaccerror"].get<bool>());
        }
        if(obj.contains("isespon"))
        {
            msg.isespon = (obj["isespon"].is_string()?(bool)atoi(obj["isespon"].get<std::string>().c_str()):obj["isespon"].get<bool>());
        }
        if(obj.contains("isespactive"))
        {
            msg.isespactive = (obj["isespactive"].is_string()?(bool)atoi(obj["isespactive"].get<std::string>().c_str()):obj["isespactive"].get<bool>());
        }
        if(obj.contains("isabserror"))
        {
            msg.isabserror = (obj["isabserror"].is_string()?(bool)atoi(obj["isabserror"].get<std::string>().c_str()):obj["isabserror"].get<bool>());
        }
        if(obj.contains("isabsactive"))
        {
            msg.isabsactive = (obj["isabsactive"].is_string()?(bool)atoi(obj["isabsactive"].get<std::string>().c_str()):obj["isabsactive"].get<bool>());
        }
        if(obj.contains("istcsvdcfail"))
        {
            msg.istcsvdcfail = (obj["istcsvdcfail"].is_string()?(bool)atoi(obj["istcsvdcfail"].get<std::string>().c_str()):obj["istcsvdcfail"].get<bool>());
        }
        if(obj.contains("isabsenabled"))
        {
            msg.isabsenabled = (obj["isabsenabled"].is_string()?(bool)atoi(obj["isabsenabled"].get<std::string>().c_str()):obj["isabsenabled"].get<bool>());
        }
        if(obj.contains("isstabactive"))
        {
            msg.isstabactive = (obj["isstabactive"].is_string()?(bool)atoi(obj["isstabactive"].get<std::string>().c_str()):obj["isstabactive"].get<bool>());
        }
        if(obj.contains("isstabenabled"))
        {
            msg.isstabenabled = (obj["isstabenabled"].is_string()?(bool)atoi(obj["isstabenabled"].get<std::string>().c_str()):obj["isstabenabled"].get<bool>());
        }
        if(obj.contains("istracactive"))
        {
            msg.istracactive = (obj["istracactive"].is_string()?(bool)atoi(obj["istracactive"].get<std::string>().c_str()):obj["istracactive"].get<bool>());
        }
        if(obj.contains("istracenabled"))
        {
            msg.istracenabled = (obj["istracenabled"].is_string()?(bool)atoi(obj["istracenabled"].get<std::string>().c_str()):obj["istracenabled"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollocanbusEsp from_json<ApollocanbusEsp>(nlohmann::json obj){
        return from_json_ApollocanbusEsp(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEsp &dt)
    {
        dt=from_json_ApollocanbusEsp(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEsp & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEsp & dt)
    {
        os << to_json(dt);
        return os;
    }
}
