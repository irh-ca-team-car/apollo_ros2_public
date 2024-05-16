#include "adapter/serialization/apollo_msgs/apolloplanning_hybrid_a_star_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningHybridAStarConfig &msg) {
        nlohmann::json obj;
        obj["xygridresolution"] = (msg.xygridresolution);
        obj["phigridresolution"] = (msg.phigridresolution);
        obj["nextnodenum"] = (msg.nextnodenum);
        obj["stepsize"] = (msg.stepsize);
        obj["trajforwardpenalty"] = (msg.trajforwardpenalty);
        obj["trajbackpenalty"] = (msg.trajbackpenalty);
        obj["trajgearswitchpenalty"] = (msg.trajgearswitchpenalty);
        obj["trajsteerpenalty"] = (msg.trajsteerpenalty);
        obj["trajsteerchangepenalty"] = (msg.trajsteerchangepenalty);
        obj["gridastarxyresolution"] = (msg.gridastarxyresolution);
        obj["noderadius"] = (msg.noderadius);
        return obj;
    }
    ApolloplanningHybridAStarConfig from_json_ApolloplanningHybridAStarConfig (nlohmann::json obj) {
        ApolloplanningHybridAStarConfig msg;
        if(obj.contains("xygridresolution"))
        {
            msg.xygridresolution = (obj["xygridresolution"].is_string()?atof(obj["xygridresolution"].get<std::string>().c_str()):obj["xygridresolution"].get<double>());
        }
        if(obj.contains("phigridresolution"))
        {
            msg.phigridresolution = (obj["phigridresolution"].is_string()?atof(obj["phigridresolution"].get<std::string>().c_str()):obj["phigridresolution"].get<double>());
        }
        if(obj.contains("nextnodenum"))
        {
            msg.nextnodenum = (obj["nextnodenum"].is_string()?atol(obj["nextnodenum"].get<std::string>().c_str()):obj["nextnodenum"].get<uint64_t>());
        }
        if(obj.contains("stepsize"))
        {
            msg.stepsize = (obj["stepsize"].is_string()?atof(obj["stepsize"].get<std::string>().c_str()):obj["stepsize"].get<double>());
        }
        if(obj.contains("trajforwardpenalty"))
        {
            msg.trajforwardpenalty = (obj["trajforwardpenalty"].is_string()?atof(obj["trajforwardpenalty"].get<std::string>().c_str()):obj["trajforwardpenalty"].get<double>());
        }
        if(obj.contains("trajbackpenalty"))
        {
            msg.trajbackpenalty = (obj["trajbackpenalty"].is_string()?atof(obj["trajbackpenalty"].get<std::string>().c_str()):obj["trajbackpenalty"].get<double>());
        }
        if(obj.contains("trajgearswitchpenalty"))
        {
            msg.trajgearswitchpenalty = (obj["trajgearswitchpenalty"].is_string()?atof(obj["trajgearswitchpenalty"].get<std::string>().c_str()):obj["trajgearswitchpenalty"].get<double>());
        }
        if(obj.contains("trajsteerpenalty"))
        {
            msg.trajsteerpenalty = (obj["trajsteerpenalty"].is_string()?atof(obj["trajsteerpenalty"].get<std::string>().c_str()):obj["trajsteerpenalty"].get<double>());
        }
        if(obj.contains("trajsteerchangepenalty"))
        {
            msg.trajsteerchangepenalty = (obj["trajsteerchangepenalty"].is_string()?atof(obj["trajsteerchangepenalty"].get<std::string>().c_str()):obj["trajsteerchangepenalty"].get<double>());
        }
        if(obj.contains("gridastarxyresolution"))
        {
            msg.gridastarxyresolution = (obj["gridastarxyresolution"].is_string()?atof(obj["gridastarxyresolution"].get<std::string>().c_str()):obj["gridastarxyresolution"].get<double>());
        }
        if(obj.contains("noderadius"))
        {
            msg.noderadius = (obj["noderadius"].is_string()?atof(obj["noderadius"].get<std::string>().c_str()):obj["noderadius"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningHybridAStarConfig from_json<ApolloplanningHybridAStarConfig>(nlohmann::json obj){
        return from_json_ApolloplanningHybridAStarConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningHybridAStarConfig &dt)
    {
        dt=from_json_ApolloplanningHybridAStarConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningHybridAStarConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningHybridAStarConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
