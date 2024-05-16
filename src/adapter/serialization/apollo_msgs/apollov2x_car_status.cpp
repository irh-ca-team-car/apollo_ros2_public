#include "adapter/serialization/apollo_msgs/apollov2x_car_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xCarStatus &msg) {
        nlohmann::json obj;
        obj["localization"] = to_json(msg.localization);
        obj["chassisdetail"] = to_json(msg.chassisdetail);
        obj["junction"] = to_json(msg.junction);
        obj["rsuid"] = to_json(msg.rsuid);
        return obj;
    }
    Apollov2xCarStatus from_json_Apollov2xCarStatus (nlohmann::json obj) {
        Apollov2xCarStatus msg;
        if(obj.contains("localization"))
        {
            msg.localization = from_json_ApollolocalizationLocalizationEstimate(obj["localization"]);
        }
        if(obj.contains("chassisdetail"))
        {
            msg.chassisdetail = from_json_ApollocanbusChassisDetail(obj["chassisdetail"]);
        }
        if(obj.contains("junction"))
        {
            msg.junction = from_json_Apollov2xJunction(obj["junction"]);
        }
        if(obj.contains("rsuid"))
        {
            msg.rsuid = from_json_Apollov2xId(obj["rsuid"]);
        }
        return msg;
    }
    template <>
    Apollov2xCarStatus from_json<Apollov2xCarStatus>(nlohmann::json obj){
        return from_json_Apollov2xCarStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xCarStatus &dt)
    {
        dt=from_json_Apollov2xCarStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xCarStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xCarStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
