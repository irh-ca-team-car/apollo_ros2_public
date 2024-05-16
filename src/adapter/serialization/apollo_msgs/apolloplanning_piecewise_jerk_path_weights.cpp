#include "adapter/serialization/apollo_msgs/apolloplanning_piecewise_jerk_path_weights.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningPiecewiseJerkPathWeights &msg) {
        nlohmann::json obj;
        obj["lweight"] = (msg.lweight);
        obj["dlweight"] = (msg.dlweight);
        obj["ddlweight"] = (msg.ddlweight);
        obj["dddlweight"] = (msg.dddlweight);
        return obj;
    }
    ApolloplanningPiecewiseJerkPathWeights from_json_ApolloplanningPiecewiseJerkPathWeights (nlohmann::json obj) {
        ApolloplanningPiecewiseJerkPathWeights msg;
        if(obj.contains("lweight"))
        {
            msg.lweight = (obj["lweight"].is_string()?atof(obj["lweight"].get<std::string>().c_str()):obj["lweight"].get<double>());
        }
        if(obj.contains("dlweight"))
        {
            msg.dlweight = (obj["dlweight"].is_string()?atof(obj["dlweight"].get<std::string>().c_str()):obj["dlweight"].get<double>());
        }
        if(obj.contains("ddlweight"))
        {
            msg.ddlweight = (obj["ddlweight"].is_string()?atof(obj["ddlweight"].get<std::string>().c_str()):obj["ddlweight"].get<double>());
        }
        if(obj.contains("dddlweight"))
        {
            msg.dddlweight = (obj["dddlweight"].is_string()?atof(obj["dddlweight"].get<std::string>().c_str()):obj["dddlweight"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningPiecewiseJerkPathWeights from_json<ApolloplanningPiecewiseJerkPathWeights>(nlohmann::json obj){
        return from_json_ApolloplanningPiecewiseJerkPathWeights(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningPiecewiseJerkPathWeights &dt)
    {
        dt=from_json_ApolloplanningPiecewiseJerkPathWeights(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningPiecewiseJerkPathWeights & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningPiecewiseJerkPathWeights & dt)
    {
        os << to_json(dt);
        return os;
    }
}
