/*
 *  Copyright (c) 2022 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef API_VIDEO_CODECS_VIDEO_ENCODER_FACTORY_TEMPLATE_LIBAOM_AV1_ADAPTER_H_
#define API_VIDEO_CODECS_VIDEO_ENCODER_FACTORY_TEMPLATE_LIBAOM_AV1_ADAPTER_H_

#include <memory>
#include <vector>

#if defined(RTC_USE_LIBAOM_AV1_ENCODER)

#include "absl/container/inlined_vector.h"
#include "api/video_codecs/sdp_video_format.h"
#include "modules/video_coding/codecs/av1/av1_svc_config.h"
#include "modules/video_coding/codecs/av1/libaom_av1_encoder.h"

#endif

namespace webrtc {
struct LibaomAv1EncoderTemplateAdapter {
  static std::vector<SdpVideoFormat> SupportedFormats() {
#if defined(RTC_USE_LIBAOM_AV1_ENCODER)
    absl::InlinedVector<ScalabilityMode, kScalabilityModeCount>
        scalability_modes = LibaomAv1EncoderSupportedScalabilityModes();
    return {
        SdpVideoFormat("AV1", SdpVideoFormat::Parameters(), scalability_modes)};
#else
	return {};
#endif
  }

  static std::unique_ptr<VideoEncoder> CreateEncoder(
      const SdpVideoFormat& format) {
#if defined(RTC_USE_LIBAOM_AV1_ENCODER)
    return CreateLibaomAv1Encoder();
#else
	  return nullptr;
#endif
  }

  static bool IsScalabilityModeSupported(ScalabilityMode scalability_mode) {
#if defined(RTC_USE_LIBAOM_AV1_ENCODER)
    return LibaomAv1EncoderSupportsScalabilityMode(scalability_mode);
#else
	  return false;
#endif
  }
};

}  // namespace webrtc

#endif  // API_VIDEO_CODECS_VIDEO_ENCODER_FACTORY_TEMPLATE_LIBAOM_AV1_ADAPTER_H_
