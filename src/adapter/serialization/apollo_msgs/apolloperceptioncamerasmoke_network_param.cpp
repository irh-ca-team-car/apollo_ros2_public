#include "adapter/serialization/apollo_msgs/apolloperceptioncamerasmoke_network_param.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioncamerasmokeNetworkParam &msg) {
        nlohmann::json obj;
        obj["det1locblob"] = (msg.det1locblob);
        obj["det1objblob"] = (msg.det1objblob);
        obj["det1clsblob"] = (msg.det1clsblob);
        obj["det1oriblob"] = (msg.det1oriblob);
        obj["det1oriconfblob"] = (msg.det1oriconfblob);
        obj["det1dimblob"] = (msg.det1dimblob);
        obj["det2locblob"] = (msg.det2locblob);
        obj["det2objblob"] = (msg.det2objblob);
        obj["det2clsblob"] = (msg.det2clsblob);
        obj["det2oriblob"] = (msg.det2oriblob);
        obj["det2oriconfblob"] = (msg.det2oriconfblob);
        obj["det2dimblob"] = (msg.det2dimblob);
        obj["det3locblob"] = (msg.det3locblob);
        obj["det3objblob"] = (msg.det3objblob);
        obj["det3clsblob"] = (msg.det3clsblob);
        obj["det3oriblob"] = (msg.det3oriblob);
        obj["det3oriconfblob"] = (msg.det3oriconfblob);
        obj["det3dimblob"] = (msg.det3dimblob);
        obj["lofblob"] = (msg.lofblob);
        obj["lorblob"] = (msg.lorblob);
        obj["inputdatablob"] = (msg.inputdatablob);
        obj["inputratioblob"] = (msg.inputratioblob);
        obj["inputinstricblob"] = (msg.inputinstricblob);
        obj["roisblob"] = (msg.roisblob);
        obj["featblob"] = (msg.featblob);
        obj["boxblob"] = (msg.boxblob);
        obj["ioublob"] = (msg.ioublob);
        obj["brvisblob"] = (msg.brvisblob);
        obj["brswtblob"] = (msg.brswtblob);
        obj["ltvisblob"] = (msg.ltvisblob);
        obj["ltswtblob"] = (msg.ltswtblob);
        obj["rtvisblob"] = (msg.rtvisblob);
        obj["rtswtblob"] = (msg.rtswtblob);
        obj["areaidblob"] = (msg.areaidblob);
        obj["visibleratioblob"] = (msg.visibleratioblob);
        obj["cutoffratioblob"] = (msg.cutoffratioblob);
        return obj;
    }
    ApolloperceptioncamerasmokeNetworkParam from_json_ApolloperceptioncamerasmokeNetworkParam (nlohmann::json obj) {
        ApolloperceptioncamerasmokeNetworkParam msg;
        if(obj.contains("det1locblob"))
        {
            msg.det1locblob = (obj["det1locblob"].is_string()?(obj["det1locblob"].get<std::string>().c_str()):obj["det1locblob"].get<std::string>());
        }
        if(obj.contains("det1objblob"))
        {
            msg.det1objblob = (obj["det1objblob"].is_string()?(obj["det1objblob"].get<std::string>().c_str()):obj["det1objblob"].get<std::string>());
        }
        if(obj.contains("det1clsblob"))
        {
            msg.det1clsblob = (obj["det1clsblob"].is_string()?(obj["det1clsblob"].get<std::string>().c_str()):obj["det1clsblob"].get<std::string>());
        }
        if(obj.contains("det1oriblob"))
        {
            msg.det1oriblob = (obj["det1oriblob"].is_string()?(obj["det1oriblob"].get<std::string>().c_str()):obj["det1oriblob"].get<std::string>());
        }
        if(obj.contains("det1oriconfblob"))
        {
            msg.det1oriconfblob = (obj["det1oriconfblob"].is_string()?(obj["det1oriconfblob"].get<std::string>().c_str()):obj["det1oriconfblob"].get<std::string>());
        }
        if(obj.contains("det1dimblob"))
        {
            msg.det1dimblob = (obj["det1dimblob"].is_string()?(obj["det1dimblob"].get<std::string>().c_str()):obj["det1dimblob"].get<std::string>());
        }
        if(obj.contains("det2locblob"))
        {
            msg.det2locblob = (obj["det2locblob"].is_string()?(obj["det2locblob"].get<std::string>().c_str()):obj["det2locblob"].get<std::string>());
        }
        if(obj.contains("det2objblob"))
        {
            msg.det2objblob = (obj["det2objblob"].is_string()?(obj["det2objblob"].get<std::string>().c_str()):obj["det2objblob"].get<std::string>());
        }
        if(obj.contains("det2clsblob"))
        {
            msg.det2clsblob = (obj["det2clsblob"].is_string()?(obj["det2clsblob"].get<std::string>().c_str()):obj["det2clsblob"].get<std::string>());
        }
        if(obj.contains("det2oriblob"))
        {
            msg.det2oriblob = (obj["det2oriblob"].is_string()?(obj["det2oriblob"].get<std::string>().c_str()):obj["det2oriblob"].get<std::string>());
        }
        if(obj.contains("det2oriconfblob"))
        {
            msg.det2oriconfblob = (obj["det2oriconfblob"].is_string()?(obj["det2oriconfblob"].get<std::string>().c_str()):obj["det2oriconfblob"].get<std::string>());
        }
        if(obj.contains("det2dimblob"))
        {
            msg.det2dimblob = (obj["det2dimblob"].is_string()?(obj["det2dimblob"].get<std::string>().c_str()):obj["det2dimblob"].get<std::string>());
        }
        if(obj.contains("det3locblob"))
        {
            msg.det3locblob = (obj["det3locblob"].is_string()?(obj["det3locblob"].get<std::string>().c_str()):obj["det3locblob"].get<std::string>());
        }
        if(obj.contains("det3objblob"))
        {
            msg.det3objblob = (obj["det3objblob"].is_string()?(obj["det3objblob"].get<std::string>().c_str()):obj["det3objblob"].get<std::string>());
        }
        if(obj.contains("det3clsblob"))
        {
            msg.det3clsblob = (obj["det3clsblob"].is_string()?(obj["det3clsblob"].get<std::string>().c_str()):obj["det3clsblob"].get<std::string>());
        }
        if(obj.contains("det3oriblob"))
        {
            msg.det3oriblob = (obj["det3oriblob"].is_string()?(obj["det3oriblob"].get<std::string>().c_str()):obj["det3oriblob"].get<std::string>());
        }
        if(obj.contains("det3oriconfblob"))
        {
            msg.det3oriconfblob = (obj["det3oriconfblob"].is_string()?(obj["det3oriconfblob"].get<std::string>().c_str()):obj["det3oriconfblob"].get<std::string>());
        }
        if(obj.contains("det3dimblob"))
        {
            msg.det3dimblob = (obj["det3dimblob"].is_string()?(obj["det3dimblob"].get<std::string>().c_str()):obj["det3dimblob"].get<std::string>());
        }
        if(obj.contains("lofblob"))
        {
            msg.lofblob = (obj["lofblob"].is_string()?(obj["lofblob"].get<std::string>().c_str()):obj["lofblob"].get<std::string>());
        }
        if(obj.contains("lorblob"))
        {
            msg.lorblob = (obj["lorblob"].is_string()?(obj["lorblob"].get<std::string>().c_str()):obj["lorblob"].get<std::string>());
        }
        if(obj.contains("inputdatablob"))
        {
            msg.inputdatablob = (obj["inputdatablob"].is_string()?(obj["inputdatablob"].get<std::string>().c_str()):obj["inputdatablob"].get<std::string>());
        }
        if(obj.contains("inputratioblob"))
        {
            msg.inputratioblob = (obj["inputratioblob"].is_string()?(obj["inputratioblob"].get<std::string>().c_str()):obj["inputratioblob"].get<std::string>());
        }
        if(obj.contains("inputinstricblob"))
        {
            msg.inputinstricblob = (obj["inputinstricblob"].is_string()?(obj["inputinstricblob"].get<std::string>().c_str()):obj["inputinstricblob"].get<std::string>());
        }
        if(obj.contains("roisblob"))
        {
            msg.roisblob = (obj["roisblob"].is_string()?(obj["roisblob"].get<std::string>().c_str()):obj["roisblob"].get<std::string>());
        }
        if(obj.contains("featblob"))
        {
            msg.featblob = (obj["featblob"].is_string()?(obj["featblob"].get<std::string>().c_str()):obj["featblob"].get<std::string>());
        }
        if(obj.contains("boxblob"))
        {
            msg.boxblob = (obj["boxblob"].is_string()?(obj["boxblob"].get<std::string>().c_str()):obj["boxblob"].get<std::string>());
        }
        if(obj.contains("ioublob"))
        {
            msg.ioublob = (obj["ioublob"].is_string()?(obj["ioublob"].get<std::string>().c_str()):obj["ioublob"].get<std::string>());
        }
        if(obj.contains("brvisblob"))
        {
            msg.brvisblob = (obj["brvisblob"].is_string()?(obj["brvisblob"].get<std::string>().c_str()):obj["brvisblob"].get<std::string>());
        }
        if(obj.contains("brswtblob"))
        {
            msg.brswtblob = (obj["brswtblob"].is_string()?(obj["brswtblob"].get<std::string>().c_str()):obj["brswtblob"].get<std::string>());
        }
        if(obj.contains("ltvisblob"))
        {
            msg.ltvisblob = (obj["ltvisblob"].is_string()?(obj["ltvisblob"].get<std::string>().c_str()):obj["ltvisblob"].get<std::string>());
        }
        if(obj.contains("ltswtblob"))
        {
            msg.ltswtblob = (obj["ltswtblob"].is_string()?(obj["ltswtblob"].get<std::string>().c_str()):obj["ltswtblob"].get<std::string>());
        }
        if(obj.contains("rtvisblob"))
        {
            msg.rtvisblob = (obj["rtvisblob"].is_string()?(obj["rtvisblob"].get<std::string>().c_str()):obj["rtvisblob"].get<std::string>());
        }
        if(obj.contains("rtswtblob"))
        {
            msg.rtswtblob = (obj["rtswtblob"].is_string()?(obj["rtswtblob"].get<std::string>().c_str()):obj["rtswtblob"].get<std::string>());
        }
        if(obj.contains("areaidblob"))
        {
            msg.areaidblob = (obj["areaidblob"].is_string()?(obj["areaidblob"].get<std::string>().c_str()):obj["areaidblob"].get<std::string>());
        }
        if(obj.contains("visibleratioblob"))
        {
            msg.visibleratioblob = (obj["visibleratioblob"].is_string()?(obj["visibleratioblob"].get<std::string>().c_str()):obj["visibleratioblob"].get<std::string>());
        }
        if(obj.contains("cutoffratioblob"))
        {
            msg.cutoffratioblob = (obj["cutoffratioblob"].is_string()?(obj["cutoffratioblob"].get<std::string>().c_str()):obj["cutoffratioblob"].get<std::string>());
        }
        return msg;
    }
    template <>
    ApolloperceptioncamerasmokeNetworkParam from_json<ApolloperceptioncamerasmokeNetworkParam>(nlohmann::json obj){
        return from_json_ApolloperceptioncamerasmokeNetworkParam(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioncamerasmokeNetworkParam &dt)
    {
        dt=from_json_ApolloperceptioncamerasmokeNetworkParam(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioncamerasmokeNetworkParam & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioncamerasmokeNetworkParam & dt)
    {
        os << to_json(dt);
        return os;
    }
}
