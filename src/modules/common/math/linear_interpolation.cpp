/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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

#include "modules/common/math/linear_interpolation.h"

#include <cmath>

#include "cyber/cyber.h"
#include "modules/common/math/math_utils.h"

namespace apollo {
namespace common {
namespace math {

double slerp(const double a0, const double t0, const double a1, const double t1,
             const double t) {
  if (std::abs(t1 - t0) <= kMathEpsilon) {
    ADEBUG << "input time difference is too small";
    return NormalizeAngle(a0);
  }
  const double a0_n = NormalizeAngle(a0);
  const double a1_n = NormalizeAngle(a1);
  double d = a1_n - a0_n;
  if (d > M_PI) {
    d = d - 2 * M_PI;
  } else if (d < -M_PI) {
    d = d + 2 * M_PI;
  }

  const double r = (t - t0) / (t1 - t0);
  const double a = a0_n + d * r;
  return NormalizeAngle(a);
}

SLPoint InterpolateUsingLinearApproximation(const SLPoint &p0,
                                            const SLPoint &p1, const double w) {
  CHECK_GE(w, 0.0);

  SLPoint p;
  p.s=((1 - w) * p0.s + w * p1.s);
  p.l=((1 - w) * p0.l + w * p1.l);
  return p;
}

PathPoint InterpolateUsingLinearApproximation(const PathPoint &p0,
                                              const PathPoint &p1,
                                              const double s) {
  double s0 = p0.s;
  double s1 = p1.s;

  PathPoint path_point;
  double weight = (s - s0) / (s1 - s0);
  double x = (1 - weight) * p0.x + weight * p1.x;
  double y = (1 - weight) * p0.y + weight * p1.y;
  double theta = slerp(p0.theta, p0.s, p1.theta, p1.s, s);
  double kappa = (1 - weight) * p0.kappa + weight * p1.kappa;
  double dkappa = (1 - weight) * p0.dkappa + weight * p1.dkappa;
  double ddkappa = (1 - weight) * p0.ddkappa + weight * p1.ddkappa;
  path_point.x=(x);
  path_point.y=(y);
  path_point.set__theta(theta);
  path_point.set__kappa(kappa);
  path_point.set__dkappa(dkappa);
  path_point.set__ddkappa(ddkappa);
  path_point.set__s(s);
  return path_point;
}

TrajectoryPoint InterpolateUsingLinearApproximation(const TrajectoryPoint &tp0,
                                                    const TrajectoryPoint &tp1,
                                                    const double t) {
  const PathPoint pp0 = tp0.pathpoint;
  const PathPoint pp1 = tp1.pathpoint;
  double t0 = tp0.relativetime;
  double t1 = tp1.relativetime;

  TrajectoryPoint tp;
  tp.set__v(lerp(tp0.v, t0, tp1.v, t1, t));
  tp.set__a(lerp(tp0.a, t0, tp1.a, t1, t));
  tp.set__relativetime(t);
  tp.set__steer(slerp(tp0.steer, t0, tp1.steer, t1, t));

  PathPoint *path_point = &tp.pathpoint;
  path_point->set__x(lerp(pp0.x, t0, pp1.x, t1, t));
  path_point->set__y(lerp(pp0.y, t0, pp1.y, t1, t));
  path_point->set__theta(slerp(pp0.theta, t0, pp1.theta, t1, t));
  path_point->set__kappa(lerp(pp0.kappa, t0, pp1.kappa, t1, t));
  path_point->set__dkappa(lerp(pp0.dkappa, t0, pp1.dkappa, t1, t));
  path_point->set__ddkappa(lerp(pp0.ddkappa, t0, pp1.ddkappa, t1, t));
  path_point->set__s(lerp(pp0.s, t0, pp1.s, t1, t));

  return tp;
}

}  // namespace math
}  // namespace common
}  // namespace apollo
