/*
 *  Copyright (c) 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 *
 */

#import <Foundation/Foundation.h>

#import "RTCVideoDecoderVP8.h"
#import "RTCWrappedNativeVideoDecoder.h"

#include "rtc_base/rtc_defines.h"
#if defined(RTC_ENABLE_VP8)
#include "modules/video_coding/codecs/vp8/include/vp8.h"
#endif

@implementation RTC_OBJC_TYPE (RTCVideoDecoderVP8)

+ (id<RTC_OBJC_TYPE(RTCVideoDecoder)>)vp8Decoder {
#if defined(RTC_ENABLE_VP8)
  return [[RTC_OBJC_TYPE(RTCWrappedNativeVideoDecoder) alloc]
      initWithNativeDecoder:std::unique_ptr<webrtc::VideoDecoder>(webrtc::VP8Decoder::Create())];
#else
  return nil;
#endif
}

@end
