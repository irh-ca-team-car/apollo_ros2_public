#include "adapter/serialization/apollo_msgs/apollocommon_engage_advice.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonEngageAdvice &msg) {
        nlohmann::json obj;
        obj["advice"] = (msg.advice);
        obj["reason"] = (msg.reason);
        return obj;
    }
    ApollocommonEngageAdvice from_json_ApollocommonEngageAdvice (nlohmann::json obj) {
        ApollocommonEngageAdvice msg;
        if(obj.contains("advice"))
        {
            msg.advice = (obj["advice"].is_string()?atoi(obj["advice"].get<std::string>().c_str()):obj["advice"].get<int>());
        }
        if(obj.contains("reason"))
        {
            msg.reason = (obj["reason"].is_string()?(obj["reason"].get<std::string>().c_str()):obj["reason"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollocommonEngageAdvice from_json<ApollocommonEngageAdvice>(nlohmann::json obj){
        return from_json_ApollocommonEngageAdvice(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonEngageAdvice &dt)
    {
        dt=from_json_ApollocommonEngageAdvice(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonEngageAdvice & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonEngageAdvice & dt)
    {
        os << to_json(dt);
        return os;
    }
}
