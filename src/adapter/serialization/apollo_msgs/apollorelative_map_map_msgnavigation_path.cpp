#include "adapter/serialization/apollo_msgs/apollorelative_map_map_msgnavigation_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapMapMsgnavigationPath &msg) {
        nlohmann::json obj;
        obj["key"] = (msg.key);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollorelativeMapMapMsgnavigationPath from_json_ApollorelativeMapMapMsgnavigationPath (nlohmann::json obj) {
        ApollorelativeMapMapMsgnavigationPath msg;
        if(obj.contains("key"))
        {
            msg.key = (obj["key"].is_string()?(obj["key"].get<std::string>().c_str()):obj["key"].get<std::string>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_ApollorelativeMapNavigationPath(obj["data"]);
        }
        return msg;
    }
    template <>
    ApollorelativeMapMapMsgnavigationPath from_json<ApollorelativeMapMapMsgnavigationPath>(nlohmann::json obj){
        return from_json_ApollorelativeMapMapMsgnavigationPath(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapMapMsgnavigationPath &dt)
    {
        dt=from_json_ApollorelativeMapMapMsgnavigationPath(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapMapMsgnavigationPath & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapMapMsgnavigationPath & dt)
    {
        os << to_json(dt);
        return os;
    }
}
