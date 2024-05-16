#include "adapter/serialization/apollo_msgs/apollocanbus_sonar.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusSonar &msg) {
        nlohmann::json obj;
        obj["range"] = (msg.range);
        obj["translation"] = to_json(msg.translation);
        obj["rotation"] = to_json(msg.rotation);
        return obj;
    }
    ApollocanbusSonar from_json_ApollocanbusSonar (nlohmann::json obj) {
        ApollocanbusSonar msg;
        if(obj.contains("range"))
        {
            msg.range = (obj["range"].is_string()?atof(obj["range"].get<std::string>().c_str()):obj["range"].get<double>());
        }
        if(obj.contains("translation"))
        {
            msg.translation = from_json_ApollocommonPoint3D(obj["translation"]);
        }
        if(obj.contains("rotation"))
        {
            msg.rotation = from_json_ApollocommonQuaternion(obj["rotation"]);
        }
        return msg;
    }
    template <>
    ApollocanbusSonar from_json<ApollocanbusSonar>(nlohmann::json obj){
        return from_json_ApollocanbusSonar(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusSonar &dt)
    {
        dt=from_json_ApollocanbusSonar(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusSonar & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusSonar & dt)
    {
        os << to_json(dt);
        return os;
    }
}
