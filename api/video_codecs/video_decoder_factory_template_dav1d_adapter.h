/*
 *  Copyright (c) 2022 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef API_VIDEO_CODECS_VIDEO_DECODER_FACTORY_TEMPLATE_DAV1D_ADAPTER_H_
#define API_VIDEO_CODECS_VIDEO_DECODER_FACTORY_TEMPLATE_DAV1D_ADAPTER_H_

#include <memory>
#include <vector>

#include "rtc_base/rtc_defines.h"

#if defined(RTC_DAV1D_IN_INTERNAL_DECODER_FACTORY)

#include "api/video_codecs/av1_profile.h"
#include "api/video_codecs/sdp_video_format.h"
#include "modules/video_coding/codecs/av1/dav1d_decoder.h"

#endif

namespace webrtc {
struct Dav1dDecoderTemplateAdapter {
  static std::vector<SdpVideoFormat> SupportedFormats() {
#if defined(RTC_DAV1D_IN_INTERNAL_DECODER_FACTORY)
    return {SdpVideoFormat("AV1"),
            SdpVideoFormat(
                "AV1", {{kAV1FmtpProfile,
                         AV1ProfileToString(AV1Profile::kProfile1).data()}})};
#else
	return nullptr;
#endif
  }

  static std::unique_ptr<VideoDecoder> CreateDecoder(
      const SdpVideoFormat& format) {
#if defined(RTC_DAV1D_IN_INTERNAL_DECODER_FACTORY)
    return CreateDav1dDecoder();
#else
	return nullptr;
#endif
  }
};

}  // namespace webrtc

#endif  // API_VIDEO_CODECS_VIDEO_DECODER_FACTORY_TEMPLATE_DAV1D_ADAPTER_H_
