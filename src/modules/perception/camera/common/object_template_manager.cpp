/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include "modules/perception/camera/common/object_template_manager.h"

#include <algorithm>
#include <limits>
#include <tuple>
#include <utility>

#include "cyber/cyber.h"
#include "modules/perception/common/io/io_util.h"
#include "modules/perception/lib/config_manager/config_manager.h"

namespace {
constexpr float kFloatEpsilon = std::numeric_limits<float>::epsilon();
}  // namespace

namespace apollo {
namespace perception {
namespace camera {

std::vector<base::ObjectSubType> kTypeCanBeRef = {base::ObjectSubType::CAR,
                                                  base::ObjectSubType::VAN};

std::vector<base::ObjectSubType> kTypeRefinedByTemplate = {
    base::ObjectSubType::CAR,        base::ObjectSubType::VAN,
    base::ObjectSubType::BUS,        base::ObjectSubType::TRUCK,
    base::ObjectSubType::PEDESTRIAN, base::ObjectSubType::TRAFFICCONE,
    base::ObjectSubType::CYCLIST,    base::ObjectSubType::MOTORCYCLIST,
};

std::vector<base::ObjectSubType> kTypeRefinedByRef = {
    base::ObjectSubType::BUS,        base::ObjectSubType::TRUCK,
    base::ObjectSubType::PEDESTRIAN, base::ObjectSubType::TRAFFICCONE,
    base::ObjectSubType::CYCLIST,    base::ObjectSubType::MOTORCYCLIST,
    base::ObjectSubType::TRICYCLIST};

ObjectTemplateManager::ObjectTemplateManager() {}

bool ObjectTemplateManager::Init(
    const ObjectTemplateManagerInitOptions &options) {
  lib::MutexLock lock(&mutex_);
  if (inited_) {
    return true;
  }

  nr_dim_per_tmplt_ = 3;

  std::string config =
      cyber::common::GetAbsolutePath(options.root_dir, options.conf_file);
  ObjectTemplateMeta proto;
  /*if (!cyber::common::GetProtoFromFile(config, &proto)) {
    AERROR_EVERY(60000) << "Read config failed: " << config;
    return false;
  }*/
  //auto currentNode = apollo::cyber::currentNode;
  apollo::cyber::ComponentBase::instance()->replaceRoot(config);
  apollo::cyber::common::GetProtoFromASCIIFile(config, &proto);

  ACHECK(proto.maxdimchangeratio!=0);

  //ACHECK(proto.unknown!=ObjectTemplate());
  ACHECK(proto.unknownmovable!=ObjectTemplate());
  //ACHECK(proto.unknownunmovable!=ObjectTemplate());
  ACHECK(proto.car!=ObjectTemplate());
  ACHECK(proto.van!=ObjectTemplate());
  ACHECK(proto.truck!=ObjectTemplate());
  ACHECK(proto.bus!=ObjectTemplate());
  ACHECK(proto.cyclist!=ObjectTemplate());
  ACHECK(proto.motorcyclist!=ObjectTemplate());
  ACHECK(proto.tricyclist!=ObjectTemplate());
  ACHECK(proto.pedestrian!=ObjectTemplate());
  ACHECK(proto.trafficcone!=ObjectTemplate());

  CHECK_LE(proto.car.dim.size(), 3);
  CHECK_LE(proto.van.dim.size(), 3);
  CHECK_LE(proto.truck.dim.size(), 3);
  CHECK_LE(proto.bus.dim.size(), 3);
  CHECK_LE(proto.cyclist.dim.size(), 3);
  CHECK_LE(proto.motorcyclist.dim.size(), 3);
  CHECK_LE(proto.tricyclist.dim.size(), 3);
  CHECK_LE(proto.pedestrian.dim.size(), 3);
  CHECK_LE(proto.trafficcone.dim.size(), 3);

  //ACHECK(proto.unknown.speedlimit!=0);
  //ACHECK(proto.unknownmovable.speedlimit!=0);
  //ACHECK(proto.unknownunmovable.speedlimit!=0);
  ACHECK(proto.car.speedlimit!=0);
  ACHECK(proto.van.speedlimit!=0);
  ACHECK(proto.truck.speedlimit!=0);
  ACHECK(proto.bus.speedlimit!=0);
  ACHECK(proto.cyclist.speedlimit!=0);
  ACHECK(proto.motorcyclist.speedlimit!=0);
  ACHECK(proto.tricyclist.speedlimit!=0);
  ACHECK(proto.pedestrian.speedlimit!=0);
  //ACHECK(proto.trafficcone.speedlimit!=0);

  max_dim_change_ratio_ = proto.maxdimchangeratio;

  total_nr_tmplts_veh_ = proto.car.dim.size() + proto.van.dim.size() +
                         proto.truck.dim.size() + proto.bus.dim.size();

  look_up_table_min_volume_index_.clear();
  veh_hwl_.resize(0);
  look_up_table_min_volume_index_[TemplateIndex::CAR_MIN_VOLUME_INDEX] =
      static_cast<int>(veh_hwl_.size());
  LoadVehTemplates(proto.car);
  look_up_table_min_volume_index_[TemplateIndex::VAN_MIN_VOLUME_INDEX] =
      static_cast<int>(veh_hwl_.size());
  LoadVehTemplates(proto.van);
  look_up_table_min_volume_index_[TemplateIndex::TRUCK_MIN_VOLUME_INDEX] =
      static_cast<int>(veh_hwl_.size());
  LoadVehTemplates(proto.truck);
  look_up_table_min_volume_index_[TemplateIndex::BUS_MIN_VOLUME_INDEX] =
      static_cast<int>(veh_hwl_.size());
  LoadVehTemplates(proto.bus);

  min_template_hwl_.clear();
  mid_template_hwl_.clear();
  max_template_hwl_.clear();
  LoadVehMinMidMaxTemplates(base::ObjectSubType::CAR, proto.car);
  LoadVehMinMidMaxTemplates(base::ObjectSubType::VAN, proto.van);
  LoadVehMinMidMaxTemplates(base::ObjectSubType::TRUCK, proto.truck);
  LoadVehMinMidMaxTemplates(base::ObjectSubType::BUS, proto.bus);
  LoadVehMinMidMaxTemplates(base::ObjectSubType::CYCLIST, proto.cyclist);
  LoadVehMinMidMaxTemplates(base::ObjectSubType::MOTORCYCLIST,
                            proto.motorcyclist);
  LoadVehMinMidMaxTemplates(base::ObjectSubType::TRICYCLIST,
                            proto.tricyclist);
  LoadVehMinMidMaxTemplates(base::ObjectSubType::PEDESTRIAN,
                            proto.pedestrian);
  LoadVehMinMidMaxTemplates(base::ObjectSubType::TRAFFICCONE,
                            proto.trafficcone);

  template_hwl_.resize(0);
  template_hwl_.push_back(min_template_hwl_);
  template_hwl_.push_back(mid_template_hwl_);
  template_hwl_.push_back(max_template_hwl_);

  type_speed_limit_.clear();
  type_speed_limit_[base::ObjectSubType::UNKNOWN] =
      proto.unknown.speedlimit;
  type_speed_limit_[base::ObjectSubType::UNKNOWN_MOVABLE] =
      proto.unknownmovable.speedlimit;
  type_speed_limit_[base::ObjectSubType::UNKNOWN_UNMOVABLE] =
      proto.unknownunmovable.speedlimit;
  type_speed_limit_[base::ObjectSubType::CAR] = proto.car.speedlimit;
  type_speed_limit_[base::ObjectSubType::VAN] = proto.van.speedlimit;
  type_speed_limit_[base::ObjectSubType::TRUCK] = proto.truck.speedlimit;
  type_speed_limit_[base::ObjectSubType::BUS] = proto.bus.speedlimit;
  type_speed_limit_[base::ObjectSubType::CYCLIST] =
      proto.cyclist.speedlimit;
  type_speed_limit_[base::ObjectSubType::MOTORCYCLIST] =
      proto.motorcyclist.speedlimit;
  type_speed_limit_[base::ObjectSubType::TRICYCLIST] =
      proto.tricyclist.speedlimit;
  type_speed_limit_[base::ObjectSubType::PEDESTRIAN] =
      proto.pedestrian.speedlimit;
  type_speed_limit_[base::ObjectSubType::TRAFFICCONE] =
      proto.trafficcone.speedlimit;

  type_can_be_ref_ = kTypeCanBeRef;
  type_refined_by_template_ = kTypeRefinedByTemplate;
  type_refined_by_ref_ = kTypeRefinedByRef;

  inited_ = true;
  AINFO_EVERY(60000) << "Init object_template_manager success.";
  return true;
}

void ObjectTemplateManager::LoadVehTemplates(const ObjectTemplate &tmplt) {
  std::vector<std::tuple<float, float, float>> list_tpl;
  list_tpl.resize(0);
  for (size_t i = 0; i < tmplt.dim.size(); ++i)
  {
    Dim dim = tmplt.dim[i];
    list_tpl.push_back(std::make_tuple(dim.h, dim.w, dim.l));
  }
  std::sort(list_tpl.begin(), list_tpl.end());
  for (size_t i = 0; i < list_tpl.size(); ++i) {
    veh_hwl_.push_back(std::get<0>(list_tpl[i]));
    veh_hwl_.push_back(std::get<1>(list_tpl[i]));
    veh_hwl_.push_back(std::get<2>(list_tpl[i]));
  }
}

void ObjectTemplateManager::LoadVehMinMidMaxTemplates(
    const base::ObjectSubType &type, const ObjectTemplate &tmplt) {
  std::vector<std::tuple<float, float, float>> list_tpl;
  list_tpl.resize(0);
  for (size_t i = 0; i < tmplt.dim.size(); ++i) {
    Dim dim = tmplt.dim[i];
    list_tpl.push_back(std::make_tuple(dim.h, dim.w, dim.l));
  }

  std::sort(list_tpl.begin(), list_tpl.end());

  int ind_min = 0;
  int ind_max = static_cast<int>(list_tpl.size()) - 1;
  int ind_mid = (ind_min + ind_max) / 2;
  std::vector<float> tmplt_min = {std::get<0>(list_tpl[ind_min]),
                                  std::get<1>(list_tpl[ind_min]),
                                  std::get<2>(list_tpl[ind_min])};
  std::vector<float> tmplt_mid = {std::get<0>(list_tpl[ind_mid]),
                                  std::get<1>(list_tpl[ind_mid]),
                                  std::get<2>(list_tpl[ind_mid])};
  std::vector<float> tmplt_max = {std::get<0>(list_tpl[ind_max]),
                                  std::get<1>(list_tpl[ind_max]),
                                  std::get<2>(list_tpl[ind_max])};
  min_template_hwl_[type] = tmplt_min;
  mid_template_hwl_[type] = tmplt_mid;
  max_template_hwl_[type] = tmplt_max;
}

// util for tmplt search
float ObjectTemplateManager::Get3dDimensionSimilarity(const float *hwl1,
                                                      const float *hwl2) {
  ACHECK(hwl1 != nullptr);
  ACHECK(hwl2 != nullptr);

  float max_h = std::max(hwl1[0], hwl2[0]);
  float min_h = hwl1[0] + hwl2[0] - max_h;
  float max_w = std::max(hwl1[1], hwl2[1]);
  float min_w = hwl1[1] + hwl2[1] - max_w;
  float max_l = std::max(hwl1[2], hwl2[2]);
  float min_l = hwl1[2] + hwl2[2] - max_l;

  float iou_h = min_h / (kFloatEpsilon + max_h);
  float iou_w = min_w / (kFloatEpsilon + max_w);
  float iou_l = min_l / (kFloatEpsilon + max_l);

  return iou_h * iou_h * iou_w * iou_l;  // h^2 * w * l
}

// for general visual obj
float ObjectTemplateManager::VehObjHwlBySearchTemplates(float *hwl, int *index,
                                                        bool *is_flip) {
  ACHECK(inited_);
  ACHECK(hwl != nullptr);

  float hwl_flip[3] = {hwl[0], hwl[2], hwl[1]};
  float score_best = -std::numeric_limits<float>::max();
  int i_best = -1;
  int i3 = 0;
  bool from_flip = false;
  for (int i = 0; i < total_nr_tmplts_veh_; ++i) {
    float score = Get3dDimensionSimilarity(hwl, &veh_hwl_[i3]);
    float score_flip = Get3dDimensionSimilarity(hwl_flip, &veh_hwl_[i3]);
    bool from_flip_cur = false;
    if (score_flip > score) {
      score = score_flip;
      from_flip_cur = true;
    }
    if (score > score_best) {
      score_best = score;
      i_best = i;
      from_flip = from_flip_cur;
    }
    i3 += 3;
  }
  int i_best_by_3 = i_best * 3;
  float hwl_tmplt_matched[3] = {veh_hwl_[i_best_by_3],
                                veh_hwl_[i_best_by_3 + 1],
                                veh_hwl_[i_best_by_3 + 2]};
  if (from_flip) {
    std::swap(hwl_tmplt_matched[1], hwl_tmplt_matched[2]);
  }

  float dh = fabsf(hwl[0] - hwl_tmplt_matched[0]);
  float dh_ratio = dh / hwl_tmplt_matched[0];
  float dw = fabsf(hwl[1] - hwl_tmplt_matched[1]);
  float dw_ratio = dw / hwl_tmplt_matched[1];
  float dl = fabsf(hwl[2] - hwl_tmplt_matched[2]);
  float dl_ratio = dl / hwl_tmplt_matched[2];
  float dh_dw_dl_ratio_mean = (dh_ratio + dw_ratio + dl_ratio) / 3;
  float dh_ratio_check = std::min(dh_ratio, dh_dw_dl_ratio_mean);
  if (score_best < kFloatEpsilon || dh_ratio_check > max_dim_change_ratio_) {
    return -1.0f;
  }
  ADEBUG << dh_ratio << ", " << dw_ratio << ", " << dl_ratio;

  hwl[0] = veh_hwl_[i_best_by_3];
  hwl[1] = veh_hwl_[i_best_by_3 + 1];
  hwl[2] = veh_hwl_[i_best_by_3 + 2];
  if (index != nullptr) {
    *index = i_best;
  }
  if (is_flip != nullptr) {
    *is_flip = from_flip;
  }
  return score_best;
}

}  // namespace camera
}  // namespace perception
}  // namespace apollo
