#include "adapter/serialization/apollo_msgs/apolloplanning_internal_obstacle_debug.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalObstacleDebug &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["slboundary"] = to_json(msg.slboundary);
        nlohmann::json arr_decisiontag;
        for (auto it = msg.decisiontag.begin(); it != msg.decisiontag.end(); ++it) {
            arr_decisiontag.push_back(to_json(*it));
        }
        obj["decisiontag"] = arr_decisiontag;
        nlohmann::json arr_verticesxcoords;
        for (auto it = msg.verticesxcoords.begin(); it != msg.verticesxcoords.end(); ++it) {
            arr_verticesxcoords.push_back((*it));
        }
        obj["verticesxcoords"] = arr_verticesxcoords;
        nlohmann::json arr_verticesycoords;
        for (auto it = msg.verticesycoords.begin(); it != msg.verticesycoords.end(); ++it) {
            arr_verticesycoords.push_back((*it));
        }
        obj["verticesycoords"] = arr_verticesycoords;
        return obj;
    }
    ApolloplanningInternalObstacleDebug from_json_ApolloplanningInternalObstacleDebug (nlohmann::json obj) {
        ApolloplanningInternalObstacleDebug msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("slboundary"))
        {
            msg.slboundary = from_json_ApolloplanningSLBoundary(obj["slboundary"]);
        }
        if(obj.contains("decisiontag"))
        {
            if(obj["decisiontag"].is_array())
            {
                for (auto& element : obj["decisiontag"])
                {
                    msg.decisiontag.push_back(from_json_ApolloplanningInternalDecisionTag(element));
                }
            }
            else
            {
                msg.decisiontag.push_back(from_json_ApolloplanningInternalDecisionTag(obj["decisiontag"]));
            }
        }
        if(obj.contains("verticesxcoords"))
        {
            if(obj["verticesxcoords"].is_array())
            {
                for (auto& element : obj["verticesxcoords"])
                {
                    msg.verticesxcoords.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.verticesxcoords.push_back((obj["verticesxcoords"].is_string()?atof(obj["verticesxcoords"].get<std::string>().c_str()):obj["verticesxcoords"].get<double>()));
            }
        }
        if(obj.contains("verticesycoords"))
        {
            if(obj["verticesycoords"].is_array())
            {
                for (auto& element : obj["verticesycoords"])
                {
                    msg.verticesycoords.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.verticesycoords.push_back((obj["verticesycoords"].is_string()?atof(obj["verticesycoords"].get<std::string>().c_str()):obj["verticesycoords"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApolloplanningInternalObstacleDebug from_json<ApolloplanningInternalObstacleDebug>(nlohmann::json obj){
        return from_json_ApolloplanningInternalObstacleDebug(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalObstacleDebug &dt)
    {
        dt=from_json_ApolloplanningInternalObstacleDebug(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalObstacleDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalObstacleDebug & dt)
    {
        os << to_json(dt);
        return os;
    }
}
