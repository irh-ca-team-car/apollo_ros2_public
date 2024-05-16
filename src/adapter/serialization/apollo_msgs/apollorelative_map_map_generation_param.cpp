#include "adapter/serialization/apollo_msgs/apollorelative_map_map_generation_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapMapGenerationParam &msg) {
        nlohmann::json obj;
        obj["defaultleftwidth"] = (msg.defaultleftwidth);
        obj["defaultrightwidth"] = (msg.defaultrightwidth);
        obj["defaultspeedlimit"] = (msg.defaultspeedlimit);
        return obj;
    }
    ApollorelativeMapMapGenerationParam from_json_ApollorelativeMapMapGenerationParam (nlohmann::json obj) {
        ApollorelativeMapMapGenerationParam msg;
        if(obj.contains("defaultleftwidth"))
        {
            msg.defaultleftwidth = (obj["defaultleftwidth"].is_string()?atof(obj["defaultleftwidth"].get<std::string>().c_str()):obj["defaultleftwidth"].get<double>());
        }
        if(obj.contains("defaultrightwidth"))
        {
            msg.defaultrightwidth = (obj["defaultrightwidth"].is_string()?atof(obj["defaultrightwidth"].get<std::string>().c_str()):obj["defaultrightwidth"].get<double>());
        }
        if(obj.contains("defaultspeedlimit"))
        {
            msg.defaultspeedlimit = (obj["defaultspeedlimit"].is_string()?atof(obj["defaultspeedlimit"].get<std::string>().c_str()):obj["defaultspeedlimit"].get<double>());
        }
        return msg;
    }
    template <>
    ApollorelativeMapMapGenerationParam from_json<ApollorelativeMapMapGenerationParam>(nlohmann::json obj){
        return from_json_ApollorelativeMapMapGenerationParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapMapGenerationParam &dt)
    {
        dt=from_json_ApollorelativeMapMapGenerationParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapMapGenerationParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapMapGenerationParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
