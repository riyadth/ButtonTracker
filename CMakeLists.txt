# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
if(NOT DEFINED ENV{PICO_SDK_PATH})
  set(PICO_SDK_PATH "/home/riyadth/Work/RaspberryPi/Pico/pico-sdk")
endif()

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(ButtonTracker C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(ButtonTracker ButtonTracker.c )

pico_set_program_name(ButtonTracker "ButtonTracker")
pico_set_program_version(ButtonTracker "0.1")

# no_flash means the target is to run from RAM
pico_set_binary_type(ButtonTracker no_flash)

pico_enable_stdio_uart(ButtonTracker 0)
pico_enable_stdio_usb(ButtonTracker 1)

# Add the standard library to the build
target_link_libraries(ButtonTracker pico_stdlib)

pico_add_extra_outputs(ButtonTracker)

