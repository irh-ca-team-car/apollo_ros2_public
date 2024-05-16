#include "modules/perception/onboard/internal_messages/point_cloud.h"
#include "modules/perception/onboard/internal_messages/box.h"
#include "modules/perception/onboard/internal_messages/object_supplement.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::LidarObjectSupplement;
    using apollo::perception::base::PointD;
    using apollo::perception::base::PointF;

    nlohmann::json to_json(const LidarObjectSupplement &msg)
    {
        nlohmann::json j;
        j["is_orientation_ready"] = msg.is_orientation_ready;
        j["on_use"] = msg.on_use;
        j["cloud"] = to_json(msg.cloud);
        j["cloud_world"] = to_json(msg.cloud_world);
        j["is_background"] = msg.is_background;
        j["is_fp"] = msg.is_fp;
        j["fp_prob"] = msg.fp_prob;
        j["is_in_roi"] = msg.is_in_roi;
        j["num_points_in_roi"] = msg.num_points_in_roi;
        j["height_above_ground"] = msg.height_above_ground;
        nlohmann::json arr_raw_probs;
        for (size_t i = 0; i < msg.raw_probs.size(); i++){
            for (auto it= msg.raw_probs[i].begin(); it != msg.raw_probs[i].end(); ++it){ 
                arr_raw_probs[i].push_back(*it);
            }
        } 
        j["raw_probs"] = arr_raw_probs;
        nlohmann::json arr_raw_classification_methods;
        for (auto it= msg.raw_classification_methods.begin(); it != msg.raw_classification_methods.end(); ++it){ 
            arr_raw_classification_methods.push_back(*it); 
        } 
        j["raw_classification_methods"] = arr_raw_classification_methods;
        return j;
    }
    LidarObjectSupplement from_json_LidarObjectSupplement(nlohmann::json obj)
    {
        LidarObjectSupplement strct;
        if (obj.contains("is_orientation_ready"))
            strct.is_orientation_ready = (obj["is_orientation_ready"].is_string()?(bool)atoi(obj["is_orientation_ready"].get<std::string>().c_str()):obj["is_orientation_ready"].get<bool>());
        if (obj.contains("on_use"))
            strct.on_use = (obj["on_use"].is_string()?(bool)atoi(obj["on_use"].get<std::string>().c_str()):obj["on_use"].get<bool>());
        if (obj.contains("cloud"))
            strct.cloud = from_json_AttributePointCloud<PointF>(obj["cloud"]);
        if (obj.contains("cloud_world"))
            strct.cloud_world = from_json_AttributePointCloud<PointD>(obj["cloud_world"]);
        if (obj.contains("is_background"))
            strct.is_background = (obj["is_background"].is_string()?(bool)atoi(obj["is_background"].get<std::string>().c_str()):obj["is_background"].get<bool>());
        if (obj.contains("is_fp"))
            strct.is_fp = (obj["is_fp"].is_string()?(bool)atoi(obj["is_fp"].get<std::string>().c_str()):obj["is_fp"].get<bool>());
        if (obj.contains("fp_prob"))
            strct.fp_prob = (obj["fp_prob"].is_string()?atof(obj["fp_prob"].get<std::string>().c_str()):obj["fp_prob"].get<float>());
        if (obj.contains("is_in_roi"))
            strct.is_in_roi = (obj["is_in_roi"].is_string()?(bool)atoi(obj["is_in_roi"].get<std::string>().c_str()):obj["is_in_roi"].get<bool>());
        if (obj.contains("num_points_in_roi"))
            strct.num_points_in_roi = (obj["num_points_in_roi"].is_string()?(size_t)atoi(obj["num_points_in_roi"].get<std::string>().c_str()):obj["num_points_in_roi"].get<size_t>());
        if (obj.contains("height_above_ground"))
            strct.height_above_ground = (obj["height_above_ground"].is_string()?atof(obj["height_above_ground"].get<std::string>().c_str()):obj["height_above_ground"].get<float>());
        if(obj.contains("raw_probs")) 
            for (auto elements : obj["raw_probs"]){
                std::vector<float> inter;
                for (auto element : elements){
                    inter.push_back(element.is_string()?atof(element.get<std::string>().c_str()):element.get<float>()); 
                }
                strct.raw_probs.push_back(inter);
            }
        if(obj.contains("raw_classification_methods")) 
            for (auto element : obj["raw_classification_methods"]){ 
                strct.raw_classification_methods.push_back(element.get<std::string>()); 
            }
        return strct;
    }
    nlohmann::json &operator>>(nlohmann::json &os, LidarObjectSupplement &dt)
    {
        dt = from_json_LidarObjectSupplement(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const LidarObjectSupplement &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LidarObjectSupplement &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::RadarObjectSupplement;

    nlohmann::json to_json(const RadarObjectSupplement &msg)
    {
        nlohmann::json j;
        j["on_use"] = msg.on_use;
        j["range"] = msg.range;
        j["angle"] = msg.angle;
        j["relative_radial_velocity"] = msg.relative_radial_velocity;
        j["relative_tangential_velocity"] = msg.relative_tangential_velocity;
        j["radial_velocity"] = msg.radial_velocity;
        return j;
    }
    RadarObjectSupplement from_json_RadarObjectSupplement(nlohmann::json obj)
    {
        RadarObjectSupplement strct;
        if (obj.contains("on_use"))
            strct.on_use = (obj["on_use"].is_string()?(bool)atoi(obj["on_use"].get<std::string>().c_str()):obj["on_use"].get<bool>());
        if (obj.contains("range"))
            strct.range = (obj["range"].is_string()?atof(obj["range"].get<std::string>().c_str()):obj["range"].get<float>());
        if (obj.contains("angle"))
            strct.angle = (obj["angle"].is_string()?atof(obj["angle"].get<std::string>().c_str()):obj["angle"].get<float>());
        if (obj.contains("relative_radial_velocity"))
            strct.relative_radial_velocity = (obj["relative_radial_velocity"].is_string()?atof(obj["relative_radial_velocity"].get<std::string>().c_str()):obj["relative_radial_velocity"].get<float>());
        if (obj.contains("relative_tangential_velocity"))
            strct.relative_tangential_velocity = (obj["relative_tangential_velocity"].is_string()?atof(obj["relative_tangential_velocity"].get<std::string>().c_str()):obj["relative_tangential_velocity"].get<float>());
        if (obj.contains("radial_velocity"))
            strct.radial_velocity = (obj["radial_velocity"].is_string()?atof(obj["radial_velocity"].get<std::string>().c_str()):obj["radial_velocity"].get<float>());
        return strct;
    }
    nlohmann::json &operator>>(nlohmann::json &os, RadarObjectSupplement &dt)
    {
        dt = from_json_RadarObjectSupplement(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const RadarObjectSupplement &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const RadarObjectSupplement &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::CameraObjectSupplement;

    nlohmann::json to_json(const CameraObjectSupplement &msg)
    {
        nlohmann::json j;
        j["on_use"] = msg.on_use;
        j["sensor_name"] = msg.sensor_name;
        j["box"] = to_json(msg.box);
        j["projected_box"] = to_json(msg.projected_box);
        j["local_track_id"] = msg.local_track_id;
        nlohmann::json arr_pts8;
        for (auto it= msg.pts8.begin(); it != msg.pts8.end(); ++it){ 
            arr_pts8.push_back(*it); 
        } 
        j["pts8"] = arr_pts8;
        j["front_box"] = to_json(msg.front_box);
        j["back_box"] = to_json(msg.back_box);
        nlohmann::json arr_object_feature;
        for (auto it= msg.object_feature.begin(); it != msg.object_feature.end(); ++it){ 
            arr_object_feature.push_back(*it); 
        } 
        j["object_feature"] = arr_object_feature;
        j["alpha"] = msg.alpha;
        j["truncated_horizontal"] = msg.truncated_horizontal;
        j["truncated_vertical"] = msg.truncated_vertical;
        nlohmann::json arr_local_center;
        for (int i = 0; i < 3; i++) {
            arr_local_center.push_back(msg.local_center(i));
        }
        j["local_center"] = arr_local_center;
        j["visual_type"] = msg.visual_type;
        nlohmann::json arr_visual_type_probs;
        for (auto it= msg.visual_type_probs.begin(); it != msg.visual_type_probs.end(); ++it){ 
            arr_visual_type_probs.push_back(*it); 
        } 
        j["visual_type_probs"] = arr_visual_type_probs;
        j["area_id"] = msg.area_id;
        nlohmann::json arr_visible_ratios;
        for (int i = 0; i < 4; i++) {
            arr_visible_ratios.push_back(msg.visible_ratios[i]);
        }
        j["visible_ratios"] = arr_visible_ratios;
        nlohmann::json arr_cut_off_ratios;
        for (int i = 0; i < 4; i++) {
            arr_cut_off_ratios.push_back(msg.cut_off_ratios[i]);
        }
        j["cut_off_ratios"] = arr_cut_off_ratios;
        
        return j;
    }
    CameraObjectSupplement from_json_CameraObjectSupplement(nlohmann::json obj)
    {
        CameraObjectSupplement strct;
        if (obj.contains("on_use"))
            strct.on_use = (obj["on_use"].is_string()?(bool)atoi(obj["on_use"].get<std::string>().c_str()):obj["on_use"].get<bool>());
        if (obj.contains("sensor_name"))
            strct.sensor_name = obj["sensor_name"].get<std::string>();
        if (obj.contains("box"))
            strct.box = from_json_BBox2D<float>(obj["box"]);
        if (obj.contains("projected_box"))
            strct.projected_box = from_json_BBox2D<float>(obj["projected_box"]);
        if (obj.contains("local_track_id"))
            strct.local_track_id = (obj["local_track_id"].is_string()?atoi(obj["local_track_id"].get<std::string>().c_str()):obj["local_track_id"].get<int>());
        if(obj.contains("pts8")) 
            for (auto element : obj["pts8"]){ 
                strct.pts8.push_back(element.is_string()?atof(element.get<std::string>().c_str()):element.get<float>());
            }
        if (obj.contains("front_box"))
            strct.front_box = from_json_BBox2D<float>(obj["front_box"]);
        if (obj.contains("back_box"))
            strct.back_box = from_json_BBox2D<float>(obj["back_box"]);
        if(obj.contains("object_feature")) 
            for (auto element : obj["object_feature"]){ 
                strct.object_feature.push_back(element.is_string()?atof(element.get<std::string>().c_str()):element.get<float>());
            }
        if (obj.contains("alpha"))
            strct.alpha = (obj["alpha"].is_string()?atof(obj["alpha"].get<std::string>().c_str()):obj["alpha"].get<float>());
        if (obj.contains("truncated_horizontal"))
            strct.truncated_horizontal = (obj["truncated_horizontal"].is_string()?atof(obj["truncated_horizontal"].get<std::string>().c_str()):obj["truncated_horizontal"].get<float>());
        if (obj.contains("truncated_vertical"))
            strct.truncated_vertical = (obj["truncated_vertical"].is_string()?atof(obj["truncated_vertical"].get<std::string>().c_str()):obj["truncated_vertical"].get<float>());
        if (obj.contains("local_center"))
            for (int i = 0; i < 3; i++) {
                strct.local_center(i) = (obj["local_center"][i].is_string()?atof(obj["local_center"][i].get<std::string>().c_str()):obj["local_center"][i].get<float>());
            }
        if (obj.contains("visual_type"))
            strct.visual_type = static_cast<apollo::perception::base::VisualObjectType>(obj["visual_type"].is_string()?atoi(obj["visual_type"].get<std::string>().c_str()):obj["visual_type"].get<int>());
        if(obj.contains("visual_type_probs")) 
            for (auto element : obj["visual_type_probs"]){ 
                strct.visual_type_probs.push_back(element.is_string()?atof(element.get<std::string>().c_str()):element.get<float>());
            }
        if (obj.contains("area_id"))
            strct.area_id = (obj["visual_type"].is_string()?atoi(obj["area_id"].get<std::string>().c_str()):obj["area_id"].get<int>());
        if (obj.contains("area_id"))
            for (int i = 0; i < 4; i++) {
                strct.visible_ratios[i] = (obj["visible_ratios"][i].is_string()?atof(obj["visible_ratios"][i].get<std::string>().c_str()):obj["visible_ratios"][i].get<float>());
            }
        if (obj.contains("cut_off_ratios"))
            for (int i = 0; i < 4; i++) {
                strct.cut_off_ratios[i] = (obj["cut_off_ratios"][i].is_string()?atof(obj["cut_off_ratios"][i].get<std::string>().c_str()):obj["cut_off_ratios"][i].get<float>());
            }
        return strct;
    }
    nlohmann::json &operator>>(nlohmann::json &os, CameraObjectSupplement &dt)
    {
        dt = from_json_CameraObjectSupplement(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const CameraObjectSupplement &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const CameraObjectSupplement &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::SensorObjectMeasurement;

    nlohmann::json to_json(const SensorObjectMeasurement &msg)
    {
        nlohmann::json j;
        j["sensor_id"] = msg.sensor_id;
        j["timestamp"] = msg.timestamp;
        j["track_id"] = msg.track_id;
        nlohmann::json arr_center;
        for (int i = 0; i < 3; i++) {
            arr_center.push_back(msg.center(i));
        }
        j["center"] = arr_center;
        j["theta"] = msg.theta;
        nlohmann::json arr_velocity;
        for (int i = 0; i < 3; i++) {
            arr_velocity.push_back(msg.velocity(i));
        }
        j["velocity"] = arr_velocity;
        nlohmann::json arr_size;
        for (int i = 0; i < 3; i++) {
            arr_size.push_back(msg.size(i));
        }
        j["size"] = arr_size;
        j["type"] = msg.type;
        j["box"] = to_json(msg.box);
        
        return j;
    }
    SensorObjectMeasurement from_json_SensorObjectMeasurement(nlohmann::json obj)
    {
        SensorObjectMeasurement strct;
        if (obj.contains("sensor_id"))
            strct.sensor_id = obj["sensor_id"].get<std::string>();
        if (obj.contains("timestamp"))
            strct.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        if (obj.contains("track_id"))
            strct.track_id = (obj["track_id"].is_string()?atoi(obj["track_id"].get<std::string>().c_str()):obj["track_id"].get<int>());
        if (obj.contains("center"))
            for (int i = 0; i < 3; i++) {
                strct.center(i) = (obj["center"][i].is_string()?atof(obj["center"][i].get<std::string>().c_str()):obj["center"][i].get<double>());
            }
        if (obj.contains("theta"))
            strct.theta = (obj["theta"].is_string()?atof(obj["theta"].get<std::string>().c_str()):obj["theta"].get<float>());
        if (obj.contains("size"))
            for (int i = 0; i < 3; i++) {
                strct.size(i) = (obj["size"][i].is_string()?atof(obj["size"][i].get<std::string>().c_str()):obj["size"][i].get<float>());
            }
        if (obj.contains("velocity"))
            for (int i = 0; i < 3; i++) {
                strct.velocity(i) = (obj["velocity"][i].is_string()?atof(obj["velocity"][i].get<std::string>().c_str()):obj["velocity"][i].get<float>());
            }
        if (obj.contains("type"))
            strct.type = static_cast<apollo::perception::base::ObjectType>(obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        if (obj.contains("box"))
            strct.box = from_json_BBox2D<float>(obj["box"]);
        return strct;
    }
    nlohmann::json &operator>>(nlohmann::json &os, SensorObjectMeasurement &dt)
    {
        dt = from_json_SensorObjectMeasurement(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const SensorObjectMeasurement &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const SensorObjectMeasurement &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::FusionObjectSupplement;

    nlohmann::json to_json(const FusionObjectSupplement &msg)
    {
        nlohmann::json j;
        j["on_use"] = msg.on_use;
        nlohmann::json arr_measurements;
        for (auto it= msg.measurements.begin(); it != msg.measurements.end(); ++it){ 
            arr_measurements.push_back(to_json(*it)); 
        } 
        j["measurements"] = arr_measurements;
        return j;
    }
    FusionObjectSupplement from_json_FusionObjectSupplement(nlohmann::json obj)
    {
        FusionObjectSupplement strct;
        if (obj.contains("on_use"))
            strct.on_use = (obj["on_use"].is_string()?(bool)atoi(obj["on_use"].get<std::string>().c_str()):obj["on_use"].get<bool>());
        if(obj.contains("measurements")) 
            for (auto element : obj["measurements"]){ 
                strct.measurements.push_back(from_json_SensorObjectMeasurement(element)); 
            }
        return strct;
    }
    nlohmann::json &operator>>(nlohmann::json &os, FusionObjectSupplement &dt)
    {
        dt = from_json_FusionObjectSupplement(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const FusionObjectSupplement &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const FusionObjectSupplement &dt)
    {
        return os << to_json(dt).dump();
    }
}
