#include "adapter/serialization/apollo_msgs/apolloplanning_planning_tag.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPlanningTag &msg) {
        nlohmann::json obj;
        obj["laneturn"] = (msg.laneturn);
        obj["cleararea"] = to_json(msg.cleararea);
        obj["crosswalk"] = to_json(msg.crosswalk);
        obj["pncjunction"] = to_json(msg.pncjunction);
        obj["signal"] = to_json(msg.signal);
        obj["stopsign"] = to_json(msg.stopsign);
        obj["yieldsign"] = to_json(msg.yieldsign);
        return obj;
    }
    ApolloplanningPlanningTag from_json_ApolloplanningPlanningTag (nlohmann::json obj) {
        ApolloplanningPlanningTag msg;
        if(obj.contains("laneturn"))
        {
            msg.laneturn = (obj["laneturn"].is_string()?atoi(obj["laneturn"].get<std::string>().c_str()):obj["laneturn"].get<int>());
        }
        if(obj.contains("cleararea"))
        {
            msg.cleararea = from_json_ApolloplanningOverlapFeature(obj["cleararea"]);
        }
        if(obj.contains("crosswalk"))
        {
            msg.crosswalk = from_json_ApolloplanningOverlapFeature(obj["crosswalk"]);
        }
        if(obj.contains("pncjunction"))
        {
            msg.pncjunction = from_json_ApolloplanningOverlapFeature(obj["pncjunction"]);
        }
        if(obj.contains("signal"))
        {
            msg.signal = from_json_ApolloplanningOverlapFeature(obj["signal"]);
        }
        if(obj.contains("stopsign"))
        {
            msg.stopsign = from_json_ApolloplanningOverlapFeature(obj["stopsign"]);
        }
        if(obj.contains("yieldsign"))
        {
            msg.yieldsign = from_json_ApolloplanningOverlapFeature(obj["yieldsign"]);
        }
        return msg;
    }
    template <>
    ApolloplanningPlanningTag from_json<ApolloplanningPlanningTag>(nlohmann::json obj){
        return from_json_ApolloplanningPlanningTag(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPlanningTag &dt)
    {
        dt=from_json_ApolloplanningPlanningTag(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPlanningTag & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPlanningTag & dt)
    {
        os << to_json(dt);
        return os;
    }
}
