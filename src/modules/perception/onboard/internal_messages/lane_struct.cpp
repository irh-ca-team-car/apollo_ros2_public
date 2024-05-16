#include "modules/perception/onboard/internal_messages/point.h"
#include "modules/perception/onboard/internal_messages/lane_struct.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::LaneLineCubicCurve;
    nlohmann::json to_json(const LaneLineCubicCurve &msg)
    {
        nlohmann::json j;

        j["x_start"] = msg.x_start;
        j["x_end"] = msg.x_end;
        j["a"] = msg.a;
        j["b"] = msg.b;
        j["c"] = msg.c;
        j["d"] = msg.d;

        return j;
    }
    LaneLineCubicCurve from_json_LaneLineCubicCurve(nlohmann::json obj)
    {
        LaneLineCubicCurve d;
        
        if (obj.contains("x_start"))
            d.x_start = (obj["x_start"].is_string()?atof(obj["x_start"].get<std::string>().c_str()):obj["x_start"].get<float>());
        if (obj.contains("x_end"))
            d.x_end = (obj["x_end"].is_string()?atof(obj["x_end"].get<std::string>().c_str()):obj["x_end"].get<float>());
        if (obj.contains("a"))
            d.a = (obj["a"].is_string()?atof(obj["a"].get<std::string>().c_str()):obj["a"].get<float>());
        if (obj.contains("b"))
            d.b = (obj["b"].is_string()?atof(obj["b"].get<std::string>().c_str()):obj["b"].get<float>());
        if (obj.contains("c"))
            d.c = (obj["c"].is_string()?atof(obj["c"].get<std::string>().c_str()):obj["c"].get<float>());
        if (obj.contains("d"))
            d.d = (obj["d"].is_string()?atof(obj["d"].get<std::string>().c_str()):obj["d"].get<float>());
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, LaneLineCubicCurve &dt)
    {
        dt = from_json_LaneLineCubicCurve(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const LaneLineCubicCurve &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LaneLineCubicCurve &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::EndPoints;
    nlohmann::json to_json(const EndPoints &msg)
    {
        nlohmann::json j;

        j["start"] = to_json(msg.start);
        j["end"] = to_json(msg.end);

        return j;
    }
    EndPoints from_json_EndPoints(nlohmann::json obj)
    {
        EndPoints d;
        
        if (obj.contains("start"))
            d.start = from_json_Point2D<float>(obj["start"]);
        if (obj.contains("end"))
            d.end = from_json_Point2D<float>(obj["end"]);
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, EndPoints &dt)
    {
        dt = from_json_EndPoints(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const EndPoints &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const EndPoints &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::LaneLine;
    nlohmann::json to_json(const LaneLine &msg)
    {
        nlohmann::json j;

        j["type"] = msg.type;
        j["pos_type"] = msg.pos_type;
        j["curve_car_coord"] = to_json(msg.curve_car_coord);
        j["curve_camera_coord"] = to_json(msg.curve_camera_coord);
        j["curve_image_coord"] = to_json(msg.curve_image_coord);
        nlohmann::json arr_curve_image_point_set;
        for (auto it= msg.curve_image_point_set.begin(); it != msg.curve_image_point_set.end(); ++it){ 
            arr_curve_image_point_set.push_back(to_json(*it)); 
        } 
        j["curve_image_point_set"] = arr_curve_image_point_set;
        nlohmann::json arr_curve_camera_point_set;
        for (auto it= msg.curve_camera_point_set.begin(); it != msg.curve_camera_point_set.end(); ++it){ 
            arr_curve_camera_point_set.push_back(to_json(*it)); 
        } 
        j["curve_camera_point_set"] = arr_curve_camera_point_set;
        nlohmann::json arr_curve_car_coord_point_set;
        for (auto it= msg.curve_car_coord_point_set.begin(); it != msg.curve_car_coord_point_set.end(); ++it){ 
            arr_curve_car_coord_point_set.push_back(to_json(*it)); 
        } 
        j["curve_car_coord_point_set"] = arr_curve_car_coord_point_set;
        nlohmann::json arr_image_end_point_set;
        for (auto it= msg.image_end_point_set.begin(); it != msg.image_end_point_set.end(); ++it){ 
            arr_image_end_point_set.push_back(to_json(*it)); 
        } 
        j["image_end_point_set"] = arr_image_end_point_set;
        j["track_id"] = msg.track_id;
        j["confidence"] = msg.confidence;
        j["use_type"] = msg.use_type;

        return j;
    }
    LaneLine from_json_LaneLine(nlohmann::json obj)
    {
        LaneLine d;
        
        if (obj.contains("type"))
            d.type = static_cast<apollo::perception::base::LaneLineType>(obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        if (obj.contains("pos_type"))
            d.pos_type = static_cast<apollo::perception::base::LaneLinePositionType>(obj["pos_type"].is_string()?atoi(obj["pos_type"].get<std::string>().c_str()):obj["pos_type"].get<int>());
        if (obj.contains("curve_car_coord"))
            d.curve_car_coord = from_json_LaneLineCubicCurve(obj["curve_car_coord"]);
        if (obj.contains("curve_camera_coord"))
            d.curve_camera_coord = from_json_LaneLineCubicCurve(obj["curve_camera_coord"]);
        if (obj.contains("curve_image_coord"))
            d.curve_image_coord = from_json_LaneLineCubicCurve(obj["curve_image_coord"]);
        if(obj.contains("curve_image_point_set")) 
            for (auto element : obj["curve_image_point_set"]){ 
                d.curve_image_point_set.push_back(from_json_Point2D<float>(element)); 
            }
        if(obj.contains("curve_camera_point_set")) 
            for (auto element : obj["curve_camera_point_set"]){ 
                d.curve_camera_point_set.push_back(from_json_Point3D<float>(element)); 
            }
        if(obj.contains("curve_car_coord_point_set")) 
            for (auto element : obj["curve_car_coord_point_set"]){ 
                d.curve_car_coord_point_set.push_back(from_json_Point2D<float>(element)); 
            }
        if(obj.contains("image_end_point_set")) 
            for (auto element : obj["image_end_point_set"]){ 
                d.image_end_point_set.push_back(from_json_EndPoints(element)); 
            }
        if (obj.contains("track_id"))
            d.track_id = (obj["track_id"].is_string()?atoi(obj["track_id"].get<std::string>().c_str()):obj["track_id"].get<int>());
        if (obj.contains("confidence"))
            d.confidence = (obj["confidence"].is_string()?atof(obj["confidence"].get<std::string>().c_str()):obj["confidence"].get<float>());
        if (obj.contains("use_type"))
            d.use_type = static_cast<apollo::perception::base::LaneLineUseType>(obj["use_type"].is_string()?atoi(obj["use_type"].get<std::string>().c_str()):obj["use_type"].get<int>());
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, LaneLine &dt)
    {
        dt = from_json_LaneLine(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const LaneLine &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LaneLine &dt)
    {
        return os << to_json(dt).dump();
    }
}
