#include "adapter/serialization/apollo_msgs/apollov2x_id.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xId &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        return obj;
    }
    Apollov2xId from_json_Apollov2xId (nlohmann::json obj) {
        Apollov2xId msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_Bytes(obj["id"]);
        }
        return msg;
    }
    template <>
    Apollov2xId from_json<Apollov2xId>(nlohmann::json obj){
        return from_json_Apollov2xId(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xId &dt)
    {
        dt=from_json_Apollov2xId(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xId & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xId & dt)
    {
        os << to_json(dt);
        return os;
    }
}
