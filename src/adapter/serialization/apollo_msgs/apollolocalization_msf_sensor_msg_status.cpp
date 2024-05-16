#include "adapter/serialization/apollo_msgs/apollolocalization_msf_sensor_msg_status.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationMsfSensorMsgStatus &msg) {
        nlohmann::json obj;
        obj["imudelaystatus"] = (msg.imudelaystatus);
        obj["imumissingstatus"] = (msg.imumissingstatus);
        obj["imudatastatus"] = (msg.imudatastatus);
        return obj;
    }
    ApollolocalizationMsfSensorMsgStatus from_json_ApollolocalizationMsfSensorMsgStatus (nlohmann::json obj) {
        ApollolocalizationMsfSensorMsgStatus msg;
        if(obj.contains("imudelaystatus"))
        {
            msg.imudelaystatus = (obj["imudelaystatus"].is_string()?atoi(obj["imudelaystatus"].get<std::string>().c_str()):obj["imudelaystatus"].get<int>());
        }
        if(obj.contains("imumissingstatus"))
        {
            msg.imumissingstatus = (obj["imumissingstatus"].is_string()?atoi(obj["imumissingstatus"].get<std::string>().c_str()):obj["imumissingstatus"].get<int>());
        }
        if(obj.contains("imudatastatus"))
        {
            msg.imudatastatus = (obj["imudatastatus"].is_string()?atoi(obj["imudatastatus"].get<std::string>().c_str()):obj["imudatastatus"].get<int>());
        }
        return msg;
    }
    template <>
    ApollolocalizationMsfSensorMsgStatus from_json<ApollolocalizationMsfSensorMsgStatus>(nlohmann::json obj){
        return from_json_ApollolocalizationMsfSensorMsgStatus(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationMsfSensorMsgStatus &dt)
    {
        dt=from_json_ApollolocalizationMsfSensorMsgStatus(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationMsfSensorMsgStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationMsfSensorMsgStatus & dt)
    {
        os << to_json(dt);
        return os;
    }
}
