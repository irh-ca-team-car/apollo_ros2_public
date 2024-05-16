#include "adapter/serialization/apollo_msgs/apollodriversgnss_ins.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversgnssIns &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["measurementtime"] = (msg.measurementtime);
        obj["type"] = (msg.type);
        obj["position"] = to_json(msg.position);
        obj["eulerangles"] = to_json(msg.eulerangles);
        obj["linearvelocity"] = to_json(msg.linearvelocity);
        obj["angularvelocity"] = to_json(msg.angularvelocity);
        obj["linearacceleration"] = to_json(msg.linearacceleration);
        nlohmann::json arr_positioncovariance;
        for (auto it = msg.positioncovariance.begin(); it != msg.positioncovariance.end(); ++it) {
            arr_positioncovariance.push_back((*it));
        }
        obj["positioncovariance"] = arr_positioncovariance;
        nlohmann::json arr_euleranglescovariance;
        for (auto it = msg.euleranglescovariance.begin(); it != msg.euleranglescovariance.end(); ++it) {
            arr_euleranglescovariance.push_back((*it));
        }
        obj["euleranglescovariance"] = arr_euleranglescovariance;
        nlohmann::json arr_linearvelocitycovariance;
        for (auto it = msg.linearvelocitycovariance.begin(); it != msg.linearvelocitycovariance.end(); ++it) {
            arr_linearvelocitycovariance.push_back((*it));
        }
        obj["linearvelocitycovariance"] = arr_linearvelocitycovariance;
        nlohmann::json arr_angularvelocitycovariance;
        for (auto it = msg.angularvelocitycovariance.begin(); it != msg.angularvelocitycovariance.end(); ++it) {
            arr_angularvelocitycovariance.push_back((*it));
        }
        obj["angularvelocitycovariance"] = arr_angularvelocitycovariance;
        nlohmann::json arr_linearaccelerationcovariance;
        for (auto it = msg.linearaccelerationcovariance.begin(); it != msg.linearaccelerationcovariance.end(); ++it) {
            arr_linearaccelerationcovariance.push_back((*it));
        }
        obj["linearaccelerationcovariance"] = arr_linearaccelerationcovariance;
        return obj;
    }
    ApollodriversgnssIns from_json_ApollodriversgnssIns (nlohmann::json obj) {
        ApollodriversgnssIns msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("measurementtime"))
        {
            msg.measurementtime = (obj["measurementtime"].is_string()?atof(obj["measurementtime"].get<std::string>().c_str()):obj["measurementtime"].get<double>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPointLLH(obj["position"]);
        }
        if(obj.contains("eulerangles"))
        {
            msg.eulerangles = from_json_ApollocommonPoint3D(obj["eulerangles"]);
        }
        if(obj.contains("linearvelocity"))
        {
            msg.linearvelocity = from_json_ApollocommonPoint3D(obj["linearvelocity"]);
        }
        if(obj.contains("angularvelocity"))
        {
            msg.angularvelocity = from_json_ApollocommonPoint3D(obj["angularvelocity"]);
        }
        if(obj.contains("linearacceleration"))
        {
            msg.linearacceleration = from_json_ApollocommonPoint3D(obj["linearacceleration"]);
        }
        if(obj.contains("positioncovariance"))
        {
            if(obj["positioncovariance"].is_array())
            {
                for (auto& element : obj["positioncovariance"])
                {
                    msg.positioncovariance.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.positioncovariance.push_back((obj["positioncovariance"].is_string()?(float)atof(obj["positioncovariance"].get<std::string>().c_str()):obj["positioncovariance"].get<float>()));
            }
        }
        if(obj.contains("euleranglescovariance"))
        {
            if(obj["euleranglescovariance"].is_array())
            {
                for (auto& element : obj["euleranglescovariance"])
                {
                    msg.euleranglescovariance.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.euleranglescovariance.push_back((obj["euleranglescovariance"].is_string()?(float)atof(obj["euleranglescovariance"].get<std::string>().c_str()):obj["euleranglescovariance"].get<float>()));
            }
        }
        if(obj.contains("linearvelocitycovariance"))
        {
            if(obj["linearvelocitycovariance"].is_array())
            {
                for (auto& element : obj["linearvelocitycovariance"])
                {
                    msg.linearvelocitycovariance.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.linearvelocitycovariance.push_back((obj["linearvelocitycovariance"].is_string()?(float)atof(obj["linearvelocitycovariance"].get<std::string>().c_str()):obj["linearvelocitycovariance"].get<float>()));
            }
        }
        if(obj.contains("angularvelocitycovariance"))
        {
            if(obj["angularvelocitycovariance"].is_array())
            {
                for (auto& element : obj["angularvelocitycovariance"])
                {
                    msg.angularvelocitycovariance.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.angularvelocitycovariance.push_back((obj["angularvelocitycovariance"].is_string()?(float)atof(obj["angularvelocitycovariance"].get<std::string>().c_str()):obj["angularvelocitycovariance"].get<float>()));
            }
        }
        if(obj.contains("linearaccelerationcovariance"))
        {
            if(obj["linearaccelerationcovariance"].is_array())
            {
                for (auto& element : obj["linearaccelerationcovariance"])
                {
                    msg.linearaccelerationcovariance.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.linearaccelerationcovariance.push_back((obj["linearaccelerationcovariance"].is_string()?(float)atof(obj["linearaccelerationcovariance"].get<std::string>().c_str()):obj["linearaccelerationcovariance"].get<float>()));
            }
        }
        return msg;
    }
    template <>
    ApollodriversgnssIns from_json<ApollodriversgnssIns>(nlohmann::json obj){
        return from_json_ApollodriversgnssIns(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversgnssIns &dt)
    {
        dt=from_json_ApollodriversgnssIns(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversgnssIns & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversgnssIns & dt)
    {
        os << to_json(dt);
        return os;
    }
}
