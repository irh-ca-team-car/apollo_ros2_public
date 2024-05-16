#include "adapter/serialization/apollo_msgs/apollov2x_rsi_msg.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xRsiMsg &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_points;
        for (auto it = msg.points.begin(); it != msg.points.end(); ++it) {
            arr_points.push_back(to_json(*it));
        }
        obj["points"] = arr_points;
        obj["speed"] = (msg.speed);
        obj["lowspeed"] = (msg.lowspeed);
        obj["highspeed"] = (msg.highspeed);
        obj["description"] = (msg.description);
        obj["rsitype"] = (msg.rsitype);
        obj["radius"] = (msg.radius);
        obj["priority"] = (msg.priority);
        return obj;
    }
    Apollov2xRsiMsg from_json_Apollov2xRsiMsg (nlohmann::json obj) {
        Apollov2xRsiMsg msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("points"))
        {
            if(obj["points"].is_array())
            {
                for (auto& element : obj["points"])
                {
                    msg.points.push_back(from_json_Apollov2xRsiPoint(element));
                }
            }
            else
            {
                msg.points.push_back(from_json_Apollov2xRsiPoint(obj["points"]));
            }
        }
        if(obj.contains("speed"))
        {
            msg.speed = (obj["speed"].is_string()?atof(obj["speed"].get<std::string>().c_str()):obj["speed"].get<double>());
        }
        if(obj.contains("lowspeed"))
        {
            msg.lowspeed = (obj["lowspeed"].is_string()?atof(obj["lowspeed"].get<std::string>().c_str()):obj["lowspeed"].get<double>());
        }
        if(obj.contains("highspeed"))
        {
            msg.highspeed = (obj["highspeed"].is_string()?atof(obj["highspeed"].get<std::string>().c_str()):obj["highspeed"].get<double>());
        }
        if(obj.contains("description"))
        {
            msg.description = (obj["description"].is_string()?(obj["description"].get<std::string>().c_str()):obj["description"].get<std::string>());
        }
        if(obj.contains("rsitype"))
        {
            msg.rsitype = (obj["rsitype"].is_string()?atoi(obj["rsitype"].get<std::string>().c_str()):obj["rsitype"].get<int>());
        }
        if(obj.contains("radius"))
        {
            msg.radius = (obj["radius"].is_string()?atof(obj["radius"].get<std::string>().c_str()):obj["radius"].get<double>());
        }
        if(obj.contains("priority"))
        {
            msg.priority = (obj["priority"].is_string()?atoi(obj["priority"].get<std::string>().c_str()):obj["priority"].get<int>());
        }
        return msg;
    }
    template <>
    Apollov2xRsiMsg from_json<Apollov2xRsiMsg>(nlohmann::json obj){
        return from_json_Apollov2xRsiMsg(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xRsiMsg &dt)
    {
        dt=from_json_Apollov2xRsiMsg(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xRsiMsg & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xRsiMsg & dt)
    {
        os << to_json(dt);
        return os;
    }
}
