#pragma once
#include <type_traits>

#include "cyber/common/log.h"
#include "cyber/common/file.h"
#include "cyber/common/macros.h"

#include "cyber/component.h"
#include "cyber/writer.h"
#include "cyber/reader.h"
#include "cyber/io_internal.h"
#include "cyber/adapter.h"
#include "cyber/time/time.h"
#include "cyber/time/clock.h"
#ifndef NVVC
#include <filesystem>
#endif
namespace apollo
{
    namespace cyber
    {
        bool IsShutdown();
        bool OK();
        std::shared_ptr<NIComponent> CreateNode(std::string name);
    } // namespace cyber
} // namespace apollo
