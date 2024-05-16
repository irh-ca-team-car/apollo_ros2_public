#include "adapter/serialization/apollo_msgs/apolloplanning_internal_lattice_st_pixel.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalLatticeStPixel &msg) {
        nlohmann::json obj;
        obj["s"] = (msg.s);
        obj["t"] = (msg.t);
        obj["r"] = (msg.r);
        obj["g"] = (msg.g);
        obj["b"] = (msg.b);
        return obj;
    }
    ApolloplanningInternalLatticeStPixel from_json_ApolloplanningInternalLatticeStPixel (nlohmann::json obj) {
        ApolloplanningInternalLatticeStPixel msg;
        if(obj.contains("s"))
        {
            msg.s = (obj["s"].is_string()?atoi(obj["s"].get<std::string>().c_str()):obj["s"].get<int>());
        }
        if(obj.contains("t"))
        {
            msg.t = (obj["t"].is_string()?atoi(obj["t"].get<std::string>().c_str()):obj["t"].get<int>());
        }
        if(obj.contains("r"))
        {
            msg.r = (obj["r"].is_string()?atoi(obj["r"].get<std::string>().c_str()):obj["r"].get<uint32_t>());
        }
        if(obj.contains("g"))
        {
            msg.g = (obj["g"].is_string()?atoi(obj["g"].get<std::string>().c_str()):obj["g"].get<uint32_t>());
        }
        if(obj.contains("b"))
        {
            msg.b = (obj["b"].is_string()?atoi(obj["b"].get<std::string>().c_str()):obj["b"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApolloplanningInternalLatticeStPixel from_json<ApolloplanningInternalLatticeStPixel>(nlohmann::json obj){
        return from_json_ApolloplanningInternalLatticeStPixel(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalLatticeStPixel &dt)
    {
        dt=from_json_ApolloplanningInternalLatticeStPixel(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalLatticeStPixel & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalLatticeStPixel & dt)
    {
        os << to_json(dt);
        return os;
    }
}
