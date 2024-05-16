#include "adapter/serialization/apollo_msgs/frame.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const Frame &msg) {
        nlohmann::json obj;
        obj["deviceposition"] = to_json(msg.deviceposition);
        obj["deviceheading"] = to_json(msg.deviceheading);
        obj["devicegpspose"] = to_json(msg.devicegpspose);
        nlohmann::json arr_points;
        for (auto it = msg.points.begin(); it != msg.points.end(); ++it) {
            arr_points.push_back(to_json(*it));
        }
        obj["points"] = arr_points;
        nlohmann::json arr_radarpoints;
        for (auto it = msg.radarpoints.begin(); it != msg.radarpoints.end(); ++it) {
            arr_radarpoints.push_back(to_json(*it));
        }
        obj["radarpoints"] = arr_radarpoints;
        nlohmann::json arr_images;
        for (auto it = msg.images.begin(); it != msg.images.end(); ++it) {
            arr_images.push_back(to_json(*it));
        }
        obj["images"] = arr_images;
        obj["timestamp"] = (msg.timestamp);
        obj["frameseq"] = (msg.frameseq);
        obj["datafile"] = (msg.datafile);
        return obj;
    }
    Frame from_json_Frame (nlohmann::json obj) {
        Frame msg;
        if(obj.contains("deviceposition"))
        {
            msg.deviceposition = from_json_Vector3(obj["deviceposition"]);
        }
        if(obj.contains("deviceheading"))
        {
            msg.deviceheading = from_json_Quaternion(obj["deviceheading"]);
        }
        if(obj.contains("devicegpspose"))
        {
            msg.devicegpspose = from_json_GPSPose(obj["devicegpspose"]);
        }
        if(obj.contains("points"))
        {
            if(obj["points"].is_array())
            {
                for (auto& element : obj["points"])
                {
                    msg.points.push_back(from_json_Vector4(element));
                }
            }
            else
            {
                msg.points.push_back(from_json_Vector4(obj["points"]));
            }
        }
        if(obj.contains("radarpoints"))
        {
            if(obj["radarpoints"].is_array())
            {
                for (auto& element : obj["radarpoints"])
                {
                    msg.radarpoints.push_back(from_json_RadarPoint(element));
                }
            }
            else
            {
                msg.radarpoints.push_back(from_json_RadarPoint(obj["radarpoints"]));
            }
        }
        if(obj.contains("images"))
        {
            if(obj["images"].is_array())
            {
                for (auto& element : obj["images"])
                {
                    msg.images.push_back(from_json_CameraImage(element));
                }
            }
            else
            {
                msg.images.push_back(from_json_CameraImage(obj["images"]));
            }
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("frameseq"))
        {
            msg.frameseq = (obj["frameseq"].is_string()?atoi(obj["frameseq"].get<std::string>().c_str()):obj["frameseq"].get<int>());
        }
        if(obj.contains("datafile"))
        {
            msg.datafile = (obj["datafile"].is_string()?(obj["datafile"].get<std::string>().c_str()):obj["datafile"].get<std::string>());
        }
        return msg;
    }
    template <>
    Frame from_json<Frame>(nlohmann::json obj){
        return from_json_Frame(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Frame &dt)
    {
        dt=from_json_Frame(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const Frame & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const Frame & dt)
    {
        os << to_json(dt);
        return os;
    }
}
