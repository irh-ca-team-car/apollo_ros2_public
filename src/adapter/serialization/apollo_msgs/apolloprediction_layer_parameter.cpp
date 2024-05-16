#include "adapter/serialization/apollo_msgs/apolloprediction_layer_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLayerParameter &msg) {
        nlohmann::json obj;
        obj["type"] = (msg.type);
        obj["name"] = (msg.name);
        obj["ordernumber"] = (msg.ordernumber);
        obj["oneoflayers"] = to_json(msg.oneoflayers);
        return obj;
    }
    ApollopredictionLayerParameter from_json_ApollopredictionLayerParameter (nlohmann::json obj) {
        ApollopredictionLayerParameter msg;
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?(obj["type"].get<std::string>().c_str()):obj["type"].get<std::string>());
        }
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("ordernumber"))
        {
            msg.ordernumber = (obj["ordernumber"].is_string()?atoi(obj["ordernumber"].get<std::string>().c_str()):obj["ordernumber"].get<int>());
        }
        if(obj.contains("oneoflayers"))
        {
            msg.oneoflayers = from_json_ApollopredictionLayerParameteroneofLayers(obj["oneoflayers"]);
        }
        return msg;
    }
    template <>
    ApollopredictionLayerParameter from_json<ApollopredictionLayerParameter>(nlohmann::json obj){
        return from_json_ApollopredictionLayerParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLayerParameter &dt)
    {
        dt=from_json_ApollopredictionLayerParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLayerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLayerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
