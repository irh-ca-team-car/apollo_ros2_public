#include "adapter/serialization/apollo_msgs/apollodrivers_point_cloud.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversPointCloud &msg) {
        nlohmann::json obj;
        obj["apolloheader"] = to_json(msg.apolloheader);
        obj["frameid"] = (msg.frameid);
        obj["isdense"] = (msg.isdense);
        nlohmann::json arr_point;
        for (auto it = msg.point.begin(); it != msg.point.end(); ++it) {
            arr_point.push_back(to_json(*it));
        }
        obj["point"] = arr_point;
        obj["measurementtime"] = (msg.measurementtime);
        obj["width"] = (msg.width);
        obj["height"] = (msg.height);
        return obj;
    }
    ApollodriversPointCloud from_json_ApollodriversPointCloud (nlohmann::json obj) {
        ApollodriversPointCloud msg;
        if(obj.contains("apolloheader"))
        {
            msg.apolloheader = from_json_ApollocommonHeader(obj["apolloheader"]);
        }
        if(obj.contains("frameid"))
        {
            msg.frameid = (obj["frameid"].is_string()?(obj["frameid"].get<std::string>().c_str()):obj["frameid"].get<std::string>());
        }
        if(obj.contains("isdense"))
        {
            msg.isdense = (obj["isdense"].is_string()?(bool)atoi(obj["isdense"].get<std::string>().c_str()):obj["isdense"].get<bool>());
        }
        if(obj.contains("point"))
        {
            if(obj["point"].is_array())
            {
                for (auto& element : obj["point"])
                {
                    msg.point.push_back(from_json_ApollodriversPointXYZIT(element));
                }
            }
            else
            {
                msg.point.push_back(from_json_ApollodriversPointXYZIT(obj["point"]));
            }
        }
        if(obj.contains("measurementtime"))
        {
            msg.measurementtime = (obj["measurementtime"].is_string()?atof(obj["measurementtime"].get<std::string>().c_str()):obj["measurementtime"].get<double>());
        }
        if(obj.contains("width"))
        {
            msg.width = (obj["width"].is_string()?atoi(obj["width"].get<std::string>().c_str()):obj["width"].get<uint32_t>());
        }
        if(obj.contains("height"))
        {
            msg.height = (obj["height"].is_string()?atoi(obj["height"].get<std::string>().c_str()):obj["height"].get<uint32_t>());
        }
        return msg;
    }
    template <>
    ApollodriversPointCloud from_json<ApollodriversPointCloud>(nlohmann::json obj){
        return from_json_ApollodriversPointCloud(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversPointCloud &dt)
    {
        dt=from_json_ApollodriversPointCloud(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversPointCloud & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversPointCloud & dt)
    {
        os << to_json(dt);
        return os;
    }
}
