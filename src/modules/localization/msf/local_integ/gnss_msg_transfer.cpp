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

#include "modules/localization/msf/local_integ/gnss_msg_transfer.h"
#include "cyber/cyber.h"

namespace apollo {
namespace localization {
namespace msf {

void GnssMagTransfer::Transfer(const apollo::drivers::gnss::BandObservation& in,
                               BandObservationMsg* out) {
  CHECK_NOTNULL(out);
  if (in.bandid!=0) {
    out->set_band_id(GnssBandID(in.bandid));
  }
  if (in.frequencyvalue!=0) {
    out->set_frequency_value(in.frequencyvalue);
  }
  if (in.pseudotype!=0) {
    out->set_pseudo_type(PseudoType(in.pseudotype));
  }
  if (in.pseudorange!=0) {
    out->set_pseudo_range(in.pseudorange);
  }
  if (in.carrierphase!=0) {
    out->set_carrier_phase(in.carrierphase);
  }
  if (in.losslockindex!=0) {
    out->set_loss_lock_index(in.losslockindex);
  }
  if (in.doppler!=0) {
    out->set_doppler(in.doppler);
  }
  if (in.snr!=0) {
    out->set_snr(in.snr);
  }
}

void GnssMagTransfer::Transfer(
    const apollo::drivers::gnss::SatelliteObservation& in,
    SatelliteObservationMsg* out) {
  CHECK_NOTNULL(out);
  if (in.satprn!=0) {
    out->set_sat_prn(in.satprn);
  }
  if (in.satsys!=0) {
    out->set_sat_sys(GnssType(in.satsys));
  }
  if (in.bandobsnum!=0) {
    out->set_band_obs_num(in.bandobsnum);
  }
  out->clear_band_obs();
  for (size_t idx = 0; idx < in.bandobs.size(); ++idx) {
    auto tmp = out->add_band_obs();
    Transfer(in.bandobs[idx], tmp);
  }
}

void GnssMagTransfer::Transfer(
    const apollo::drivers::gnss::EpochObservation& in,
    EpochObservationMsg* out) {
  CHECK_NOTNULL(out);
  if (in.receiverid!=0) {
    out->set_receiver_id(in.receiverid);
  }
  if (in.gnsstimetype!=0) {
    out->set_gnss_time_type(GnssTimeType(in.gnsstimetype));
  }
  if (in.gnssweek!=0) {
    out->set_gnss_week(in.gnssweek);
  }
  if (in.gnssseconds!=0) {
    out->set_gnss_second_s(in.gnssseconds);
  }
  if (in.positionx!=0) {
    out->set_position_x(in.positionx);
  }
  if (in.positiony!=0) {
    out->set_position_y(in.positiony);
  }
  if (in.positionz!=0) {
    out->set_position_z(in.positionz);
  }
  if (in.healthflag!=0) {
    out->set_health_flag(in.healthflag);
  }
  if (in.satobsnum!=0) {
    out->set_sat_obs_num(in.satobsnum);
  }
  out->clear_sat_obs();
  for (size_t idx = 0; idx < in.satobs.size(); ++idx) {
    auto tmp = out->add_sat_obs();
    Transfer(in.satobs[idx], tmp);
  }
}

void GnssMagTransfer::Transfer(const apollo::drivers::gnss::KepplerOrbit& in,
                               KepplerOrbitMsg* out) {
  CHECK_NOTNULL(out);
  if (in.gnsstype!=0) {
    out->set_gnss_type(GnssType(in.gnsstype));
  }
  if (in.satprn!=0) {
    out->set_sat_prn(in.satprn);
  }
  if (in.gnsstimetype!=0) {
    out->set_gnss_time_type(GnssTimeType(in.gnsstimetype));
  }
  if (in.year!=0) {
    out->set_year(in.year);
  }
  if (in.month!=0) {
    out->set_month(in.month);
  }
  if (in.day!=0) {
    out->set_day(in.day);
  }
  if (in.hour!=0) {
    out->set_hour(in.hour);
  }
  if (in.minute!=0) {
    out->set_minute(in.minute);
  }
  if (in.seconds!=0) {
    out->set_second_s(in.seconds);
  }
  if (in.weeknum!=0) {
    out->set_week_num(in.weeknum);
  }
  if (in.reserved!=0) {
    out->set_reserved(in.reserved);
  }
  if (in.af0!=0) {
    out->set_af0(in.af0);
  }
  if (in.af1!=0) {
    out->set_af1(in.af1);
  }
  if (in.af2!=0) {
    out->set_af2(in.af2);
  }
  if (in.iode!=0) {
    out->set_iode(in.iode);
  }
  if (in.deltan!=0) {
    out->set_deltan(in.deltan);
  }
  if (in.m0!=0) {
    out->set_m0(in.m0);
  }
  if (in.e!=0) {
    out->set_e(in.e);
  }
  if (in.roota!=0) {
    out->set_roota(in.roota);
  }
  if (in.toe!=0) {
    out->set_toe(in.toe);
  }
  if (in.toc!=0) {
    out->set_toc(in.toc);
  }
  if (in.cic!=0) {
    out->set_cic(in.cic);
  }
  if (in.crc!=0) {
    out->set_crc(in.crc);
  }
  if (in.cis!=0) {
    out->set_cis(in.cis);
  }
  if (in.crs!=0) {
    out->set_crs(in.crs);
  }
  if (in.cuc!=0) {
    out->set_cuc(in.cuc);
  }
  if (in.cus!=0) {
    out->set_cus(in.cus);
  }
  if (in.omega0!=0) {
    out->set_omega0(in.omega0);
  }
  if (in.omega!=0) {
    out->set_omega(in.omega);
  }
  if (in.i0!=0) {
    out->set_i0(in.i0);
  }
  if (in.omegadot!=0) {
    out->set_omegadot(in.omegadot);
  }
  if (in.idot!=0) {
    out->set_idot(in.idot);
  }
  if (in.codesonl2channel!=0) {
    out->set_codesonl2channel(in.codesonl2channel);
  }
  if (in.l2pdataflag!=0) {
    out->set_l2pdataflag(in.l2pdataflag);
  }
  if (in.accuracy!=0) {
    out->set_accuracy(in.accuracy);
  }
  if (in.health!=0) {
    out->set_health(in.health);
  }
  if (in.tgd!=0) {
    out->set_tgd(in.tgd);
  }
  if (in.iodc!=0) {
    out->set_iodc(in.iodc);
  }
}

void GnssMagTransfer::Transfer(const apollo::drivers::gnss::GlonassOrbit& in,
                               GlonassOrbitMsg* out) {
  CHECK_NOTNULL(out);
  if (in.gnsstype!=0) {
    out->set_gnss_type(GnssType(in.gnsstype));
  }
  if (in.slotprn!=0) {
    out->set_slot_prn(in.slotprn);
  }
  if (in.gnsstimetype!=0) {
    out->set_gnss_time_type(GnssTimeType(in.gnsstimetype));
  }
  if (in.toe!=0) {
    out->set_toe(in.toe);
  }
  if (in.year!=0) {
    out->set_year(in.year);
  }
  if (in.month!=0) {
    out->set_month(in.month);
  }
  if (in.day!=0) {
    out->set_day(in.day);
  }
  if (in.hour!=0) {
    out->set_hour(in.hour);
  }
  if (in.minute!=0) {
    out->set_minute(in.minute);
  }
  if (in.seconds!=0) {
    out->set_second_s(in.seconds);
  }
  if (in.frequencyno!=0) {
    out->set_frequency_no(in.frequencyno);
  }
  if (in.weeknum!=0) {
    out->set_week_num(in.weeknum);
  }
  if (in.weekseconds!=0) {
    out->set_week_second_s(in.weekseconds);
  }
  if (in.tk!=0) {
    out->set_tk(in.tk);
  }
  if (in.clockoffset!=0) {
    out->set_clock_offset(in.clockoffset);
  }
  if (in.clockdrift!=0) {
    out->set_clock_drift(in.clockdrift);
  }
  if (in.health!=0) {
    out->set_health(in.health);
  }
  if (in.positionx!=0) {
    out->set_position_x(in.positionx);
  }
  if (in.positiony!=0) {
    out->set_position_y(in.positiony);
  }
  if (in.positionz!=0) {
    out->set_position_z(in.positionz);
  }
  if (in.velocityx!=0) {
    out->set_velocity_x(in.velocityx);
  }
  if (in.velocityy!=0) {
    out->set_velocity_y(in.velocityy);
  }
  if (in.velocityz!=0) {
    out->set_velocity_z(in.velocityz);
  }
  if (in.acceleratex!=0) {
    out->set_accelerate_x(in.acceleratex);
  }
  if (in.acceleratey!=0) {
    out->set_accelerate_y(in.acceleratey);
  }
  if (in.acceleratez!=0) {
    out->set_accelerate_z(in.acceleratez);
  }
  if (in.inforage!=0) {
    out->set_infor_age(in.inforage);
  }
}

void GnssMagTransfer::Transfer(const apollo::drivers::gnss::GnssEphemeris& in,
                               GnssEphemerisMsg* out) {
  CHECK_NOTNULL(out);
  if (in.gnsstype!=0) {
    out->set_gnss_type(GnssType(in.gnsstype));
  }
  if (in.kepplerorbit!=apollo_msgs::msg::ApollodriversgnssKepplerOrbit()) {
    auto tmp = out->mutable_keppler_orbit();
    Transfer(in.kepplerorbit, tmp);
  }
  if (in.glonassorbit!=apollo_msgs::msg::ApollodriversgnssGlonassOrbit()) {
    auto tmp = out->mutable_glonass_orbit();
    Transfer(in.glonassorbit, tmp);
  }
}

}  // namespace msf
}  // namespace localization
}  // namespace apollo
