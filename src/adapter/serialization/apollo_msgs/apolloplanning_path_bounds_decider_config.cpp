#include "adapter/serialization/apollo_msgs/apolloplanning_path_bounds_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPathBoundsDeciderConfig &msg) {
        nlohmann::json obj;
        obj["islaneborrowing"] = (msg.islaneborrowing);
        obj["ispullover"] = (msg.ispullover);
        obj["pulloverdestinationtoadcbuffer"] = (msg.pulloverdestinationtoadcbuffer);
        obj["pulloverdestinationtopathendbuffer"] = (msg.pulloverdestinationtopathendbuffer);
        obj["pulloverroadedgebuffer"] = (msg.pulloverroadedgebuffer);
        obj["pulloverapproachlondistanceadjustfactor"] = (msg.pulloverapproachlondistanceadjustfactor);
        obj["adcbuffercoeff"] = (msg.adcbuffercoeff);
        obj["isextendlaneboundstoincludeadc"] = (msg.isextendlaneboundstoincludeadc);
        return obj;
    }
    ApolloplanningPathBoundsDeciderConfig from_json_ApolloplanningPathBoundsDeciderConfig (nlohmann::json obj) {
        ApolloplanningPathBoundsDeciderConfig msg;
        if(obj.contains("islaneborrowing"))
        {
            msg.islaneborrowing = (obj["islaneborrowing"].is_string()?(bool)atoi(obj["islaneborrowing"].get<std::string>().c_str()):obj["islaneborrowing"].get<bool>());
        }
        if(obj.contains("ispullover"))
        {
            msg.ispullover = (obj["ispullover"].is_string()?(bool)atoi(obj["ispullover"].get<std::string>().c_str()):obj["ispullover"].get<bool>());
        }
        if(obj.contains("pulloverdestinationtoadcbuffer"))
        {
            msg.pulloverdestinationtoadcbuffer = (obj["pulloverdestinationtoadcbuffer"].is_string()?atof(obj["pulloverdestinationtoadcbuffer"].get<std::string>().c_str()):obj["pulloverdestinationtoadcbuffer"].get<double>());
        }
        if(obj.contains("pulloverdestinationtopathendbuffer"))
        {
            msg.pulloverdestinationtopathendbuffer = (obj["pulloverdestinationtopathendbuffer"].is_string()?atof(obj["pulloverdestinationtopathendbuffer"].get<std::string>().c_str()):obj["pulloverdestinationtopathendbuffer"].get<double>());
        }
        if(obj.contains("pulloverroadedgebuffer"))
        {
            msg.pulloverroadedgebuffer = (obj["pulloverroadedgebuffer"].is_string()?atof(obj["pulloverroadedgebuffer"].get<std::string>().c_str()):obj["pulloverroadedgebuffer"].get<double>());
        }
        if(obj.contains("pulloverapproachlondistanceadjustfactor"))
        {
            msg.pulloverapproachlondistanceadjustfactor = (obj["pulloverapproachlondistanceadjustfactor"].is_string()?atof(obj["pulloverapproachlondistanceadjustfactor"].get<std::string>().c_str()):obj["pulloverapproachlondistanceadjustfactor"].get<double>());
        }
        if(obj.contains("adcbuffercoeff"))
        {
            msg.adcbuffercoeff = (obj["adcbuffercoeff"].is_string()?atof(obj["adcbuffercoeff"].get<std::string>().c_str()):obj["adcbuffercoeff"].get<double>());
        }
        if(obj.contains("isextendlaneboundstoincludeadc"))
        {
            msg.isextendlaneboundstoincludeadc = (obj["isextendlaneboundstoincludeadc"].is_string()?(bool)atoi(obj["isextendlaneboundstoincludeadc"].get<std::string>().c_str()):obj["isextendlaneboundstoincludeadc"].get<bool>());
        }
        return msg;
    }
    template <>
    ApolloplanningPathBoundsDeciderConfig from_json<ApolloplanningPathBoundsDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningPathBoundsDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPathBoundsDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningPathBoundsDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPathBoundsDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPathBoundsDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
