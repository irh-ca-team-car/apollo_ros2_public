#include "adapter/serialization/apollo_msgs/apollolocalization_integ_measure.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollolocalizationIntegMeasure &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["measuretype"] = (msg.measuretype);
        obj["frametype"] = (msg.frametype);
        obj["position"] = to_json(msg.position);
        obj["velocity"] = to_json(msg.velocity);
        obj["yaw"] = (msg.yaw);
        obj["zoneid"] = (msg.zoneid);
        obj["ishavevariance"] = (msg.ishavevariance);
        obj["isgnssdoubleantenna"] = (msg.isgnssdoubleantenna);
        nlohmann::json arr_measurecovar;
        for (auto it = msg.measurecovar.begin(); it != msg.measurecovar.end(); ++it) {
            arr_measurecovar.push_back((*it));
        }
        obj["measurecovar"] = arr_measurecovar;
        return obj;
    }
    ApollolocalizationIntegMeasure from_json_ApollolocalizationIntegMeasure (nlohmann::json obj) {
        ApollolocalizationIntegMeasure msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("measuretype"))
        {
            msg.measuretype = (obj["measuretype"].is_string()?atoi(obj["measuretype"].get<std::string>().c_str()):obj["measuretype"].get<int>());
        }
        if(obj.contains("frametype"))
        {
            msg.frametype = (obj["frametype"].is_string()?atoi(obj["frametype"].get<std::string>().c_str()):obj["frametype"].get<int>());
        }
        if(obj.contains("position"))
        {
            msg.position = from_json_ApollocommonPoint3D(obj["position"]);
        }
        if(obj.contains("velocity"))
        {
            msg.velocity = from_json_ApollocommonPoint3D(obj["velocity"]);
        }
        if(obj.contains("yaw"))
        {
            msg.yaw = (obj["yaw"].is_string()?atof(obj["yaw"].get<std::string>().c_str()):obj["yaw"].get<double>());
        }
        if(obj.contains("zoneid"))
        {
            msg.zoneid = (obj["zoneid"].is_string()?atoi(obj["zoneid"].get<std::string>().c_str()):obj["zoneid"].get<int>());
        }
        if(obj.contains("ishavevariance"))
        {
            msg.ishavevariance = (obj["ishavevariance"].is_string()?(bool)atoi(obj["ishavevariance"].get<std::string>().c_str()):obj["ishavevariance"].get<bool>());
        }
        if(obj.contains("isgnssdoubleantenna"))
        {
            msg.isgnssdoubleantenna = (obj["isgnssdoubleantenna"].is_string()?(bool)atoi(obj["isgnssdoubleantenna"].get<std::string>().c_str()):obj["isgnssdoubleantenna"].get<bool>());
        }
        if(obj.contains("measurecovar"))
        {
            if(obj["measurecovar"].is_array())
            {
                for (auto& element : obj["measurecovar"])
                {
                    msg.measurecovar.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.measurecovar.push_back((obj["measurecovar"].is_string()?atof(obj["measurecovar"].get<std::string>().c_str()):obj["measurecovar"].get<double>()));
            }
        }
        return msg;
    }
    template <>
    ApollolocalizationIntegMeasure from_json<ApollolocalizationIntegMeasure>(nlohmann::json obj){
        return from_json_ApollolocalizationIntegMeasure(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollolocalizationIntegMeasure &dt)
    {
        dt=from_json_ApollolocalizationIntegMeasure(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollolocalizationIntegMeasure & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollolocalizationIntegMeasure & dt)
    {
        os << to_json(dt);
        return os;
    }
}
