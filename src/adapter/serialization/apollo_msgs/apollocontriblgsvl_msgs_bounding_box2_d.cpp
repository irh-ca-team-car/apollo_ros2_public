#include "adapter/serialization/apollo_msgs/apollocontriblgsvl_msgs_bounding_box2_d.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontriblgsvlMsgsBoundingBox2D &msg) {
        nlohmann::json obj;
        obj["x"] = (msg.x);
        obj["y"] = (msg.y);
        obj["width"] = (msg.width);
        obj["height"] = (msg.height);
        return obj;
    }
    ApollocontriblgsvlMsgsBoundingBox2D from_json_ApollocontriblgsvlMsgsBoundingBox2D (nlohmann::json obj) {
        ApollocontriblgsvlMsgsBoundingBox2D msg;
        if(obj.contains("x"))
        {
            msg.x = (obj["x"].is_string()?(float)atof(obj["x"].get<std::string>().c_str()):obj["x"].get<float>());
        }
        if(obj.contains("y"))
        {
            msg.y = (obj["y"].is_string()?(float)atof(obj["y"].get<std::string>().c_str()):obj["y"].get<float>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?(float)atof(obj["width"].get<std::string>().c_str()):obj["width"].get<float>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?(float)atof(obj["height"].get<std::string>().c_str()):obj["height"].get<float>());
        }
        return msg;
    }
    template <>
    ApollocontriblgsvlMsgsBoundingBox2D from_json<ApollocontriblgsvlMsgsBoundingBox2D>(nlohmann::json obj){
        return from_json_ApollocontriblgsvlMsgsBoundingBox2D(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontriblgsvlMsgsBoundingBox2D &dt)
    {
        dt=from_json_ApollocontriblgsvlMsgsBoundingBox2D(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontriblgsvlMsgsBoundingBox2D & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontriblgsvlMsgsBoundingBox2D & dt)
    {
        os << to_json(dt);
        return os;
    }
}
