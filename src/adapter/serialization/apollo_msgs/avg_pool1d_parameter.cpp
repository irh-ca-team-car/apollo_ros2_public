#include "adapter/serialization/apollo_msgs/avg_pool1d_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const AvgPool1dParameter &msg) {
        nlohmann::json obj;
        obj["kernelsize"] = (msg.kernelsize);
        obj["stride"] = (msg.stride);
        return obj;
    }
    AvgPool1dParameter from_json_AvgPool1dParameter (nlohmann::json obj) {
        AvgPool1dParameter msg;
        if(obj.contains("kernelsize"))
        {
            msg.kernelsize = (obj["kernelsize"].is_string()?atoi(obj["kernelsize"].get<std::string>().c_str()):obj["kernelsize"].get<int>());
        }
        if(obj.contains("stride"))
        {
            msg.stride = (obj["stride"].is_string()?atoi(obj["stride"].get<std::string>().c_str()):obj["stride"].get<int>());
        }
        return msg;
    }
    template <>
    AvgPool1dParameter from_json<AvgPool1dParameter>(nlohmann::json obj){
        return from_json_AvgPool1dParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, AvgPool1dParameter &dt)
    {
        dt=from_json_AvgPool1dParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const AvgPool1dParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const AvgPool1dParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
