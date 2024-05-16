#include "adapter/serialization/apollo_msgs/apollov2x_road_traffic_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xRoadTrafficLight &msg) {
        nlohmann::json obj;
        obj["gpsxm"] = (msg.gpsxm);
        obj["gpsym"] = (msg.gpsym);
        nlohmann::json arr_singletrafficlight;
        for (auto it = msg.singletrafficlight.begin(); it != msg.singletrafficlight.end(); ++it) {
            arr_singletrafficlight.push_back(to_json(*it));
        }
        obj["singletrafficlight"] = arr_singletrafficlight;
        obj["roadattribute"] = (msg.roadattribute);
        return obj;
    }
    Apollov2xRoadTrafficLight from_json_Apollov2xRoadTrafficLight (nlohmann::json obj) {
        Apollov2xRoadTrafficLight msg;
        if(obj.contains("gpsxm"))
        {
            msg.gpsxm = (obj["gpsxm"].is_string()?atof(obj["gpsxm"].get<std::string>().c_str()):obj["gpsxm"].get<double>());
        }
        if(obj.contains("gpsym"))
        {
            msg.gpsym = (obj["gpsym"].is_string()?atof(obj["gpsym"].get<std::string>().c_str()):obj["gpsym"].get<double>());
        }
        if(obj.contains("singletrafficlight"))
        {
            if(obj["singletrafficlight"].is_array())
            {
                for (auto& element : obj["singletrafficlight"])
                {
                    msg.singletrafficlight.push_back(from_json_Apollov2xSingleTrafficLight(element));
                }
            }
            else
            {
                msg.singletrafficlight.push_back(from_json_Apollov2xSingleTrafficLight(obj["singletrafficlight"]));
            }
        }
        if(obj.contains("roadattribute"))
        {
            msg.roadattribute = (obj["roadattribute"].is_string()?atoi(obj["roadattribute"].get<std::string>().c_str()):obj["roadattribute"].get<int>());
        }
        return msg;
    }
    template <>
    Apollov2xRoadTrafficLight from_json<Apollov2xRoadTrafficLight>(nlohmann::json obj){
        return from_json_Apollov2xRoadTrafficLight(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xRoadTrafficLight &dt)
    {
        dt=from_json_Apollov2xRoadTrafficLight(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xRoadTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xRoadTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
}
