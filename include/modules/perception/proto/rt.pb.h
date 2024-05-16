#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_blob_shape.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_shape.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceBlobShape BlobShape;
}
#include "apollo_msgs/msg/apolloperceptioninference_blob_proto.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_proto.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceBlobProto BlobProto;
}
#include "apollo_msgs/msg/apolloperceptioninference_datum.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_datum.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceDatum Datum;
}
#include "apollo_msgs/msg/apolloperceptioninference_label_map_item.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_label_map_item.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceLabelMapItem LabelMapItem;
}
#include "apollo_msgs/msg/apolloperceptioninference_label_map.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_label_map.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceLabelMap LabelMap;
}
#include "apollo_msgs/msg/apolloperceptioninference_sampler.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_sampler.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceSampler Sampler;
}
#include "apollo_msgs/msg/apolloperceptioninference_sample_constraint.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_sample_constraint.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceSampleConstraint SampleConstraint;
}
#include "apollo_msgs/msg/apolloperceptioninference_batch_sampler.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_batch_sampler.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceBatchSampler BatchSampler;
}
#include "apollo_msgs/msg/apolloperceptioninference_emit_constraint.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_emit_constraint.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_normalized_b_box.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_normalized_b_box.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceNormalizedBBox NormalizedBBox;
}
#include "apollo_msgs/msg/apolloperceptioninference_b_box3_d.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_b_box3_d.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceBBox3D BBox3D;
}
#include "apollo_msgs/msg/apolloperceptioninference_annotation.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotation.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceAnnotation Annotation;
}
#include "apollo_msgs/msg/apolloperceptioninference_annotation_group.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotation_group.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceAnnotationGroup AnnotationGroup;
}
#include "apollo_msgs/msg/apolloperceptioninference_annotated_datum.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotated_datum.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_filler_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_filler_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_net_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_net_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceNetParameter NetParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_net_state.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_net_state.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceNetState NetState;
}
#include "apollo_msgs/msg/apolloperceptioninference_net_state_rule.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_net_state_rule.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceNetStateRule NetStateRule;
}
#include "apollo_msgs/msg/apolloperceptioninference_param_spec.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_param_spec.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_layer_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_layer_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceLayerParameter LayerParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_transformation_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_transformation_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceTransformationParameter TransformationParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_resize_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_resize_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_salt_pepper_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_salt_pepper_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceSaltPepperParameter SaltPepperParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_noise_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_noise_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceNoiseParameter NoiseParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_distortion_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_distortion_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceDistortionParameter DistortionParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_expansion_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_expansion_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceExpansionParameter ExpansionParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_loss_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_accuracy_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_accuracy_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceAccuracyParameter AccuracyParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_annotated_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_annotated_data_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceAnnotatedDataParameter AnnotatedDataParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_arg_max_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_arg_max_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceArgMaxParameter ArgMaxParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_concat_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_concat_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceConcatParameter ConcatParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_batch_norm_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_batch_norm_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceBatchNormParameter BatchNormParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_bias_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_bias_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceBiasParameter BiasParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_contrastive_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_contrastive_loss_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceContrastiveLossParameter ContrastiveLossParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_convolution_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_convolution_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_crop_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_crop_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceCropParameter CropParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_data_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_detection_evaluate_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_detection_evaluate_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceDetectionEvaluateParameter DetectionEvaluateParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_non_maximum_suppression_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_non_maximum_suppression_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceNonMaximumSuppressionParameter NonMaximumSuppressionParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_save_output_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_save_output_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceSaveOutputParameter SaveOutputParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_detection_output_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_detection_output_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceDetectionOutputParameter DetectionOutputParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_region_output_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_region_output_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceRegionOutputParameter RegionOutputParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_dropout_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dropout_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceDropoutParameter DropoutParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_dummy_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dummy_data_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceDummyDataParameter DummyDataParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_eltwise_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_eltwise_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_elu_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_elu_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceELUParameter ELUParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_embed_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_embed_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceEmbedParameter EmbedParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_exp_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_exp_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceExpParameter ExpParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_flatten_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_flatten_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceFlattenParameter FlattenParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_hdf5_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hdf5_data_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceHDF5DataParameter HDF5DataParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_hdf5_output_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hdf5_output_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceHDF5OutputParameter HDF5OutputParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_hinge_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hinge_loss_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_repeated_list.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_repeated_list.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceRepeatedList RepeatedList;
}
#include "apollo_msgs/msg/apolloperceptioninference_dataset_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dataset_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_image_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_image_data_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceImageDataParameter ImageDataParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_infogain_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_infogain_loss_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceInfogainLossParameter InfogainLossParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_inner_product_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_inner_product_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceInnerProductParameter InnerProductParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_input_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_input_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceInputParameter InputParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_log_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_log_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceLogParameter LogParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_lrn_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_lrn_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_memory_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_memory_data_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceMemoryDataParameter MemoryDataParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_multi_box_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_multi_box_loss_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_mvn_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_mvn_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceMVNParameter MVNParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_normalize_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_normalize_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceNormalizeParameter NormalizeParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_parameter_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_parameter_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceParameterParameter ParameterParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_permute_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_permute_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferencePermuteParameter PermuteParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_pooling_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_pooling_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_power_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_power_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferencePowerParameter PowerParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_prior_box_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_prior_box_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_python_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_python_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferencePythonParameter PythonParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_recurrent_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_recurrent_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceRecurrentParameter RecurrentParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_reduction_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_reduction_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_re_lu_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_re_lu_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_reshape_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_reshape_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceReshapeParameter ReshapeParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_roi_pooling_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_roi_pooling_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceROIPoolingParameter ROIPoolingParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_scale_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_scale_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceScaleParameter ScaleParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_sigmoid_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_sigmoid_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_slice_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_slice_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceSliceParameter SliceParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_softmax_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_softmax_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_tan_h_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_tan_h_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_tile_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_tile_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceTileParameter TileParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_threshold_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_threshold_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceThresholdParameter ThresholdParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_video_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_video_data_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_window_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_window_data_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceWindowDataParameter WindowDataParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_spp_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_spp_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_v1_layer_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_v1_layer_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_v0_layer_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_v0_layer_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_p_re_lu_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_p_re_lu_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferencePReLUParameter PReLUParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_padding_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_padding_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferencePaddingParameter PaddingParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_yolo_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_loss_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_yolo_dump_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_dump_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceYoloDumpParameter YoloDumpParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_yolo_anchors_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_anchors_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceYoloAnchorsParameter YoloAnchorsParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_dimension_statistics.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dimension_statistics.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceDimensionStatistics DimensionStatistics;
}
#include "apollo_msgs/msg/apolloperceptioninference_yolo_target_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_yolo_target_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceYoloTargetParameter YoloTargetParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_region_proposal_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_region_proposal_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceRegionProposalParameter RegionProposalParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_region_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_region_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceRegionParameter RegionParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_anchor_box.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_anchor_box.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceAnchorBox AnchorBox;
}
#include "apollo_msgs/msg/apolloperceptioninference_reorg_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_reorg_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceReorgParameter ReorgParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_b_box_reg_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_b_box_reg_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceBBoxRegParameter BBoxRegParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_dfmbpsroi_align_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dfmbpsroi_align_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceDFMBPSROIAlignParameter DFMBPSROIAlignParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_detection_output_ssd_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_detection_output_ssd_parameter.hpp"
#include "apollo_msgs/msg/apolloperceptioninference_nmsssd_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_nmsssd_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceNMSSSDParameter NMSSSDParameter;
}
#include "apollo_msgs/msg/apolloperceptioninference_gen_anchor_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_gen_anchor_parameter.hpp"
namespace apollo::perception::inference{
	typedef apollo_msgs::msg::ApolloperceptioninferenceGenAnchorParameter GenAnchorParameter;
}
namespace apollo::perception::inference::EmitConstraint{
	enum EmitType {
		CENTER = 0,
		MIN_OVERLAP = 1
	};
}
namespace apollo::perception::inference::AnnotatedDatum{
	enum AnnotationType {
		BBOX = 0,      // normal 2D bbox
		BBOX3D = 1,    // BBOX with 3D info
		BBOX3DFR = 2  // BBOX3D with front & rear 2D bbox
	};
}
namespace apollo::perception::inference::FillerParameter{
	enum VarianceNorm {
		FAN_IN = 0,
		FAN_OUT = 1,
		AVERAGE = 2
	};
}
namespace apollo::perception::inference{
	enum Phase {
		TRAIN = 0,
		TEST = 1
	};
}
namespace apollo::perception::inference::ParamSpec{
	enum DimCheckMode {
		// STRICT (default) requires that num, channels, height, width each match.
		STRICT = 0,
		// PERMISSIVE requires only the count (num*channels*height*width) to match.
		PERMISSIVE = 1
	};
}
namespace apollo::perception::inference::ResizeParameter{
	enum Resize_mode {
		WARP = 1,
		FIT_SMALL_SIZE = 2,
		FIT_LARGE_SIZE_AND_PAD = 3
	};
}
namespace apollo::perception::inference::ResizeParameter{
	enum Pad_mode {
		CONSTANT = 1,
		MIRRORED = 2,
		REPEAT_NEAREST = 3
	};
}
namespace apollo::perception::inference::ResizeParameter{
	enum Interp_mode {
		LINEAR = 1,
		AREA = 2,
		NEAREST = 3,
		CUBIC = 4,
		LANCZOS4 = 5
	};
}
namespace apollo::perception::inference::LossParameter{
	enum NormalizationMode {
		// Divide by the number of examples in the batch times spatial dimensions.
		// Outputs that receive the ignore label will NOT be ignored in computing
		// the normalization factor.
		FULL = 0,
		// Divide by the total number of output locations that do not take the
		// ignore_label.  If ignore_label is not set, this behaves like FULL.
		VALID = 1,
		// Divide by the batch size.
		BATCH_SIZE = 2,
		// Do not normalize the loss.
		NONE = 3
	};
}
namespace apollo::perception::inference::ConvolutionParameter{
	enum Engine {
		DEFAULT = 0,
		CAFFE = 1,
		CUDNN = 2
	};
}
namespace apollo::perception::inference::DataParameter{
	enum DB {
		LEVELDB = 0,
		LMDB = 1
	};
}
namespace apollo::perception::inference::EltwiseParameter{
	enum EltwiseOp {
		PROD = 0,
		SUM = 1,
		MAX = 2
	};
}
namespace apollo::perception::inference::HingeLossParameter{
	enum Norm {
		L1 = 1,
		L2 = 2
	};
}
namespace apollo::perception::inference::DatasetParameter{
	enum DatasetType {
		LIST = 1,   // list of paired image and label paths
		BLOCK = 2  // list of paired image and label block paths
	};
}
namespace apollo::perception::inference::LRNParameter{
	enum NormRegion {
		ACROSS_CHANNELS = 0,
		WITHIN_CHANNEL = 1
	};
}
namespace apollo::perception::inference::LRNParameter{
	enum Engine {
		DEFAULT = 0,
		CAFFE = 1,
		CUDNN = 2
	};
}
namespace apollo::perception::inference::MultiBoxLossParameter{
	enum LocLossType {
		L2 = 0,
		SMOOTH_L1 = 1
	};
}
namespace apollo::perception::inference::MultiBoxLossParameter{
	enum ConfLossType {
		SOFTMAX = 0,
		LOGISTIC = 1
	};
}
namespace apollo::perception::inference::MultiBoxLossParameter{
	enum MatchType {
		BIPARTITE = 0,
		PER_PREDICTION = 1
	};
}
namespace apollo::perception::inference::MultiBoxLossParameter{
	enum MiningType {
		NONE = 0,
		MAX_NEGATIVE = 1,
		HARD_EXAMPLE = 2
	};
}
namespace apollo::perception::inference::PoolingParameter{
	enum PoolMethod {
		MAX = 0,
		AVE = 1,
		STOCHASTIC = 2
	};
}
namespace apollo::perception::inference::PoolingParameter{
	enum Engine {
		DEFAULT = 0,
		CAFFE = 1,
		CUDNN = 2
	};
}
namespace apollo::perception::inference::PoolingParameter{
	enum RoundMode {
		CEIL = 0,
		FLOOR = 1
	};
}
namespace apollo::perception::inference::PriorBoxParameter{
	enum CodeType {
		CORNER = 1,
		CENTER_SIZE = 2,
		CORNER_SIZE = 3
	};
}
namespace apollo::perception::inference::ReductionParameter{
	enum ReductionOp {
		SUM = 1,
		ASUM = 2,
		SUMSQ = 3,
		MEAN = 4
	};
}
namespace apollo::perception::inference::ReLUParameter{
	enum Engine {
		DEFAULT = 0,
		CAFFE = 1,
		CUDNN = 2
	};
}
namespace apollo::perception::inference::SigmoidParameter{
	enum Engine {
		DEFAULT = 0,
		CAFFE = 1,
		CUDNN = 2
	};
}
namespace apollo::perception::inference::SoftmaxParameter{
	enum Engine {
		DEFAULT = 0,
		CAFFE = 1,
		CUDNN = 2
	};
}
namespace apollo::perception::inference::TanHParameter{
	enum Engine {
		DEFAULT = 0,
		CAFFE = 1,
		CUDNN = 2
	};
}
namespace apollo::perception::inference::VideoDataParameter{
	enum VideoType {
		WEBCAM = 0,
		VIDEO = 1
	};
}
namespace apollo::perception::inference::SPPParameter{
	enum PoolMethod {
		MAX = 0,
		AVE = 1,
		STOCHASTIC = 2
	};
}
namespace apollo::perception::inference::SPPParameter{
	enum Engine {
		DEFAULT = 0,
		CAFFE = 1,
		CUDNN = 2
	};
}
namespace apollo::perception::inference::V1LayerParameter{
	enum LayerType {
		NONE = 0,
		ABSVAL = 35,
		ACCURACY = 1,
		ARGMAX = 30,
		BNLL = 2,
		CONCAT = 3,
		CONTRASTIVE_LOSS = 37,
		CONVOLUTION = 4,
		DATA = 5,
		DECONVOLUTION = 39,
		DROPOUT = 6,
		DUMMY_DATA = 32,
		EUCLIDEAN_LOSS = 7,
		ELTWISE = 25,
		EXP = 38,
		FLATTEN = 8,
		HDF5_DATA = 9,
		HDF5_OUTPUT = 10,
		HINGE_LOSS = 28,
		IM2COL = 11,
		IMAGE_DATA = 12,
		INFOGAIN_LOSS = 13,
		INNER_PRODUCT = 14,
		LRN = 15,
		MEMORY_DATA = 29,
		MULTINOMIAL_LOGISTIC_LOSS = 16,
		MVN = 34,
		POOLING = 17,
		POWER = 26,
		RELU = 18,
		SIGMOID = 19,
		SIGMOID_CROSS_ENTROPY_LOSS = 27,
		SILENCE = 36,
		SOFTMAX = 20,
		SOFTMAX_LOSS = 21,
		SPLIT = 22,
		SLICE = 33,
		TANH = 23,
		WINDOW_DATA = 24,
		THRESHOLD = 31
	};
}
namespace apollo::perception::inference::V1LayerParameter{
	enum DimCheckMode {
		STRICT = 0,
		PERMISSIVE = 1
	};
}
namespace apollo::perception::inference::V0LayerParameter{
	enum PoolMethod {
		MAX = 0,
		AVE = 1,
		STOCHASTIC = 2
	};
}
namespace apollo::perception::inference::YoloLossParameter{
	enum RegLossType {
		L2 = 0,
		L1 = 1,
		SMOOTH_L1 = 2
	};
}
namespace apollo::perception::inference::DetectionOutputSSDParameter{
	enum MIN_SIZE_MODE {
		HEIGHT_AND_WIDTH = 0,
		HEIGHT_OR_WIDTH = 1
	};
}