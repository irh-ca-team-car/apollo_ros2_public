#include "adapter/serialization/apollo_msgs/apolloprediction_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionFeature &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        nlohmann::json arr_polygonpoint;
        for (auto it = msg.polygonpoint.begin(); it != msg.polygonpoint.end(); ++it) {
            arr_polygonpoint.push_back(to_json(*it));
        }
        obj["polygonpoint"] = arr_polygonpoint;
        obj["position"] = to_json(msg.position);
        obj["frontposition"] = to_json(msg.frontposition);
        obj["velocity"] = to_json(msg.velocity);
        obj["rawvelocity"] = to_json(msg.rawvelocity);
        obj["acceleration"] = to_json(msg.acceleration);
        obj["velocityheading"] = (msg.velocityheading);
        obj["speed"] = (msg.speed);
        obj["acc"] = (msg.acc);
        obj["theta"] = (msg.theta);
        obj["length"] = (msg.length);
        obj["width"] = (msg.width);
        obj["height"] = (msg.height);
        obj["trackingtime"] = (msg.trackingtime);
        obj["timestamp"] = (msg.timestamp);
        obj["lane"] = to_json(msg.lane);
        obj["junctionfeature"] = to_json(msg.junctionfeature);
        obj["tposition"] = to_json(msg.tposition);
        obj["tvelocity"] = to_json(msg.tvelocity);
        obj["tvelocityheading"] = (msg.tvelocityheading);
        obj["tspeed"] = (msg.tspeed);
        obj["tacceleration"] = to_json(msg.tacceleration);
        obj["tacc"] = (msg.tacc);
        obj["isstill"] = (msg.isstill);
        obj["type"] = (msg.type);
        obj["labelupdatetimedelta"] = (msg.labelupdatetimedelta);
        obj["priority"] = to_json(msg.priority);
        obj["isnearjunction"] = (msg.isnearjunction);
        nlohmann::json arr_futuretrajectorypoints;
        for (auto it = msg.futuretrajectorypoints.begin(); it != msg.futuretrajectorypoints.end(); ++it) {
            arr_futuretrajectorypoints.push_back(to_json(*it));
        }
        obj["futuretrajectorypoints"] = arr_futuretrajectorypoints;
        nlohmann::json arr_shorttermpredictedtrajectorypoints;
        for (auto it = msg.shorttermpredictedtrajectorypoints.begin(); it != msg.shorttermpredictedtrajectorypoints.end(); ++it) {
            arr_shorttermpredictedtrajectorypoints.push_back(to_json(*it));
        }
        obj["shorttermpredictedtrajectorypoints"] = arr_shorttermpredictedtrajectorypoints;
        nlohmann::json arr_predictedtrajectory;
        for (auto it = msg.predictedtrajectory.begin(); it != msg.predictedtrajectory.end(); ++it) {
            arr_predictedtrajectory.push_back(to_json(*it));
        }
        obj["predictedtrajectory"] = arr_predictedtrajectory;
        nlohmann::json arr_adctrajectorypoint;
        for (auto it = msg.adctrajectorypoint.begin(); it != msg.adctrajectorypoint.end(); ++it) {
            arr_adctrajectorypoint.push_back(to_json(*it));
        }
        obj["adctrajectorypoint"] = arr_adctrajectorypoint;
        nlohmann::json arr_surroundinglaneid;
        for (auto it = msg.surroundinglaneid.begin(); it != msg.surroundinglaneid.end(); ++it) {
            arr_surroundinglaneid.push_back((*it));
        }
        obj["surroundinglaneid"] = arr_surroundinglaneid;
        nlohmann::json arr_withinlaneid;
        for (auto it = msg.withinlaneid.begin(); it != msg.withinlaneid.end(); ++it) {
            arr_withinlaneid.push_back((*it));
        }
        obj["withinlaneid"] = arr_withinlaneid;
        return obj;
    }
    ApollopredictionFeature from_json_ApollopredictionFeature (nlohmann::json obj) {
        ApollopredictionFeature msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("polygonpoint"))
        {
            if(obj["polygonpoint"].is_array())
            {
                for (auto& element : obj["polygonpoint"])
                {
                    msg.polygonpoint.push_back(from_json_ApollocommonPoint3D(element));
                }
            }
            else
            {
                msg.polygonpoint.push_back(from_json_ApollocommonPoint3D(obj["polygonpoint"]));
            }
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPoint3D(obj["position"]);
        }
        if(obj.contains("frontposition"))
        {
            msg.frontposition = from_json_ApollocommonPoint3D(obj["frontposition"]);
        }
        if(obj.contains("velocity"))
        {
            msg.velocity = from_json_ApollocommonPoint3D(obj["velocity"]);
        }
        if(obj.contains("rawvelocity"))
        {
            msg.rawvelocity = from_json_ApollocommonPoint3D(obj["rawvelocity"]);
        }
        if(obj.contains("acceleration"))
        {
            msg.acceleration = from_json_ApollocommonPoint3D(obj["acceleration"]);
        }
        if(obj.contains("velocityheading"))
        {
            msg.velocityheading = (obj["velocityheading"].is_string()?atof(obj["velocityheading"].get<std::string>().c_str()):obj["velocityheading"].get<double>());
        }
        if(obj.contains("speed"))
        {
            msg.speed = (obj["speed"].is_string()?atof(obj["speed"].get<std::string>().c_str()):obj["speed"].get<double>());
        }
        if(obj.contains("acc"))
        {
            msg.acc = (obj["acc"].is_string()?atof(obj["acc"].get<std::string>().c_str()):obj["acc"].get<double>());
        }
        if(obj.contains("theta"))
        {
            msg.theta = (obj["theta"].is_string()?atof(obj["theta"].get<std::string>().c_str()):obj["theta"].get<double>());
        }
        if(obj.contains("length"))
        {
            msg.length = (obj["length"].is_string()?atof(obj["length"].get<std::string>().c_str()):obj["length"].get<double>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atof(obj["width"].get<std::string>().c_str()):obj["width"].get<double>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atof(obj["height"].get<std::string>().c_str()):obj["height"].get<double>());
        }
        if(obj.contains("trackingtime"))
        {
            msg.trackingtime = (obj["trackingtime"].is_string()?atof(obj["trackingtime"].get<std::string>().c_str()):obj["trackingtime"].get<double>());
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("lane"))
        {
            msg.lane = from_json_ApollopredictionLane(obj["lane"]);
        }
        if(obj.contains("junctionfeature"))
        {
            msg.junctionfeature = from_json_ApollopredictionJunctionFeature(obj["junctionfeature"]);
        }
        if(obj.contains("tposition"))
        {
            msg.tposition = from_json_ApollocommonPoint3D(obj["tposition"]);
        }
        if(obj.contains("tvelocity"))
        {
            msg.tvelocity = from_json_ApollocommonPoint3D(obj["tvelocity"]);
        }
        if(obj.contains("tvelocityheading"))
        {
            msg.tvelocityheading = (obj["tvelocityheading"].is_string()?atof(obj["tvelocityheading"].get<std::string>().c_str()):obj["tvelocityheading"].get<double>());
        }
        if(obj.contains("tspeed"))
        {
            msg.tspeed = (obj["tspeed"].is_string()?atof(obj["tspeed"].get<std::string>().c_str()):obj["tspeed"].get<double>());
        }
        if(obj.contains("tacceleration"))
        {
            msg.tacceleration = from_json_ApollocommonPoint3D(obj["tacceleration"]);
        }
        if(obj.contains("tacc"))
        {
            msg.tacc = (obj["tacc"].is_string()?atof(obj["tacc"].get<std::string>().c_str()):obj["tacc"].get<double>());
        }
        if(obj.contains("isstill"))
        {
            msg.isstill = (obj["isstill"].is_string()?(bool)atoi(obj["isstill"].get<std::string>().c_str()):obj["isstill"].get<bool>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("labelupdatetimedelta"))
        {
            msg.labelupdatetimedelta = (obj["labelupdatetimedelta"].is_string()?atof(obj["labelupdatetimedelta"].get<std::string>().c_str()):obj["labelupdatetimedelta"].get<double>());
        }
        if(obj.contains("priority"))
        {
            msg.priority = from_json_ApollopredictionObstaclePriority(obj["priority"]);
        }
        if(obj.contains("isnearjunction"))
        {
            msg.isnearjunction = (obj["isnearjunction"].is_string()?(bool)atoi(obj["isnearjunction"].get<std::string>().c_str()):obj["isnearjunction"].get<bool>());
        }
        if(obj.contains("futuretrajectorypoints"))
        {
            if(obj["futuretrajectorypoints"].is_array())
            {
                for (auto& element : obj["futuretrajectorypoints"])
                {
                    msg.futuretrajectorypoints.push_back(from_json_ApollopredictionPredictionTrajectoryPoint(element));
                }
            }
            else
            {
                msg.futuretrajectorypoints.push_back(from_json_ApollopredictionPredictionTrajectoryPoint(obj["futuretrajectorypoints"]));
            }
        }
        if(obj.contains("shorttermpredictedtrajectorypoints"))
        {
            if(obj["shorttermpredictedtrajectorypoints"].is_array())
            {
                for (auto& element : obj["shorttermpredictedtrajectorypoints"])
                {
                    msg.shorttermpredictedtrajectorypoints.push_back(from_json_ApollocommonTrajectoryPoint(element));
                }
            }
            else
            {
                msg.shorttermpredictedtrajectorypoints.push_back(from_json_ApollocommonTrajectoryPoint(obj["shorttermpredictedtrajectorypoints"]));
            }
        }
        if(obj.contains("predictedtrajectory"))
        {
            if(obj["predictedtrajectory"].is_array())
            {
                for (auto& element : obj["predictedtrajectory"])
                {
                    msg.predictedtrajectory.push_back(from_json_ApollopredictionTrajectory(element));
                }
            }
            else
            {
                msg.predictedtrajectory.push_back(from_json_ApollopredictionTrajectory(obj["predictedtrajectory"]));
            }
        }
        if(obj.contains("adctrajectorypoint"))
        {
            if(obj["adctrajectorypoint"].is_array())
            {
                for (auto& element : obj["adctrajectorypoint"])
                {
                    msg.adctrajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(element));
                }
            }
            else
            {
                msg.adctrajectorypoint.push_back(from_json_ApollocommonTrajectoryPoint(obj["adctrajectorypoint"]));
            }
        }
        if(obj.contains("surroundinglaneid"))
        {
            if(obj["surroundinglaneid"].is_array())
            {
                for (auto& element : obj["surroundinglaneid"])
                {
                    msg.surroundinglaneid.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.surroundinglaneid.push_back((obj["surroundinglaneid"].is_string()?(obj["surroundinglaneid"].get<std::string>().c_str()):obj["surroundinglaneid"].get<std::string>()));
            }
        }
        if(obj.contains("withinlaneid"))
        {
            if(obj["withinlaneid"].is_array())
            {
                for (auto& element : obj["withinlaneid"])
                {
                    msg.withinlaneid.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.withinlaneid.push_back((obj["withinlaneid"].is_string()?(obj["withinlaneid"].get<std::string>().c_str()):obj["withinlaneid"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionFeature from_json<ApollopredictionFeature>(nlohmann::json obj){
        return from_json_ApollopredictionFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionFeature &dt)
    {
        dt=from_json_ApollopredictionFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
