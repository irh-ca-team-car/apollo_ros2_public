#pragma once
#include "modules/map/tools/map_datachecker/proto/collection_error_code.pb.h"
#include "apollo_msgs/msg/apollohdmap_verify_range.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_verify_range.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapVerifyRange VerifyRange;
}
#include "apollo_msgs/msg/apollohdmap_loop_result.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_loop_result.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapLoopResult LoopResult;
}
#include "apollo_msgs/msg/apollohdmap_topic_result.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_topic_result.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapTopicResult TopicResult;
}
#include "apollo_msgs/msg/apollohdmap_frame_rate.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_frame_rate.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapFrameRate FrameRate;
}
#include "apollo_msgs/msg/apollohdmap_verify_result.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_verify_result.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapVerifyResult VerifyResult;
}
#include "apollo_msgs/msg/apollohdmap_channel_verify_request.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_channel_verify_request.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapChannelVerifyRequest ChannelVerifyRequest;
}
#include "apollo_msgs/msg/apollohdmap_channel_verify_response.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_channel_verify_response.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapChannelVerifyResponse ChannelVerifyResponse;
}
#include "apollo_msgs/msg/apollohdmap_loops_verify_request.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_loops_verify_request.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapLoopsVerifyRequest LoopsVerifyRequest;
}
#include "apollo_msgs/msg/apollohdmap_loops_verify_response.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_loops_verify_response.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapLoopsVerifyResponse LoopsVerifyResponse;
}
#include "apollo_msgs/msg/apollohdmap_dynamic_align_request.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_dynamic_align_request.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapDynamicAlignRequest DynamicAlignRequest;
}
#include "apollo_msgs/msg/apollohdmap_dynamic_align_response.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_dynamic_align_response.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapDynamicAlignResponse DynamicAlignResponse;
}
#include "apollo_msgs/msg/apollohdmap_static_align_request.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_static_align_request.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapStaticAlignRequest StaticAlignRequest;
}
#include "apollo_msgs/msg/apollohdmap_static_align_response.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_static_align_response.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapStaticAlignResponse StaticAlignResponse;
}
#include "apollo_msgs/msg/apollohdmap_eight_route_request.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_eight_route_request.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapEightRouteRequest EightRouteRequest;
}
#include "apollo_msgs/msg/apollohdmap_eight_route_response.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_eight_route_response.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapEightRouteResponse EightRouteResponse;
}
namespace apollo::hdmap{
	enum CmdType {
		START = 1,
		CHECK = 2,
		STOP = 3
	};
}
namespace apollo::hdmap{
	enum DataType {
		MAP_MAKING = 1,
		MAP_CHECKOUT = 2
	};
}