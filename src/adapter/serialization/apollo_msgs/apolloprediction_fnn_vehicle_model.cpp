#include "adapter/serialization/apollo_msgs/apolloprediction_fnn_vehicle_model.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionFnnVehicleModel &msg) {
        nlohmann::json obj;
        obj["diminput"] = (msg.diminput);
        obj["samplesmean"] = to_json(msg.samplesmean);
        obj["samplesstd"] = to_json(msg.samplesstd);
        obj["numlayer"] = (msg.numlayer);
        nlohmann::json arr_layer;
        for (auto it = msg.layer.begin(); it != msg.layer.end(); ++it) {
            arr_layer.push_back(to_json(*it));
        }
        obj["layer"] = arr_layer;
        obj["dimoutput"] = (msg.dimoutput);
        return obj;
    }
    ApollopredictionFnnVehicleModel from_json_ApollopredictionFnnVehicleModel (nlohmann::json obj) {
        ApollopredictionFnnVehicleModel msg;
        if(obj.contains("diminput"))
        {
            msg.diminput = (obj["diminput"].is_string()?atoi(obj["diminput"].get<std::string>().c_str()):obj["diminput"].get<int>());
        }
        if(obj.contains("samplesmean"))
        {
            msg.samplesmean = from_json_ApollopredictionVector(obj["samplesmean"]);
        }
        if(obj.contains("samplesstd"))
        {
            msg.samplesstd = from_json_ApollopredictionVector(obj["samplesstd"]);
        }
        if(obj.contains("numlayer"))
        {
            msg.numlayer = (obj["numlayer"].is_string()?atoi(obj["numlayer"].get<std::string>().c_str()):obj["numlayer"].get<int>());
        }
        if(obj.contains("layer"))
        {
            if(obj["layer"].is_array())
            {
                for (auto& element : obj["layer"])
                {
                    msg.layer.push_back(from_json_ApollopredictionLayer(element));
                }
            }
            else
            {
                msg.layer.push_back(from_json_ApollopredictionLayer(obj["layer"]));
            }
        }
        if(obj.contains("dimoutput"))
        {
            msg.dimoutput = (obj["dimoutput"].is_string()?atoi(obj["dimoutput"].get<std::string>().c_str()):obj["dimoutput"].get<int>());
        }
        return msg;
    }
    template <>
    ApollopredictionFnnVehicleModel from_json<ApollopredictionFnnVehicleModel>(nlohmann::json obj){
        return from_json_ApollopredictionFnnVehicleModel(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionFnnVehicleModel &dt)
    {
        dt=from_json_ApollopredictionFnnVehicleModel(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionFnnVehicleModel & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionFnnVehicleModel & dt)
    {
        os << to_json(dt);
        return os;
    }
}
