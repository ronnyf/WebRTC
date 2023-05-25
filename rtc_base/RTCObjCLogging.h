//
//  RTCObjCLogging.h
//  rtc_base
//
//  Created by Falk, Ronny on 7/11/23.
//
//  Copyright 2023 The WebRTC Project Authors. All rights reserved.
//
//  Use of this source code is governed by a BSD-style license
//  that can be found in the LICENSE file in the root of the source
//  tree. An additional intellectual property rights grant can be found
//  in the file PATENTS.  All contributing project authors may
//  be found in the AUTHORS file in the root of the source tree.


#import <Foundation/Foundation.h>
#include "rtc_base/rtc_export_bridge.h"

NS_ASSUME_NONNULL_BEGIN

RTC_EXTERN void RTCLog(NSString *format, ...);
RTC_EXTERN void RTCLogWarning(NSString *format, ...);
RTC_EXTERN void RTCLogError(NSString *format, ...);

NS_ASSUME_NONNULL_END
