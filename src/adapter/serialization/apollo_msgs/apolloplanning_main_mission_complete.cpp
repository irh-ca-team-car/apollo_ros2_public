#include "adapter/serialization/apollo_msgs/apolloplanning_main_mission_complete.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningMainMissionComplete &msg) {
        nlohmann::json obj;
        obj["stoppoint"] = to_json(msg.stoppoint);
        obj["stopheading"] = (msg.stopheading);
        return obj;
    }
    ApolloplanningMainMissionComplete from_json_ApolloplanningMainMissionComplete (nlohmann::json obj) {
        ApolloplanningMainMissionComplete msg;
        if(obj.contains("stoppoint"))
        {
            msg.stoppoint = from_json_ApollocommonPointENU(obj["stoppoint"]);
        }
        if(obj.contains("stopheading"))
        {
            msg.stopheading = (obj["stopheading"].is_string()?atof(obj["stopheading"].get<std::string>().c_str()):obj["stopheading"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningMainMissionComplete from_json<ApolloplanningMainMissionComplete>(nlohmann::json obj){
        return from_json_ApolloplanningMainMissionComplete(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningMainMissionComplete &dt)
    {
        dt=from_json_ApolloplanningMainMissionComplete(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningMainMissionComplete & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningMainMissionComplete & dt)
    {
        os << to_json(dt);
        return os;
    }
}
