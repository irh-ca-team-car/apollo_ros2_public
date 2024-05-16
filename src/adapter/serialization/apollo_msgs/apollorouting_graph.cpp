#include "adapter/serialization/apollo_msgs/apollorouting_graph.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingGraph &msg) {
        nlohmann::json obj;
        obj["hdmapversion"] = (msg.hdmapversion);
        obj["hdmapdistrict"] = (msg.hdmapdistrict);
        nlohmann::json arr_node;
        for (auto it = msg.node.begin(); it != msg.node.end(); ++it) {
            arr_node.push_back(to_json(*it));
        }
        obj["node"] = arr_node;
        nlohmann::json arr_edge;
        for (auto it = msg.edge.begin(); it != msg.edge.end(); ++it) {
            arr_edge.push_back(to_json(*it));
        }
        obj["edge"] = arr_edge;
        return obj;
    }
    ApolloroutingGraph from_json_ApolloroutingGraph (nlohmann::json obj) {
        ApolloroutingGraph msg;
        if(obj.contains("hdmapversion"))
        {
            msg.hdmapversion = (obj["hdmapversion"].is_string()?(obj["hdmapversion"].get<std::string>().c_str()):obj["hdmapversion"].get<std::string>());
        }
        if(obj.contains("hdmapdistrict"))
        {
            msg.hdmapdistrict = (obj["hdmapdistrict"].is_string()?(obj["hdmapdistrict"].get<std::string>().c_str()):obj["hdmapdistrict"].get<std::string>());
        }
        if(obj.contains("node"))
        {
            if(obj["node"].is_array())
            {
                for (auto& element : obj["node"])
                {
                    msg.node.push_back(from_json_ApolloroutingNode(element));
                }
            }
            else
            {
                msg.node.push_back(from_json_ApolloroutingNode(obj["node"]));
            }
        }
        if(obj.contains("edge"))
        {
            if(obj["edge"].is_array())
            {
                for (auto& element : obj["edge"])
                {
                    msg.edge.push_back(from_json_ApolloroutingEdge(element));
                }
            }
            else
            {
                msg.edge.push_back(from_json_ApolloroutingEdge(obj["edge"]));
            }
        }
        return msg;
    }
    template <>
    ApolloroutingGraph from_json<ApolloroutingGraph>(nlohmann::json obj){
        return from_json_ApolloroutingGraph(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingGraph &dt)
    {
        dt=from_json_ApolloroutingGraph(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingGraph & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingGraph & dt)
    {
        os << to_json(dt);
        return os;
    }
}
