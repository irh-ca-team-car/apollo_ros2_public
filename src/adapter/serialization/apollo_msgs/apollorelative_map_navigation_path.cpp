#include "adapter/serialization/apollo_msgs/apollorelative_map_navigation_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapNavigationPath &msg) {
        nlohmann::json obj;
        obj["path"] = to_json(msg.path);
        obj["pathpriority"] = (msg.pathpriority);
        return obj;
    }
    ApollorelativeMapNavigationPath from_json_ApollorelativeMapNavigationPath (nlohmann::json obj) {
        ApollorelativeMapNavigationPath msg;
        if(obj.contains("path"))
        {
            msg.path = from_json_ApollocommonPath(obj["path"]);
        }
        if(obj.contains("pathpriority"))
        {
            msg.pathpriority = (obj["pathpriority"].is_string()?atoi(obj["pathpriority"].get<std::string>().c_str()):obj["pathpriority"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollorelativeMapNavigationPath from_json<ApollorelativeMapNavigationPath>(nlohmann::json obj){
        return from_json_ApollorelativeMapNavigationPath(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapNavigationPath &dt)
    {
        dt=from_json_ApollorelativeMapNavigationPath(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapNavigationPath & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapNavigationPath & dt)
    {
        os << to_json(dt);
        return os;
    }
}
