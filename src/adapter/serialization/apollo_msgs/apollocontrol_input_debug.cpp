#include "adapter/serialization/apollo_msgs/apollocontrol_input_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolInputDebug &msg) {
        nlohmann::json obj;
        obj["localizationheader"] = to_json(msg.localizationheader);
        obj["canbusheader"] = to_json(msg.canbusheader);
        obj["trajectoryheader"] = to_json(msg.trajectoryheader);
        obj["latestreplantrajectoryheader"] = to_json(msg.latestreplantrajectoryheader);
        return obj;
    }
    ApollocontrolInputDebug from_json_ApollocontrolInputDebug (nlohmann::json obj) {
        ApollocontrolInputDebug msg;
        if(obj.contains("localizationheader"))
        {
            msg.localizationheader = from_json_ApollocommonHeader(obj["localizationheader"]);
        }
        if(obj.contains("canbusheader"))
        {
            msg.canbusheader = from_json_ApollocommonHeader(obj["canbusheader"]);
        }
        if(obj.contains("trajectoryheader"))
        {
            msg.trajectoryheader = from_json_ApollocommonHeader(obj["trajectoryheader"]);
        }
        if(obj.contains("latestreplantrajectoryheader"))
        {
            msg.latestreplantrajectoryheader = from_json_ApollocommonHeader(obj["latestreplantrajectoryheader"]);
        }
        return msg;
    }
    template <>
    ApollocontrolInputDebug from_json<ApollocontrolInputDebug>(nlohmann::json obj){
        return from_json_ApollocontrolInputDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolInputDebug &dt)
    {
        dt=from_json_ApollocontrolInputDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolInputDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolInputDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
