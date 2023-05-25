//
//  WebRTC.h
//  WebRTC
//
//  Created by Falk, Ronny on 5/31/23.
//
//  Copyright 2023 The WebRTC Project Authors. All rights reserved.
//
//  Use of this source code is governed by a BSD-style license
//  that can be found in the LICENSE file in the root of the source
//  tree. An additional intellectual property rights grant can be found
//  in the file PATENTS.  All contributing project authors may
//  be found in the AUTHORS file in the root of the source tree.

#import <Foundation/Foundation.h>

//! Project version number for WebRTC.
FOUNDATION_EXPORT double WebRTCVersionNumber;

//! Project version string for WebRTC.
FOUNDATION_EXPORT const unsigned char WebRTCVersionString[];

#import <WebRTC/RTCAudioDevice.h>
#if !TARGET_OS_OSX
#import <WebRTC/RTCAudioSession.h>
#import <WebRTC/RTCAudioSessionConfiguration.h>
#endif
#import <WebRTC/RTCAudioSource.h>
#import <WebRTC/RTCAudioTrack.h>
#import <WebRTC/RTCCVPixelBuffer.h>
#import <WebRTC/RTCCallbackLogger.h>
#import <WebRTC/RTCCameraPreviewView.h>
#import <WebRTC/RTCCameraVideoCapturer.h>
#import <WebRTC/RTCCertificate.h>
#import <WebRTC/RTCCodecSpecificInfo.h>
#import <WebRTC/RTCCodecSpecificInfoH264.h>
#import <WebRTC/RTCConfiguration.h>
#import <WebRTC/RTCCryptoOptions.h>
#import <WebRTC/RTCDataChannel.h>
#import <WebRTC/RTCDataChannelConfiguration.h>
#import <WebRTC/RTCDefaultVideoDecoderFactory.h>
#import <WebRTC/RTCDefaultVideoEncoderFactory.h>
#import <WebRTC/RTCDispatcher.h>
#import <WebRTC/RTCDtmfSender.h>
#import <WebRTC/RTCEAGLVideoView.h>
#import <WebRTC/RTCEncodedImage.h>
#import <WebRTC/RTCFieldTrials.h>
#import <WebRTC/RTCFileLogger.h>
#import <WebRTC/RTCFileVideoCapturer.h>
#import <WebRTC/RTCH264ProfileLevelId.h>
#import <WebRTC/RTCI420Buffer.h>
#import <WebRTC/RTCIceCandidate.h>
#import <WebRTC/RTCIceCandidateErrorEvent.h>
#import <WebRTC/RTCIceServer.h>
#import <WebRTC/RTCLegacyStatsReport.h>
#import <WebRTC/RTCLogging.h>
#import <WebRTC/RTCMTLNSVideoView.h>
#import <WebRTC/RTCMTLRenderer.h>
#import <WebRTC/RTCMTLVideoView.h>
#import <WebRTC/RTCMacros.h>
#import <WebRTC/RTCMediaConstraints.h>
#import <WebRTC/RTCMediaSource.h>
#import <WebRTC/RTCMediaStream.h>
#import <WebRTC/RTCMediaStreamTrack.h>
#import <WebRTC/RTCMetrics.h>
#import <WebRTC/RTCMetricsSampleInfo.h>
#import <WebRTC/RTCMutableI420Buffer.h>
#import <WebRTC/RTCMutableYUVPlanarBuffer.h>
#import <WebRTC/RTCNativeI420Buffer.h>
#import <WebRTC/RTCNativeMutableI420Buffer.h>
#import <WebRTC/RTCNetworkMonitor.h>
#import <WebRTC/RTCPeerConnection.h>
#import <WebRTC/RTCPeerConnectionFactory.h>
#import <WebRTC/RTCPeerConnectionFactoryOptions.h>
#import <WebRTC/RTCRtcpParameters.h>
#import <WebRTC/RTCRtpCodecParameters.h>
#import <WebRTC/RTCRtpEncodingParameters.h>
#import <WebRTC/RTCRtpHeaderExtension.h>
#import <WebRTC/RTCRtpParameters.h>
#import <WebRTC/RTCRtpReceiver.h>
#import <WebRTC/RTCRtpSender.h>
#import <WebRTC/RTCRtpTransceiver.h>
#import <WebRTC/RTCSSLAdapter.h>
#import <WebRTC/RTCSSLCertificateVerifier.h>
#import <WebRTC/RTCSessionDescription.h>
#import <WebRTC/RTCStatisticsReport.h>
#import <WebRTC/RTCTracing.h>
#import <WebRTC/UIDevice+RTCDevice.h>
#import <WebRTC/RTCVideoCapturer.h>
#import <WebRTC/RTCVideoCodecConstants.h>
#import <WebRTC/RTCVideoCodecInfo.h>
#import <WebRTC/RTCVideoDecoder.h>
#import <WebRTC/RTCVideoDecoderAV1.h>
#import <WebRTC/RTCVideoDecoderFactory.h>
#import <WebRTC/RTCVideoDecoderFactoryH264.h>
#import <WebRTC/RTCVideoDecoderH264.h>
#import <WebRTC/RTCVideoDecoderVP8.h>
#import <WebRTC/RTCVideoDecoderVP9.h>
#import <WebRTC/RTCVideoEncoder.h>
#import <WebRTC/RTCVideoEncoderAV1.h>
#import <WebRTC/RTCVideoEncoderFactory.h>
#import <WebRTC/RTCVideoEncoderFactoryH264.h>
#import <WebRTC/RTCVideoEncoderH264.h>
#import <WebRTC/RTCVideoEncoderQpThresholds.h>
#import <WebRTC/RTCVideoEncoderSettings.h>
#import <WebRTC/RTCVideoEncoderVP8.h>
#import <WebRTC/RTCVideoEncoderVP9.h>
#import <WebRTC/RTCVideoFrame.h>
#import <WebRTC/RTCVideoFrameBuffer.h>
#import <WebRTC/RTCVideoRenderer.h>
#import <WebRTC/RTCVideoRendererAdapter.h>
#import <WebRTC/RTCVideoSource.h>
#import <WebRTC/RTCVideoTrack.h>
#import <WebRTC/RTCVideoViewShading.h>
#import <WebRTC/RTCYUVPlanarBuffer.h>
