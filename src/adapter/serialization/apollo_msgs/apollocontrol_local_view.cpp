#include "adapter/serialization/apollo_msgs/apollocontrol_local_view.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolLocalView &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["chassis"] = to_json(msg.chassis);
        obj["trajectory"] = to_json(msg.trajectory);
        obj["localization"] = to_json(msg.localization);
        obj["padmsg"] = to_json(msg.padmsg);
        return obj;
    }
    ApollocontrolLocalView from_json_ApollocontrolLocalView (nlohmann::json obj) {
        ApollocontrolLocalView msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("chassis"))
        {
            msg.chassis = from_json_ApollocanbusChassis(obj["chassis"]);
        }
        if(obj.contains("trajectory"))
        {
            msg.trajectory = from_json_ApolloplanningADCTrajectory(obj["trajectory"]);
        }
        if(obj.contains("localization"))
        {
            msg.localization = from_json_ApollolocalizationLocalizationEstimate(obj["localization"]);
        }
        if(obj.contains("padmsg"))
        {
            msg.padmsg = from_json_ApollocontrolPadMessage(obj["padmsg"]);
        }
        return msg;
    }
    template <>
    ApollocontrolLocalView from_json<ApollocontrolLocalView>(nlohmann::json obj){
        return from_json_ApollocontrolLocalView(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolLocalView &dt)
    {
        dt=from_json_ApollocontrolLocalView(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolLocalView & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolLocalView & dt)
    {
        os << to_json(dt);
        return os;
    }
}
