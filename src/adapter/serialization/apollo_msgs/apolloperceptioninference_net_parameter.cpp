#include "adapter/serialization/apollo_msgs/apolloperceptioninference_net_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceNetParameter &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        nlohmann::json arr_input;
        for (auto it = msg.input.begin(); it != msg.input.end(); ++it) {
            arr_input.push_back((*it));
        }
        obj["input"] = arr_input;
        nlohmann::json arr_inputshape;
        for (auto it = msg.inputshape.begin(); it != msg.inputshape.end(); ++it) {
            arr_inputshape.push_back(to_json(*it));
        }
        obj["inputshape"] = arr_inputshape;
        nlohmann::json arr_inputdim;
        for (auto it = msg.inputdim.begin(); it != msg.inputdim.end(); ++it) {
            arr_inputdim.push_back((*it));
        }
        obj["inputdim"] = arr_inputdim;
        obj["forcebackward"] = (msg.forcebackward);
        obj["state"] = to_json(msg.state);
        obj["debuginfo"] = (msg.debuginfo);
        nlohmann::json arr_layer;
        for (auto it = msg.layer.begin(); it != msg.layer.end(); ++it) {
            arr_layer.push_back(to_json(*it));
        }
        obj["layer"] = arr_layer;
        nlohmann::json arr_layers;
        for (auto it = msg.layers.begin(); it != msg.layers.end(); ++it) {
            arr_layers.push_back(to_json(*it));
        }
        obj["layers"] = arr_layers;
        return obj;
    }
    ApolloperceptioninferenceNetParameter from_json_ApolloperceptioninferenceNetParameter (nlohmann::json obj) {
        ApolloperceptioninferenceNetParameter msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("input"))
        {
            if(obj["input"].is_array())
            {
                for (auto& element : obj["input"])
                {
                    msg.input.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.input.push_back((obj["input"].is_string()?(obj["input"].get<std::string>().c_str()):obj["input"].get<std::string>()));
            }
        }
        if(obj.contains("inputshape"))
        {
            if(obj["inputshape"].is_array())
            {
                for (auto& element : obj["inputshape"])
                {
                    msg.inputshape.push_back(from_json_ApolloperceptioninferenceBlobShape(element));
                }
            }
            else
            {
                msg.inputshape.push_back(from_json_ApolloperceptioninferenceBlobShape(obj["inputshape"]));
            }
        }
        if(obj.contains("inputdim"))
        {
            if(obj["inputdim"].is_array())
            {
                for (auto& element : obj["inputdim"])
                {
                    msg.inputdim.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.inputdim.push_back((obj["inputdim"].is_string()?atoi(obj["inputdim"].get<std::string>().c_str()):obj["inputdim"].get<int>()));
            }
        }
        if(obj.contains("forcebackward"))
        {
            msg.forcebackward = (obj["forcebackward"].is_string()?(bool)atoi(obj["forcebackward"].get<std::string>().c_str()):obj["forcebackward"].get<bool>());
        }
        if(obj.contains("state"))
        {
            msg.state = from_json_ApolloperceptioninferenceNetState(obj["state"]);
        }
        if(obj.contains("debuginfo"))
        {
            msg.debuginfo = (obj["debuginfo"].is_string()?(bool)atoi(obj["debuginfo"].get<std::string>().c_str()):obj["debuginfo"].get<bool>());
        }
        if(obj.contains("layer"))
        {
            if(obj["layer"].is_array())
            {
                for (auto& element : obj["layer"])
                {
                    msg.layer.push_back(from_json_ApolloperceptioninferenceLayerParameter(element));
                }
            }
            else
            {
                msg.layer.push_back(from_json_ApolloperceptioninferenceLayerParameter(obj["layer"]));
            }
        }
        if(obj.contains("layers"))
        {
            if(obj["layers"].is_array())
            {
                for (auto& element : obj["layers"])
                {
                    msg.layers.push_back(from_json_ApolloperceptioninferenceV1LayerParameter(element));
                }
            }
            else
            {
                msg.layers.push_back(from_json_ApolloperceptioninferenceV1LayerParameter(obj["layers"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceNetParameter from_json<ApolloperceptioninferenceNetParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceNetParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceNetParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceNetParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceNetParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceNetParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
