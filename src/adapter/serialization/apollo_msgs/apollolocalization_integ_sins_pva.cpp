#include "adapter/serialization/apollo_msgs/apollolocalization_integ_sins_pva.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationIntegSinsPva &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["position"] = to_json(msg.position);
        obj["velocity"] = to_json(msg.velocity);
        obj["attitude"] = to_json(msg.attitude);
        nlohmann::json arr_pvacovar;
        for (auto it = msg.pvacovar.begin(); it != msg.pvacovar.end(); ++it) {
            arr_pvacovar.push_back((*it));
        }
        obj["pvacovar"] = arr_pvacovar;
        obj["initandalignment"] = (msg.initandalignment);
        return obj;
    }
    ApollolocalizationIntegSinsPva from_json_ApollolocalizationIntegSinsPva (nlohmann::json obj) {
        ApollolocalizationIntegSinsPva msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPointLLH(obj["position"]);
        }
        if(obj.contains("velocity"))
        {
            msg.velocity = from_json_ApollocommonPoint3D(obj["velocity"]);
        }
        if(obj.contains("attitude"))
        {
            msg.attitude = from_json_ApollocommonPoint3D(obj["attitude"]);
        }
        if(obj.contains("pvacovar"))
        {
            if(obj["pvacovar"].is_array())
            {
                for (auto& element : obj["pvacovar"])
                {
                    msg.pvacovar.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.pvacovar.push_back((obj["pvacovar"].is_string()?atof(obj["pvacovar"].get<std::string>().c_str()):obj["pvacovar"].get<double>()));
            }
        }
        if(obj.contains("initandalignment"))
        {
            msg.initandalignment = (obj["initandalignment"].is_string()?(bool)atoi(obj["initandalignment"].get<std::string>().c_str()):obj["initandalignment"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollolocalizationIntegSinsPva from_json<ApollolocalizationIntegSinsPva>(nlohmann::json obj){
        return from_json_ApollolocalizationIntegSinsPva(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationIntegSinsPva &dt)
    {
        dt=from_json_ApollolocalizationIntegSinsPva(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationIntegSinsPva & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationIntegSinsPva & dt)
    {
        os << to_json(dt);
        return os;
    }
}
