#include "adapter/serialization/apollo_msgs/apollov2xftfusion_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xftfusionParam &msg) {
        nlohmann::json obj;
        obj["k"] = (msg.k);
        obj["b"] = (msg.b);
        return obj;
    }
    Apollov2xftfusionParam from_json_Apollov2xftfusionParam (nlohmann::json obj) {
        Apollov2xftfusionParam msg;
        if(obj.contains("k"))
        {
            msg.k = (obj["k"].is_string()?atof(obj["k"].get<std::string>().c_str()):obj["k"].get<double>());
        }
        if(obj.contains("b"))
        {
            msg.b = (obj["b"].is_string()?atof(obj["b"].get<std::string>().c_str()):obj["b"].get<double>());
        }
        return msg;
    }
    template <>
    Apollov2xftfusionParam from_json<Apollov2xftfusionParam>(nlohmann::json obj){
        return from_json_Apollov2xftfusionParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xftfusionParam &dt)
    {
        dt=from_json_Apollov2xftfusionParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xftfusionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xftfusionParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
