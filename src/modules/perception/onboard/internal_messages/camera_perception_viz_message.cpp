#include "modules/perception/onboard/internal_messages/lane_struct.h"
#include "modules/perception/onboard/internal_messages/object.h"
#include "modules/perception/onboard/internal_messages/blob.h"
#include "modules/perception/onboard/internal_messages/camera_perception_viz_message.h"

namespace apollo_msgs::msg
{
    using apollo::perception::onboard::CameraPerceptionVizMessage;
    nlohmann::json to_json(const CameraPerceptionVizMessage &msg)
    {
        nlohmann::json j;

        j["camera_name_"] = msg.camera_name_;
        j["type_name_"] = msg.type_name_;
        j["msg_timestamp_"] = msg.msg_timestamp_;
        nlohmann::json arr_pose_camera_to_world_;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                arr_pose_camera_to_world_.push_back(msg.pose_camera_to_world_(i,j));
            }
        }
        j["pose_camera_to_world_"] = arr_pose_camera_to_world_;
        if (msg.image_blob_ != nullptr)
            j["image_blob_"] = to_json(*msg.image_blob_);
        else
            j["image_blob_"] = nullptr;
        nlohmann::json arr_camera_objects_;
        for (auto it= msg.camera_objects_.begin(); it != msg.camera_objects_.end(); ++it){
            if (*it != nullptr)
                arr_camera_objects_.push_back(to_json(**it));
            else
                arr_camera_objects_.push_back(nullptr); 
        }
        j["camera_objects_"] = arr_camera_objects_;
        nlohmann::json arr_lane_objects_;
        for (auto it= msg.lane_objects_.begin(); it != msg.lane_objects_.end(); ++it){ 
            arr_lane_objects_.push_back(to_json(*it)); 
        } 
        j["lane_objects_"] = arr_lane_objects_;
        j["error_code_"] = msg.error_code_;

        return j;
    }
    CameraPerceptionVizMessage from_json_CameraPerceptionVizMessage(nlohmann::json obj)
    {
        CameraPerceptionVizMessage d;
        
        if (obj.contains("camera_name_"))
            d.camera_name_ = obj["camera_name_"].get<std::string>();
        if (obj.contains("type_name_"))
            d.type_name_ = obj["type_name_"].get<std::string>();
        if (obj.contains("msg_timestamp_"))
            d.msg_timestamp_ = (obj["msg_timestamp_"].is_string()?atof(obj["msg_timestamp_"].get<std::string>().c_str()):obj["msg_timestamp_"].get<double>());
        if (obj.contains("pose_camera_to_world_"))
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    d.pose_camera_to_world_(i,j) = (obj["pose_camera_to_world_"][i*4+j].is_string()?atof(obj["pose_camera_to_world_"][i*4+j].get<std::string>().c_str()):obj["pose_camera_to_world_"][i*4+j].get<double>());
                }
            }
        if (obj.contains("image_blob_")){
            if (obj["image_blob_"].is_null())
               d.image_blob_ = nullptr;
            else
               *d.image_blob_ = from_json_Blob<uint8_t>(obj["image_blob_"]);}
        if(obj.contains("camera_objects_")) 
            for (auto element : obj["camera_objects_"]){
                if (element.is_null())
                    d.camera_objects_.push_back(nullptr);
                else{
                    std::shared_ptr<Object> inter;
                    *inter = from_json_Object(element);
                    d.camera_objects_.push_back(inter);}
            }
        if(obj.contains("lane_objects_")) 
            for (auto element : obj["lane_objects_"]){ 
                d.lane_objects_.push_back(from_json_LaneLine(element)); 
            }
        if (obj.contains("error_code_"))
            d.error_code_ = static_cast<apollo::common::ErrorCode>(obj["error_code_"].is_string()?atoi(obj["error_code_"].get<std::string>().c_str()):obj["error_code_"].get<int>());
        
        return d;
    }
    template <>
    CameraPerceptionVizMessage from_json<CameraPerceptionVizMessage>(nlohmann::json obj)
    {
        return from_json_CameraPerceptionVizMessage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, CameraPerceptionVizMessage &dt)
    {
        dt = from_json_CameraPerceptionVizMessage(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const CameraPerceptionVizMessage &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const CameraPerceptionVizMessage &dt)
    {
        return os << to_json(dt).dump();
    }
}
