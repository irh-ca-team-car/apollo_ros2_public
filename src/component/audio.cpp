#include "component/audio.h"

#include "modules/audio/proto/audio_conf.pb.h"
#include "modules/common/proto/geometry.pb.h"
#include "modules/common/util/message_util.h"

namespace apollo
{
  namespace audio
  {

    using apollo::common::Point3D;

    AudioComponent::~AudioComponent() {}

    std::string AudioComponent::Name() const
    {
      // TODO(all) implement
      return "audio";
    }

   

    bool AudioComponent::Init()
    {
      AINFO << "Init";
      INIT_FLAG_int32(cache_signal_time, 3, "The time to cache signal");
      INIT_FLAG_string(torch_siren_detection_model,
                       "data/audio/torch_siren_detection_model.pt",
                       "Siren detection model file");

      INIT_FLAG_string(audio_records_dir, "", "The dir path to offline cyber records");

      replaceRoot(FLAGS_torch_siren_detection_model);
      replaceRoot(FLAGS_audio_records_dir);
      ADEBUG << "---------------------------------------------------------------------------";
      ADEBUG << "FLAGS_cache_signal_time           = [" << FLAGS_cache_signal_time << "]";
      ADEBUG << "FLAGS_torch_siren_detection_model = [" << FLAGS_torch_siren_detection_model << "]";
      ADEBUG << "FLAGS_audio_records_dir           = [" << FLAGS_audio_records_dir << "]";
      ADEBUG << "---------------------------------------------------------------------------";
      localization_reader_ =
          node_->CreateReader<apollo::localization::LocalizationEstimate>(
              "/apollo/localization/pose", nullptr);
      audio_writer_ = node_->CreateWriter<AudioDetection>(
          "/apollo/audio_detection");
      mic_reader_ = node_->CreateReader<AudioData>("/apollo/sensor/microphone", std::bind(&AudioComponent::Proc, this, std::placeholders::_1));

      siren_detection_ = std::make_shared<SirenDetection>();
      moving_detection_ = std::make_shared<MovingDetection>();
      direction_detection_ = std::make_shared<DirectionDetection>();

      return true;
    }

    bool AudioComponent::Proc(AudioData::SharedPtr audio_data)
    {
      AINFO << "Proc";
      // TODO(all) remove GetSignals() multiple calls
      AudioDetection audio_detection;
      MessageProcess::OnMicrophone(*audio_data, respeaker_extrinsics_file_,
                                   &audio_info_, direction_detection_.get(), moving_detection_.get(),
                                   siren_detection_.get(), &audio_detection);

      FillHeader(node_->get_name(), audio_detection.apolloheader);
      audio_writer_->Write(audio_detection);
      return true;
    }

    

  } // namespace audio
} // namespace apollo*/
CYBER_REGISTER_COMPONENT(AudioComponent)
