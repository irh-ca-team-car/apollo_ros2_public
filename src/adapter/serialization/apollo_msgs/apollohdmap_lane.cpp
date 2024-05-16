#include "adapter/serialization/apollo_msgs/apollohdmap_lane.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollohdmapLane &msg) {
        nlohmann::json obj;
        obj["id"] = to_json(msg.id);
        obj["centralcurve"] = to_json(msg.centralcurve);
        obj["leftboundary"] = to_json(msg.leftboundary);
        obj["rightboundary"] = to_json(msg.rightboundary);
        obj["length"] = (msg.length);
        obj["speedlimit"] = (msg.speedlimit);
        nlohmann::json arr_overlapid;
        for (auto it = msg.overlapid.begin(); it != msg.overlapid.end(); ++it) {
            arr_overlapid.push_back(to_json(*it));
        }
        obj["overlapid"] = arr_overlapid;
        nlohmann::json arr_predecessorid;
        for (auto it = msg.predecessorid.begin(); it != msg.predecessorid.end(); ++it) {
            arr_predecessorid.push_back(to_json(*it));
        }
        obj["predecessorid"] = arr_predecessorid;
        nlohmann::json arr_successorid;
        for (auto it = msg.successorid.begin(); it != msg.successorid.end(); ++it) {
            arr_successorid.push_back(to_json(*it));
        }
        obj["successorid"] = arr_successorid;
        nlohmann::json arr_leftneighborforwardlaneid;
        for (auto it = msg.leftneighborforwardlaneid.begin(); it != msg.leftneighborforwardlaneid.end(); ++it) {
            arr_leftneighborforwardlaneid.push_back(to_json(*it));
        }
        obj["leftneighborforwardlaneid"] = arr_leftneighborforwardlaneid;
        nlohmann::json arr_rightneighborforwardlaneid;
        for (auto it = msg.rightneighborforwardlaneid.begin(); it != msg.rightneighborforwardlaneid.end(); ++it) {
            arr_rightneighborforwardlaneid.push_back(to_json(*it));
        }
        obj["rightneighborforwardlaneid"] = arr_rightneighborforwardlaneid;
        obj["type"] = (msg.type);
        obj["turn"] = (msg.turn);
        nlohmann::json arr_leftneighborreverselaneid;
        for (auto it = msg.leftneighborreverselaneid.begin(); it != msg.leftneighborreverselaneid.end(); ++it) {
            arr_leftneighborreverselaneid.push_back(to_json(*it));
        }
        obj["leftneighborreverselaneid"] = arr_leftneighborreverselaneid;
        nlohmann::json arr_rightneighborreverselaneid;
        for (auto it = msg.rightneighborreverselaneid.begin(); it != msg.rightneighborreverselaneid.end(); ++it) {
            arr_rightneighborreverselaneid.push_back(to_json(*it));
        }
        obj["rightneighborreverselaneid"] = arr_rightneighborreverselaneid;
        obj["junctionid"] = to_json(msg.junctionid);
        nlohmann::json arr_leftsample;
        for (auto it = msg.leftsample.begin(); it != msg.leftsample.end(); ++it) {
            arr_leftsample.push_back(to_json(*it));
        }
        obj["leftsample"] = arr_leftsample;
        nlohmann::json arr_rightsample;
        for (auto it = msg.rightsample.begin(); it != msg.rightsample.end(); ++it) {
            arr_rightsample.push_back(to_json(*it));
        }
        obj["rightsample"] = arr_rightsample;
        obj["direction"] = (msg.direction);
        nlohmann::json arr_leftroadsample;
        for (auto it = msg.leftroadsample.begin(); it != msg.leftroadsample.end(); ++it) {
            arr_leftroadsample.push_back(to_json(*it));
        }
        obj["leftroadsample"] = arr_leftroadsample;
        nlohmann::json arr_rightroadsample;
        for (auto it = msg.rightroadsample.begin(); it != msg.rightroadsample.end(); ++it) {
            arr_rightroadsample.push_back(to_json(*it));
        }
        obj["rightroadsample"] = arr_rightroadsample;
        nlohmann::json arr_selfreverselaneid;
        for (auto it = msg.selfreverselaneid.begin(); it != msg.selfreverselaneid.end(); ++it) {
            arr_selfreverselaneid.push_back(to_json(*it));
        }
        obj["selfreverselaneid"] = arr_selfreverselaneid;
        return obj;
    }
    ApollohdmapLane from_json_ApollohdmapLane (nlohmann::json obj) {
        ApollohdmapLane msg;
        if(obj.contains("id"))
        {
            msg.id = from_json_ApollohdmapId(obj["id"]);
        }
        if(obj.contains("centralcurve"))
        {
            msg.centralcurve = from_json_ApollohdmapCurve(obj["centralcurve"]);
        }
        if(obj.contains("leftboundary"))
        {
            msg.leftboundary = from_json_ApollohdmapLaneBoundary(obj["leftboundary"]);
        }
        if(obj.contains("rightboundary"))
        {
            msg.rightboundary = from_json_ApollohdmapLaneBoundary(obj["rightboundary"]);
        }
        if(obj.contains("length"))
        {
            msg.length = (obj["length"].is_string()?atof(obj["length"].get<std::string>().c_str()):obj["length"].get<double>());
        }
        if(obj.contains("speedlimit"))
        {
            msg.speedlimit = (obj["speedlimit"].is_string()?atof(obj["speedlimit"].get<std::string>().c_str()):obj["speedlimit"].get<double>());
        }
        if(obj.contains("overlapid"))
        {
            if(obj["overlapid"].is_array())
            {
                for (auto& element : obj["overlapid"])
                {
                    msg.overlapid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.overlapid.push_back(from_json_ApollohdmapId(obj["overlapid"]));
            }
        }
        if(obj.contains("predecessorid"))
        {
            if(obj["predecessorid"].is_array())
            {
                for (auto& element : obj["predecessorid"])
                {
                    msg.predecessorid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.predecessorid.push_back(from_json_ApollohdmapId(obj["predecessorid"]));
            }
        }
        if(obj.contains("successorid"))
        {
            if(obj["successorid"].is_array())
            {
                for (auto& element : obj["successorid"])
                {
                    msg.successorid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.successorid.push_back(from_json_ApollohdmapId(obj["successorid"]));
            }
        }
        if(obj.contains("leftneighborforwardlaneid"))
        {
            if(obj["leftneighborforwardlaneid"].is_array())
            {
                for (auto& element : obj["leftneighborforwardlaneid"])
                {
                    msg.leftneighborforwardlaneid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.leftneighborforwardlaneid.push_back(from_json_ApollohdmapId(obj["leftneighborforwardlaneid"]));
            }
        }
        if(obj.contains("rightneighborforwardlaneid"))
        {
            if(obj["rightneighborforwardlaneid"].is_array())
            {
                for (auto& element : obj["rightneighborforwardlaneid"])
                {
                    msg.rightneighborforwardlaneid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.rightneighborforwardlaneid.push_back(from_json_ApollohdmapId(obj["rightneighborforwardlaneid"]));
            }
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("turn"))
        {
            msg.turn = (obj["turn"].is_string()?atoi(obj["turn"].get<std::string>().c_str()):obj["turn"].get<int>());
        }
        if(obj.contains("leftneighborreverselaneid"))
        {
            if(obj["leftneighborreverselaneid"].is_array())
            {
                for (auto& element : obj["leftneighborreverselaneid"])
                {
                    msg.leftneighborreverselaneid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.leftneighborreverselaneid.push_back(from_json_ApollohdmapId(obj["leftneighborreverselaneid"]));
            }
        }
        if(obj.contains("rightneighborreverselaneid"))
        {
            if(obj["rightneighborreverselaneid"].is_array())
            {
                for (auto& element : obj["rightneighborreverselaneid"])
                {
                    msg.rightneighborreverselaneid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.rightneighborreverselaneid.push_back(from_json_ApollohdmapId(obj["rightneighborreverselaneid"]));
            }
        }
        if(obj.contains("junctionid"))
        {
            msg.junctionid = from_json_ApollohdmapId(obj["junctionid"]);
        }
        if(obj.contains("leftsample"))
        {
            if(obj["leftsample"].is_array())
            {
                for (auto& element : obj["leftsample"])
                {
                    msg.leftsample.push_back(from_json_ApollohdmapLaneSampleAssociation(element));
                }
            }
            else
            {
                msg.leftsample.push_back(from_json_ApollohdmapLaneSampleAssociation(obj["leftsample"]));
            }
        }
        if(obj.contains("rightsample"))
        {
            if(obj["rightsample"].is_array())
            {
                for (auto& element : obj["rightsample"])
                {
                    msg.rightsample.push_back(from_json_ApollohdmapLaneSampleAssociation(element));
                }
            }
            else
            {
                msg.rightsample.push_back(from_json_ApollohdmapLaneSampleAssociation(obj["rightsample"]));
            }
        }
        if(obj.contains("direction"))
        {
            msg.direction = (obj["direction"].is_string()?atoi(obj["direction"].get<std::string>().c_str()):obj["direction"].get<int>());
        }
        if(obj.contains("leftroadsample"))
        {
            if(obj["leftroadsample"].is_array())
            {
                for (auto& element : obj["leftroadsample"])
                {
                    msg.leftroadsample.push_back(from_json_ApollohdmapLaneSampleAssociation(element));
                }
            }
            else
            {
                msg.leftroadsample.push_back(from_json_ApollohdmapLaneSampleAssociation(obj["leftroadsample"]));
            }
        }
        if(obj.contains("rightroadsample"))
        {
            if(obj["rightroadsample"].is_array())
            {
                for (auto& element : obj["rightroadsample"])
                {
                    msg.rightroadsample.push_back(from_json_ApollohdmapLaneSampleAssociation(element));
                }
            }
            else
            {
                msg.rightroadsample.push_back(from_json_ApollohdmapLaneSampleAssociation(obj["rightroadsample"]));
            }
        }
        if(obj.contains("selfreverselaneid"))
        {
            if(obj["selfreverselaneid"].is_array())
            {
                for (auto& element : obj["selfreverselaneid"])
                {
                    msg.selfreverselaneid.push_back(from_json_ApollohdmapId(element));
                }
            }
            else
            {
                msg.selfreverselaneid.push_back(from_json_ApollohdmapId(obj["selfreverselaneid"]));
            }
        }
        return msg;
    }
    template <>
    ApollohdmapLane from_json<ApollohdmapLane>(nlohmann::json obj){
        return from_json_ApollohdmapLane(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollohdmapLane &dt)
    {
        dt=from_json_ApollohdmapLane(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollohdmapLane & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollohdmapLane & dt)
    {
        os << to_json(dt);
        return os;
    }
}
