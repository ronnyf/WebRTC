/*
 *  Copyright 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#import "RTCVideoFrame+Private.h"

#import <WebRTC/RTCI420Buffer.h>
#import <WebRTC/RTCVideoFrameBuffer.h>
#import <WebRTC/RTCCVPixelBuffer.h>

#include "api/video/video_frame.h"
#include "api/video/video_frame_buffer.h"
#include "api/video/i420_buffer.h"
#include "api/video/video_rotation.h"

@interface RTC_OBJC_TYPE (RTCVideoFrame)()

@property (nonatomic, assign) int64_t timeStampNs;
@property (nonatomic, assign) RTCVideoRotation rotation;
@property (nonatomic, strong) id<RTC_OBJC_TYPE(RTCVideoFrameBuffer)> buffer;

@end

@implementation RTC_OBJC_TYPE (RTCVideoFrame) {
	std::unique_ptr<webrtc::VideoFrame> _videoFrame;
}

- (NSInteger)width {
  return _buffer.width;
}

- (NSInteger)height {
  return _buffer.height;
}

- (RTC_OBJC_TYPE(RTCVideoFrame) *)newI420VideoFrame {
  return [[RTC_OBJC_TYPE(RTCVideoFrame) alloc] initWithBuffer:[_buffer toI420]
                                                     rotation:_rotation
                                                  timeStampNs:_timeStampNs];
}

- (instancetype)initWithPixelBuffer:(CVPixelBufferRef)pixelBuffer
                           rotation:(RTCVideoRotation)rotation
                        timeStampNs:(int64_t)timeStampNs {
  RTCCVPixelBuffer *cvPixelBuffer = [[RTCCVPixelBuffer alloc] initWithPixelBuffer:pixelBuffer];
  if (cvPixelBuffer != nil) {
	return [self initWithBuffer:cvPixelBuffer rotation:rotation timeStampNs:timeStampNs];
  } else {
	return nil;
  }
}

- (instancetype)initWithPixelBuffer:(CVPixelBufferRef)pixelBuffer
                        scaledWidth:(NSInteger)scaledWidth
                       scaledHeight:(NSInteger)scaledHeight
                          cropWidth:(NSInteger)cropWidth
                         cropHeight:(NSInteger)cropHeight
                              cropX:(NSInteger)cropX
                              cropY:(NSInteger)cropY
                           rotation:(RTCVideoRotation)rotation
                        timeStampNs:(int64_t)timeStampNs {
	RTCCVPixelBuffer *cvPixelBuffer = [[RTCCVPixelBuffer alloc] initWithPixelBuffer:pixelBuffer
																	   adaptedWidth:scaledWidth
																	  adaptedHeight:scaledHeight
																		  cropWidth:cropWidth
																		 cropHeight:cropHeight
																			  cropX:cropX
																			  cropY:cropY];
	if (cvPixelBuffer != nil) {
		return [self initWithBuffer:cvPixelBuffer rotation:rotation timeStampNs:timeStampNs];
	} else {
		return nil;
	}
}

- (instancetype)initWithBuffer:(id<RTC_OBJC_TYPE(RTCVideoFrameBuffer)>)buffer
                      rotation:(RTCVideoRotation)rotation
                   timeStampNs:(int64_t)timeStampNs {
  if (self = [super init]) {
    _buffer = buffer;
    _rotation = rotation;
    _timeStampNs = timeStampNs;
	_timeStamp = 0;
  }

  return self;
}

- (instancetype)initWithNativeFrame:(const webrtc::VideoFrame &)nativeFrame {
	self = [super init];
	if (self) {
		_videoFrame.reset(new webrtc::VideoFrame(nativeFrame));
	}
	return self;
}

- (void)setFrame:(const webrtc::VideoFrame &)nativeFrame {
	_videoFrame.reset(new webrtc::VideoFrame(nativeFrame));
}

- (const webrtc::VideoFrame *)nativeFrame {
	return _videoFrame.get();
}

@end
