#include "adapter/serialization/apollo_msgs/dense_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const DenseParameter &msg) {
        nlohmann::json obj;
        obj["units"] = (msg.units);
        obj["activation"] = (msg.activation);
        obj["usebias"] = (msg.usebias);
        obj["weights"] = to_json(msg.weights);
        obj["bias"] = to_json(msg.bias);
        return obj;
    }
    DenseParameter from_json_DenseParameter (nlohmann::json obj) {
        DenseParameter msg;
        if(obj.contains("units"))
        {
            msg.units = (obj["units"].is_string()?atoi(obj["units"].get<std::string>().c_str()):obj["units"].get<int>());
        }
        if(obj.contains("activation"))
        {
            msg.activation = (obj["activation"].is_string()?(obj["activation"].get<std::string>().c_str()):obj["activation"].get<std::string>());
        }
        if(obj.contains("usebias"))
        {
            msg.usebias = (obj["usebias"].is_string()?(bool)atoi(obj["usebias"].get<std::string>().c_str()):obj["usebias"].get<bool>());
        }
        if(obj.contains("weights"))
        {
            msg.weights = from_json_TensorParameter(obj["weights"]);
        }
        if(obj.contains("bias"))
        {
            msg.bias = from_json_TensorParameter(obj["bias"]);
        }
        return msg;
    }
    template <>
    DenseParameter from_json<DenseParameter>(nlohmann::json obj){
        return from_json_DenseParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, DenseParameter &dt)
    {
        dt=from_json_DenseParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const DenseParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const DenseParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
