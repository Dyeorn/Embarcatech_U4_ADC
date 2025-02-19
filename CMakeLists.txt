# Generated CMake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Embarcatech_U4_ADC C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable
add_executable(Embarcatech_U4_ADC
    main.c
    src/gpio.c
    src/pwm.c
    src/display.c
    src/joystick.c
    src/ssd1306.c
    src/i2c.c
)

# Set program name and version
pico_set_program_name(Embarcatech_U4_ADC "Embarcatech_U4_ADC")
pico_set_program_version(Embarcatech_U4_ADC "0.1")

# Enable USB output
pico_enable_stdio_uart(Embarcatech_U4_ADC 0)
pico_enable_stdio_usb(Embarcatech_U4_ADC 1)

# Add standard library and necessary hardware libraries
target_link_libraries(Embarcatech_U4_ADC
    pico_stdlib
    hardware_adc
    hardware_pwm
    hardware_i2c
    hardware_gpio
    pico_bootrom
)

# Add include directories
target_include_directories(Embarcatech_U4_ADC PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    src
)

# Generate additional outputs (UF2, BIN, HEX)
pico_add_extra_outputs(Embarcatech_U4_ADC)
