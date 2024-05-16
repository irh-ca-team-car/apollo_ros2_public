#include "adapter/serialization/apollo_msgs/apolloperception_impending_collision_edge.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionImpendingCollisionEdge &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        nlohmann::json arr_coneidlist;
        for (auto it = msg.coneidlist.begin(); it != msg.coneidlist.end(); ++it) {
            arr_coneidlist.push_back((*it));
        }
        obj["coneidlist"] = arr_coneidlist;
        nlohmann::json arr_point;
        for (auto it = msg.point.begin(); it != msg.point.end(); ++it) {
            arr_point.push_back(to_json(*it));
        }
        obj["point"] = arr_point;
        obj["trackingtime"] = (msg.trackingtime);
        return obj;
    }
    ApolloperceptionImpendingCollisionEdge from_json_ApolloperceptionImpendingCollisionEdge (nlohmann::json obj) {
        ApolloperceptionImpendingCollisionEdge msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("coneidlist"))
        {
            if(obj["coneidlist"].is_array())
            {
                for (auto& element : obj["coneidlist"])
                {
                    msg.coneidlist.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.coneidlist.push_back((obj["coneidlist"].is_string()?atoi(obj["coneidlist"].get<std::string>().c_str()):obj["coneidlist"].get<int>()));
            }
        }
        if(obj.contains("point"))
        {
            if(obj["point"].is_array())
            {
                for (auto& element : obj["point"])
                {
                    msg.point.push_back(from_json_ApollocommonPoint3D(element));
                }
            }
            else
            {
                msg.point.push_back(from_json_ApollocommonPoint3D(obj["point"]));
            }
        }
        if(obj.contains("trackingtime"))
        {
            msg.trackingtime = (obj["trackingtime"].is_string()?atof(obj["trackingtime"].get<std::string>().c_str()):obj["trackingtime"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloperceptionImpendingCollisionEdge from_json<ApolloperceptionImpendingCollisionEdge>(nlohmann::json obj){
        return from_json_ApolloperceptionImpendingCollisionEdge(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionImpendingCollisionEdge &dt)
    {
        dt=from_json_ApolloperceptionImpendingCollisionEdge(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionImpendingCollisionEdge & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionImpendingCollisionEdge & dt)
    {
        os << to_json(dt);
        return os;
    }
}
