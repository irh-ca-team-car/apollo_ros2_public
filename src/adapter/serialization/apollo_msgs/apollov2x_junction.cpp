#include "adapter/serialization/apollo_msgs/apollov2x_junction.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xJunction &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        obj["polygon"] = to_json(msg.polygon);
        nlohmann::json arr_crosswalkid;
        for (auto it = msg.crosswalkid.begin(); it != msg.crosswalkid.end(); ++it) {
            arr_crosswalkid.push_back(to_json(*it));
        }
        obj["crosswalkid"] = arr_crosswalkid;
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        obj["numroadsegments"] = (msg.numroadsegments);
        nlohmann::json arr_laneid;
        for (auto it = msg.laneid.begin(); it != msg.laneid.end(); ++it) {
            arr_laneid.push_back(to_json(*it));
        }
        obj["laneid"] = arr_laneid;
        obj["type"] = (msg.type);
        nlohmann::json arr_edgetype;
        for (auto it = msg.edgetype.begin(); it != msg.edgetype.end(); ++it) {
            arr_edgetype.push_back((*it));
        }
        obj["edgetype"] = arr_edgetype;
        return obj;
    }
    Apollov2xJunction from_json_Apollov2xJunction (nlohmann::json obj) {
        Apollov2xJunction msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_Apollov2xId(obj["id"]);
        }
        if(obj.contains("polygon"))
        {
            msg.polygon = from_json_ApollocommonPolygon(obj["polygon"]);
        }
        if(obj.contains("crosswalkid"))
        {
            if(obj["crosswalkid"].is_array())
            {
                for (auto& element : obj["crosswalkid"])
                {
                    msg.crosswalkid.push_back(from_json_Apollov2xId(element));
                }
            }
            else
            {
                msg.crosswalkid.push_back(from_json_Apollov2xId(obj["crosswalkid"]));
            }
        }
        if(obj.contains("overlapid"))
        {
            if(obj["overlapid"].is_array())
            {
                for (auto& element : obj["overlapid"])
                {
                    msg.overlapid.push_back(from_json_Apollov2xId(element));
                }
            }
            else
            {
                msg.overlapid.push_back(from_json_Apollov2xId(obj["overlapid"]));
            }
        }
        if(obj.contains("numroadsegments"))
        {
            msg.numroadsegments = (obj["numroadsegments"].is_string()?atoi(obj["numroadsegments"].get<std::string>().c_str()):obj["numroadsegments"].get<int>());
        }
        if(obj.contains("laneid"))
        {
            if(obj["laneid"].is_array())
            {
                for (auto& element : obj["laneid"])
                {
                    msg.laneid.push_back(from_json_Apollov2xId(element));
                }
            }
            else
            {
                msg.laneid.push_back(from_json_Apollov2xId(obj["laneid"]));
            }
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("edgetype"))
        {
            if(obj["edgetype"].is_array())
            {
                for (auto& element : obj["edgetype"])
                {
                    msg.edgetype.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.edgetype.push_back((obj["edgetype"].is_string()?atoi(obj["edgetype"].get<std::string>().c_str()):obj["edgetype"].get<int>()));
            }
        }
        return msg;
    }
    template <>
    Apollov2xJunction from_json<Apollov2xJunction>(nlohmann::json obj){
        return from_json_Apollov2xJunction(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xJunction &dt)
    {
        dt=from_json_Apollov2xJunction(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xJunction & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xJunction & dt)
    {
        os << to_json(dt);
        return os;
    }
}
