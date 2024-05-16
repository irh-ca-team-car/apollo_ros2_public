#include "adapter/serialization/apollo_msgs/apollodrivers_ldw_lens_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversLdwLensInfo &msg) {
        nlohmann::json obj;
        obj["ximagefocal"] = (msg.ximagefocal);
        obj["yimagefocal"] = (msg.yimagefocal);
        obj["xratiofocalpixel"] = (msg.xratiofocalpixel);
        obj["yratiofocalpixel"] = (msg.yratiofocalpixel);
        obj["mountingheight"] = (msg.mountingheight);
        obj["mcosrx"] = (msg.mcosrx);
        obj["msinrx"] = (msg.msinrx);
        obj["mcosry"] = (msg.mcosry);
        obj["msinry"] = (msg.msinry);
        return obj;
    }
    ApollodriversLdwLensInfo from_json_ApollodriversLdwLensInfo (nlohmann::json obj) {
        ApollodriversLdwLensInfo msg;
        if(obj.contains("ximagefocal"))
        {
            msg.ximagefocal = (obj["ximagefocal"].is_string()?(float)atof(obj["ximagefocal"].get<std::string>().c_str()):obj["ximagefocal"].get<float>());
        }
        if(obj.contains("yimagefocal"))
        {
            msg.yimagefocal = (obj["yimagefocal"].is_string()?(float)atof(obj["yimagefocal"].get<std::string>().c_str()):obj["yimagefocal"].get<float>());
        }
        if(obj.contains("xratiofocalpixel"))
        {
            msg.xratiofocalpixel = (obj["xratiofocalpixel"].is_string()?(float)atof(obj["xratiofocalpixel"].get<std::string>().c_str()):obj["xratiofocalpixel"].get<float>());
        }
        if(obj.contains("yratiofocalpixel"))
        {
            msg.yratiofocalpixel = (obj["yratiofocalpixel"].is_string()?(float)atof(obj["yratiofocalpixel"].get<std::string>().c_str()):obj["yratiofocalpixel"].get<float>());
        }
        if(obj.contains("mountingheight"))
        {
            msg.mountingheight = (obj["mountingheight"].is_string()?(float)atof(obj["mountingheight"].get<std::string>().c_str()):obj["mountingheight"].get<float>());
        }
        if(obj.contains("mcosrx"))
        {
            msg.mcosrx = (obj["mcosrx"].is_string()?(float)atof(obj["mcosrx"].get<std::string>().c_str()):obj["mcosrx"].get<float>());
        }
        if(obj.contains("msinrx"))
        {
            msg.msinrx = (obj["msinrx"].is_string()?(float)atof(obj["msinrx"].get<std::string>().c_str()):obj["msinrx"].get<float>());
        }
        if(obj.contains("mcosry"))
        {
            msg.mcosry = (obj["mcosry"].is_string()?(float)atof(obj["mcosry"].get<std::string>().c_str()):obj["mcosry"].get<float>());
        }
        if(obj.contains("msinry"))
        {
            msg.msinry = (obj["msinry"].is_string()?(float)atof(obj["msinry"].get<std::string>().c_str()):obj["msinry"].get<float>());
        }
        return msg;
    }
    template <>
    ApollodriversLdwLensInfo from_json<ApollodriversLdwLensInfo>(nlohmann::json obj){
        return from_json_ApollodriversLdwLensInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversLdwLensInfo &dt)
    {
        dt=from_json_ApollodriversLdwLensInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversLdwLensInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversLdwLensInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
