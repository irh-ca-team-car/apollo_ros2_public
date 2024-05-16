#pragma once
#include "apollo_msgs/msg/apollodriversgnssconfig_stream_serial.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream_serial.hpp"
namespace apollo::drivers::gnss::config::Stream{
	typedef apollo_msgs::msg::ApollodriversgnssconfigStreamSerial Serial;
}
#include "apollo_msgs/msg/apollodriversgnssconfig_stream_tcp.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream_tcp.hpp"
namespace apollo::drivers::gnss::config::Stream{
	typedef apollo_msgs::msg::ApollodriversgnssconfigStreamTcp Tcp;
}
#include "apollo_msgs/msg/apollodriversgnssconfig_stream_udp.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream_udp.hpp"
namespace apollo::drivers::gnss::config::Stream{
	typedef apollo_msgs::msg::ApollodriversgnssconfigStreamUdp Udp;
}
#include "apollo_msgs/msg/apollodriversgnssconfig_stream_ntrip.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream_ntrip.hpp"
namespace apollo::drivers::gnss::config::Stream{
	typedef apollo_msgs::msg::ApollodriversgnssconfigStreamNtrip Ntrip;
}
#include "apollo_msgs/msg/apollodriversgnssconfig_stream.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_stream.hpp"
#include "apollo_msgs/msg/apollodriversgnssconfig_novatel_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_novatel_config.hpp"
namespace apollo::drivers::gnss::config{
	typedef apollo_msgs::msg::ApollodriversgnssconfigNovatelConfig NovatelConfig;
}
#include "apollo_msgs/msg/apollodriversgnssconfig_tf.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_tf.hpp"
namespace apollo::drivers::gnss::config{
	typedef apollo_msgs::msg::ApollodriversgnssconfigTF TF;
}
#include "apollo_msgs/msg/apollodriversgnssconfig_config.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnssconfig_config.hpp"
namespace apollo::drivers::gnss::config::Stream{
	enum Format {
		UNKNOWN = 0,
		NMEA = 1,
		RTCM_V2 = 2,
		RTCM_V3 = 3,
		
		NOVATEL_TEXT = 10,
		NOVATEL_BINARY = 11,
		
		UBLOX_TEXT = 20,
		UBLOX_BINARY = 21
	};
}
namespace apollo::drivers::gnss::config{
	enum ImuType {
		// We currently use the following IMUs. We'll extend this list when a new IMU
		// is introduced.
		IMAR_FSAS = 13,      // iMAR iIMU-FSAS
		ISA100C = 26,        // Northrop Grumman Litef ISA-100C
		ADIS16488 = 31,      // Analog Devices ADIS16488
		STIM300 = 32,        // Sensonor STIM300
		ISA100 = 34,         // Northrop Grumman Litef ISA-100
		ISA100_400HZ = 38,   // Northrop Grumman Litef ISA-100
		ISA100C_400HZ = 39,  // Northrop Grumman Litef ISA-100
		CPT_XW5651 = 40,     // IMU@SPAN-CPT, and XingWangYuda 5651
		G320N = 41,          // EPSON G320N
		UM442 = 42,          // UM442
		IAM20680 = 57       // InvenSense-IAM20680
	};
}
namespace apollo::drivers::gnss::config::Config{
	enum RtkSolutionType {
		RTK_RECEIVER_SOLUTION = 1,
		RTK_SOFTWARE_SOLUTION = 2
	};
}