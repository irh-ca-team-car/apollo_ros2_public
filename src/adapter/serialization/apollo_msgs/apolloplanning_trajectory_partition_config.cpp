#include "adapter/serialization/apollo_msgs/apolloplanning_trajectory_partition_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningTrajectoryPartitionConfig &msg) {
        nlohmann::json obj;
        obj["interpolatedpiecesnum"] = (msg.interpolatedpiecesnum);
        obj["initialgearcheckhorizon"] = (msg.initialgearcheckhorizon);
        obj["headingsearchingrange"] = (msg.headingsearchingrange);
        obj["gearshiftperiodduration"] = (msg.gearshiftperiodduration);
        obj["gearshiftmaxt"] = (msg.gearshiftmaxt);
        obj["gearshiftunitt"] = (msg.gearshiftunitt);
        return obj;
    }
    ApolloplanningTrajectoryPartitionConfig from_json_ApolloplanningTrajectoryPartitionConfig (nlohmann::json obj) {
        ApolloplanningTrajectoryPartitionConfig msg;
        if(obj.contains("interpolatedpiecesnum"))
        {
            msg.interpolatedpiecesnum = (obj["interpolatedpiecesnum"].is_string()?atol(obj["interpolatedpiecesnum"].get<std::string>().c_str()):obj["interpolatedpiecesnum"].get<uint64_t>());
        }
        if(obj.contains("initialgearcheckhorizon"))
        {
            msg.initialgearcheckhorizon = (obj["initialgearcheckhorizon"].is_string()?atol(obj["initialgearcheckhorizon"].get<std::string>().c_str()):obj["initialgearcheckhorizon"].get<uint64_t>());
        }
        if(obj.contains("headingsearchingrange"))
        {
            msg.headingsearchingrange = (obj["headingsearchingrange"].is_string()?atof(obj["headingsearchingrange"].get<std::string>().c_str()):obj["headingsearchingrange"].get<double>());
        }
        if(obj.contains("gearshiftperiodduration"))
        {
            msg.gearshiftperiodduration = (obj["gearshiftperiodduration"].is_string()?atof(obj["gearshiftperiodduration"].get<std::string>().c_str()):obj["gearshiftperiodduration"].get<double>());
        }
        if(obj.contains("gearshiftmaxt"))
        {
            msg.gearshiftmaxt = (obj["gearshiftmaxt"].is_string()?atof(obj["gearshiftmaxt"].get<std::string>().c_str()):obj["gearshiftmaxt"].get<double>());
        }
        if(obj.contains("gearshiftunitt"))
        {
            msg.gearshiftunitt = (obj["gearshiftunitt"].is_string()?atof(obj["gearshiftunitt"].get<std::string>().c_str()):obj["gearshiftunitt"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningTrajectoryPartitionConfig from_json<ApolloplanningTrajectoryPartitionConfig>(nlohmann::json obj){
        return from_json_ApolloplanningTrajectoryPartitionConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningTrajectoryPartitionConfig &dt)
    {
        dt=from_json_ApolloplanningTrajectoryPartitionConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningTrajectoryPartitionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningTrajectoryPartitionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
