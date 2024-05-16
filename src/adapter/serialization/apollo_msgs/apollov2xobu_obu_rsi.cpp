#include "adapter/serialization/apollo_msgs/apollov2xobu_obu_rsi.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xobuObuRsi &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["rsuid"] = to_json(msg.rsuid);
        obj["rsiid"] = (msg.rsiid);
        obj["altertype"] = (msg.altertype);
        obj["description"] = (msg.description);
        obj["refpoint"] = to_json(msg.refpoint);
        nlohmann::json arr_points;
        for (auto it = msg.points.begin(); it != msg.points.end(); ++it) {
            arr_points.push_back(to_json(*it));
        }
        obj["points"] = arr_points;
        obj["radius"] = (msg.radius);
        obj["msgcnt"] = (msg.msgcnt);
        return obj;
    }
    Apollov2xobuObuRsi from_json_Apollov2xobuObuRsi (nlohmann::json obj) {
        Apollov2xobuObuRsi msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("rsuid"))
        {
            msg.rsuid = from_json_Bytes(obj["rsuid"]);
        }
        if(obj.contains("rsiid"))
        {
            msg.rsiid = (obj["rsiid"].is_string()?atoi(obj["rsiid"].get<std::string>().c_str()):obj["rsiid"].get<int>());
        }
        if(obj.contains("altertype"))
        {
            msg.altertype = (obj["altertype"].is_string()?atoi(obj["altertype"].get<std::string>().c_str()):obj["altertype"].get<int>());
        }
        if(obj.contains("description"))
        {
            msg.description = (obj["description"].is_string()?(obj["description"].get<std::string>().c_str()):obj["description"].get<std::string>());
        }
        if(obj.contains("refpoint"))
        {
            msg.refpoint = from_json_ApollocommonPoint2D(obj["refpoint"]);
        }
        if(obj.contains("points"))
        {
            if(obj["points"].is_array())
            {
                for (auto& element : obj["points"])
                {
                    msg.points.push_back(from_json_ApollocommonPoint2D(element));
                }
            }
            else
            {
                msg.points.push_back(from_json_ApollocommonPoint2D(obj["points"]));
            }
        }
        if(obj.contains("radius"))
        {
            msg.radius = (obj["radius"].is_string()?atoi(obj["radius"].get<std::string>().c_str()):obj["radius"].get<int>());
        }
        if(obj.contains("msgcnt"))
        {
            msg.msgcnt = (obj["msgcnt"].is_string()?atoi(obj["msgcnt"].get<std::string>().c_str()):obj["msgcnt"].get<int>());
        }
        return msg;
    }
    template <>
    Apollov2xobuObuRsi from_json<Apollov2xobuObuRsi>(nlohmann::json obj){
        return from_json_Apollov2xobuObuRsi(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xobuObuRsi &dt)
    {
        dt=from_json_Apollov2xobuObuRsi(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xobuObuRsi & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xobuObuRsi & dt)
    {
        os << to_json(dt);
        return os;
    }
}
