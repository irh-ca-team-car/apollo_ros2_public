#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle14f0.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle14f0 &msg) {
        nlohmann::json obj;
        obj["canrxsteeringanglevalidity"] = (msg.canrxsteeringanglevalidity);
        obj["canrxsteeringanglerate"] = (msg.canrxsteeringanglerate);
        obj["canrxsteeringanglesign"] = (msg.canrxsteeringanglesign);
        obj["canrxsteeringangleratesign"] = (msg.canrxsteeringangleratesign);
        obj["canrxsteeringangle"] = (msg.canrxsteeringangle);
        obj["canrxradiuscurvature"] = (msg.canrxradiuscurvature);
        obj["canrxyawratevalidity"] = (msg.canrxyawratevalidity);
        obj["canrxyawrate"] = (msg.canrxyawrate);
        obj["canrxvehiclespeeddirection"] = (msg.canrxvehiclespeeddirection);
        obj["canrxvehiclespeed"] = (msg.canrxvehiclespeed);
        return obj;
    }
    ApollodriversVehicle14f0 from_json_ApollodriversVehicle14f0 (nlohmann::json obj) {
        ApollodriversVehicle14f0 msg;
        if(obj.contains("canrxsteeringanglevalidity"))
        {
            msg.canrxsteeringanglevalidity = (obj["canrxsteeringanglevalidity"].is_string()?atoi(obj["canrxsteeringanglevalidity"].get<std::string>().c_str()):obj["canrxsteeringanglevalidity"].get<int>());
        }
        if(obj.contains("canrxsteeringanglerate"))
        {
            msg.canrxsteeringanglerate = (obj["canrxsteeringanglerate"].is_string()?atoi(obj["canrxsteeringanglerate"].get<std::string>().c_str()):obj["canrxsteeringanglerate"].get<int>());
        }
        if(obj.contains("canrxsteeringanglesign"))
        {
            msg.canrxsteeringanglesign = (obj["canrxsteeringanglesign"].is_string()?atoi(obj["canrxsteeringanglesign"].get<std::string>().c_str()):obj["canrxsteeringanglesign"].get<int>());
        }
        if(obj.contains("canrxsteeringangleratesign"))
        {
            msg.canrxsteeringangleratesign = (obj["canrxsteeringangleratesign"].is_string()?atoi(obj["canrxsteeringangleratesign"].get<std::string>().c_str()):obj["canrxsteeringangleratesign"].get<int>());
        }
        if(obj.contains("canrxsteeringangle"))
        {
            msg.canrxsteeringangle = (obj["canrxsteeringangle"].is_string()?atoi(obj["canrxsteeringangle"].get<std::string>().c_str()):obj["canrxsteeringangle"].get<int>());
        }
        if(obj.contains("canrxradiuscurvature"))
        {
            msg.canrxradiuscurvature = (obj["canrxradiuscurvature"].is_string()?atoi(obj["canrxradiuscurvature"].get<std::string>().c_str()):obj["canrxradiuscurvature"].get<int>());
        }
        if(obj.contains("canrxyawratevalidity"))
        {
            msg.canrxyawratevalidity = (obj["canrxyawratevalidity"].is_string()?atoi(obj["canrxyawratevalidity"].get<std::string>().c_str()):obj["canrxyawratevalidity"].get<int>());
        }
        if(obj.contains("canrxyawrate"))
        {
            msg.canrxyawrate = (obj["canrxyawrate"].is_string()?atof(obj["canrxyawrate"].get<std::string>().c_str()):obj["canrxyawrate"].get<double>());
        }
        if(obj.contains("canrxvehiclespeeddirection"))
        {
            msg.canrxvehiclespeeddirection = (obj["canrxvehiclespeeddirection"].is_string()?atoi(obj["canrxvehiclespeeddirection"].get<std::string>().c_str()):obj["canrxvehiclespeeddirection"].get<int>());
        }
        if(obj.contains("canrxvehiclespeed"))
        {
            msg.canrxvehiclespeed = (obj["canrxvehiclespeed"].is_string()?atof(obj["canrxvehiclespeed"].get<std::string>().c_str()):obj["canrxvehiclespeed"].get<double>());
        }
        return msg;
    }
    template <>
    ApollodriversVehicle14f0 from_json<ApollodriversVehicle14f0>(nlohmann::json obj){
        return from_json_ApollodriversVehicle14f0(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle14f0 &dt)
    {
        dt=from_json_ApollodriversVehicle14f0(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle14f0 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle14f0 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
