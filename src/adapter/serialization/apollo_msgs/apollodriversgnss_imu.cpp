#include "adapter/serialization/apollo_msgs/apollodriversgnss_imu.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssImu &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["measurementtime"] = (msg.measurementtime);
        obj["measurementspan"] = (msg.measurementspan);
        obj["linearacceleration"] = to_json(msg.linearacceleration);
        obj["angularvelocity"] = to_json(msg.angularvelocity);
        return obj;
    }
    ApollodriversgnssImu from_json_ApollodriversgnssImu (nlohmann::json obj) {
        ApollodriversgnssImu msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("measurementtime"))
        {
            msg.measurementtime = (obj["measurementtime"].is_string()?atof(obj["measurementtime"].get<std::string>().c_str()):obj["measurementtime"].get<double>());
        }
        if(obj.contains("measurementspan"))
        {
            msg.measurementspan = (obj["measurementspan"].is_string()?(float)atof(obj["measurementspan"].get<std::string>().c_str()):obj["measurementspan"].get<float>());
        }
        if(obj.contains("linearacceleration"))
        {
            msg.linearacceleration = from_json_ApollocommonPoint3D(obj["linearacceleration"]);
        }
        if(obj.contains("angularvelocity"))
        {
            msg.angularvelocity = from_json_ApollocommonPoint3D(obj["angularvelocity"]);
        }
        return msg;
    }
    template <>
    ApollodriversgnssImu from_json<ApollodriversgnssImu>(nlohmann::json obj){
        return from_json_ApollodriversgnssImu(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssImu &dt)
    {
        dt=from_json_ApollodriversgnssImu(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssImu & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssImu & dt)
    {
        os << to_json(dt);
        return os;
    }
}
