/*
 *  Copyright (c) 2022 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef API_VIDEO_CODECS_VIDEO_ENCODER_FACTORY_TEMPLATE_LIBVPX_VP8_ADAPTER_H_
#define API_VIDEO_CODECS_VIDEO_ENCODER_FACTORY_TEMPLATE_LIBVPX_VP8_ADAPTER_H_

#include <memory>
#include <vector>

#include "rtc_base/rtc_defines.h"
#if defined(RTC_ENABLE_VP8)
#include "absl/container/inlined_vector.h"
#include "api/video_codecs/sdp_video_format.h"
#include "modules/video_coding/codecs/vp8/include/vp8.h"
#include "modules/video_coding/codecs/vp8/vp8_scalability.h"
#endif

namespace webrtc {
struct LibvpxVp8EncoderTemplateAdapter {
  static std::vector<SdpVideoFormat> SupportedFormats() {
#if defined(RTC_ENABLE_VP8)
	absl::InlinedVector<ScalabilityMode, kScalabilityModeCount>
        scalability_modes;
    for (const auto scalability_mode : kVP8SupportedScalabilityModes) {
      scalability_modes.push_back(scalability_mode);
    }

    return {
        SdpVideoFormat("VP8", SdpVideoFormat::Parameters(), scalability_modes)};
#else
	return {};
#endif

  }

  static std::unique_ptr<VideoEncoder> CreateEncoder(
      const SdpVideoFormat& format) {
#if defined(RTC_ENABLE_VP8)
    return VP8Encoder::Create();
#else
	return nullptr;
#endif
  }

  static bool IsScalabilityModeSupported(ScalabilityMode scalability_mode) {
#if defined(RTC_ENABLE_VP8)
    return VP8SupportsScalabilityMode(scalability_mode);
#else
	return false;
#endif
  }
};
}  // namespace webrtc

#endif  // API_VIDEO_CODECS_VIDEO_ENCODER_FACTORY_TEMPLATE_LIBVPX_VP8_ADAPTER_H_
