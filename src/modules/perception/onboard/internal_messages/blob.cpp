#include "modules/perception/onboard/internal_messages/syncedmem.h"
#include "modules/perception/onboard/internal_messages/blob.h"

namespace apollo_msgs::msg
{
    using apollo::perception::base::Blob;
    template <typename T>
    nlohmann::json to_json(const Blob<T> &msg)
    {
        nlohmann::json j;
        
        if (msg.data_ != nullptr)
            j["data_"] = to_json(*msg.data_);
        else
            j["data_"] = nullptr;
        if (msg.shape_data_ != nullptr)
            j["shape_data_"] = to_json(*msg.shape_data_);
        else
            j["shape_data_"] = nullptr;
        nlohmann::json arr_shape_;
        for (auto it= msg.shape_.begin(); it != msg.shape_.end(); ++it){ 
            arr_shape_.push_back(*it); 
        } 
        j["shape_"] = arr_shape_;
        j["count_"] = msg.count_;
        j["capacity_"] = msg.capacity_;
        j["zuse_cuda_host_malloc_"] = msg.use_cuda_host_malloc_;

        return j;
    }
    template <>
    nlohmann::json to_json(const Blob<uint8_t> &msg)
    {
        return to_json(msg);
    }
    template <typename T>
    Blob<T> from_json_Blob(nlohmann::json obj)
    {
        Blob<T> d;
        
        if (obj.contains("data_")){
            if (obj["data_"].is_null())
               d.data_ = nullptr;
            else
               *d.data_ = from_json_SyncedMemory(obj["data_"]);}
        if (obj.contains("shape_data_")){
            if (obj["shape_data_"].is_null())
               d.shape_data_ = nullptr;
            else
               *d.shape_data_ = from_json_SyncedMemory(obj["data_"]);}
        if(obj.contains("shape_")) 
            for (auto element : obj["shape_"]){ 
                d.shape_.push_back(element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()); 
            }
        if (obj.contains("count_"))
            d.count_ = (obj["count_"].is_string()?atoi(obj["count_"].get<std::string>().c_str()):obj["count_"].get<int>());
        if (obj.contains("capacity_"))
            d.capacity_ = (obj["capacity_"].is_string()?atoi(obj["capacity_"].get<std::string>().c_str()):obj["capacity_"].get<int>());
        if (obj.contains("use_cuda_host_malloc_"))
            d.use_cuda_host_malloc_ = (obj["use_cuda_host_malloc_"].is_string()?(bool)atoi(obj["use_cuda_host_malloc_"].get<std::string>().c_str()):obj["use_cuda_host_malloc_"].get<bool>());
        
        return d;
    }
    template <>
    Blob<uint8_t> from_json<Blob<uint8_t>>(nlohmann::json obj)
    {return from_json_Blob<uint8_t>(obj);}
    template <typename T>
    nlohmann::json &operator>>(nlohmann::json &os, Blob<T> &dt)
    {
        dt = from_json_Blob<T>(os);
        return os;
    }
    template <typename T>
    std::ostream &
    operator<<(std::ostream &os, const Blob<T> &dt)
    {
        return os << to_json(dt).dump();
    }
    template <typename T>
    close_after_if_not_null &operator<<(close_after_if_not_null &os, const Blob<T> &dt)
    {
        return os << to_json(dt).dump();
    }
}
