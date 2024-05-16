#include "adapter/serialization/apollo_msgs/apollorouting_parking_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingParkingInfo &msg) {
        nlohmann::json obj;
        obj["parkingspaceid"] = (msg.parkingspaceid);
        obj["parkingpoint"] = to_json(msg.parkingpoint);
        return obj;
    }
    ApolloroutingParkingInfo from_json_ApolloroutingParkingInfo (nlohmann::json obj) {
        ApolloroutingParkingInfo msg;
        if(obj.contains("parkingspaceid"))
        {
            msg.parkingspaceid = (obj["parkingspaceid"].is_string()?(obj["parkingspaceid"].get<std::string>().c_str()):obj["parkingspaceid"].get<std::string>());
        }
        if(obj.contains("parkingpoint"))
        {
            msg.parkingpoint = from_json_ApollocommonPointENU(obj["parkingpoint"]);
        }
        return msg;
    }
    template <>
    ApolloroutingParkingInfo from_json<ApolloroutingParkingInfo>(nlohmann::json obj){
        return from_json_ApolloroutingParkingInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingParkingInfo &dt)
    {
        dt=from_json_ApolloroutingParkingInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingParkingInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingParkingInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
