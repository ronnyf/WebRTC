/*
 *  Copyright 2018 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "objc_to_native_video_encoder_factory.h"
#include "objc_video_encoder_factory.h"

#include <memory>

namespace webrtc {

std::unique_ptr<VideoEncoderFactory> ObjCToNativeVideoEncoderFactory(
    id<RTC_OBJC_TYPE(RTCVideoEncoderFactory)> objc_video_encoder_factory) {
  return std::make_unique<ObjCVideoEncoderFactory>(objc_video_encoder_factory);
}

}  // namespace webrtc
