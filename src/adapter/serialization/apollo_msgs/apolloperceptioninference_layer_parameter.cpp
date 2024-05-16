#include "adapter/serialization/apollo_msgs/apolloperceptioninference_layer_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceLayerParameter &msg) {
        nlohmann::json obj;
        obj["name"] = (msg.name);
        obj["type"] = (msg.type);
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
        obj["phase"] = (msg.phase);
        nlohmann::json arr_lossweight;
        for (auto it = msg.lossweight.begin(); it != msg.lossweight.end(); ++it) {
            arr_lossweight.push_back((*it));
        }
        obj["lossweight"] = arr_lossweight;
        nlohmann::json arr_param;
        for (auto it = msg.param.begin(); it != msg.param.end(); ++it) {
            arr_param.push_back(to_json(*it));
        }
        obj["param"] = arr_param;
        nlohmann::json arr_blobs;
        for (auto it = msg.blobs.begin(); it != msg.blobs.end(); ++it) {
            arr_blobs.push_back(to_json(*it));
        }
        obj["blobs"] = arr_blobs;
        nlohmann::json arr_propagatedown;
        for (auto it = msg.propagatedown.begin(); it != msg.propagatedown.end(); ++it) {
            arr_propagatedown.push_back((*it));
        }
        obj["propagatedown"] = arr_propagatedown;
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
        obj["transformparam"] = to_json(msg.transformparam);
        obj["lossparam"] = to_json(msg.lossparam);
        obj["accuracyparam"] = to_json(msg.accuracyparam);
        obj["annotateddataparam"] = to_json(msg.annotateddataparam);
        obj["argmaxparam"] = to_json(msg.argmaxparam);
        obj["batchnormparam"] = to_json(msg.batchnormparam);
        obj["bboxregparam"] = to_json(msg.bboxregparam);
        obj["biasparam"] = to_json(msg.biasparam);
        obj["concatparam"] = to_json(msg.concatparam);
        obj["contrastivelossparam"] = to_json(msg.contrastivelossparam);
        obj["convolutionparam"] = to_json(msg.convolutionparam);
        obj["cropparam"] = to_json(msg.cropparam);
        obj["dataparam"] = to_json(msg.dataparam);
        obj["detectionevaluateparam"] = to_json(msg.detectionevaluateparam);
        obj["detectionoutputparam"] = to_json(msg.detectionoutputparam);
        obj["detectionoutputssdparam"] = to_json(msg.detectionoutputssdparam);
        obj["dfmbpsroipoolingparam"] = to_json(msg.dfmbpsroipoolingparam);
        obj["dropoutparam"] = to_json(msg.dropoutparam);
        obj["dummydataparam"] = to_json(msg.dummydataparam);
        obj["eltwiseparam"] = to_json(msg.eltwiseparam);
        obj["eluparam"] = to_json(msg.eluparam);
        obj["embedparam"] = to_json(msg.embedparam);
        obj["expparam"] = to_json(msg.expparam);
        obj["flattenparam"] = to_json(msg.flattenparam);
        obj["hdf5dataparam"] = to_json(msg.hdf5dataparam);
        obj["hdf5outputparam"] = to_json(msg.hdf5outputparam);
        obj["hingelossparam"] = to_json(msg.hingelossparam);
        obj["imagedataparam"] = to_json(msg.imagedataparam);
        nlohmann::json arr_yolodataparam;
        for (auto it = msg.yolodataparam.begin(); it != msg.yolodataparam.end(); ++it) {
            arr_yolodataparam.push_back(to_json(*it));
        }
        obj["yolodataparam"] = arr_yolodataparam;
        nlohmann::json arr_dataprobparam;
        for (auto it = msg.dataprobparam.begin(); it != msg.dataprobparam.end(); ++it) {
            arr_dataprobparam.push_back((*it));
        }
        obj["dataprobparam"] = arr_dataprobparam;
        obj["infogainlossparam"] = to_json(msg.infogainlossparam);
        obj["innerproductparam"] = to_json(msg.innerproductparam);
        obj["inputparam"] = to_json(msg.inputparam);
        obj["logparam"] = to_json(msg.logparam);
        obj["lrnparam"] = to_json(msg.lrnparam);
        obj["memorydataparam"] = to_json(msg.memorydataparam);
        obj["multiboxlossparam"] = to_json(msg.multiboxlossparam);
        obj["regionparam"] = to_json(msg.regionparam);
        obj["regionoutputparam"] = to_json(msg.regionoutputparam);
        obj["regionproposalparam"] = to_json(msg.regionproposalparam);
        obj["yolotargetparam"] = to_json(msg.yolotargetparam);
        obj["yoloanchorsparam"] = to_json(msg.yoloanchorsparam);
        obj["yololossparam"] = to_json(msg.yololossparam);
        obj["yolodumpparam"] = to_json(msg.yolodumpparam);
        obj["paddingparam"] = to_json(msg.paddingparam);
        obj["reorgparam"] = to_json(msg.reorgparam);
        obj["mvnparam"] = to_json(msg.mvnparam);
        obj["normparam"] = to_json(msg.normparam);
        obj["parameterparam"] = to_json(msg.parameterparam);
        obj["permuteparam"] = to_json(msg.permuteparam);
        obj["poolingparam"] = to_json(msg.poolingparam);
        obj["powerparam"] = to_json(msg.powerparam);
        obj["preluparam"] = to_json(msg.preluparam);
        obj["priorboxparam"] = to_json(msg.priorboxparam);
        obj["pythonparam"] = to_json(msg.pythonparam);
        obj["recurrentparam"] = to_json(msg.recurrentparam);
        obj["reductionparam"] = to_json(msg.reductionparam);
        obj["reluparam"] = to_json(msg.reluparam);
        obj["reshapeparam"] = to_json(msg.reshapeparam);
        obj["roipoolingparam"] = to_json(msg.roipoolingparam);
        obj["scaleparam"] = to_json(msg.scaleparam);
        obj["sigmoidparam"] = to_json(msg.sigmoidparam);
        obj["softmaxparam"] = to_json(msg.softmaxparam);
        obj["sppparam"] = to_json(msg.sppparam);
        obj["sliceparam"] = to_json(msg.sliceparam);
        obj["tanhparam"] = to_json(msg.tanhparam);
        obj["thresholdparam"] = to_json(msg.thresholdparam);
        obj["tileparam"] = to_json(msg.tileparam);
        obj["videodataparam"] = to_json(msg.videodataparam);
        obj["windowdataparam"] = to_json(msg.windowdataparam);
        return obj;
    }
    ApolloperceptioninferenceLayerParameter from_json_ApolloperceptioninferenceLayerParameter (nlohmann::json obj) {
        ApolloperceptioninferenceLayerParameter msg;
        if(obj.contains("name"))
        {
            msg.name = (obj["name"].is_string()?(obj["name"].get<std::string>().c_str()):obj["name"].get<std::string>());
        }
        if(obj.contains("type"))
        {
            msg.type = (obj["type"].is_string()?(obj["type"].get<std::string>().c_str()):obj["type"].get<std::string>());
        }
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
        if(obj.contains("phase"))
        {
            msg.phase = (obj["phase"].is_string()?atoi(obj["phase"].get<std::string>().c_str()):obj["phase"].get<int>());
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
        if(obj.contains("param"))
        {
            if(obj["param"].is_array())
            {
                for (auto& element : obj["param"])
                {
                    msg.param.push_back(from_json_ApolloperceptioninferenceParamSpec(element));
                }
            }
            else
            {
                msg.param.push_back(from_json_ApolloperceptioninferenceParamSpec(obj["param"]));
            }
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
        if(obj.contains("propagatedown"))
        {
            if(obj["propagatedown"].is_array())
            {
                for (auto& element : obj["propagatedown"])
                {
                    msg.propagatedown.push_back((element.is_string()?(bool)atoi(element.get<std::string>().c_str()):element.get<bool>()));
                }
            }
            else
            {
                msg.propagatedown.push_back((obj["propagatedown"].is_string()?(bool)atoi(obj["propagatedown"].get<std::string>().c_str()):obj["propagatedown"].get<bool>()));
            }
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
        if(obj.contains("transformparam"))
        {
            msg.transformparam = from_json_ApolloperceptioninferenceTransformationParameter(obj["transformparam"]);
        }
        if(obj.contains("lossparam"))
        {
            msg.lossparam = from_json_ApolloperceptioninferenceLossParameter(obj["lossparam"]);
        }
        if(obj.contains("accuracyparam"))
        {
            msg.accuracyparam = from_json_ApolloperceptioninferenceAccuracyParameter(obj["accuracyparam"]);
        }
        if(obj.contains("annotateddataparam"))
        {
            msg.annotateddataparam = from_json_ApolloperceptioninferenceAnnotatedDataParameter(obj["annotateddataparam"]);
        }
        if(obj.contains("argmaxparam"))
        {
            msg.argmaxparam = from_json_ApolloperceptioninferenceArgMaxParameter(obj["argmaxparam"]);
        }
        if(obj.contains("batchnormparam"))
        {
            msg.batchnormparam = from_json_ApolloperceptioninferenceBatchNormParameter(obj["batchnormparam"]);
        }
        if(obj.contains("bboxregparam"))
        {
            msg.bboxregparam = from_json_ApolloperceptioninferenceBBoxRegParameter(obj["bboxregparam"]);
        }
        if(obj.contains("biasparam"))
        {
            msg.biasparam = from_json_ApolloperceptioninferenceBiasParameter(obj["biasparam"]);
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
        if(obj.contains("cropparam"))
        {
            msg.cropparam = from_json_ApolloperceptioninferenceCropParameter(obj["cropparam"]);
        }
        if(obj.contains("dataparam"))
        {
            msg.dataparam = from_json_ApolloperceptioninferenceDataParameter(obj["dataparam"]);
        }
        if(obj.contains("detectionevaluateparam"))
        {
            msg.detectionevaluateparam = from_json_ApolloperceptioninferenceDetectionEvaluateParameter(obj["detectionevaluateparam"]);
        }
        if(obj.contains("detectionoutputparam"))
        {
            msg.detectionoutputparam = from_json_ApolloperceptioninferenceDetectionOutputParameter(obj["detectionoutputparam"]);
        }
        if(obj.contains("detectionoutputssdparam"))
        {
            msg.detectionoutputssdparam = from_json_ApolloperceptioninferenceDetectionOutputSSDParameter(obj["detectionoutputssdparam"]);
        }
        if(obj.contains("dfmbpsroipoolingparam"))
        {
            msg.dfmbpsroipoolingparam = from_json_ApolloperceptioninferenceDFMBPSROIAlignParameter(obj["dfmbpsroipoolingparam"]);
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
        if(obj.contains("eluparam"))
        {
            msg.eluparam = from_json_ApolloperceptioninferenceELUParameter(obj["eluparam"]);
        }
        if(obj.contains("embedparam"))
        {
            msg.embedparam = from_json_ApolloperceptioninferenceEmbedParameter(obj["embedparam"]);
        }
        if(obj.contains("expparam"))
        {
            msg.expparam = from_json_ApolloperceptioninferenceExpParameter(obj["expparam"]);
        }
        if(obj.contains("flattenparam"))
        {
            msg.flattenparam = from_json_ApolloperceptioninferenceFlattenParameter(obj["flattenparam"]);
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
        if(obj.contains("yolodataparam"))
        {
            if(obj["yolodataparam"].is_array())
            {
                for (auto& element : obj["yolodataparam"])
                {
                    msg.yolodataparam.push_back(from_json_ApolloperceptioninferenceImageDataParameter(element));
                }
            }
            else
            {
                msg.yolodataparam.push_back(from_json_ApolloperceptioninferenceImageDataParameter(obj["yolodataparam"]));
            }
        }
        if(obj.contains("dataprobparam"))
        {
            if(obj["dataprobparam"].is_array())
            {
                for (auto& element : obj["dataprobparam"])
                {
                    msg.dataprobparam.push_back((element.is_string()?(float)atof(element.get<std::string>().c_str()):element.get<float>()));
                }
            }
            else
            {
                msg.dataprobparam.push_back((obj["dataprobparam"].is_string()?(float)atof(obj["dataprobparam"].get<std::string>().c_str()):obj["dataprobparam"].get<float>()));
            }
        }
        if(obj.contains("infogainlossparam"))
        {
            msg.infogainlossparam = from_json_ApolloperceptioninferenceInfogainLossParameter(obj["infogainlossparam"]);
        }
        if(obj.contains("innerproductparam"))
        {
            msg.innerproductparam = from_json_ApolloperceptioninferenceInnerProductParameter(obj["innerproductparam"]);
        }
        if(obj.contains("inputparam"))
        {
            msg.inputparam = from_json_ApolloperceptioninferenceInputParameter(obj["inputparam"]);
        }
        if(obj.contains("logparam"))
        {
            msg.logparam = from_json_ApolloperceptioninferenceLogParameter(obj["logparam"]);
        }
        if(obj.contains("lrnparam"))
        {
            msg.lrnparam = from_json_ApolloperceptioninferenceLRNParameter(obj["lrnparam"]);
        }
        if(obj.contains("memorydataparam"))
        {
            msg.memorydataparam = from_json_ApolloperceptioninferenceMemoryDataParameter(obj["memorydataparam"]);
        }
        if(obj.contains("multiboxlossparam"))
        {
            msg.multiboxlossparam = from_json_ApolloperceptioninferenceMultiBoxLossParameter(obj["multiboxlossparam"]);
        }
        if(obj.contains("regionparam"))
        {
            msg.regionparam = from_json_ApolloperceptioninferenceRegionParameter(obj["regionparam"]);
        }
        if(obj.contains("regionoutputparam"))
        {
            msg.regionoutputparam = from_json_ApolloperceptioninferenceRegionOutputParameter(obj["regionoutputparam"]);
        }
        if(obj.contains("regionproposalparam"))
        {
            msg.regionproposalparam = from_json_ApolloperceptioninferenceRegionProposalParameter(obj["regionproposalparam"]);
        }
        if(obj.contains("yolotargetparam"))
        {
            msg.yolotargetparam = from_json_ApolloperceptioninferenceYoloTargetParameter(obj["yolotargetparam"]);
        }
        if(obj.contains("yoloanchorsparam"))
        {
            msg.yoloanchorsparam = from_json_ApolloperceptioninferenceYoloAnchorsParameter(obj["yoloanchorsparam"]);
        }
        if(obj.contains("yololossparam"))
        {
            msg.yololossparam = from_json_ApolloperceptioninferenceYoloLossParameter(obj["yololossparam"]);
        }
        if(obj.contains("yolodumpparam"))
        {
            msg.yolodumpparam = from_json_ApolloperceptioninferenceYoloDumpParameter(obj["yolodumpparam"]);
        }
        if(obj.contains("paddingparam"))
        {
            msg.paddingparam = from_json_ApolloperceptioninferencePaddingParameter(obj["paddingparam"]);
        }
        if(obj.contains("reorgparam"))
        {
            msg.reorgparam = from_json_ApolloperceptioninferenceReorgParameter(obj["reorgparam"]);
        }
        if(obj.contains("mvnparam"))
        {
            msg.mvnparam = from_json_ApolloperceptioninferenceMVNParameter(obj["mvnparam"]);
        }
        if(obj.contains("normparam"))
        {
            msg.normparam = from_json_ApolloperceptioninferenceNormalizeParameter(obj["normparam"]);
        }
        if(obj.contains("parameterparam"))
        {
            msg.parameterparam = from_json_ApolloperceptioninferenceParameterParameter(obj["parameterparam"]);
        }
        if(obj.contains("permuteparam"))
        {
            msg.permuteparam = from_json_ApolloperceptioninferencePermuteParameter(obj["permuteparam"]);
        }
        if(obj.contains("poolingparam"))
        {
            msg.poolingparam = from_json_ApolloperceptioninferencePoolingParameter(obj["poolingparam"]);
        }
        if(obj.contains("powerparam"))
        {
            msg.powerparam = from_json_ApolloperceptioninferencePowerParameter(obj["powerparam"]);
        }
        if(obj.contains("preluparam"))
        {
            msg.preluparam = from_json_ApolloperceptioninferencePReLUParameter(obj["preluparam"]);
        }
        if(obj.contains("priorboxparam"))
        {
            msg.priorboxparam = from_json_ApolloperceptioninferencePriorBoxParameter(obj["priorboxparam"]);
        }
        if(obj.contains("pythonparam"))
        {
            msg.pythonparam = from_json_ApolloperceptioninferencePythonParameter(obj["pythonparam"]);
        }
        if(obj.contains("recurrentparam"))
        {
            msg.recurrentparam = from_json_ApolloperceptioninferenceRecurrentParameter(obj["recurrentparam"]);
        }
        if(obj.contains("reductionparam"))
        {
            msg.reductionparam = from_json_ApolloperceptioninferenceReductionParameter(obj["reductionparam"]);
        }
        if(obj.contains("reluparam"))
        {
            msg.reluparam = from_json_ApolloperceptioninferenceReLUParameter(obj["reluparam"]);
        }
        if(obj.contains("reshapeparam"))
        {
            msg.reshapeparam = from_json_ApolloperceptioninferenceReshapeParameter(obj["reshapeparam"]);
        }
        if(obj.contains("roipoolingparam"))
        {
            msg.roipoolingparam = from_json_ApolloperceptioninferenceROIPoolingParameter(obj["roipoolingparam"]);
        }
        if(obj.contains("scaleparam"))
        {
            msg.scaleparam = from_json_ApolloperceptioninferenceScaleParameter(obj["scaleparam"]);
        }
        if(obj.contains("sigmoidparam"))
        {
            msg.sigmoidparam = from_json_ApolloperceptioninferenceSigmoidParameter(obj["sigmoidparam"]);
        }
        if(obj.contains("softmaxparam"))
        {
            msg.softmaxparam = from_json_ApolloperceptioninferenceSoftmaxParameter(obj["softmaxparam"]);
        }
        if(obj.contains("sppparam"))
        {
            msg.sppparam = from_json_ApolloperceptioninferenceSPPParameter(obj["sppparam"]);
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
        if(obj.contains("tileparam"))
        {
            msg.tileparam = from_json_ApolloperceptioninferenceTileParameter(obj["tileparam"]);
        }
        if(obj.contains("videodataparam"))
        {
            msg.videodataparam = from_json_ApolloperceptioninferenceVideoDataParameter(obj["videodataparam"]);
        }
        if(obj.contains("windowdataparam"))
        {
            msg.windowdataparam = from_json_ApolloperceptioninferenceWindowDataParameter(obj["windowdataparam"]);
        }
        return msg;
    }
    template <>
    ApolloperceptioninferenceLayerParameter from_json<ApolloperceptioninferenceLayerParameter>(nlohmann::json obj){
        return from_json_ApolloperceptioninferenceLayerParameter(obj);
    }
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceLayerParameter &dt)
    {
        dt=from_json_ApolloperceptioninferenceLayerParameter(os);
        return os;
    }
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceLayerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceLayerParameter & dt)
    {
        os << to_json(dt);
        return os;
    }
}
