#include "adapter/serialization/apollo_msgs/apolloprediction_avg_pool1d_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionAvgPool1dParameter &msg) {
        nlohmann::json obj;
        obj["kernelsize"] = (msg.kernelsize);
        obj["stride"] = (msg.stride);
        return obj;
    }
    ApollopredictionAvgPool1dParameter from_json_ApollopredictionAvgPool1dParameter (nlohmann::json obj) {
        ApollopredictionAvgPool1dParameter msg;
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
    ApollopredictionAvgPool1dParameter from_json<ApollopredictionAvgPool1dParameter>(nlohmann::json obj){
        return from_json_ApollopredictionAvgPool1dParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionAvgPool1dParameter &dt)
    {
        dt=from_json_ApollopredictionAvgPool1dParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionAvgPool1dParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionAvgPool1dParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
