#include "adapter/serialization/apollo_msgs/apolloprediction_lane_sequence.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLaneSequence &msg) {
        nlohmann::json obj;
        obj["lanesequenceid"] = (msg.lanesequenceid);
        nlohmann::json arr_lanesegment;
        for (auto it = msg.lanesegment.begin(); it != msg.lanesegment.end(); ++it) {
            arr_lanesegment.push_back(to_json(*it));
        }
        obj["lanesegment"] = arr_lanesegment;
        obj["adclanesegmentidx"] = (msg.adclanesegmentidx);
        nlohmann::json arr_pathpoint;
        for (auto it = msg.pathpoint.begin(); it != msg.pathpoint.end(); ++it) {
            arr_pathpoint.push_back(to_json(*it));
        }
        obj["pathpoint"] = arr_pathpoint;
        obj["lanetype"] = (msg.lanetype);
        obj["lanes"] = (msg.lanes);
        obj["lanel"] = (msg.lanel);
        obj["vehicleonlane"] = (msg.vehicleonlane);
        nlohmann::json arr_nearbyobstacle;
        for (auto it = msg.nearbyobstacle.begin(); it != msg.nearbyobstacle.end(); ++it) {
            arr_nearbyobstacle.push_back(to_json(*it));
        }
        obj["nearbyobstacle"] = arr_nearbyobstacle;
        obj["stopsign"] = to_json(msg.stopsign);
        obj["rightofway"] = (msg.rightofway);
        obj["features"] = to_json(msg.features);
        obj["label"] = (msg.label);
        obj["probability"] = (msg.probability);
        obj["acceleration"] = (msg.acceleration);
        obj["timetolanecenter"] = (msg.timetolanecenter);
        obj["timetolaneedge"] = (msg.timetolaneedge);
        obj["behaviortype"] = (msg.behaviortype);
        nlohmann::json arr_currlanepoint;
        for (auto it = msg.currlanepoint.begin(); it != msg.currlanepoint.end(); ++it) {
            arr_currlanepoint.push_back(to_json(*it));
        }
        obj["currlanepoint"] = arr_currlanepoint;
        nlohmann::json arr_leftneighborpoint;
        for (auto it = msg.leftneighborpoint.begin(); it != msg.leftneighborpoint.end(); ++it) {
            arr_leftneighborpoint.push_back(to_json(*it));
        }
        obj["leftneighborpoint"] = arr_leftneighborpoint;
        nlohmann::json arr_rightneighborpoint;
        for (auto it = msg.rightneighborpoint.begin(); it != msg.rightneighborpoint.end(); ++it) {
            arr_rightneighborpoint.push_back(to_json(*it));
        }
        obj["rightneighborpoint"] = arr_rightneighborpoint;
        nlohmann::json arr_leftnearbyobstacle;
        for (auto it = msg.leftnearbyobstacle.begin(); it != msg.leftnearbyobstacle.end(); ++it) {
            arr_leftnearbyobstacle.push_back(to_json(*it));
        }
        obj["leftnearbyobstacle"] = arr_leftnearbyobstacle;
        nlohmann::json arr_rightnearbyobstacle;
        for (auto it = msg.rightnearbyobstacle.begin(); it != msg.rightnearbyobstacle.end(); ++it) {
            arr_rightnearbyobstacle.push_back(to_json(*it));
        }
        obj["rightnearbyobstacle"] = arr_rightnearbyobstacle;
        return obj;
    }
    ApollopredictionLaneSequence from_json_ApollopredictionLaneSequence (nlohmann::json obj) {
        ApollopredictionLaneSequence msg;
        if(obj.contains("lanesequenceid"))
        {
            msg.lanesequenceid = (obj["lanesequenceid"].is_string()?atoi(obj["lanesequenceid"].get<std::string>().c_str()):obj["lanesequenceid"].get<int>());
        }
        if(obj.contains("lanesegment"))
        {
            if(obj["lanesegment"].is_array())
            {
                for (auto& element : obj["lanesegment"])
                {
                    msg.lanesegment.push_back(from_json_ApollopredictionLaneSegment(element));
                }
            }
            else
            {
                msg.lanesegment.push_back(from_json_ApollopredictionLaneSegment(obj["lanesegment"]));
            }
        }
        if(obj.contains("adclanesegmentidx"))
        {
            msg.adclanesegmentidx = (obj["adclanesegmentidx"].is_string()?atoi(obj["adclanesegmentidx"].get<std::string>().c_str()):obj["adclanesegmentidx"].get<int>());
        }
        if(obj.contains("pathpoint"))
        {
            if(obj["pathpoint"].is_array())
            {
                for (auto& element : obj["pathpoint"])
                {
                    msg.pathpoint.push_back(from_json_ApollocommonPathPoint(element));
                }
            }
            else
            {
                msg.pathpoint.push_back(from_json_ApollocommonPathPoint(obj["pathpoint"]));
            }
        }
        if(obj.contains("lanetype"))
        {
            msg.lanetype = (obj["lanetype"].is_string()?atoi(obj["lanetype"].get<std::string>().c_str()):obj["lanetype"].get<int>());
        }
        if(obj.contains("lanes"))
        {
            msg.lanes = (obj["lanes"].is_string()?atof(obj["lanes"].get<std::string>().c_str()):obj["lanes"].get<double>());
        }
        if(obj.contains("lanel"))
        {
            msg.lanel = (obj["lanel"].is_string()?atof(obj["lanel"].get<std::string>().c_str()):obj["lanel"].get<double>());
        }
        if(obj.contains("vehicleonlane"))
        {
            msg.vehicleonlane = (obj["vehicleonlane"].is_string()?(bool)atoi(obj["vehicleonlane"].get<std::string>().c_str()):obj["vehicleonlane"].get<bool>());
        }
        if(obj.contains("nearbyobstacle"))
        {
            if(obj["nearbyobstacle"].is_array())
            {
                for (auto& element : obj["nearbyobstacle"])
                {
                    msg.nearbyobstacle.push_back(from_json_ApollopredictionNearbyObstacle(element));
                }
            }
            else
            {
                msg.nearbyobstacle.push_back(from_json_ApollopredictionNearbyObstacle(obj["nearbyobstacle"]));
            }
        }
        if(obj.contains("stopsign"))
        {
            msg.stopsign = from_json_ApollopredictionStopSign(obj["stopsign"]);
        }
        if(obj.contains("rightofway"))
        {
            msg.rightofway = (obj["rightofway"].is_string()?atoi(obj["rightofway"].get<std::string>().c_str()):obj["rightofway"].get<int>());
        }
        if(obj.contains("features"))
        {
            msg.features = from_json_ApollopredictionLaneSequenceFeatures(obj["features"]);
        }
        if(obj.contains("label"))
        {
            msg.label = (obj["label"].is_string()?atoi(obj["label"].get<std::string>().c_str()):obj["label"].get<int>());
        }
        if(obj.contains("probability"))
        {
            msg.probability = (obj["probability"].is_string()?atof(obj["probability"].get<std::string>().c_str()):obj["probability"].get<double>());
        }
        if(obj.contains("acceleration"))
        {
            msg.acceleration = (obj["acceleration"].is_string()?atof(obj["acceleration"].get<std::string>().c_str()):obj["acceleration"].get<double>());
        }
        if(obj.contains("timetolanecenter"))
        {
            msg.timetolanecenter = (obj["timetolanecenter"].is_string()?atof(obj["timetolanecenter"].get<std::string>().c_str()):obj["timetolanecenter"].get<double>());
        }
        if(obj.contains("timetolaneedge"))
        {
            msg.timetolaneedge = (obj["timetolaneedge"].is_string()?atof(obj["timetolaneedge"].get<std::string>().c_str()):obj["timetolaneedge"].get<double>());
        }
        if(obj.contains("behaviortype"))
        {
            msg.behaviortype = (obj["behaviortype"].is_string()?atoi(obj["behaviortype"].get<std::string>().c_str()):obj["behaviortype"].get<int>());
        }
        if(obj.contains("currlanepoint"))
        {
            if(obj["currlanepoint"].is_array())
            {
                for (auto& element : obj["currlanepoint"])
                {
                    msg.currlanepoint.push_back(from_json_ApollopredictionLanePoint(element));
                }
            }
            else
            {
                msg.currlanepoint.push_back(from_json_ApollopredictionLanePoint(obj["currlanepoint"]));
            }
        }
        if(obj.contains("leftneighborpoint"))
        {
            if(obj["leftneighborpoint"].is_array())
            {
                for (auto& element : obj["leftneighborpoint"])
                {
                    msg.leftneighborpoint.push_back(from_json_ApollopredictionLanePoint(element));
                }
            }
            else
            {
                msg.leftneighborpoint.push_back(from_json_ApollopredictionLanePoint(obj["leftneighborpoint"]));
            }
        }
        if(obj.contains("rightneighborpoint"))
        {
            if(obj["rightneighborpoint"].is_array())
            {
                for (auto& element : obj["rightneighborpoint"])
                {
                    msg.rightneighborpoint.push_back(from_json_ApollopredictionLanePoint(element));
                }
            }
            else
            {
                msg.rightneighborpoint.push_back(from_json_ApollopredictionLanePoint(obj["rightneighborpoint"]));
            }
        }
        if(obj.contains("leftnearbyobstacle"))
        {
            if(obj["leftnearbyobstacle"].is_array())
            {
                for (auto& element : obj["leftnearbyobstacle"])
                {
                    msg.leftnearbyobstacle.push_back(from_json_ApollopredictionNearbyObstacle(element));
                }
            }
            else
            {
                msg.leftnearbyobstacle.push_back(from_json_ApollopredictionNearbyObstacle(obj["leftnearbyobstacle"]));
            }
        }
        if(obj.contains("rightnearbyobstacle"))
        {
            if(obj["rightnearbyobstacle"].is_array())
            {
                for (auto& element : obj["rightnearbyobstacle"])
                {
                    msg.rightnearbyobstacle.push_back(from_json_ApollopredictionNearbyObstacle(element));
                }
            }
            else
            {
                msg.rightnearbyobstacle.push_back(from_json_ApollopredictionNearbyObstacle(obj["rightnearbyobstacle"]));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionLaneSequence from_json<ApollopredictionLaneSequence>(nlohmann::json obj){
        return from_json_ApollopredictionLaneSequence(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLaneSequence &dt)
    {
        dt=from_json_ApollopredictionLaneSequence(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLaneSequence & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLaneSequence & dt)
    {
        os << to_json(dt);
        return os;
    }
}
