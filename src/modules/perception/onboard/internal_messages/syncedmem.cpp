#include "modules/perception/onboard/internal_messages/syncedmem.h"
#include "modules/perception/base/base64.h"
namespace apollo_msgs::msg
{
    using apollo::perception::base::SyncedMemory;
    nlohmann::json to_json(SyncedMemory &msg)
    {
        nlohmann::json j;
        
        j["size_"] = msg.size_;
        j["head_"] = msg.head_;
        j["own_cpu_data_"] = msg.own_cpu_data_;
        j["cpu_malloc_use_cuda_"] = msg.cpu_malloc_use_cuda_;
        j["own_gpu_data_"] = msg.own_gpu_data_;
        j["device_"] = msg.device_;

        msg.to_cpu();
        j["data_"] = base64_encode((BYTE *)msg.cpu_ptr_, msg.size_);

        return j;
    }
    SyncedMemory from_json_SyncedMemory(nlohmann::json obj)
    {
        SyncedMemory d;
        
        if (obj.contains("size_"))
            d.size_ = (obj["size_"].is_string()?(size_t)atoi(obj["size_"].get<std::string>().c_str()):obj["size_"].get<size_t>());
        if (obj.contains("head_"))
            d.head_ = static_cast<apollo::perception::base::SyncedMemory::SyncedHead>(obj["head_"].is_string()?atoi(obj["head_"].get<std::string>().c_str()):obj["head_"].get<int>());
        if (obj.contains("own_cpu_data_"))
            d.own_cpu_data_ = (obj["own_cpu_data_"].is_string()?(bool)atoi(obj["own_cpu_data_"].get<std::string>().c_str()):obj["own_cpu_data_"].get<bool>());
        if (obj.contains("cpu_malloc_use_cuda_"))
            d.cpu_malloc_use_cuda_ = (obj["cpu_malloc_use_cuda_"].is_string()?(bool)atoi(obj["cpu_malloc_use_cuda_"].get<std::string>().c_str()):obj["cpu_malloc_use_cuda_"].get<bool>());
        if (obj.contains("own_gpu_data_"))
            d.own_gpu_data_ = (obj["own_gpu_data_"].is_string()?(bool)atoi(obj["own_gpu_data_"].get<std::string>().c_str()):obj["own_gpu_data_"].get<bool>());
        if (obj.contains("device_"))
            d.device_ = (obj["device_"].is_string()?atoi(obj["device_"].get<std::string>().c_str()):obj["device_"].get<int>());

        d.to_cpu();
        if (obj.contains("data_"))
            base64_decode(obj["data_"].get<std::string>(), (BYTE *)d.cpu_ptr_, d.size_);
        if(d.own_gpu_data_)
            d.to_gpu();

        return d;
    }
    nlohmann::json &operator>>(nlohmann::json &os, SyncedMemory &dt)
    {
        dt = from_json_SyncedMemory(os);
        return os;
    }
    std::ostream &
    operator<<(std::ostream &os, const SyncedMemory &dt)
    {
        SyncedMemory dt2 = dt;
        return os << to_json(dt2).dump();
    }

    close_after_if_not_null &operator<<(close_after_if_not_null &os, const SyncedMemory &dt)
    {
        SyncedMemory dt2 = dt;
        return os << to_json(dt2).dump();
    }
}
