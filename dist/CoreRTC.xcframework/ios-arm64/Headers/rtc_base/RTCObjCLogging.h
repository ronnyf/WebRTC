//
//  RTCObjCLogging.h
//  rtc_base
//
//  Created by Falk, Ronny on 7/11/23.
//

#import <Foundation/Foundation.h>
#include "rtc_base/rtc_export_bridge.h"

NS_ASSUME_NONNULL_BEGIN

RTC_EXTERN void RTCLog(NSString *format, ...);
RTC_EXTERN void RTCLogWarning(NSString *format, ...);
RTC_EXTERN void RTCLogError(NSString *format, ...);

NS_ASSUME_NONNULL_END
