#include "adapter/serialization/apollo_msgs/apollohdmap_verify_range.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapVerifyRange &msg) {
        nlohmann::json obj;
        obj["starttime"] = (msg.starttime);
        obj["endtime"] = (msg.endtime);
        return obj;
    }
    ApollohdmapVerifyRange from_json_ApollohdmapVerifyRange (nlohmann::json obj) {
        ApollohdmapVerifyRange msg;
        if(obj.contains("starttime"))
        {
            msg.starttime = (obj["starttime"].is_string()?atof(obj["starttime"].get<std::string>().c_str()):obj["starttime"].get<double>());
        }
        if(obj.contains("endtime"))
        {
            msg.endtime = (obj["endtime"].is_string()?atof(obj["endtime"].get<std::string>().c_str()):obj["endtime"].get<double>());
        }
        return msg;
    }
    template <>
    ApollohdmapVerifyRange from_json<ApollohdmapVerifyRange>(nlohmann::json obj){
        return from_json_ApollohdmapVerifyRange(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapVerifyRange &dt)
    {
        dt=from_json_ApollohdmapVerifyRange(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapVerifyRange & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapVerifyRange & dt)
    {
        os << to_json(dt);
        return os;
    }
}
