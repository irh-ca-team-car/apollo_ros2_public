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

#include "modules/perception/inference/tensorrt/rt_common.h"

#include <utility>

#include "absl/strings/str_cat.h"
using namespace apollo_msgs::msg;

namespace apollo
{
  namespace perception
  {
    namespace inference
    {

      apollo::perception::inference::DimsCHW ReshapeDims(const apollo::perception::inference::DimsCHW &dims,
                                                         const apollo::perception::inference::DimsCHW &inputDims)
      {
        apollo::perception::inference::DimsCHW outDims = inputDims;
        int count = inputDims.d[0] * inputDims.d[1] * inputDims.d[2];
        int constant = 1;
        int axis_inference = -1;
        for (int i = 0; i < inputDims.nbDims; ++i)
        {
          if (dims.d[i] == 0)
          {
            outDims.d[i] = inputDims.d[i];
            constant *= outDims.d[i];
          }
          else if (dims.d[i] > 0)
          {
            constant *= dims.d[i];
          }
          else if (dims.d[i] == -1)
          {
            CHECK_EQ(axis_inference, -1);
            outDims.d[i] = count / constant;
            axis_inference = i;
          }
        }
        return outDims;
      }

      void ParseNetParam(const NetParameter &net_param,
                         TensorDimsMap *tensor_dims_map,
                         std::map<std::string, std::string> *tensor_modify_map,
                         std::vector<LayerParameter> *order)
      {
        for (size_t i = 0; i < net_param.layer.size(); ++i)
        {
          LayerParameter tensorrt_layer_param = net_param.layer.at(i);
          if (tensorrt_layer_param.type == "Input")
          {
            auto input = tensorrt_layer_param.inputparam;
            apollo::perception::inference::DimsCHW dims{static_cast<int>(input.shape.at(0).dim.at(1)),
                                                        static_cast<int>(input.shape.at(0).dim.at(2)),
                                                        static_cast<int>(input.shape.at(0).dim.at(3))};
            auto name = tensorrt_layer_param.top.at(0);
            tensor_dims_map->insert(std::make_pair(name, dims));
            tensor_modify_map->insert(
                std::make_pair(name, tensorrt_layer_param.top.at(0)));
          }
          else if (net_param.layer.at(i).type == "Pooling")
          {
            // if (tensorrt_layer_param.poolingparam.cmpoutshapefloorasconv) {
            // tensorrt_layer_param.set__name(tensorrt_layer_param.name + "as_conv");
            //}
            if (tensorrt_layer_param.poolingparam.pad == 0)
            {
              order->push_back(tensorrt_layer_param);
              continue;
            }
            LayerParameter fake_layer_param = tensorrt_layer_param;
            fake_layer_param.set__type("Padding");
            fake_layer_param.set__name(absl::StrCat("padding_split_", i));
            fake_layer_param.poolingparam = ApolloperceptioninferencePoolingParameter();
            auto pad_param = &fake_layer_param.paddingparam;
            auto pool_param = &tensorrt_layer_param.poolingparam;
            modify_pool_param(pool_param);
            pad_param->set__padl(pool_param->padw);
            pad_param->set__padt(pool_param->padh);
            pad_param->set__padb(pool_param->padh);
            pad_param->set__padr(pool_param->padw);
            fake_layer_param.top.at(0) = (fake_layer_param.name);
            pool_param->set__pad(0);
            tensorrt_layer_param.bottom.at(0) = (fake_layer_param.name);

            order->push_back(fake_layer_param);
            order->push_back(tensorrt_layer_param);
          }
          else
          {
            order->push_back(tensorrt_layer_param);
          }
        }
      }

      bool ParserConvParam(const apollo_msgs::msg::ApolloperceptioninferenceConvolutionParameter &conv, ConvParam *param)
      {
        if (conv.kernelh != 0 || conv.kernelw != 0)
        {
          if (conv.kernelsize.size() != 0)
          {
            return false;
          }
          param->kernel_h = conv.kernelh;
          param->kernel_w = conv.kernelw;
        }
        else
        {
          if (conv.kernelsize.size() < 1)
          {
            return false;
          }
          param->kernel_h = conv.kernelsize.at(0);
          param->kernel_w = (conv.kernelsize.size() > 1 ? conv.kernelsize.at(1)
                                                        : conv.kernelsize.at(0));
        }
        if (param->kernel_h == 0 || param->kernel_w == 0)
        {
          return false;
        }

        if (conv.padh != 0 || conv.padw != 0)
        {
          if (conv.pad.size() != 0)
          {
            return false;
          }
          param->padding_h = conv.padh;
          param->padding_w = conv.padw;
        }
        else
        {
          param->padding_h = (conv.pad.empty() ? 0 : conv.pad.at(0));
          param->padding_w = (conv.pad.size() > 1 ? conv.pad.at(1) : param->padding_h);
        }

        if (conv.strideh != 0 || conv.stridew != 0)
        {
          if (conv.stride.size() != 0)
          {
            return false;
          }
          param->stride_h = conv.strideh;
          param->stride_w = conv.stridew;
        }
        else
        {
          param->stride_h = (conv.stride.empty() ? 1 : conv.stride.at(0));
          param->stride_w =
              (conv.stride.size() > 1 ? conv.stride.at(1) : param->stride_h);
        }
        if (param->stride_h == 0 || param->stride_w == 0)
        {
          return false;
        }

        param->dilation = conv.dilation.empty() ? 1 : conv.dilation.at(0);
        return true;
      }

      bool modify_pool_param(apollo_msgs::msg::ApolloperceptioninferencePoolingParameter *pool_param)
      {
        if (pool_param->kernelsize != 0)
        {
          pool_param->set__kernelh(pool_param->kernelsize);
          pool_param->set__kernelw(pool_param->kernelsize);
        }
        if (pool_param->kernelw == 0 || pool_param->kernelh == 0)
        {
          return false;
        }
        if (pool_param->pad != 0)
        {
          pool_param->set__padh(pool_param->pad);
          pool_param->set__padw(pool_param->pad);
        }
        if (pool_param->stride != 0)
        {
          pool_param->set__strideh(pool_param->stride);
          pool_param->set__stridew(pool_param->stride);
        }
        if (pool_param->stridew == 0 || pool_param->strideh == 0)
        {
          return false;
        }
        return true;
      }

    } // namespace inference
  }   // namespace perception
} // namespace apollo
