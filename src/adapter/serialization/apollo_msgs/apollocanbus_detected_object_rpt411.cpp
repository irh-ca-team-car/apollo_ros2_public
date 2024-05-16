#include "adapter/serialization/apollo_msgs/apollocanbus_detected_object_rpt411.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusDetectedObjectRpt411 &msg) {
        nlohmann::json obj;
        obj["frontobjectdistancehighres"] = (msg.frontobjectdistancehighres);
        obj["frontobjectdistancelowres"] = (msg.frontobjectdistancelowres);
        return obj;
    }
    ApollocanbusDetectedObjectRpt411 from_json_ApollocanbusDetectedObjectRpt411 (nlohmann::json obj) {
        ApollocanbusDetectedObjectRpt411 msg;
        if(obj.contains("frontobjectdistancehighres"))
        {
            msg.frontobjectdistancehighres = (obj["frontobjectdistancehighres"].is_string()?atof(obj["frontobjectdistancehighres"].get<std::string>().c_str()):obj["frontobjectdistancehighres"].get<double>());
        }
        if(obj.contains("frontobjectdistancelowres"))
        {
            msg.frontobjectdistancelowres = (obj["frontobjectdistancelowres"].is_string()?atof(obj["frontobjectdistancelowres"].get<std::string>().c_str()):obj["frontobjectdistancelowres"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusDetectedObjectRpt411 from_json<ApollocanbusDetectedObjectRpt411>(nlohmann::json obj){
        return from_json_ApollocanbusDetectedObjectRpt411(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusDetectedObjectRpt411 &dt)
    {
        dt=from_json_ApollocanbusDetectedObjectRpt411(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusDetectedObjectRpt411 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusDetectedObjectRpt411 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
