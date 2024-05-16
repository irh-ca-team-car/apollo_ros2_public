#include "modules/perception/onboard/internal_messages/impending_collision_edge.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::ImpendingCollisionEdge;
    nlohmann::json to_json(const ImpendingCollisionEdge &msg)
    {
        nlohmann::json j;
        
        j["id"] = msg.id;
        j["tracking_time"] = msg.tracking_time;
        nlohmann::json arr_points;
        for (size_t i = 0; i < msg.points.size(); i++){
            for (int j = 0; j < 3; j++) {
                arr_points[i].push_back(msg.points[i](j));
            } 
        } 
        j["points"] = arr_points;

        return j;
    }
    ImpendingCollisionEdge from_json_ImpendingCollisionEdge(nlohmann::json obj)
    {
        ImpendingCollisionEdge d;
        
        if (obj.contains("id"))
            d.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        if (obj.contains("tracking_time"))
            d.tracking_time = (obj["tracking_time"].is_string()?atof(obj["tracking_time"].get<std::string>().c_str()):obj["tracking_time"].get<double>());
        if(obj.contains("points")) 
            for (auto element : obj["points"]){
                Eigen::Vector3d inter;
                for (int i = 0; i < 3; i++) {
                    inter(i) = (element[i].is_string()?atof(element[i].get<std::string>().c_str()):element[i].get<double>());
                }
                d.points.push_back(inter);
            }
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, ImpendingCollisionEdge &dt)
    {
        dt = from_json_ImpendingCollisionEdge(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const ImpendingCollisionEdge &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const ImpendingCollisionEdge &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::ImpendingCollisionEdges;
    nlohmann::json to_json(const ImpendingCollisionEdges &msg)
    {
        nlohmann::json j;
        
        j["timestamp"] = msg.timestamp;
        nlohmann::json arr_impending_collision_edges;
        for (auto it= msg.impending_collision_edges.begin(); it != msg.impending_collision_edges.end(); ++it){
            if (*it != nullptr)
                arr_impending_collision_edges.push_back(to_json(**it));
            else
                arr_impending_collision_edges.push_back(nullptr); 
        } 
        j["impending_collision_edges"] = arr_impending_collision_edges;
        nlohmann::json arr_sensor2world_pose;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                arr_sensor2world_pose.push_back(msg.sensor2world_pose(i,j));
            }
        }
        j["sensor2world_pose"] = arr_sensor2world_pose;

        return j;
    }
    ImpendingCollisionEdges from_json_ImpendingCollisionEdges(nlohmann::json obj)
    {
        ImpendingCollisionEdges d;
        
        if (obj.contains("timestamp"))
            d.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        if(obj.contains("impending_collision_edges")) 
            for (auto element : obj["impending_collision_edges"]){
                if (element.is_null())
                    d.impending_collision_edges.push_back(nullptr);
                else{
                    std::shared_ptr<ImpendingCollisionEdge> inter;
                    *inter = from_json_ImpendingCollisionEdge(element);
                    d.impending_collision_edges.push_back(inter);}
            }
        if (obj.contains("sensor2world_pose"))
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    d.sensor2world_pose(i,j) = (obj["sensor2world_pose"][i*4+j].is_string()?atof(obj["sensor2world_pose"][i*4+j].get<std::string>().c_str()):obj["sensor2world_pose"][i*4+j].get<double>());
                }
            }
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, ImpendingCollisionEdges &dt)
    {
        dt = from_json_ImpendingCollisionEdges(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const ImpendingCollisionEdges &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const ImpendingCollisionEdges &dt)
    {
        return os << to_json(dt).dump();
    }
}
