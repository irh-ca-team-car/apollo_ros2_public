#include "adapter/serialization/apollo_msgs/apollohdmap_loops_verify_response.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLoopsVerifyResponse &msg) {
        nlohmann::json obj;
        obj["code"] = (msg.code);
        obj["progress"] = (msg.progress);
        obj["loopresult"] = to_json(msg.loopresult);
        return obj;
    }
    ApollohdmapLoopsVerifyResponse from_json_ApollohdmapLoopsVerifyResponse (nlohmann::json obj) {
        ApollohdmapLoopsVerifyResponse msg;
        if(obj.contains("code"))
        {
            msg.code = (obj["code"].is_string()?atoi(obj["code"].get<std::string>().c_str()):obj["code"].get<int>());
        }
        if(obj.contains("progress"))
        {
            msg.progress = (obj["progress"].is_string()?atof(obj["progress"].get<std::string>().c_str()):obj["progress"].get<double>());
        }
        if(obj.contains("loopresult"))
        {
            msg.loopresult = from_json_ApollohdmapLoopResult(obj["loopresult"]);
        }
        return msg;
    }
    template <>
    ApollohdmapLoopsVerifyResponse from_json<ApollohdmapLoopsVerifyResponse>(nlohmann::json obj){
        return from_json_ApollohdmapLoopsVerifyResponse(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLoopsVerifyResponse &dt)
    {
        dt=from_json_ApollohdmapLoopsVerifyResponse(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLoopsVerifyResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLoopsVerifyResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
}
