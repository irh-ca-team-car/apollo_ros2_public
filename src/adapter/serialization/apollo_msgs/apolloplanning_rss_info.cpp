#include "adapter/serialization/apollo_msgs/apolloplanning_rss_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningRSSInfo &msg) {
        nlohmann::json obj;
        obj["isrsssafe"] = (msg.isrsssafe);
        obj["curdistlon"] = (msg.curdistlon);
        obj["rsssafedistlon"] = (msg.rsssafedistlon);
        obj["acclonrangeminimum"] = (msg.acclonrangeminimum);
        obj["acclonrangemaximum"] = (msg.acclonrangemaximum);
        obj["acclatleftrangeminimum"] = (msg.acclatleftrangeminimum);
        obj["acclatleftrangemaximum"] = (msg.acclatleftrangemaximum);
        obj["acclatrightrangeminimum"] = (msg.acclatrightrangeminimum);
        obj["acclatrightrangemaximum"] = (msg.acclatrightrangemaximum);
        return obj;
    }
    ApolloplanningRSSInfo from_json_ApolloplanningRSSInfo (nlohmann::json obj) {
        ApolloplanningRSSInfo msg;
        if(obj.contains("isrsssafe"))
        {
            msg.isrsssafe = (obj["isrsssafe"].is_string()?(bool)atoi(obj["isrsssafe"].get<std::string>().c_str()):obj["isrsssafe"].get<bool>());
        }
        if(obj.contains("curdistlon"))
        {
            msg.curdistlon = (obj["curdistlon"].is_string()?atof(obj["curdistlon"].get<std::string>().c_str()):obj["curdistlon"].get<double>());
        }
        if(obj.contains("rsssafedistlon"))
        {
            msg.rsssafedistlon = (obj["rsssafedistlon"].is_string()?atof(obj["rsssafedistlon"].get<std::string>().c_str()):obj["rsssafedistlon"].get<double>());
        }
        if(obj.contains("acclonrangeminimum"))
        {
            msg.acclonrangeminimum = (obj["acclonrangeminimum"].is_string()?atof(obj["acclonrangeminimum"].get<std::string>().c_str()):obj["acclonrangeminimum"].get<double>());
        }
        if(obj.contains("acclonrangemaximum"))
        {
            msg.acclonrangemaximum = (obj["acclonrangemaximum"].is_string()?atof(obj["acclonrangemaximum"].get<std::string>().c_str()):obj["acclonrangemaximum"].get<double>());
        }
        if(obj.contains("acclatleftrangeminimum"))
        {
            msg.acclatleftrangeminimum = (obj["acclatleftrangeminimum"].is_string()?atof(obj["acclatleftrangeminimum"].get<std::string>().c_str()):obj["acclatleftrangeminimum"].get<double>());
        }
        if(obj.contains("acclatleftrangemaximum"))
        {
            msg.acclatleftrangemaximum = (obj["acclatleftrangemaximum"].is_string()?atof(obj["acclatleftrangemaximum"].get<std::string>().c_str()):obj["acclatleftrangemaximum"].get<double>());
        }
        if(obj.contains("acclatrightrangeminimum"))
        {
            msg.acclatrightrangeminimum = (obj["acclatrightrangeminimum"].is_string()?atof(obj["acclatrightrangeminimum"].get<std::string>().c_str()):obj["acclatrightrangeminimum"].get<double>());
        }
        if(obj.contains("acclatrightrangemaximum"))
        {
            msg.acclatrightrangemaximum = (obj["acclatrightrangemaximum"].is_string()?atof(obj["acclatrightrangemaximum"].get<std::string>().c_str()):obj["acclatrightrangemaximum"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningRSSInfo from_json<ApolloplanningRSSInfo>(nlohmann::json obj){
        return from_json_ApolloplanningRSSInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningRSSInfo &dt)
    {
        dt=from_json_ApolloplanningRSSInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningRSSInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningRSSInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
