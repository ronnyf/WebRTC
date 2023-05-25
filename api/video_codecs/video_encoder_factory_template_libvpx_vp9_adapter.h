/*
 *  Copyright (c) 2022 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef API_VIDEO_CODECS_VIDEO_ENCODER_FACTORY_TEMPLATE_LIBVPX_VP9_ADAPTER_H_
#define API_VIDEO_CODECS_VIDEO_ENCODER_FACTORY_TEMPLATE_LIBVPX_VP9_ADAPTER_H_

#include <memory>
#include <vector>

#include "rtc_base/rtc_defines.h"
#if defined(RTC_ENABLE_VP9)
#include "modules/video_coding/codecs/vp9/include/vp9.h"
#endif

namespace webrtc {
struct LibvpxVp9EncoderTemplateAdapter {
  static std::vector<SdpVideoFormat> SupportedFormats() {
#if defined(RTC_ENABLE_VP9)
    return SupportedVP9Codecs(/*add_scalability_modes=*/true);
#else
	return {};
#endif
  }

  static std::unique_ptr<VideoEncoder> CreateEncoder(
      const SdpVideoFormat& format) {
#if defined(RTC_ENABLE_VP9)
	return VP9Encoder::Create(cricket::CreateVideoCodec(format));
#else
	return nullptr;
#endif
  }

  static bool IsScalabilityModeSupported(ScalabilityMode scalability_mode) {
#if defined(RTC_ENABLE_VP9)
	return VP9Encoder::SupportsScalabilityMode(scalability_mode);
#else
	return false;
#endif
  }
};
}  // namespace webrtc

#endif  // API_VIDEO_CODECS_VIDEO_ENCODER_FACTORY_TEMPLATE_LIBVPX_VP9_ADAPTER_H_
