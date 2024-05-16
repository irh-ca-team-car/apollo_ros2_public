#include "adapter/serialization/apollo_msgs/apollov2xobu_obu_traffic_light.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Apollov2xobuObuTrafficLight &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_roadtrafficlight;
        for (auto it = msg.roadtrafficlight.begin(); it != msg.roadtrafficlight.end(); ++it) {
            arr_roadtrafficlight.push_back(to_json(*it));
        }
        obj["roadtrafficlight"] = arr_roadtrafficlight;
        obj["intersectionid"] = (msg.intersectionid);
        obj["hdmapjunctionid"] = to_json(msg.hdmapjunctionid);
        return obj;
    }
    Apollov2xobuObuTrafficLight from_json_Apollov2xobuObuTrafficLight (nlohmann::json obj) {
        Apollov2xobuObuTrafficLight msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("roadtrafficlight"))
        {
            if(obj["roadtrafficlight"].is_array())
            {
                for (auto& element : obj["roadtrafficlight"])
                {
                    msg.roadtrafficlight.push_back(from_json_Apollov2xobuRoadTrafficLight(element));
                }
            }
            else
            {
                msg.roadtrafficlight.push_back(from_json_Apollov2xobuRoadTrafficLight(obj["roadtrafficlight"]));
            }
        }
        if(obj.contains("intersectionid"))
        {
            msg.intersectionid = (obj["intersectionid"].is_string()?atoi(obj["intersectionid"].get<std::string>().c_str()):obj["intersectionid"].get<int>());
        }
        if(obj.contains("hdmapjunctionid"))
        {
            msg.hdmapjunctionid = from_json_Bytes(obj["hdmapjunctionid"]);
        }
        return msg;
    }
    template <>
    Apollov2xobuObuTrafficLight from_json<Apollov2xobuObuTrafficLight>(nlohmann::json obj){
        return from_json_Apollov2xobuObuTrafficLight(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Apollov2xobuObuTrafficLight &dt)
    {
        dt=from_json_Apollov2xobuObuTrafficLight(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Apollov2xobuObuTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Apollov2xobuObuTrafficLight & dt)
    {
        os << to_json(dt);
        return os;
    }
}
