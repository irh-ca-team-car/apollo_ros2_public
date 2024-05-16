/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
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

/**
 * @file
 **/

#include "modules/planning/math/discretized_points_smoothing/fem_pos_deviation_smoother.h"
#if true
#include <coin/IpIpoptApplication.hpp>
#include <coin/IpSolveStatistics.hpp>

#include "cyber/common/log.h"
#include "modules/planning/math/discretized_points_smoothing/fem_pos_deviation_ipopt_interface.h"
#include "modules/planning/math/discretized_points_smoothing/fem_pos_deviation_osqp_interface.h"
#include "modules/planning/math/discretized_points_smoothing/fem_pos_deviation_sqp_osqp_interface.h"

namespace apollo {
namespace planning {
FemPosDeviationSmoother::FemPosDeviationSmoother(
    const FemPosDeviationSmootherConfig& config)
    : config_(config) {}

bool FemPosDeviationSmoother::Solve(
    const std::vector<std::pair<double, double>>& raw_point2d,
    const std::vector<double>& bounds, std::vector<double>* opt_x,
    std::vector<double>* opt_y) {
  if (config_.applycurvatureconstraint) {
    if (config_.usesqp) {
      return SqpWithOsqp(raw_point2d, bounds, opt_x, opt_y);
    } else {
      return NlpWithIpopt(raw_point2d, bounds, opt_x, opt_y);
    }
  } else {
    return QpWithOsqp(raw_point2d, bounds, opt_x, opt_y);
  }
  return true;
}

bool FemPosDeviationSmoother::QpWithOsqp(
    const std::vector<std::pair<double, double>>& raw_point2d,
    const std::vector<double>& bounds, std::vector<double>* opt_x,
    std::vector<double>* opt_y) {
  if (opt_x == nullptr || opt_y == nullptr) {
    AERROR << "opt_x or opt_y is nullptr";
    return false;
  }

  FemPosDeviationOsqpInterface solver;

  solver.set_weight_fem_pos_deviation(config_.weightfemposdeviation);
  solver.set_weight_path_length(config_.weightpathlength);
  solver.set_weight_ref_deviation(config_.weightrefdeviation);

  solver.set_max_iter(config_.maxiter);
  solver.set_time_limit(config_.timelimit);
  solver.set_verbose(config_.verbose);
  solver.set_scaled_termination(config_.scaledtermination);
  solver.set_warm_start(config_.warmstart);

  solver.set_ref_points(raw_point2d);
  solver.set_bounds_around_refs(bounds);

  if (!solver.Solve()) {
    return false;
  }

  *opt_x = solver.opt_x();
  *opt_y = solver.opt_y();
  return true;
}

bool FemPosDeviationSmoother::SqpWithOsqp(
    const std::vector<std::pair<double, double>>& raw_point2d,
    const std::vector<double>& bounds, std::vector<double>* opt_x,
    std::vector<double>* opt_y) {
  if (opt_x == nullptr || opt_y == nullptr) {
    AERROR << "opt_x or opt_y is nullptr";
    return false;
  }

  FemPosDeviationSqpOsqpInterface solver;

  solver.set_weight_fem_pos_deviation(config_.weightfemposdeviation);
  solver.set_weight_path_length(config_.weightpathlength);
  solver.set_weight_ref_deviation(config_.weightrefdeviation);
  solver.set_weight_curvature_constraint_slack_var(
      config_.weightcurvatureconstraintslackvar);

  solver.set_curvature_constraint(config_.curvatureconstraint);

  solver.set_sqp_sub_max_iter(config_.sqpsubmaxiter);
  solver.set_sqp_ftol(config_.sqpftol);
  solver.set_sqp_pen_max_iter(config_.sqppenmaxiter);
  solver.set_sqp_ctol(config_.sqpctol);

  solver.set_max_iter(config_.maxiter);
  solver.set_time_limit(config_.timelimit);
  solver.set_verbose(config_.verbose);
  solver.set_scaled_termination(config_.scaledtermination);
  solver.set_warm_start(config_.warmstart);

  solver.set_ref_points(raw_point2d);
  solver.set_bounds_around_refs(bounds);

  if (!solver.Solve()) {
    return false;
  }

  std::vector<std::pair<double, double>> opt_xy = solver.opt_xy();

  // TODO(Jinyun): unify output data container
  opt_x->resize(opt_xy.size());
  opt_y->resize(opt_xy.size());
  for (size_t i = 0; i < opt_xy.size(); ++i) {
    (*opt_x)[i] = opt_xy[i].first;
    (*opt_y)[i] = opt_xy[i].second;
  }
  return true;
}

bool FemPosDeviationSmoother::NlpWithIpopt(
    const std::vector<std::pair<double, double>>& raw_point2d,
    const std::vector<double>& bounds, std::vector<double>* opt_x,
    std::vector<double>* opt_y) {
  if (opt_x == nullptr || opt_y == nullptr) {
    AERROR << "opt_x or opt_y is nullptr";
    return false;
  }

  FemPosDeviationIpoptInterface* smoother =
      new FemPosDeviationIpoptInterface(raw_point2d, bounds);

  smoother->set_weight_fem_pos_deviation(config_.weightfemposdeviation);
  smoother->set_weight_path_length(config_.weightpathlength);
  smoother->set_weight_ref_deviation(config_.weightrefdeviation);
  smoother->set_weight_curvature_constraint_slack_var(
      config_.weightcurvatureconstraintslackvar);
  smoother->set_curvature_constraint(config_.curvatureconstraint);

  Ipopt::SmartPtr<Ipopt::TNLP> problem = smoother;

  // Create an instance of the IpoptApplication
  Ipopt::SmartPtr<Ipopt::IpoptApplication> app = IpoptApplicationFactory();

  app->Options()->SetIntegerValue("print_level",
                                  static_cast<int>(config_.printlevel));
  app->Options()->SetIntegerValue(
      "max_iter", static_cast<int>(config_.maxnumofiterations));
  app->Options()->SetIntegerValue(
      "acceptable_iter",
      static_cast<int>(config_.acceptablenumofiterations));
  app->Options()->SetNumericValue("tol", config_.tol);
  app->Options()->SetNumericValue("acceptable_tol", config_.acceptabletol);

  Ipopt::ApplicationReturnStatus status = app->Initialize();
  if (status != Ipopt::Solve_Succeeded) {
    AERROR << "*** Error during initialization!";
    return false;
  }

  status = app->OptimizeTNLP(problem);

  if (status == Ipopt::Solve_Succeeded ||
      status == Ipopt::Solved_To_Acceptable_Level) {
    // Retrieve some statistics about the solve
    Ipopt::Index iter_count = app->Statistics()->IterationCount();
    ADEBUG << "*** The problem solved in " << iter_count << " iterations!";
  } else {
    AERROR << "Solver fails with return code: " << static_cast<int>(status);
    return false;
  }
  smoother->get_optimization_results(opt_x, opt_y);
  return true;
}

}  // namespace planning
}  // namespace apollo
#endif