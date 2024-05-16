#pragma once
#include "modules/common/proto/pnc_point.pb.h"
#include "modules/prediction/proto/feature.pb.h"
#include "modules/prediction/proto/prediction_conf.pb.h"
#include "modules/prediction/proto/scenario.pb.h"
#include "apollo_msgs/msg/apolloprediction_data_for_learning.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_data_for_learning.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionDataForLearning DataForLearning;
}
#include "apollo_msgs/msg/apolloprediction_list_data_for_learning.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_list_data_for_learning.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionListDataForLearning ListDataForLearning;
}
#include "apollo_msgs/msg/apolloprediction_prediction_result.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_prediction_result.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionPredictionResult PredictionResult;
}
#include "apollo_msgs/msg/apolloprediction_list_prediction_result.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_list_prediction_result.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionListPredictionResult ListPredictionResult;
}
#include "apollo_msgs/msg/apolloprediction_list_frame_env.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_list_frame_env.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionListFrameEnv ListFrameEnv;
}
#include "apollo_msgs/msg/apolloprediction_data_for_tuning.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_data_for_tuning.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionDataForTuning DataForTuning;
}
#include "apollo_msgs/msg/apolloprediction_list_data_for_tuning.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_list_data_for_tuning.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionListDataForTuning ListDataForTuning;
}
#include "apollo_msgs/msg/apolloprediction_features.hpp"
#include "adapter/serialization/apollo_msgs/apolloprediction_features.hpp"
namespace apollo::prediction{
	typedef apollo_msgs::msg::ApollopredictionFeatures Features;
}