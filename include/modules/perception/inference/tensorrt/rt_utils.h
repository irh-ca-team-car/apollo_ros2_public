/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#pragma once

#include <string>

#include "google/protobuf/io/zero_copy_stream_impl.h"
#include "google/protobuf/text_format.h"
#include "cyber/common/file.h"
#include "modules/perception/proto/rt.pb.h"

namespace apollo {
namespace perception {
namespace inference {
    template <typename T>
    bool ReadProtoFromFile(const std::string &filename,
                               T *proto)
    {
        return apollo::cyber::common::GetProtoFromFile(filename, proto);
    }
    template <typename T>
    bool ReadProtoFromTextFile(const std::string &filename,
                               T *proto)
    {
        return apollo::cyber::common::GetProtoFromASCIIFile(filename, proto);
    }
    template <typename T>
    bool ReadProtoFromBinaryFile(const std::string &filename,
                                 T *proto)
    {
        return apollo::cyber::common::GetProtoFromBinaryFile(filename, proto);
    }

bool loadNetParams(const std::string &param_file, NetParameter *param);
std::string locateFile(const std::string &path, const std::string &input);

}  // namespace inference
}  // namespace perception
}  // namespace apollo
