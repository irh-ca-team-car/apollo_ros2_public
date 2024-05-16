#include "adapter/serialization/apollo_msgs/apolloplanning_object_decision_typeobject_tag.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningObjectDecisionTypeobjectTag &msg) {
        nlohmann::json obj;
        obj["ignore"] = (msg.ignore);
        obj["stop"] = to_json(msg.stop);
        obj["follow"] = to_json(msg.follow);
        obj["yieldd"] = to_json(msg.yieldd);
        obj["overtake"] = to_json(msg.overtake);
        obj["nudge"] = to_json(msg.nudge);
        obj["avoid"] = (msg.avoid);
        obj["sidepass"] = to_json(msg.sidepass);
        return obj;
    }
    ApolloplanningObjectDecisionTypeobjectTag from_json_ApolloplanningObjectDecisionTypeobjectTag (nlohmann::json obj) {
        ApolloplanningObjectDecisionTypeobjectTag msg;
        if(obj.contains("ignore"))
        {
            msg.ignore = (obj["ignore"].is_string()?atoi(obj["ignore"].get<std::string>().c_str()):obj["ignore"].get<int>());
        }
        if(obj.contains("stop"))
        {
            msg.stop = from_json_ApolloplanningObjectStop(obj["stop"]);
        }
        if(obj.contains("follow"))
        {
            msg.follow = from_json_ApolloplanningObjectFollow(obj["follow"]);
        }
        if(obj.contains("yieldd"))
        {
            msg.yieldd = from_json_ApolloplanningObjectYield(obj["yieldd"]);
        }
        if(obj.contains("overtake"))
        {
            msg.overtake = from_json_ApolloplanningObjectOvertake(obj["overtake"]);
        }
        if(obj.contains("nudge"))
        {
            msg.nudge = from_json_ApolloplanningObjectNudge(obj["nudge"]);
        }
        if(obj.contains("avoid"))
        {
            msg.avoid = (obj["avoid"].is_string()?atoi(obj["avoid"].get<std::string>().c_str()):obj["avoid"].get<int>());
        }
        if(obj.contains("sidepass"))
        {
            msg.sidepass = from_json_ApolloplanningObjectSidePass(obj["sidepass"]);
        }
        return msg;
    }
    template <>
    ApolloplanningObjectDecisionTypeobjectTag from_json<ApolloplanningObjectDecisionTypeobjectTag>(nlohmann::json obj){
        return from_json_ApolloplanningObjectDecisionTypeobjectTag(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningObjectDecisionTypeobjectTag &dt)
    {
        dt=from_json_ApolloplanningObjectDecisionTypeobjectTag(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningObjectDecisionTypeobjectTag & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningObjectDecisionTypeobjectTag & dt)
    {
        os << to_json(dt);
        return os;
    }
}
