//
//  RTCVideoFrame+Private.h
//  WebRTC
//
//  Created by Falk, Ronny on 1/8/24.
//
//  Copyright 2024 The WebRTC project authors. All Rights Reserved.
//
//  Use of this source code is governed by a BSD-style license
//  that can be found in the LICENSE file in the root of the source
//  tree. An additional intellectual property rights grant can be found
//  in the file PATENTS.  All contributing project authors may
//  be found in the AUTHORS file in the root of the source tree.

#import "RTCVideoFrame.h"

#include "api/video/video_frame.h"

@interface RTCVideoFrame ()

- (instancetype)initWithNativeFrame:(const webrtc::VideoFrame &)nativeFrame;

- (void)setFrame:(const webrtc::VideoFrame &)nativeFrame;
- (const webrtc::VideoFrame *)nativeFrame;

@end
