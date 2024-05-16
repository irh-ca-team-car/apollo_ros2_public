#include "modules/perception/onboard/internal_messages/point_cloud.h"
#include "modules/perception/onboard/internal_messages/vehicle_struct.h"
#include "modules/perception/onboard/internal_messages/object_supplement.h"
#include "modules/perception/onboard/internal_messages/object.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::Object;
    nlohmann::json to_json(const Object &msg)
    {
        nlohmann::json j;

        j["id"] = msg.id;
        //j["polygon"] = to_json(msg.polygon);
        
        nlohmann::json arr_direction;
        for (int i = 0; i < 3; i++) {
            arr_direction.push_back(msg.direction(i));
        }
        j["direction"] = arr_direction;
        
        j["theta"] = msg.theta;
        j["theta_variance"] = msg.theta_variance;
        
        nlohmann::json arr_center;
        for (int i = 0; i < 3; i++) {
            arr_center.push_back(msg.center(i));
        }
        j["center"] = arr_center;
        
        nlohmann::json arr_center_uncertainty;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arr_center_uncertainty.push_back(msg.center_uncertainty(i,j));
            }
        }
        j["center_uncertainty"] = arr_center_uncertainty;
        
        nlohmann::json arr_size;
        for (int i = 0; i < 3; i++) {
            arr_size.push_back(msg.size(i));
        }
        j["size"] = arr_size;
        
        nlohmann::json arr_size_variance;
        for (int i = 0; i < 3; i++) {
            arr_size_variance.push_back(msg.size_variance(i));
        }
        j["size_variance"] = arr_size_variance;
        
        nlohmann::json arr_anchor_point;
        for (int i = 0; i < 3; i++) {
            arr_anchor_point.push_back(msg.anchor_point(i));
        }
        j["anchor_point"] = arr_anchor_point;
        
        j["type"] = msg.type;
        
        nlohmann::json arr_type_probs;
        for (auto it= msg.type_probs.begin(); it != msg.type_probs.end(); ++it){ 
            arr_type_probs.push_back(*it); 
        } 
        j["type_probs"] = arr_type_probs;
        
        j["sub_type"] = msg.sub_type;
        
        nlohmann::json arr_sub_type_probs;
        for (auto it= msg.sub_type_probs.begin(); it != msg.sub_type_probs.end(); ++it){ 
            arr_sub_type_probs.push_back(*it); 
        } 
        j["sub_type_probs"] = arr_sub_type_probs;
        
        j["confidence"] = msg.confidence;
        j["track_id"] = msg.track_id;
        
        nlohmann::json arr_velocity;
        for (int i = 0; i < 3; i++) {
            arr_velocity.push_back(msg.velocity(i));
        }
        j["velocity"] = arr_velocity;
        
        nlohmann::json arr_velocity_uncertainty;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arr_velocity_uncertainty.push_back(msg.velocity_uncertainty(i,j));
            }
        }
        j["velocity_uncertainty"] = arr_velocity_uncertainty;
        
        j["velocity_converged"] = msg.velocity_converged;
        j["velocity_confidence"] = msg.velocity_confidence;
        
        nlohmann::json arr_acceleration;
        for (int i = 0; i < 3; i++) {
            arr_acceleration.push_back(msg.acceleration(i));
        }
        j["acceleration"] = arr_acceleration;
        
        nlohmann::json arr_acceleration_uncertainty;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arr_acceleration_uncertainty.push_back(msg.acceleration_uncertainty(i,j));
            }
        }
        j["acceleration_uncertainty"] = arr_acceleration_uncertainty;
        
        j["tracking_time"] = msg.tracking_time;
        j["latest_tracked_time"] = msg.latest_tracked_time;
        j["motion_state"] = msg.motion_state;
        
        nlohmann::json arr_drops;
        for (size_t i = 0; i < 100; i++) {
            for (int j = 0; j < 3; j++) {
                arr_drops.push_back(msg.drops[i](j));
            }
        }
        j["drops"] = arr_drops;
        
        j["drop_num"] = msg.drop_num;
        j["b_cipv"] = msg.b_cipv;
        
        j["car_light"] = to_json(msg.car_light);
        
        //j["lidar_supplement"] = to_json(msg.lidar_supplement);
        //j["radar_supplement"] = to_json(msg.radar_supplement);
        //j["camera_supplement"] = to_json(msg.camera_supplement);
        //j["fusion_supplement"] = to_json(msg.fusion_supplement);

        return j;
    }
    Object from_json_Object(nlohmann::json obj)
    {
        Object d;
        
        if (obj.contains("id"))
            d.id = (obj["id"].is_string()?atoi(obj["id"].get<std::string>().c_str()):obj["id"].get<int>());
        
        if (obj.contains("polygon"))
            d.polygon = from_json_PointCloud<PointD>(obj["polygon"]);
            
        if (obj.contains("direction"))
            for (int i = 0; i < 3; i++) {
                d.direction(i) = (obj["direction"][i].is_string()?atof(obj["direction"][i].get<std::string>().c_str()):obj["direction"][i].get<float>());
            }
        
        if (obj.contains("theta"))
            d.theta = (obj["theta"].is_string()?atof(obj["theta"].get<std::string>().c_str()):obj["theta"].get<float>());
        
        if (obj.contains("theta_variance"))
            d.theta_variance = (obj["theta_variance"].is_string()?atof(obj["theta_variance"].get<std::string>().c_str()):obj["theta_variance"].get<float>());
        
        if (obj.contains("center"))
            for (int i = 0; i < 3; i++) {
                d.center(i) = (obj["center"][i].is_string()?atof(obj["center"][i].get<std::string>().c_str()):obj["center"][i].get<double>());
            }
        
        if (obj.contains("center_uncertainty"))
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    d.center_uncertainty(i,j) = (obj["center_uncertainty"][i*3+j].is_string()?atof(obj["center_uncertainty"][i*3+j].get<std::string>().c_str()):obj["center_uncertainty"][i*3+j].get<float>());
                }
            }
        
        if (obj.contains("size"))
            for (int i = 0; i < 3; i++) {
                d.size(i) = (obj["size"][i].is_string()?atof(obj["size"][i].get<std::string>().c_str()):obj["size"][i].get<float>());
            }
        
        if (obj.contains("size_variance"))
            for (int i = 0; i < 3; i++) {
                d.size_variance(i) = (obj["size_variance"][i].is_string()?atof(obj["size_variance"][i].get<std::string>().c_str()):obj["size_variance"][i].get<float>());
            }
        
        if (obj.contains("anchor_point"))
            for (int i = 0; i < 3; i++) {
                d.anchor_point(i) = (obj["anchor_point"][i].is_string()?atof(obj["anchor_point"][i].get<std::string>().c_str()):obj["anchor_point"][i].get<double>());
            }
        
        if (obj.contains("type"))
            d.type = static_cast<apollo::perception::base::ObjectType>(obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        
        if(obj.contains("type_probs")) 
            for (auto element : obj["type_probs"]){ 
                d.type_probs.push_back(element.is_string()?atof(element.get<std::string>().c_str()):element.get<float>());
            }
        
        if (obj.contains("sub_type"))
            d.sub_type = static_cast<apollo::perception::base::ObjectSubType>(obj["sub_type"].is_string()?atoi(obj["sub_type"].get<std::string>().c_str()):obj["sub_type"].get<int>());
        
        if(obj.contains("sub_type_probs")) 
            for (auto element : obj["sub_type_probs"]){ 
                d.sub_type_probs.push_back(element.is_string()?atof(element.get<std::string>().c_str()):element.get<float>());
            }
        
        if (obj.contains("confidence"))
            d.confidence = (obj["confidence"].is_string()?atof(obj["confidence"].get<std::string>().c_str()):obj["confidence"].get<float>());
            
        if (obj.contains("track_id"))
            d.track_id = (obj["track_id"].is_string()?atoi(obj["track_id"].get<std::string>().c_str()):obj["track_id"].get<int>());
        
        if (obj.contains("velocity"))
            for (int i = 0; i < 3; i++) {
                d.velocity(i) = (obj["velocity"][i].is_string()?atof(obj["velocity"][i].get<std::string>().c_str()):obj["velocity"][i].get<float>());
            }
        
        if (obj.contains("velocity_uncertainty"))
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    d.velocity_uncertainty(i,j) = (obj["velocity_uncertainty"][i*3+j].is_string()?atof(obj["velocity_uncertainty"][i*3+j].get<std::string>().c_str()):obj["velocity_uncertainty"][i*3+j].get<float>());
                }
            }
        
        if (obj.contains("velocity_converged"))
            d.velocity_converged = (obj["velocity_converged"].is_string()?(bool)atoi(obj["velocity_converged"].get<std::string>().c_str()):obj["velocity_converged"].get<bool>());
            
        if (obj.contains("velocity_confidence"))
            d.velocity_confidence = (obj["velocity_confidence"].is_string()?atof(obj["velocity_confidence"].get<std::string>().c_str()):obj["velocity_confidence"].get<float>());
        
        if (obj.contains("acceleration"))
            for (int i = 0; i < 3; i++) {
                d.acceleration(i) = (obj["acceleration"][i].is_string()?atof(obj["acceleration"][i].get<std::string>().c_str()):obj["acceleration"][i].get<float>());
            }
        
        if (obj.contains("acceleration_uncertainty"))
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    d.acceleration_uncertainty(i,j) = (obj["acceleration_uncertainty"][i*3+j].is_string()?atof(obj["acceleration_uncertainty"][i*3+j].get<std::string>().c_str()):obj["acceleration_uncertainty"][i*3+j].get<float>());
                }
            }
        
        if (obj.contains("tracking_time"))
            d.tracking_time = (obj["tracking_time"].is_string()?atof(obj["tracking_time"].get<std::string>().c_str()):obj["tracking_time"].get<double>());
            
        if (obj.contains("latest_tracked_time"))
            d.latest_tracked_time = (obj["latest_tracked_time"].is_string()?atof(obj["latest_tracked_time"].get<std::string>().c_str()):obj["latest_tracked_time"].get<double>());
        
        if (obj.contains("motion_state"))
            d.motion_state = static_cast<apollo::perception::base::MotionState>(obj["motion_state"].is_string()?atoi(obj["motion_state"].get<std::string>().c_str()):obj["motion_state"].get<int>());
        
        if (obj.contains("drops"))
        for (size_t i = 0; i < 100; i++) {
            for (int j = 0; j < 3; j++) {
                d.drops[i](j)=(obj["drops"][i*3+j].is_string()?atof(obj["drops"][i*3+j].get<std::string>().c_str()):obj["drops"][i*3+j].get<double>());
            }
        }
        
        if (obj.contains("drop_num"))
            d.drop_num = (obj["drop_num"].is_string()?(size_t)atoi(obj["drop_num"].get<std::string>().c_str()):obj["drop_num"].get<size_t>());
        
        if (obj.contains("b_cipv"))
            d.b_cipv = (obj["b_cipv"].is_string()?(bool)atoi(obj["b_cipv"].get<std::string>().c_str()):obj["b_cipv"].get<bool>());
        
        if (obj.contains("car_light"))
            d.car_light = from_json_CarLight(obj["car_light"]);
        
        if (obj.contains("lidar_supplement"))
            d.lidar_supplement = from_json_LidarObjectSupplement(obj["lidar_supplement"]);
        
        if (obj.contains("radar_supplement"))
            d.radar_supplement = from_json_RadarObjectSupplement(obj["radar_supplement"]);
        
        if (obj.contains("camera_supplement"))
            d.camera_supplement = from_json_CameraObjectSupplement(obj["camera_supplement"]);
        
        if (obj.contains("fusion_supplement"))
            d.fusion_supplement = from_json_FusionObjectSupplement(obj["fusion_supplement"]);
        
        return d;
    }
    template <>
    Object from_json<Object>(nlohmann::json obj)
    {
        return from_json_Object(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, Object &dt)
    {
        dt = from_json_Object(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const Object &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Object &dt)
    {
        return os << to_json(dt).dump();
    }
}
