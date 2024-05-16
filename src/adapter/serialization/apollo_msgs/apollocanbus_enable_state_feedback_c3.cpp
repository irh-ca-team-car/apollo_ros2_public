#include "adapter/serialization/apollo_msgs/apollocanbus_enable_state_feedback_c3.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusEnableStateFeedbackC3 &msg) {
        nlohmann::json obj;
        obj["parkingenablestate"] = (msg.parkingenablestate);
        obj["steeringenablestate"] = (msg.steeringenablestate);
        obj["gearenableactual"] = (msg.gearenableactual);
        obj["drivenenablestate"] = (msg.drivenenablestate);
        obj["brakeenablestate"] = (msg.brakeenablestate);
        return obj;
    }
    ApollocanbusEnableStateFeedbackC3 from_json_ApollocanbusEnableStateFeedbackC3 (nlohmann::json obj) {
        ApollocanbusEnableStateFeedbackC3 msg;
        if(obj.contains("parkingenablestate"))
        {
            msg.parkingenablestate = (obj["parkingenablestate"].is_string()?atoi(obj["parkingenablestate"].get<std::string>().c_str()):obj["parkingenablestate"].get<int>());
        }
        if(obj.contains("steeringenablestate"))
        {
            msg.steeringenablestate = (obj["steeringenablestate"].is_string()?atoi(obj["steeringenablestate"].get<std::string>().c_str()):obj["steeringenablestate"].get<int>());
        }
        if(obj.contains("gearenableactual"))
        {
            msg.gearenableactual = (obj["gearenableactual"].is_string()?atoi(obj["gearenableactual"].get<std::string>().c_str()):obj["gearenableactual"].get<int>());
        }
        if(obj.contains("drivenenablestate"))
        {
            msg.drivenenablestate = (obj["drivenenablestate"].is_string()?atoi(obj["drivenenablestate"].get<std::string>().c_str()):obj["drivenenablestate"].get<int>());
        }
        if(obj.contains("brakeenablestate"))
        {
            msg.brakeenablestate = (obj["brakeenablestate"].is_string()?atoi(obj["brakeenablestate"].get<std::string>().c_str()):obj["brakeenablestate"].get<int>());
        }
        return msg;
    }
    template <>
    ApollocanbusEnableStateFeedbackC3 from_json<ApollocanbusEnableStateFeedbackC3>(nlohmann::json obj){
        return from_json_ApollocanbusEnableStateFeedbackC3(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusEnableStateFeedbackC3 &dt)
    {
        dt=from_json_ApollocanbusEnableStateFeedbackC3(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusEnableStateFeedbackC3 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusEnableStateFeedbackC3 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
