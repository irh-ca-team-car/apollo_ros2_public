#include "modules/canbus/kia/translator.hpp"
#include <cmath>
#define BRAKE_RATIO 0.12
#define SPEED_RATIO 0.002
#define THROTTLE_RATIO 0.393
#define STEERING_RATIO 0.00018

void kia_translator::translate(can_msgs::msg::Frame frm, apollo_msgs::msg::ApollocanbusChassis &chassis)
{
  if (frm.id == 0x018)
  {
    chassis.lowbeamsignal = ((frm.data[2] >> 1) & 1) > 0;
    chassis.highbeamsignal = ((frm.data[2] >> 2) & 1) > 0;
    chassis.leftturnsignal = ((frm.data[5] >> 6) & 1) > 0;
    chassis.rightturnsignal = ((frm.data[5] >> 5) & 1) > 0;
  }
  if (frm.id == 0x050)
  {
    chassis.wiper = (frm.data[2] & 0b111) > 0;
  }
  if (frm.id == 0x200)
  {
    chassis.fuelrangem = ((frm.data[1] & 1) << 8) | (frm.data[2] << 0);
    chassis.throttlepercentage = frm.data[4] * THROTTLE_RATIO;
  }
  if (frm.id == 0x220)
  {
    chassis.brakepercentage = (frm.data[4] + frm.data[5] * 256) * BRAKE_RATIO;
  }
  if (frm.id == 0x2B0)
  {
    double steering_angle_report = frm.data[0] + frm.data[1] * 256;

    if (steering_angle_report > 60000)
    {
      steering_angle_report -= 65535;
    }

    chassis.steeringpercentage = -steering_angle_report * STEERING_RATIO;
  }
  if (frm.id == 0x4b0)
  {
    chassis.wheelspeed.wheelspdfr =  (frm.data[0] + frm.data[1] * 256) *0.033 /3.6
    chassis.wheelspeed.wheelspdfl =  (frm.data[2] + frm.data[3] * 256) *0.033 /3.6
    chassis.wheelspeed.wheelspdrr =  (frm.data[4] + frm.data[5] * 256) *0.033 /3.6
    chassis.wheelspeed.wheelspdrl =  (frm.data[6] + frm.data[7] * 256) *0.033 /3.6
  }
  if (frm.id == 0x4f0)
  {
    chassis.odometerm = (frm.data[5] << 16) | (frm.data[6] << 8) | (frm.data[7] << 0) / 10;
  }
  if (frm.id == 0x433)
  {
    chassis.parkingbrake = frm.data[2] == 0x08;
  }
  
  if (frm.id == 0x524)
  {
    double speed_report = frm.data[3] + frm.data[2] * 128;

    speed_report = speed_report * SPEED_RATIO;
    chassis.speedmps = speed_report;
  }
  if (frm.id == 0x598)
  {
    int d4 = frm.data[4] & 0b11111111;
    int d5 = frm.data[5] & 0b11111111;
    int soc =  d5 *256 + d4;
    chassis.batterysocpercentage = soc;
  }

  chassis.enginestarted = true;
  chassis.drivingmode = apollo::canbus::Chassis::DrivingMode::COMPLETE_AUTO_DRIVE;
  chassis.gearlocation = apollo::canbus::Chassis::GearPosition::GEAR_DRIVE;
  chassis.enginerpm = NAN;
  chassis.steeringtorquenm = NAN;
}
void kia_translator::translate(can_msgs::msg::Frame frm, apollo_msgs::msg::ApollocanbusChassisDetail &chassis)
{
  //From what I know,this is basically useless unless we do research purposes with it.
  //Only Chassis is used and not ChassisDetail
  chassis.cartype = 'k';
  if (frm.id == 0x018)
  {
    chassis.safety.isdrivercardoorclose = ((frm.data[0] >> 4) & 1) == 0;
    chassis.safety.ispassengerdooropen = ((frm.data[0] >> 7) & 1) == 0;
    chassis.safety.istrunkopen = ((frm.data[5] >> 7) & 1) == 0;
    chassis.safety.isdriverbuckled = ((frm.data[7] >> 4) & 1) == 0;
    chassis.safety.ispassengerbuckled = ((frm.data[7] >> 6) & 1) == 0;
  }
  if (frm.id == 0x200)
  {
    chassis.gas.gaspedalposition = frm.data[4] * THROTTLE_RATIO;
  }
  if (frm.id == 0x220)
  {
    chassis.brake.brakepedalposition = (frm.data[4] + frm.data[5] * 256) * BRAKE_RATIO;
    chassis.brake.brakeenabled = chassis.brake.brakepedalposition > 0;
  }
 
  if (frm.id == 0x433)
  {
    chassis.brake.ishandbrakeon = frm.data[2] == 0x08;
    chassis.epb.isepbreleased = frm.data[2] != 0x08;
  }
  chassis.gear.canbusfault = false;
  chassis.gear.driveroverride = false;
  chassis.ems.enginerpm = 0;
  chassis.ems.enginestate = apollo::canbus::Ems::RUNNING;
};

/*
//should be optionnal as it come from ChassisDetail which seems unused
[missing] Esp esp = 6;                     // Electronic Stability Program
//Can be obtained from the speed
[missing] Deceleration deceleration = 10;  // deceleration
//It's the speed in X,Y (world coordinate)
[missing] VehicleSpd vehicle_spd = 11;     // vehicle speed
//Missing but can possibly be omitted
[missing] Eps eps = 12;                    // Electronic Power Steering
//Missing and isn't in any message currently known
[missing] float steering_torque_nm = 12 [default = nan];
//Will probably be unused unless we can get the GPS from the car
[from gps] ChassisGPS chassis_gps = 28;
//Since the kia does not have surround support, we'll ignore
[missing] Surround surround = 31;
*/