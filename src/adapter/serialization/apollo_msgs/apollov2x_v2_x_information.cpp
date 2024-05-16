#include "adapter/serialization/apollo_msgs/apollov2x_v2_x_information.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xV2XInformation &msg) {
        nlohmann::json obj;
        nlohmann::json arr_v2xtype;
        for (auto it = msg.v2xtype.begin(); it != msg.v2xtype.end(); ++it) {
            arr_v2xtype.push_back((*it));
        }
        obj["v2xtype"] = arr_v2xtype;
        obj["trafficeventstart"] = to_json(msg.trafficeventstart);
        obj["trafficeventstarterror"] = to_json(msg.trafficeventstarterror);
        obj["trafficeventend"] = to_json(msg.trafficeventend);
        obj["trafficeventenderror"] = to_json(msg.trafficeventenderror);
        obj["abnormalinfo"] = to_json(msg.abnormalinfo);
        return obj;
    }
    Apollov2xV2XInformation from_json_Apollov2xV2XInformation (nlohmann::json obj) {
        Apollov2xV2XInformation msg;
        if(obj.contains("v2xtype"))
        {
            if(obj["v2xtype"].is_array())
            {
                for (auto& element : obj["v2xtype"])
                {
                    msg.v2xtype.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.v2xtype.push_back((obj["v2xtype"].is_string()?atoi(obj["v2xtype"].get<std::string>().c_str()):obj["v2xtype"].get<int>()));
            }
        }
        if(obj.contains("trafficeventstart"))
        {
            msg.trafficeventstart = from_json_Apollov2xPoint(obj["trafficeventstart"]);
        }
        if(obj.contains("trafficeventstarterror"))
        {
            msg.trafficeventstarterror = from_json_Apollov2xPoint(obj["trafficeventstarterror"]);
        }
        if(obj.contains("trafficeventend"))
        {
            msg.trafficeventend = from_json_Apollov2xPoint(obj["trafficeventend"]);
        }
        if(obj.contains("trafficeventenderror"))
        {
            msg.trafficeventenderror = from_json_Apollov2xPoint(obj["trafficeventenderror"]);
        }
        if(obj.contains("abnormalinfo"))
        {
            msg.abnormalinfo = from_json_Apollov2xAbnormalInformation(obj["abnormalinfo"]);
        }
        return msg;
    }
    template <>
    Apollov2xV2XInformation from_json<Apollov2xV2XInformation>(nlohmann::json obj){
        return from_json_Apollov2xV2XInformation(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xV2XInformation &dt)
    {
        dt=from_json_Apollov2xV2XInformation(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xV2XInformation & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xV2XInformation & dt)
    {
        os << to_json(dt);
        return os;
    }
}
