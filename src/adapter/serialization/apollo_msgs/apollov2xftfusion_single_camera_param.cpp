#include "adapter/serialization/apollo_msgs/apollov2xftfusion_single_camera_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xftfusionSingleCameraParam &msg) {
        nlohmann::json obj;
        obj["cameraid"] = (msg.cameraid);
        nlohmann::json arr_param;
        for (auto it = msg.param.begin(); it != msg.param.end(); ++it) {
            arr_param.push_back(to_json(*it));
        }
        obj["param"] = arr_param;
        return obj;
    }
    Apollov2xftfusionSingleCameraParam from_json_Apollov2xftfusionSingleCameraParam (nlohmann::json obj) {
        Apollov2xftfusionSingleCameraParam msg;
        if(obj.contains("cameraid"))
        {
            msg.cameraid = (obj["cameraid"].is_string()?atoi(obj["cameraid"].get<std::string>().c_str()):obj["cameraid"].get<int>());
        }
        if(obj.contains("param"))
        {
            if(obj["param"].is_array())
            {
                for (auto& element : obj["param"])
                {
                    msg.param.push_back(from_json_Apollov2xftfusionParam(element));
                }
            }
            else
            {
                msg.param.push_back(from_json_Apollov2xftfusionParam(obj["param"]));
            }
        }
        return msg;
    }
    template <>
    Apollov2xftfusionSingleCameraParam from_json<Apollov2xftfusionSingleCameraParam>(nlohmann::json obj){
        return from_json_Apollov2xftfusionSingleCameraParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xftfusionSingleCameraParam &dt)
    {
        dt=from_json_Apollov2xftfusionSingleCameraParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xftfusionSingleCameraParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xftfusionSingleCameraParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
