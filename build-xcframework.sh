#! /bin/sh

XCFW_NAME="WebRTC"
SCHEME_NAME="WebRTC-static"

if [ -z ${BUILD_DIR} ]; then
    BUILD_DIR=`pwd`/.build
fi

if [ -z ${CONFIGURATION} ]; then
    CONFIGURATION="Release"
fi

if [ -z ${MARKETING_VERSION} ]; then
	MARKETING_VERSION=`plutil -extract objects.6026CD1A2A285B490018A202.buildSettings.MARKETING_VERSION raw WebRTC.xcodeproj/project.pbxproj`
fi

ARCHIVE_ROOT_PATH="${BUILD_DIR}/${CONFIGURATION}-xcf"
ARCHIVE_PATH="${ARCHIVE_ROOT_PATH}/${XCFW_NAME}"
PKG_CACHE_PATH="${BUILD_DIR}/${CONFIGURATION}-xcf/pkg-cache"

# Platforms to build for
PLATFORMS=("iOS" "iOS Simulator" "macOS")

# Build archives for each platform
for platform in "${PLATFORMS[@]}"; do
    if [ -d "${ARCHIVE_PATH}-${platform}.xcarchive" ]; then
	    echo "${platform} archive exists, skipping"
    else
        echo "Building archive for ${platform}..."
        xcodebuild archive \
            -scheme "${SCHEME_NAME}" \
            -destination "generic/platform=${platform}" \
            -archivePath "${ARCHIVE_PATH}-${platform}.xcarchive" \
            SKIP_INSTALL=NO \
            BUILD_LIBRARY_FOR_DISTRIBUTION=YES \
            clean archive || { echo "Error building archive for ${platform}"; exit 1; }

        echo "Archive for ${platform} built successfully"
    fi
done

echo "Building ${XCFW_NAME} XCFramework"

XCF_PATH="${ARCHIVE_PATH}.xcframework"
XCFZIP_PATH="${ARCHIVE_PATH}.${MARKETING_VERSION}.xcframework.zip"
LIB_PATH="Products/Library/Frameworks/${XCFW_NAME}.framework"

if [ -d "${XCF_PATH}" ]; then
	echo "XCFramework exists, skipping"
else
	xcodebuild -create-xcframework \
		-framework ${ARCHIVE_PATH}-iOS.xcarchive/${LIB_PATH} \
		-framework ${ARCHIVE_PATH}-iOS\ Simulator.xcarchive/${LIB_PATH} \
		-framework ${ARCHIVE_PATH}-macOS.xcarchive/${LIB_PATH} \
		-output ${XCF_PATH}
fi

echo "zipping it with version: ${MARKETING_VERSION}"
cd "${ARCHIVE_ROOT_PATH}"
zip -ry9 "${XCFZIP_PATH}" "${XCFW_NAME}.xcframework"
