#include "adapter/serialization/apollo_msgs/apollorelative_map_map_msg.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapMapMsg &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["hdmap"] = to_json(msg.hdmap);
        nlohmann::json arr_navigationpath;
        for (auto it = msg.navigationpath.begin(); it != msg.navigationpath.end(); ++it) {
            arr_navigationpath.push_back(to_json(*it));
        }
        obj["navigationpath"] = arr_navigationpath;
        obj["lanemarker"] = to_json(msg.lanemarker);
        obj["localization"] = to_json(msg.localization);
        return obj;
    }
    ApollorelativeMapMapMsg from_json_ApollorelativeMapMapMsg (nlohmann::json obj) {
        ApollorelativeMapMapMsg msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("hdmap"))
        {
            msg.hdmap = from_json_ApollohdmapMap(obj["hdmap"]);
        }
        if(obj.contains("navigationpath"))
        {
            if(obj["navigationpath"].is_array())
            {
                for (auto& element : obj["navigationpath"])
                {
                    msg.navigationpath.push_back(from_json_ApollorelativeMapMapMsgnavigationPath(element));
                }
            }
            else
            {
                msg.navigationpath.push_back(from_json_ApollorelativeMapMapMsgnavigationPath(obj["navigationpath"]));
            }
        }
        if(obj.contains("lanemarker"))
        {
            msg.lanemarker = from_json_ApolloperceptionLaneMarkers(obj["lanemarker"]);
        }
        if(obj.contains("localization"))
        {
            msg.localization = from_json_ApollolocalizationLocalizationEstimate(obj["localization"]);
        }
        return msg;
    }
    template <>
    ApollorelativeMapMapMsg from_json<ApollorelativeMapMapMsg>(nlohmann::json obj){
        return from_json_ApollorelativeMapMapMsg(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapMapMsg &dt)
    {
        dt=from_json_ApollorelativeMapMapMsg(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapMapMsg & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapMapMsg & dt)
    {
        os << to_json(dt);
        return os;
    }
}
