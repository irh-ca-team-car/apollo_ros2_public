#include "adapter/serialization/apollo_msgs/apollohdmap_parking_space.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapParkingSpace &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        obj["polygon"] = to_json(msg.polygon);
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        obj["heading"] = (msg.heading);
        return obj;
    }
    ApollohdmapParkingSpace from_json_ApollohdmapParkingSpace (nlohmann::json obj) {
        ApollohdmapParkingSpace msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("polygon"))
        {
            msg.polygon = from_json_ApollohdmapPolygon(obj["polygon"]);
        }
        if(obj.contains("overlapid"))
        {
            if(obj["overlapid"].is_array())
            {
                for (auto& element : obj["overlapid"])
                {
                    msg.overlapid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.overlapid.push_back(from_json_ApollohdmapId(obj["overlapid"]));
            }
        }
        if(obj.contains("heading"))
        {
            msg.heading = (obj["heading"].is_string()?atof(obj["heading"].get<std::string>().c_str()):obj["heading"].get<double>());
        }
        return msg;
    }
    template <>
    ApollohdmapParkingSpace from_json<ApollohdmapParkingSpace>(nlohmann::json obj){
        return from_json_ApollohdmapParkingSpace(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapParkingSpace &dt)
    {
        dt=from_json_ApollohdmapParkingSpace(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapParkingSpace & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapParkingSpace & dt)
    {
        os << to_json(dt);
        return os;
    }
}
