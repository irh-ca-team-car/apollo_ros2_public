#include "adapter/serialization/apollo_msgs/apollov2x_status_response.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xStatusResponse &msg) {
        nlohmann::json obj;
        obj["status"] = (msg.status);
        obj["info"] = (msg.info);
        obj["errorcode"] = (msg.errorcode);
        return obj;
    }
    Apollov2xStatusResponse from_json_Apollov2xStatusResponse (nlohmann::json obj) {
        Apollov2xStatusResponse msg;
        if(obj.contains("status"))
        {
            msg.status = (obj["status"].is_string()?(bool)atoi(obj["status"].get<std::string>().c_str()):obj["status"].get<bool>());
        }
        if(obj.contains("info"))
        {
            msg.info = (obj["info"].is_string()?(obj["info"].get<std::string>().c_str()):obj["info"].get<std::string>());
        }
        if(obj.contains("errorcode"))
        {
            msg.errorcode = (obj["errorcode"].is_string()?atol(obj["errorcode"].get<std::string>().c_str()):obj["errorcode"].get<long>());
        }
        return msg;
    }
    template <>
    Apollov2xStatusResponse from_json<Apollov2xStatusResponse>(nlohmann::json obj){
        return from_json_Apollov2xStatusResponse(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xStatusResponse &dt)
    {
        dt=from_json_Apollov2xStatusResponse(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xStatusResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xStatusResponse & dt)
    {
        os << to_json(dt);
        return os;
    }
}
