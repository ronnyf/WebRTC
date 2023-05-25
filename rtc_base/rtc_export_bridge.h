//
//  rtc_export_bridge.h
//  WebRTC
//
//  Created by Falk, Ronny on 7/11/23.
//

#ifndef rtc_export_bridge_h
#define rtc_export_bridge_h

#include "rtc_base/system/rtc_export.h"

#ifndef RTC_OBJC_TYPE
#define RTC_OBJC_TYPE(t) t
#endif

#ifndef RTC_OBJC_EXPORT
#define RTC_OBJC_EXPORT RTC_EXPORT
#endif

#ifndef RTC_EXTERN
#if defined(__cplusplus)
#define RTC_EXTERN extern "C" RTC_OBJC_EXPORT
#else
#define RTC_EXTERN extern RTC_OBJC_EXPORT
#endif
#endif

#ifndef RTC_FWD_DECL_OBJC_CLASS
#ifdef __OBJC__
#define RTC_FWD_DECL_OBJC_CLASS(classname) @class classname
#else
#define RTC_FWD_DECL_OBJC_CLASS(classname) typedef struct objc_object classname
#endif
#endif

#endif /* rtc_export_bridge_h */
