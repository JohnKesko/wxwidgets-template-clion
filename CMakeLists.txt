# General
# If we have downloaded wxWidgets form the website or cloned the repo, we need to compile everything first
# before we can continue with anything else.

# Define minimum CMake version
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)

# Rename this to your project name.
project(wxWidget-Template)

##---------------------------------------------
## wxWidgets configuration here
##---------------------------------------------
set(wxWidgets_ROOT_DIR /Path/To/wxWidgets/wxWidgets-version-x-y-z) # No / at the end
set(wxWidgets_CONFIG_EXECUTABLE ${wxWidgets_ROOT_DIR}/build-cocoa-debug/wx-config)
find_package(wxWidgets COMPONENTS core base REQUIRED)

if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})
else()
    message(FATAL_ERROR "wxWidgets not found!")
endif()


##---------------------------------------------
## Configure the project here
##---------------------------------------------
set(SRCS SourceFiles/cApp.cpp SourceFiles/cMain.cpp HeaderFiles/cApp.h HeaderFiles/cMain.h)

add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
