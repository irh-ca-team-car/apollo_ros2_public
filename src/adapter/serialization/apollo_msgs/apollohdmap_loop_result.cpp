#include "adapter/serialization/apollo_msgs/apollohdmap_loop_result.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLoopResult &msg) {
        nlohmann::json obj;
        obj["isreached"] = (msg.isreached);
        obj["loopnum"] = (msg.loopnum);
        return obj;
    }
    ApollohdmapLoopResult from_json_ApollohdmapLoopResult (nlohmann::json obj) {
        ApollohdmapLoopResult msg;
        if(obj.contains("isreached"))
        {
            msg.isreached = (obj["isreached"].is_string()?(bool)atoi(obj["isreached"].get<std::string>().c_str()):obj["isreached"].get<bool>());
        }
        if(obj.contains("loopnum"))
        {
            msg.loopnum = (obj["loopnum"].is_string()?atof(obj["loopnum"].get<std::string>().c_str()):obj["loopnum"].get<double>());
        }
        return msg;
    }
    template <>
    ApollohdmapLoopResult from_json<ApollohdmapLoopResult>(nlohmann::json obj){
        return from_json_ApollohdmapLoopResult(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLoopResult &dt)
    {
        dt=from_json_ApollohdmapLoopResult(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLoopResult & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLoopResult & dt)
    {
        os << to_json(dt);
        return os;
    }
}
