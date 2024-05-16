#include "adapter/serialization/apollo_msgs/apollocontrol_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolDebug &msg) {
        nlohmann::json obj;
        obj["simplelondebug"] = to_json(msg.simplelondebug);
        obj["simplelatdebug"] = to_json(msg.simplelatdebug);
        obj["inputdebug"] = to_json(msg.inputdebug);
        obj["simplempcdebug"] = to_json(msg.simplempcdebug);
        return obj;
    }
    ApollocontrolDebug from_json_ApollocontrolDebug (nlohmann::json obj) {
        ApollocontrolDebug msg;
        if(obj.contains("simplelondebug"))
        {
            msg.simplelondebug = from_json_ApollocontrolSimpleLongitudinalDebug(obj["simplelondebug"]);
        }
        if(obj.contains("simplelatdebug"))
        {
            msg.simplelatdebug = from_json_ApollocontrolSimpleLateralDebug(obj["simplelatdebug"]);
        }
        if(obj.contains("inputdebug"))
        {
            msg.inputdebug = from_json_ApollocontrolInputDebug(obj["inputdebug"]);
        }
        if(obj.contains("simplempcdebug"))
        {
            msg.simplempcdebug = from_json_ApollocontrolSimpleMPCDebug(obj["simplempcdebug"]);
        }
        return msg;
    }
    template <>
    ApollocontrolDebug from_json<ApollocontrolDebug>(nlohmann::json obj){
        return from_json_ApollocontrolDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolDebug &dt)
    {
        dt=from_json_ApollocontrolDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
