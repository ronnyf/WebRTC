//
//  rtc_defines.h
//  WebRTC
//
//  Created by Falk, Ronny on 7/8/23.
//
//  Copyright 2023 The WebRTC Project Authors. All rights reserved.
// 
//  Use of this source code is governed by a BSD-style license
//  that can be found in the LICENSE file in the root of the source
//  tree. An additional intellectual property rights grant can be found
//  in the file PATENTS.  All contributing project authors may
//  be found in the AUTHORS file in the root of the source tree.
//

#ifndef rtc_defines_h
#define rtc_defines_h

#ifdef __APPLE__
#include <TargetConditionals.h>
#else
#error The purpose of this is to build WebRTC with Xcode
#endif // __APPLE__

#ifndef WEBRTC_POSIX
#define WEBRTC_POSIX 1
#endif

#ifndef WEBRTC_MAC
#define WEBRTC_MAC //iOS and macOS and also sim
#endif

#if TARGET_OS_IOS || TARGET_OS_SIMULATOR
#define WEBRTC_IOS
#else
#undef WEBRTC_IOS
#endif

#if TARGET_CPU_ARM64 && !defined(WEBRTC_ARCH_ARM64)
#define WEBRTC_ARCH_ARM64
#endif

#if TARGET_CPU_ARM && !defined(WEBRTC_ARCH_ARM)
#define WEBRTC_ARCH_ARM
#endif

#if __ARM_ARCH == 7 && !defined(WEBRTC_ARCH_ARM_V7)
#define WEBRTC_ARCH_ARM_V7
#endif

#if __ARM_ARCH_7S__ && !defined(WEBRTC_ARCH_ARM_V7S)
#define WEBRTC_ARCH_ARM_V7S
#endif

#if __ARM_NEON && !defined(WEBRTC_HAS_NEON)
#define WEBRTC_HAS_NEON
#endif

#if TARGET_CPU_X86 && !defined(WEBRTC_ARCH_X86_FAMILY)
#define WEBRTC_ARCH_X86_FAMILY
#endif

#if TARGET_CPU_X86_64 && !defined(WEBRTC_ARCH_X86_FAMILY)
#define WEBRTC_ARCH_X86_FAMILY
#endif

#if TARGET_CPU_X86_64 && !defined(WEBRTC_ARCH_X86_64)
#define WEBRTC_ARCH_X86_64
#endif

#if defined(WEBRTC_ARCH_X86_FAMILY)
#if __MMX__
#define WEBRTC_HAS_MMX
#endif

#if __SSE2__
#define WEBRTC_HAS_SSE2
#else
#error This should be on!
#endif

#if __SSE3__
#define WEBRTC_HAS_SSE3
#endif

#if __SSE4_1__
#define WEBRTC_HAS_SSE4_1
#endif

#if __SSSE3__
#define WEBRTC_HAS_SSSE3
#endif

#if __AVX2__
#define WEBRTC_HAS_AVX2
#define WEBRTC_ENABLE_AVX2
#endif

#endif // WEBRTC_ARCH_X86_FAMILY

#define WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE
//#define WEBRTC_EXCLUDE_AUDIO_PROCESSING_MODULE
#define WEBRTC_LIBRARY_IMPL
#define WEBRTC_ENABLE_SYMBOL_EXPORT
#define WEBRTC_ENABLE_OBJC_SYMBOL_EXPORT
#define WEBRTC_USE_BUILTIN_ILBC 1
#define WEBRTC_USE_BUILTIN_OPUS 1
#define WEBRTC_HAVE_SCTP
#define WEBRTC_HAVE_DCSCTP
#define WEBRTC_STRICT_FIELD_TRIALS 0
#define WEBRTC_APM_DEBUG_DUMP 0
#define WEBRTC_ENABLE_PROTOBUF 0
#define WEBRTC_AUDIOPROC_FIXED_PROFILE
//#define WEBRTC_ENABLE_RTC_EVENT_LOG
#define HAVE_WEBRTC_VIDEO
#define OPENSSL_IS_BORINGSSL
//experimental:begin
#define WEBRTC_ENABLE_DEPRECATED_OPENGLES
//experimental:end

#ifdef RTC_ENABLE_VP8
#undef RTC_ENABLE_VP8
#endif

#ifdef RTC_ENABLE_VP9
#undef RTC_ENABLE_VP9
#endif

#ifdef RTC_USE_LIBAOM_AV1_ENCODER
#undef RTC_USE_LIBAOM_AV1_ENCODER
#endif

#ifdef WEBRTC_USE_H264
#error Let's use the built-in HW encoder/decoder.
#endif

#ifdef RTC_DAV1D_IN_INTERNAL_DECODER_FACTORY
#undef RTC_DAV1D_IN_INTERNAL_DECODER_FACTORY
#endif

//#define WEBRTC_UNIT_TEST
//#define WEBRTC_DUMMY_FILE_DEVICES
//#define WEBRTC_EXCLUDE_TRANSIENT_SUPPRESSOR
//#define AECM_WITH_ABS_APPROX
//#define WEBRTC_USE_CRYPTO_BUFFER_CALLBACK
//#define WEBRTC_IOS_ENABLE_COVERAGE
//#define WEBRTC_USE_GIO

#endif /* rtc_defines_h */

//RTC_DISABLE_LOGGING RTC_DISABLE_TRACE_EVENTS RTC_DISABLE_METRICS RTC_DISABLE_CHECK_MSG
