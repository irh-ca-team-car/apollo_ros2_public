#pragma once
#include "apollo_msgs/msg/apollodriversgnss_band_observation.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_band_observation.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssBandObservation BandObservation;
}
#include "apollo_msgs/msg/apollodriversgnss_satellite_observation.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_satellite_observation.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssSatelliteObservation SatelliteObservation;
}
#include "apollo_msgs/msg/apollodriversgnss_epoch_observation.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_epoch_observation.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssEpochObservation EpochObservation;
}
#include "apollo_msgs/msg/apollodriversgnss_keppler_orbit.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_keppler_orbit.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssKepplerOrbit KepplerOrbit;
}
#include "apollo_msgs/msg/apollodriversgnss_glonass_orbit.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_glonass_orbit.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssGlonassOrbit GlonassOrbit;
}
#include "apollo_msgs/msg/apollodriversgnss_gnss_ephemeris.hpp"
#include "adapter/serialization/apollo_msgs/apollodriversgnss_gnss_ephemeris.hpp"
namespace apollo::drivers::gnss{
	typedef apollo_msgs::msg::ApollodriversgnssGnssEphemeris GnssEphemeris;
}
namespace apollo::drivers::gnss{
	enum GnssBandID {
		BAND_UNKNOWN = 0,
		GPS_L1 = 1,
		GPS_L2 = 2,
		GPS_L5 = 3,
		BDS_B1 = 4,
		BDS_B2 = 5,
		BDS_B3 = 6,
		GLO_G1 = 7,
		GLO_G2 = 8,
		GLO_G3 = 9
	};
}
namespace apollo::drivers::gnss{
	enum GnssTimeType {
		TIME_UNKNOWN = 0,
		GPS_TIME = 1,
		BDS_TIME = 2,
		GLO_TIME = 3,
		GAL_TIME = 4
	};
}
namespace apollo::drivers::gnss{
	enum GnssType {
		SYS_UNKNOWN = 0,
		GPS_SYS = 1,
		BDS_SYS = 2,
		GLO_SYS = 3,
		GAL_SYS = 4
	};
}
namespace apollo::drivers::gnss{
	enum PseudoType {
		CODE_UNKNOWN = 0,
		CORSE_CODE = 1,
		PRECISION_CODE = 2
	};
}