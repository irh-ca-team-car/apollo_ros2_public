#include "adapter/serialization/apollo_msgs/apollocontrolcalibrationtable_control_calibration_table.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocontrolcalibrationtableControlCalibrationTable &msg) {
        nlohmann::json obj;
        nlohmann::json arr_calibration;
        for (auto it = msg.calibration.begin(); it != msg.calibration.end(); ++it) {
            arr_calibration.push_back(to_json(*it));
        }
        obj["calibration"] = arr_calibration;
        return obj;
    }
    ApollocontrolcalibrationtableControlCalibrationTable from_json_ApollocontrolcalibrationtableControlCalibrationTable (nlohmann::json obj) {
        ApollocontrolcalibrationtableControlCalibrationTable msg;
        if(obj.contains("calibration"))
        {
            if(obj["calibration"].is_array())
            {
                for (auto& element : obj["calibration"])
                {
                    msg.calibration.push_back(from_json_ApollocontrolcalibrationtableControlCalibrationInfo(element));
                }
            }
            else
            {
                msg.calibration.push_back(from_json_ApollocontrolcalibrationtableControlCalibrationInfo(obj["calibration"]));
            }
        }
        return msg;
    }
    template <>
    ApollocontrolcalibrationtableControlCalibrationTable from_json<ApollocontrolcalibrationtableControlCalibrationTable>(nlohmann::json obj){
        return from_json_ApollocontrolcalibrationtableControlCalibrationTable(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocontrolcalibrationtableControlCalibrationTable &dt)
    {
        dt=from_json_ApollocontrolcalibrationtableControlCalibrationTable(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocontrolcalibrationtableControlCalibrationTable & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocontrolcalibrationtableControlCalibrationTable & dt)
    {
        os << to_json(dt);
        return os;
    }
}
