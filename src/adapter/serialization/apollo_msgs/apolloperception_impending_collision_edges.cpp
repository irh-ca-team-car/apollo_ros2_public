#include "adapter/serialization/apollo_msgs/apolloperception_impending_collision_edges.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionImpendingCollisionEdges &msg) {
        nlohmann::json obj;
        nlohmann::json arr_impendingcollisionedge;
        for (auto it = msg.impendingcollisionedge.begin(); it != msg.impendingcollisionedge.end(); ++it) {
            arr_impendingcollisionedge.push_back(to_json(*it));
        }
        obj["impendingcollisionedge"] = arr_impendingcollisionedge;
        obj["apolloheader"] = to_json(msg.apolloheader);
        return obj;
    }
    ApolloperceptionImpendingCollisionEdges from_json_ApolloperceptionImpendingCollisionEdges (nlohmann::json obj) {
        ApolloperceptionImpendingCollisionEdges msg;
        if(obj.contains("impendingcollisionedge"))
        {
            if(obj["impendingcollisionedge"].is_array())
            {
                for (auto& element : obj["impendingcollisionedge"])
                {
                    msg.impendingcollisionedge.push_back(from_json_ApolloperceptionImpendingCollisionEdge(element));
                }
            }
            else
            {
                msg.impendingcollisionedge.push_back(from_json_ApolloperceptionImpendingCollisionEdge(obj["impendingcollisionedge"]));
            }
        }
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        return msg;
    }
    template <>
    ApolloperceptionImpendingCollisionEdges from_json<ApolloperceptionImpendingCollisionEdges>(nlohmann::json obj){
        return from_json_ApolloperceptionImpendingCollisionEdges(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionImpendingCollisionEdges &dt)
    {
        dt=from_json_ApolloperceptionImpendingCollisionEdges(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionImpendingCollisionEdges & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionImpendingCollisionEdges & dt)
    {
        os << to_json(dt);
        return os;
    }
}
