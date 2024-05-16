#include "adapter/serialization/apollo_msgs/apollostatic_transform_conf.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollostaticTransformConf &msg) {
        nlohmann::json obj;
        nlohmann::json arr_extrinsicfile;
        for (auto it = msg.extrinsicfile.begin(); it != msg.extrinsicfile.end(); ++it) {
            arr_extrinsicfile.push_back(to_json(*it));
        }
        obj["extrinsicfile"] = arr_extrinsicfile;
        return obj;
    }
    ApollostaticTransformConf from_json_ApollostaticTransformConf (nlohmann::json obj) {
        ApollostaticTransformConf msg;
        if(obj.contains("extrinsicfile"))
        {
            if(obj["extrinsicfile"].is_array())
            {
                for (auto& element : obj["extrinsicfile"])
                {
                    msg.extrinsicfile.push_back(from_json_ApollostaticTransformExtrinsicFile(element));
                }
            }
            else
            {
                msg.extrinsicfile.push_back(from_json_ApollostaticTransformExtrinsicFile(obj["extrinsicfile"]));
            }
        }
        return msg;
    }
    template <>
    ApollostaticTransformConf from_json<ApollostaticTransformConf>(nlohmann::json obj){
        return from_json_ApollostaticTransformConf(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollostaticTransformConf &dt)
    {
        dt=from_json_ApollostaticTransformConf(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollostaticTransformConf & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollostaticTransformConf & dt)
    {
        os << to_json(dt);
        return os;
    }
}
