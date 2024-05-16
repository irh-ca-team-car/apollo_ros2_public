#include "adapter/serialization/apollo_msgs/apolloplanning_open_space_roi_decider_config.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloplanningOpenSpaceRoiDeciderConfig &msg) {
        nlohmann::json obj;
        obj["roitype"] = (msg.roitype);
        obj["roilongitudinalrangestart"] = (msg.roilongitudinalrangestart);
        obj["roilongitudinalrangeend"] = (msg.roilongitudinalrangeend);
        obj["parkingstartrange"] = (msg.parkingstartrange);
        obj["parkinginwards"] = (msg.parkinginwards);
        obj["enableperceptionobstacles"] = (msg.enableperceptionobstacles);
        obj["parkingdepthbuffer"] = (msg.parkingdepthbuffer);
        obj["roilinesegmentminangle"] = (msg.roilinesegmentminangle);
        obj["roilinesegmentlength"] = (msg.roilinesegmentlength);
        obj["roilinesegmentlengthfrommap"] = (msg.roilinesegmentlengthfrommap);
        obj["perceptionobstaclefilteringdistance"] = (msg.perceptionobstaclefilteringdistance);
        obj["perceptionobstaclebuffer"] = (msg.perceptionobstaclebuffer);
        obj["curbheadingtangentchangeupperlimit"] = (msg.curbheadingtangentchangeupperlimit);
        obj["endposesdistance"] = (msg.endposesdistance);
        return obj;
    }
    ApolloplanningOpenSpaceRoiDeciderConfig from_json_ApolloplanningOpenSpaceRoiDeciderConfig (nlohmann::json obj) {
        ApolloplanningOpenSpaceRoiDeciderConfig msg;
        if(obj.contains("roitype"))
        {
            msg.roitype = (obj["roitype"].is_string()?atoi(obj["roitype"].get<std::string>().c_str()):obj["roitype"].get<int>());
        }
        if(obj.contains("roilongitudinalrangestart"))
        {
            msg.roilongitudinalrangestart = (obj["roilongitudinalrangestart"].is_string()?atof(obj["roilongitudinalrangestart"].get<std::string>().c_str()):obj["roilongitudinalrangestart"].get<double>());
        }
        if(obj.contains("roilongitudinalrangeend"))
        {
            msg.roilongitudinalrangeend = (obj["roilongitudinalrangeend"].is_string()?atof(obj["roilongitudinalrangeend"].get<std::string>().c_str()):obj["roilongitudinalrangeend"].get<double>());
        }
        if(obj.contains("parkingstartrange"))
        {
            msg.parkingstartrange = (obj["parkingstartrange"].is_string()?atof(obj["parkingstartrange"].get<std::string>().c_str()):obj["parkingstartrange"].get<double>());
        }
        if(obj.contains("parkinginwards"))
        {
            msg.parkinginwards = (obj["parkinginwards"].is_string()?(bool)atoi(obj["parkinginwards"].get<std::string>().c_str()):obj["parkinginwards"].get<bool>());
        }
        if(obj.contains("enableperceptionobstacles"))
        {
            msg.enableperceptionobstacles = (obj["enableperceptionobstacles"].is_string()?(bool)atoi(obj["enableperceptionobstacles"].get<std::string>().c_str()):obj["enableperceptionobstacles"].get<bool>());
        }
        if(obj.contains("parkingdepthbuffer"))
        {
            msg.parkingdepthbuffer = (obj["parkingdepthbuffer"].is_string()?atof(obj["parkingdepthbuffer"].get<std::string>().c_str()):obj["parkingdepthbuffer"].get<double>());
        }
        if(obj.contains("roilinesegmentminangle"))
        {
            msg.roilinesegmentminangle = (obj["roilinesegmentminangle"].is_string()?atof(obj["roilinesegmentminangle"].get<std::string>().c_str()):obj["roilinesegmentminangle"].get<double>());
        }
        if(obj.contains("roilinesegmentlength"))
        {
            msg.roilinesegmentlength = (obj["roilinesegmentlength"].is_string()?atof(obj["roilinesegmentlength"].get<std::string>().c_str()):obj["roilinesegmentlength"].get<double>());
        }
        if(obj.contains("roilinesegmentlengthfrommap"))
        {
            msg.roilinesegmentlengthfrommap = (obj["roilinesegmentlengthfrommap"].is_string()?atof(obj["roilinesegmentlengthfrommap"].get<std::string>().c_str()):obj["roilinesegmentlengthfrommap"].get<double>());
        }
        if(obj.contains("perceptionobstaclefilteringdistance"))
        {
            msg.perceptionobstaclefilteringdistance = (obj["perceptionobstaclefilteringdistance"].is_string()?atof(obj["perceptionobstaclefilteringdistance"].get<std::string>().c_str()):obj["perceptionobstaclefilteringdistance"].get<double>());
        }
        if(obj.contains("perceptionobstaclebuffer"))
        {
            msg.perceptionobstaclebuffer = (obj["perceptionobstaclebuffer"].is_string()?atof(obj["perceptionobstaclebuffer"].get<std::string>().c_str()):obj["perceptionobstaclebuffer"].get<double>());
        }
        if(obj.contains("curbheadingtangentchangeupperlimit"))
        {
            msg.curbheadingtangentchangeupperlimit = (obj["curbheadingtangentchangeupperlimit"].is_string()?atof(obj["curbheadingtangentchangeupperlimit"].get<std::string>().c_str()):obj["curbheadingtangentchangeupperlimit"].get<double>());
        }
        if(obj.contains("endposesdistance"))
        {
            msg.endposesdistance = (obj["endposesdistance"].is_string()?atof(obj["endposesdistance"].get<std::string>().c_str()):obj["endposesdistance"].get<double>());
        }
        return msg;
    }
    template <>
    ApolloplanningOpenSpaceRoiDeciderConfig from_json<ApolloplanningOpenSpaceRoiDeciderConfig>(nlohmann::json obj){
        return from_json_ApolloplanningOpenSpaceRoiDeciderConfig(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloplanningOpenSpaceRoiDeciderConfig &dt)
    {
        dt=from_json_ApolloplanningOpenSpaceRoiDeciderConfig(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloplanningOpenSpaceRoiDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloplanningOpenSpaceRoiDeciderConfig & dt)
    {
        os << to_json(dt);
        return os;
    }
}
