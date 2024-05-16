#include "adapter/serialization/apollo_msgs/apolloplanning_navi_path_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningNaviPathDeciderConfig &msg) {
        nlohmann::json obj;
        obj["minpathlength"] = (msg.minpathlength);
        obj["minlookforwardtime"] = (msg.minlookforwardtime);
        obj["maxkeeplanedistance"] = (msg.maxkeeplanedistance);
        obj["maxkeeplaneshifty"] = (msg.maxkeeplaneshifty);
        obj["minkeeplaneoffset"] = (msg.minkeeplaneoffset);
        obj["keeplaneshiftcompensation"] = (msg.keeplaneshiftcompensation);
        obj["movedestlaneconfigtalbe"] = to_json(msg.movedestlaneconfigtalbe);
        obj["movedestlanecompensation"] = (msg.movedestlanecompensation);
        obj["maxkappathreshold"] = (msg.maxkappathreshold);
        obj["kappamovedestlanecompensation"] = (msg.kappamovedestlanecompensation);
        obj["startplanpointfrom"] = (msg.startplanpointfrom);
        return obj;
    }
    ApolloplanningNaviPathDeciderConfig from_json_ApolloplanningNaviPathDeciderConfig (nlohmann::json obj) {
        ApolloplanningNaviPathDeciderConfig msg;
        if(obj.contains("minpathlength"))
        {
            msg.minpathlength = (obj["minpathlength"].is_string()?atof(obj["minpathlength"].get<std::string>().c_str()):obj["minpathlength"].get<double>());
        }
        if(obj.contains("minlookforwardtime"))
        {
            msg.minlookforwardtime = (obj["minlookforwardtime"].is_string()?atoi(obj["minlookforwardtime"].get<std::string>().c_str()):obj["minlookforwardtime"].get<uint32_t>());
        }
        if(obj.contains("maxkeeplanedistance"))
        {
            msg.maxkeeplanedistance = (obj["maxkeeplanedistance"].is_string()?atof(obj["maxkeeplanedistance"].get<std::string>().c_str()):obj["maxkeeplanedistance"].get<double>());
        }
        if(obj.contains("maxkeeplaneshifty"))
        {
            msg.maxkeeplaneshifty = (obj["maxkeeplaneshifty"].is_string()?atof(obj["maxkeeplaneshifty"].get<std::string>().c_str()):obj["maxkeeplaneshifty"].get<double>());
        }
        if(obj.contains("minkeeplaneoffset"))
        {
            msg.minkeeplaneoffset = (obj["minkeeplaneoffset"].is_string()?atof(obj["minkeeplaneoffset"].get<std::string>().c_str()):obj["minkeeplaneoffset"].get<double>());
        }
        if(obj.contains("keeplaneshiftcompensation"))
        {
            msg.keeplaneshiftcompensation = (obj["keeplaneshiftcompensation"].is_string()?atof(obj["keeplaneshiftcompensation"].get<std::string>().c_str()):obj["keeplaneshiftcompensation"].get<double>());
        }
        if(obj.contains("movedestlaneconfigtalbe"))
        {
            msg.movedestlaneconfigtalbe = from_json_ApolloplanningMoveDestLaneConfigTable(obj["movedestlaneconfigtalbe"]);
        }
        if(obj.contains("movedestlanecompensation"))
        {
            msg.movedestlanecompensation = (obj["movedestlanecompensation"].is_string()?atof(obj["movedestlanecompensation"].get<std::string>().c_str()):obj["movedestlanecompensation"].get<double>());
        }
        if(obj.contains("maxkappathreshold"))
        {
            msg.maxkappathreshold = (obj["maxkappathreshold"].is_string()?atof(obj["maxkappathreshold"].get<std::string>().c_str()):obj["maxkappathreshold"].get<double>());
        }
        if(obj.contains("kappamovedestlanecompensation"))
        {
            msg.kappamovedestlanecompensation = (obj["kappamovedestlanecompensation"].is_string()?atof(obj["kappamovedestlanecompensation"].get<std::string>().c_str()):obj["kappamovedestlanecompensation"].get<double>());
        }
        if(obj.contains("startplanpointfrom"))
        {
            msg.startplanpointfrom = (obj["startplanpointfrom"].is_string()?atoi(obj["startplanpointfrom"].get<std::string>().c_str()):obj["startplanpointfrom"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloplanningNaviPathDeciderConfig from_json<ApolloplanningNaviPathDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningNaviPathDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningNaviPathDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningNaviPathDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningNaviPathDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningNaviPathDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
