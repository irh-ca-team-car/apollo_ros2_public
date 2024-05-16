#include "adapter/serialization/apollo_msgs/apollorouting_node.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloroutingNode &msg) {
        nlohmann::json obj;
        obj["laneid"] = (msg.laneid);
        obj["length"] = (msg.length);
        nlohmann::json arr_leftout;
        for (auto it = msg.leftout.begin(); it != msg.leftout.end(); ++it) {
            arr_leftout.push_back(to_json(*it));
        }
        obj["leftout"] = arr_leftout;
        nlohmann::json arr_rightout;
        for (auto it = msg.rightout.begin(); it != msg.rightout.end(); ++it) {
            arr_rightout.push_back(to_json(*it));
        }
        obj["rightout"] = arr_rightout;
        obj["cost"] = (msg.cost);
        obj["centralcurve"] = to_json(msg.centralcurve);
        obj["isvirtual"] = (msg.isvirtual);
        obj["roadid"] = (msg.roadid);
        return obj;
    }
    ApolloroutingNode from_json_ApolloroutingNode (nlohmann::json obj) {
        ApolloroutingNode msg;
        if(obj.contains("laneid"))
        {
            msg.laneid = (obj["laneid"].is_string()?(obj["laneid"].get<std::string>().c_str()):obj["laneid"].get<std::string>());
        }
        if(obj.contains("length"))
        {
            msg.length = (obj["length"].is_string()?atof(obj["length"].get<std::string>().c_str()):obj["length"].get<double>());
        }
        if(obj.contains("leftout"))
        {
            if(obj["leftout"].is_array())
            {
                for (auto& element : obj["leftout"])
                {
                    msg.leftout.push_back(from_json_ApolloroutingCurveRange(element));
                }
            }
            else
            {
                msg.leftout.push_back(from_json_ApolloroutingCurveRange(obj["leftout"]));
            }
        }
        if(obj.contains("rightout"))
        {
            if(obj["rightout"].is_array())
            {
                for (auto& element : obj["rightout"])
                {
                    msg.rightout.push_back(from_json_ApolloroutingCurveRange(element));
                }
            }
            else
            {
                msg.rightout.push_back(from_json_ApolloroutingCurveRange(obj["rightout"]));
            }
        }
        if(obj.contains("cost"))
        {
            msg.cost = (obj["cost"].is_string()?atof(obj["cost"].get<std::string>().c_str()):obj["cost"].get<double>());
        }
        if(obj.contains("centralcurve"))
        {
            msg.centralcurve = from_json_ApollohdmapCurve(obj["centralcurve"]);
        }
        if(obj.contains("isvirtual"))
        {
            msg.isvirtual = (obj["isvirtual"].is_string()?(bool)atoi(obj["isvirtual"].get<std::string>().c_str()):obj["isvirtual"].get<bool>());
        }
        if(obj.contains("roadid"))
        {
            msg.roadid = (obj["roadid"].is_string()?(obj["roadid"].get<std::string>().c_str()):obj["roadid"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloroutingNode from_json<ApolloroutingNode>(nlohmann::json obj){
        return from_json_ApolloroutingNode(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloroutingNode &dt)
    {
        dt=from_json_ApolloroutingNode(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloroutingNode & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloroutingNode & dt)
    {
        os << to_json(dt);
        return os;
    }
}
