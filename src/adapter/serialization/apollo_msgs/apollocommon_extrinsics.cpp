#include "adapter/serialization/apollo_msgs/apollocommon_extrinsics.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonExtrinsics &msg) {
        nlohmann::json obj;
        nlohmann::json arr_tansforms;
        for (auto it = msg.tansforms.begin(); it != msg.tansforms.end(); ++it) {
            arr_tansforms.push_back(to_json(*it));
        }
        obj["tansforms"] = arr_tansforms;
        return obj;
    }
    ApollocommonExtrinsics from_json_ApollocommonExtrinsics (nlohmann::json obj) {
        ApollocommonExtrinsics msg;
        if(obj.contains("tansforms"))
        {
            if(obj["tansforms"].is_array())
            {
                for (auto& element : obj["tansforms"])
                {
                    msg.tansforms.push_back(from_json_ApollocommonTransform(element));
                }
            }
            else
            {
                msg.tansforms.push_back(from_json_ApollocommonTransform(obj["tansforms"]));
            }
        }
        return msg;
    }
    template <>
    ApollocommonExtrinsics from_json<ApollocommonExtrinsics>(nlohmann::json obj){
        return from_json_ApollocommonExtrinsics(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonExtrinsics &dt)
    {
        dt=from_json_ApollocommonExtrinsics(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonExtrinsics & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonExtrinsics & dt)
    {
        os << to_json(dt);
        return os;
    }
}
