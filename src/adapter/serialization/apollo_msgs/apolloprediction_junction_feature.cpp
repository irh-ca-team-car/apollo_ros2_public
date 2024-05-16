#include "adapter/serialization/apollo_msgs/apolloprediction_junction_feature.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollopredictionJunctionFeature &msg) {
        nlohmann::json obj;
        obj["junctionid"] = (msg.junctionid);
        obj["junctionrange"] = (msg.junctionrange);
        obj["enterlane"] = to_json(msg.enterlane);
        nlohmann::json arr_junctionexit;
        for (auto it = msg.junctionexit.begin(); it != msg.junctionexit.end(); ++it) {
            arr_junctionexit.push_back(to_json(*it));
        }
        obj["junctionexit"] = arr_junctionexit;
        nlohmann::json arr_junctionmlpfeature;
        for (auto it = msg.junctionmlpfeature.begin(); it != msg.junctionmlpfeature.end(); ++it) {
            arr_junctionmlpfeature.push_back((*it));
        }
        obj["junctionmlpfeature"] = arr_junctionmlpfeature;
        nlohmann::json arr_junctionmlplabel;
        for (auto it = msg.junctionmlplabel.begin(); it != msg.junctionmlplabel.end(); ++it) {
            arr_junctionmlplabel.push_back((*it));
        }
        obj["junctionmlplabel"] = arr_junctionmlplabel;
        nlohmann::json arr_junctionmlpprobability;
        for (auto it = msg.junctionmlpprobability.begin(); it != msg.junctionmlpprobability.end(); ++it) {
            arr_junctionmlpprobability.push_back((*it));
        }
        obj["junctionmlpprobability"] = arr_junctionmlpprobability;
        nlohmann::json arr_startlaneid;
        for (auto it = msg.startlaneid.begin(); it != msg.startlaneid.end(); ++it) {
            arr_startlaneid.push_back((*it));
        }
        obj["startlaneid"] = arr_startlaneid;
        return obj;
    }
    ApollopredictionJunctionFeature from_json_ApollopredictionJunctionFeature (nlohmann::json obj) {
        ApollopredictionJunctionFeature msg;
        if(obj.contains("junctionid"))
        {
            msg.junctionid = (obj["junctionid"].is_string()?(obj["junctionid"].get<std::string>().c_str()):obj["junctionid"].get<std::string>());
        }
        if(obj.contains("junctionrange"))
        {
            msg.junctionrange = (obj["junctionrange"].is_string()?atof(obj["junctionrange"].get<std::string>().c_str()):obj["junctionrange"].get<double>());
        }
        if(obj.contains("enterlane"))
        {
            msg.enterlane = from_json_ApollopredictionLaneFeature(obj["enterlane"]);
        }
        if(obj.contains("junctionexit"))
        {
            if(obj["junctionexit"].is_array())
            {
                for (auto& element : obj["junctionexit"])
                {
                    msg.junctionexit.push_back(from_json_ApollopredictionJunctionExit(element));
                }
            }
            else
            {
                msg.junctionexit.push_back(from_json_ApollopredictionJunctionExit(obj["junctionexit"]));
            }
        }
        if(obj.contains("junctionmlpfeature"))
        {
            if(obj["junctionmlpfeature"].is_array())
            {
                for (auto& element : obj["junctionmlpfeature"])
                {
                    msg.junctionmlpfeature.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.junctionmlpfeature.push_back((obj["junctionmlpfeature"].is_string()?atof(obj["junctionmlpfeature"].get<std::string>().c_str()):obj["junctionmlpfeature"].get<double>()));
            }
        }
        if(obj.contains("junctionmlplabel"))
        {
            if(obj["junctionmlplabel"].is_array())
            {
                for (auto& element : obj["junctionmlplabel"])
                {
                    msg.junctionmlplabel.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.junctionmlplabel.push_back((obj["junctionmlplabel"].is_string()?atoi(obj["junctionmlplabel"].get<std::string>().c_str()):obj["junctionmlplabel"].get<int>()));
            }
        }
        if(obj.contains("junctionmlpprobability"))
        {
            if(obj["junctionmlpprobability"].is_array())
            {
                for (auto& element : obj["junctionmlpprobability"])
                {
                    msg.junctionmlpprobability.push_back((element.is_string()?atof(element.get<std::string>().c_str()):element.get<double>()));
                }
            }
            else
            {
                msg.junctionmlpprobability.push_back((obj["junctionmlpprobability"].is_string()?atof(obj["junctionmlpprobability"].get<std::string>().c_str()):obj["junctionmlpprobability"].get<double>()));
            }
        }
        if(obj.contains("startlaneid"))
        {
            if(obj["startlaneid"].is_array())
            {
                for (auto& element : obj["startlaneid"])
                {
                    msg.startlaneid.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.startlaneid.push_back((obj["startlaneid"].is_string()?(obj["startlaneid"].get<std::string>().c_str()):obj["startlaneid"].get<std::string>()));
            }
        }
        return msg;
    }
    template <>
    ApollopredictionJunctionFeature from_json<ApollopredictionJunctionFeature>(nlohmann::json obj){
        return from_json_ApollopredictionJunctionFeature(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollopredictionJunctionFeature &dt)
    {
        dt=from_json_ApollopredictionJunctionFeature(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollopredictionJunctionFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollopredictionJunctionFeature & dt)
    {
        os << to_json(dt);
        return os;
    }
}
