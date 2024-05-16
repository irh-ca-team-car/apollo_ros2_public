#include "adapter/serialization/apollo_msgs/apollov2x_update_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xUpdateStatus &msg) {
        nlohmann::json obj;
        obj["updated"] = (msg.updated);
        return obj;
    }
    Apollov2xUpdateStatus from_json_Apollov2xUpdateStatus (nlohmann::json obj) {
        Apollov2xUpdateStatus msg;
        if(obj.contains("updated"))
        {
            msg.updated = (obj["updated"].is_string()?(bool)atoi(obj["updated"].get<std::string>().c_str()):obj["updated"].get<bool>());
        }
        return msg;
    }
    template <>
    Apollov2xUpdateStatus from_json<Apollov2xUpdateStatus>(nlohmann::json obj){
        return from_json_Apollov2xUpdateStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xUpdateStatus &dt)
    {
        dt=from_json_Apollov2xUpdateStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xUpdateStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xUpdateStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
