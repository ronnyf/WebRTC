/*
 *  Copyright 2018 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#import <AVFoundation/AVFoundation.h>

#import <WebRTC/RTCMacros.h>
#import <WebRTC/RTCVideoFrameBuffer.h>

NS_ASSUME_NONNULL_BEGIN

/** Protocol for RTCVideoFrameBuffers containing YUV planar data. */
RTC_OBJC_EXPORT
@protocol RTC_OBJC_TYPE
(RTCYUVPlanarBuffer)<RTC_OBJC_TYPE(RTCVideoFrameBuffer)>

@property(nonatomic, readonly) NSInteger chromaWidth;
@property(nonatomic, readonly) NSInteger chromaHeight;
@property(nonatomic, readonly) const uint8_t *dataY;
@property(nonatomic, readonly) const uint8_t *dataU;
@property(nonatomic, readonly) const uint8_t *dataV;
@property(nonatomic, readonly) NSInteger strideY;
@property(nonatomic, readonly) NSInteger strideU;
@property(nonatomic, readonly) NSInteger strideV;

- (instancetype)initWithWidth:(NSInteger)width
                       height:(NSInteger)height
                        dataY:(const uint8_t *)dataY
                        dataU:(const uint8_t *)dataU
                        dataV:(const uint8_t *)dataV;
- (instancetype)initWithWidth:(NSInteger)width height:(NSInteger)height;
- (instancetype)initWithWidth:(NSInteger)width
                       height:(NSInteger)height
                      strideY:(NSInteger)strideY
                      strideU:(NSInteger)strideU
                      strideV:(NSInteger)strideV;

@end

NS_ASSUME_NONNULL_END
