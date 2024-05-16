#pragma once
#include "apollo_msgs/msg/apolloperceptioninference_v1_layer_parameter.hpp"
#include "rclcpp/rclcpp.hpp"
#include "nlohmann/json.hpp"
#include "cyber/common/log.h"
#include "adapter/serialization/std_msgs/header.hpp"
#include <string>
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_net_state_rule.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_blob_proto.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_accuracy_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_arg_max_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_concat_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_contrastive_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_convolution_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dropout_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_dummy_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_eltwise_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_exp_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hdf5_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hdf5_output_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_hinge_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_image_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_infogain_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_inner_product_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_lrn_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_memory_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_mvn_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_pooling_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_power_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_re_lu_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_sigmoid_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_softmax_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_slice_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_tan_h_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_threshold_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_window_data_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_transformation_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_loss_parameter.hpp"
#include "adapter/serialization/apollo_msgs/apolloperceptioninference_v0_layer_parameter.hpp"
namespace apollo_msgs::msg {
    nlohmann::json to_json (const ApolloperceptioninferenceV1LayerParameter &msg) ;
    ApolloperceptioninferenceV1LayerParameter from_json_ApolloperceptioninferenceV1LayerParameter (nlohmann::json obj) ;
    template <>
    ApolloperceptioninferenceV1LayerParameter from_json<ApolloperceptioninferenceV1LayerParameter>(nlohmann::json obj);
    nlohmann::json &operator>>(nlohmann::json &os, ApolloperceptioninferenceV1LayerParameter &dt);
    std::ostream & operator<<(std::ostream & os, const ApolloperceptioninferenceV1LayerParameter & dt);
    close_after_if_not_null & operator<<(close_after_if_not_null & os, const ApolloperceptioninferenceV1LayerParameter & dt);
}
