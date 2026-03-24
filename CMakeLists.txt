cmake_minimum_required(VERSION 3.21)

project(InputsViewer VERSION 1.3.1 LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED src/class/IVBackgroundSprite.cpp src/class/IVFloatSlider.cpp src/class/IVInputSprite.cpp src/class/IVInputsViewLayer.cpp src/class/IVManager.cpp src/class/IVPlayerInputNode.cpp src/class/IVSettingsLayer.cpp src/class/IVTransformSlider.cpp src/class/geode_setting/IVUISettingsButton.cpp src/hooks/GJBaseGameLayer.cpp src/hooks/PauseLayer.cpp src/hooks/PlayLayer.cpp src/json/Cocos.cpp src/json/NodeTransform.cpp)

# Add Geode
if (NOT DEFINED ENV{GEODE_SDK})
  message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
  message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

target_include_directories(${PROJECT_NAME} PRIVATE src)

setup_geode_mod(${PROJECT_NAME})
