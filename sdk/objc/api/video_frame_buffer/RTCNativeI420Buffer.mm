/*
 *  Copyright 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#import "RTCNativeI420Buffer+Private.h"

#include "api/video/i420_buffer.h"

#if !defined(NDEBUG) && TARGET_OS_IOS
#import <UIKit/UIKit.h>
#include <libyuv/libyuv.h>
#endif

@implementation RTC_OBJC_TYPE (RTCI420Buffer)

- (instancetype)initWithWidth:(NSInteger)width height:(NSInteger)height {
  if (self = [super init]) {
    _i420Buffer = webrtc::I420Buffer::Create(width, height);
  }

  return self;
}

- (instancetype)initWithWidth:(NSInteger)width
                       height:(NSInteger)height
                        dataY:(const uint8_t *)dataY
                        dataU:(const uint8_t *)dataU
                        dataV:(const uint8_t *)dataV {
  if (self = [super init]) {
    _i420Buffer = webrtc::I420Buffer::Copy(
        width, height, dataY, width, dataU, (width + 1) / 2, dataV, (width + 1) / 2);
  }
  return self;
}

- (instancetype)initWithWidth:(NSInteger)width
                       height:(NSInteger)height
                      strideY:(NSInteger)strideY
                      strideU:(NSInteger)strideU
                      strideV:(NSInteger)strideV {
  if (self = [super init]) {
    _i420Buffer = webrtc::I420Buffer::Create(width, height, strideY, strideU, strideV);
  }

  return self;
}

- (instancetype)initWithFrameBuffer:(rtc::scoped_refptr<webrtc::I420BufferInterface>)i420Buffer {
  if (self = [super init]) {
    _i420Buffer = i420Buffer;
  }

  return self;
}

- (NSInteger)width {
  return _i420Buffer->width();
}

- (NSInteger)height {
  return _i420Buffer->height();
}

- (NSInteger)strideY {
  return _i420Buffer->StrideY();
}

- (NSInteger)strideU {
  return _i420Buffer->StrideU();
}

- (NSInteger)strideV {
  return _i420Buffer->StrideV();
}

- (NSInteger)chromaWidth {
  return _i420Buffer->ChromaWidth();
}

- (NSInteger)chromaHeight {
  return _i420Buffer->ChromaHeight();
}

- (const uint8_t *)dataY {
  return _i420Buffer->DataY();
}

- (const uint8_t *)dataU {
  return _i420Buffer->DataU();
}

- (const uint8_t *)dataV {
  return _i420Buffer->DataV();
}

- (id<RTC_OBJC_TYPE(RTCVideoFrameBuffer)>)cropAndScaleWith:(NSInteger)offsetX
                                                   offsetY:(NSInteger)offsetY
                                                 cropWidth:(NSInteger)cropWidth
                                                cropHeight:(NSInteger)cropHeight
                                                scaleWidth:(NSInteger)scaleWidth
                                               scaleHeight:(NSInteger)scaleHeight {
  rtc::scoped_refptr<webrtc::VideoFrameBuffer> scaled_buffer =
      _i420Buffer->CropAndScale(offsetX, offsetY, cropWidth, cropHeight, scaleWidth, scaleHeight);
  RTC_DCHECK_EQ(scaled_buffer->type(), webrtc::VideoFrameBuffer::Type::kI420);
  // Calling ToI420() doesn't do any conversions.
  rtc::scoped_refptr<webrtc::I420BufferInterface> buffer = scaled_buffer->ToI420();
  RTC_OBJC_TYPE(RTCI420Buffer) *result =
      [[RTC_OBJC_TYPE(RTCI420Buffer) alloc] initWithFrameBuffer:buffer];
  return result;
}

- (id<RTC_OBJC_TYPE(RTCI420Buffer)>)toI420 {
  return self;
}

#pragma mark - Private

- (rtc::scoped_refptr<webrtc::I420BufferInterface>)nativeI420Buffer {
  return _i420Buffer;
}

#pragma mark - Debugging

#if !defined(NDEBUG) && TARGET_OS_IOS
- (id)debugQuickLookObject {
  UIGraphicsBeginImageContext(CGSizeMake(_i420Buffer->width(), _i420Buffer->height()));
  CGContextRef c = UIGraphicsGetCurrentContext();
  uint8_t *ctxData = (uint8_t *)CGBitmapContextGetData(c);

  libyuv::I420ToARGB(_i420Buffer->DataY(),
                     _i420Buffer->StrideY(),
                     _i420Buffer->DataU(),
                     _i420Buffer->StrideU(),
                     _i420Buffer->DataV(),
                     _i420Buffer->StrideV(),
                     ctxData,
                     CGBitmapContextGetBytesPerRow(c),
                     CGBitmapContextGetWidth(c),
                     CGBitmapContextGetHeight(c));

  UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
  UIGraphicsEndImageContext();

  return image;
}
#endif

@end
