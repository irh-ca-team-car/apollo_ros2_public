#include "adapter/serialization/apollo_msgs/apollov2xobu_road_traffic_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xobuRoadTrafficLight &msg) {
        nlohmann::json obj;
        nlohmann::json arr_lanetrafficlight;
        for (auto it = msg.lanetrafficlight.begin(); it != msg.lanetrafficlight.end(); ++it) {
            arr_lanetrafficlight.push_back(to_json(*it));
        }
        obj["lanetrafficlight"] = arr_lanetrafficlight;
        obj["roaddirection"] = (msg.roaddirection);
        return obj;
    }
    Apollov2xobuRoadTrafficLight from_json_Apollov2xobuRoadTrafficLight (nlohmann::json obj) {
        Apollov2xobuRoadTrafficLight msg;
        if(obj.contains("lanetrafficlight"))
        {
            if(obj["lanetrafficlight"].is_array())
            {
                for (auto& element : obj["lanetrafficlight"])
                {
                    msg.lanetrafficlight.push_back(from_json_Apollov2xobuLaneTrafficLight(element));
                }
            }
            else
            {
                msg.lanetrafficlight.push_back(from_json_Apollov2xobuLaneTrafficLight(obj["lanetrafficlight"]));
            }
        }
        if(obj.contains("roaddirection"))
        {
            msg.roaddirection = (obj["roaddirection"].is_string()?atoi(obj["roaddirection"].get<std::string>().c_str()):obj["roaddirection"].get<int>());
        }
        return msg;
    }
    template <>
    Apollov2xobuRoadTrafficLight from_json<Apollov2xobuRoadTrafficLight>(nlohmann::json obj){
        return from_json_Apollov2xobuRoadTrafficLight(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xobuRoadTrafficLight &dt)
    {
        dt=from_json_Apollov2xobuRoadTrafficLight(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xobuRoadTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xobuRoadTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
}
