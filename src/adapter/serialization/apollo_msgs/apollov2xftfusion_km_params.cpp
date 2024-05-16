#include "adapter/serialization/apollo_msgs/apollov2xftfusion_km_params.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xftfusionKMParams &msg) {
        nlohmann::json obj;
        obj["minscore"] = (msg.minscore);
        return obj;
    }
    Apollov2xftfusionKMParams from_json_Apollov2xftfusionKMParams (nlohmann::json obj) {
        Apollov2xftfusionKMParams msg;
        if(obj.contains("minscore"))
        {
            msg.minscore = (obj["minscore"].is_string()?atof(obj["minscore"].get<std::string>().c_str()):obj["minscore"].get<double>());
        }
        return msg;
    }
    template <>
    Apollov2xftfusionKMParams from_json<Apollov2xftfusionKMParams>(nlohmann::json obj){
        return from_json_Apollov2xftfusionKMParams(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xftfusionKMParams &dt)
    {
        dt=from_json_Apollov2xftfusionKMParams(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xftfusionKMParams & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xftfusionKMParams & dt)
    {
        os << to_json(dt);
        return os;
    }
}
