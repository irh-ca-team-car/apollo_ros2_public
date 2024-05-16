#include "adapter/serialization/apollo_msgs/apollostatic_transform_extrinsic_file.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostaticTransformExtrinsicFile &msg) {
        nlohmann::json obj;
        obj["frameid"] = (msg.frameid);
        obj["childframeid"] = (msg.childframeid);
        obj["filepath"] = (msg.filepath);
        obj["enable"] = (msg.enable);
        return obj;
    }
    ApollostaticTransformExtrinsicFile from_json_ApollostaticTransformExtrinsicFile (nlohmann::json obj) {
        ApollostaticTransformExtrinsicFile msg;
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("childframeid"))
        {
            msg.childframeid = (obj["childframeid"].is_string()?(obj["childframeid"].get<std::string>().c_str()):obj["childframeid"].get<std::string>());
        }
        if(obj.contains("filepath"))
        {
            msg.filepath = (obj["filepath"].is_string()?(obj["filepath"].get<std::string>().c_str()):obj["filepath"].get<std::string>());
        }
        if(obj.contains("enable"))
        {
            msg.enable = (obj["enable"].is_string()?(bool)atoi(obj["enable"].get<std::string>().c_str()):obj["enable"].get<bool>());
        }
        return msg;
    }
    template <>
    ApollostaticTransformExtrinsicFile from_json<ApollostaticTransformExtrinsicFile>(nlohmann::json obj){
        return from_json_ApollostaticTransformExtrinsicFile(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostaticTransformExtrinsicFile &dt)
    {
        dt=from_json_ApollostaticTransformExtrinsicFile(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostaticTransformExtrinsicFile & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostaticTransformExtrinsicFile & dt)
    {
        os << to_json(dt);
        return os;
    }
}
