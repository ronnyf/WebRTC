/*
 *  Copyright (c) 2020 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#ifndef MODULES_VIDEO_CODING_CODECS_AV1_LIBAOM_AV1_ENCODER_H_
#define MODULES_VIDEO_CODING_CODECS_AV1_LIBAOM_AV1_ENCODER_H_

#if defined(RTC_USE_LIBAOM_AV1_ENCODER)

#include <map>
#include <memory>

#include "absl/strings/string_view.h"
#include "api/video_codecs/video_encoder.h"

namespace webrtc {
struct LibaomAv1EncoderAuxConfig {
  // A map of max pixel count --> cpu speed.
  std::map<int, int> max_pixel_count_to_cpu_speed;
};

std::unique_ptr<VideoEncoder> CreateLibaomAv1Encoder();
std::unique_ptr<VideoEncoder> CreateLibaomAv1Encoder(
    const LibaomAv1EncoderAuxConfig& aux_config);

}  // namespace webrtc

#endif // defined(RTC_USE_LIBAOM_AV1_ENCODER)

#endif  // MODULES_VIDEO_CODING_CODECS_AV1_LIBAOM_AV1_ENCODER_H_
