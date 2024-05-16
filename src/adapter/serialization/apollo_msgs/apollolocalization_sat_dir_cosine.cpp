#include "adapter/serialization/apollo_msgs/apollolocalization_sat_dir_cosine.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationSatDirCosine &msg) {
        nlohmann::json obj;
        obj["satprn"] = (msg.satprn);
        obj["satsys"] = (msg.satsys);
        obj["cosinex"] = (msg.cosinex);
        obj["cosiney"] = (msg.cosiney);
        obj["cosinez"] = (msg.cosinez);
        return obj;
    }
    ApollolocalizationSatDirCosine from_json_ApollolocalizationSatDirCosine (nlohmann::json obj) {
        ApollolocalizationSatDirCosine msg;
        if(obj.contains("satprn"))
        {
            msg.satprn = (obj["satprn"].is_string()?atoi(obj["satprn"].get<std::string>().c_str()):obj["satprn"].get<uint32_t>());
        }
        if(obj.contains("satsys"))
        {
            msg.satsys = (obj["satsys"].is_string()?atoi(obj["satsys"].get<std::string>().c_str()):obj["satsys"].get<uint32_t>());
        }
        if(obj.contains("cosinex"))
        {
            msg.cosinex = (obj["cosinex"].is_string()?atof(obj["cosinex"].get<std::string>().c_str()):obj["cosinex"].get<double>());
        }
        if(obj.contains("cosiney"))
        {
            msg.cosiney = (obj["cosiney"].is_string()?atof(obj["cosiney"].get<std::string>().c_str()):obj["cosiney"].get<double>());
        }
        if(obj.contains("cosinez"))
        {
            msg.cosinez = (obj["cosinez"].is_string()?atof(obj["cosinez"].get<std::string>().c_str()):obj["cosinez"].get<double>());
        }
        return msg;
    }
    template <>
    ApollolocalizationSatDirCosine from_json<ApollolocalizationSatDirCosine>(nlohmann::json obj){
        return from_json_ApollolocalizationSatDirCosine(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationSatDirCosine &dt)
    {
        dt=from_json_ApollolocalizationSatDirCosine(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationSatDirCosine & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationSatDirCosine & dt)
    {
        os << to_json(dt);
        return os;
    }
}
