#include "adapter/serialization/apollo_msgs/apolloperception_sensor_measurement.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptionSensorMeasurement &msg) {
        nlohmann::json obj;
        obj["sensorid"] = (msg.sensorid);
        obj["id"] = (msg.id);
        obj["position"] = to_json(msg.position);
        obj["theta"] = (msg.theta);
        obj["length"] = (msg.length);
        obj["width"] = (msg.width);
        obj["height"] = (msg.height);
        obj["velocity"] = to_json(msg.velocity);
        obj["type"] = (msg.type);
        obj["subtype"] = (msg.subtype);
        obj["timestamp"] = (msg.timestamp);
        obj["box"] = to_json(msg.box);
        return obj;
    }
    ApolloperceptionSensorMeasurement from_json_ApolloperceptionSensorMeasurement (nlohmann::json obj) {
        ApolloperceptionSensorMeasurement msg;
        if(obj.contains("sensorid"))
        {
            msg.sensorid = (obj["sensorid"].is_string()?(obj["sensorid"].get<std::string>().c_str()):obj["sensorid"].get<std::string>());
        }
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
        if(obj.contains("velocity"))
        {
            msg.velocity = from_json_ApollocommonPoint3D(obj["velocity"]);
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("subtype"))
        {
            msg.subtype = (obj["subtype"].is_string()?atoi(obj["subtype"].get<std::string>().c_str()):obj["subtype"].get<int>());
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("box"))
        {
            msg.box = from_json_ApolloperceptionBBox2D(obj["box"]);
        }
        return msg;
    }
    template <>
    ApolloperceptionSensorMeasurement from_json<ApolloperceptionSensorMeasurement>(nlohmann::json obj){
        return from_json_ApolloperceptionSensorMeasurement(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptionSensorMeasurement &dt)
    {
        dt=from_json_ApolloperceptionSensorMeasurement(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptionSensorMeasurement & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptionSensorMeasurement & dt)
    {
        os << to_json(dt);
        return os;
    }
}
