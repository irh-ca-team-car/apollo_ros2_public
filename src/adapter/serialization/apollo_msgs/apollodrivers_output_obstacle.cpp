#include "adapter/serialization/apollo_msgs/apollodrivers_output_obstacle.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApollodriversOutputObstacle &msg) {
        nlohmann::json obj;
        obj["currentspeed"] = (msg.currentspeed);
        obj["framerate"] = (msg.framerate);
        obj["trackid"] = (msg.trackid);
        obj["trackframenum"] = (msg.trackframenum);
        obj["statelabel"] = (msg.statelabel);
        obj["classlabel"] = (msg.classlabel);
        obj["continuouslabel"] = (msg.continuouslabel);
        obj["fuzzyestimationvalid"] = (msg.fuzzyestimationvalid);
        obj["obstacletype"] = (msg.obstacletype);
        obj["avgdisp"] = (msg.avgdisp);
        obj["avgdistancez"] = (msg.avgdistancez);
        obj["neardistancez"] = (msg.neardistancez);
        obj["fardistancez"] = (msg.fardistancez);
        obj["real3dleftx"] = (msg.real3dleftx);
        obj["real3drightx"] = (msg.real3drightx);
        obj["real3dcenterx"] = (msg.real3dcenterx);
        obj["real3dupy"] = (msg.real3dupy);
        obj["real3dlowy"] = (msg.real3dlowy);
        obj["firstpointx"] = (msg.firstpointx);
        obj["firstpointy"] = (msg.firstpointy);
        obj["secondpointx"] = (msg.secondpointx);
        obj["secondpointy"] = (msg.secondpointy);
        obj["thirdpointx"] = (msg.thirdpointx);
        obj["thirdpointy"] = (msg.thirdpointy);
        obj["fourthpointx"] = (msg.fourthpointx);
        obj["fourthpointy"] = (msg.fourthpointy);
        obj["fuzzyrelativedistancez"] = (msg.fuzzyrelativedistancez);
        obj["fuzzyrelativespeedz"] = (msg.fuzzyrelativespeedz);
        obj["fuzzycollisiontimez"] = (msg.fuzzycollisiontimez);
        obj["fuzzycollisionx"] = (msg.fuzzycollisionx);
        obj["fuzzy3dwidth"] = (msg.fuzzy3dwidth);
        obj["fuzzy3dcenterx"] = (msg.fuzzy3dcenterx);
        obj["fuzzy3dleftx"] = (msg.fuzzy3dleftx);
        obj["fuzzy3drightx"] = (msg.fuzzy3drightx);
        obj["fuzzy3dheight"] = (msg.fuzzy3dheight);
        obj["fuzzy3dupy"] = (msg.fuzzy3dupy);
        obj["fuzzy3dlowy"] = (msg.fuzzy3dlowy);
        obj["fuzzyrelativespeedcenterx"] = (msg.fuzzyrelativespeedcenterx);
        obj["fuzzyrelativespeedleftx"] = (msg.fuzzyrelativespeedleftx);
        obj["fuzzyrelativespeedrightx"] = (msg.fuzzyrelativespeedrightx);
        return obj;
    }
    ApollodriversOutputObstacle from_json_ApollodriversOutputObstacle (nlohmann::json obj) {
        ApollodriversOutputObstacle msg;
        if(obj.contains("currentspeed"))
        {
            msg.currentspeed = (obj["currentspeed"].is_string()?(float)atof(obj["currentspeed"].get<std::string>().c_str()):obj["currentspeed"].get<float>());
        }
        if(obj.contains("framerate"))
        {
            msg.framerate = (obj["framerate"].is_string()?(float)atof(obj["framerate"].get<std::string>().c_str()):obj["framerate"].get<float>());
        }
        if(obj.contains("trackid"))
        {
            msg.trackid = (obj["trackid"].is_string()?atoi(obj["trackid"].get<std::string>().c_str()):obj["trackid"].get<uint32_t>());
        }
        if(obj.contains("trackframenum"))
        {
            msg.trackframenum = (obj["trackframenum"].is_string()?atoi(obj["trackframenum"].get<std::string>().c_str()):obj["trackframenum"].get<uint32_t>());
        }
        if(obj.contains("statelabel"))
        {
            msg.statelabel = (obj["statelabel"].is_string()?atoi(obj["statelabel"].get<std::string>().c_str()):obj["statelabel"].get<uint32_t>());
        }
        if(obj.contains("classlabel"))
        {
            msg.classlabel = (obj["classlabel"].is_string()?atoi(obj["classlabel"].get<std::string>().c_str()):obj["classlabel"].get<uint32_t>());
        }
        if(obj.contains("continuouslabel"))
        {
            msg.continuouslabel = (obj["continuouslabel"].is_string()?atoi(obj["continuouslabel"].get<std::string>().c_str()):obj["continuouslabel"].get<uint32_t>());
        }
        if(obj.contains("fuzzyestimationvalid"))
        {
            msg.fuzzyestimationvalid = (obj["fuzzyestimationvalid"].is_string()?atoi(obj["fuzzyestimationvalid"].get<std::string>().c_str()):obj["fuzzyestimationvalid"].get<uint32_t>());
        }
        if(obj.contains("obstacletype"))
        {
            msg.obstacletype = (obj["obstacletype"].is_string()?atoi(obj["obstacletype"].get<std::string>().c_str()):obj["obstacletype"].get<int>());
        }
        if(obj.contains("avgdisp"))
        {
            msg.avgdisp = (obj["avgdisp"].is_string()?(float)atof(obj["avgdisp"].get<std::string>().c_str()):obj["avgdisp"].get<float>());
        }
        if(obj.contains("avgdistancez"))
        {
            msg.avgdistancez = (obj["avgdistancez"].is_string()?(float)atof(obj["avgdistancez"].get<std::string>().c_str()):obj["avgdistancez"].get<float>());
        }
        if(obj.contains("neardistancez"))
        {
            msg.neardistancez = (obj["neardistancez"].is_string()?(float)atof(obj["neardistancez"].get<std::string>().c_str()):obj["neardistancez"].get<float>());
        }
        if(obj.contains("fardistancez"))
        {
            msg.fardistancez = (obj["fardistancez"].is_string()?(float)atof(obj["fardistancez"].get<std::string>().c_str()):obj["fardistancez"].get<float>());
        }
        if(obj.contains("real3dleftx"))
        {
            msg.real3dleftx = (obj["real3dleftx"].is_string()?(float)atof(obj["real3dleftx"].get<std::string>().c_str()):obj["real3dleftx"].get<float>());
        }
        if(obj.contains("real3drightx"))
        {
            msg.real3drightx = (obj["real3drightx"].is_string()?(float)atof(obj["real3drightx"].get<std::string>().c_str()):obj["real3drightx"].get<float>());
        }
        if(obj.contains("real3dcenterx"))
        {
            msg.real3dcenterx = (obj["real3dcenterx"].is_string()?(float)atof(obj["real3dcenterx"].get<std::string>().c_str()):obj["real3dcenterx"].get<float>());
        }
        if(obj.contains("real3dupy"))
        {
            msg.real3dupy = (obj["real3dupy"].is_string()?(float)atof(obj["real3dupy"].get<std::string>().c_str()):obj["real3dupy"].get<float>());
        }
        if(obj.contains("real3dlowy"))
        {
            msg.real3dlowy = (obj["real3dlowy"].is_string()?(float)atof(obj["real3dlowy"].get<std::string>().c_str()):obj["real3dlowy"].get<float>());
        }
        if(obj.contains("firstpointx"))
        {
            msg.firstpointx = (obj["firstpointx"].is_string()?atoi(obj["firstpointx"].get<std::string>().c_str()):obj["firstpointx"].get<uint32_t>());
        }
        if(obj.contains("firstpointy"))
        {
            msg.firstpointy = (obj["firstpointy"].is_string()?atoi(obj["firstpointy"].get<std::string>().c_str()):obj["firstpointy"].get<uint32_t>());
        }
        if(obj.contains("secondpointx"))
        {
            msg.secondpointx = (obj["secondpointx"].is_string()?atoi(obj["secondpointx"].get<std::string>().c_str()):obj["secondpointx"].get<uint32_t>());
        }
        if(obj.contains("secondpointy"))
        {
            msg.secondpointy = (obj["secondpointy"].is_string()?atoi(obj["secondpointy"].get<std::string>().c_str()):obj["secondpointy"].get<uint32_t>());
        }
        if(obj.contains("thirdpointx"))
        {
            msg.thirdpointx = (obj["thirdpointx"].is_string()?atoi(obj["thirdpointx"].get<std::string>().c_str()):obj["thirdpointx"].get<uint32_t>());
        }
        if(obj.contains("thirdpointy"))
        {
            msg.thirdpointy = (obj["thirdpointy"].is_string()?atoi(obj["thirdpointy"].get<std::string>().c_str()):obj["thirdpointy"].get<uint32_t>());
        }
        if(obj.contains("fourthpointx"))
        {
            msg.fourthpointx = (obj["fourthpointx"].is_string()?atoi(obj["fourthpointx"].get<std::string>().c_str()):obj["fourthpointx"].get<uint32_t>());
        }
        if(obj.contains("fourthpointy"))
        {
            msg.fourthpointy = (obj["fourthpointy"].is_string()?atoi(obj["fourthpointy"].get<std::string>().c_str()):obj["fourthpointy"].get<uint32_t>());
        }
        if(obj.contains("fuzzyrelativedistancez"))
        {
            msg.fuzzyrelativedistancez = (obj["fuzzyrelativedistancez"].is_string()?(float)atof(obj["fuzzyrelativedistancez"].get<std::string>().c_str()):obj["fuzzyrelativedistancez"].get<float>());
        }
        if(obj.contains("fuzzyrelativespeedz"))
        {
            msg.fuzzyrelativespeedz = (obj["fuzzyrelativespeedz"].is_string()?(float)atof(obj["fuzzyrelativespeedz"].get<std::string>().c_str()):obj["fuzzyrelativespeedz"].get<float>());
        }
        if(obj.contains("fuzzycollisiontimez"))
        {
            msg.fuzzycollisiontimez = (obj["fuzzycollisiontimez"].is_string()?(float)atof(obj["fuzzycollisiontimez"].get<std::string>().c_str()):obj["fuzzycollisiontimez"].get<float>());
        }
        if(obj.contains("fuzzycollisionx"))
        {
            msg.fuzzycollisionx = (obj["fuzzycollisionx"].is_string()?atoi(obj["fuzzycollisionx"].get<std::string>().c_str()):obj["fuzzycollisionx"].get<uint32_t>());
        }
        if(obj.contains("fuzzy3dwidth"))
        {
            msg.fuzzy3dwidth = (obj["fuzzy3dwidth"].is_string()?(float)atof(obj["fuzzy3dwidth"].get<std::string>().c_str()):obj["fuzzy3dwidth"].get<float>());
        }
        if(obj.contains("fuzzy3dcenterx"))
        {
            msg.fuzzy3dcenterx = (obj["fuzzy3dcenterx"].is_string()?(float)atof(obj["fuzzy3dcenterx"].get<std::string>().c_str()):obj["fuzzy3dcenterx"].get<float>());
        }
        if(obj.contains("fuzzy3dleftx"))
        {
            msg.fuzzy3dleftx = (obj["fuzzy3dleftx"].is_string()?(float)atof(obj["fuzzy3dleftx"].get<std::string>().c_str()):obj["fuzzy3dleftx"].get<float>());
        }
        if(obj.contains("fuzzy3drightx"))
        {
            msg.fuzzy3drightx = (obj["fuzzy3drightx"].is_string()?(float)atof(obj["fuzzy3drightx"].get<std::string>().c_str()):obj["fuzzy3drightx"].get<float>());
        }
        if(obj.contains("fuzzy3dheight"))
        {
            msg.fuzzy3dheight = (obj["fuzzy3dheight"].is_string()?(float)atof(obj["fuzzy3dheight"].get<std::string>().c_str()):obj["fuzzy3dheight"].get<float>());
        }
        if(obj.contains("fuzzy3dupy"))
        {
            msg.fuzzy3dupy = (obj["fuzzy3dupy"].is_string()?(float)atof(obj["fuzzy3dupy"].get<std::string>().c_str()):obj["fuzzy3dupy"].get<float>());
        }
        if(obj.contains("fuzzy3dlowy"))
        {
            msg.fuzzy3dlowy = (obj["fuzzy3dlowy"].is_string()?(float)atof(obj["fuzzy3dlowy"].get<std::string>().c_str()):obj["fuzzy3dlowy"].get<float>());
        }
        if(obj.contains("fuzzyrelativespeedcenterx"))
        {
            msg.fuzzyrelativespeedcenterx = (obj["fuzzyrelativespeedcenterx"].is_string()?(float)atof(obj["fuzzyrelativespeedcenterx"].get<std::string>().c_str()):obj["fuzzyrelativespeedcenterx"].get<float>());
        }
        if(obj.contains("fuzzyrelativespeedleftx"))
        {
            msg.fuzzyrelativespeedleftx = (obj["fuzzyrelativespeedleftx"].is_string()?(float)atof(obj["fuzzyrelativespeedleftx"].get<std::string>().c_str()):obj["fuzzyrelativespeedleftx"].get<float>());
        }
        if(obj.contains("fuzzyrelativespeedrightx"))
        {
            msg.fuzzyrelativespeedrightx = (obj["fuzzyrelativespeedrightx"].is_string()?(float)atof(obj["fuzzyrelativespeedrightx"].get<std::string>().c_str()):obj["fuzzyrelativespeedrightx"].get<float>());
        }
        return msg;
    }
    template <>
    ApollodriversOutputObstacle from_json<ApollodriversOutputObstacle>(nlohmann::json obj){
        return from_json_ApollodriversOutputObstacle(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApollodriversOutputObstacle &dt)
    {
        dt=from_json_ApollodriversOutputObstacle(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApollodriversOutputObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApollodriversOutputObstacle & dt)
    {
        os << to_json(dt);
        return os;
    }
}
