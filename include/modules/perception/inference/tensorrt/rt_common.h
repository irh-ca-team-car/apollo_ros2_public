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

#include <cudnn.h>
#include <map>
#include <string>
#include <vector>

#include "NvCaffeParser.h"
#include "NvInfer.h"

#ifndef NVVC
#include "cyber/cyber.h"
#include "modules/perception/proto/rt.pb.h"
#else
#include "cyber/common/log.h"
#include "cyber/common/macros.h"
#endif
#include "modules/perception/base/common.h"
namespace apollo
{
  namespace perception
  {
    namespace inference
    {
      class DimsCHW : public nvinfer1::Dims3
      {
      public:
        //!
        //! \brief Construct an empty DimsCHW object.
        //!
        DimsCHW()
            : nvinfer1::Dims3()
        {
        }

        //!
        //! \brief Construct a DimsCHW given channel count, height and width.
        //!
        //! \param channels The channel count.
        //! \param height The height of the data.
        //! \param width The width of the data.
        //!
        DimsCHW(int channels, int height, int width)
            : nvinfer1::Dims3(channels, height, width)
        {
        }

        //!
        //! \brief Get the channel count.
        //!
        //! \return The channel count.
        //!
        int &c() { return d[0]; }

        //!
        //! \brief Get the channel count.
        //!
        //! \return The channel count.
        //!
        int c() const { return d[0]; }

        //!
        //! \brief Get the height.
        //!
        //! \return The height.
        //!
        int &h() { return d[1]; }

        //!
        //! \brief Get the height.
        //!
        //! \return The height.
        //!
        int h() const { return d[1]; }

        //!
        //! \brief Get the width.
        //!
        //! \return The width.
        //!
        int &w() { return d[2]; }

        //!
        //! \brief Get the width.
        //!
        //! \return The width.
        //!
        int w() const { return d[2]; }
      };

      typedef std::map<std::string, std::vector<nvinfer1::Weights>> WeightMap;
      typedef std::map<std::string, nvinfer1::ITensor *> TensorMap;
      typedef std::map<std::string, apollo::perception::inference::DimsCHW> TensorDimsMap;

      apollo::perception::inference::DimsCHW ReshapeDims(const apollo::perception::inference::DimsCHW &dims,
                                                         const apollo::perception::inference::DimsCHW &inputDims);
#ifndef NVVC

      void ParseNetParam(const NetParameter &net_param,
                         TensorDimsMap *tensor_dims_map,
                         std::map<std::string, std::string> *tensor_modify_map,
                         std::vector<LayerParameter> *order);

      bool modify_pool_param(apollo_msgs::msg::ApolloperceptioninferencePoolingParameter *pool_param);
#endif
      struct ConvParam
      {
        int kernel_h;
        int kernel_w;
        int padding_h;
        int padding_w;
        int stride_h;
        int stride_w;
        int group;
        int dilation;
      };
#ifndef NVVC

      bool ParserConvParam(const apollo_msgs::msg::ApolloperceptioninferenceConvolutionParameter &conv, ConvParam *param);

#endif
      inline DimsCHW getCHW(const nvinfer1::Dims &d)
      {
        assert(d.nbDims >= 3);
        return DimsCHW(d.d[d.nbDims - 3], d.d[d.nbDims - 2],
                       d.d[d.nbDims - 1]);
      }

    } // namespace inference
  }   // namespace perception
} // namespace apollo
