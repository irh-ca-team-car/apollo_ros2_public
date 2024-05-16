#include "adapter/serialization/apollo_msgs/apollodrivers_racobit_radar.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversRacobitRadar &msg) {
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
    ApollodriversRacobitRadar from_json_ApollodriversRacobitRadar (nlohmann::json obj) {
        ApollodriversRacobitRadar msg;
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
                    msg.contiobs.push_back(from_json_ApollodriversRacobitRadarObs(element));
                }
            }
            else
            {
                msg.contiobs.push_back(from_json_ApollodriversRacobitRadarObs(obj["contiobs"]));
            }
        }
        if(obj.contains("radarstate"))
        {
            msg.radarstate = from_json_ApollodriversRacobitRadarState201(obj["radarstate"]);
        }
        if(obj.contains("clusterliststatus"))
        {
            msg.clusterliststatus = from_json_ApollodriversRacobitClusterListStatus600(obj["clusterliststatus"]);
        }
        if(obj.contains("objectliststatus"))
        {
            msg.objectliststatus = from_json_ApollodriversRacobitObjectListStatus60A(obj["objectliststatus"]);
        }
        return msg;
    }
    template <>
    ApollodriversRacobitRadar from_json<ApollodriversRacobitRadar>(nlohmann::json obj){
        return from_json_ApollodriversRacobitRadar(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversRacobitRadar &dt)
    {
        dt=from_json_ApollodriversRacobitRadar(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversRacobitRadar & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversRacobitRadar & dt)
    {
        os << to_json(dt);
        return os;
    }
}
