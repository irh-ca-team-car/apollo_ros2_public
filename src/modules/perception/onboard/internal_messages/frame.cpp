#include "modules/perception/onboard/internal_messages/sensor_meta.h"
#include "modules/perception/onboard/internal_messages/object.h"
#include "modules/perception/onboard/internal_messages/frame_supplement.h"
#include "modules/perception/onboard/internal_messages/frame.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::Frame;
    nlohmann::json to_json(const Frame &msg)
    {
        nlohmann::json j;

        j["sensor_info"] = to_json(msg.sensor_info);
        j["timestamp"] = msg.timestamp;
        nlohmann::json arr_objects;
        for (auto it= msg.objects.begin(); it != msg.objects.end(); ++it){
            if (*it != nullptr)
                arr_objects.push_back(to_json(**it));
            else
                arr_objects.push_back(nullptr); 
        }
        j["objects"] = arr_objects;
        nlohmann::json arr_sensor2world_pose;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                arr_sensor2world_pose.push_back(msg.sensor2world_pose(i,j));
            }
        }
        j["sensor2world_pose"] = arr_sensor2world_pose;
        j["lidar_frame_supplement"] = to_json(msg.lidar_frame_supplement);
        j["radar_frame_supplement"] = to_json(msg.radar_frame_supplement);
        j["camera_frame_supplement"] = to_json(msg.camera_frame_supplement);
        j["ultrasonic_frame_supplement"] = to_json(msg.ultrasonic_frame_supplement);

        return j;
    }
    Frame from_json_Frame(nlohmann::json obj)
    {
        Frame d;
        
        if (obj.contains("sensor_info"))
            d.sensor_info = from_json_SensorInfo(obj["sensor_info"]);
        if (obj.contains("timestamp"))
            d.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        if(obj.contains("objects")) 
            for (auto element : obj["objects"]){
                if (element.is_null())
                    d.objects.push_back(nullptr);
                else{
                    std::shared_ptr<Object> inter;
                    *inter = from_json_Object(element);
                    d.objects.push_back(inter);}
            }
        if (obj.contains("sensor2world_pose"))
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    d.sensor2world_pose(i,j) = (obj["sensor2world_pose"][i*4+j].is_string()?atof(obj["sensor2world_pose"][i*4+j].get<std::string>().c_str()):obj["sensor2world_pose"][i*4+j].get<double>());
                }
            }
        if (obj.contains("lidar_frame_supplement"))
            d.lidar_frame_supplement = from_json_LidarFrameSupplement(obj["lidar_frame_supplement"]);
        if (obj.contains("radar_frame_supplement"))
            d.radar_frame_supplement = from_json_RadarFrameSupplement(obj["radar_frame_supplement"]);
        if (obj.contains("camera_frame_supplement"))
            d.camera_frame_supplement = from_json_CameraFrameSupplement(obj["camera_frame_supplement"]);
        if (obj.contains("ultrasonic_frame_supplement"))
            d.ultrasonic_frame_supplement = from_json_UltrasonicFrameSupplement(obj["ultrasonic_frame_supplement"]);
        
        return d;
    }
    template <>
    Frame from_json<Frame>(nlohmann::json obj)
    {
        return from_json_Frame(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Frame &dt)
    {
        dt = from_json_Frame(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const Frame &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Frame &dt)
    {
        return os << to_json(dt).dump();
    }
}
