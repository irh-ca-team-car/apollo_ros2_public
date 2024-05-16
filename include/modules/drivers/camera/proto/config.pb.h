#pragma once
#include "apollo_msgs/msg/apollodriverscameraconfig_config_compress_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriverscameraconfig_config_compress_config.hpp"
namespace apollo::drivers::camera::config::Config{
	typedef apollo_msgs::msg::ApollodriverscameraconfigConfigCompressConfig CompressConfig;
}
#include "apollo_msgs/msg/apollodriverscameraconfig_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriverscameraconfig_config.hpp"
namespace apollo::drivers::camera::config{
	enum IOMethod {
		IO_METHOD_UNKNOWN = 0,
		IO_METHOD_READ = 1,
		IO_METHOD_MMAP = 2,
		IO_METHOD_USERPTR = 3
	};
}
namespace apollo::drivers::camera::config{
	enum OutputType {
		YUYV = 0,
		RGB = 1
	};
}