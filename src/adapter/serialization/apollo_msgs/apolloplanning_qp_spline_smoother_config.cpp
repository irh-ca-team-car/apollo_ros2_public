#include "adapter/serialization/apollo_msgs/apolloplanning_qp_spline_smoother_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningQpSplineSmootherConfig &msg) {
        nlohmann::json obj;
        obj["splineorder"] = (msg.splineorder);
        obj["maxsplinelength"] = (msg.maxsplinelength);
        obj["regularizationweight"] = (msg.regularizationweight);
        obj["secondderivativeweight"] = (msg.secondderivativeweight);
        obj["thirdderivativeweight"] = (msg.thirdderivativeweight);
        return obj;
    }
    ApolloplanningQpSplineSmootherConfig from_json_ApolloplanningQpSplineSmootherConfig (nlohmann::json obj) {
        ApolloplanningQpSplineSmootherConfig msg;
        if(obj.contains("splineorder"))
        {
            msg.splineorder = (obj["splineorder"].is_string()?atoi(obj["splineorder"].get<std::string>().c_str()):obj["splineorder"].get<uint32_t>());
        }
        if(obj.contains("maxsplinelength"))
        {
            msg.maxsplinelength = (obj["maxsplinelength"].is_string()?atof(obj["maxsplinelength"].get<std::string>().c_str()):obj["maxsplinelength"].get<double>());
        }
        if(obj.contains("regularizationweight"))
        {
            msg.regularizationweight = (obj["regularizationweight"].is_string()?atof(obj["regularizationweight"].get<std::string>().c_str()):obj["regularizationweight"].get<double>());
        }
        if(obj.contains("secondderivativeweight"))
        {
            msg.secondderivativeweight = (obj["secondderivativeweight"].is_string()?atof(obj["secondderivativeweight"].get<std::string>().c_str()):obj["secondderivativeweight"].get<double>());
        }
        if(obj.contains("thirdderivativeweight"))
        {
            msg.thirdderivativeweight = (obj["thirdderivativeweight"].is_string()?atof(obj["thirdderivativeweight"].get<std::string>().c_str()):obj["thirdderivativeweight"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningQpSplineSmootherConfig from_json<ApolloplanningQpSplineSmootherConfig>(nlohmann::json obj){
        return from_json_ApolloplanningQpSplineSmootherConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningQpSplineSmootherConfig &dt)
    {
        dt=from_json_ApolloplanningQpSplineSmootherConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningQpSplineSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningQpSplineSmootherConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
