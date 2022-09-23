cmake_minimum_required(VERSION 3.23)

set(_PROJECT_NAME FlightDisplayCompanion)
set(_PROJECT_VERSION 3.0.0)

project(${_PROJECT_NAME} VERSION ${_PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,clang-*)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(src/source_files.txt)
include(qt_modules.txt)

add_compile_definitions(LOG_TO_FILE)

find_package(Qt5 COMPONENTS ${QT_MODULES} REQUIRED)

find_library( # Sets the name of the path variable.
          log-lib

          # Specifies the name of the NDK library that
          # you want CMake to locate.
          log )

set(PROJECT_SOURCES
    ${CPP_FILES}
    ${HPP_FILES}
    resources/images.qrc
    resources/fonts.qrc
    qml/qml.qrc
)
# set(ANDROID_EXTRA_LIBS
#     C:/Users/Mikey/AppData/Local/Android/Sdk/android_openssl/latest/arm64/libcrypto_1_1.so
#     C:/Users/Mikey/AppData/Local/Android/Sdk/android_openssl/latest/arm64/libssl_1_1.so
#     C:/Users/Mikey/AppData/Local/Android/Sdk/android_openssl/latest/arm/libcrypto_1_1.so
#     C:/Users/Mikey/AppData/Local/Android/Sdk/android_openssl/latest/arm/libssl_1_1.so
#     C:/Users/Mikey/AppData/Local/Android/Sdk/android_openssl/latest/x86/libcrypto_1_1.so
#     C:/Users/Mikey/AppData/Local/Android/Sdk/android_openssl/latest/x86/libssl_1_1.so
#     C:/Users/Mikey/AppData/Local/Android/Sdk/android_openssl/latest/x86_64/libcrypto_1_1.so
#     C:/Users/Mikey/AppData/Local/Android/Sdk/android_openssl/latest/x86_64/libssl_1_1.so
# CACHE INTERNAL "")

add_library(${_PROJECT_NAME} SHARED
    ${PROJECT_SOURCES}
)

# Define properties for Android with Qt 5 after find_package() calls as:
set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android" CACHE INTERNAL "")

target_include_directories(${_PROJECT_NAME} PUBLIC
    src
    qml
)

target_compile_definitions(${_PROJECT_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

list(TRANSFORM QT_MODULES PREPEND Qt5::)
target_link_libraries(${_PROJECT_NAME} PRIVATE
        ${QT_MODULES}
        ${log-lib}
)

set_target_properties(${_PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
)
# if (ANDROID)
include(C:/Users/Mikey/AppData/Local/Android/Sdk/android_openssl/CMakeLists.txt)
# endif()
message(STATUS "android ndk: ${ANDROID_NDK}")
message(STATUS "android home: ${ANDROID_HOME}")
message(STATUS "log lib: ${log-lib}")
