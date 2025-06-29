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

#include "modules/control/controller/mpc_controller.h"

#include <algorithm>
#include <iomanip>
#include <limits>
#include <utility>
#include <vector>

#include "Eigen/LU"
#include "absl/strings/str_cat.h"
#include "cyber/common/log.h"
#include "cyber/time/clock.h"
#include "modules/common/configs/vehicle_config_helper.h"
#include "modules/common/math/math_utils.h"
#include "modules/common/math/mpc_osqp.h"
#include "modules/control/common/control_gflags.h"

namespace apollo {
namespace control {
using apollo::common::ErrorCode;
using apollo::common::Status;
using apollo::common::TrajectoryPoint;
using apollo::common::VehicleStateProvider;
using apollo::cyber::Clock;
using Matrix = Eigen::MatrixXd;
using apollo::common::VehicleConfigHelper;

namespace {

std::string GetLogFileName() {
  time_t raw_time;
  char name_buffer[80];
  std::time(&raw_time);

  std::tm time_tm;
  localtime_r(&raw_time, &time_tm);
  strftime(name_buffer, sizeof(name_buffer),
           "/tmp/mpc_controller_%F_%H%M%S.csv", &time_tm);
  return std::string(name_buffer);
}

void WriteHeaders(std::ofstream &file_stream) { UNUSED(file_stream); }
}  // namespace

MPCController::MPCController() : name_("MPC Controller") {
  if (FLAGS_enable_csv_debug) {
    mpc_log_file_.open(GetLogFileName());
    mpc_log_file_ << std::fixed;
    mpc_log_file_ << std::setprecision(6);
    WriteHeaders(mpc_log_file_);
  }
  AINFO << "Using " << name_;
}

MPCController::~MPCController() { CloseLogFile(); }

bool MPCController::LoadControlConf(const apollo_msgs::msg::ApollocontrolControlConf *control_conf) {
  if (!control_conf) {
    AERROR << "[MPCController] control_conf = nullptr";
    return false;
  }
  vehicle_param_ = VehicleConfigHelper::Instance()->GetConfig().vehicleparam;

  ts_ = control_conf->mpccontrollerconf.ts;
  if (ts_ <= 0.0) {
    AERROR << "[MPCController] Invalid control update interval.";
    return false;
  }
  cf_ = control_conf->mpccontrollerconf.cf;
  cr_ = control_conf->mpccontrollerconf.cr;
  wheelbase_ = vehicle_param_.wheelbase;
  steer_ratio_ = vehicle_param_.steerratio;
  steer_single_direction_max_degree_ =
      vehicle_param_.maxsteerangle * 180 / M_PI;
  max_lat_acc_ = control_conf->mpccontrollerconf.maxlateralacceleration;

  // TODO(Shu, Qi, Yu): add sanity check for conf values
  // steering ratio should be positive
  static constexpr double kEpsilon = 1e-6;
  if (std::isnan(steer_ratio_) || steer_ratio_ < kEpsilon) {
    AERROR << "[MPCController] steer_ratio = 0";
    return false;
  }
  wheel_single_direction_max_degree_ =
      steer_single_direction_max_degree_ / steer_ratio_ / 180 * M_PI;
  max_acceleration_ = vehicle_param_.maxacceleration;
  max_deceleration_ = vehicle_param_.maxdeceleration;

  const double mass_fl = control_conf->mpccontrollerconf.massfl;
  const double mass_fr = control_conf->mpccontrollerconf.massfr;
  const double mass_rl = control_conf->mpccontrollerconf.massrl;
  const double mass_rr = control_conf->mpccontrollerconf.massrr;
  const double mass_front = mass_fl + mass_fr;
  const double mass_rear = mass_rl + mass_rr;
  mass_ = mass_front + mass_rear;

  lf_ = wheelbase_ * (1.0 - mass_front / mass_);
  lr_ = wheelbase_ * (1.0 - mass_rear / mass_);
  iz_ = lf_ * lf_ * mass_front + lr_ * lr_ * mass_rear;

  mpc_eps_ = control_conf->mpccontrollerconf.eps;
  mpc_max_iteration_ = control_conf->mpccontrollerconf.maxiteration;
  throttle_lowerbound_ =
      std::max(vehicle_param_.throttledeadzone,
               control_conf->mpccontrollerconf.throttleminimumaction);
  brake_lowerbound_ =
      std::max(vehicle_param_.brakedeadzone,
               control_conf->mpccontrollerconf.brakeminimumaction);

  minimum_speed_protection_ = control_conf->minimumspeedprotection;
  max_acceleration_when_stopped_ =
      control_conf->maxaccelerationwhenstopped;
  max_abs_speed_when_stopped_ = vehicle_param_.maxabsspeedwhenstopped;
  standstill_acceleration_ =
      control_conf->mpccontrollerconf.standstillacceleration;

  enable_mpc_feedforward_compensation_ =
      control_conf->mpccontrollerconf.enablempcfeedforwardcompensation;

  unconstrained_control_diff_limit_ =
      control_conf->mpccontrollerconf.unconstrainedcontroldifflimit;

  LoadControlCalibrationTable(control_conf->mpccontrollerconf);
  ADEBUG << "MPC conf loaded";
  return true;
}

void MPCController::ProcessLogs(const SimpleMPCDebug *debug,
                                const apollo_msgs::msg::ApollocanbusChassis *chassis) {
  UNUSED(debug);
  UNUSED(chassis);
  // TODO(QiL): Add debug information
}

void MPCController::LogInitParameters() {
  ADEBUG << name_ << " begin.";
  ADEBUG << "[MPCController parameters]"
         << " mass_: " << mass_ << ","
         << " iz_: " << iz_ << ","
         << " lf_: " << lf_ << ","
         << " lr_: " << lr_;
}

void MPCController::InitializeFilters(const apollo_msgs::msg::ApollocontrolControlConf *control_conf) {
  // Low pass filter
  std::vector<double> den(3, 0.0);
  std::vector<double> num(3, 0.0);
  common::LpfCoefficients(
      ts_, control_conf->mpccontrollerconf.cutofffreq, &den, &num);
  digital_filter_.set_coefficients(den, num);
  lateral_error_filter_ = common::MeanFilter(static_cast<std::uint_fast8_t>(
      control_conf->mpccontrollerconf.meanfilterwindowsize));
  heading_error_filter_ = common::MeanFilter(static_cast<std::uint_fast8_t>(
      control_conf->mpccontrollerconf.meanfilterwindowsize));
}

Status MPCController::Init(std::shared_ptr<DependencyInjector> injector,
                           const apollo_msgs::msg::ApollocontrolControlConf *control_conf) {
  if (!LoadControlConf(control_conf)) {
    AERROR << "failed to load control conf";
    return Status(ErrorCode::CONTROL_COMPUTE_ERROR,
                  "failed to load control_conf");
  }
  injector_ = injector;
  // Matrix init operations.
  matrix_a_ = Matrix::Zero(basic_state_size_, basic_state_size_);
  matrix_ad_ = Matrix::Zero(basic_state_size_, basic_state_size_);
  matrix_a_(0, 1) = 1.0;
  matrix_a_(1, 2) = (cf_ + cr_) / mass_;
  matrix_a_(2, 3) = 1.0;
  matrix_a_(3, 2) = (lf_ * cf_ - lr_ * cr_) / iz_;
  matrix_a_(4, 5) = 1.0;
  matrix_a_(5, 5) = 0.0;
  // TODO(QiL): expand the model to accommodate more combined states.

  matrix_a_coeff_ = Matrix::Zero(basic_state_size_, basic_state_size_);
  matrix_a_coeff_(1, 1) = -(cf_ + cr_) / mass_;
  matrix_a_coeff_(1, 3) = (lr_ * cr_ - lf_ * cf_) / mass_;
  matrix_a_coeff_(2, 3) = 1.0;
  matrix_a_coeff_(3, 1) = (lr_ * cr_ - lf_ * cf_) / iz_;
  matrix_a_coeff_(3, 3) = -1.0 * (lf_ * lf_ * cf_ + lr_ * lr_ * cr_) / iz_;

  matrix_b_ = Matrix::Zero(basic_state_size_, controls_);
  matrix_bd_ = Matrix::Zero(basic_state_size_, controls_);
  matrix_b_(1, 0) = cf_ / mass_;
  matrix_b_(3, 0) = lf_ * cf_ / iz_;
  matrix_b_(4, 1) = 0.0;
  matrix_b_(5, 1) = -1.0;
  matrix_bd_ = matrix_b_ * ts_;

  matrix_c_ = Matrix::Zero(basic_state_size_, 1);
  matrix_cd_ = Matrix::Zero(basic_state_size_, 1);

  matrix_state_ = Matrix::Zero(basic_state_size_, 1);
  matrix_k_ = Matrix::Zero(1, basic_state_size_);

  matrix_r_ = Matrix::Identity(controls_, controls_);

  matrix_q_ = Matrix::Zero(basic_state_size_, basic_state_size_);

  int r_param_size = control_conf->mpccontrollerconf.matrixr.size();
  for (int i = 0; i < r_param_size; ++i) {
    matrix_r_(i, i) = control_conf->mpccontrollerconf.matrixr.at(i);
  }

  int q_param_size = control_conf->mpccontrollerconf.matrixq.size();
  if (basic_state_size_ != q_param_size) {
    const auto error_msg =
        absl::StrCat("MPC controller error: matrix_q size: ", q_param_size,
                     " in parameter file not equal to basic_state_size_: ",
                     basic_state_size_);
    AERROR << error_msg;
    return Status(ErrorCode::CONTROL_COMPUTE_ERROR, error_msg);
  }
  for (int i = 0; i < q_param_size; ++i) {
    matrix_q_(i, i) = control_conf->mpccontrollerconf.matrixq.at(i);
  }

  // Update matrix_q_updated_ and matrix_r_updated_
  matrix_r_updated_ = matrix_r_;
  matrix_q_updated_ = matrix_q_;

  InitializeFilters(control_conf);
  LoadMPCGainScheduler(control_conf->mpccontrollerconf);
  LogInitParameters();
  ADEBUG << "[MPCController] init done!";
  return Status::OK();
}

void MPCController::CloseLogFile() {
  if (FLAGS_enable_csv_debug && mpc_log_file_.is_open()) {
    mpc_log_file_.close();
  }
}

double MPCController::Wheel2SteerPct(const double wheel_angle) {
  return wheel_angle / wheel_single_direction_max_degree_ * 100;
}

void MPCController::Stop() { CloseLogFile(); }

std::string MPCController::Name() const { return name_; }

void MPCController::LoadMPCGainScheduler(
    const MPCControllerConf &mpc_controller_conf) {
  const auto &lat_err_gain_scheduler =
      mpc_controller_conf.laterrgainscheduler;
  const auto &heading_err_gain_scheduler =
      mpc_controller_conf.headingerrgainscheduler;
  const auto &feedforwardterm_gain_scheduler =
      mpc_controller_conf.feedforwardtermgainscheduler;
  const auto &steer_weight_gain_scheduler =
      mpc_controller_conf.steerweightgainscheduler;
  ADEBUG << "MPC control gain scheduler loaded";
  Interpolation1D::DataType xy1, xy2, xy3, xy4;
  for (const auto &scheduler : lat_err_gain_scheduler.scheduler) {
    xy1.push_back(std::make_pair(scheduler.speed, scheduler.ratio));
  }
  for (const auto &scheduler : heading_err_gain_scheduler.scheduler) {
    xy2.push_back(std::make_pair(scheduler.speed, scheduler.ratio));
  }
  for (const auto &scheduler : feedforwardterm_gain_scheduler.scheduler) {
    xy3.push_back(std::make_pair(scheduler.speed, scheduler.ratio));
  }
  for (const auto &scheduler : steer_weight_gain_scheduler.scheduler) {
    xy4.push_back(std::make_pair(scheduler.speed, scheduler.ratio));
  }

  lat_err_interpolation_.reset(new Interpolation1D);
  ACHECK(lat_err_interpolation_->Init(xy1))
      << "Fail to load lateral error gain scheduler for MPC controller";

  heading_err_interpolation_.reset(new Interpolation1D);
  ACHECK(heading_err_interpolation_->Init(xy2))
      << "Fail to load heading error gain scheduler for MPC controller";

  feedforwardterm_interpolation_.reset(new Interpolation1D);
  ACHECK(feedforwardterm_interpolation_->Init(xy3))
      << "Fail to load feed forward term gain scheduler for MPC controller";

  steer_weight_interpolation_.reset(new Interpolation1D);
  ACHECK(steer_weight_interpolation_->Init(xy4))
      << "Fail to load steer weight gain scheduler for MPC controller";
}

Status MPCController::ComputeControlCommand(
    const localization::LocalizationEstimate *localization,
    const apollo_msgs::msg::ApollocanbusChassis *chassis,
    const apollo_msgs::msg::ApolloplanningADCTrajectory *planning_published_trajectory,
    ControlCommand *cmd)
{
  UNUSED(localization);
  trajectory_analyzer_ =
      std::move(TrajectoryAnalyzer(planning_published_trajectory));

  SimpleMPCDebug *debug = &cmd->debug.simplempcdebug;
  *debug = apollo::control::SimpleMPCDebug();

  ComputeLongitudinalErrors(&trajectory_analyzer_, debug);

  // Update state
  UpdateState(debug);

  UpdateMatrix(debug);

  FeedforwardUpdate(debug);

  auto vehicle_state = injector_->vehicle_state();
  // Add gain scheduler for higher speed steering
  if (FLAGS_enable_gain_scheduler) {
    matrix_q_updated_(0, 0) =
        matrix_q_(0, 0) *
        lat_err_interpolation_->Interpolate(vehicle_state->linear_velocity());
    matrix_q_updated_(2, 2) =
        matrix_q_(2, 2) * heading_err_interpolation_->Interpolate(
                              vehicle_state->linear_velocity());
    steer_angle_feedforwardterm_updated_ =
        steer_angle_feedforwardterm_ *
        feedforwardterm_interpolation_->Interpolate(
            vehicle_state->linear_velocity());
    matrix_r_updated_(0, 0) =
        matrix_r_(0, 0) * steer_weight_interpolation_->Interpolate(
                              vehicle_state->linear_velocity());
  } else {
    matrix_q_updated_ = matrix_q_;
    matrix_r_updated_ = matrix_r_;
    steer_angle_feedforwardterm_updated_ = steer_angle_feedforwardterm_;
  }

  debug->matrixqupdated.push_back(matrix_q_updated_(0, 0));
  debug->matrixqupdated.push_back(matrix_q_updated_(1, 1));
  debug->matrixqupdated.push_back(matrix_q_updated_(2, 2));
  debug->matrixqupdated.push_back(matrix_q_updated_(3, 3));

  debug->matrixrupdated.push_back(matrix_r_updated_(0, 0));
  debug->matrixrupdated.push_back(matrix_r_updated_(1, 1));

  Matrix control_matrix = Matrix::Zero(controls_, 1);
  std::vector<Matrix> control(horizon_, control_matrix);

  Matrix control_gain_matrix = Matrix::Zero(controls_, basic_state_size_);
  std::vector<Matrix> control_gain(horizon_, control_gain_matrix);

  Matrix addition_gain_matrix = Matrix::Zero(controls_, 1);
  std::vector<Matrix> addition_gain(horizon_, addition_gain_matrix);

  Matrix reference_state = Matrix::Zero(basic_state_size_, 1);
  std::vector<Matrix> reference(horizon_, reference_state);

  Matrix lower_bound(controls_, 1);
  lower_bound << -wheel_single_direction_max_degree_, max_deceleration_;

  Matrix upper_bound(controls_, 1);
  upper_bound << wheel_single_direction_max_degree_, max_acceleration_;

  const double max = std::numeric_limits<double>::max();
  Matrix lower_state_bound(basic_state_size_, 1);
  Matrix upper_state_bound(basic_state_size_, 1);

  // lateral_error, lateral_error_rate, heading_error, heading_error_rate
  // station_error, station_error_rate
  lower_state_bound << -1.0 * max, -1.0 * max, -1.0 * M_PI, -1.0 * max,
      -1.0 * max, -1.0 * max;
  upper_state_bound << max, max, M_PI, max, max, max;

  double mpc_start_timestamp = Clock::NowInSeconds();
  double steer_angle_feedback = 0.0;
  double acc_feedback = 0.0;
  double steer_angle_ff_compensation = 0.0;
  double unconstrained_control_diff = 0.0;
  double control_gain_truncation_ratio = 0.0;
  double unconstrained_control = 0.0;
  const double v = injector_->vehicle_state()->linear_velocity();

  std::vector<double> control_cmd(controls_, 0);

  apollo::common::math::MpcOsqp mpc_osqp(
      matrix_ad_, matrix_bd_, matrix_q_updated_, matrix_r_updated_,
      matrix_state_, lower_bound, upper_bound, lower_state_bound,
      upper_state_bound, reference_state, mpc_max_iteration_, horizon_,
      mpc_eps_);
  if (!mpc_osqp.Solve(&control_cmd)) {
    AERROR << "MPC OSQP solver failed";
  } else {
    ADEBUG << "MPC OSQP problem solved! ";
    control[0](0, 0) = control_cmd.at(0);
    control[0](1, 0) = control_cmd.at(1);
  }

  steer_angle_feedback = Wheel2SteerPct(control[0](0, 0));
  acc_feedback = control[0](1, 0);
  for (int i = 0; i < basic_state_size_; ++i) {
    unconstrained_control += control_gain[0](0, i) * matrix_state_(i, 0);
  }
  unconstrained_control += addition_gain[0](0, 0) * v * debug->curvature;
  if (enable_mpc_feedforward_compensation_) {
    unconstrained_control_diff =
        Wheel2SteerPct(control[0](0, 0) - unconstrained_control);
    if (fabs(unconstrained_control_diff) <= unconstrained_control_diff_limit_) {
      steer_angle_ff_compensation =
          Wheel2SteerPct(debug->curvature *
                         (control_gain[0](0, 2) *
                              (lr_ - lf_ / cr_ * mass_ * v * v / wheelbase_) -
                          addition_gain[0](0, 0) * v));
    } else {
      control_gain_truncation_ratio = control[0](0, 0) / unconstrained_control;
      steer_angle_ff_compensation =
          Wheel2SteerPct(debug->curvature *
                         (control_gain[0](0, 2) *
                              (lr_ - lf_ / cr_ * mass_ * v * v / wheelbase_) -
                          addition_gain[0](0, 0) * v) *
                         control_gain_truncation_ratio);
    }
  } else {
    steer_angle_ff_compensation = 0.0;
  }

  double mpc_end_timestamp = Clock::NowInSeconds();

  ADEBUG << "MPC core algorithm: calculation time is: "
         << (mpc_end_timestamp - mpc_start_timestamp) * 1000 << " ms.";

  // TODO(QiL): evaluate whether need to add spline smoothing after the result
  double steer_angle = steer_angle_feedback +
                       steer_angle_feedforwardterm_updated_ +
                       steer_angle_ff_compensation;

  if (FLAGS_set_steer_limit) {
    const double steer_limit = std::atan(max_lat_acc_ * wheelbase_ /
                                         (vehicle_state->linear_velocity() *
                                          vehicle_state->linear_velocity())) *
                               steer_ratio_ * 180 / M_PI /
                               steer_single_direction_max_degree_ * 100;

    // Clamp the steer angle with steer limitations at current speed
    double steer_angle_limited =
        common::math::Clamp(steer_angle, -steer_limit, steer_limit);
    steer_angle_limited = digital_filter_.Filter(steer_angle_limited);
    steer_angle = steer_angle_limited;
    debug->set__steeranglelimited(steer_angle_limited);
  }
  steer_angle = digital_filter_.Filter(steer_angle);
  // Clamp the steer angle to -100.0 to 100.0
  steer_angle = common::math::Clamp(steer_angle, -100.0, 100.0);
  cmd->set__steeringtarget(steer_angle);

  debug->set__accelerationcmdcloseloop(acc_feedback);

  double acceleration_cmd = acc_feedback + debug->accelerationreference;
  // TODO(QiL): add pitch angle feed forward to accommodate for 3D control

  if ((planning_published_trajectory->trajectorytype ==
       apollo::planning::ADCTrajectory::NORMAL) &&
      (std::fabs(debug->accelerationreference) <=
           max_acceleration_when_stopped_ &&
       std::fabs(debug->speedreference) <= max_abs_speed_when_stopped_)) {
    acceleration_cmd =
        (chassis->gearlocation == canbus::Chassis::GEAR_REVERSE)
            ? std::max(acceleration_cmd, -standstill_acceleration_)
            : std::min(acceleration_cmd, standstill_acceleration_);
    ADEBUG << "Stop location reached";
    debug->set__isfullstop(true);
  }
  // TODO(Yu): study the necessity of path_remain and add it to MPC if needed

  debug->set__accelerationcmd(acceleration_cmd);

  double calibration_value = 0.0;
  if (FLAGS_use_preview_speed_for_table) {
    calibration_value = control_interpolation_->Interpolate(
        std::make_pair(debug->speedreference, acceleration_cmd));
  } else {
    calibration_value = control_interpolation_->Interpolate(std::make_pair(
        injector_->vehicle_state()->linear_velocity(), acceleration_cmd));
  }

  debug->set__calibrationvalue(calibration_value);

  double throttle_cmd = 0.0;
  double brake_cmd = 0.0;
  if (calibration_value >= 0) {
    throttle_cmd = std::max(calibration_value, throttle_lowerbound_);
    brake_cmd = 0.0;
  } else {
    throttle_cmd = 0.0;
    brake_cmd = std::max(-calibration_value, brake_lowerbound_);
  }

  cmd->set__steeringrate(FLAGS_steer_angle_rate);
  // if the car is driven by acceleration, disgard the cmd->throttle and brake
  cmd->set__throttle(throttle_cmd);
  cmd->set__brake(brake_cmd);
  cmd->set__acceleration(acceleration_cmd);

  debug->set__heading(vehicle_state->heading());
  debug->set__steeringposition(chassis->steeringpercentage);
  debug->set__steerangle(steer_angle);
  debug->set__steeranglefeedforward(steer_angle_feedforwardterm_updated_);
  debug->set__steeranglefeedforwardcompensation(steer_angle_ff_compensation);
  debug->set__steerunconstrainedcontroldiff(unconstrained_control_diff);
  debug->set__steeranglefeedback(steer_angle_feedback);
  debug->set__steeringposition(chassis->steeringpercentage);

  if (std::fabs(vehicle_state->linear_velocity()) <=
          vehicle_param_.maxabsspeedwhenstopped ||
      chassis->gearlocation == planning_published_trajectory->gear ||
      chassis->gearlocation == canbus::Chassis::GEAR_NEUTRAL) {
    cmd->set__gearlocation(planning_published_trajectory->gear);
  } else {
    cmd->set__gearlocation(chassis->gearlocation);
  }

  ProcessLogs(debug, chassis);
  return Status::OK();
}

Status MPCController::Reset() {
  previous_heading_error_ = 0.0;
  previous_lateral_error_ = 0.0;
  return Status::OK();
}

void MPCController::LoadControlCalibrationTable(
    const MPCControllerConf &mpc_controller_conf) {
  const auto &control_table = mpc_controller_conf.calibrationtable;
 ADEBUG << "Control calibration table loaded";
  ADEBUG << "Control calibration table size is "
         << control_table.calibration.size();
  Interpolation2D::DataType xyz;
  for (const auto &calibration : control_table.calibration) {
    xyz.push_back(std::make_tuple(calibration.speed,
                                  calibration.acceleration,
                                  calibration.command));
  }
  control_interpolation_.reset(new Interpolation2D);
  ACHECK(control_interpolation_->Init(xyz))
      << "Fail to load control calibration table";
}

void MPCController::UpdateState(SimpleMPCDebug *debug) {
  const auto &com = injector_->vehicle_state()->ComputeCOMPosition(lr_);
  ComputeLateralErrors(com.x(), com.y(), injector_->vehicle_state()->heading(),
                       injector_->vehicle_state()->linear_velocity(),
                       injector_->vehicle_state()->angular_velocity(),
                       injector_->vehicle_state()->linear_acceleration(),
                       trajectory_analyzer_, debug);

  // State matrix update;
  matrix_state_(0, 0) = debug->lateralerror;
  matrix_state_(1, 0) = debug->lateralerrorrate;
  matrix_state_(2, 0) = debug->headingerror;
  matrix_state_(3, 0) = debug->headingerrorrate;
  matrix_state_(4, 0) = debug->stationerror;
  matrix_state_(5, 0) = debug->speederror;
}

void MPCController::UpdateMatrix(SimpleMPCDebug *debug) {
  const double v = std::max(injector_->vehicle_state()->linear_velocity(),
                            minimum_speed_protection_);
  matrix_a_(1, 1) = matrix_a_coeff_(1, 1) / v;
  matrix_a_(1, 3) = matrix_a_coeff_(1, 3) / v;
  matrix_a_(3, 1) = matrix_a_coeff_(3, 1) / v;
  matrix_a_(3, 3) = matrix_a_coeff_(3, 3) / v;

  Matrix matrix_i = Matrix::Identity(matrix_a_.cols(), matrix_a_.cols());
  matrix_ad_ = (matrix_i - ts_ * 0.5 * matrix_a_).inverse() *
               (matrix_i + ts_ * 0.5 * matrix_a_);

  matrix_c_(1, 0) = (lr_ * cr_ - lf_ * cf_) / mass_ / v - v;
  matrix_c_(3, 0) = -(lf_ * lf_ * cf_ + lr_ * lr_ * cr_) / iz_ / v;
  matrix_cd_ = matrix_c_ * debug->refheadingrate * ts_;
}

void MPCController::FeedforwardUpdate(SimpleMPCDebug *debug) {
  const double v = injector_->vehicle_state()->linear_velocity();
  const double kv =
      lr_ * mass_ / 2 / cf_ / wheelbase_ - lf_ * mass_ / 2 / cr_ / wheelbase_;
  steer_angle_feedforwardterm_ = Wheel2SteerPct(
      wheelbase_ * debug->curvature + kv * v * v * debug->curvature);
}

void MPCController::ComputeLateralErrors(
    const double x, const double y, const double theta, const double linear_v,
    const double angular_v, const double linear_a,
    const TrajectoryAnalyzer &trajectory_analyzer, SimpleMPCDebug *debug) {
  const auto matched_point =
      trajectory_analyzer.QueryNearestPointByPosition(x, y);

  const double dx = x - matched_point.pathpoint.x;
  const double dy = y - matched_point.pathpoint.y;

  const double cos_matched_theta = std::cos(matched_point.pathpoint.theta);
  const double sin_matched_theta = std::sin(matched_point.pathpoint.theta);
  // d_error = cos_matched_theta * dy - sin_matched_theta * dx;
  debug->set__lateralerror(cos_matched_theta * dy - sin_matched_theta * dx);

  // matched_theta = matched_point.path_point().theta();
  debug->set__refheading(matched_point.pathpoint.theta);
  const double delta_theta =
      common::math::NormalizeAngle(theta - debug->refheading);
  debug->set__headingerror(delta_theta);

  const double sin_delta_theta = std::sin(delta_theta);
  // d_error_dot = chassis_v * sin_delta_theta;
  double lateral_error_dot = linear_v * sin_delta_theta;
  double lateral_error_dot_dot = linear_a * sin_delta_theta;
  if (FLAGS_reverse_heading_control) {
    if (injector_->vehicle_state()->gear() == canbus::Chassis::GEAR_REVERSE) {
      lateral_error_dot = -lateral_error_dot;
      lateral_error_dot_dot = -lateral_error_dot_dot;
    }
  }

  debug->set__lateralerrorrate(lateral_error_dot);
  debug->set__lateralacceleration(lateral_error_dot_dot);
  debug->set__lateraljerk(
      (debug->lateralacceleration - previous_lateral_acceleration_) / ts_);
  previous_lateral_acceleration_ = debug->lateralacceleration;

  // matched_kappa = matched_point.path_point().kappa();
  debug->set__curvature(matched_point.pathpoint.kappa);
  // theta_error = delta_theta;
  debug->set__headingerror(delta_theta);
  // theta_error_dot = angular_v - matched_point.path_point().kappa() *
  // matched_point.v();
  debug->set__headingrate(angular_v);
  debug->set__refheadingrate(debug->curvature * matched_point.v);
  debug->set__headingerrorrate(debug->headingrate -
                                debug->refheadingrate);

  debug->set__headingacceleration(
      (debug->headingrate - previous_heading_rate_) / ts_);
  debug->set__refheadingacceleration(
      (debug->refheadingrate - previous_ref_heading_rate_) / ts_);
  debug->set__headingerroracceleration(debug->headingacceleration -
                                        debug->refheadingacceleration);
  previous_heading_rate_ = debug->headingrate;
  previous_ref_heading_rate_ = debug->refheadingrate;

  debug->set__headingjerk(
      (debug->headingacceleration - previous_heading_acceleration_) / ts_);
  debug->set__refheadingjerk(
      (debug->refheadingacceleration - previous_ref_heading_acceleration_) /
      ts_);
  debug->set__headingerrorjerk(debug->headingjerk -
                                debug->refheadingjerk);
  previous_heading_acceleration_ = debug->headingacceleration;
  previous_ref_heading_acceleration_ = debug->refheadingacceleration;
}

void MPCController::ComputeLongitudinalErrors(
    const TrajectoryAnalyzer *trajectory_analyzer, SimpleMPCDebug *debug) {
  // the decomposed vehicle motion onto Frenet frame
  // s: longitudinal accumulated distance along reference trajectory
  // s_dot: longitudinal velocity along reference trajectory
  // d: lateral distance w.r.t. reference trajectory
  // d_dot: lateral distance change rate, i.e. dd/dt
  double s_matched = 0.0;
  double s_dot_matched = 0.0;
  double d_matched = 0.0;
  double d_dot_matched = 0.0;

  const auto matched_point = trajectory_analyzer->QueryMatchedPathPoint(
      injector_->vehicle_state()->x(), injector_->vehicle_state()->y());

  trajectory_analyzer->ToTrajectoryFrame(
      injector_->vehicle_state()->x(), injector_->vehicle_state()->y(),
      injector_->vehicle_state()->heading(),
      injector_->vehicle_state()->linear_velocity(), matched_point, &s_matched,
      &s_dot_matched, &d_matched, &d_dot_matched);

  const double current_control_time = Clock::NowInSeconds();

  TrajectoryPoint reference_point =
      trajectory_analyzer->QueryNearestPointByAbsoluteTime(
          current_control_time);

  ADEBUG << "matched point:" << matched_point;
  ADEBUG << "reference point:" << reference_point;

  const double linear_v = injector_->vehicle_state()->linear_velocity();
  const double linear_a = injector_->vehicle_state()->linear_acceleration();
  double heading_error = common::math::NormalizeAngle(
      injector_->vehicle_state()->heading() - matched_point.theta);
  double lon_speed = linear_v * std::cos(heading_error);
  double lon_acceleration = linear_a * std::cos(heading_error);
  double one_minus_kappa_lat_error = 1 - reference_point.pathpoint.kappa *
                                             linear_v * std::sin(heading_error);

  debug->set__stationreference(reference_point.pathpoint.s);
  debug->set__stationfeedback(s_matched);
  debug->set__stationerror(reference_point.pathpoint.s - s_matched);
  debug->set__speedreference(reference_point.v);
  debug->set__speedfeedback(lon_speed);
  debug->set__speederror(reference_point.v - s_dot_matched);
  debug->set__accelerationreference(reference_point.a);
  debug->set__accelerationfeedback(lon_acceleration);
  debug->set__accelerationerror(reference_point.a -
                                lon_acceleration / one_minus_kappa_lat_error);
  double jerk_reference =
      (debug->accelerationreference - previous_acceleration_reference_) /
      ts_;
  double lon_jerk =
      (debug->accelerationfeedback - previous_acceleration_) / ts_;
  debug->set__jerkreference(jerk_reference);
  debug->set__jerkfeedback(lon_jerk);
  debug->set__jerkerror(jerk_reference - lon_jerk / one_minus_kappa_lat_error);
  previous_acceleration_reference_ = debug->accelerationreference;
  previous_acceleration_ = debug->accelerationfeedback;
}

}  // namespace control
}  // namespace apollo
