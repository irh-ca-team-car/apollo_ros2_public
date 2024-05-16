#include "adapter/serialization/apollo_msgs/apollodrivers_image.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversImage &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["frameid"] = (msg.frameid);
        obj["measurementtime"] = (msg.measurementtime);
        obj["height"] = (msg.height);
        obj["width"] = (msg.width);
        obj["encoding"] = (msg.encoding);
        obj["step"] = (msg.step);
        obj["data"] = to_json(msg.data);
        return obj;
    }
    ApollodriversImage from_json_ApollodriversImage (nlohmann::json obj) {
        ApollodriversImage msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("measurementtime"))
        {
            msg.measurementtime = (obj["measurementtime"].is_string()?atof(obj["measurementtime"].get<std::string>().c_str()):obj["measurementtime"].get<double>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atoi(obj["height"].get<std::string>().c_str()):obj["height"].get<uint32_t>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<uint32_t>());
        }
        if(obj.contains("encoding"))
        {
            msg.encoding = (obj["encoding"].is_string()?(obj["encoding"].get<std::string>().c_str()):obj["encoding"].get<std::string>());
        }
        if(obj.contains("step"))
        {
            msg.step = (obj["step"].is_string()?atoi(obj["step"].get<std::string>().c_str()):obj["step"].get<uint32_t>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_Bytes(obj["data"]);
        }
        return msg;
    }
    template <>
    ApollodriversImage from_json<ApollodriversImage>(nlohmann::json obj){
        return from_json_ApollodriversImage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversImage &dt)
    {
        dt=from_json_ApollodriversImage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversImage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversImage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
