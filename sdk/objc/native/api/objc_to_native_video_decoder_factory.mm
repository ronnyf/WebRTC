/*
 *  Copyright 2018 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "objc_to_native_video_decoder_factory.h"
#include "objc_video_decoder_factory.h"

#include <memory>

namespace webrtc {

std::unique_ptr<VideoDecoderFactory> ObjCToNativeVideoDecoderFactory(
    id<RTC_OBJC_TYPE(RTCVideoDecoderFactory)> objc_video_decoder_factory) {
  return std::make_unique<ObjCVideoDecoderFactory>(objc_video_decoder_factory);
}

}  // namespace webrtc
