#include "adapter/serialization/apollo_msgs/apolloprediction_concatenate_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionConcatenateParameter &msg) {
        nlohmann::json obj;
        obj["axis"] = (msg.axis);
        return obj;
    }
    ApollopredictionConcatenateParameter from_json_ApollopredictionConcatenateParameter (nlohmann::json obj) {
        ApollopredictionConcatenateParameter msg;
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        return msg;
    }
    template <>
    ApollopredictionConcatenateParameter from_json<ApollopredictionConcatenateParameter>(nlohmann::json obj){
        return from_json_ApollopredictionConcatenateParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionConcatenateParameter &dt)
    {
        dt=from_json_ApollopredictionConcatenateParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionConcatenateParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionConcatenateParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
