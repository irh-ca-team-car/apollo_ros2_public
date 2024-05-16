#include "adapter/serialization/apollo_msgs/apollomonitor_component_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollomonitorComponentStatus &msg) {
        nlohmann::json obj;
        obj["status"] = (msg.status);
        obj["message"] = (msg.message);
        return obj;
    }
    ApollomonitorComponentStatus from_json_ApollomonitorComponentStatus (nlohmann::json obj) {
        ApollomonitorComponentStatus msg;
        if(obj.contains("status"))
        {
            msg.status = (obj["status"].is_string()?atoi(obj["status"].get<std::string>().c_str()):obj["status"].get<int>());
        }
        if(obj.contains("message"))
        {
            msg.message = (obj["message"].is_string()?(obj["message"].get<std::string>().c_str()):obj["message"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApollomonitorComponentStatus from_json<ApollomonitorComponentStatus>(nlohmann::json obj){
        return from_json_ApollomonitorComponentStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollomonitorComponentStatus &dt)
    {
        dt=from_json_ApollomonitorComponentStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollomonitorComponentStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollomonitorComponentStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
