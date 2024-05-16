#pragma once
#include "apollo_msgs/msg/apollocommon_point_enu.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point_enu.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonPointENU PointENU;
}
#include "apollo_msgs/msg/apollocommon_point_llh.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point_llh.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonPointLLH PointLLH;
}
#include "apollo_msgs/msg/apollocommon_point2_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point2_d.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonPoint2D Point2D;
}
#include "apollo_msgs/msg/apollocommon_point3_d.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_point3_d.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonPoint3D Point3D;
}
#include "apollo_msgs/msg/apollocommon_quaternion.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_quaternion.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonQuaternion Quaternion;
}
#include "apollo_msgs/msg/apollocommon_polygon.hpp"
#include "adapter/serialization/apollo_msgs/apollocommon_polygon.hpp"
namespace apollo::common{
	typedef apollo_msgs::msg::ApollocommonPolygon Polygon;
}