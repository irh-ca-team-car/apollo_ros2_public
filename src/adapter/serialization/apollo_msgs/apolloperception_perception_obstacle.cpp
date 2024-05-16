#include "adapter/serialization/apollo_msgs/apolloperception_perception_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionPerceptionObstacle &msg) {
        nlohmann::json obj;
        obj["id"] = (msg.id);
        obj["position"] = to_json(msg.position);
        obj["theta"] = (msg.theta);
        obj["velocity"] = to_json(msg.velocity);
        obj["length"] = (msg.length);
        obj["width"] = (msg.width);
        obj["height"] = (msg.height);
        nlohmann::json arr_polygonpoint;
        for (auto it = msg.polygonpoint.begin(); it != msg.polygonpoint.end(); ++it) {
            arr_polygonpoint.push_back(to_json(*it));
        }
        obj["polygonpoint"] = arr_polygonpoint;
        obj["trackingtime"] = (msg.trackingtime);
        obj["type"] = (msg.type);
        obj["timestamp"] = (msg.timestamp);
        nlohmann::json arr_pointcloud;
        for (auto it = msg.pointcloud.begin(); it != msg.pointcloud.end(); ++it) {
            arr_pointcloud.push_back((*it));
        }
        obj["pointcloud"] = arr_pointcloud;
        obj["confidence"] = (msg.confidence);
        obj["confidencetype"] = (msg.confidencetype);
        nlohmann::json arr_drops;
        for (auto it = msg.drops.begin(); it != msg.drops.end(); ++it) {
            arr_drops.push_back(to_json(*it));
        }
        obj["drops"] = arr_drops;
        obj["acceleration"] = to_json(msg.acceleration);
        obj["anchorpoint"] = to_json(msg.anchorpoint);
        obj["bbox2d"] = to_json(msg.bbox2d);
        obj["subtype"] = (msg.subtype);
        nlohmann::json arr_measurements;
        for (auto it = msg.measurements.begin(); it != msg.measurements.end(); ++it) {
            arr_measurements.push_back(to_json(*it));
        }
        obj["measurements"] = arr_measurements;
        obj["heightaboveground"] = (msg.heightaboveground);
        nlohmann::json arr_positioncovariance;
        for (auto it = msg.positioncovariance.begin(); it != msg.positioncovariance.end(); ++it) {
            arr_positioncovariance.push_back((*it));
        }
        obj["positioncovariance"] = arr_positioncovariance;
        nlohmann::json arr_velocitycovariance;
        for (auto it = msg.velocitycovariance.begin(); it != msg.velocitycovariance.end(); ++it) {
            arr_velocitycovariance.push_back((*it));
        }
        obj["velocitycovariance"] = arr_velocitycovariance;
        nlohmann::json arr_accelerationcovariance;
        for (auto it = msg.accelerationcovariance.begin(); it != msg.accelerationcovariance.end(); ++it) {
            arr_accelerationcovariance.push_back((*it));
        }
        obj["accelerationcovariance"] = arr_accelerationcovariance;
        obj["lightstatus"] = to_json(msg.lightstatus);
        obj["msg"] = to_json(msg.msg);
        obj["source"] = (msg.source);
        obj["v2xinfo"] = to_json(msg.v2xinfo);
        return obj;
    }
    ApolloperceptionPerceptionObstacle from_json_ApolloperceptionPerceptionObstacle (nlohmann::json obj) {
        ApolloperceptionPerceptionObstacle msg;
        if(obj.contains("id"))
        {
            msg.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPoint3D(obj["position"]);
        }
        if(obj.contains("theta"))
        {
            msg.theta = (obj["theta"].is_string()?atof(obj["theta"].get<std::string>().c_str()):obj["theta"].get<double>());
        }
        if(obj.contains("velocity"))
        {
            msg.velocity = from_json_ApollocommonPoint3D(obj["velocity"]);
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
        if(obj.contains("trackingtime"))
        {
            msg.trackingtime = (obj["trackingtime"].is_string()?atof(obj["trackingtime"].get<std::string>().c_str()):obj["trackingtime"].get<double>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("pointcloud"))
        {
            if(obj["pointcloud"].is_array())
            {
                for (auto& element : obj["pointcloud"])
                {
                    msg.pointcloud.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.pointcloud.push_back((obj["pointcloud"].is_string()?atof(obj["pointcloud"].get<std::string>().c_str()):obj["pointcloud"].get<double>()));
            }
        }
        if(obj.contains("confidence"))
        {
            msg.confidence = (obj["confidence"].is_string()?atof(obj["confidence"].get<std::string>().c_str()):obj["confidence"].get<double>());
        }
        if(obj.contains("confidencetype"))
        {
            msg.confidencetype = (obj["confidencetype"].is_string()?atoi(obj["confidencetype"].get<std::string>().c_str()):obj["confidencetype"].get<int>());
        }
        if(obj.contains("drops"))
        {
            if(obj["drops"].is_array())
            {
                for (auto& element : obj["drops"])
                {
                    msg.drops.push_back(from_json_ApollocommonPoint3D(element));
                }
            }
            else
            {
                msg.drops.push_back(from_json_ApollocommonPoint3D(obj["drops"]));
            }
        }
        if(obj.contains("acceleration"))
        {
            msg.acceleration = from_json_ApollocommonPoint3D(obj["acceleration"]);
        }
        if(obj.contains("anchorpoint"))
        {
            msg.anchorpoint = from_json_ApollocommonPoint3D(obj["anchorpoint"]);
        }
        if(obj.contains("bbox2d"))
        {
            msg.bbox2d = from_json_ApolloperceptionBBox2D(obj["bbox2d"]);
        }
        if(obj.contains("subtype"))
        {
            msg.subtype = (obj["subtype"].is_string()?atoi(obj["subtype"].get<std::string>().c_str()):obj["subtype"].get<int>());
        }
        if(obj.contains("measurements"))
        {
            if(obj["measurements"].is_array())
            {
                for (auto& element : obj["measurements"])
                {
                    msg.measurements.push_back(from_json_ApolloperceptionSensorMeasurement(element));
                }
            }
            else
            {
                msg.measurements.push_back(from_json_ApolloperceptionSensorMeasurement(obj["measurements"]));
            }
        }
        if(obj.contains("heightaboveground"))
        {
            msg.heightaboveground = (obj["heightaboveground"].is_string()?atof(obj["heightaboveground"].get<std::string>().c_str()):obj["heightaboveground"].get<double>());
        }
        if(obj.contains("positioncovariance"))
        {
            if(obj["positioncovariance"].is_array())
            {
                for (auto& element : obj["positioncovariance"])
                {
                    msg.positioncovariance.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.positioncovariance.push_back((obj["positioncovariance"].is_string()?atof(obj["positioncovariance"].get<std::string>().c_str()):obj["positioncovariance"].get<double>()));
            }
        }
        if(obj.contains("velocitycovariance"))
        {
            if(obj["velocitycovariance"].is_array())
            {
                for (auto& element : obj["velocitycovariance"])
                {
                    msg.velocitycovariance.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.velocitycovariance.push_back((obj["velocitycovariance"].is_string()?atof(obj["velocitycovariance"].get<std::string>().c_str()):obj["velocitycovariance"].get<double>()));
            }
        }
        if(obj.contains("accelerationcovariance"))
        {
            if(obj["accelerationcovariance"].is_array())
            {
                for (auto& element : obj["accelerationcovariance"])
                {
                    msg.accelerationcovariance.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.accelerationcovariance.push_back((obj["accelerationcovariance"].is_string()?atof(obj["accelerationcovariance"].get<std::string>().c_str()):obj["accelerationcovariance"].get<double>()));
            }
        }
        if(obj.contains("lightstatus"))
        {
            msg.lightstatus = from_json_ApolloperceptionLightStatus(obj["lightstatus"]);
        }
        if(obj.contains("msg"))
        {
            msg.msg = from_json_ApolloperceptionDebugMessage(obj["msg"]);
        }
        if(obj.contains("source"))
        {
            msg.source = (obj["source"].is_string()?atoi(obj["source"].get<std::string>().c_str()):obj["source"].get<int>());
        }
        if(obj.contains("v2xinfo"))
        {
            msg.v2xinfo = from_json_ApolloperceptionV2XInformation(obj["v2xinfo"]);
        }
        return msg;
    }
    template <>
    ApolloperceptionPerceptionObstacle from_json<ApolloperceptionPerceptionObstacle>(nlohmann::json obj){
        return from_json_ApolloperceptionPerceptionObstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionPerceptionObstacle &dt)
    {
        dt=from_json_ApolloperceptionPerceptionObstacle(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionPerceptionObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionPerceptionObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
}
