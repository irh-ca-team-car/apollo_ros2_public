#include "adapter/serialization/apollo_msgs/apolloplanning_internal_lattice_st_training.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningInternalLatticeStTraining &msg) {
        nlohmann::json obj;
        nlohmann::json arr_pixel;
        for (auto it = msg.pixel.begin(); it != msg.pixel.end(); ++it) {
            arr_pixel.push_back(to_json(*it));
        }
        obj["pixel"] = arr_pixel;
        obj["timestamp"] = (msg.timestamp);
        obj["annotation"] = (msg.annotation);
        obj["numsgrids"] = (msg.numsgrids);
        obj["numtgrids"] = (msg.numtgrids);
        obj["sresolution"] = (msg.sresolution);
        obj["tresolution"] = (msg.tresolution);
        return obj;
    }
    ApolloplanningInternalLatticeStTraining from_json_ApolloplanningInternalLatticeStTraining (nlohmann::json obj) {
        ApolloplanningInternalLatticeStTraining msg;
        if(obj.contains("pixel"))
        {
            if(obj["pixel"].is_array())
            {
                for (auto& element : obj["pixel"])
                {
                    msg.pixel.push_back(from_json_ApolloplanningInternalLatticeStPixel(element));
                }
            }
            else
            {
                msg.pixel.push_back(from_json_ApolloplanningInternalLatticeStPixel(obj["pixel"]));
            }
        }
        if(obj.contains("timestamp"))
        {
            msg.timestamp = (obj["timestamp"].is_string()?atof(obj["timestamp"].get<std::string>().c_str()):obj["timestamp"].get<double>());
        }
        if(obj.contains("annotation"))
        {
            msg.annotation = (obj["annotation"].is_string()?(obj["annotation"].get<std::string>().c_str()):obj["annotation"].get<std::string>());
        }
        if(obj.contains("numsgrids"))
        {
            msg.numsgrids = (obj["numsgrids"].is_string()?atoi(obj["numsgrids"].get<std::string>().c_str()):obj["numsgrids"].get<uint32_t>());
        }
        if(obj.contains("numtgrids"))
        {
            msg.numtgrids = (obj["numtgrids"].is_string()?atoi(obj["numtgrids"].get<std::string>().c_str()):obj["numtgrids"].get<uint32_t>());
        }
        if(obj.contains("sresolution"))
        {
            msg.sresolution = (obj["sresolution"].is_string()?atof(obj["sresolution"].get<std::string>().c_str()):obj["sresolution"].get<double>());
        }
        if(obj.contains("tresolution"))
        {
            msg.tresolution = (obj["tresolution"].is_string()?atof(obj["tresolution"].get<std::string>().c_str()):obj["tresolution"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningInternalLatticeStTraining from_json<ApolloplanningInternalLatticeStTraining>(nlohmann::json obj){
        return from_json_ApolloplanningInternalLatticeStTraining(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningInternalLatticeStTraining &dt)
    {
        dt=from_json_ApolloplanningInternalLatticeStTraining(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningInternalLatticeStTraining & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningInternalLatticeStTraining & dt)
    {
        os << to_json(dt);
        return os;
    }
}
