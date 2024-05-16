#include "adapter/serialization/apollo_msgs/apollodrivers_conti_radar.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversContiRadar &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_contiobs;
        for (auto it = msg.contiobs.begin(); it != msg.contiobs.end(); ++it) {
            arr_contiobs.push_back(to_json(*it));
        }
        obj["contiobs"] = arr_contiobs;
        obj["radarstate"] = to_json(msg.radarstate);
        obj["clusterliststatus"] = to_json(msg.clusterliststatus);
        obj["objectliststatus"] = to_json(msg.objectliststatus);
        return obj;
    }
    ApollodriversContiRadar from_json_ApollodriversContiRadar (nlohmann::json obj) {
        ApollodriversContiRadar msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("contiobs"))
        {
            if(obj["contiobs"].is_array())
            {
                for (auto& element : obj["contiobs"])
                {
                    msg.contiobs.push_back(from_json_ApollodriversContiRadarObs(element));
                }
            }
            else
            {
                msg.contiobs.push_back(from_json_ApollodriversContiRadarObs(obj["contiobs"]));
            }
        }
        if(obj.contains("radarstate"))
        {
            msg.radarstate = from_json_ApollodriversRadarState201(obj["radarstate"]);
        }
        if(obj.contains("clusterliststatus"))
        {
            msg.clusterliststatus = from_json_ApollodriversClusterListStatus600(obj["clusterliststatus"]);
        }
        if(obj.contains("objectliststatus"))
        {
            msg.objectliststatus = from_json_ApollodriversObjectListStatus60A(obj["objectliststatus"]);
        }
        return msg;
    }
    template <>
    ApollodriversContiRadar from_json<ApollodriversContiRadar>(nlohmann::json obj){
        return from_json_ApollodriversContiRadar(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversContiRadar &dt)
    {
        dt=from_json_ApollodriversContiRadar(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversContiRadar & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversContiRadar & dt)
    {
        os << to_json(dt);
        return os;
    }
}
