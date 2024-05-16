#include "adapter/serialization/apollo_msgs/apollodrivers_compressed_image.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversCompressedImage &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["frameid"] = (msg.frameid);
        obj["format"] = (msg.format);
        obj["data"] = to_json(msg.data);
        obj["measurementtime"] = (msg.measurementtime);
        obj["frametype"] = (msg.frametype);
        return obj;
    }
    ApollodriversCompressedImage from_json_ApollodriversCompressedImage (nlohmann::json obj) {
        ApollodriversCompressedImage msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("format"))
        {
            msg.format = (obj["format"].is_string()?(obj["format"].get<std::string>().c_str()):obj["format"].get<std::string>());
        }
        if(obj.contains("data"))
        {
            msg.data = from_json_Bytes(obj["data"]);
        }
        if(obj.contains("measurementtime"))
        {
            msg.measurementtime = (obj["measurementtime"].is_string()?atof(obj["measurementtime"].get<std::string>().c_str()):obj["measurementtime"].get<double>());
        }
        if(obj.contains("frametype"))
        {
            msg.frametype = (obj["frametype"].is_string()?atoi(obj["frametype"].get<std::string>().c_str()):obj["frametype"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriversCompressedImage from_json<ApollodriversCompressedImage>(nlohmann::json obj){
        return from_json_ApollodriversCompressedImage(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversCompressedImage &dt)
    {
        dt=from_json_ApollodriversCompressedImage(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversCompressedImage & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversCompressedImage & dt)
    {
        os << to_json(dt);
        return os;
    }
}
