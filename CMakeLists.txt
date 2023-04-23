# General
# If we have downloaded wxWidgets form the website or cloned the repo, we need to compile everything first
# before we can continue with anything else.

# Define minimum CMake version
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

# Rename this to your project name if you want.
project(wxWidget-Template)

##---------------------------------------------
## wxWidgets configuration here
##---------------------------------------------
if(APPLE)
    set(wxWidgets_ROOT_DIR /Path/To/wxWidgets/wxWidgets-version-x-y-z) # Configure to the path where your downloaded wxWidgets are located. Notice no / at the end.
    set(wxWidgets_CONFIG_EXECUTABLE ${wxWidgets_ROOT_DIR}/build-cocoa-debug/wx-config) # This does not need to be changed since it's default built behaviour.
elseif(WIN32)
    set(wxWidgets_ROOT_DIR C:/path/to/your/wxWidgets) # Set the correct path to your wxWidgets folder on Windows
    set(wxWidgets_CONFIG_EXECUTABLE ${wxWidgets_ROOT_DIR}/build-msw-debug/wx-config) # This does not need to be changed since it's default built behaviour.
else()
    find_program(wxWidgets_CONFIG_EXECUTABLE wx-config)
endif()

find_package(wxWidgets COMPONENTS core base REQUIRED)

if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})
else()
    message(FATAL_ERROR "wxWidgets not found!")
endif()


##---------------------------------------------
## Configure the project here
##---------------------------------------------
file(GLOB_RECURSE SRCS
        "SourceFiles/*.cpp"
        "HeaderFiles/*.h"
        )

if(APPLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SRCS})
elseif(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SRCS})
else()
    add_executable(${PROJECT_NAME} ${SRCS})
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
