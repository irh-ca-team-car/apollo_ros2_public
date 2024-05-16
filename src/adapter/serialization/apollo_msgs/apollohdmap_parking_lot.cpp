#include "adapter/serialization/apollo_msgs/apollohdmap_parking_lot.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapParkingLot &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        obj["polygon"] = to_json(msg.polygon);
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        return obj;
    }
    ApollohdmapParkingLot from_json_ApollohdmapParkingLot (nlohmann::json obj) {
        ApollohdmapParkingLot msg;
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
        return msg;
    }
    template <>
    ApollohdmapParkingLot from_json<ApollohdmapParkingLot>(nlohmann::json obj){
        return from_json_ApollohdmapParkingLot(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapParkingLot &dt)
    {
        dt=from_json_ApollohdmapParkingLot(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapParkingLot & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapParkingLot & dt)
    {
        os << to_json(dt);
        return os;
    }
}
