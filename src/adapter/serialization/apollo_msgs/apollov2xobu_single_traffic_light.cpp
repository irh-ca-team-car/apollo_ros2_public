#include "adapter/serialization/apollo_msgs/apollov2xobu_single_traffic_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xobuSingleTrafficLight &msg) {
        nlohmann::json obj;
        obj["color"] = (msg.color);
        obj["trafficlighttype"] = (msg.trafficlighttype);
        obj["id"] = (msg.id);
        obj["colorremainingtimes"] = (msg.colorremainingtimes);
        obj["rightturnlight"] = (msg.rightturnlight);
        obj["nextcolor"] = (msg.nextcolor);
        obj["nextremainingtime"] = (msg.nextremainingtime);
        obj["next2ndcolor"] = (msg.next2ndcolor);
        obj["next2ndremainingtime"] = (msg.next2ndremainingtime);
        return obj;
    }
    Apollov2xobuSingleTrafficLight from_json_Apollov2xobuSingleTrafficLight (nlohmann::json obj) {
        Apollov2xobuSingleTrafficLight msg;
        if(obj.contains("color"))
        {
            msg.color = (obj["color"].is_string()?atoi(obj["color"].get<std::string>().c_str()):obj["color"].get<int>());
        }
        if(obj.contains("trafficlighttype"))
        {
            msg.trafficlighttype = (obj["trafficlighttype"].is_string()?atoi(obj["trafficlighttype"].get<std::string>().c_str()):obj["trafficlighttype"].get<int>());
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
        if(obj.contains("nextremainingtime"))
        {
            msg.nextremainingtime = (obj["nextremainingtime"].is_string()?atof(obj["nextremainingtime"].get<std::string>().c_str()):obj["nextremainingtime"].get<double>());
        }
        if(obj.contains("next2ndcolor"))
        {
            msg.next2ndcolor = (obj["next2ndcolor"].is_string()?atoi(obj["next2ndcolor"].get<std::string>().c_str()):obj["next2ndcolor"].get<int>());
        }
        if(obj.contains("next2ndremainingtime"))
        {
            msg.next2ndremainingtime = (obj["next2ndremainingtime"].is_string()?atof(obj["next2ndremainingtime"].get<std::string>().c_str()):obj["next2ndremainingtime"].get<double>());
        }
        return msg;
    }
    template <>
    Apollov2xobuSingleTrafficLight from_json<Apollov2xobuSingleTrafficLight>(nlohmann::json obj){
        return from_json_Apollov2xobuSingleTrafficLight(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xobuSingleTrafficLight &dt)
    {
        dt=from_json_Apollov2xobuSingleTrafficLight(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xobuSingleTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xobuSingleTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
}
