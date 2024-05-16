#include "adapter/serialization/apollo_msgs/classify_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ClassifyParameter &msg) {
        nlohmann::json obj;
        obj["linear0"] = to_json(msg.linear0);
        obj["activation1"] = to_json(msg.activation1);
        obj["linear3"] = to_json(msg.linear3);
        obj["activation4"] = to_json(msg.activation4);
        obj["linear6"] = to_json(msg.linear6);
        obj["activation7"] = to_json(msg.activation7);
        obj["linear9"] = to_json(msg.linear9);
        obj["activation10"] = to_json(msg.activation10);
        return obj;
    }
    ClassifyParameter from_json_ClassifyParameter (nlohmann::json obj) {
        ClassifyParameter msg;
        if(obj.contains("linear0"))
        {
            msg.linear0 = from_json_DenseParameter(obj["linear0"]);
        }
        if(obj.contains("activation1"))
        {
            msg.activation1 = from_json_ActivationParameter(obj["activation1"]);
        }
        if(obj.contains("linear3"))
        {
            msg.linear3 = from_json_DenseParameter(obj["linear3"]);
        }
        if(obj.contains("activation4"))
        {
            msg.activation4 = from_json_ActivationParameter(obj["activation4"]);
        }
        if(obj.contains("linear6"))
        {
            msg.linear6 = from_json_DenseParameter(obj["linear6"]);
        }
        if(obj.contains("activation7"))
        {
            msg.activation7 = from_json_ActivationParameter(obj["activation7"]);
        }
        if(obj.contains("linear9"))
        {
            msg.linear9 = from_json_DenseParameter(obj["linear9"]);
        }
        if(obj.contains("activation10"))
        {
            msg.activation10 = from_json_ActivationParameter(obj["activation10"]);
        }
        return msg;
    }
    template <>
    ClassifyParameter from_json<ClassifyParameter>(nlohmann::json obj){
        return from_json_ClassifyParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ClassifyParameter &dt)
    {
        dt=from_json_ClassifyParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ClassifyParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ClassifyParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
