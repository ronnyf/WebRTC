/*
 *  Copyright 2016 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#import <WebRTC/RTCMacros.h>

#if TARGET_OS_IOS

#import <UIKit/UIKit.h>

RTC_OBJC_EXPORT
@interface UIDevice (RTCDevice)

+ (NSString *)machineName;

@end

#endif
