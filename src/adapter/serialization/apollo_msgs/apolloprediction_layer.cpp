#include "adapter/serialization/apollo_msgs/apolloprediction_layer.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionLayer &msg) {
        nlohmann::json obj;
        obj["layerinputdim"] = (msg.layerinputdim);
        obj["layeroutputdim"] = (msg.layeroutputdim);
        obj["layerinputweight"] = to_json(msg.layerinputweight);
        obj["layerbias"] = to_json(msg.layerbias);
        obj["layeractivationfunc"] = (msg.layeractivationfunc);
        return obj;
    }
    ApollopredictionLayer from_json_ApollopredictionLayer (nlohmann::json obj) {
        ApollopredictionLayer msg;
        if(obj.contains("layerinputdim"))
        {
            msg.layerinputdim = (obj["layerinputdim"].is_string()?atoi(obj["layerinputdim"].get<std::string>().c_str()):obj["layerinputdim"].get<int>());
        }
        if(obj.contains("layeroutputdim"))
        {
            msg.layeroutputdim = (obj["layeroutputdim"].is_string()?atoi(obj["layeroutputdim"].get<std::string>().c_str()):obj["layeroutputdim"].get<int>());
        }
        if(obj.contains("layerinputweight"))
        {
            msg.layerinputweight = from_json_ApollopredictionMatrix(obj["layerinputweight"]);
        }
        if(obj.contains("layerbias"))
        {
            msg.layerbias = from_json_ApollopredictionVector(obj["layerbias"]);
        }
        if(obj.contains("layeractivationfunc"))
        {
            msg.layeractivationfunc = (obj["layeractivationfunc"].is_string()?atoi(obj["layeractivationfunc"].get<std::string>().c_str()):obj["layeractivationfunc"].get<int>());
        }
        return msg;
    }
    template <>
    ApollopredictionLayer from_json<ApollopredictionLayer>(nlohmann::json obj){
        return from_json_ApollopredictionLayer(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionLayer &dt)
    {
        dt=from_json_ApollopredictionLayer(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionLayer & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionLayer & dt)
    {
        os << to_json(dt);
        return os;
    }
}
