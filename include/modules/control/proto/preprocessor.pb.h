#pragma once
#include "modules/common/proto/header.pb.h"
#include "modules/common/proto/drive_state.pb.h"
#include "modules/control/proto/input_debug.pb.h"
#include "modules/control/proto/local_view.pb.h"
#include "apollo_msgs/msg/apollocontrol_preprocessor.hpp"
#include "adapter/serialization/apollo_msgs/apollocontrol_preprocessor.hpp"
namespace apollo::control{
	typedef apollo_msgs::msg::ApollocontrolPreprocessor Preprocessor;
}