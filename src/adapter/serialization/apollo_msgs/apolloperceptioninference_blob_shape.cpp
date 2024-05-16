#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_shape.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceBlobShape &msg) {
        nlohmann::json obj;
        nlohmann::json arr_dim;
        for (auto it = msg.dim.begin(); it != msg.dim.end(); ++it) {
            arr_dim.push_back((*it));
        }
        obj["dim"] = arr_dim;
        return obj;
    }
    ApolloperceptioninferenceBlobShape from_json_ApolloperceptioninferenceBlobShape (nlohmann::json obj) {
        ApolloperceptioninferenceBlobShape msg;
        if(obj.contains("dim"))
        {
            if(obj["dim"].is_array())
            {
                for (auto& element : obj["dim"])
                {
                    msg.dim.push_back((element.is_string()?atol(element.get<std::string>().c_str()):element.get<long>()));
                }
            }
            else
            {
                msg.dim.push_back((obj["dim"].is_string()?atol(obj["dim"].get<std::string>().c_str()):obj["dim"].get<long>()));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceBlobShape from_json<ApolloperceptioninferenceBlobShape>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceBlobShape(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceBlobShape &dt)
    {
        dt=from_json_ApolloperceptioninferenceBlobShape(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceBlobShape & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceBlobShape & dt)
    {
        os << to_json(dt);
        return os;
    }
}
