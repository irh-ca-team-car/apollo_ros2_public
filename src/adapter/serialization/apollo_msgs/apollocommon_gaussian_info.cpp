#include "adapter/serialization/apollo_msgs/apollocommon_gaussian_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonGaussianInfo &msg) {
        nlohmann::json obj;
        obj["sigmax"] = (msg.sigmax);
        obj["sigmay"] = (msg.sigmay);
        obj["correlation"] = (msg.correlation);
        obj["areaprobability"] = (msg.areaprobability);
        obj["ellipsea"] = (msg.ellipsea);
        obj["ellipseb"] = (msg.ellipseb);
        obj["thetaa"] = (msg.thetaa);
        return obj;
    }
    ApollocommonGaussianInfo from_json_ApollocommonGaussianInfo (nlohmann::json obj) {
        ApollocommonGaussianInfo msg;
        if(obj.contains("sigmax"))
        {
            msg.sigmax = (obj["sigmax"].is_string()?atof(obj["sigmax"].get<std::string>().c_str()):obj["sigmax"].get<double>());
        }
        if(obj.contains("sigmay"))
        {
            msg.sigmay = (obj["sigmay"].is_string()?atof(obj["sigmay"].get<std::string>().c_str()):obj["sigmay"].get<double>());
        }
        if(obj.contains("correlation"))
        {
            msg.correlation = (obj["correlation"].is_string()?atof(obj["correlation"].get<std::string>().c_str()):obj["correlation"].get<double>());
        }
        if(obj.contains("areaprobability"))
        {
            msg.areaprobability = (obj["areaprobability"].is_string()?atof(obj["areaprobability"].get<std::string>().c_str()):obj["areaprobability"].get<double>());
        }
        if(obj.contains("ellipsea"))
        {
            msg.ellipsea = (obj["ellipsea"].is_string()?atof(obj["ellipsea"].get<std::string>().c_str()):obj["ellipsea"].get<double>());
        }
        if(obj.contains("ellipseb"))
        {
            msg.ellipseb = (obj["ellipseb"].is_string()?atof(obj["ellipseb"].get<std::string>().c_str()):obj["ellipseb"].get<double>());
        }
        if(obj.contains("thetaa"))
        {
            msg.thetaa = (obj["thetaa"].is_string()?atof(obj["thetaa"].get<std::string>().c_str()):obj["thetaa"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocommonGaussianInfo from_json<ApollocommonGaussianInfo>(nlohmann::json obj){
        return from_json_ApollocommonGaussianInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonGaussianInfo &dt)
    {
        dt=from_json_ApollocommonGaussianInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonGaussianInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonGaussianInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
