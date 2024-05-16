#pragma once
#include "modules/common/proto/geometry.pb.h"
#include "apollo_msgs/msg/apollohdmap_polygon.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_polygon.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapPolygon Polygon;
}
#include "apollo_msgs/msg/apollohdmap_line_segment.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_line_segment.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapLineSegment LineSegment;
}
#include "apollo_msgs/msg/apollohdmap_curve_segment.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_curve_segment.hpp"
#include "apollo_msgs/msg/apollohdmap_curve.hpp"
#include "adapter/serialization/apollo_msgs/apollohdmap_curve.hpp"
namespace apollo::hdmap{
	typedef apollo_msgs::msg::ApollohdmapCurve Curve;
}