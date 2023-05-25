/*
 *  Copyright (c) 2021 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 *
 */

#import <Foundation/Foundation.h>

#import "RTCVideoDecoderAV1.h"
#import "RTCWrappedNativeVideoDecoder.h"

#if defined(RTC_USE_LIBAOM_AV1_ENCODER)
#include "modules/video_coding/codecs/av1/dav1d_decoder.h"
#endif

@implementation RTC_OBJC_TYPE (RTCVideoDecoderAV1)

+ (id<RTC_OBJC_TYPE(RTCVideoDecoder)>)av1Decoder {
#if defined(RTC_USE_LIBAOM_AV1_ENCODER)
  return [[RTC_OBJC_TYPE(RTCWrappedNativeVideoDecoder) alloc]
      initWithNativeDecoder:std::unique_ptr<webrtc::VideoDecoder>(webrtc::CreateDav1dDecoder())];
#else
  return nil;
#endif
}

@end
