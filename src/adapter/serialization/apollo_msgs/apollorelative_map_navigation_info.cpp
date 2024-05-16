#include "adapter/serialization/apollo_msgs/apollorelative_map_navigation_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapNavigationInfo &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_navigationpath;
        for (auto it = msg.navigationpath.begin(); it != msg.navigationpath.end(); ++it) {
            arr_navigationpath.push_back(to_json(*it));
        }
        obj["navigationpath"] = arr_navigationpath;
        return obj;
    }
    ApollorelativeMapNavigationInfo from_json_ApollorelativeMapNavigationInfo (nlohmann::json obj) {
        ApollorelativeMapNavigationInfo msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("navigationpath"))
        {
            if(obj["navigationpath"].is_array())
            {
                for (auto& element : obj["navigationpath"])
                {
                    msg.navigationpath.push_back(from_json_ApollorelativeMapNavigationPath(element));
                }
            }
            else
            {
                msg.navigationpath.push_back(from_json_ApollorelativeMapNavigationPath(obj["navigationpath"]));
            }
        }
        return msg;
    }
    template <>
    ApollorelativeMapNavigationInfo from_json<ApollorelativeMapNavigationInfo>(nlohmann::json obj){
        return from_json_ApollorelativeMapNavigationInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapNavigationInfo &dt)
    {
        dt=from_json_ApollorelativeMapNavigationInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapNavigationInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapNavigationInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
