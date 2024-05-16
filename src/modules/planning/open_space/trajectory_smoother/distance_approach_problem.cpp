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

/*
 * @file
 */

#include "modules/planning/open_space/trajectory_smoother/distance_approach_problem.h"

#include <string>
#include <unordered_map>

#include "modules/common/util/perf_util.h"

namespace apollo {
namespace planning {

DistanceApproachProblem::DistanceApproachProblem(
    const PlannerOpenSpaceConfig& planner_open_space_config) {
  planner_open_space_config_ = planner_open_space_config;
}

bool DistanceApproachProblem::Solve(
    const Eigen::MatrixXd& x0, const Eigen::MatrixXd& xF,
    const Eigen::MatrixXd& last_time_u, const size_t horizon, const double ts,
    const Eigen::MatrixXd& ego, const Eigen::MatrixXd& xWS,
    const Eigen::MatrixXd& uWS, const Eigen::MatrixXd& l_warm_up,
    const Eigen::MatrixXd& n_warm_up, const Eigen::MatrixXd& s_warm_up,
    const std::vector<double>& XYbounds, const size_t obstacles_num,
    const Eigen::MatrixXi& obstacles_edges_num,
    const Eigen::MatrixXd& obstacles_A, const Eigen::MatrixXd& obstacles_b,
    Eigen::MatrixXd* state_result, Eigen::MatrixXd* control_result,
    Eigen::MatrixXd* time_result, Eigen::MatrixXd* dual_l_result,
    Eigen::MatrixXd* dual_n_result) {

    UNUSED(x0);
    UNUSED(xF);
    UNUSED(last_time_u);
    UNUSED(horizon);
    UNUSED(ts);
    UNUSED(ego);
    UNUSED(xWS);
    UNUSED(uWS);
    UNUSED(l_warm_up);
    UNUSED(n_warm_up);
    UNUSED(s_warm_up);
    UNUSED(XYbounds);
    UNUSED(obstacles_num);
    UNUSED(obstacles_edges_num);
    UNUSED(obstacles_A);
    UNUSED(obstacles_b);
    UNUSED(state_result);
    UNUSED(control_result);
    UNUSED(time_result);
    UNUSED(dual_l_result);
    UNUSED(dual_n_result);
    // TODO(QiL) : evaluate whether need to new it everytime
    PERF_BLOCK_START();
#if true
    DistanceApproachInterface *ptop = nullptr;

    if (planner_open_space_config_.distanceapproachconfig
            .distanceapproachmode == DISTANCE_APPROACH_IPOPT)
    {
        ptop = new DistanceApproachIPOPTInterface(
            horizon, ts, ego, xWS, uWS, l_warm_up, n_warm_up, x0, xF, last_time_u,
            XYbounds, obstacles_edges_num, obstacles_num, obstacles_A, obstacles_b,
            planner_open_space_config_);
  } else if (planner_open_space_config_.distanceapproachconfig
                 .distanceapproachmode ==
             DISTANCE_APPROACH_IPOPT_FIXED_TS) {
    ptop = new DistanceApproachIPOPTFixedTsInterface(
        horizon, ts, ego, xWS, uWS, l_warm_up, n_warm_up, x0, xF, last_time_u,
        XYbounds, obstacles_edges_num, obstacles_num, obstacles_A, obstacles_b,
        planner_open_space_config_);
  } else if (planner_open_space_config_.distanceapproachconfig
                 .distanceapproachmode == DISTANCE_APPROACH_IPOPT_CUDA) {
    ptop = new DistanceApproachIPOPTCUDAInterface(
        horizon, ts, ego, xWS, uWS, l_warm_up, n_warm_up, x0, xF, last_time_u,
        XYbounds, obstacles_edges_num, obstacles_num, obstacles_A, obstacles_b,
        planner_open_space_config_);
  } else if (planner_open_space_config_.distanceapproachconfig
                 .distanceapproachmode ==
             DISTANCE_APPROACH_IPOPT_FIXED_DUAL) {
    ptop = new DistanceApproachIPOPTFixedDualInterface(
        horizon, ts, ego, xWS, uWS, l_warm_up, n_warm_up, x0, xF, last_time_u,
        XYbounds, obstacles_edges_num, obstacles_num, obstacles_A, obstacles_b,
        planner_open_space_config_);
  } else if (planner_open_space_config_.distanceapproachconfig
                 .distanceapproachmode ==
             DISTANCE_APPROACH_IPOPT_RELAX_END) {
    ptop = new DistanceApproachIPOPTRelaxEndInterface(
        horizon, ts, ego, xWS, uWS, l_warm_up, n_warm_up, x0, xF, last_time_u,
        XYbounds, obstacles_edges_num, obstacles_num, obstacles_A, obstacles_b,
        planner_open_space_config_);
  } else if (planner_open_space_config_.distanceapproachconfig
                 .distanceapproachmode ==
             DISTANCE_APPROACH_IPOPT_RELAX_END_SLACK) {
    ptop = new DistanceApproachIPOPTRelaxEndSlackInterface(
        horizon, ts, ego, xWS, uWS, l_warm_up, n_warm_up, s_warm_up, x0, xF,
        last_time_u, XYbounds, obstacles_edges_num, obstacles_num, obstacles_A,
        obstacles_b, planner_open_space_config_);
  }

  Ipopt::SmartPtr<Ipopt::TNLP> problem = ptop;

  // Create an instance of the IpoptApplication
  Ipopt::SmartPtr<Ipopt::IpoptApplication> app = IpoptApplicationFactory();

  app->Options()->SetIntegerValue(
      "print_level", planner_open_space_config_.distanceapproachconfig
                         .ipoptconfig
                         .ipoptprintlevel);
  app->Options()->SetIntegerValue(
      "mumps_mem_percent", planner_open_space_config_.distanceapproachconfig
                               .ipoptconfig
                               .mumpsmempercent);
  app->Options()->SetNumericValue(
      "mumps_pivtol", planner_open_space_config_.distanceapproachconfig
                          .ipoptconfig
                          .mumpspivtol);
  app->Options()->SetIntegerValue(
      "max_iter", planner_open_space_config_.distanceapproachconfig
                      .ipoptconfig
                      .ipoptmaxiter);
  app->Options()->SetNumericValue(
      "tol", planner_open_space_config_.distanceapproachconfig
                 .ipoptconfig
                 .ipopttol);
  app->Options()->SetNumericValue(
      "acceptable_constr_viol_tol",
      planner_open_space_config_.distanceapproachconfig
          .ipoptconfig
          .ipoptacceptableconstrvioltol);
  app->Options()->SetNumericValue(
      "min_hessian_perturbation",
      planner_open_space_config_.distanceapproachconfig
          .ipoptconfig
          .ipoptminhessianperturbation);
  app->Options()->SetNumericValue(
      "jacobian_regularization_value",
      planner_open_space_config_.distanceapproachconfig
          .ipoptconfig
          .ipoptjacobianregularizationvalue);
  app->Options()->SetStringValue(
      "print_timing_statistics",
      planner_open_space_config_.distanceapproachconfig
          .ipoptconfig
          .ipoptprinttimingstatistics);
  app->Options()->SetStringValue(
      "alpha_for_y", planner_open_space_config_.distanceapproachconfig
                         .ipoptconfig
                         .ipoptalphafory);
  app->Options()->SetStringValue(
      "recalc_y", planner_open_space_config_.distanceapproachconfig
                      .ipoptconfig
                      .ipoptrecalcy);
  app->Options()->SetNumericValue(
      "mu_init", planner_open_space_config_.distanceapproachconfig
                     .ipoptconfig
                     .ipoptmuinit);

  Ipopt::ApplicationReturnStatus status = app->Initialize();
  if (status != Ipopt::Solve_Succeeded) {
    AERROR << "*** Distance Approach problem error during initialization!";
    return false;
  }

  status = app->OptimizeTNLP(problem);

  if (status == Ipopt::Solve_Succeeded ||
      status == Ipopt::Solved_To_Acceptable_Level) {
    // Retrieve some statistics about the solve
    Ipopt::Index iter_count = app->Statistics()->IterationCount();
    ADEBUG << "*** The problem solved in " << iter_count << " iterations!";

    Ipopt::Number final_obj = app->Statistics()->FinalObjective();
    
    ADEBUG << "*** The final value of the objective function is " 
           << '.' << final_obj;

    PERF_BLOCK_END("DistanceApproachProblemSolving");
  } else {
    /*
      return detailed failure information,
      reference resource: Ipopt::ApplicationReturnStatus, https://
      www.coin-or.org/Doxygen/CoinAll/_ip_return_codes__inc_8h-source.html
    */
    std::unordered_map<int, std::string> failure_status = {
        {0, "Solve_Succeeded"},
        {1, "Solved_To_Acceptable_Level"},
        {2, "Infeasible_Problem_Detected"},
        {3, "Search_Direction_Becomes_Too_Small"},
        {4, "Diverging_Iterates"},
        {5, "User_Requested_Stop"},
        {6, "Feasible_Point_Found"},
        {-1, "Maximum_Iterations_Exceeded"},
        {-2, "Restoration_Failed"},
        {-3, "Error_In_Step_Computation"},
        {-10, "Not_Enough_Degrees_Of_Freedom"},
        {-11, "Invalid_Problem_Definition"},
        {-12, "Invalid_Option"},
        {-13, "Invalid_Number_Detected"},
        {-100, "Unrecoverable_Exception"},
        {-101, "NonIpopt_Exception_Thrown"},
        {-102, "Insufficient_Memory"},
        {-199, "Internal_Error"}};

    if (!failure_status.count(static_cast<size_t>(status))) {
      AINFO << "Solver ends with unknown failure code: "
            << static_cast<int>(status);
    } else {
      AINFO << "Solver failure case: "
            << failure_status[static_cast<size_t>(status)];
    }
  }

  ptop->get_optimization_results(state_result, control_result, time_result,
                                 dual_l_result, dual_n_result);

  return status == Ipopt::Solve_Succeeded ||
         status == Ipopt::Solved_To_Acceptable_Level;
         #else
         return false;
         #endif
}

}  // namespace planning
}  // namespace apollo
