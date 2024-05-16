#include "adapter/serialization/apollo_msgs/apollocommon_vehicle_model_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollocommonVehicleModelConfig &msg) {
        nlohmann::json obj;
        obj["modeltype"] = (msg.modeltype);
        obj["rckinematicbicyclemodel"] = to_json(msg.rckinematicbicyclemodel);
        obj["comcdynamicbicyclemodel"] = to_json(msg.comcdynamicbicyclemodel);
        obj["mlpmodel"] = to_json(msg.mlpmodel);
        return obj;
    }
    ApollocommonVehicleModelConfig from_json_ApollocommonVehicleModelConfig (nlohmann::json obj) {
        ApollocommonVehicleModelConfig msg;
        if(obj.contains("modeltype"))
        {
            msg.modeltype = (obj["modeltype"].is_string()?atoi(obj["modeltype"].get<std::string>().c_str()):obj["modeltype"].get<int>());
        }
        if(obj.contains("rckinematicbicyclemodel"))
        {
            msg.rckinematicbicyclemodel = from_json_ApollocommonRearCenteredKinematicBicycleModelConfig(obj["rckinematicbicyclemodel"]);
        }
        if(obj.contains("comcdynamicbicyclemodel"))
        {
            msg.comcdynamicbicyclemodel = from_json_ApollocommonComCenteredDynamicBicycleModelConfig(obj["comcdynamicbicyclemodel"]);
        }
        if(obj.contains("mlpmodel"))
        {
            msg.mlpmodel = from_json_ApollocommonMlpModelConfig(obj["mlpmodel"]);
        }
        return msg;
    }
    template <>
    ApollocommonVehicleModelConfig from_json<ApollocommonVehicleModelConfig>(nlohmann::json obj){
        return from_json_ApollocommonVehicleModelConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollocommonVehicleModelConfig &dt)
    {
        dt=from_json_ApollocommonVehicleModelConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollocommonVehicleModelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollocommonVehicleModelConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
