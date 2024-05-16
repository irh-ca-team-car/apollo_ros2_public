#include "adapter/serialization/apollo_msgs/apollodbmap_db_path.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodbmapDBPath &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        nlohmann::json arr_path;
        for (auto it = msg.path.begin(); it != msg.path.end(); ++it) {
            arr_path.push_back(to_json(*it));
        }
        obj["path"] = arr_path;
        nlohmann::json arr_leftbounday;
        for (auto it = msg.leftbounday.begin(); it != msg.leftbounday.end(); ++it) {
            arr_leftbounday.push_back(to_json(*it));
        }
        obj["leftbounday"] = arr_leftbounday;
        nlohmann::json arr_rightbounday;
        for (auto it = msg.rightbounday.begin(); it != msg.rightbounday.end(); ++it) {
            arr_rightbounday.push_back(to_json(*it));
        }
        obj["rightbounday"] = arr_rightbounday;
        nlohmann::json arr_leftpath;
        for (auto it = msg.leftpath.begin(); it != msg.leftpath.end(); ++it) {
            arr_leftpath.push_back(to_json(*it));
        }
        obj["leftpath"] = arr_leftpath;
        nlohmann::json arr_rightpath;
        for (auto it = msg.rightpath.begin(); it != msg.rightpath.end(); ++it) {
            arr_rightpath.push_back(to_json(*it));
        }
        obj["rightpath"] = arr_rightpath;
        nlohmann::json arr_duplicatepath;
        for (auto it = msg.duplicatepath.begin(); it != msg.duplicatepath.end(); ++it) {
            arr_duplicatepath.push_back(to_json(*it));
        }
        obj["duplicatepath"] = arr_duplicatepath;
        return obj;
    }
    ApollodbmapDBPath from_json_ApollodbmapDBPath (nlohmann::json obj) {
        ApollodbmapDBPath msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("path"))
        {
            if(obj["path"].is_array())
            {
                for (auto& element : obj["path"])
                {
                    msg.path.push_back(from_json_ApollodbmapDBLine(element));
                }
            }
            else
            {
                msg.path.push_back(from_json_ApollodbmapDBLine(obj["path"]));
            }
        }
        if(obj.contains("leftbounday"))
        {
            if(obj["leftbounday"].is_array())
            {
                for (auto& element : obj["leftbounday"])
                {
                    msg.leftbounday.push_back(from_json_ApollodbmapDBLine(element));
                }
            }
            else
            {
                msg.leftbounday.push_back(from_json_ApollodbmapDBLine(obj["leftbounday"]));
            }
        }
        if(obj.contains("rightbounday"))
        {
            if(obj["rightbounday"].is_array())
            {
                for (auto& element : obj["rightbounday"])
                {
                    msg.rightbounday.push_back(from_json_ApollodbmapDBLine(element));
                }
            }
            else
            {
                msg.rightbounday.push_back(from_json_ApollodbmapDBLine(obj["rightbounday"]));
            }
        }
        if(obj.contains("leftpath"))
        {
            if(obj["leftpath"].is_array())
            {
                for (auto& element : obj["leftpath"])
                {
                    msg.leftpath.push_back(from_json_ApollodbmapDBNeighbourPath(element));
                }
            }
            else
            {
                msg.leftpath.push_back(from_json_ApollodbmapDBNeighbourPath(obj["leftpath"]));
            }
        }
        if(obj.contains("rightpath"))
        {
            if(obj["rightpath"].is_array())
            {
                for (auto& element : obj["rightpath"])
                {
                    msg.rightpath.push_back(from_json_ApollodbmapDBNeighbourPath(element));
                }
            }
            else
            {
                msg.rightpath.push_back(from_json_ApollodbmapDBNeighbourPath(obj["rightpath"]));
            }
        }
        if(obj.contains("duplicatepath"))
        {
            if(obj["duplicatepath"].is_array())
            {
                for (auto& element : obj["duplicatepath"])
                {
                    msg.duplicatepath.push_back(from_json_ApollodbmapDBNeighbourPath(element));
                }
            }
            else
            {
                msg.duplicatepath.push_back(from_json_ApollodbmapDBNeighbourPath(obj["duplicatepath"]));
            }
        }
        return msg;
    }
    template <>
    ApollodbmapDBPath from_json<ApollodbmapDBPath>(nlohmann::json obj){
        return from_json_ApollodbmapDBPath(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodbmapDBPath &dt)
    {
        dt=from_json_ApollodbmapDBPath(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodbmapDBPath & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodbmapDBPath & dt)
    {
        os << to_json(dt);
        return os;
    }
}
