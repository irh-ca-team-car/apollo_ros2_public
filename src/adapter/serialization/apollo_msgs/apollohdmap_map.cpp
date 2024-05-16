#include "adapter/serialization/apollo_msgs/apollohdmap_map.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapMap &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        nlohmann::json arr_crosswalk;
        for (auto it = msg.crosswalk.begin(); it != msg.crosswalk.end(); ++it) {
            arr_crosswalk.push_back(to_json(*it));
        }
        obj["crosswalk"] = arr_crosswalk;
        nlohmann::json arr_junction;
        for (auto it = msg.junction.begin(); it != msg.junction.end(); ++it) {
            arr_junction.push_back(to_json(*it));
        }
        obj["junction"] = arr_junction;
        nlohmann::json arr_lane;
        for (auto it = msg.lane.begin(); it != msg.lane.end(); ++it) {
            arr_lane.push_back(to_json(*it));
        }
        obj["lane"] = arr_lane;
        nlohmann::json arr_stopsign;
        for (auto it = msg.stopsign.begin(); it != msg.stopsign.end(); ++it) {
            arr_stopsign.push_back(to_json(*it));
        }
        obj["stopsign"] = arr_stopsign;
        nlohmann::json arr_signal;
        for (auto it = msg.signal.begin(); it != msg.signal.end(); ++it) {
            arr_signal.push_back(to_json(*it));
        }
        obj["signal"] = arr_signal;
        nlohmann::json arr_yieldd;
        for (auto it = msg.yieldd.begin(); it != msg.yieldd.end(); ++it) {
            arr_yieldd.push_back(to_json(*it));
        }
        obj["yieldd"] = arr_yieldd;
        nlohmann::json arr_overlap;
        for (auto it = msg.overlap.begin(); it != msg.overlap.end(); ++it) {
            arr_overlap.push_back(to_json(*it));
        }
        obj["overlap"] = arr_overlap;
        nlohmann::json arr_cleararea;
        for (auto it = msg.cleararea.begin(); it != msg.cleararea.end(); ++it) {
            arr_cleararea.push_back(to_json(*it));
        }
        obj["cleararea"] = arr_cleararea;
        nlohmann::json arr_speedbump;
        for (auto it = msg.speedbump.begin(); it != msg.speedbump.end(); ++it) {
            arr_speedbump.push_back(to_json(*it));
        }
        obj["speedbump"] = arr_speedbump;
        nlohmann::json arr_road;
        for (auto it = msg.road.begin(); it != msg.road.end(); ++it) {
            arr_road.push_back(to_json(*it));
        }
        obj["road"] = arr_road;
        nlohmann::json arr_parkingspace;
        for (auto it = msg.parkingspace.begin(); it != msg.parkingspace.end(); ++it) {
            arr_parkingspace.push_back(to_json(*it));
        }
        obj["parkingspace"] = arr_parkingspace;
        nlohmann::json arr_pncjunction;
        for (auto it = msg.pncjunction.begin(); it != msg.pncjunction.end(); ++it) {
            arr_pncjunction.push_back(to_json(*it));
        }
        obj["pncjunction"] = arr_pncjunction;
        nlohmann::json arr_rsu;
        for (auto it = msg.rsu.begin(); it != msg.rsu.end(); ++it) {
            arr_rsu.push_back(to_json(*it));
        }
        obj["rsu"] = arr_rsu;
        return obj;
    }
    ApollohdmapMap from_json_ApollohdmapMap (nlohmann::json obj) {
        ApollohdmapMap msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollohdmapHeader(obj["apolloheader"]);
        }
        if(obj.contains("crosswalk"))
        {
            if(obj["crosswalk"].is_array())
            {
                for (auto& element : obj["crosswalk"])
                {
                    msg.crosswalk.push_back(from_json_ApollohdmapCrosswalk(element));
                }
            }
            else
            {
                msg.crosswalk.push_back(from_json_ApollohdmapCrosswalk(obj["crosswalk"]));
            }
        }
        if(obj.contains("junction"))
        {
            if(obj["junction"].is_array())
            {
                for (auto& element : obj["junction"])
                {
                    msg.junction.push_back(from_json_ApollohdmapJunction(element));
                }
            }
            else
            {
                msg.junction.push_back(from_json_ApollohdmapJunction(obj["junction"]));
            }
        }
        if(obj.contains("lane"))
        {
            if(obj["lane"].is_array())
            {
                for (auto& element : obj["lane"])
                {
                    msg.lane.push_back(from_json_ApollohdmapLane(element));
                }
            }
            else
            {
                msg.lane.push_back(from_json_ApollohdmapLane(obj["lane"]));
            }
        }
        if(obj.contains("stopsign"))
        {
            if(obj["stopsign"].is_array())
            {
                for (auto& element : obj["stopsign"])
                {
                    msg.stopsign.push_back(from_json_ApollohdmapStopSign(element));
                }
            }
            else
            {
                msg.stopsign.push_back(from_json_ApollohdmapStopSign(obj["stopsign"]));
            }
        }
        if(obj.contains("signal"))
        {
            if(obj["signal"].is_array())
            {
                for (auto& element : obj["signal"])
                {
                    msg.signal.push_back(from_json_ApollohdmapSignal(element));
                }
            }
            else
            {
                msg.signal.push_back(from_json_ApollohdmapSignal(obj["signal"]));
            }
        }
        if(obj.contains("yieldd"))
        {
            if(obj["yieldd"].is_array())
            {
                for (auto& element : obj["yieldd"])
                {
                    msg.yieldd.push_back(from_json_ApollohdmapYieldSign(element));
                }
            }
            else
            {
                msg.yieldd.push_back(from_json_ApollohdmapYieldSign(obj["yieldd"]));
            }
        }
        if(obj.contains("overlap"))
        {
            if(obj["overlap"].is_array())
            {
                for (auto& element : obj["overlap"])
                {
                    msg.overlap.push_back(from_json_ApollohdmapOverlap(element));
                }
            }
            else
            {
                msg.overlap.push_back(from_json_ApollohdmapOverlap(obj["overlap"]));
            }
        }
        if(obj.contains("cleararea"))
        {
            if(obj["cleararea"].is_array())
            {
                for (auto& element : obj["cleararea"])
                {
                    msg.cleararea.push_back(from_json_ApollohdmapClearArea(element));
                }
            }
            else
            {
                msg.cleararea.push_back(from_json_ApollohdmapClearArea(obj["cleararea"]));
            }
        }
        if(obj.contains("speedbump"))
        {
            if(obj["speedbump"].is_array())
            {
                for (auto& element : obj["speedbump"])
                {
                    msg.speedbump.push_back(from_json_ApollohdmapSpeedBump(element));
                }
            }
            else
            {
                msg.speedbump.push_back(from_json_ApollohdmapSpeedBump(obj["speedbump"]));
            }
        }
        if(obj.contains("road"))
        {
            if(obj["road"].is_array())
            {
                for (auto& element : obj["road"])
                {
                    msg.road.push_back(from_json_ApollohdmapRoad(element));
                }
            }
            else
            {
                msg.road.push_back(from_json_ApollohdmapRoad(obj["road"]));
            }
        }
        if(obj.contains("parkingspace"))
        {
            if(obj["parkingspace"].is_array())
            {
                for (auto& element : obj["parkingspace"])
                {
                    msg.parkingspace.push_back(from_json_ApollohdmapParkingSpace(element));
                }
            }
            else
            {
                msg.parkingspace.push_back(from_json_ApollohdmapParkingSpace(obj["parkingspace"]));
            }
        }
        if(obj.contains("pncjunction"))
        {
            if(obj["pncjunction"].is_array())
            {
                for (auto& element : obj["pncjunction"])
                {
                    msg.pncjunction.push_back(from_json_ApollohdmapPNCJunction(element));
                }
            }
            else
            {
                msg.pncjunction.push_back(from_json_ApollohdmapPNCJunction(obj["pncjunction"]));
            }
        }
        if(obj.contains("rsu"))
        {
            if(obj["rsu"].is_array())
            {
                for (auto& element : obj["rsu"])
                {
                    msg.rsu.push_back(from_json_ApollohdmapRSU(element));
                }
            }
            else
            {
                msg.rsu.push_back(from_json_ApollohdmapRSU(obj["rsu"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapMap from_json<ApollohdmapMap>(nlohmann::json obj){
        return from_json_ApollohdmapMap(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapMap &dt)
    {
        dt=from_json_ApollohdmapMap(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapMap & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapMap & dt)
    {
        os << to_json(dt);
        return os;
    }
}
