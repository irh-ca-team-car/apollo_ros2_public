#include "adapter/serialization/apollo_msgs/apolloperceptioninference_v0_layer_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceV0LayerParameter &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["type"] = (msg.type);
        obj["numoutput"] = (msg.numoutput);
        obj["biasterm"] = (msg.biasterm);
        obj["weightfiller"] = to_json(msg.weightfiller);
        obj["biasfiller"] = to_json(msg.biasfiller);
        obj["pad"] = (msg.pad);
        obj["kernelsize"] = (msg.kernelsize);
        obj["group"] = (msg.group);
        obj["stride"] = (msg.stride);
        obj["pool"] = (msg.pool);
        obj["dropoutratio"] = (msg.dropoutratio);
        obj["localsize"] = (msg.localsize);
        obj["alpha"] = (msg.alpha);
        obj["beta"] = (msg.beta);
        obj["k"] = (msg.k);
        obj["source"] = (msg.source);
        obj["scale"] = (msg.scale);
        obj["meanfile"] = (msg.meanfile);
        obj["batchsize"] = (msg.batchsize);
        obj["cropsize"] = (msg.cropsize);
        obj["mirror"] = (msg.mirror);
        nlohmann::json arr_blobs;
        for (auto it = msg.blobs.begin(); it != msg.blobs.end(); ++it) {
            arr_blobs.push_back(to_json(*it));
        }
        obj["blobs"] = arr_blobs;
        nlohmann::json arr_blobslr;
        for (auto it = msg.blobslr.begin(); it != msg.blobslr.end(); ++it) {
            arr_blobslr.push_back((*it));
        }
        obj["blobslr"] = arr_blobslr;
        nlohmann::json arr_weightdecay;
        for (auto it = msg.weightdecay.begin(); it != msg.weightdecay.end(); ++it) {
            arr_weightdecay.push_back((*it));
        }
        obj["weightdecay"] = arr_weightdecay;
        obj["randskip"] = (msg.randskip);
        obj["detfgthreshold"] = (msg.detfgthreshold);
        obj["detbgthreshold"] = (msg.detbgthreshold);
        obj["detfgfraction"] = (msg.detfgfraction);
        obj["detcontextpad"] = (msg.detcontextpad);
        obj["detcropmode"] = (msg.detcropmode);
        obj["newnum"] = (msg.newnum);
        obj["newchannels"] = (msg.newchannels);
        obj["newheight"] = (msg.newheight);
        obj["newwidth"] = (msg.newwidth);
        obj["shuffleimages"] = (msg.shuffleimages);
        obj["concatdim"] = (msg.concatdim);
        obj["hdf5outputparam"] = to_json(msg.hdf5outputparam);
        return obj;
    }
    ApolloperceptioninferenceV0LayerParameter from_json_ApolloperceptioninferenceV0LayerParameter (nlohmann::json obj) {
        ApolloperceptioninferenceV0LayerParameter msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?(obj["type"].get<std::string>().c_str()):obj["type"].get<std::string>());
        }
        if(obj.contains("numoutput"))
        {
            msg.numoutput = (obj["numoutput"].is_string()?atoi(obj["numoutput"].get<std::string>().c_str()):obj["numoutput"].get<uint32_t>());
        }
        if(obj.contains("biasterm"))
        {
            msg.biasterm = (obj["biasterm"].is_string()?(bool)atoi(obj["biasterm"].get<std::string>().c_str()):obj["biasterm"].get<bool>());
        }
        if(obj.contains("weightfiller"))
        {
            msg.weightfiller = from_json_ApolloperceptioninferenceFillerParameter(obj["weightfiller"]);
        }
        if(obj.contains("biasfiller"))
        {
            msg.biasfiller = from_json_ApolloperceptioninferenceFillerParameter(obj["biasfiller"]);
        }
        if(obj.contains("pad"))
        {
            msg.pad = (obj["pad"].is_string()?atoi(obj["pad"].get<std::string>().c_str()):obj["pad"].get<uint32_t>());
        }
        if(obj.contains("kernelsize"))
        {
            msg.kernelsize = (obj["kernelsize"].is_string()?atoi(obj["kernelsize"].get<std::string>().c_str()):obj["kernelsize"].get<uint32_t>());
        }
        if(obj.contains("group"))
        {
            msg.group = (obj["group"].is_string()?atoi(obj["group"].get<std::string>().c_str()):obj["group"].get<uint32_t>());
        }
        if(obj.contains("stride"))
        {
            msg.stride = (obj["stride"].is_string()?atoi(obj["stride"].get<std::string>().c_str()):obj["stride"].get<uint32_t>());
        }
        if(obj.contains("pool"))
        {
            msg.pool = (obj["pool"].is_string()?atoi(obj["pool"].get<std::string>().c_str()):obj["pool"].get<int>());
        }
        if(obj.contains("dropoutratio"))
        {
            msg.dropoutratio = (obj["dropoutratio"].is_string()?(float)atof(obj["dropoutratio"].get<std::string>().c_str()):obj["dropoutratio"].get<float>());
        }
        if(obj.contains("localsize"))
        {
            msg.localsize = (obj["localsize"].is_string()?atoi(obj["localsize"].get<std::string>().c_str()):obj["localsize"].get<uint32_t>());
        }
        if(obj.contains("alpha"))
        {
            msg.alpha = (obj["alpha"].is_string()?(float)atof(obj["alpha"].get<std::string>().c_str()):obj["alpha"].get<float>());
        }
        if(obj.contains("beta"))
        {
            msg.beta = (obj["beta"].is_string()?(float)atof(obj["beta"].get<std::string>().c_str()):obj["beta"].get<float>());
        }
        if(obj.contains("k"))
        {
            msg.k = (obj["k"].is_string()?(float)atof(obj["k"].get<std::string>().c_str()):obj["k"].get<float>());
        }
        if(obj.contains("source"))
        {
            msg.source = (obj["source"].is_string()?(obj["source"].get<std::string>().c_str()):obj["source"].get<std::string>());
        }
        if(obj.contains("scale"))
        {
            msg.scale = (obj["scale"].is_string()?(float)atof(obj["scale"].get<std::string>().c_str()):obj["scale"].get<float>());
        }
        if(obj.contains("meanfile"))
        {
            msg.meanfile = (obj["meanfile"].is_string()?(obj["meanfile"].get<std::string>().c_str()):obj["meanfile"].get<std::string>());
        }
        if(obj.contains("batchsize"))
        {
            msg.batchsize = (obj["batchsize"].is_string()?atoi(obj["batchsize"].get<std::string>().c_str()):obj["batchsize"].get<uint32_t>());
        }
        if(obj.contains("cropsize"))
        {
            msg.cropsize = (obj["cropsize"].is_string()?atoi(obj["cropsize"].get<std::string>().c_str()):obj["cropsize"].get<uint32_t>());
        }
        if(obj.contains("mirror"))
        {
            msg.mirror = (obj["mirror"].is_string()?(bool)atoi(obj["mirror"].get<std::string>().c_str()):obj["mirror"].get<bool>());
        }
        if(obj.contains("blobs"))
        {
            if(obj["blobs"].is_array())
            {
                for (auto& element : obj["blobs"])
                {
                    msg.blobs.push_back(from_json_ApolloperceptioninferenceBlobProto(element));
                }
            }
            else
            {
                msg.blobs.push_back(from_json_ApolloperceptioninferenceBlobProto(obj["blobs"]));
            }
        }
        if(obj.contains("blobslr"))
        {
            if(obj["blobslr"].is_array())
            {
                for (auto& element : obj["blobslr"])
                {
                    msg.blobslr.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.blobslr.push_back((obj["blobslr"].is_string()?(float)atof(obj["blobslr"].get<std::string>().c_str()):obj["blobslr"].get<float>()));
            }
        }
        if(obj.contains("weightdecay"))
        {
            if(obj["weightdecay"].is_array())
            {
                for (auto& element : obj["weightdecay"])
                {
                    msg.weightdecay.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.weightdecay.push_back((obj["weightdecay"].is_string()?(float)atof(obj["weightdecay"].get<std::string>().c_str()):obj["weightdecay"].get<float>()));
            }
        }
        if(obj.contains("randskip"))
        {
            msg.randskip = (obj["randskip"].is_string()?atoi(obj["randskip"].get<std::string>().c_str()):obj["randskip"].get<uint32_t>());
        }
        if(obj.contains("detfgthreshold"))
        {
            msg.detfgthreshold = (obj["detfgthreshold"].is_string()?(float)atof(obj["detfgthreshold"].get<std::string>().c_str()):obj["detfgthreshold"].get<float>());
        }
        if(obj.contains("detbgthreshold"))
        {
            msg.detbgthreshold = (obj["detbgthreshold"].is_string()?(float)atof(obj["detbgthreshold"].get<std::string>().c_str()):obj["detbgthreshold"].get<float>());
        }
        if(obj.contains("detfgfraction"))
        {
            msg.detfgfraction = (obj["detfgfraction"].is_string()?(float)atof(obj["detfgfraction"].get<std::string>().c_str()):obj["detfgfraction"].get<float>());
        }
        if(obj.contains("detcontextpad"))
        {
            msg.detcontextpad = (obj["detcontextpad"].is_string()?atoi(obj["detcontextpad"].get<std::string>().c_str()):obj["detcontextpad"].get<uint32_t>());
        }
        if(obj.contains("detcropmode"))
        {
            msg.detcropmode = (obj["detcropmode"].is_string()?(obj["detcropmode"].get<std::string>().c_str()):obj["detcropmode"].get<std::string>());
        }
        if(obj.contains("newnum"))
        {
            msg.newnum = (obj["newnum"].is_string()?atoi(obj["newnum"].get<std::string>().c_str()):obj["newnum"].get<int>());
        }
        if(obj.contains("newchannels"))
        {
            msg.newchannels = (obj["newchannels"].is_string()?atoi(obj["newchannels"].get<std::string>().c_str()):obj["newchannels"].get<int>());
        }
        if(obj.contains("newheight"))
        {
            msg.newheight = (obj["newheight"].is_string()?atoi(obj["newheight"].get<std::string>().c_str()):obj["newheight"].get<int>());
        }
        if(obj.contains("newwidth"))
        {
            msg.newwidth = (obj["newwidth"].is_string()?atoi(obj["newwidth"].get<std::string>().c_str()):obj["newwidth"].get<int>());
        }
        if(obj.contains("shuffleimages"))
        {
            msg.shuffleimages = (obj["shuffleimages"].is_string()?(bool)atoi(obj["shuffleimages"].get<std::string>().c_str()):obj["shuffleimages"].get<bool>());
        }
        if(obj.contains("concatdim"))
        {
            msg.concatdim = (obj["concatdim"].is_string()?atoi(obj["concatdim"].get<std::string>().c_str()):obj["concatdim"].get<uint32_t>());
        }
        if(obj.contains("hdf5outputparam"))
        {
            msg.hdf5outputparam = from_json_ApolloperceptioninferenceHDF5OutputParameter(obj["hdf5outputparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceV0LayerParameter from_json<ApolloperceptioninferenceV0LayerParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceV0LayerParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceV0LayerParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceV0LayerParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceV0LayerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceV0LayerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
