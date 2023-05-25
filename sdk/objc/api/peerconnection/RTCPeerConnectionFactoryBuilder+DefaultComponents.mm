/*
 *  Copyright 2018 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#import "RTCPeerConnectionFactoryBuilder+DefaultComponents.h"
#import "RTCPeerConnectionFactory+Native.h"

#include "api/audio_codecs/builtin_audio_decoder_factory.h"
#include "api/audio_codecs/builtin_audio_encoder_factory.h"
#import <WebRTC/RTCVideoDecoderFactoryH264.h>
#import <WebRTC/RTCVideoEncoderFactoryH264.h>
#include "objc_to_native_video_decoder_factory.h" // previously, those names clashed
#include "objc_to_native_video_encoder_factory.h" // previously, those names clashed

#if TARGET_OS_IOS
#include "audio_device_module.h"
#endif

@implementation RTCPeerConnectionFactoryBuilder (DefaultComponents)

+ (RTCPeerConnectionFactoryBuilder *)defaultBuilder {
  RTCPeerConnectionFactoryBuilder *builder = [[RTCPeerConnectionFactoryBuilder alloc] init];
  auto audioEncoderFactory = webrtc::CreateBuiltinAudioEncoderFactory();
  [builder setAudioEncoderFactory:audioEncoderFactory];

  auto audioDecoderFactory = webrtc::CreateBuiltinAudioDecoderFactory();
  [builder setAudioDecoderFactory:audioDecoderFactory];

  auto videoEncoderFactory = webrtc::ObjCToNativeVideoEncoderFactory(
      [[RTC_OBJC_TYPE(RTCVideoEncoderFactoryH264) alloc] init]);
  [builder setVideoEncoderFactory:std::move(videoEncoderFactory)];

  auto videoDecoderFactory = webrtc::ObjCToNativeVideoDecoderFactory(
      [[RTC_OBJC_TYPE(RTCVideoDecoderFactoryH264) alloc] init]);
  [builder setVideoDecoderFactory:std::move(videoDecoderFactory)];

#if TARGET_OS_IOS
  [builder setAudioDeviceModule:webrtc::CreateAudioDeviceModule()];
#endif
  return builder;
}

@end
