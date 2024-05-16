#include "adapter/serialization/apollo_msgs/apollodriversvelodyne_velodyne_scan.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversvelodyneVelodyneScan &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["model"] = (msg.model);
        obj["mode"] = (msg.mode);
        nlohmann::json arr_firingpkts;
        for (auto it = msg.firingpkts.begin(); it != msg.firingpkts.end(); ++it) {
            arr_firingpkts.push_back(to_json(*it));
        }
        obj["firingpkts"] = arr_firingpkts;
        nlohmann::json arr_positioningpkts;
        for (auto it = msg.positioningpkts.begin(); it != msg.positioningpkts.end(); ++it) {
            arr_positioningpkts.push_back(to_json(*it));
        }
        obj["positioningpkts"] = arr_positioningpkts;
        obj["sn"] = (msg.sn);
        obj["basetime"] = (msg.basetime);
        return obj;
    }
    ApollodriversvelodyneVelodyneScan from_json_ApollodriversvelodyneVelodyneScan (nlohmann::json obj) {
        ApollodriversvelodyneVelodyneScan msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("model"))
        {
            msg.model = (obj["model"].is_string()?atoi(obj["model"].get<std::string>().c_str()):obj["model"].get<int>());
        }
        if(obj.contains("mode"))
        {
            msg.mode = (obj["mode"].is_string()?atoi(obj["mode"].get<std::string>().c_str()):obj["mode"].get<int>());
        }
        if(obj.contains("firingpkts"))
        {
            if(obj["firingpkts"].is_array())
            {
                for (auto& element : obj["firingpkts"])
                {
                    msg.firingpkts.push_back(from_json_ApollodriversvelodyneVelodynePacket(element));
                }
            }
            else
            {
                msg.firingpkts.push_back(from_json_ApollodriversvelodyneVelodynePacket(obj["firingpkts"]));
            }
        }
        if(obj.contains("positioningpkts"))
        {
            if(obj["positioningpkts"].is_array())
            {
                for (auto& element : obj["positioningpkts"])
                {
                    msg.positioningpkts.push_back(from_json_ApollodriversvelodyneVelodynePacket(element));
                }
            }
            else
            {
                msg.positioningpkts.push_back(from_json_ApollodriversvelodyneVelodynePacket(obj["positioningpkts"]));
            }
        }
        if(obj.contains("sn"))
        {
            msg.sn = (obj["sn"].is_string()?(obj["sn"].get<std::string>().c_str()):obj["sn"].get<std::string>());
        }
        if(obj.contains("basetime"))
        {
            msg.basetime = (obj["basetime"].is_string()?atol(obj["basetime"].get<std::string>().c_str()):obj["basetime"].get<uint64_t>());
        }
        return msg;
    }
    template <>
    ApollodriversvelodyneVelodyneScan from_json<ApollodriversvelodyneVelodyneScan>(nlohmann::json obj){
        return from_json_ApollodriversvelodyneVelodyneScan(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversvelodyneVelodyneScan &dt)
    {
        dt=from_json_ApollodriversvelodyneVelodyneScan(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversvelodyneVelodyneScan & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversvelodyneVelodyneScan & dt)
    {
        os << to_json(dt);
        return os;
    }
}
