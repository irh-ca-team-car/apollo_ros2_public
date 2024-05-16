#include "adapter/serialization/apollo_msgs/fnn_model.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const FnnModel &msg) {
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
    FnnModel from_json_FnnModel (nlohmann::json obj) {
        FnnModel msg;
        if(obj.contains("diminput"))
        {
            msg.diminput = (obj["diminput"].is_string()?atoi(obj["diminput"].get<std::string>().c_str()):obj["diminput"].get<int>());
        }
        if(obj.contains("samplesmean"))
        {
            msg.samplesmean = from_json_Vector(obj["samplesmean"]);
        }
        if(obj.contains("samplesstd"))
        {
            msg.samplesstd = from_json_Vector(obj["samplesstd"]);
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
                    msg.layer.push_back(from_json_Layer(element));
                }
            }
            else
            {
                msg.layer.push_back(from_json_Layer(obj["layer"]));
            }
        }
        if(obj.contains("dimoutput"))
        {
            msg.dimoutput = (obj["dimoutput"].is_string()?atoi(obj["dimoutput"].get<std::string>().c_str()):obj["dimoutput"].get<int>());
        }
        return msg;
    }
    template <>
    FnnModel from_json<FnnModel>(nlohmann::json obj){
        return from_json_FnnModel(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, FnnModel &dt)
    {
        dt=from_json_FnnModel(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const FnnModel & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const FnnModel & dt)
    {
        os << to_json(dt);
        return os;
    }
}
