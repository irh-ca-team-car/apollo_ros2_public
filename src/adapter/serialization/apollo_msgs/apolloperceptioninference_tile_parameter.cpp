#include "adapter/serialization/apollo_msgs/apolloperceptioninference_tile_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceTileParameter &msg) {
        nlohmann::json obj;
        obj["axis"] = (msg.axis);
        obj["tiles"] = (msg.tiles);
        return obj;
    }
    ApolloperceptioninferenceTileParameter from_json_ApolloperceptioninferenceTileParameter (nlohmann::json obj) {
        ApolloperceptioninferenceTileParameter msg;
        if(obj.contains("axis"))
        {
            msg.axis = (obj["axis"].is_string()?atoi(obj["axis"].get<std::string>().c_str()):obj["axis"].get<int>());
        }
        if(obj.contains("tiles"))
        {
            msg.tiles = (obj["tiles"].is_string()?atoi(obj["tiles"].get<std::string>().c_str()):obj["tiles"].get<int>());
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceTileParameter from_json<ApolloperceptioninferenceTileParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceTileParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceTileParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceTileParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceTileParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceTileParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
