//
//  RTCObjCLogging.m
//  rtc_base
//
//  Created by Falk, Ronny on 7/11/23.
//

#import "rtc_base/RTCObjCLogging.h"
#include "rtc_base/logging.h"

void RTCLogError(NSString *format, ...) {
	va_list(args);
	va_start(args,format);
	NSString *message = [[NSString alloc] initWithFormat:format arguments:args];
	va_end(args);
	RTC_LOG(LS_ERROR) << [message UTF8String];
}

void RTCLogWarning(NSString *format, ...) {
	va_list(args);
	va_start(args,format);
	NSString *message = [[NSString alloc] initWithFormat:format arguments:args];
	va_end(args);
	RTC_LOG(LS_WARNING) << [message UTF8String];
}

void RTCLog(NSString *format, ...) {
	va_list(args);
	va_start(args,format);
	NSString *message = [[NSString alloc] initWithFormat:format arguments:args];
	va_end(args);
	RTC_LOG(LS_INFO) << [message UTF8String];
}
