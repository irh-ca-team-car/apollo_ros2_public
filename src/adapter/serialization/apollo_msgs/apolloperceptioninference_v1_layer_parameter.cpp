#include "adapter/serialization/apollo_msgs/apolloperceptioninference_v1_layer_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceV1LayerParameter &msg) {
        nlohmann::json obj;
        nlohmann::json arr_bottom;
        for (auto it = msg.bottom.begin(); it != msg.bottom.end(); ++it) {
            arr_bottom.push_back((*it));
        }
        obj["bottom"] = arr_bottom;
        nlohmann::json arr_top;
        for (auto it = msg.top.begin(); it != msg.top.end(); ++it) {
            arr_top.push_back((*it));
        }
        obj["top"] = arr_top;
        obj["name"] = (msg.name);
        nlohmann::json arr_include;
        for (auto it = msg.include.begin(); it != msg.include.end(); ++it) {
            arr_include.push_back(to_json(*it));
        }
        obj["include"] = arr_include;
        nlohmann::json arr_exclude;
        for (auto it = msg.exclude.begin(); it != msg.exclude.end(); ++it) {
            arr_exclude.push_back(to_json(*it));
        }
        obj["exclude"] = arr_exclude;
        obj["type"] = (msg.type);
        nlohmann::json arr_blobs;
        for (auto it = msg.blobs.begin(); it != msg.blobs.end(); ++it) {
            arr_blobs.push_back(to_json(*it));
        }
        obj["blobs"] = arr_blobs;
        nlohmann::json arr_param;
        for (auto it = msg.param.begin(); it != msg.param.end(); ++it) {
            arr_param.push_back((*it));
        }
        obj["param"] = arr_param;
        nlohmann::json arr_blobsharemode;
        for (auto it = msg.blobsharemode.begin(); it != msg.blobsharemode.end(); ++it) {
            arr_blobsharemode.push_back((*it));
        }
        obj["blobsharemode"] = arr_blobsharemode;
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
        nlohmann::json arr_lossweight;
        for (auto it = msg.lossweight.begin(); it != msg.lossweight.end(); ++it) {
            arr_lossweight.push_back((*it));
        }
        obj["lossweight"] = arr_lossweight;
        obj["accuracyparam"] = to_json(msg.accuracyparam);
        obj["argmaxparam"] = to_json(msg.argmaxparam);
        obj["concatparam"] = to_json(msg.concatparam);
        obj["contrastivelossparam"] = to_json(msg.contrastivelossparam);
        obj["convolutionparam"] = to_json(msg.convolutionparam);
        obj["dataparam"] = to_json(msg.dataparam);
        obj["dropoutparam"] = to_json(msg.dropoutparam);
        obj["dummydataparam"] = to_json(msg.dummydataparam);
        obj["eltwiseparam"] = to_json(msg.eltwiseparam);
        obj["expparam"] = to_json(msg.expparam);
        obj["hdf5dataparam"] = to_json(msg.hdf5dataparam);
        obj["hdf5outputparam"] = to_json(msg.hdf5outputparam);
        obj["hingelossparam"] = to_json(msg.hingelossparam);
        obj["imagedataparam"] = to_json(msg.imagedataparam);
        obj["infogainlossparam"] = to_json(msg.infogainlossparam);
        obj["innerproductparam"] = to_json(msg.innerproductparam);
        obj["lrnparam"] = to_json(msg.lrnparam);
        obj["memorydataparam"] = to_json(msg.memorydataparam);
        obj["mvnparam"] = to_json(msg.mvnparam);
        obj["poolingparam"] = to_json(msg.poolingparam);
        obj["powerparam"] = to_json(msg.powerparam);
        obj["reluparam"] = to_json(msg.reluparam);
        obj["sigmoidparam"] = to_json(msg.sigmoidparam);
        obj["softmaxparam"] = to_json(msg.softmaxparam);
        obj["sliceparam"] = to_json(msg.sliceparam);
        obj["tanhparam"] = to_json(msg.tanhparam);
        obj["thresholdparam"] = to_json(msg.thresholdparam);
        obj["windowdataparam"] = to_json(msg.windowdataparam);
        obj["transformparam"] = to_json(msg.transformparam);
        obj["lossparam"] = to_json(msg.lossparam);
        obj["layer"] = to_json(msg.layer);
        return obj;
    }
    ApolloperceptioninferenceV1LayerParameter from_json_ApolloperceptioninferenceV1LayerParameter (nlohmann::json obj) {
        ApolloperceptioninferenceV1LayerParameter msg;
        if(obj.contains("bottom"))
        {
            if(obj["bottom"].is_array())
            {
                for (auto& element : obj["bottom"])
                {
                    msg.bottom.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.bottom.push_back((obj["bottom"].is_string()?(obj["bottom"].get<std::string>().c_str()):obj["bottom"].get<std::string>()));
            }
        }
        if(obj.contains("top"))
        {
            if(obj["top"].is_array())
            {
                for (auto& element : obj["top"])
                {
                    msg.top.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.top.push_back((obj["top"].is_string()?(obj["top"].get<std::string>().c_str()):obj["top"].get<std::string>()));
            }
        }
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("include"))
        {
            if(obj["include"].is_array())
            {
                for (auto& element : obj["include"])
                {
                    msg.include.push_back(from_json_ApolloperceptioninferenceNetStateRule(element));
                }
            }
            else
            {
                msg.include.push_back(from_json_ApolloperceptioninferenceNetStateRule(obj["include"]));
            }
        }
        if(obj.contains("exclude"))
        {
            if(obj["exclude"].is_array())
            {
                for (auto& element : obj["exclude"])
                {
                    msg.exclude.push_back(from_json_ApolloperceptioninferenceNetStateRule(element));
                }
            }
            else
            {
                msg.exclude.push_back(from_json_ApolloperceptioninferenceNetStateRule(obj["exclude"]));
            }
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?atoi(obj["type"].get<std::string>().c_str()):obj["type"].get<int>());
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
        if(obj.contains("param"))
        {
            if(obj["param"].is_array())
            {
                for (auto& element : obj["param"])
                {
                    msg.param.push_back((element.is_string()?(element.get<std::string>().c_str()):element.get<std::string>()));
                }
            }
            else
            {
                msg.param.push_back((obj["param"].is_string()?(obj["param"].get<std::string>().c_str()):obj["param"].get<std::string>()));
            }
        }
        if(obj.contains("blobsharemode"))
        {
            if(obj["blobsharemode"].is_array())
            {
                for (auto& element : obj["blobsharemode"])
                {
                    msg.blobsharemode.push_back((element.is_string()?atoi(element.get<std::string>().c_str()):element.get<int>()));
                }
            }
            else
            {
                msg.blobsharemode.push_back((obj["blobsharemode"].is_string()?atoi(obj["blobsharemode"].get<std::string>().c_str()):obj["blobsharemode"].get<int>()));
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
        if(obj.contains("lossweight"))
        {
            if(obj["lossweight"].is_array())
            {
                for (auto& element : obj["lossweight"])
                {
                    msg.lossweight.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.lossweight.push_back((obj["lossweight"].is_string()?(float)atof(obj["lossweight"].get<std::string>().c_str()):obj["lossweight"].get<float>()));
            }
        }
        if(obj.contains("accuracyparam"))
        {
            msg.accuracyparam = from_json_ApolloperceptioninferenceAccuracyParameter(obj["accuracyparam"]);
        }
        if(obj.contains("argmaxparam"))
        {
            msg.argmaxparam = from_json_ApolloperceptioninferenceArgMaxParameter(obj["argmaxparam"]);
        }
        if(obj.contains("concatparam"))
        {
            msg.concatparam = from_json_ApolloperceptioninferenceConcatParameter(obj["concatparam"]);
        }
        if(obj.contains("contrastivelossparam"))
        {
            msg.contrastivelossparam = from_json_ApolloperceptioninferenceContrastiveLossParameter(obj["contrastivelossparam"]);
        }
        if(obj.contains("convolutionparam"))
        {
            msg.convolutionparam = from_json_ApolloperceptioninferenceConvolutionParameter(obj["convolutionparam"]);
        }
        if(obj.contains("dataparam"))
        {
            msg.dataparam = from_json_ApolloperceptioninferenceDataParameter(obj["dataparam"]);
        }
        if(obj.contains("dropoutparam"))
        {
            msg.dropoutparam = from_json_ApolloperceptioninferenceDropoutParameter(obj["dropoutparam"]);
        }
        if(obj.contains("dummydataparam"))
        {
            msg.dummydataparam = from_json_ApolloperceptioninferenceDummyDataParameter(obj["dummydataparam"]);
        }
        if(obj.contains("eltwiseparam"))
        {
            msg.eltwiseparam = from_json_ApolloperceptioninferenceEltwiseParameter(obj["eltwiseparam"]);
        }
        if(obj.contains("expparam"))
        {
            msg.expparam = from_json_ApolloperceptioninferenceExpParameter(obj["expparam"]);
        }
        if(obj.contains("hdf5dataparam"))
        {
            msg.hdf5dataparam = from_json_ApolloperceptioninferenceHDF5DataParameter(obj["hdf5dataparam"]);
        }
        if(obj.contains("hdf5outputparam"))
        {
            msg.hdf5outputparam = from_json_ApolloperceptioninferenceHDF5OutputParameter(obj["hdf5outputparam"]);
        }
        if(obj.contains("hingelossparam"))
        {
            msg.hingelossparam = from_json_ApolloperceptioninferenceHingeLossParameter(obj["hingelossparam"]);
        }
        if(obj.contains("imagedataparam"))
        {
            msg.imagedataparam = from_json_ApolloperceptioninferenceImageDataParameter(obj["imagedataparam"]);
        }
        if(obj.contains("infogainlossparam"))
        {
            msg.infogainlossparam = from_json_ApolloperceptioninferenceInfogainLossParameter(obj["infogainlossparam"]);
        }
        if(obj.contains("innerproductparam"))
        {
            msg.innerproductparam = from_json_ApolloperceptioninferenceInnerProductParameter(obj["innerproductparam"]);
        }
        if(obj.contains("lrnparam"))
        {
            msg.lrnparam = from_json_ApolloperceptioninferenceLRNParameter(obj["lrnparam"]);
        }
        if(obj.contains("memorydataparam"))
        {
            msg.memorydataparam = from_json_ApolloperceptioninferenceMemoryDataParameter(obj["memorydataparam"]);
        }
        if(obj.contains("mvnparam"))
        {
            msg.mvnparam = from_json_ApolloperceptioninferenceMVNParameter(obj["mvnparam"]);
        }
        if(obj.contains("poolingparam"))
        {
            msg.poolingparam = from_json_ApolloperceptioninferencePoolingParameter(obj["poolingparam"]);
        }
        if(obj.contains("powerparam"))
        {
            msg.powerparam = from_json_ApolloperceptioninferencePowerParameter(obj["powerparam"]);
        }
        if(obj.contains("reluparam"))
        {
            msg.reluparam = from_json_ApolloperceptioninferenceReLUParameter(obj["reluparam"]);
        }
        if(obj.contains("sigmoidparam"))
        {
            msg.sigmoidparam = from_json_ApolloperceptioninferenceSigmoidParameter(obj["sigmoidparam"]);
        }
        if(obj.contains("softmaxparam"))
        {
            msg.softmaxparam = from_json_ApolloperceptioninferenceSoftmaxParameter(obj["softmaxparam"]);
        }
        if(obj.contains("sliceparam"))
        {
            msg.sliceparam = from_json_ApolloperceptioninferenceSliceParameter(obj["sliceparam"]);
        }
        if(obj.contains("tanhparam"))
        {
            msg.tanhparam = from_json_ApolloperceptioninferenceTanHParameter(obj["tanhparam"]);
        }
        if(obj.contains("thresholdparam"))
        {
            msg.thresholdparam = from_json_ApolloperceptioninferenceThresholdParameter(obj["thresholdparam"]);
        }
        if(obj.contains("windowdataparam"))
        {
            msg.windowdataparam = from_json_ApolloperceptioninferenceWindowDataParameter(obj["windowdataparam"]);
        }
        if(obj.contains("transformparam"))
        {
            msg.transformparam = from_json_ApolloperceptioninferenceTransformationParameter(obj["transformparam"]);
        }
        if(obj.contains("lossparam"))
        {
            msg.lossparam = from_json_ApolloperceptioninferenceLossParameter(obj["lossparam"]);
        }
        if(obj.contains("layer"))
        {
            msg.layer = from_json_ApolloperceptioninferenceV0LayerParameter(obj["layer"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceV1LayerParameter from_json<ApolloperceptioninferenceV1LayerParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceV1LayerParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceV1LayerParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceV1LayerParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceV1LayerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceV1LayerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
