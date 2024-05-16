#include "adapter/serialization/apollo_msgs/apollohdmap_object_overlap_infooverlap_info.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapObjectOverlapInfooverlapInfo &msg) {
        nlohmann::json obj;
        obj["laneoverlapinfo"] = to_json(msg.laneoverlapinfo);
        obj["signaloverlapinfo"] = (msg.signaloverlapinfo);
        obj["stopsignoverlapinfo"] = (msg.stopsignoverlapinfo);
        obj["crosswalkoverlapinfo"] = to_json(msg.crosswalkoverlapinfo);
        obj["junctionoverlapinfo"] = (msg.junctionoverlapinfo);
        obj["yieldsignoverlapinfo"] = (msg.yieldsignoverlapinfo);
        obj["clearareaoverlapinfo"] = (msg.clearareaoverlapinfo);
        obj["speedbumpoverlapinfo"] = (msg.speedbumpoverlapinfo);
        obj["parkingspaceoverlapinfo"] = (msg.parkingspaceoverlapinfo);
        obj["pncjunctionoverlapinfo"] = (msg.pncjunctionoverlapinfo);
        obj["rsuoverlapinfo"] = (msg.rsuoverlapinfo);
        return obj;
    }
    ApollohdmapObjectOverlapInfooverlapInfo from_json_ApollohdmapObjectOverlapInfooverlapInfo (nlohmann::json obj) {
        ApollohdmapObjectOverlapInfooverlapInfo msg;
        if(obj.contains("laneoverlapinfo"))
        {
            msg.laneoverlapinfo = from_json_ApollohdmapLaneOverlapInfo(obj["laneoverlapinfo"]);
        }
        if(obj.contains("signaloverlapinfo"))
        {
            msg.signaloverlapinfo = (obj["signaloverlapinfo"].is_string()?atoi(obj["signaloverlapinfo"].get<std::string>().c_str()):obj["signaloverlapinfo"].get<int>());
        }
        if(obj.contains("stopsignoverlapinfo"))
        {
            msg.stopsignoverlapinfo = (obj["stopsignoverlapinfo"].is_string()?atoi(obj["stopsignoverlapinfo"].get<std::string>().c_str()):obj["stopsignoverlapinfo"].get<int>());
        }
        if(obj.contains("crosswalkoverlapinfo"))
        {
            msg.crosswalkoverlapinfo = from_json_ApollohdmapCrosswalkOverlapInfo(obj["crosswalkoverlapinfo"]);
        }
        if(obj.contains("junctionoverlapinfo"))
        {
            msg.junctionoverlapinfo = (obj["junctionoverlapinfo"].is_string()?atoi(obj["junctionoverlapinfo"].get<std::string>().c_str()):obj["junctionoverlapinfo"].get<int>());
        }
        if(obj.contains("yieldsignoverlapinfo"))
        {
            msg.yieldsignoverlapinfo = (obj["yieldsignoverlapinfo"].is_string()?atoi(obj["yieldsignoverlapinfo"].get<std::string>().c_str()):obj["yieldsignoverlapinfo"].get<int>());
        }
        if(obj.contains("clearareaoverlapinfo"))
        {
            msg.clearareaoverlapinfo = (obj["clearareaoverlapinfo"].is_string()?atoi(obj["clearareaoverlapinfo"].get<std::string>().c_str()):obj["clearareaoverlapinfo"].get<int>());
        }
        if(obj.contains("speedbumpoverlapinfo"))
        {
            msg.speedbumpoverlapinfo = (obj["speedbumpoverlapinfo"].is_string()?atoi(obj["speedbumpoverlapinfo"].get<std::string>().c_str()):obj["speedbumpoverlapinfo"].get<int>());
        }
        if(obj.contains("parkingspaceoverlapinfo"))
        {
            msg.parkingspaceoverlapinfo = (obj["parkingspaceoverlapinfo"].is_string()?atoi(obj["parkingspaceoverlapinfo"].get<std::string>().c_str()):obj["parkingspaceoverlapinfo"].get<int>());
        }
        if(obj.contains("pncjunctionoverlapinfo"))
        {
            msg.pncjunctionoverlapinfo = (obj["pncjunctionoverlapinfo"].is_string()?atoi(obj["pncjunctionoverlapinfo"].get<std::string>().c_str()):obj["pncjunctionoverlapinfo"].get<int>());
        }
        if(obj.contains("rsuoverlapinfo"))
        {
            msg.rsuoverlapinfo = (obj["rsuoverlapinfo"].is_string()?atoi(obj["rsuoverlapinfo"].get<std::string>().c_str()):obj["rsuoverlapinfo"].get<int>());
        }
        return msg;
    }
    template <>
    ApollohdmapObjectOverlapInfooverlapInfo from_json<ApollohdmapObjectOverlapInfooverlapInfo>(nlohmann::json obj){
        return from_json_ApollohdmapObjectOverlapInfooverlapInfo(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapObjectOverlapInfooverlapInfo &dt)
    {
        dt=from_json_ApollohdmapObjectOverlapInfooverlapInfo(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapObjectOverlapInfooverlapInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapObjectOverlapInfooverlapInfo & dt)
    {
        os << to_json(dt);
        return os;
    }
}
