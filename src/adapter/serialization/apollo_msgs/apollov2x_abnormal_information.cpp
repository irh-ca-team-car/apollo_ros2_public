#include "adapter/serialization/apollo_msgs/apollov2x_abnormal_information.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xAbnormalInformation &msg) {
        nlohmann::json obj;
        obj["averagespeed"] = (msg.averagespeed);
        obj["vehicledensity"] = (msg.vehicledensity);
        return obj;
    }
    Apollov2xAbnormalInformation from_json_Apollov2xAbnormalInformation (nlohmann::json obj) {
        Apollov2xAbnormalInformation msg;
        if(obj.contains("averagespeed"))
        {
            msg.averagespeed = (obj["averagespeed"].is_string()?atof(obj["averagespeed"].get<std::string>().c_str()):obj["averagespeed"].get<double>());
        }
        if(obj.contains("vehicledensity"))
        {
            msg.vehicledensity = (obj["vehicledensity"].is_string()?atof(obj["vehicledensity"].get<std::string>().c_str()):obj["vehicledensity"].get<double>());
        }
        return msg;
    }
    template <>
    Apollov2xAbnormalInformation from_json<Apollov2xAbnormalInformation>(nlohmann::json obj){
        return from_json_Apollov2xAbnormalInformation(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xAbnormalInformation &dt)
    {
        dt=from_json_Apollov2xAbnormalInformation(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xAbnormalInformation & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xAbnormalInformation & dt)
    {
        os << to_json(dt);
        return os;
    }
}
