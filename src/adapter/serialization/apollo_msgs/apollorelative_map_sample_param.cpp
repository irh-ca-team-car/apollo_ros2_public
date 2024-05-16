#include "adapter/serialization/apollo_msgs/apollorelative_map_sample_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollorelativeMapSampleParam &msg) {
        nlohmann::json obj;
        obj["straightsampleinterval"] = (msg.straightsampleinterval);
        obj["smallkappasampleinterval"] = (msg.smallkappasampleinterval);
        obj["middlekappasampleinterval"] = (msg.middlekappasampleinterval);
        obj["largekappasampleinterval"] = (msg.largekappasampleinterval);
        obj["smallkappa"] = (msg.smallkappa);
        obj["middlekappa"] = (msg.middlekappa);
        obj["largekappa"] = (msg.largekappa);
        return obj;
    }
    ApollorelativeMapSampleParam from_json_ApollorelativeMapSampleParam (nlohmann::json obj) {
        ApollorelativeMapSampleParam msg;
        if(obj.contains("straightsampleinterval"))
        {
            msg.straightsampleinterval = (obj["straightsampleinterval"].is_string()?atof(obj["straightsampleinterval"].get<std::string>().c_str()):obj["straightsampleinterval"].get<double>());
        }
        if(obj.contains("smallkappasampleinterval"))
        {
            msg.smallkappasampleinterval = (obj["smallkappasampleinterval"].is_string()?atof(obj["smallkappasampleinterval"].get<std::string>().c_str()):obj["smallkappasampleinterval"].get<double>());
        }
        if(obj.contains("middlekappasampleinterval"))
        {
            msg.middlekappasampleinterval = (obj["middlekappasampleinterval"].is_string()?atof(obj["middlekappasampleinterval"].get<std::string>().c_str()):obj["middlekappasampleinterval"].get<double>());
        }
        if(obj.contains("largekappasampleinterval"))
        {
            msg.largekappasampleinterval = (obj["largekappasampleinterval"].is_string()?atof(obj["largekappasampleinterval"].get<std::string>().c_str()):obj["largekappasampleinterval"].get<double>());
        }
        if(obj.contains("smallkappa"))
        {
            msg.smallkappa = (obj["smallkappa"].is_string()?atof(obj["smallkappa"].get<std::string>().c_str()):obj["smallkappa"].get<double>());
        }
        if(obj.contains("middlekappa"))
        {
            msg.middlekappa = (obj["middlekappa"].is_string()?atof(obj["middlekappa"].get<std::string>().c_str()):obj["middlekappa"].get<double>());
        }
        if(obj.contains("largekappa"))
        {
            msg.largekappa = (obj["largekappa"].is_string()?atof(obj["largekappa"].get<std::string>().c_str()):obj["largekappa"].get<double>());
        }
        return msg;
    }
    template <>
    ApollorelativeMapSampleParam from_json<ApollorelativeMapSampleParam>(nlohmann::json obj){
        return from_json_ApollorelativeMapSampleParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollorelativeMapSampleParam &dt)
    {
        dt=from_json_ApollorelativeMapSampleParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollorelativeMapSampleParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollorelativeMapSampleParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
