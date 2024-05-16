#include "adapter/serialization/apollo_msgs/apollodrivers_vehicle45f3.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversVehicle45f3 &msg) {
        nlohmann::json obj;
        obj["canrxfactgtranger2m"] = (msg.canrxfactgtranger2m);
        obj["canrxfactgtrangem2t"] = (msg.canrxfactgtrangem2t);
        obj["canrxfactgtrange1"] = (msg.canrxfactgtrange1);
        obj["canrxfactgtmtgspacever"] = (msg.canrxfactgtmtgspacever);
        obj["canrxfactgtmtgspacehor"] = (msg.canrxfactgtmtgspacehor);
        obj["canrxfactgtmtgoffset"] = (msg.canrxfactgtmtgoffset);
        obj["canrxfacalignsampreq"] = (msg.canrxfacalignsampreq);
        obj["canrxfacalignmaxnt"] = (msg.canrxfacalignmaxnt);
        obj["canrxfacaligncmd2"] = (msg.canrxfacaligncmd2);
        obj["canrxfacaligncmd1"] = (msg.canrxfacaligncmd1);
        return obj;
    }
    ApollodriversVehicle45f3 from_json_ApollodriversVehicle45f3 (nlohmann::json obj) {
        ApollodriversVehicle45f3 msg;
        if(obj.contains("canrxfactgtranger2m"))
        {
            msg.canrxfactgtranger2m = (obj["canrxfactgtranger2m"].is_string()?atof(obj["canrxfactgtranger2m"].get<std::string>().c_str()):obj["canrxfactgtranger2m"].get<double>());
        }
        if(obj.contains("canrxfactgtrangem2t"))
        {
            msg.canrxfactgtrangem2t = (obj["canrxfactgtrangem2t"].is_string()?atof(obj["canrxfactgtrangem2t"].get<std::string>().c_str()):obj["canrxfactgtrangem2t"].get<double>());
        }
        if(obj.contains("canrxfactgtrange1"))
        {
            msg.canrxfactgtrange1 = (obj["canrxfactgtrange1"].is_string()?atof(obj["canrxfactgtrange1"].get<std::string>().c_str()):obj["canrxfactgtrange1"].get<double>());
        }
        if(obj.contains("canrxfactgtmtgspacever"))
        {
            msg.canrxfactgtmtgspacever = (obj["canrxfactgtmtgspacever"].is_string()?atoi(obj["canrxfactgtmtgspacever"].get<std::string>().c_str()):obj["canrxfactgtmtgspacever"].get<int>());
        }
        if(obj.contains("canrxfactgtmtgspacehor"))
        {
            msg.canrxfactgtmtgspacehor = (obj["canrxfactgtmtgspacehor"].is_string()?atoi(obj["canrxfactgtmtgspacehor"].get<std::string>().c_str()):obj["canrxfactgtmtgspacehor"].get<int>());
        }
        if(obj.contains("canrxfactgtmtgoffset"))
        {
            msg.canrxfactgtmtgoffset = (obj["canrxfactgtmtgoffset"].is_string()?atoi(obj["canrxfactgtmtgoffset"].get<std::string>().c_str()):obj["canrxfactgtmtgoffset"].get<int>());
        }
        if(obj.contains("canrxfacalignsampreq"))
        {
            msg.canrxfacalignsampreq = (obj["canrxfacalignsampreq"].is_string()?atoi(obj["canrxfacalignsampreq"].get<std::string>().c_str()):obj["canrxfacalignsampreq"].get<int>());
        }
        if(obj.contains("canrxfacalignmaxnt"))
        {
            msg.canrxfacalignmaxnt = (obj["canrxfacalignmaxnt"].is_string()?atoi(obj["canrxfacalignmaxnt"].get<std::string>().c_str()):obj["canrxfacalignmaxnt"].get<int>());
        }
        if(obj.contains("canrxfacaligncmd2"))
        {
            msg.canrxfacaligncmd2 = (obj["canrxfacaligncmd2"].is_string()?atoi(obj["canrxfacaligncmd2"].get<std::string>().c_str()):obj["canrxfacaligncmd2"].get<int>());
        }
        if(obj.contains("canrxfacaligncmd1"))
        {
            msg.canrxfacaligncmd1 = (obj["canrxfacaligncmd1"].is_string()?atoi(obj["canrxfacaligncmd1"].get<std::string>().c_str()):obj["canrxfacaligncmd1"].get<int>());
        }
        return msg;
    }
    template <>
    ApollodriversVehicle45f3 from_json<ApollodriversVehicle45f3>(nlohmann::json obj){
        return from_json_ApollodriversVehicle45f3(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversVehicle45f3 &dt)
    {
        dt=from_json_ApollodriversVehicle45f3(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversVehicle45f3 & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversVehicle45f3 & dt)
    {
        os << to_json(dt);
        return os;
    }
}
