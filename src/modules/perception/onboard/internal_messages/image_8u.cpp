#include "modules/perception/onboard/internal_messages/blob.h"
#include "modules/perception/onboard/internal_messages/image_8u.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::Image8U;
    nlohmann::json to_json(const Image8U &msg)
    {
        nlohmann::json j;

        j["rows_"] = msg.rows_;
        j["cols_"] = msg.cols_;
        j["type_"] = msg.type_;
        j["channels_"] = msg.channels_;
        j["width_step_"] = msg.width_step_;
        if (msg.blob_ != nullptr)
            j["blob_"] = to_json(*msg.blob_);
        else
            j["blob_"] = nullptr;
        j["offset_"] = msg.offset_;

        return j;
    }
    Image8U from_json_Image8U(nlohmann::json obj)
    {
        Image8U d;
        
        if (obj.contains("rows_"))
            d.rows_ = (obj["rows_"].is_string()?atoi(obj["rows_"].get<std::string>().c_str()):obj["rows_"].get<int>());
        if (obj.contains("cols_"))
            d.cols_ = (obj["cols_"].is_string()?atoi(obj["cols_"].get<std::string>().c_str()):obj["cols_"].get<int>());
        if (obj.contains("type_"))
            d.type_ = static_cast<apollo::perception::base::Color>(obj["type_"].is_string()?atoi(obj["type_"].get<std::string>().c_str()):obj["type_"].get<int>());
        if (obj.contains("channels_"))
            d.channels_ = (obj["channels_"].is_string()?atoi(obj["channels_"].get<std::string>().c_str()):obj["channels_"].get<int>());
        if (obj.contains("width_step_"))
            d.width_step_ = (obj["width_step_"].is_string()?atoi(obj["width_step_"].get<std::string>().c_str()):obj["width_step_"].get<int>());
        if (obj.contains("blob_")){
            if (obj["blob_"].is_null())
               d.blob_ = nullptr;
            else
               d.blob_ = std::make_shared<Blob<uint8_t>>(from_json_Blob<uint8_t>(obj["blob_"]));}
        if (obj.contains("offset_"))
            d.offset_ = (obj["offset_"].is_string()?atoi(obj["offset_"].get<std::string>().c_str()):obj["offset_"].get<int>());
        
        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, Image8U &dt)
    {
        dt = from_json_Image8U(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const Image8U &dt)
    {
        return os << to_json(dt).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Image8U &dt)
    {
        return os << to_json(dt).dump();
    }
}
