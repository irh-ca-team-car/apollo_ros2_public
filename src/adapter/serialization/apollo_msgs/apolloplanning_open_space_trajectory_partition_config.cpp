#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_trajectory_partition_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceTrajectoryPartitionConfig &msg) {
        nlohmann::json obj;
        obj["gearshiftmaxt"] = (msg.gearshiftmaxt);
        obj["gearshiftunitt"] = (msg.gearshiftunitt);
        obj["gearshiftperiodduration"] = (msg.gearshiftperiodduration);
        obj["interpolatedpiecesnum"] = (msg.interpolatedpiecesnum);
        obj["initialgearcheckhorizon"] = (msg.initialgearcheckhorizon);
        obj["headingsearchrange"] = (msg.headingsearchrange);
        obj["headingtrackrange"] = (msg.headingtrackrange);
        obj["distancesearchrange"] = (msg.distancesearchrange);
        obj["headingoffsettomidpoint"] = (msg.headingoffsettomidpoint);
        obj["lateraloffsettomidpoint"] = (msg.lateraloffsettomidpoint);
        obj["longitudinaloffsettomidpoint"] = (msg.longitudinaloffsettomidpoint);
        obj["vehicleboxiouthresholdtomidpoint"] = (msg.vehicleboxiouthresholdtomidpoint);
        obj["linearvelocitythresholdonego"] = (msg.linearvelocitythresholdonego);
        return obj;
    }
    ApolloplanningOpenSpaceTrajectoryPartitionConfig from_json_ApolloplanningOpenSpaceTrajectoryPartitionConfig (nlohmann::json obj) {
        ApolloplanningOpenSpaceTrajectoryPartitionConfig msg;
        if(obj.contains("gearshiftmaxt"))
        {
            msg.gearshiftmaxt = (obj["gearshiftmaxt"].is_string()?atof(obj["gearshiftmaxt"].get<std::string>().c_str()):obj["gearshiftmaxt"].get<double>());
        }
        if(obj.contains("gearshiftunitt"))
        {
            msg.gearshiftunitt = (obj["gearshiftunitt"].is_string()?atof(obj["gearshiftunitt"].get<std::string>().c_str()):obj["gearshiftunitt"].get<double>());
        }
        if(obj.contains("gearshiftperiodduration"))
        {
            msg.gearshiftperiodduration = (obj["gearshiftperiodduration"].is_string()?atof(obj["gearshiftperiodduration"].get<std::string>().c_str()):obj["gearshiftperiodduration"].get<double>());
        }
        if(obj.contains("interpolatedpiecesnum"))
        {
            msg.interpolatedpiecesnum = (obj["interpolatedpiecesnum"].is_string()?atol(obj["interpolatedpiecesnum"].get<std::string>().c_str()):obj["interpolatedpiecesnum"].get<uint64_t>());
        }
        if(obj.contains("initialgearcheckhorizon"))
        {
            msg.initialgearcheckhorizon = (obj["initialgearcheckhorizon"].is_string()?atol(obj["initialgearcheckhorizon"].get<std::string>().c_str()):obj["initialgearcheckhorizon"].get<uint64_t>());
        }
        if(obj.contains("headingsearchrange"))
        {
            msg.headingsearchrange = (obj["headingsearchrange"].is_string()?atof(obj["headingsearchrange"].get<std::string>().c_str()):obj["headingsearchrange"].get<double>());
        }
        if(obj.contains("headingtrackrange"))
        {
            msg.headingtrackrange = (obj["headingtrackrange"].is_string()?atof(obj["headingtrackrange"].get<std::string>().c_str()):obj["headingtrackrange"].get<double>());
        }
        if(obj.contains("distancesearchrange"))
        {
            msg.distancesearchrange = (obj["distancesearchrange"].is_string()?atof(obj["distancesearchrange"].get<std::string>().c_str()):obj["distancesearchrange"].get<double>());
        }
        if(obj.contains("headingoffsettomidpoint"))
        {
            msg.headingoffsettomidpoint = (obj["headingoffsettomidpoint"].is_string()?atof(obj["headingoffsettomidpoint"].get<std::string>().c_str()):obj["headingoffsettomidpoint"].get<double>());
        }
        if(obj.contains("lateraloffsettomidpoint"))
        {
            msg.lateraloffsettomidpoint = (obj["lateraloffsettomidpoint"].is_string()?atof(obj["lateraloffsettomidpoint"].get<std::string>().c_str()):obj["lateraloffsettomidpoint"].get<double>());
        }
        if(obj.contains("longitudinaloffsettomidpoint"))
        {
            msg.longitudinaloffsettomidpoint = (obj["longitudinaloffsettomidpoint"].is_string()?atof(obj["longitudinaloffsettomidpoint"].get<std::string>().c_str()):obj["longitudinaloffsettomidpoint"].get<double>());
        }
        if(obj.contains("vehicleboxiouthresholdtomidpoint"))
        {
            msg.vehicleboxiouthresholdtomidpoint = (obj["vehicleboxiouthresholdtomidpoint"].is_string()?atof(obj["vehicleboxiouthresholdtomidpoint"].get<std::string>().c_str()):obj["vehicleboxiouthresholdtomidpoint"].get<double>());
        }
        if(obj.contains("linearvelocitythresholdonego"))
        {
            msg.linearvelocitythresholdonego = (obj["linearvelocitythresholdonego"].is_string()?atof(obj["linearvelocitythresholdonego"].get<std::string>().c_str()):obj["linearvelocitythresholdonego"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningOpenSpaceTrajectoryPartitionConfig from_json<ApolloplanningOpenSpaceTrajectoryPartitionConfig>(nlohmann::json obj){
        return from_json_ApolloplanningOpenSpaceTrajectoryPartitionConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceTrajectoryPartitionConfig &dt)
    {
        dt=from_json_ApolloplanningOpenSpaceTrajectoryPartitionConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceTrajectoryPartitionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceTrajectoryPartitionConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
