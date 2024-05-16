/******************************************************************************
COPYRIGHT
All contributions by the University of California:
Copyright (c) 2014-2017 The Regents of the University of California (Regents)
All rights reserved.
All other contributions:
Copyright (c) 2014-2017, the respective contributors
All rights reserved.
Caffe uses a shared copyright model: each contributor holds copyright over
their contributions to Caffe. The project versioning records all such
contribution and copyright details. If a contributor wants to further mark
their specific copyright on a particular contribution, they should indicate
their copyright solely in the commit message of the change when it is
committed.
LICENSE
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
CONTRIBUTION AGREEMENT
By contributing to the BVLC/caffe repository through pull-request, comment,
or otherwise, the contributor releases their content to the
license and copyright terms herein.
 *****************************************************************************/

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
#ifndef USE_GPU
#define USE_GPU
#endif
#include "cyber/common/log.h"
#include "modules/perception/base/common.h"

namespace apollo {
namespace perception {
namespace base {

inline void PerceptionMallocHost(void** ptr, size_t size, bool use_cuda) {
#ifdef USE_GPU 
  if (use_cuda) {
    BASE_CUDA_CHECK(cudaMallocHost(ptr, size));
    return;
  }
#endif
  *ptr = malloc(size);
  ACHECK(*ptr) << "host allocation of size " << size << " failed";
}

inline void PerceptionFreeHost(void* ptr, bool use_cuda) {
#ifdef USE_GPU
  if (use_cuda) {
    BASE_CUDA_CHECK(cudaFreeHost(ptr));
    return;
  }
#endif
  free(ptr);
}

/**
 * @brief Manages memory allocation and synchronization between the host (CPU)
 *        and device (GPU).
 *
 * TODO(dox): more thorough description.
 */
class SyncedMemory {
 public:
  enum SyncedHead { UNINITIALIZED, HEAD_AT_CPU, HEAD_AT_GPU, SYNCED };
  
  SyncedMemory(){}
  explicit SyncedMemory(bool use_cuda);
  SyncedMemory(size_t size, bool use_cuda);
  ~SyncedMemory() {
  check_device();
  if (cpu_ptr_ && own_cpu_data_) {
    PerceptionFreeHost(cpu_ptr_, cpu_malloc_use_cuda_);
  }

  #ifdef USE_GPU 
    if (gpu_ptr_ && own_gpu_data_) {
      BASE_CUDA_CHECK(cudaFree(gpu_ptr_));
    }
  #endif  // USE_GPU
  }

  const void* cpu_data();
  void set_cpu_data(void* data);
  const void* gpu_data();
  void set_gpu_data(void* data);
  void* mutable_cpu_data();
  void* mutable_gpu_data();

  SyncedHead head() const { return head_; }
  void set_head(SyncedHead head) { head_ = head; }
  void set_head_gpu() { set_head(HEAD_AT_GPU); }
  void set_head_cpu() { set_head(HEAD_AT_CPU); }
  size_t size() { return size_; }

#ifdef USE_GPU
  void async_gpu_push(const cudaStream_t& stream);
#endif
  void to_cpu();
  inline void to_gpu()
  {
    check_device();
#ifdef USE_GPU
    switch (head_)
    {
    case UNINITIALIZED:
      BASE_CUDA_CHECK(cudaMalloc(&gpu_ptr_, size_));
      BASE_CUDA_CHECK(cudaMemset(gpu_ptr_, 0, size_));
      head_ = HEAD_AT_GPU;
      own_gpu_data_ = true;
      break;
    case HEAD_AT_CPU:
      if (gpu_ptr_ == nullptr)
      {
        BASE_CUDA_CHECK(cudaMalloc(&gpu_ptr_, size_));
        own_gpu_data_ = true;
      }
      BASE_CUDA_CHECK(cudaMemcpy(gpu_ptr_, cpu_ptr_, size_, cudaMemcpyDefault));
      head_ = SYNCED;
      break;
    case HEAD_AT_GPU:
    case SYNCED:
      break;
    }
#else
    NO_GPU;
#endif
  }

private:
  void check_device(){
#ifdef USE_GPU
  int device;
  cudaGetDevice(&device);
  //CHECK_EQ(device, device_);
  if (gpu_ptr_ && own_gpu_data_) {
    cudaPointerAttributes attributes;
    BASE_CUDA_CHECK(cudaPointerGetAttributes(&attributes, gpu_ptr_));
    //CHECK_EQ(attributes.device, device_);
  }
#endif
}


 public:
  void* cpu_ptr_;
  void* gpu_ptr_;
  size_t size_;
  SyncedHead head_;
  bool own_cpu_data_;
  bool cpu_malloc_use_cuda_;
  bool own_gpu_data_;
  int device_;
};  // class SyncedMemory

}  // namespace base
}  // namespace perception
}  // namespace apollo
