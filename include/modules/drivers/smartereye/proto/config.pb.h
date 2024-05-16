#pragma once
#include "apollo_msgs/msg/apollodriverssmartereyeconfig_config_compress_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriverssmartereyeconfig_config_compress_config.hpp"
namespace apollo::drivers::smartereye::config::Config{
	typedef apollo_msgs::msg::ApollodriverssmartereyeconfigConfigCompressConfig CompressConfig;
}
#include "apollo_msgs/msg/apollodriverssmartereyeconfig_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriverssmartereyeconfig_config.hpp"
namespace apollo::drivers::smartereye::config{
	enum IOMethod {
		IO_METHOD_UNKNOWN = 0,
		IO_METHOD_READ = 1,
		IO_METHOD_MMAP = 2,
		IO_METHOD_USERPTR = 3
	};
}
namespace apollo::drivers::smartereye::config{
	enum OutputType {
		YUYV = 0,
		RGB = 1
	};
}