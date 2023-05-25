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

/** RTCVideoFrameBuffer containing a CVPixelBufferRef */
RTC_OBJC_EXPORT
@interface RTC_OBJC_TYPE (RTCCVPixelBuffer) : NSObject <RTC_OBJC_TYPE(RTCVideoFrameBuffer)>

@property(nonatomic, assign, readonly) CVPixelBufferRef pixelBuffer;
@property(nonatomic, assign, readonly) NSInteger cropX;
@property(nonatomic, assign, readonly) NSInteger cropY;
@property(nonatomic, assign, readonly) NSInteger cropWidth;
@property(nonatomic, assign, readonly) NSInteger cropHeight;

+ (NSSet<NSNumber *> *)supportedPixelFormats;

- (instancetype)initWithPixelBuffer:(CVPixelBufferRef)pixelBuffer;
- (instancetype)initWithPixelBuffer:(CVPixelBufferRef)pixelBuffer
                       adaptedWidth:(NSInteger)adaptedWidth
                      adaptedHeight:(NSInteger)adaptedHeight
                          cropWidth:(NSInteger)cropWidth
                         cropHeight:(NSInteger)cropHeight
                              cropX:(NSInteger)cropX
                              cropY:(NSInteger)cropY;

- (BOOL)requiresCropping;
- (BOOL)requiresScalingToWidth:(NSInteger)width height:(NSInteger)height;
- (NSInteger)bufferSizeForCroppingAndScalingToWidth:(NSInteger)width height:(NSInteger)height;

/** The minimum size of the `tmpBuffer` must be the number of bytes returned from the
 * bufferSizeForCroppingAndScalingToWidth:height: method.
 * If that size is 0, the `tmpBuffer` may be nil.
 */
- (BOOL)cropAndScaleTo:(CVPixelBufferRef)outputPixelBuffer
        withTempBuffer:(nullable uint8_t *)tmpBuffer;

@end

NS_ASSUME_NONNULL_END
