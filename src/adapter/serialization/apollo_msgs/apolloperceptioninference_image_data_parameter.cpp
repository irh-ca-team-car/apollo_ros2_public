#include "adapter/serialization/apollo_msgs/apolloperceptioninference_image_data_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceImageDataParameter &msg) {
        nlohmann::json obj;
        obj["source"] = (msg.source);
        obj["batchsize"] = (msg.batchsize);
        obj["randskip"] = (msg.randskip);
        obj["shuffle"] = (msg.shuffle);
        obj["newheight"] = (msg.newheight);
        obj["newwidth"] = (msg.newwidth);
        obj["iscolor"] = (msg.iscolor);
        obj["scale"] = (msg.scale);
        obj["meanfile"] = (msg.meanfile);
        obj["cropsize"] = (msg.cropsize);
        obj["mirror"] = (msg.mirror);
        obj["rootfolder"] = (msg.rootfolder);
        obj["prefetch"] = (msg.prefetch);
        nlohmann::json arr_imageset;
        for (auto it = msg.imageset.begin(); it != msg.imageset.end(); ++it) {
            arr_imageset.push_back(to_json(*it));
        }
        obj["imageset"] = arr_imageset;
        return obj;
    }
    ApolloperceptioninferenceImageDataParameter from_json_ApolloperceptioninferenceImageDataParameter (nlohmann::json obj) {
        ApolloperceptioninferenceImageDataParameter msg;
        if(obj.contains("source"))
        {
            msg.source = (obj["source"].is_string()?(obj["source"].get<std::string>().c_str()):obj["source"].get<std::string>());
        }
        if(obj.contains("batchsize"))
        {
            msg.batchsize = (obj["batchsize"].is_string()?atoi(obj["batchsize"].get<std::string>().c_str()):obj["batchsize"].get<uint32_t>());
        }
        if(obj.contains("randskip"))
        {
            msg.randskip = (obj["randskip"].is_string()?atoi(obj["randskip"].get<std::string>().c_str()):obj["randskip"].get<uint32_t>());
        }
        if(obj.contains("shuffle"))
        {
            msg.shuffle = (obj["shuffle"].is_string()?(bool)atoi(obj["shuffle"].get<std::string>().c_str()):obj["shuffle"].get<bool>());
        }
        if(obj.contains("newheight"))
        {
            msg.newheight = (obj["newheight"].is_string()?atoi(obj["newheight"].get<std::string>().c_str()):obj["newheight"].get<uint32_t>());
        }
        if(obj.contains("newwidth"))
        {
            msg.newwidth = (obj["newwidth"].is_string()?atoi(obj["newwidth"].get<std::string>().c_str()):obj["newwidth"].get<uint32_t>());
        }
        if(obj.contains("iscolor"))
        {
            msg.iscolor = (obj["iscolor"].is_string()?(bool)atoi(obj["iscolor"].get<std::string>().c_str()):obj["iscolor"].get<bool>());
        }
        if(obj.contains("scale"))
        {
            msg.scale = (obj["scale"].is_string()?(float)atof(obj["scale"].get<std::string>().c_str()):obj["scale"].get<float>());
        }
        if(obj.contains("meanfile"))
        {
            msg.meanfile = (obj["meanfile"].is_string()?(obj["meanfile"].get<std::string>().c_str()):obj["meanfile"].get<std::string>());
        }
        if(obj.contains("cropsize"))
        {
            msg.cropsize = (obj["cropsize"].is_string()?atoi(obj["cropsize"].get<std::string>().c_str()):obj["cropsize"].get<uint32_t>());
        }
        if(obj.contains("mirror"))
        {
            msg.mirror = (obj["mirror"].is_string()?(bool)atoi(obj["mirror"].get<std::string>().c_str()):obj["mirror"].get<bool>());
        }
        if(obj.contains("rootfolder"))
        {
            msg.rootfolder = (obj["rootfolder"].is_string()?(obj["rootfolder"].get<std::string>().c_str()):obj["rootfolder"].get<std::string>());
        }
        if(obj.contains("prefetch"))
        {
            msg.prefetch = (obj["prefetch"].is_string()?atoi(obj["prefetch"].get<std::string>().c_str()):obj["prefetch"].get<uint32_t>());
        }
        if(obj.contains("imageset"))
        {
            if(obj["imageset"].is_array())
            {
                for (auto& element : obj["imageset"])
                {
                    msg.imageset.push_back(from_json_ApolloperceptioninferenceDatasetParameter(element));
                }
            }
            else
            {
                msg.imageset.push_back(from_json_ApolloperceptioninferenceDatasetParameter(obj["imageset"]));
            }
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceImageDataParameter from_json<ApolloperceptioninferenceImageDataParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceImageDataParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceImageDataParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceImageDataParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceImageDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceImageDataParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
