/*
 *  Copyright 2020 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "native_network_monitor_factory.h"

#if TARGET_OS_IOS
#include "objc_network_monitor.h"
#endif

#include "rtc_base/logging.h"

namespace webrtc {

std::unique_ptr<rtc::NetworkMonitorFactory> CreateNetworkMonitorFactory() {
  RTC_DLOG(LS_INFO) << __FUNCTION__;
#if TARGET_OS_IOS
  return std::make_unique<ObjCNetworkMonitorFactory>();
#else
  return nullptr;
#endif
}

}
