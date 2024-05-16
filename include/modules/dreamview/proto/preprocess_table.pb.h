#pragma once
#include "apollo_msgs/msg/apollodreamview_translation.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_translation.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewTranslation Translation;
}
#include "apollo_msgs/msg/apollodreamview_lidar_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_lidar_config.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewLidarConfig LidarConfig;
}
#include "apollo_msgs/msg/apollodreamview_camera_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_camera_config.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewCameraConfig CameraConfig;
}
#include "apollo_msgs/msg/apollodreamview_progress.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_progress.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewProgress Progress;
}
#include "apollo_msgs/msg/apollodreamview_preprocess_table.hpp"
#include "adapter/serialization/apollo_msgs/apollodreamview_preprocess_table.hpp"
namespace apollo::dreamview{
	typedef apollo_msgs::msg::ApollodreamviewPreprocessTable PreprocessTable;
}
namespace apollo::dreamview{
	enum Status {
		SUCCESS = 0,
		FAIL = 1,
		UNKNOWN = 2
	};
}