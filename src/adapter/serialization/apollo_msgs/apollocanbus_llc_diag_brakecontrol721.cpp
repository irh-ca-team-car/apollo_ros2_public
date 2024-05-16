#include "adapter/serialization/apollo_msgs/apollocanbus_llc_diag_brakecontrol721.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocanbusLlcDiagBrakecontrol721 &msg) {
        nlohmann::json obj;
        obj["llcdbgbrakepidcontributionp"] = (msg.llcdbgbrakepidcontributionp);
        obj["llcdbgbrakepidcontributioni"] = (msg.llcdbgbrakepidcontributioni);
        obj["llcdbgbrakepidcontributiond"] = (msg.llcdbgbrakepidcontributiond);
        obj["llcdbgbrakepidoutput"] = (msg.llcdbgbrakepidoutput);
        obj["llcdbgbrakepiderror"] = (msg.llcdbgbrakepiderror);
        obj["llcdbgbrakefeedforward"] = (msg.llcdbgbrakefeedforward);
        return obj;
    }
    ApollocanbusLlcDiagBrakecontrol721 from_json_ApollocanbusLlcDiagBrakecontrol721 (nlohmann::json obj) {
        ApollocanbusLlcDiagBrakecontrol721 msg;
        if(obj.contains("llcdbgbrakepidcontributionp"))
        {
            msg.llcdbgbrakepidcontributionp = (obj["llcdbgbrakepidcontributionp"].is_string()?atof(obj["llcdbgbrakepidcontributionp"].get<std::string>().c_str()):obj["llcdbgbrakepidcontributionp"].get<double>());
        }
        if(obj.contains("llcdbgbrakepidcontributioni"))
        {
            msg.llcdbgbrakepidcontributioni = (obj["llcdbgbrakepidcontributioni"].is_string()?atof(obj["llcdbgbrakepidcontributioni"].get<std::string>().c_str()):obj["llcdbgbrakepidcontributioni"].get<double>());
        }
        if(obj.contains("llcdbgbrakepidcontributiond"))
        {
            msg.llcdbgbrakepidcontributiond = (obj["llcdbgbrakepidcontributiond"].is_string()?atof(obj["llcdbgbrakepidcontributiond"].get<std::string>().c_str()):obj["llcdbgbrakepidcontributiond"].get<double>());
        }
        if(obj.contains("llcdbgbrakepidoutput"))
        {
            msg.llcdbgbrakepidoutput = (obj["llcdbgbrakepidoutput"].is_string()?atof(obj["llcdbgbrakepidoutput"].get<std::string>().c_str()):obj["llcdbgbrakepidoutput"].get<double>());
        }
        if(obj.contains("llcdbgbrakepiderror"))
        {
            msg.llcdbgbrakepiderror = (obj["llcdbgbrakepiderror"].is_string()?atoi(obj["llcdbgbrakepiderror"].get<std::string>().c_str()):obj["llcdbgbrakepiderror"].get<int>());
        }
        if(obj.contains("llcdbgbrakefeedforward"))
        {
            msg.llcdbgbrakefeedforward = (obj["llcdbgbrakefeedforward"].is_string()?atof(obj["llcdbgbrakefeedforward"].get<std::string>().c_str()):obj["llcdbgbrakefeedforward"].get<double>());
        }
        return msg;
    }
    template <>
    ApollocanbusLlcDiagBrakecontrol721 from_json<ApollocanbusLlcDiagBrakecontrol721>(nlohmann::json obj){
        return from_json_ApollocanbusLlcDiagBrakecontrol721(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocanbusLlcDiagBrakecontrol721 &dt)
    {
        dt=from_json_ApollocanbusLlcDiagBrakecontrol721(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocanbusLlcDiagBrakecontrol721 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocanbusLlcDiagBrakecontrol721 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
