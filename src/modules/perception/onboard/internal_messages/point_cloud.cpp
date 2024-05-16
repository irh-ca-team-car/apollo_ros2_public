#include "modules/perception/onboard/internal_messages/point.h"
#include "modules/perception/onboard/internal_messages/point_cloud.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::PointCloud;
    template<typename T>
    nlohmann::json to_json(const PointCloud<T> &msg)
    {
        nlohmann::json j;
        
        nlohmann::json arr_points_;
        for (auto it= msg.points_.begin(); it != msg.points_.end(); ++it){ 
            arr_points_.push_back(to_json(*it)); 
        } 
        j["points_"] = arr_points_;
        
        j["width_"] = msg.width_;
        j["height_"] = msg.height_;
        j["timestamp_"] = msg.timestamp_;
        
        nlohmann::json arr_sensor_to_world_pose_;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                arr_sensor_to_world_pose_.push_back(msg.sensor_to_world_pose_(i,j));
            }
        }
        j["sensor_to_world_pose_"] = arr_sensor_to_world_pose_;
        
        return j;
    }
    template<>
    nlohmann::json to_json(const PointCloud<Point<double>> &msg)
    {
        return to_json(msg);
    }
    template <typename T>
    PointCloud<T> from_json_PointCloud(nlohmann::json obj)
    {
        PointCloud<T> d;

        if(obj.contains("points_")) 
            for (auto element : obj["points_"]){ 
                d.points_.push_back(from_json<T>(element)); 
            }
        if (obj.contains("width_"))
            d.width_ = (obj["width_"].is_string()?(size_t)atoi(obj["width_"].get<std::string>().c_str()):obj["width_"].get<size_t>());
        if (obj.contains("height_"))
            d.height_ = (obj["height_"].is_string()?(size_t)atoi(obj["height_"].get<std::string>().c_str()):obj["height_"].get<size_t>());
        if (obj.contains("timestamp_"))
            d.timestamp_ = (obj["timestamp_"].is_string()?atof(obj["timestamp_"].get<std::string>().c_str()):obj["timestamp_"].get<double>());
        if (obj.contains("sensor_to_world_pose_"))
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    d.sensor_to_world_pose_(i,j) = (obj["sensor_to_world_pose_"][i*4+j].is_string()?atof(obj["sensor_to_world_pose_"][i*4+j].get<std::string>().c_str()):obj["sensor_to_world_pose_"][i*4+j].get<double>());
                }
            }

        return d;
    }
    template <>
    PointCloud<Point<double>> from_json<PointCloud<Point<double>>>(nlohmann::json obj)
    {
        return from_json_PointCloud<Point<double>>(obj);
    }
    template<typename T>
    nlohmann::json &operator>>(nlohmann::json &os, PointCloud<T> &dt)
    {
        dt = from_json_PointCloud<T>(os);
        return os;
    }
    template<typename T>
    std::ostream &
    operator<<(std::ostream &os, const PointCloud<T> &dt)
    {
        return os << to_json(dt).dump();
    }
    template<typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const PointCloud<T> &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::AttributePointCloud;
    template<typename T>
    nlohmann::json to_json(const AttributePointCloud<T> &msg)
    {
        nlohmann::json j;
        
        nlohmann::json arr_points_timestamp_;
        for (auto it= msg.points_timestamp_.begin(); it != msg.points_timestamp_.end(); ++it){ 
            arr_points_timestamp_.push_back(*it); 
        } 
        j["points_timestamp_"] = arr_points_timestamp_;
        
        nlohmann::json arr_points_height_;
        for (auto it= msg.points_height_.begin(); it != msg.points_height_.end(); ++it){ 
            arr_points_height_.push_back(*it); 
        } 
        j["points_height_"] = arr_points_height_;
        
        nlohmann::json arr_points_beam_id_;
        for (auto it= msg.points_beam_id_.begin(); it != msg.points_beam_id_.end(); ++it){ 
            arr_points_beam_id_.push_back(*it); 
        } 
        j["points_beam_id_"] = arr_points_beam_id_;
        
        nlohmann::json arr_points_label_;
        for (auto it= msg.points_label_.begin(); it != msg.points_label_.end(); ++it){ 
            arr_points_label_.push_back(*it); 
        } 
        j["points_label_"] = arr_points_label_;
        
        nlohmann::json arr_points_;
        for (auto it= msg.points_.begin(); it != msg.points_.end(); ++it){ 
            arr_points_.push_back(to_json(*it)); 
        } 
        j["points_"] = arr_points_;
        
        j["width_"] = msg.width_;
        j["height_"] = msg.height_;
        j["timestamp_"] = msg.timestamp_;
        
        nlohmann::json arr_sensor_to_world_pose_;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                arr_sensor_to_world_pose_.push_back(msg.sensor_to_world_pose_(i,j));
            }
        }
        j["sensor_to_world_pose_"] = arr_sensor_to_world_pose_;
        
        return j;
    }
    template<>
    nlohmann::json to_json(const AttributePointCloud<Point<float>> &msg)
    {
        return to_json(msg);
    }
    template<>
    nlohmann::json to_json(const AttributePointCloud<Point<double>> &msg)
    {
        return to_json(msg);
    }
    template <typename T>
    AttributePointCloud<T> from_json_AttributePointCloud(nlohmann::json obj)
    {
        AttributePointCloud<T> d;

        if(obj.contains("points_timestamp_")) 
            for (auto element : obj["points_timestamp_"]){ 
                d.points_timestamp_.push_back(element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>());
            }
        if(obj.contains("points_height_")) 
            for (auto element : obj["points_height_"]){ 
                d.points_height_.push_back(element.is_string()?atof(element.get<std::string>().c_str()):element.get<float>());
            }
        if(obj.contains("points_beam_id_")) 
            for (auto element : obj["points_beam_id_"]){ 
                d.points_beam_id_.push_back(element.is_string()?atof(element.get<std::string>().c_str()):element.get<int32_t>());
            }
        if(obj.contains("points_label_")) 
            for (auto element : obj["points_label_"]){ 
                d.points_label_.push_back(element.is_string()?atof(element.get<std::string>().c_str()):element.get<uint8_t>());
            }
        if(obj.contains("points_")) 
            for (auto element : obj["points_"]){ 
                d.points_.push_back(from_json<T>(element)); 
            }
        if (obj.contains("width_"))
            d.width_ = (obj["width_"].is_string()?(size_t)atoi(obj["width_"].get<std::string>().c_str()):obj["width_"].get<size_t>());
        if (obj.contains("height_"))
            d.height_ = (obj["height_"].is_string()?(size_t)atoi(obj["height_"].get<std::string>().c_str()):obj["height_"].get<size_t>());
        if (obj.contains("timestamp_"))
            d.timestamp_ = (obj["timestamp_"].is_string()?atof(obj["timestamp_"].get<std::string>().c_str()):obj["timestamp_"].get<double>());
        if (obj.contains("sensor_to_world_pose_"))
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    d.sensor_to_world_pose_(i,j) = (obj["sensor_to_world_pose_"][i*4+j].is_string()?atof(obj["sensor_to_world_pose_"][i*4+j].get<std::string>().c_str()):obj["sensor_to_world_pose_"][i*4+j].get<double>());
                }
            }

        return d;
    }
    template <>
    AttributePointCloud<Point<float>> from_json<AttributePointCloud<Point<float>>>(nlohmann::json obj)
    {
        return from_json_AttributePointCloud<Point<float>>(obj);
    }
    template <>
    AttributePointCloud<Point<double>> from_json<AttributePointCloud<Point<double>>>(nlohmann::json obj)
    {
        return from_json_AttributePointCloud<Point<double>>(obj);
    }
    template<typename T>
    nlohmann::json &operator>>(nlohmann::json &os, AttributePointCloud<T> &dt)
    {
        dt = from_json_AttributePointCloud<T>(os);
        return os;
    }
    template<typename T>
    std::ostream &
    operator<<(std::ostream &os, const AttributePointCloud<T> &dt)
    {
        return os << to_json(dt).dump();
    }
    template<typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const AttributePointCloud<T> &dt)
    {
        return os << to_json(dt).dump();
    }
}
