#include "modules/perception/onboard/internal_messages/blob.h"
#include "modules/perception/onboard/internal_messages/image_8u.h"
#include "modules/perception/onboard/internal_messages/impending_collision_edge.h"
#include "modules/perception/onboard/internal_messages/frame_supplement.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::LidarFrameSupplement;
    nlohmann::json to_json(const LidarFrameSupplement &msg)
    {
        nlohmann::json j;
        
        j["on_use"] = msg.on_use;
        if (msg.cloud_ptr != nullptr)
            j["cloud_ptr"] = to_json(*msg.cloud_ptr);
        else
            j["cloud_ptr"] = nullptr;

        return j;
    }
    LidarFrameSupplement from_json_LidarFrameSupplement(nlohmann::json obj)
    {
        LidarFrameSupplement d;
        
        if (obj.contains("on_use"))
            d.on_use = (obj["on_use"].is_string()?(bool)atoi(obj["on_use"].get<std::string>().c_str()):obj["on_use"].get<bool>());
        if (obj.contains("cloud_ptr")){
            if (obj["cloud_ptr"].is_null())
               d.cloud_ptr = nullptr;
            else
               *d.cloud_ptr = from_json_AttributePointCloud<Point<float>>(obj["cloud_ptr"]);}
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, LidarFrameSupplement &dt)
    {
        dt = from_json_LidarFrameSupplement(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const LidarFrameSupplement &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const LidarFrameSupplement &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::RadarFrameSupplement;
    nlohmann::json to_json(const RadarFrameSupplement &msg)
    {
        nlohmann::json j;
        
        j["on_use"] = msg.on_use;

        return j;
    }
    RadarFrameSupplement from_json_RadarFrameSupplement(nlohmann::json obj)
    {
        RadarFrameSupplement d;
        
        if (obj.contains("on_use"))
            d.on_use = (obj["on_use"].is_string()?(bool)atoi(obj["on_use"].get<std::string>().c_str()):obj["on_use"].get<bool>());
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, RadarFrameSupplement &dt)
    {
        dt = from_json_RadarFrameSupplement(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const RadarFrameSupplement &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const RadarFrameSupplement &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::CameraFrameSupplement;
    nlohmann::json to_json(const CameraFrameSupplement &msg)
    {
        nlohmann::json j;
        
        j["on_use"] = msg.on_use;
        if (msg.image_ptr != nullptr)
            j["image_ptr"] = to_json(*msg.image_ptr);
        else
            j["image_ptr"] = nullptr;
        if (msg.image_blob != nullptr)
            j["image_blob"] = to_json(*msg.image_blob);
        else
            j["image_blob"] = nullptr;

        return j;
    }
    CameraFrameSupplement from_json_CameraFrameSupplement(nlohmann::json obj)
    {
        CameraFrameSupplement d;
        
        if (obj.contains("on_use"))
            d.on_use = (obj["on_use"].is_string()?(bool)atoi(obj["on_use"].get<std::string>().c_str()):obj["on_use"].get<bool>());
        if (obj.contains("image_ptr")){
            if (obj["image_ptr"].is_null())
               d.image_ptr = nullptr;
            else
               d.image_ptr = std::make_shared<Image8U>(from_json_Image8U(obj["image_ptr"]));}
        if (obj.contains("image_blob")){
            if (obj["image_blob"].is_null())
               d.image_blob = nullptr;
            else
               d.image_blob = std::make_shared<Blob<uint8_t>>(from_json_Blob<uint8_t>(obj["image_blob"]));}
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, CameraFrameSupplement &dt)
    {
        dt = from_json_CameraFrameSupplement(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const CameraFrameSupplement &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const CameraFrameSupplement &dt)
    {
        return os << to_json(dt).dump();
    }
}

namespace apollo_msgs::msg
{
    using apollo::perception::base::UltrasonicFrameSupplement;
    nlohmann::json to_json(const UltrasonicFrameSupplement &msg)
    {
        nlohmann::json j;
        
        j["on_use"] = msg.on_use;
        if (msg.impending_collision_edges_ptr != nullptr)
            j["impending_collision_edges_ptr"] = to_json(*msg.impending_collision_edges_ptr);
        else
            j["impending_collision_edges_ptr"] = nullptr;

        return j;
    }
    UltrasonicFrameSupplement from_json_UltrasonicFrameSupplement(nlohmann::json obj)
    {
        UltrasonicFrameSupplement d;
        
        if (obj.contains("on_use"))
            d.on_use = (obj["on_use"].is_string()?(bool)atoi(obj["on_use"].get<std::string>().c_str()):obj["on_use"].get<bool>());
        if (obj.contains("impending_collision_edges_ptr")){
            if (obj["impending_collision_edges_ptr"].is_null())
               d.impending_collision_edges_ptr = nullptr;
            else
               *d.impending_collision_edges_ptr = from_json_ImpendingCollisionEdges(obj["impending_collision_edges_ptr"]);}
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, UltrasonicFrameSupplement &dt)
    {
        dt = from_json_UltrasonicFrameSupplement(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const UltrasonicFrameSupplement &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const UltrasonicFrameSupplement &dt)
    {
        return os << to_json(dt).dump();
    }
}
