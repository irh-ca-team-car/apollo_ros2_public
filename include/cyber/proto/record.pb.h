#pragma once

namespace apollo::cyber::proto{
	enum SectionType {
		SECTION_HEADER = 0,
		SECTION_CHUNK_HEADER = 1,
		SECTION_CHUNK_BODY = 2,
		SECTION_INDEX = 3,
		SECTION_CHANNEL = 4
	};
}
namespace apollo::cyber::proto{
	enum CompressType {
		COMPRESS_NONE = 0,
		COMPRESS_BZ2 = 1,
		COMPRESS_LZ4 = 2
	};
}