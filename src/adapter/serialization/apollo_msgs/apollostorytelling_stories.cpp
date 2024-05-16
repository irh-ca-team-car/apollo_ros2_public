#include "adapter/serialization/apollo_msgs/apollostorytelling_stories.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostorytellingStories &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["closetocleararea"] = to_json(msg.closetocleararea);
        obj["closetocrosswalk"] = to_json(msg.closetocrosswalk);
        obj["closetojunction"] = to_json(msg.closetojunction);
        obj["closetosignal"] = to_json(msg.closetosignal);
        obj["closetostopsign"] = to_json(msg.closetostopsign);
        obj["closetoyieldsign"] = to_json(msg.closetoyieldsign);
        return obj;
    }
    ApollostorytellingStories from_json_ApollostorytellingStories (nlohmann::json obj) {
        ApollostorytellingStories msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("closetocleararea"))
        {
            msg.closetocleararea = from_json_ApollostorytellingCloseToClearArea(obj["closetocleararea"]);
        }
        if(obj.contains("closetocrosswalk"))
        {
            msg.closetocrosswalk = from_json_ApollostorytellingCloseToCrosswalk(obj["closetocrosswalk"]);
        }
        if(obj.contains("closetojunction"))
        {
            msg.closetojunction = from_json_ApollostorytellingCloseToJunction(obj["closetojunction"]);
        }
        if(obj.contains("closetosignal"))
        {
            msg.closetosignal = from_json_ApollostorytellingCloseToSignal(obj["closetosignal"]);
        }
        if(obj.contains("closetostopsign"))
        {
            msg.closetostopsign = from_json_ApollostorytellingCloseToStopSign(obj["closetostopsign"]);
        }
        if(obj.contains("closetoyieldsign"))
        {
            msg.closetoyieldsign = from_json_ApollostorytellingCloseToYieldSign(obj["closetoyieldsign"]);
        }
        return msg;
    }
    template <>
    ApollostorytellingStories from_json<ApollostorytellingStories>(nlohmann::json obj){
        return from_json_ApollostorytellingStories(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostorytellingStories &dt)
    {
        dt=from_json_ApollostorytellingStories(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostorytellingStories & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostorytellingStories & dt)
    {
        os << to_json(dt);
        return os;
    }
}
