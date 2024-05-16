#include "adapter/serialization/apollo_msgs/apollov2x_single_traffic_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xSingleTrafficLight &msg) {
        nlohmann::json obj;
        obj["color"] = (msg.color);
        nlohmann::json arr_trafficlighttype;
        for (auto it = msg.trafficlighttype.begin(); it != msg.trafficlighttype.end(); ++it) {
            arr_trafficlighttype.push_back((*it));
        }
        obj["trafficlighttype"] = arr_trafficlighttype;
        obj["id"] = (msg.id);
        obj["colorremainingtimes"] = (msg.colorremainingtimes);
        obj["rightturnlight"] = (msg.rightturnlight);
        obj["nextcolor"] = (msg.nextcolor);
        obj["nextremainingtimes"] = (msg.nextremainingtimes);
        return obj;
    }
    Apollov2xSingleTrafficLight from_json_Apollov2xSingleTrafficLight (nlohmann::json obj) {
        Apollov2xSingleTrafficLight msg;
        if(obj.contains("color"))
        {
            msg.color = (obj["color"].is_string()?atoi(obj["color"].get<std::string>().c_str()):obj["color"].get<int>());
        }
        if(obj.contains("trafficlighttype"))
        {
            if(obj["trafficlighttype"].is_array())
            {
                for (auto& element : obj["trafficlighttype"])
                {
                    msg.trafficlighttype.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.trafficlighttype.push_back((obj["trafficlighttype"].is_string()?atoi(obj["trafficlighttype"].get<std::string>().c_str()):obj["trafficlighttype"].get<int>()));
            }
        }
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?(obj["id"].get<std::string>().c_str()):obj["id"].get<std::string>());
        }
        if(obj.contains("colorremainingtimes"))
        {
            msg.colorremainingtimes = (obj["colorremainingtimes"].is_string()?atoi(obj["colorremainingtimes"].get<std::string>().c_str()):obj["colorremainingtimes"].get<int>());
        }
        if(obj.contains("rightturnlight"))
        {
            msg.rightturnlight = (obj["rightturnlight"].is_string()?(bool)atoi(obj["rightturnlight"].get<std::string>().c_str()):obj["rightturnlight"].get<bool>());
        }
        if(obj.contains("nextcolor"))
        {
            msg.nextcolor = (obj["nextcolor"].is_string()?atoi(obj["nextcolor"].get<std::string>().c_str()):obj["nextcolor"].get<int>());
        }
        if(obj.contains("nextremainingtimes"))
        {
            msg.nextremainingtimes = (obj["nextremainingtimes"].is_string()?atof(obj["nextremainingtimes"].get<std::string>().c_str()):obj["nextremainingtimes"].get<double>());
        }
        return msg;
    }
    template <>
    Apollov2xSingleTrafficLight from_json<Apollov2xSingleTrafficLight>(nlohmann::json obj){
        return from_json_Apollov2xSingleTrafficLight(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xSingleTrafficLight &dt)
    {
        dt=from_json_Apollov2xSingleTrafficLight(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xSingleTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xSingleTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
}
