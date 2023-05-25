/*
 *  Copyright 2016 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#import "UIDevice+RTCDevice.h"

#if TARGET_OS_IOS

#import <sys/utsname.h>

@implementation UIDevice (RTCDevice)

+ (NSString *)machineName {
#if TARGET_OS_SIMULATOR
  return [[[NSProcessInfo processInfo] environment] valueForKey:@"SIMULATOR_MODEL_IDENTIFIER"];
#else
  struct utsname systemInfo;
  uname(&systemInfo);
  return [[NSString alloc] initWithCString:systemInfo.machine
								  encoding:NSUTF8StringEncoding];
#endif
}

@end

#endif
